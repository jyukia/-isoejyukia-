//=============================================================================
// インクルードファイル
//=============================================================================
#include "main.h"
#include "title.h"
#include "renderer.h"
#include "application.h"
#include "input.h"
#include "fade.h"
#include "object2D.h"

#include "objectX.h"
#include "object3D.h"
#include "object2D.h"


#include "player.h"
#include "light.h"
#include "meshfield.h"
#include "Meshline.h"
#include "camera.h"
#include"DebugProc.h"
#include "load_stage.h"
#include"skyfield.h"

//=============================================================================
// 静的メンバ変数宣言
//=============================================================================
LPDIRECT3DTEXTURE9 CTitle::m_pTexture = nullptr;

CPlayer *CTitle::m_pPlayer = nullptr;
CMeshfield *CTitle::m_pMeshField = nullptr;
CLight *CTitle::m_pLight = nullptr;
CMeshLine *m_pMeshLine = nullptr;			//	メッシュライン

//=============================================================================
// コンストラクタ
//=============================================================================
CTitle::CTitle():m_modecount(0), m_bmodeflg(false)
{

}

//=============================================================================
// デストラクタ
//=============================================================================
CTitle::~CTitle()
{

}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CTitle::Init(void)
{
	//ライトの生成
	m_pLight = CLight::Create();

	{//初期化
		m_modecount = 1;
		m_bmodeflg = false;
	}

	//プレイヤーの生成
	CApplication::Getinstnce()->GetpMode()->SetPlayer(CPlayer::Create(D3DXVECTOR3(1850.0f, 20.0f, -600.0f), CObject::PRIORITY_LEVEL3));
	CApplication::Getinstnce()->GetpMode()->GetPlayer()->LoadModel("Kedama");

	{//壁
		for (int cont = 0; cont < 5; cont++)
		{
			CObjectX* wallX = CObjectX::CObjectX::Create("FENCE", D3DXVECTOR3(700 + 520 * cont, 0, -3500), 3);
		}
		for (int cont = 0; cont < 6; cont++)
		{
			CObjectX* wallX1 = CObjectX::CObjectX::Create("FENCEROT", D3DXVECTOR3(3000, 0, -3200 + 515 * cont), 3);
		}
		for (int cont = 0; cont < 5; cont++)
		{
			CObjectX* wallX2 = CObjectX::CObjectX::Create("FENCE", D3DXVECTOR3(2780 - 515 * cont, 0, -350), 3);
		}
		for (int cont = 0; cont < 6; cont++)
		{
			CObjectX* wallX3 = CObjectX::CObjectX::Create("FENCEROT", D3DXVECTOR3(450, 0, -3200 + 515 * cont), 3);
		}
	}

	//メッシュフィールドの生成
	m_pMeshField = CMeshfield::Create(D3DXVECTOR3(-1500.0f, 0.0f, 1500.0f), CObject::PRIORITY_LEVEL3);
	m_pMeshField->LoadTexture("Data\\TEXTURE\\shiba.png");

	//タイトル配置
	m_pTitle = CObject2D::Create("TITLE",D3DXVECTOR3((float)SCREEN_WIDTH_HALF,-20.0f,0.0f), D3DXVECTOR3(500.0f, 500.0f, 0.0f), PRIORITY_LEVEL5);

	//プレイヤー入力選択
	m_pGame = CObject2D::Create("OMOIDE", D3DXVECTOR3((float)SCREEN_WIDTH_HALF -300, 500.0f, 0.0f), D3DXVECTOR3(300.0f, 300.0f, 0.0f), PRIORITY_LEVEL5);
	
	m_pRanking = CObject2D::Create("INIESUTA", D3DXVECTOR3((float)SCREEN_WIDTH_HALF + 300, 500.0f, 0.0f), D3DXVECTOR3(300.0f, 300.0f, 0.0f), PRIORITY_LEVEL5);

	CSkyField::Create();

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CTitle::Uninit(void)
{
	//ライトの解放・削除
	if (m_pLight != nullptr)
	{
		m_pLight->Uninit();
		delete m_pLight;
		m_pLight = nullptr;
	}

	//インスタンスの解放処理
	CObject::Release();
}

//=============================================================================
// 更新処理
//=============================================================================
void CTitle::Update(void)
{
	{//デバック処理
		CDebugProc::Print("遷移のための選択カウント : [%d]\n", m_modecount);
	}

	D3DXVECTOR3 move = CApplication::Getinstnce()->GetpMode()->GetPlayer()->GetMove();

	bool flg = CApplication::Getinstnce()->GetpMode()->GetPlayer()->GetMoveFlg();

	if (flg)	//移動可
	{
		move.z -= 3;
	}
	else	//移動不可
	{
		move.z = 0;
	}

	CApplication::Getinstnce()->GetpMode()->GetPlayer()->SetMove(move);

	//ゲームネームの情報取得
	D3DXVECTOR3 Titlepos = m_pTitle->GetPos();

	//タイトル止まる処理
	if (Titlepos.y >= SCREEN_HEIGHT_HALF)
	{
		m_pTitle->SetMove(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	}
	else
	{
		m_pTitle->SetMove(D3DXVECTOR3(0.0f, 2.0f, 0.0f));
	}

	// キーボードの情報取得
	CInput *pInputKeyboard = CApplication::Getinstnce()->GetInput();
	if (pInputKeyboard->Trigger(DIK_A))
	{// 上に移動
		m_modecount++;
	}
	if (pInputKeyboard->Trigger(DIK_D))
	{// 下に移動
		m_modecount--;
	}
	//選択カウントの制限
	if (m_modecount > m_modeMax)
	{
		m_modecount = m_modeMin;
	}
	if (m_modecount < m_modeMin)
	{
		m_modecount = m_modeMax;
	}

	//選択際色の変更分かりやすく
	if (m_modecount == 1)
	{
		m_pGame->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		m_pRanking->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));

	}
	if (m_modecount == 2)
	{
		m_pGame->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));
		m_pRanking->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	}

	// 入力処理用のポインタ宣言
	CInput *pInput = CApplication::Getinstnce()->GetInput();
	if (!m_bmodeflg)	//フェードキャンセル
	{
		if (pInput->Trigger(DIK_RETURN))		//選択シーン実行
		{
			m_bmodeflg = true;
		}
	}
	if (m_pFade->GetFade() == CFade::FADE_NONE)
	{
		if (pInput->Trigger(DIK_RETURN))
		{
			if (m_modecount == 1)
			{
				//遷移
				CFade::SetFade(CApplication::MODE_SELECT_STAGE);	//ゲーム遷移
			}
			if (m_modecount == 2)
			{
				//遷移
				CFade::SetFade(CApplication::MODE_RANKING); //ランキング遷移
			}
		}
	}

	//降りきるまでにEnterを押した際移動を終了させる
	if (m_bmodeflg)
	{
		m_pTitle->SetPos(D3DXVECTOR3(SCREEN_WIDTH_HALF, SCREEN_HEIGHT_HALF, 0.0f));
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void CTitle::Draw(void)
{

}

//=============================================================================
// 生成処理
//=============================================================================
CTitle * CTitle::Create()
{
	//ポインタ宣言
	CTitle *pTitle = nullptr;

	//インスタンス生成
	pTitle = new CTitle;

	if (pTitle != nullptr)
	{//ポインタが存在したら実行
		pTitle->Init();
	}
	else
	{//ポインタが虚無だったら実行
		assert(false);
	}

	//ポインタを返す
	return pTitle;
}
