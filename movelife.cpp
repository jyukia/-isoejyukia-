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
#include "mode.h"
#include"Meshline.h"
#include"player.h"
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

	for (int numberCnt = 0; numberCnt <5; numberCnt++)
	{
		pNumber[numberCnt] = CNumber::Create("NUMBER", D3DXVECTOR3(50.0f + numberCnt *45.0f, 360.0f, 0.0f), D3DXVECTOR3(35.0f, 40.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 3);
	}

	Setlife(10000);

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

	//プレイヤー情報
	D3DXVECTOR3 Playerpos = CApplication::Getinstnce()->GetpMode()->GetPlayer()->GetPos();
	D3DXVECTOR3 PlayerposOld = CMode::GetPlayer()->GetPosOld();
	bool flg =CApplication::Getinstnce()->GetpMode()->GetMeshLine()->GetbIsLanding();
	CInput *pInputKeyboard = CApplication::Getinstnce()->GetInput();

	//減る処理
	if (pInputKeyboard->Press(DIK_R))
	{
		type = RETURN;
	}
	else if (Playerpos != PlayerposOld)	//動いていたら　移動ライフを減らす
	{
		type = MOVE;
	}
	else
	{
		type = MOVE_NONE;
	}

	switch (type)
	{
	case CMovelife::MOVE_NONE:
		a = 1;
		break;
	case CMovelife::MOVE:
		Sublife(2);
		break;
	case CMovelife::RETURN:
		{
			//増える処理
			Addlife(2);
		}
		break;
	default:
		break;
	}

	//// キーボードの情報取得
	//CInput *pInputKeyboard = CApplication::Getinstnce()->GetInput();
	//if (pInputKeyboard->Trigger(DIK_B))
	//{
	//	//増える処理
	//	Addlife(1);
	//}
	//if (pInputKeyboard->Trigger(DIK_N))
	//{
	//	//減る処理
	//	Sublife(1);
	//}

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
	int aPosTexU[5];	//各桁の数字を格納

	m_Life += nGain;

	aPosTexU[0] = m_Life % 100000 / 10000;
	aPosTexU[1] = m_Life % 10000 / 1000;
	aPosTexU[2] = m_Life % 1000 / 100;
	aPosTexU[3] = m_Life % 100 / 10;
	aPosTexU[4] = m_Life % 10 / 1;

	if (m_Life > 10000)
	{
		m_Life = 10000;
	}
	

	for (int nCount = 0; nCount < 5; nCount++)
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
	int aPosTexU[5];	//各桁の数字を格納

	m_Life -= nDecrease;

	if (m_Life <= 0)
	{//0以下だったら
		m_Life = 0;
	}

	aPosTexU[0] = m_Life % 100000 / 10000;
	aPosTexU[1] = m_Life % 10000 / 1000;
	aPosTexU[2] = m_Life % 1000 / 100;
	aPosTexU[3] = m_Life % 100 / 10;
	aPosTexU[4] = m_Life % 10 / 1;

	for (int nCount = 0; nCount < 5; nCount++)
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
	int aPosTexU[5];	//各桁の数字を格納

	m_Life = nLife;

	aPosTexU[0] = m_Life % 100000 / 10000;
	aPosTexU[1] = m_Life % 10000 / 1000;
	aPosTexU[2] = m_Life % 1000 / 100;
	aPosTexU[3] = m_Life % 100 / 10;
	aPosTexU[4] = m_Life % 10 / 1;

	for (int nCount = 0; nCount < 5; nCount++)
	{
		//テクスチャ設定
		pNumber[nCount]->ScoreVtx
		(0.1f * aPosTexU[nCount],
			0.0f,
			0.1f * aPosTexU[nCount] + 0.1f,
			1.0f);
	}
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
