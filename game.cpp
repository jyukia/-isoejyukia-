//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "application.h"
#include "renderer.h"
#include "objectX.h"
#include "object3D.h"
#include "object2D.h"
#include "object.h"
#include "input.h"
#include "title.h"
#include "game.h"
#include "fade.h"
#include "player.h"
#include "light.h"
#include "meshfield.h"
#include "camera.h"
#include "Meshline.h"
#include"Number.h"
#include"score.h"
#include "file.h"
#include "goal.h"
#include "load_stage.h"

#include "movelife.h"
#include "Preparation.h"
#include "mode.h"

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
CMeshfield *CGame::m_pMeshField = nullptr;
CLight *CGame::m_pLight = nullptr;
CScore* CGame::pScore = nullptr;
CMovelife* CGame::pMovelife = nullptr;
CGoal* CGame::m_pGoal = nullptr;
//=============================================================================
// �R���X�g���N�^
//=============================================================================
CGame::CGame()
{

}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CGame::~CGame()
{

}

//=============================================================================
// ����������
//=============================================================================
HRESULT CGame::Init(void)
{
	//���C�g�̐���
	m_pLight = CLight::Create();
	{//������
		m_rot = D3DXVECTOR3(0.0f,0.0f,0.0f);
	}

	//���f���ǂݍ��݈�ԏ�ɔz�u
//	OutputStatus();

	//���b�V���t�B�[���h�̐���
	m_pMeshField = CMeshfield::Create(D3DXVECTOR3(-1500.0f, 0.0f, 1500.0f), CObject::PRIORITY_LEVEL3);
	m_pMeshField->LoadTexture("Data\\TEXTURE\\wood.png");


	//�v���C���[�̐���
	CApplication::Getinstnce()->GetpMode()->SetPlayer(CPlayer::Create(D3DXVECTOR3(110.0f, 610.0f, -600.0f), CObject::PRIORITY_LEVEL3));
	CApplication::Getinstnce()->GetpMode()->GetPlayer()->LoadModel("Kedama");

	m_pGoal = CGoal::Create(D3DXVECTOR3(1890.0f, 605.0f, -2300.0f), CObject::PRIORITY_LEVEL3);
	m_pGoal->LoadModel("Kedama");
	m_pGoal->Setstring("GOAL");

	{//��
		D3DXVECTOR3 WallSize(3050, 0.0f, 1000.0f);

		CObject3D* wallX = CObject3D::Create(D3DXVECTOR3(1300.0f, 700.0f, 1750.0f), D3DXVECTOR3(-D3DX_PI / 2.0f, 0.0f, 0.0f), WallSize,3);
		wallX->LoadTexture("Data/TEXTURE/Background_6.png");

		CObject3D* wallX1 = CObject3D::Create(D3DXVECTOR3(1300.0f, 700.0f, -4300.0f), D3DXVECTOR3(-D3DX_PI / 2.0f, 0.0f, D3DX_PI), WallSize, 3);
		wallX1->LoadTexture("Data/TEXTURE/Background_6.png");

		CObject3D* wallX2 = CObject3D::Create(D3DXVECTOR3(4300.0f, 700.0f, -1300.0f), D3DXVECTOR3(-D3DX_PI / 2.0f, 0.0f, D3DX_PI / 2), WallSize, 3);
		wallX2->LoadTexture("Data/TEXTURE/Background_6.png");

		CObject3D* wallX3 = CObject3D::Create(D3DXVECTOR3(-1700.0f, 700.0f, -1300.0f), D3DXVECTOR3(-D3DX_PI / 2.0f, 0.0f, -D3DX_PI / 2), WallSize, 3);
		wallX3->LoadTexture("Data/TEXTURE/Background_6.png");
	}

	{//�ʐ^
		float lch = -2600;
		CObject3D* me = CObject3D::Create(D3DXVECTOR3(100.0f, 500.0f, -1680.0f + lch), D3DXVECTOR3(-D3DX_PI / 2.0f, 0.0f, D3DX_PI), D3DXVECTOR3(150, 0.0f, 200.0f), 3);
		me->LoadTexture("Data/TEXTURE/01.png");

		CObject3D* memory = CObject3D::Create(D3DXVECTOR3(1250.0f, 680.0f, -1098.0f), D3DXVECTOR3(-D3DX_PI / 1.83f, D3DX_PI, D3DX_PI), D3DXVECTOR3(50, 0.0f, 70.0f), 3);
		memory->LoadTexture("Data/TEXTURE/omoide.png");
	}
	//�R���p�X����
	m_pCompass = CObject2D::Create("COMPASS", D3DXVECTOR3(1150.0f, 110.0f, 0.0f), D3DXVECTOR3(220.0f, 220.0f, 0.0f), CObject::PRIORITY_LEVEL3);

	pScore = CScore::Create(D3DXVECTOR3(0.0f,0.0f, 0.0f));

	pMovelife = CMovelife::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), CObject::PRIORITY_LEVEL3);

	//�Q�[���J�n�̍��}
	m_pPreparation->Create("REDY", D3DXVECTOR3(SCREEN_WIDTH+100, SCREEN_HEIGHT_HALF, 0.0f), D3DXVECTOR3(1000.0f, 1000.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f),CObject::PRIORITY_LEVEL3);

	CLoadStage::LoadAllTest(0);

	//Load();

	//CLoadStage::SaveAll();

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CGame::Uninit(void)
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
void CGame::Update(void)
{
	// ���͏����p�̃|�C���^�錾
	CInput *pInput = CApplication::Getinstnce()->GetInput();

	if (m_pFade->GetFade() == CFade::FADE_NONE)
	{
		if (pInput->Trigger(DIK_RETURN))
		{
			// �J��
			CFade::SetFade(CApplication::MODE_RANKING);
		}
	}

	//�R���p�X����
	{
		m_rot = CCamera::GetRot();
		m_rot.z = m_rot.y;
		if (pInput->Press(DIK_Q))
		{
			m_rot.z += 0.05f;
		}
		if (pInput->Press(DIK_E))
		{
			m_rot.z -= 0.05f;
		}
		m_rot.y *= -1;
		m_pCompass->SetRot(m_rot);
	}

}

//=============================================================================
// �`�揈��
//=============================================================================
void CGame::Draw(void)
{

}

//=============================================================================
// ��������
//=============================================================================
CGame * CGame::Create()
{
	//�|�C���^�錾
	CGame *pGame = nullptr;

	//�C���X�^���X����
	pGame = new CGame;

	if (pGame != nullptr)
	{//�|�C���^�����݂�������s
		pGame->Init();
	}
	else
	{//�|�C���^����������������s
		assert(false);
	}

	//�|�C���^��Ԃ�
	return pGame;
}