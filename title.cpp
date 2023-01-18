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
#include "Meshline.h"
#include "camera.h"
#include"DebugProc.h"
#include "load_stage.h"
#include"skyfield.h"

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
LPDIRECT3DTEXTURE9 CTitle::m_pTexture = nullptr;

CPlayer *CTitle::m_pPlayer = nullptr;
CMeshfield *CTitle::m_pMeshField = nullptr;
CLight *CTitle::m_pLight = nullptr;
CMeshLine *m_pMeshLine = nullptr;			//	���b�V�����C��

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
	//���C�g�̐���
	m_pLight = CLight::Create();

	{//������
		m_modecount = 1;
		m_bmodeflg = false;
	}

	//�v���C���[�̐���
	CApplication::Getinstnce()->GetpMode()->SetPlayer(CPlayer::Create(D3DXVECTOR3(1850.0f, 20.0f, -600.0f), CObject::PRIORITY_LEVEL3));
	CApplication::Getinstnce()->GetpMode()->GetPlayer()->LoadModel("Kedama");

	{//��
		for (int cont = 0; cont < 5; cont++)
		{
			CObjectX* wallX = CObjectX::CObjectX::Create("FENCE", D3DXVECTOR3(700 + 520 * cont, 0, -3500), 3);
		}
		for (int cont = 0; cont < 6; cont++)
		{
			CObjectX* wallX1 = CObjectX::CObjectX::Create("FENCEROT", D3DXVECTOR3(3000, 0, -3200 + 515 * cont), 3);
		}
		for (int cont = 0; cont < 5; cont++)
		{
			CObjectX* wallX2 = CObjectX::CObjectX::Create("FENCE", D3DXVECTOR3(2780 - 515 * cont, 0, -350), 3);
		}
		for (int cont = 0; cont < 6; cont++)
		{
			CObjectX* wallX3 = CObjectX::CObjectX::Create("FENCEROT", D3DXVECTOR3(450, 0, -3200 + 515 * cont), 3);
		}
	}

	//���b�V���t�B�[���h�̐���
	m_pMeshField = CMeshfield::Create(D3DXVECTOR3(-1500.0f, 0.0f, 1500.0f), CObject::PRIORITY_LEVEL3);
	m_pMeshField->LoadTexture("Data\\TEXTURE\\shiba.png");

	//�^�C�g���z�u
	m_pTitle = CObject2D::Create("TITLE",D3DXVECTOR3((float)SCREEN_WIDTH_HALF,-20.0f,0.0f), D3DXVECTOR3(500.0f, 500.0f, 0.0f), PRIORITY_LEVEL5);

	//�v���C���[���͑I��
	m_pGame = CObject2D::Create("OMOIDE", D3DXVECTOR3((float)SCREEN_WIDTH_HALF -300, 500.0f, 0.0f), D3DXVECTOR3(300.0f, 300.0f, 0.0f), PRIORITY_LEVEL5);
	
	m_pRanking = CObject2D::Create("INIESUTA", D3DXVECTOR3((float)SCREEN_WIDTH_HALF + 300, 500.0f, 0.0f), D3DXVECTOR3(300.0f, 300.0f, 0.0f), PRIORITY_LEVEL5);

	CSkyField::Create();

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CTitle::Uninit(void)
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
void CTitle::Update(void)
{
	{//�f�o�b�N����
		CDebugProc::Print("�J�ڂ̂��߂̑I���J�E���g : [%d]\n", m_modecount);
	}

	D3DXVECTOR3 move = CApplication::Getinstnce()->GetpMode()->GetPlayer()->GetMove();

	bool flg = CApplication::Getinstnce()->GetpMode()->GetPlayer()->GetMoveFlg();

	if (flg)	//�ړ���
	{
		move.z -= 3;
	}
	else	//�ړ��s��
	{
		move.z = 0;
	}

	CApplication::Getinstnce()->GetpMode()->GetPlayer()->SetMove(move);

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
	if (!m_bmodeflg)	//�t�F�[�h�L�����Z��
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
