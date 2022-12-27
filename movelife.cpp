//=============================================================================
//
// movelife.cpp
// Author : ��]����
//
//=============================================================================
//*****************************************************************************
// �C���N���[�h�t�@�C��
//*****************************************************************************

#include "movelife.h"
#include"input.h"

//�R���X�g���N�^
CMovelife::CMovelife(int nPriority)
{
}
//�f�X�g���N�^
CMovelife::~CMovelife()
{
}
//-----------------------------------------
//������
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
//�I��
//-----------------------------------------
void CMovelife::Uninit()
{
}
//-----------------------------------------
//�X�V
//-----------------------------------------
void CMovelife::Update()
{
	D3DXVECTOR3 pos = CObject2D::GetPos();

	// �L�[�{�[�h�̏��擾
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
//�`��
//-----------------------------------------
void CMovelife::Draw()
{
}
//���Z����
void CMovelife::Addlife(int nGain)
{
	int aPosTexU[3];	//�e���̐������i�[

	m_Life += nGain;

	aPosTexU[0] = m_Life % 1000 / 100;
	aPosTexU[1] = m_Life % 100 / 10;
	aPosTexU[2] = m_Life % 10 / 1;

	for (int nCount = 0; nCount < 3; nCount++)
	{
		//�e�N�X�`���ݒ�
		pNumber[nCount]->ScoreVtx
		(0.1f * aPosTexU[nCount],
			0.0f,
			0.1f * aPosTexU[nCount] + 0.1f,
			1.0f);
	}
}
//���Z����
void CMovelife::Sublife(int nDecrease)
{
	int aPosTexU[3];	//�e���̐������i�[

	m_Life -= nDecrease;

	if (m_Life <= 0)
	{//0�ȉ���������
		m_Life = 0;
	}

	aPosTexU[0] = m_Life % 1000 / 100;
	aPosTexU[1] = m_Life % 100 / 10;
	aPosTexU[2] = m_Life % 10 / 1;

	for (int nCount = 0; nCount < 3; nCount++)
	{
		//�e�N�X�`���ݒ�
		pNumber[nCount]->ScoreVtx
		(0.1f * aPosTexU[nCount],
			0.0f,
			0.1f * aPosTexU[nCount] + 0.1f,
			1.0f);
	}
}
//�X�R�A�ݒ菈��
void CMovelife::Setlife(int nLife)
{
	int aPosTexU[3];	//�e���̐������i�[

	m_Life = nLife;

	aPosTexU[0] = m_Life % 1000 / 100;
	aPosTexU[1] = m_Life % 100 / 10;
	aPosTexU[2] = m_Life % 10 / 1;

}

CMovelife * CMovelife::Create(D3DXVECTOR3 pos,int nPriority)
{
	CMovelife* pLife = nullptr;
	//���I�m��
	pLife = new CMovelife(nPriority);

	if (pLife != nullptr)
	{
		pLife->Init();

		//�ʒu���
		pLife->SetPos(pos);

	}
	else
	{//�������~�߂�
		assert(false);
	}

	return pLife;
}
