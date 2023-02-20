#include"SelectStage.h"
#include "main.h"
#include "renderer.h"
#include "application.h"
#include "input.h"
#include "fade.h"
#include "objectX.h"
#include "object3D.h"
#include "object2D.h"
#include "light.h"
#include"DebugProc.h"
#include"joypad.h"

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
LPDIRECT3DTEXTURE9 CSelectStage::m_pTexture = nullptr;

CLight *CSelectStage::m_pLight = nullptr;

int CSelectStage::m_modeSelectcount;

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CSelectStage::CSelectStage(): m_bmodeflg(false)
{
}
//=============================================================================
// �f�X�g���N�^
//=============================================================================
CSelectStage::~CSelectStage()
{
}
//=============================================================================
// ����������
//=============================================================================
HRESULT CSelectStage::Init(void)
{
	{//�ϐ�������
		m_modeSelectcount = 1;
		m_bmodeflg = false;
	}

	//���C�g�̐���
	m_pLight = CLight::Create();

	//�X�e�[�W�I��
	CObject2D* selectstage = CObject2D::Create("SELECTSTAGE", D3DXVECTOR3(1000.0f, 40.0f, 0.0f), D3DXVECTOR3(600.0f, 400.0f, 0.0f), CObject::PRIORITY_LEVEL3);

	//1�ڂ̃X�e�[�W��
	stagename = CObject2D::Create("STAGENAME", D3DXVECTOR3(300.0f, 600.0f, 0.0f), D3DXVECTOR3(600.0f, 400.0f, 0.0f), CObject::PRIORITY_LEVEL3);
	//2�ڂ̃X�e�[�W��
	stagename1 = CObject2D::Create("STAGENAME1", D3DXVECTOR3(300.0f, 600.0f, 0.0f), D3DXVECTOR3(600.0f, 400.0f, 0.0f), CObject::PRIORITY_LEVEL3);

	//�X�e�[�W�ʒu
	D3DXVECTOR3 pos = D3DXVECTOR3(730.0f, 10.0f, 0.0f);
	D3DXVECTOR3 pos1 = D3DXVECTOR3(0.0f, 10.0f, 0.0f);
	//�X�e�[�W1
	pStage = CObjectX::Create(pos, CObject::PRIORITY_LEVEL3);
	pStage->LoadModel("MAP1");
	//�X�e�[�W2
	pStage1 = CObjectX::Create(pos1, CObject::PRIORITY_LEVEL3);
	pStage1->LoadModel("MAP2");

	return S_OK;
}
//=============================================================================
// �I������
//=============================================================================
void CSelectStage::Uninit(void)
{
	//���C�g�̉���E�폜
	if (m_pLight != nullptr)
	{
		m_pLight->Uninit();
		delete m_pLight;
		m_pLight = nullptr;
	}

	//�C���X�^���X�̉������
	CObject::Release();
}
//=============================================================================
// �X�V����
//=============================================================================
void CSelectStage::Update(void)
{
//�~�̌v�Z��
	//�v�Z��
	//radius = m_Angle * 3.14f / 180.0f;
	//// �O�p�֐����g�p���A�~�̈ʒu������o���B
	//add_x = cos(radius) * 10;
	//add_z = sin(radius) * 10;
	////������ς���
	//m_Angle += 3.0f;
	//
	//CDebugProc::Print("add_x : %f\n", add_x);
	//CDebugProc::Print("add_z : %f\n", add_z);

	CDebugProc::Print("m_modeSelectcount : %d\n", m_modeSelectcount);

	//=====================================
	//1�ڂ̃}�b�v�錾�Ə���
	D3DXVECTOR3 pos = pStage->GetPos();
	D3DXVECTOR3 rot = pStage->GetRot();
	//=====================================
	//2�ڂ̃}�b�v�錾�Ə���
	D3DXVECTOR3 pos1 = pStage1->GetPos();
	D3DXVECTOR3 rot1 = pStage1->GetRot();

	// ���͏����p�̃|�C���^�錾
	CInput *pInput = CApplication::Getinstnce()->GetInput();
	//�R���g���[���[
	CJoypad *pJoy = CApplication::GetJoy();

	if (m_modeSelectcount == 1)
	{
		//���f���̉�]�ύX����
		rot.y += 0.01f;

		//1�ڂ̃X�e�[�W��
		stagename->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		//2�ڂ̃X�e�[�W��
		stagename1->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
		if (m_pFade->GetFade() == CFade::FADE_NONE)
		{

			if (pInput->Trigger(DIK_RETURN) || pJoy->GetTrigger(CJoypad::JOYKEY_A, 0))
			{
				//�J��
				CFade::SetFade(CApplication::MODE_GAME);	//�Q�[���J��
			}
		}
	}
	if (m_modeSelectcount == 2)
	{
		//���f���̉�]�ύX����
		rot1.y += 0.01f;

		//1�ڂ̃X�e�[�W��
		stagename->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.0f));
		//2�ڂ̃X�e�[�W��
		stagename1->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));

		if (m_pFade->GetFade() == CFade::FADE_NONE)
		{
			if (pInput->Trigger(DIK_RETURN) || pJoy->GetTrigger(CJoypad::JOYKEY_A, 0))
			{
				//�J��
				CFade::SetFade(CApplication::MODE_GAME1);	//�Q�[���J��
			}
		}
	}
	if (m_pFade->GetFade() == CFade::FADE_NONE)	//�@�^�C�g���ɖ߂鏈��
	{
		if (pInput->Trigger(DIK_ESCAPE) || pJoy->GetTrigger(CJoypad::JOYKEY_B, 0))
		{
			//�J��
			CFade::SetFade(CApplication::MODE_TITLE);	//�Q�[���J��
		}
	}
	//=====================================
	pStage->SetPos(pos);
	pStage->SetRot(rot);
	//=====================================
	pStage1->SetPos(pos1);
	pStage1->SetRot(rot1);
	//=====================================

	//�I���J�E���g�̐���
	if (m_modeSelectcount > m_modeMax)
	{
		m_modeSelectcount = m_modeMin;
	}
	if (m_modeSelectcount < m_modeMin)
	{
		m_modeSelectcount = m_modeMax;
	}

	//�Z���N�g�̈ړ�
	if (pInput->Trigger(DIK_D) || pJoy->GetTrigger(CJoypad::JOYKEY_RIGHT, 0))
	{
		m_modeSelectcount++;
	}
	if (pInput->Trigger(DIK_A) || pJoy->GetTrigger(CJoypad::JOYKEY_LEFT, 0))
	{
		m_modeSelectcount--;
	}
}
//=============================================================================
// �`�揈��
//=============================================================================
void CSelectStage::Draw(void)
{

}
//=============================================================================
// ��������
//=============================================================================
CSelectStage * CSelectStage::Create()
{
	//�|�C���^�錾
	CSelectStage *pSelectStage = nullptr;

	//�C���X�^���X����
	pSelectStage = new CSelectStage;

	if (pSelectStage != nullptr)
	{//�|�C���^�����݂�������s
		pSelectStage->Init();
	}
	else
	{//�|�C���^����������������s
		assert(false);
	}

	//�|�C���^��Ԃ�
	return pSelectStage;
}
