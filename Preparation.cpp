//=============================================================================
//
// Cpreparation.cpp
// Author : 磯江寿希亜
//
//=============================================================================
//*****************************************************************************
// インクルードファイル
//*****************************************************************************
#include "Preparation.h"
//コンストラクタ
Cpreparation::Cpreparation(int nPriority):ChangeCount(0)
{

}
//デストラクタ
Cpreparation::~Cpreparation()
{

}
//-----------------------------------------
//初期化
//-----------------------------------------
HRESULT Cpreparation::Init()
{
	{//初期化
		ChangeCount = 0;
	}

	CObject2D::Init();

	return S_OK;
}
//-----------------------------------------
//更新
//-----------------------------------------
void Cpreparation::Update()
{
	D3DXVECTOR3 pos = CObject2D::GetPos();
	D3DXVECTOR3 size = CObject2D::GetSize();
	D3DXVECTOR3 rot = CObject2D::GetRot();

	ChangeCount++;	//テクスチャ変更カウント

	CObject2D::Update();
}

Cpreparation * Cpreparation::Create(const char *aFileName,D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot)
{
	Cpreparation* pPreparation = nullptr;
	//動的確保
	pPreparation = new Cpreparation(CObject::PRIORITY_LEVEL3);

	if (pPreparation != nullptr)
	{
		//位置情報
		pPreparation->SetPos(pos);
		pPreparation->SetSize(size);
		pPreparation->SetRot(rot);
		pPreparation->SetCol(D3DXCOLOR(1.f,1.f,1.f,1.f));
		pPreparation->BindTexture(aFileName);
		pPreparation->Init();

	}
	else
	{//処理を止める
		assert(false);
	}

	return pPreparation;
}

