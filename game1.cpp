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
#include "game1.h"
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
#include"skyfield.h"
#include "movelife.h"
#include "Preparation.h"
#include "load_stage.h"

//=============================================================================
// 静的メンバ変数宣言
//=============================================================================
CPlayer *CGame1::m_pPlayer = nullptr;
CMeshfield *CGame1::m_pMeshField = nullptr;
CLight *CGame1::m_pLight = nullptr;
CScore* CGame1::pScore = nullptr;
CMovelife* CGame1::pMovelife = nullptr;
CGoal* CGame1::m_pGoal = nullptr;
//=============================================================================
// コンストラクタ
//=============================================================================
CGame1::CGame1()
{

}

//=============================================================================
// デストラクタ
//=============================================================================
CGame1::~CGame1()
{

}

//=============================================================================
// 初期化処理
//=============================================================================
HRESULT CGame1::Init(void)
{
	//ライトの生成

	m_pLight = CLight::Create();

	{//初期化
		m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	}

	//メッシュフィールドの生成
	m_pMeshField = CMeshfield::Create(D3DXVECTOR3(-1500.0f, 0.0f, 1500.0f), CObject::PRIORITY_LEVEL3);
	m_pMeshField->LoadTexture("Data\\TEXTURE\\shiba.png");

	//プレイヤーの生成
	CApplication::Getinstnce()->GetpMode()->SetPlayer(CPlayer::Create(D3DXVECTOR3(2600.0f, 20.0f, -3100.0f), CObject::PRIORITY_LEVEL3));
	CApplication::Getinstnce()->GetpMode()->GetPlayer()->LoadModel("Kedama");

	m_pGoal = CGoal::Create(D3DXVECTOR3(1100.0f, 610.0f, -600.0f), CObject::PRIORITY_LEVEL3);
	m_pGoal->LoadModel("Kedama");
	m_pGoal->Setstring("GOAL");

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
	{
		for (int cont = 0; cont < 6; cont++)
		{
			CObjectX* botle = CObjectX::CObjectX::Create("BEERBOTTLE", D3DXVECTOR3(2000.0f, 0.0f, -3400.0f + 100 * cont), 3);
		}
		for (int cont = 0; cont < 6; cont++)
		{
			CObjectX* botle = CObjectX::CObjectX::Create("BEERBOTTLE", D3DXVECTOR3(2450.0f + 100 * cont, 0.0f, -2500.0f), 3);
		}

		CObjectX* buckt = CObjectX::CObjectX::Create("BUCKET", D3DXVECTOR3(1950.0f, 0.0f, -1600.0f), 3);

		for (int cont = 0; cont < 2; cont++)
		{
			CObjectX* cone = CObjectX::CObjectX::Create("CONE", D3DXVECTOR3(2100.0f + 240 * cont, 0.0f, -2200.0f), 3);
		}
		for (int cont = 0; cont < 2; cont++)
		{
			CObjectX* cone = CObjectX::CObjectX::Create("CONE", D3DXVECTOR3(1300.0f, 0.0f, -1400.0f + 240 * cont), 3);
		}
	}

	//コンパス生成
	m_pCompass = CObject2D::Create("COMPASS", D3DXVECTOR3(1150.0f, 110.0f, 0.0f), D3DXVECTOR3(220.0f, 220.0f, 0.0f), CObject::PRIORITY_LEVEL3);

	pScore = CScore::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	//ゲーム開始の合図
	m_pPreparation->Create("REDY", D3DXVECTOR3(SCREEN_WIDTH + 100, SCREEN_HEIGHT_HALF, 0.0f), D3DXVECTOR3(1000.0f, 1000.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CObject::PRIORITY_LEVEL3);

	CSkyField::Create();

	//CLoadStage::LoadAllTest(0);

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CGame1::Uninit(void)
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
void CGame1::Update(void)
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
void CGame1::Draw(void)
{

}

//=============================================================================
// 生成処理
//=============================================================================
CGame1 * CGame1::Create()
{
	//ポインタ宣言
	CGame1 *pGame = nullptr;

	//インスタンス生成
	pGame = new CGame1;

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