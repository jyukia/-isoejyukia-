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

	size = D3DXVECTOR3(200.0f,200.0f,0.0f);




	CObject2D::SetPos(pos);
	CObject2D::SetSize(size);
	CObject2D::SetRot(rot);

	CObject2D::Update();
}

Cpreparation * Cpreparation::Create(const char *aFileName,D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot)
{
	Cpreparation* pPreparation = nullptr;
	//動的確保
	pPreparation = new Cpreparation(3);

	if (pPreparation != nullptr)
	{
		pPreparation->Init();

		pPreparation->BindTexture(aFileName);

		pPreparation->SetSize(size);
		//位置情報
		pPreparation->SetPos(pos);

		pPreparation->SetRot(rot);
	}
	else
	{//処理を止める
		assert(false);
	}

	return pPreparation;
}

