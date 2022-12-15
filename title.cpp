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
#include "camera.h"
#include"DebugProc.h"

//=============================================================================
// 静的メンバ変数宣言
//=============================================================================
LPDIRECT3DTEXTURE9 CTitle::m_pTexture = nullptr;

CPlayer *CTitle::m_pPlayer = nullptr;
CMeshfield *CTitle::m_pMeshField = nullptr;
CLight *CTitle::m_pLight = nullptr;

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
	{//初期化
		m_modecount = 1;
		m_bmodeflg = false;
	}

	//タイトル配置
	Title = CObject2D::Create("TITLE",D3DXVECTOR3((float)SCREEN_WIDTH_HALF,-20.0f,0.0f), D3DXVECTOR3(500.0f, 500.0f, 0.0f), PRIORITY_LEVEL0);

	return S_OK;
}

//=============================================================================
// 終了処理
//=============================================================================
void CTitle::Uninit(void)
{
	//インスタンスの解放処理
	CObject::Release();
}

//=============================================================================
// 更新処理
//=============================================================================
void CTitle::Update(void)
{
	{
		CDebugProc::Print("遷移のための選択カウント : [%d]\n", m_modecount);
	}
	D3DXVECTOR3 pos = Title->GetPos();
	if (pos.y >= SCREEN_HEIGHT_HALF)
	{
		Title->SetMove(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	}
	else
	{
		Title->SetMove(D3DXVECTOR3(0.0f, 2.0f, 0.0f));
	}

	// キーボードの情報取得
	CInput *pInputKeyboard = CApplication::GetInput();
	if (pInputKeyboard->Trigger(DIK_W))
	{// 上に移動
		m_modecount++;
	}
	if (pInputKeyboard->Trigger(DIK_S))
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


	// 入力処理用のポインタ宣言
	CInput *pInput = CApplication::GetInput();
	if (!m_bmodeflg)
	{
		if (pInput->Trigger(DIK_RETURN))
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
				// 遷移
				CFade::SetFade(CApplication::MODE_GAME);
			}
			if (m_modecount == 2)
			{
				// 遷移
				CFade::SetFade(CApplication::MODE_RANKING);
			}

		}
	}

	if (m_bmodeflg)
	{
		Title->SetPos(D3DXVECTOR3(SCREEN_WIDTH_HALF, SCREEN_HEIGHT_HALF, 0.0f));
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
