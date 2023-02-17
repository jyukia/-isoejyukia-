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
#include "mode.h"
#include"Meshline.h"
#include"player.h"
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

	for (int numberCnt = 0; numberCnt <5; numberCnt++)
	{
		pNumber[numberCnt] = CNumber::Create("NUMBER", D3DXVECTOR3(50.0f + numberCnt *45.0f, 360.0f, 0.0f), D3DXVECTOR3(35.0f, 40.0f, 0.0f), D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f), 3);
	}

	Setlife(10000);

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

	//�v���C���[���
	D3DXVECTOR3 Playerpos = CApplication::Getinstnce()->GetpMode()->GetPlayer()->GetPos();
	D3DXVECTOR3 PlayerposOld = CMode::GetPlayer()->GetPosOld();
	bool flg =CApplication::Getinstnce()->GetpMode()->GetMeshLine()->GetbIsLanding();
	CInput *pInputKeyboard = CApplication::Getinstnce()->GetInput();

	//���鏈��
	if (pInputKeyboard->Press(DIK_R))
	{
		type = RETURN;
	}
	else if (Playerpos != PlayerposOld)	//�����Ă�����@�ړ����C�t�����炷
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
			//�����鏈��
			Addlife(2);
		}
		break;
	default:
		break;
	}

	//// �L�[�{�[�h�̏��擾
	//CInput *pInputKeyboard = CApplication::Getinstnce()->GetInput();
	//if (pInputKeyboard->Trigger(DIK_B))
	//{
	//	//�����鏈��
	//	Addlife(1);
	//}
	//if (pInputKeyboard->Trigger(DIK_N))
	//{
	//	//���鏈��
	//	Sublife(1);
	//}

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
	int aPosTexU[5];	//�e���̐������i�[

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
	int aPosTexU[5];	//�e���̐������i�[

	m_Life -= nDecrease;

	if (m_Life <= 0)
	{//0�ȉ���������
		m_Life = 0;
	}

	aPosTexU[0] = m_Life % 100000 / 10000;
	aPosTexU[1] = m_Life % 10000 / 1000;
	aPosTexU[2] = m_Life % 1000 / 100;
	aPosTexU[3] = m_Life % 100 / 10;
	aPosTexU[4] = m_Life % 10 / 1;

	for (int nCount = 0; nCount < 5; nCount++)
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
	int aPosTexU[5];	//�e���̐������i�[

	m_Life = nLife;

	aPosTexU[0] = m_Life % 100000 / 10000;
	aPosTexU[1] = m_Life % 10000 / 1000;
	aPosTexU[2] = m_Life % 1000 / 100;
	aPosTexU[3] = m_Life % 100 / 10;
	aPosTexU[4] = m_Life % 10 / 1;

	for (int nCount = 0; nCount < 5; nCount++)
	{
		//�e�N�X�`���ݒ�
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
