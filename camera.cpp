//=============================================================================
// インクルードファイル
//=============================================================================
#include "camera.h"
#include "application.h"
#include "renderer.h"
#include "input.h"
#include "player.h"
#include "game.h"
#include"DebugProc.h"
#include"SelectStage.h"

#include <math.h>

//=============================================================================
// 静的メンバ変数宣言
//=============================================================================
D3DXVECTOR3 CCamera::m_rot;
//=============================================================================
// コンストラクタ
//=============================================================================
CCamera::CCamera()
{
}

//=============================================================================
// デストラクタ
//=============================================================================
CCamera::~CCamera()
{
}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CCamera::Init(void)
{
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//向き

	{//画面分割	プレイヤー
	 //視点・注視点・上方向を設定する（構造体の初期化）
		m_posV[NumCameraZero] = D3DXVECTOR3(0.0f, 200.0f, -400.0f);								//視点
		m_posR[NumCameraZero] = D3DXVECTOR3(0.0f, 20.0f, -1.0f);								//注視点
		m_vecU[NumCameraZero] = D3DXVECTOR3(0.0f, 1.0f, 0.0f);									//上方向ベクトル ←固定でOK!!

		m_CamPosV[NumCameraZero] = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_CamPosR[NumCameraZero] = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		//ビューポート構成の保存
		m_game_viewport[NumCameraZero].X = 0;
		m_game_viewport[NumCameraZero].Y = 0;
		m_game_viewport[NumCameraZero].Width = 1280;
		m_game_viewport[NumCameraZero].Height = 720;
		m_game_viewport[NumCameraZero].MaxZ = 1.0f;
		m_game_viewport[NumCameraZero].MinZ = 0.0f;
	}

	{//画面分割 マップ
		m_posV[NumCameraOne] = D3DXVECTOR3(0.0f, 1000.0f, -400.0f);						//視点
		m_posR[NumCameraOne] = D3DXVECTOR3(0.0f, 20.0f, -1.0f);							//注視点
		m_vecU[NumCameraOne] = D3DXVECTOR3(0.0f, 1.0f, 0.0f);							//上方向ベクトル ←固定でOK!!

		m_CamPosV[NumCameraOne] = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_CamPosR[NumCameraOne] = D3DXVECTOR3(0.0f, 0.0f, 0.0f);


		//ビューポート構成の保存
		m_game_viewport[NumCameraOne].X = 1050;
		m_game_viewport[NumCameraOne].Y = 10;
		m_game_viewport[NumCameraOne].Width = 200;
		m_game_viewport[NumCameraOne].Height = 200;
		m_game_viewport[NumCameraOne].MaxZ = 1.0f;
		m_game_viewport[NumCameraOne].MinZ = 0.0f;

	}

	float fLength1 = (m_posV[NumCameraZero].x - m_posR[NumCameraZero].x);									//視点から注視点のX軸の距離
	float fLength2 = (m_posV[NumCameraZero].z - m_posR[NumCameraZero].z);									//視点から注視点のZ軸の距離
	m_fDistance = sqrtf((fLength1 * fLength1) + (fLength2 * fLength2));		//視点から注視点までの距離

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CCamera::Uninit(void)
{
}

//=============================================================================
// 更新処理
//=============================================================================
void CCamera::Update(void)
{
	//キーボードの情報取得
	CInput *pInputKeyboard = CApplication::Getinstnce()->GetInput();

	//カメラの移動
	if (pInputKeyboard->Press(DIK_DOWN))
	{//上に移動
		m_posV[NumCameraZero].x -= sinf(m_rot.y) * CAMERA_SPEED;
		m_posV[NumCameraZero].z -= cosf(m_rot.y) * CAMERA_SPEED;
		m_posR[NumCameraZero].x = m_posV[NumCameraZero].x + sinf(m_rot.y) * m_fDistance;
		m_posR[NumCameraZero].z = m_posV[NumCameraZero].z + cosf(m_rot.y) * m_fDistance;
	}
	if (pInputKeyboard->Press(DIK_UP))
	{//下に移動
		m_posV[NumCameraZero].x += sinf(m_rot.y) * CAMERA_SPEED;
		m_posV[NumCameraZero].z += cosf(m_rot.y) * CAMERA_SPEED;
		m_posR[NumCameraZero].x = m_posV[NumCameraZero].x + sinf(m_rot.y) * m_fDistance;
		m_posR[NumCameraZero].z = m_posV[NumCameraZero].z + cosf(m_rot.y) * m_fDistance;
	}
	if (pInputKeyboard->Press(DIK_RIGHT))
	{//左に移動
		m_posV[NumCameraZero].x += sinf(D3DX_PI * 0.5f + m_rot.y) * CAMERA_SPEED;
		m_posV[NumCameraZero].z += cosf(D3DX_PI * 0.5f + m_rot.y) * CAMERA_SPEED;
		m_posR[NumCameraZero].x = m_posV[NumCameraZero].x + sinf(m_rot.y) * m_fDistance;
		m_posR[NumCameraZero].z = m_posV[NumCameraZero].z + cosf(m_rot.y) * m_fDistance;
	}
	if (pInputKeyboard->Press(DIK_LEFT))
	{//右に移動
		m_posV[NumCameraZero].x -= sinf(D3DX_PI * 0.5f + m_rot.y) * CAMERA_SPEED;
		m_posV[NumCameraZero].z -= cosf(D3DX_PI * 0.5f + m_rot.y) * CAMERA_SPEED;
		m_posR[NumCameraZero].x = m_posV[NumCameraZero].x + sinf(m_rot.y) * m_fDistance;
		m_posR[NumCameraZero].z = m_posV[NumCameraZero].z + cosf(m_rot.y) * m_fDistance;
	}

	//注視点の旋回
	if (pInputKeyboard->Press(DIK_C))
	{//左に旋回
		m_rot.y += 0.05f;
		m_posR[NumCameraZero].x = m_posV[NumCameraZero].x + sinf(m_rot.y) * m_fDistance;
		m_posR[NumCameraZero].z = m_posV[NumCameraZero].z + cosf(m_rot.y) * m_fDistance;
	}
	else if (pInputKeyboard->Press(DIK_Z))
	{//右に旋回
		m_rot.y -= 0.05f;
		m_posR[NumCameraZero].x = m_posV[NumCameraZero].x + sinf(m_rot.y) * m_fDistance;
		m_posR[NumCameraZero].z = m_posV[NumCameraZero].z + cosf(m_rot.y) * m_fDistance;
	}

	//視点の旋回
	if (pInputKeyboard->Press(DIK_E))
	{//左に旋回
		m_rot.y += 0.05f;
	}
	else if (pInputKeyboard->Press(DIK_Q))
	{//右に旋回
		m_rot.y -= 0.05f;
	}

	int mode = CApplication::Getinstnce()->GetMode();
	if (mode == CApplication::MODE_GAME || mode == CApplication::MODE_GAME1)
	{
		//プレイヤー情報
		D3DXVECTOR3 pPlayerPos = CApplication::Getinstnce()->GetpMode()->GetPlayer()->GetPos();

		//計算用マトリックス
		D3DXMATRIX mtxRot, mtxTrans;

		for (int cameranum = 0; cameranum <2; cameranum++)
		{
			//ワールドマトリックスの初期化
			D3DXMatrixIdentity(&m_mtxView[cameranum]);		//行列初期化関数(第一引数の行列を単位行列に初期化)

			//向きを反映
			D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z); //行列回転関数(第一引数にヨー(y)ピッチ(x)ロール(z)方向の回転行列を作成)
			D3DXMatrixMultiply(&m_mtxView[cameranum], &m_mtxView[cameranum], &mtxRot);				//行列掛け算関数(第2引数 * 第三引数を第一引数に格納)

			//位置を反映
			D3DXMatrixTranslation(&mtxTrans, pPlayerPos.x, pPlayerPos.y, pPlayerPos.z);		//行列移動関数(第一引数にx,y,z方向の移動行列を作成)
			D3DXMatrixMultiply(&m_mtxView[cameranum], &m_mtxView[cameranum], &mtxTrans);

			D3DXVec3TransformCoord(&m_CamPosV[cameranum], &m_posV[cameranum], &m_mtxView[cameranum]);	//ワールド変換行列
			D3DXVec3TransformCoord(&m_CamPosR[cameranum], &m_posR[cameranum], &m_mtxView[cameranum]);	//ワールド変換行列
		}
	}
	if (mode == CApplication::MODE_SELECT_STAGE)
	{
		SetCameraType(ONE_CAMERA);

		//プレイヤー情報
		D3DXVECTOR3 pos1 = D3DXVECTOR3(700.0f, 10.0f, 0.0f);
		D3DXVECTOR3 pos = D3DXVECTOR3(0.0f, 10.0f, 0.0f);

		int modecount = CSelectStage::GetModeCount();
		//計算用マトリックス
		D3DXMATRIX mtxRot, mtxTrans;

		//ワールドマトリックスの初期化
		D3DXMatrixIdentity(&m_mtxView[1]);		//行列初期化関数(第一引数の行列を単位行列に初期化)

		//向きを反映
		D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z); //行列回転関数(第一引数にヨー(y)ピッチ(x)ロール(z)方向の回転行列を作成)
		D3DXMatrixMultiply(&m_mtxView[1], &m_mtxView[1], &mtxRot);				//行列掛け算関数(第2引数 * 第三引数を第一引数に格納)

		if (modecount ==1)
		{
			//位置を反映
			D3DXMatrixTranslation(&mtxTrans, pos1.x, pos1.y, pos1.z);		//行列移動関数(第一引数にx,y,z方向の移動行列を作成)
		}
		if (modecount == 2)
		{
			//位置を反映
			D3DXMatrixTranslation(&mtxTrans, pos.x, pos.y, pos.z);		//行列移動関数(第一引数にx,y,z方向の移動行列を作成)
		}
		D3DXMatrixMultiply(&m_mtxView[1], &m_mtxView[1], &mtxTrans);


		D3DXVec3TransformCoord(&m_CamPosV[1], &m_posV[1], &m_mtxView[1]);	//ワールド変換行列
		D3DXVec3TransformCoord(&m_CamPosR[1], &m_posR[1], &m_mtxView[1]);	//ワールド変換行列
	}
	else
	{
		SetCameraType(CAMERA_MAP);

	}


}

//=============================================================================
// 設定処理	(引数1 true 固定カメラ false フリーカメラ)(引数2 true 投影 false 並行投影)(引数3 true 画面複数生成 false 無効)
//=============================================================================
void CCamera::SetCamera(bool bfixed, bool btypecom, int numCamera)
{
	//デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::Getinstnce()->GetRenderer()->GetDevice();

	switch (m_cameratype)
	{
	case CCamera::NONE:
		break;
	case CCamera::ONE_CAMERA:		//プレイヤー等
		pDevice->SetViewport(&m_game_viewport[NumCameraZero]);
		if (bfixed)	//固定カメラするかしないか
		{
			//ビューマトリックスの作成
			D3DXMatrixLookAtLH(&m_mtxView[NumCameraZero],
				&m_CamPosV[NumCameraZero],
				&m_CamPosR[NumCameraZero],
				&m_vecU[NumCameraZero]);
		}
		else
		{
			//ビューマトリックスの作成
			D3DXMatrixLookAtLH(&m_mtxView[NumCameraZero],
				&m_posV[NumCameraZero],
				&m_posR[NumCameraZero],
				&m_vecU[NumCameraZero]);
		}
		//ビューマトリックスの設定
		pDevice->SetTransform(D3DTS_VIEW, &m_mtxView[NumCameraZero]);
		//プロジェクションマトリックスの初期化
		D3DXMatrixIdentity(&m_mtxProjection[NumCameraZero]);
		if (btypecom)	//投影方法
		{
			//プロジェクションマトリックスの作成
			D3DXMatrixPerspectiveFovLH(&m_mtxProjection[NumCameraZero],
				D3DXToRadian(45.0f),							//視野角
				(float)m_game_viewport[NumCameraZero].Width / (float)m_game_viewport[NumCameraZero].Height,		//アスペクト比
				10.0f,											//ニア（どこからどこまでカメラで表示するか設定）
				1000.0f);										//ファー
		}
		else
		{
			// プロジェクションマトリックスの作成(平行投影)
			D3DXMatrixOrthoLH(&m_mtxProjection[NumCameraZero],				// プロジェクションマトリックス
				(float)m_game_viewport[NumCameraZero].Width,				// 幅
				(float)m_game_viewport[NumCameraZero].Height,				// 高さ
				10.0f,													// ニア
				1000.0f);												// ファー
		}
		//プロジェクションマトリックスの設定
		pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection[NumCameraZero]);
		break;
	case CCamera::CAMERA_MAP:		//それ以外の処理

		//ビューポートの設定
		pDevice->SetViewport(&m_game_viewport[numCamera]);

		//ビューマトリックスの初期化
		D3DXMatrixIdentity(&m_mtxView[NumCameraOne]);

		//ビューマトリックスの作成
		D3DXMatrixLookAtLH(&m_mtxView[numCamera],
			&m_CamPosV[numCamera],
			&m_CamPosR[numCamera],
			&m_vecU[numCamera]);

		//ビューマトリックスの設定
		pDevice->SetTransform(D3DTS_VIEW, &m_mtxView[numCamera]);

		//プロジェクションマトリックスの初期化
		D3DXMatrixIdentity(&m_mtxProjection[numCamera]);

		//プロジェクションマトリックスの作成
		D3DXMatrixPerspectiveFovLH(&m_mtxProjection[numCamera],
			D3DXToRadian(45.0f),																//視野角
			(float)m_game_viewport[numCamera].Width / (float)m_game_viewport[numCamera].Height,			//アスペクト比
			10.0f,																				//どこから(ニア)どこまで(ファー)をカメラで
			50000.0f);																			//表示するか設定

		//プロジェクションマトリックスの設定
		pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection[numCamera]);
		break;
	case CCamera::CAMERA_INVALID:
		break;
	default:
		break;
	}
}

//=============================================================================
// 生成処理
//=============================================================================
CCamera * CCamera::Create(CAMERATYPE cameratype)
{
	//ポインタ宣言
	CCamera *pCamera = nullptr;

	//インスタンス生成
	pCamera = new CCamera;

	if (pCamera != nullptr)
	{//ポインタが存在したら実行

		pCamera->Init();

		pCamera->SetCameraType(cameratype);

	}
	else
	{//ポインタが虚無だったら実行
		assert(false);
	}

	//ポインタを返す
	return pCamera;
}

void CCamera::SetCameraType(CAMERATYPE cameratype)
{
	m_cameratype = cameratype;
}

void CCamera::SetSIz_Camera(D3DXVECTOR2 siz)
{
	m_game_viewport[NumCameraZero].Height = (DWORD)siz.y;
	m_game_viewport[NumCameraZero].Width = (DWORD)siz.x;

}

void CCamera::SetPos_Camera(D3DXVECTOR2 pos)
{
	m_game_viewport[NumCameraZero].X = (DWORD)pos.x;
	m_game_viewport[NumCameraZero].Y = (DWORD)pos.y;

}