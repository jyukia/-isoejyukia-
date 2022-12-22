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

	size = D3DXVECTOR3(200.0f,200.0f,0.0f);




	CObject2D::SetPos(pos);
	CObject2D::SetSize(size);
	CObject2D::SetRot(rot);

	CObject2D::Update();
}

Cpreparation * Cpreparation::Create(const char *aFileName,D3DXVECTOR3 pos, D3DXVECTOR3 size, D3DXVECTOR3 rot)
{
	Cpreparation* pPreparation = nullptr;
	//���I�m��
	pPreparation = new Cpreparation(3);

	if (pPreparation != nullptr)
	{
		pPreparation->Init();

		pPreparation->BindTexture(aFileName);

		pPreparation->SetSize(size);
		//�ʒu���
		pPreparation->SetPos(pos);

		pPreparation->SetRot(rot);
	}
	else
	{//�������~�߂�
		assert(false);
	}

	return pPreparation;
}

