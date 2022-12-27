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
#include "game1.h"
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

#include "movelife.h"
#include "Preparation.h"

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
CPlayer *CGame1::m_pPlayer = nullptr;
CMeshfield *CGame1::m_pMeshField = nullptr;
CLight *CGame1::m_pLight = nullptr;
CScore* CGame1::pScore = nullptr;
CMovelife* CGame1::pMovelife = nullptr;
CGoal* CGame1::m_pGoal = nullptr;
//=============================================================================
// �R���X�g���N�^
//=============================================================================
CGame1::CGame1()
{

}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CGame1::~CGame1()
{

}

//=============================================================================
// ����������
//=============================================================================
HRESULT CGame1::Init(void)
{
	{//������
		m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	}

	//���f���ǂݍ��݈�ԏ�ɔz�u
	OutputStatus();

	//���C�g�̐���
	m_pLight = CLight::Create();

	//���b�V���t�B�[���h�̐���
	m_pMeshField = CMeshfield::Create(D3DXVECTOR3(-1500.0f, 0.0f, 1500.0f), CObject::PRIORITY_LEVEL3);

	//�v���C���[�̐���
	CApplication::GetpMode()->SetPlayer(CPlayer::Create(D3DXVECTOR3(110.0f, 610.0f, -600.0f), CObject::PRIORITY_LEVEL3));
	CApplication::GetpMode()->GetPlayer()->LoadModel("Kedama");

	m_pGoal = CGoal::Create(D3DXVECTOR3(1100.0f, 610.0f, -600.0f), CObject::PRIORITY_LEVEL3);
	m_pGoal->LoadModel("Kedama");

	//�R���p�X����
	m_pCompass = CObject2D::Create("COMPASS", D3DXVECTOR3(1150.0f, 110.0f, 0.0f), D3DXVECTOR3(220.0f, 220.0f, 0.0f), CObject::PRIORITY_LEVEL3);

	pScore = CScore::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f));

	pMovelife = CMovelife::Create(D3DXVECTOR3(0.0f, 0.0f, 0.0f), CObject::PRIORITY_LEVEL3);

	//�Q�[���J�n�̍��}
	m_pPreparation->Create("REDY", D3DXVECTOR3(SCREEN_WIDTH + 100, SCREEN_HEIGHT_HALF, 0.0f), D3DXVECTOR3(1000.0f, 1000.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f), CObject::PRIORITY_LEVEL3);

	Load();

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CGame1::Uninit(void)
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
void CGame1::Update(void)
{
	// ���͏����p�̃|�C���^�錾
	CInput *pInput = CApplication::GetInput();

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
void CGame1::Draw(void)
{

}

//=============================================================================
// ��������
//=============================================================================
CGame1 * CGame1::Create()
{
	//�|�C���^�錾
	CGame1 *pGame = nullptr;

	//�C���X�^���X����
	pGame = new CGame1;

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