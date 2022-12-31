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
	m_pTitle = CObject2D::Create("TITLE",D3DXVECTOR3((float)SCREEN_WIDTH_HALF,-20.0f,0.0f), D3DXVECTOR3(500.0f, 500.0f, 0.0f), PRIORITY_LEVEL0);

	//�v���C���[���͑I��
	m_pGame = CObject2D::Create("OMOIDE", D3DXVECTOR3((float)SCREEN_WIDTH_HALF -300, 500.0f, 0.0f), D3DXVECTOR3(300.0f, 300.0f, 0.0f), PRIORITY_LEVEL0);

	m_pRanking = CObject2D::Create("INIESUTA", D3DXVECTOR3((float)SCREEN_WIDTH_HALF + 300, 500.0f, 0.0f), D3DXVECTOR3(300.0f, 300.0f, 0.0f), PRIORITY_LEVEL0);


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
	{//�f�o�b�N����
		CDebugProc::Print("�J�ڂ̂��߂̑I���J�E���g : [%d]\n", m_modecount);
	}

	//�Q�[���l�[���̏��擾
	D3DXVECTOR3 Titlepos = m_pTitle->GetPos();

	//�^�C�g���~�܂鏈��
	if (Titlepos.y >= SCREEN_HEIGHT_HALF)
	{
		m_pTitle->SetMove(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	}
	else
	{
		m_pTitle->SetMove(D3DXVECTOR3(0.0f, 2.0f, 0.0f));
	}

	// �L�[�{�[�h�̏��擾
	CInput *pInputKeyboard = CApplication::Getinstnce()->GetInput();
	if (pInputKeyboard->Trigger(DIK_A))
	{// ��Ɉړ�
		m_modecount++;
	}
	if (pInputKeyboard->Trigger(DIK_D))
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

	//�I���ېF�̕ύX������₷��
	if (m_modecount == 1)
	{
		m_pGame->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
		m_pRanking->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));

	}
	if (m_modecount == 2)
	{
		m_pGame->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 0.5f));
		m_pRanking->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));
	}

	// ���͏����p�̃|�C���^�錾
	CInput *pInput = CApplication::Getinstnce()->GetInput();
	if (!m_bmodeflg)
	{
		if (pInput->Trigger(DIK_RETURN))		//�I���V�[�����s
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
				//�J��
				CFade::SetFade(CApplication::MODE_SELECT_STAGE);	//�Q�[���J��
			}
			if (m_modecount == 2)
			{
				//�J��
				CFade::SetFade(CApplication::MODE_RANKING); //�����L���O�J��
			}
		}
	}

	//�~�肫��܂ł�Enter���������ۈړ����I��������
	if (m_bmodeflg)
	{
		m_pTitle->SetPos(D3DXVECTOR3(SCREEN_WIDTH_HALF, SCREEN_HEIGHT_HALF, 0.0f));
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
