//=============================================================================
// インクルードファイル
//=============================================================================
#include "application.h"
#include "renderer.h"
#include "object.h"
#include "input.h"
#include "camera.h"
#include "light.h"
#include "texture.h"
#include "title.h"

#include "game.h"
#include "game1.h"

#include "ranking.h"
#include "tutorial.h"
#include "fade.h"
#include "objectX_group.h"
#include "sound.h"
#include"DebugProc.h"
#include"SelectStage.h"

#include"stage_imgui.h"

//=============================================================================
// 静的メンバ変数宣言
//=============================================================================
CApplication *CApplication::m_pApplication = nullptr;
//=============================================================================
// コンストラクタ
//=============================================================================
CApplication::CApplication():m_pRenderer(nullptr), m_pInput(nullptr), m_pMode(nullptr), m_pCamera(nullptr), m_pTexture(nullptr), m_pObjectXGroup(nullptr), m_pSound(nullptr), m_pDebugProc(nullptr), m_Imgui(nullptr)
{
	CApplication::m_mode = MODE_SELECT_STAGE;
}

//=============================================================================
// デストラクタ
//=============================================================================
CApplication::~CApplication()
{

}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CApplication::Init(HINSTANCE hInstance, HWND hWnd, bool bWindow)
{
	//乱数の初期化
	srand((unsigned int)time(0));

	//レンダリングクラスの生成
	m_pRenderer = new CRenderer;
	//レンダリングの初期化処理
	if (FAILED(m_pRenderer->Init(hWnd, bWindow)))
	{ //初期化処理が失敗した場合
		return -1;
	}

	//インプットクラスの生成
	m_pInput = CInput::Create();
	//インプットの初期化処理
	if (FAILED(m_pInput->Init(hInstance, hWnd)))
	{ //初期化処理が失敗した場合
		return -1;
	}

	m_pDebugProc = new CDebugProc;
	// 初期化
	assert(m_pDebugProc != nullptr);
	m_pDebugProc->Init();

	LPDIRECT3DDEVICE9 pDevice = m_pRenderer->GetDevice();
	m_Imgui = new CStageImgui;
	// 初期化
	assert(m_Imgui != nullptr);
	m_Imgui->Init(hWnd, pDevice);


	// カメラの初期化
	m_pCamera = new CCamera;

	// テクスチャの生成
	m_pTexture = new CTexture;
	m_pTexture->LoadAll();

	// モデルの生成
	m_pObjectXGroup = new CObjectXGroup;
	m_pObjectXGroup->LoadAll();

	// サウンドの生成
	m_pSound = new CSound;
	m_pSound->Init(hWnd);

	//モード生成
	CFade::Create(m_mode);

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CApplication::Uninit(void)
{
	//オブジェクトの全開放
	CObject::UninitAll();

	// テクスチャの削除
	if (m_pTexture != nullptr)
	{
		m_pTexture->UnloadAll();
		delete m_pTexture;
		m_pTexture = nullptr;
	}
	//デバック表示
	if (m_pDebugProc != nullptr)
	{// 終了処理
		m_pDebugProc->Uninit();

		// メモリの解放
		delete m_pDebugProc;
		m_pDebugProc = nullptr;
	}

	// サウンドの削除
	if (m_pSound != nullptr)
	{
		m_pSound->Uninit();
		delete m_pSound;
		m_pSound = nullptr;
	}

	// Xモデルの削除
	if (m_pObjectXGroup != nullptr)
	{
		m_pObjectXGroup->UnloadAll();
		delete m_pObjectXGroup;
		m_pObjectXGroup = nullptr;
	}

	//レンダリングの解放・削除
	if (m_pRenderer != nullptr)
	{
		m_pRenderer->Uninit();
		delete m_pRenderer;
		m_pRenderer = nullptr;
	}

	//インプットの解放・削除
	if (m_pInput != nullptr)
	{
		m_pInput->Uninit();
		delete m_pInput;
		m_pInput = nullptr;
	}

	//カメラの解放・削除
	if (m_pCamera != nullptr)
	{
		m_pCamera->Uninit();
		delete m_pCamera;
		m_pCamera = nullptr;
	}
	//imguiの解放
	if (m_Imgui != nullptr)
	{
		//m_Imgui->Uninit();
		delete m_Imgui;
		m_Imgui = nullptr;
	}

}

//=============================================================================
// 更新処理
//=============================================================================
void CApplication::Update(void)
{
#ifdef _DEBUG
	int FPS = GetFPS();

	CDebugProc::Print("フレームレート : %d\n", FPS);

	CDebugProc::Print("現在の画面遷移番号 : [%d] \n", m_mode);

#endif // _DEBUG
	//インプットの更新処理
	if (m_pInput != nullptr)
	{
		m_pInput->Update();
	}
	//レンダリングの更新処理
	if (m_pRenderer != nullptr)
	{
		m_pRenderer->Update();
	}

	//カメラの更新処理
	if (m_pCamera != nullptr)
	{
		m_pCamera->Update();
	}

	//imguiの更新処理
	if (m_Imgui != nullptr)
	{
		m_Imgui->Update();
	}
}

//=============================================================================
// 描画処理
//=============================================================================
void CApplication::Draw(void)
{
	//レンダリングの描画処理
	if (m_pRenderer != nullptr)
	{
		m_pRenderer->Draw();
	}
	//imguiの描画処理
	if (m_Imgui != nullptr)
	{
		m_Imgui->Draw();
	}

}

//=============================================================================
// レンダリングのポインタを返す処理
//=============================================================================
CRenderer * CApplication::GetRenderer()
{
	return m_pRenderer;
}

//=============================================================================
// インプットのポインタを返す処理
//=============================================================================
CInput * CApplication::GetInput()
{
	return m_pInput;
}

//=============================================================================
// モードセット処理
//=============================================================================
void CApplication::SetMode(MODE mode)
{
	if (m_pMode != nullptr)
	{
		m_pMode->Uninit();
		m_pMode = nullptr;
	}

	CObject::ModeRelease();

	m_mode = mode;

	m_pCamera->Init();

	switch (m_mode)
	{
	case MODE_TITLE:
		m_pMode = CTitle::Create();			//
		break;
	case MODE_GAME:
		m_pMode = CGame::Create();			//
		break;
	case MODE_GAME1:
		m_pMode = CGame1::Create();			//
		break;
	case MODE_SELECT_STAGE:			//ステージ選択
		m_pMode = CSelectStage::Create();
		break;
	case MODE_RANKING:
		m_pMode = CRanking::Create();			//
		CRanking::SetRankingScore();
		break;
	case MODE_TUTORIAL:			//
		m_pMode = CTutorial::Create();
		break;
	}
}

//=============================================================================
// モードを取得する処理
//=============================================================================
CApplication::MODE CApplication::GetMode()
{
	return m_mode;
}