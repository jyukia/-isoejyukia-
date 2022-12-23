//=============================================================================
//
// Cpreparation.cpp
// Author : ��]����
//
//=============================================================================
//*****************************************************************************
// �C���N���[�h�t�@�C��
//*****************************************************************************
#include "Preparation.h"
//�R���X�g���N�^
Cpreparation::Cpreparation(int nPriority):ChangeCount(0)
{

}
//�f�X�g���N�^
Cpreparation::~Cpreparation()
{

}
//-----------------------------------------
//������
//-----------------------------------------
HRESULT Cpreparation::Init()
{
	{//������
		ChangeCount = 0;
	}

	CObject2D::Init();

	return S_OK;
}
//-----------------------------------------
//�X�V
//-----------------------------------------
void Cpreparation::Update()
{
	D3DXVECTOR3 pos = CObject2D::GetPos();
	D3DXVECTOR3 size = CObject2D::GetSize();
	D3DXVECTOR3 rot = CObject2D::GetRot();

	ChangeCount++;	//�e�N�X�`���ύX�J�E���g

	CObject2D::Update();
}

Cpreparation * Cpreparation::Create(const char *aFileName,D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot)
{
	Cpreparation* pPreparation = nullptr;
	//���I�m��
	pPreparation = new Cpreparation(CObject::PRIORITY_LEVEL3);

	if (pPreparation != nullptr)
	{
		//�ʒu���
		pPreparation->SetPos(pos);
		pPreparation->SetSize(size);
		pPreparation->SetRot(rot);
		pPreparation->SetCol(D3DXCOLOR(1.f,1.f,1.f,1.f));
		pPreparation->BindTexture(aFileName);
		pPreparation->Init();

	}
	else
	{//�������~�߂�
		assert(false);
	}

	return pPreparation;
}

