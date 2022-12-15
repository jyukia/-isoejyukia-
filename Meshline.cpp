#include "Meshline.h"
#include"application.h"
#include "renderer.h"
#include "object3D.h"
#include "player.h"
#include "game.h"
#include"DebugProc.h"

bool CMeshLine::MoveMaxFlg = false;


CMeshLine::CMeshLine(int nPriority) :m_pVtxMax(0), m_col(0.0f, 0.0f, 0.0f, 0.0f), m_Vtxcount(0), bUseflg(false)
{

}

CMeshLine::~CMeshLine()
{
}

HRESULT CMeshLine::Init()
{
	{//初期化
		m_pVtxMax = MaxLine;	//頂点数最大数
	}

	//デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//頂点バッファの生成
	pDevice->CreateVertexBuffer((sizeof(VERTEX_3D) * m_pVtxMax),
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	//頂点情報へのポインタ
	VERTEX_3D*pVtx;

	//頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	for (int Cnt = 0; Cnt < m_pVtxMax; Cnt++)
	{
		// 頂点情報を設定
		pVtx[Cnt].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		//各頂点の法線の設定（※ベクトルの大きさは1にする必要がある）
		pVtx[Cnt].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		// 頂点カラーの設定
		pVtx[Cnt].col = D3DXCOLOR(0.0f, 0.0f, 0.0f,1.0f);

		//テクスチャの座標設定
		pVtx[Cnt].tex = D3DXVECTOR2(0.0f, 0.0f);


	}

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();

	return S_OK;
}

void CMeshLine::Uninit()
{
	//頂点バッファの解放・削除
	if (m_pVtxBuff != nullptr)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = nullptr;
	}
}

void CMeshLine::Update()
{
	//頂点情報へのポインタ
//	VERTEX_3D*pVtx;
//
//	//頂点バッファをロックし、頂点情報へのポインタを取得
//	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);
//
//	for (int Cnt = m_pVtxMax - 3; Cnt >= 0; Cnt--)
//	{
//		if (pVtx[m_pVtxMax -1].pos == pVtx[m_pVtxMax -3].pos)
//		{
//			pVtx[Cnt + 2].pos = pVtx[Cnt].pos;
//		}
//	}
//	if (pVtx[m_pVtxMax - 1].pos == pVtx[m_pVtxMax - 3].pos)
//	{
//		D3DXVECTOR3 Pos(0.0f, 0.0f, 0.0f);	//原点
//
//		D3DXVec3TransformCoord(&OfSetPos, &OfSetPos, m_pMtxParent);
//		D3DXVec3TransformCoord(&Pos, &Pos, m_pMtxParent);
//		pVtx[1].pos = OfSetPos;	//高さ変更
//		pVtx[0].pos = Pos;//原点
//
//	}
//	//頂点バッファをアンロックする
//	m_pVtxBuff->Unlock();

	bUseflg = true;

	D3DXVECTOR3 axis = CObjectX::GetAxis();
	//プレイヤー情報
	D3DXVECTOR3 pPlayerPos = CGame::GetPlayer()->GetPos();
	D3DXVECTOR3 pPlayerPosOld = CGame::GetPlayer()->GetPosOld();

	//頂点情報へのポインタ
	VERTEX_3D*pVtx;

	//頂点バッファをロックし、頂点情報へのポインタを取得
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);


	if (m_Vtxcount == 6)
	{
//		CollisionReturn(&pPlayerPos, &pPlayerPosOld, &D3DXVECTOR3(50.0f, 50.0f, 50.0f));
		for (int CollisionCount = 0; CollisionCount < 2; CollisionCount++)
		{
		}

			//戻った際の当たり判定 (巻き戻し)
			bUseflg = CollisionReturn(&pPlayerPos, &pPlayerPosOld, &D3DXVECTOR3(50.0f, 50.0f, 50.0f));

	}
	if (bUseflg)	//生成
	{
		if (pPlayerPosOld != pPlayerPos && !(axis.x == 0 && axis.y == 0 && axis.z == 0))	//動いてるとき実行
		{
			for (int Cnt = m_pVtxMax - 3; Cnt >= 0; Cnt--)
			{
				pVtx[Cnt + 2].pos = pVtx[Cnt].pos;
			}
			pVtx[1].pos = pPlayerPos + axis * 30.0f;			//高さ変更
			pVtx[0].pos = pPlayerPos - axis * 30.0f;			//原点
			m_Vtxcount += 2;
		}
	}

	//頂点バッファをアンロックする
	m_pVtxBuff->Unlock();


#ifdef _DEBUG
	CDebugProc::Print("プレイヤーの進行方向       (axis)       | X : %.2f | Y : %.2f | Z : %.2f |\n", axis.x, axis.y, axis.z);

	CDebugProc::Print("プレイヤーの座標       (pPlayerPos)       | X : %.2f | Y : %.2f | Z : %.2f |\n", pPlayerPos.x, pPlayerPos.y, pPlayerPos.z);
#endif // _DEBUG
}

void CMeshLine::Draw()
{
	//GetDeviveの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	//ライト設定falseにするとライトと食らわない
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	//計算用マトリックス
	D3DXMATRIX mtxRot, mtxTrans;

	//ワールドマトリックスの初期化
	D3DXMatrixIdentity(&m_mtxWorld);				//行列初期化関数(第一引数の行列を単位行列に初期化)

	//向きを反映
	D3DXMatrixRotationYawPitchRoll(&mtxRot, 0.0f, 0.0f, 0.0f); //行列回転関数(第一引数にヨー(y)ピッチ(x)ロール(z)方向の回転行列を作成)
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);				//行列掛け算関数(第2引数 * 第三引数を第一引数に格納)

	//位置を反映
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);		//行列移動関数(第一引数にx,y,z方向の移動行列を作成)
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	//ワールドマトリックスの設定
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);		//ワールド座標行列の設定

	//頂点バッファをデータストリームに設定
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));

	//頂点フォーマットの設定
	pDevice->SetFVF(FVF_VERTEX_3D);

	//テクスチャの設定
	pDevice->SetTexture(0, NULL);

	//ポリゴンの描画
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, m_pVtxMax - 2);

	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

	//テクスチャの解除
	pDevice->SetTexture(0, NULL);

}

void CMeshLine::BindTexture(LPDIRECT3DTEXTURE9 pTexture)
{
}

void CMeshLine::LoadTexture(const char * aFileName)
{
}

void CMeshLine::SetMtxParent(D3DXMATRIX * pMtx)
{
	m_pMtxParent = pMtx;
}

void CMeshLine::SetOfSetPos(D3DXVECTOR3 ofsetpos)
{
	OfSetPos = ofsetpos;
}

void CMeshLine::SetPos(D3DXVECTOR3 pos)
{
	m_pos = pos;

}

void CMeshLine::SetCol(D3DXCOLOR col)
{
	m_col = col;

}

void CMeshLine::SetRot(D3DXVECTOR3 rot)
{
	m_rot = rot;

}

void CMeshLine::SetMoveFlg(bool movemaxflg)
{
	MoveMaxFlg = movemaxflg;
}

CMeshLine * CMeshLine::Create(D3DXCOLOR col, D3DXVECTOR3 distancepos)
{
	CMeshLine *pMeshLine = new CMeshLine(2);

	if (pMeshLine != nullptr)
	{
		pMeshLine->SetCol(col);
		pMeshLine->Init();
		pMeshLine->SetOfSetPos(distancepos);

	}
	else
	{
		assert(false);
	}

	return pMeshLine;
}
//毛糸が障害物に触れた際接触した際きれる処理
bool CMeshLine::Collision(D3DXVECTOR3 * PlayerPos, D3DXVECTOR3 * PlayerSize)
{
	//頂点情報へのポインタ
	VERTEX_3D * pVtx = nullptr;
	//WORD * pIdx;
	D3DXVECTOR3 IdxPos[3];				//Idxのpos
	D3DXVECTOR3 VecA[3];				//VecA
	D3DXVECTOR3 VecB[3];				//VecB

	bool bIsLanding = false;

	//頂点バッファをロック
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);




	//頂点バッファをアンロック
	m_pVtxBuff->Unlock();

	return bIsLanding;
}
//プレイヤーが戻った際毛糸の回収を行う
bool CMeshLine::ReturnCollision(D3DXVECTOR3 * PlayerPos, D3DXVECTOR3 * PlayerPosOld, D3DXVECTOR3 * PlayerSize)
{
	//頂点情報へのポインタ
	VERTEX_3D * pVtx = nullptr;

	D3DXVECTOR3 Answer;					//外積の計算結果
	bool bIsLanding = false;

	//頂点バッファをロック
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	D3DXVECTOR3 MoveVec = pVtx[22].pos - pVtx[20].pos;
	D3DXVECTOR3 VecLine = *PlayerPos - *PlayerPosOld + (MoveVec);			//ベクトル現在のPOSと始点までの距離
	D3DXVECTOR3 VecPos = pVtx[22].pos - *PlayerPosOld;

	//外積計算
	float vecCalculation = Vec2Cross(&VecPos, &VecLine);

	if (vecCalculation <= 0.0f)	//2点の中にいるか外にいるか
	{
		//ベクトルv
		D3DXVECTOR3 vecOld = *PlayerPosOld - pVtx[20].pos;

		//計算用の箱
		float vecCalculation[2];
		//T1求める
		vecCalculation[0] = Vec2Cross(&vecOld, &VecLine);
		vecCalculation[1] = Vec2Cross(&MoveVec, &VecLine);

		//posOldから交点までの距離
		float t1 = vecCalculation[0] / vecCalculation[1];
		//T2求める
		vecCalculation[0] = Vec2Cross(&vecOld, &MoveVec);
		vecCalculation[1] = Vec2Cross(&MoveVec, &VecLine);

		//壁の視点から交点までの距離
		float t2 = vecCalculation[0] / vecCalculation[1];
		//差
		float eps = 0.00001f;

		//プレイヤー情報
		D3DXVECTOR3 pPlayerPos = CGame::GetPlayer()->GetPos();
		D3DXVECTOR3 pPlayerPosOld = CGame::GetPlayer()->GetPosOld();

		if (MoveMaxFlg)
		{
			if (t1 + eps < 0 || t1 - eps > 1 || t2 + eps < 0 || t2 - eps > 1)
			{	//交差してないときの判別

				pPlayerPos = pPlayerPosOld;

				SetPos(pPlayerPos);
			}
			else
			{	//交差してるときの判別
				for (int Cnt = 0; Cnt < m_pVtxMax - 3; Cnt++)
				{
					pVtx[21].pos - pVtx[19].pos;
				}
				bIsLanding = true;
			}
		}
	}

	//頂点バッファをアンロック
	m_pVtxBuff->Unlock();

	return bIsLanding;
}

//=============================================================================
// 当たり判定 プレイヤーが戻った際毛糸の回収を行う
//=============================================================================
bool CMeshLine::CollisionReturn(D3DXVECTOR3 * PlayerPos, D3DXVECTOR3 * PlayerPosOld, D3DXVECTOR3 * PlayerSize)
{
	//プレイヤー情報
	D3DXVECTOR3 pPlayerPos = CGame::GetPlayer()->GetPos();
	D3DXVECTOR3 pPlayerPosOld = CGame::GetPlayer()->GetPosOld();

	//頂点情報へのポインタ
	VERTEX_3D * pVtx = nullptr;
	WORD * pIdx;
	D3DXVECTOR3 VecA[6];				//VecA
	D3DXVECTOR3 VecB[6];				//VecB
	float Calculation2D[6];				//2次元外積の計算結果
	bool bIsLanding = false;

	//頂点バッファをロック
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	D3DXVECTOR3 SIZE = D3DXVECTOR3(1.0f,1.0f,1.0f);

	//ベクトルの取得 VecA 2 3 4
	VecA[0] = pVtx[2].pos + SIZE - pVtx[4].pos + SIZE;
	VecA[1] = pVtx[3].pos + SIZE - pVtx[4].pos + SIZE;
	VecA[2] = pVtx[2].pos + SIZE - pVtx[3].pos + SIZE;

	//ベクトルの取得 VecA 3 4 5
	VecA[3] = pVtx[4].pos + SIZE - pVtx[3].pos + SIZE;
	VecA[4] = pVtx[4].pos + SIZE - pVtx[5].pos + SIZE;
	VecA[5] = pVtx[5].pos + SIZE - pVtx[3].pos + SIZE;

	//プレイヤー	頂点を測る
	VecB[0] = *PlayerPos - pVtx[2].pos;
	VecB[1] = *PlayerPos - pVtx[3].pos;
	VecB[2] = *PlayerPos - pVtx[4].pos;

	VecB[3] = *PlayerPos - pVtx[3].pos;
	VecB[4] = *PlayerPos - pVtx[4].pos;
	VecB[5] = *PlayerPos - pVtx[5].pos;

	//2次元外積の計算結果
	Calculation2D[0] = Vec2Cross(&VecA[0], &VecB[0]);
	Calculation2D[1] = Vec2Cross(&VecA[1], &VecB[1]);
	Calculation2D[2] = Vec2Cross(&VecA[2], &VecB[2]);

	Calculation2D[3] = Vec2Cross(&VecA[3], &VecB[3]);
	Calculation2D[4] = Vec2Cross(&VecA[4], &VecB[4]);
	Calculation2D[5] = Vec2Cross(&VecA[5], &VecB[5]);

	//プレイヤーの位置が全部-か+
		if ((Calculation2D[0] >= 0 && Calculation2D[1] >= 0 && Calculation2D[2] >= 0) || (Calculation2D[0] <= 0 && Calculation2D[1] <= 0 && Calculation2D[2] <= 0) ||
			(Calculation2D[3] >= 0 && Calculation2D[4] >= 0 && Calculation2D[5] >= 0) || (Calculation2D[3] <= 0 && Calculation2D[4] <= 0 && Calculation2D[5] <= 0))
		{//当たった時
			if (MoveMaxFlg)	//動けなくなった時 (移動量すべて使い切った時)
			{
				//線を引いた場所だけ戻れるように
			}
			for (int Cnt = 0; Cnt < m_pVtxMax-3; Cnt++)
			{
				m_Vtxcount = 0;


				// 頂点カラーの設定
				pVtx[Cnt].col = D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f);				//判定　分かりやすく色を変える

			}
			//false生成無し
			bUseflg = false;
			bIsLanding = true;
		}
		else
		{
			//判定　分かりやすく色を変える
			for (int Cnt = 0; Cnt < m_pVtxMax -3; Cnt++)
			{

				//配列を入れ替える事で消している
				pVtx[Cnt] = pVtx[Cnt + 2];


				// 頂点カラーの設定
				pVtx[Cnt].col = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
			}
		}

	//頂点バッファをアンロック
	m_pVtxBuff->Unlock();

	return bIsLanding;
}


//=========================================
// 2Dベクトルの外積
// Author: Yuda Kaito
//=========================================
float CMeshLine::Vec2Cross(D3DXVECTOR3* v1, D3DXVECTOR3* v2)
{
	return v1->x * v2->z - v1->z * v2->x;
}

//=========================================
// 2Dベクトルの内積
// Author: hamada ryuuga
//=========================================
float CMeshLine::Vec2Dot(D3DXVECTOR3* v1, D3DXVECTOR3* v2)
{
	return v1->x * v2->x + v1->z * v2->z;
}
