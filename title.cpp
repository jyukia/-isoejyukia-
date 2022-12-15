//=============================================================================
// �C���N���[�h�t�@�C��
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
// �ÓI�����o�ϐ��錾
//=============================================================================
LPDIRECT3DTEXTURE9 CTitle::m_pTexture = nullptr;

CPlayer *CTitle::m_pPlayer = nullptr;
CMeshfield *CTitle::m_pMeshField = nullptr;
CLight *CTitle::m_pLight = nullptr;

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CTitle::CTitle():m_modecount(0), m_bmodeflg(false)
{

}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CTitle::~CTitle()
{

}

//=============================================================================
// ����������
//=============================================================================
HRESULT CTitle::Init(void)
{
	{//������
		m_modecount = 1;
		m_bmodeflg = false;
	}

	//�^�C�g���z�u
	Title = CObject2D::Create("TITLE",D3DXVECTOR3((float)SCREEN_WIDTH_HALF,-20.0f,0.0f), D3DXVECTOR3(500.0f, 500.0f, 0.0f), PRIORITY_LEVEL0);

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CTitle::Uninit(void)
{
	//�C���X�^���X�̉������
	CObject::Release();
}

//=============================================================================
// �X�V����
//=============================================================================
void CTitle::Update(void)
{
	{
		CDebugProc::Print("�J�ڂ̂��߂̑I���J�E���g : [%d]\n", m_modecount);
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

	// �L�[�{�[�h�̏��擾
	CInput *pInputKeyboard = CApplication::GetInput();
	if (pInputKeyboard->Trigger(DIK_W))
	{// ��Ɉړ�
		m_modecount++;
	}
	if (pInputKeyboard->Trigger(DIK_S))
	{// ���Ɉړ�
		m_modecount--;
	}
	//�I���J�E���g�̐���
	if (m_modecount > m_modeMax)
	{
		m_modecount = m_modeMin;
	}
	if (m_modecount < m_modeMin)
	{
		m_modecount = m_modeMax;
	}


	// ���͏����p�̃|�C���^�錾
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
				// �J��
				CFade::SetFade(CApplication::MODE_GAME);
			}
			if (m_modecount == 2)
			{
				// �J��
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
// �`�揈��
//=============================================================================
void CTitle::Draw(void)
{

}

//=============================================================================
// ��������
//=============================================================================
CTitle * CTitle::Create()
{
	//�|�C���^�錾
	CTitle *pTitle = nullptr;

	//�C���X�^���X����
	pTitle = new CTitle;

	if (pTitle != nullptr)
	{//�|�C���^�����݂�������s
		pTitle->Init();
	}
	else
	{//�|�C���^����������������s
		assert(false);
	}

	//�|�C���^��Ԃ�
	return pTitle;
}
