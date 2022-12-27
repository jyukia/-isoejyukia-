//=============================================================================
//
// movelife.cpp
// Author : 磯江寿希亜
//
//=============================================================================
//*****************************************************************************
// インクルードファイル
//*****************************************************************************

#include "movelife.h"
#include"input.h"

//コンストラクタ
CMovelife::CMovelife(int nPriority)
{
}
//デストラクタ
CMovelife::~CMovelife()
{
}
//-----------------------------------------
//初期化
//-----------------------------------------
HRESULT CMovelife::Init()
{
	for (int numberCnt = 0; numberCnt <3; numberCnt++)
	{
		pNumber[numberCnt] = CNumber::Create("NUMBER", D3DXVECTOR3(50.0f + numberCnt *45.0f, 360.0f, 0.0f), D3DXVECTOR3(35.0f, 40.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 3);
	}

	Setlife(5);

	return S_OK;
}
//-----------------------------------------
//終了
//-----------------------------------------
void CMovelife::Uninit()
{
}
//-----------------------------------------
//更新
//-----------------------------------------
void CMovelife::Update()
{
	D3DXVECTOR3 pos = CObject2D::GetPos();

	// キーボードの情報取得
	CInput *pInputKeyboard = CApplication::GetInput();
	if (pInputKeyboard->Trigger(DIK_F))
	{
		Addlife(1);
	}
	if (pInputKeyboard->Trigger(DIK_G))
	{
		Sublife(1);
	}

	CObject2D::SetPos(pos);

}
//-----------------------------------------
//描画
//-----------------------------------------
void CMovelife::Draw()
{
}
//加算処理
void CMovelife::Addlife(int nGain)
{
	int aPosTexU[3];	//各桁の数字を格納

	m_Life += nGain;

	aPosTexU[0] = m_Life % 1000 / 100;
	aPosTexU[1] = m_Life % 100 / 10;
	aPosTexU[2] = m_Life % 10 / 1;

	for (int nCount = 0; nCount < 3; nCount++)
	{
		//テクスチャ設定
		pNumber[nCount]->ScoreVtx
		(0.1f * aPosTexU[nCount],
			0.0f,
			0.1f * aPosTexU[nCount] + 0.1f,
			1.0f);
	}
}
//減算処理
void CMovelife::Sublife(int nDecrease)
{
	int aPosTexU[3];	//各桁の数字を格納

	m_Life -= nDecrease;

	if (m_Life <= 0)
	{//0以下だったら
		m_Life = 0;
	}

	aPosTexU[0] = m_Life % 1000 / 100;
	aPosTexU[1] = m_Life % 100 / 10;
	aPosTexU[2] = m_Life % 10 / 1;

	for (int nCount = 0; nCount < 3; nCount++)
	{
		//テクスチャ設定
		pNumber[nCount]->ScoreVtx
		(0.1f * aPosTexU[nCount],
			0.0f,
			0.1f * aPosTexU[nCount] + 0.1f,
			1.0f);
	}
}
//スコア設定処理
void CMovelife::Setlife(int nLife)
{
	int aPosTexU[3];	//各桁の数字を格納

	m_Life = nLife;

	aPosTexU[0] = m_Life % 1000 / 100;
	aPosTexU[1] = m_Life % 100 / 10;
	aPosTexU[2] = m_Life % 10 / 1;

}

CMovelife * CMovelife::Create(D3DXVECTOR3 pos,int nPriority)
{
	CMovelife* pLife = nullptr;
	//動的確保
	pLife = new CMovelife(nPriority);

	if (pLife != nullptr)
	{
		pLife->Init();

		//位置情報
		pLife->SetPos(pos);

	}
	else
	{//処理を止める
		assert(false);
	}

	return pLife;
}
