//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "application.h"
#include "renderer.h"
#include "object.h"
#include "input.h"
#include "camera.h"
#include "light.h"
#include "texture.h"
#include "title.h"

#include "game.h"
#include "game1.h"

#include "ranking.h"
#include "tutorial.h"
#include "fade.h"
#include "objectX_group.h"
#include "sound.h"
#include"DebugProc.h"
#include"SelectStage.h"

#include"stage_imgui.h"

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
CApplication *CApplication::m_pApplication = nullptr;
//=============================================================================
// �R���X�g���N�^
//=============================================================================
CApplication::CApplication():m_pRenderer(nullptr), m_pInput(nullptr), m_pMode(nullptr), m_pCamera(nullptr), m_pTexture(nullptr), m_pObjectXGroup(nullptr), m_pSound(nullptr), m_pDebugProc(nullptr), m_Imgui(nullptr)
{
	CApplication::m_mode = MODE_SELECT_STAGE;
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CApplication::~CApplication()
{

}

//=============================================================================
// ����������
//=============================================================================
HRESULT CApplication::Init(HINSTANCE hInstance, HWND hWnd, bool bWindow)
{
	//�����̏�����
	srand((unsigned int)time(0));

	//�����_�����O�N���X�̐���
	m_pRenderer = new CRenderer;
	//�����_�����O�̏���������
	if (FAILED(m_pRenderer->Init(hWnd, bWindow)))
	{ //���������������s�����ꍇ
		return -1;
	}

	//�C���v�b�g�N���X�̐���
	m_pInput = CInput::Create();
	//�C���v�b�g�̏���������
	if (FAILED(m_pInput->Init(hInstance, hWnd)))
	{ //���������������s�����ꍇ
		return -1;
	}

	m_pDebugProc = new CDebugProc;
	// ������
	assert(m_pDebugProc != nullptr);
	m_pDebugProc->Init();

	LPDIRECT3DDEVICE9 pDevice = m_pRenderer->GetDevice();
	m_Imgui = new CStageImgui;
	// ������
	assert(m_Imgui != nullptr);
	m_Imgui->Init(hWnd, pDevice);


	// �J�����̏�����
	m_pCamera = new CCamera;

	// �e�N�X�`���̐���
	m_pTexture = new CTexture;
	m_pTexture->LoadAll();

	// ���f���̐���
	m_pObjectXGroup = new CObjectXGroup;
	m_pObjectXGroup->LoadAll();

	// �T�E���h�̐���
	m_pSound = new CSound;
	m_pSound->Init(hWnd);

	//���[�h����
	CFade::Create(m_mode);

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CApplication::Uninit(void)
{
	//�I�u�W�F�N�g�̑S�J��
	CObject::UninitAll();

	// �e�N�X�`���̍폜
	if (m_pTexture != nullptr)
	{
		m_pTexture->UnloadAll();
		delete m_pTexture;
		m_pTexture = nullptr;
	}
	//�f�o�b�N�\��
	if (m_pDebugProc != nullptr)
	{// �I������
		m_pDebugProc->Uninit();

		// �������̉��
		delete m_pDebugProc;
		m_pDebugProc = nullptr;
	}

	// �T�E���h�̍폜
	if (m_pSound != nullptr)
	{
		m_pSound->Uninit();
		delete m_pSound;
		m_pSound = nullptr;
	}

	// X���f���̍폜
	if (m_pObjectXGroup != nullptr)
	{
		m_pObjectXGroup->UnloadAll();
		delete m_pObjectXGroup;
		m_pObjectXGroup = nullptr;
	}

	//�����_�����O�̉���E�폜
	if (m_pRenderer != nullptr)
	{
		m_pRenderer->Uninit();
		delete m_pRenderer;
		m_pRenderer = nullptr;
	}

	//�C���v�b�g�̉���E�폜
	if (m_pInput != nullptr)
	{
		m_pInput->Uninit();
		delete m_pInput;
		m_pInput = nullptr;
	}

	//�J�����̉���E�폜
	if (m_pCamera != nullptr)
	{
		m_pCamera->Uninit();
		delete m_pCamera;
		m_pCamera = nullptr;
	}
	//imgui�̉��
	if (m_Imgui != nullptr)
	{
		//m_Imgui->Uninit();
		delete m_Imgui;
		m_Imgui = nullptr;
	}

}

//=============================================================================
// �X�V����
//=============================================================================
void CApplication::Update(void)
{
#ifdef _DEBUG
	int FPS = GetFPS();

	CDebugProc::Print("�t���[�����[�g : %d\n", FPS);

	CDebugProc::Print("���݂̉�ʑJ�ڔԍ� : [%d] \n", m_mode);

#endif // _DEBUG
	//�C���v�b�g�̍X�V����
	if (m_pInput != nullptr)
	{
		m_pInput->Update();
	}
	//�����_�����O�̍X�V����
	if (m_pRenderer != nullptr)
	{
		m_pRenderer->Update();
	}

	//�J�����̍X�V����
	if (m_pCamera != nullptr)
	{
		m_pCamera->Update();
	}

	//imgui�̍X�V����
	if (m_Imgui != nullptr)
	{
		m_Imgui->Update();
	}
}

//=============================================================================
// �`�揈��
//=============================================================================
void CApplication::Draw(void)
{
	//�����_�����O�̕`�揈��
	if (m_pRenderer != nullptr)
	{
		m_pRenderer->Draw();
	}
	//imgui�̕`�揈��
	if (m_Imgui != nullptr)
	{
		m_Imgui->Draw();
	}

}

//=============================================================================
// �����_�����O�̃|�C���^��Ԃ�����
//=============================================================================
CRenderer * CApplication::GetRenderer()
{
	return m_pRenderer;
}

//=============================================================================
// �C���v�b�g�̃|�C���^��Ԃ�����
//=============================================================================
CInput * CApplication::GetInput()
{
	return m_pInput;
}

//=============================================================================
// ���[�h�Z�b�g����
//=============================================================================
void CApplication::SetMode(MODE mode)
{
	if (m_pMode != nullptr)
	{
		m_pMode->Uninit();
		m_pMode = nullptr;
	}

	CObject::ModeRelease();

	m_mode = mode;

	m_pCamera->Init();

	switch (m_mode)
	{
	case MODE_TITLE:
		m_pMode = CTitle::Create();			//
		break;
	case MODE_GAME:
		m_pMode = CGame::Create();			//
		break;
	case MODE_GAME1:
		m_pMode = CGame1::Create();			//
		break;
	case MODE_SELECT_STAGE:			//�X�e�[�W�I��
		m_pMode = CSelectStage::Create();
		break;
	case MODE_RANKING:
		m_pMode = CRanking::Create();			//
		CRanking::SetRankingScore();
		break;
	case MODE_TUTORIAL:			//
		m_pMode = CTutorial::Create();
		break;
	}
}

//=============================================================================
// ���[�h���擾���鏈��
//=============================================================================
CApplication::MODE CApplication::GetMode()
{
	return m_mode;
}