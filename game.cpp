//=============================================================================
// インクルードファイル
//=============================================================================
#include "application.h"
#include "renderer.h"
#include "objectX.h"
#include "object3D.h"
#include "object2D.h"
#include "object.h"
#include "input.h"
#include "title.h"
#include "game.h"
#include "fade.h"
#include "player.h"
#include "light.h"
#include "meshfield.h"
#include "camera.h"
#include "Meshline.h"
#include"Number.h"
#include"score.h"
#include "file.h"
#include "goal.h"
#include "load_stage.h"

#include "movelife.h"
#include "Preparation.h"
#include "mode.h"

//=============================================================================
// 静的メンバ変数宣言
//=============================================================================
CMeshfield *CGame::m_pMeshField = nullptr;
CLight *CGame::m_pLight = nullptr;
CScore* CGame::pScore = nullptr;
CMovelife* CGame::pMovelife = nullptr;
CGoal* CGame::m_pGoal = nullptr;
//=============================================================================
// コンストラクタ
//=============================================================================
CGame::CGame()
{

}

//=============================================================================
// デストラクタ
//=============================================================================
CGame::~CGame()
{

}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CGame::Init(void)
{
	{//初期化
		m_rot = D3DXVECTOR3(0.0f,0.0f,0.0f);
	}

	//モデル読み込み一番上に配置
	OutputStatus();

	//ライトの生成
	m_pLight = CLight::Create();

	//メッシュフィールドの生成
	m_pMeshField = CMeshfield::Create(D3DXVECTOR3(-1500.0f, 0.0f, 1500.0f), CObject::PRIORITY_LEVEL3);

	//プレイヤーの生成
	CApplication::Getinstnce()->GetpMode()->SetPlayer(CPlayer::Create(D3DXVECTOR3(110.0f, 610.0f, -600.0f), CObject::PRIORITY_LEVEL3));
	CApplication::Getinstnce()->GetpMode()->GetPlayer()->LoadModel("Kedama");

	m_pGoal = CGoal::Create(D3DXVECTOR3(1100.0f, 610.0f, -600.0f), CObject::PRIORITY_LEVEL3);
	m_pGoal->LoadModel("Kedama");

	//コンパス生成
	m_pCompass = CObject2D::Create("COMPASS", D3DXVECTOR3(1150.0f, 110.0f, 0.0f), D3DXVECTOR3(220.0f, 220.0f, 0.0f), CObject::PRIORITY_LEVEL3);

	pScore = CScore::Create(D3DXVECTOR3(0.0f,0.0f, 0.0f));

	pMovelife = CMovelife::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), CObject::PRIORITY_LEVEL3);

	//ゲーム開始の合図
	m_pPreparation->Create("REDY", D3DXVECTOR3(SCREEN_WIDTH+100, SCREEN_HEIGHT_HALF, 0.0f), D3DXVECTOR3(1000.0f, 1000.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f),CObject::PRIORITY_LEVEL3);

	Load();

	CLoadStage::SaveAll();

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CGame::Uninit(void)
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
void CGame::Update(void)
{
	// 入力処理用のポインタ宣言
	CInput *pInput = CApplication::Getinstnce()->GetInput();

	if (m_pFade->GetFade() == CFade::FADE_NONE)
	{
		if (pInput->Trigger(DIK_RETURN))
		{
			// 遷移
			CFade::SetFade(CApplication::MODE_RANKING);
		}
	}

	//コンパス処理
	{
		m_rot = CCamera::GetRot();
		m_rot.z = m_rot.y;
		if (pInput->Press(DIK_Q))
		{
			m_rot.z += 0.05f;
		}
		if (pInput->Press(DIK_E))
		{
			m_rot.z -= 0.05f;
		}
		m_rot.y *= -1;
		m_pCompass->SetRot(m_rot);
	}

}

//=============================================================================
// 描画処理
//=============================================================================
void CGame::Draw(void)
{

}

//=============================================================================
// 生成処理
//=============================================================================
CGame * CGame::Create()
{
	//ポインタ宣言
	CGame *pGame = nullptr;

	//インスタンス生成
	pGame = new CGame;

	if (pGame != nullptr)
	{//ポインタが存在したら実行
		pGame->Init();
	}
	else
	{//ポインタが虚無だったら実行
		assert(false);
	}

	//ポインタを返す
	return pGame;
}