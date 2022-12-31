//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "camera.h"
#include "application.h"
#include "renderer.h"
#include "input.h"
#include "player.h"
#include "game.h"
#include"DebugProc.h"
#include"SelectStage.h"

#include <math.h>

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
D3DXVECTOR3 CCamera::m_rot;
//=============================================================================
// �R���X�g���N�^
//=============================================================================
CCamera::CCamera()
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CCamera::~CCamera()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CCamera::Init(void)
{
	m_rot = D3DXVECTOR3(0.0f, 0.0f, 0.0f);		//����

	{//��ʕ���	�v���C���[
	 //���_�E�����_�E�������ݒ肷��i�\���̂̏������j
		m_posV[NumCameraZero] = D3DXVECTOR3(0.0f, 200.0f, -400.0f);								//���_
		m_posR[NumCameraZero] = D3DXVECTOR3(0.0f, 20.0f, -1.0f);								//�����_
		m_vecU[NumCameraZero] = D3DXVECTOR3(0.0f, 1.0f, 0.0f);									//������x�N�g�� ���Œ��OK!!

		m_CamPosV[NumCameraZero] = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_CamPosR[NumCameraZero] = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		//�r���[�|�[�g�\���̕ۑ�
		m_game_viewport[NumCameraZero].X = 0;
		m_game_viewport[NumCameraZero].Y = 0;
		m_game_viewport[NumCameraZero].Width = 1280;
		m_game_viewport[NumCameraZero].Height = 720;
		m_game_viewport[NumCameraZero].MaxZ = 1.0f;
		m_game_viewport[NumCameraZero].MinZ = 0.0f;
	}

	{//��ʕ��� �}�b�v
		m_posV[NumCameraOne] = D3DXVECTOR3(0.0f, 1000.0f, -400.0f);						//���_
		m_posR[NumCameraOne] = D3DXVECTOR3(0.0f, 20.0f, -1.0f);							//�����_
		m_vecU[NumCameraOne] = D3DXVECTOR3(0.0f, 1.0f, 0.0f);							//������x�N�g�� ���Œ��OK!!

		m_CamPosV[NumCameraOne] = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
		m_CamPosR[NumCameraOne] = D3DXVECTOR3(0.0f, 0.0f, 0.0f);


		//�r���[�|�[�g�\���̕ۑ�
		m_game_viewport[NumCameraOne].X = 1050;
		m_game_viewport[NumCameraOne].Y = 10;
		m_game_viewport[NumCameraOne].Width = 200;
		m_game_viewport[NumCameraOne].Height = 200;
		m_game_viewport[NumCameraOne].MaxZ = 1.0f;
		m_game_viewport[NumCameraOne].MinZ = 0.0f;

	}

	float fLength1 = (m_posV[NumCameraZero].x - m_posR[NumCameraZero].x);									//���_���璍���_��X���̋���
	float fLength2 = (m_posV[NumCameraZero].z - m_posR[NumCameraZero].z);									//���_���璍���_��Z���̋���
	m_fDistance = sqrtf((fLength1 * fLength1) + (fLength2 * fLength2));		//���_���璍���_�܂ł̋���

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CCamera::Uninit(void)
{
}

//=============================================================================
// �X�V����
//=============================================================================
void CCamera::Update(void)
{
	//�L�[�{�[�h�̏��擾
	CInput *pInputKeyboard = CApplication::Getinstnce()->GetInput();

	//�J�����̈ړ�
	if (pInputKeyboard->Press(DIK_DOWN))
	{//��Ɉړ�
		m_posV[NumCameraZero].x -= sinf(m_rot.y) * CAMERA_SPEED;
		m_posV[NumCameraZero].z -= cosf(m_rot.y) * CAMERA_SPEED;
		m_posR[NumCameraZero].x = m_posV[NumCameraZero].x + sinf(m_rot.y) * m_fDistance;
		m_posR[NumCameraZero].z = m_posV[NumCameraZero].z + cosf(m_rot.y) * m_fDistance;
	}
	if (pInputKeyboard->Press(DIK_UP))
	{//���Ɉړ�
		m_posV[NumCameraZero].x += sinf(m_rot.y) * CAMERA_SPEED;
		m_posV[NumCameraZero].z += cosf(m_rot.y) * CAMERA_SPEED;
		m_posR[NumCameraZero].x = m_posV[NumCameraZero].x + sinf(m_rot.y) * m_fDistance;
		m_posR[NumCameraZero].z = m_posV[NumCameraZero].z + cosf(m_rot.y) * m_fDistance;
	}
	if (pInputKeyboard->Press(DIK_RIGHT))
	{//���Ɉړ�
		m_posV[NumCameraZero].x += sinf(D3DX_PI * 0.5f + m_rot.y) * CAMERA_SPEED;
		m_posV[NumCameraZero].z += cosf(D3DX_PI * 0.5f + m_rot.y) * CAMERA_SPEED;
		m_posR[NumCameraZero].x = m_posV[NumCameraZero].x + sinf(m_rot.y) * m_fDistance;
		m_posR[NumCameraZero].z = m_posV[NumCameraZero].z + cosf(m_rot.y) * m_fDistance;
	}
	if (pInputKeyboard->Press(DIK_LEFT))
	{//�E�Ɉړ�
		m_posV[NumCameraZero].x -= sinf(D3DX_PI * 0.5f + m_rot.y) * CAMERA_SPEED;
		m_posV[NumCameraZero].z -= cosf(D3DX_PI * 0.5f + m_rot.y) * CAMERA_SPEED;
		m_posR[NumCameraZero].x = m_posV[NumCameraZero].x + sinf(m_rot.y) * m_fDistance;
		m_posR[NumCameraZero].z = m_posV[NumCameraZero].z + cosf(m_rot.y) * m_fDistance;
	}

	//�����_�̐���
	if (pInputKeyboard->Press(DIK_C))
	{//���ɐ���
		m_rot.y += 0.05f;
		m_posR[NumCameraZero].x = m_posV[NumCameraZero].x + sinf(m_rot.y) * m_fDistance;
		m_posR[NumCameraZero].z = m_posV[NumCameraZero].z + cosf(m_rot.y) * m_fDistance;
	}
	else if (pInputKeyboard->Press(DIK_Z))
	{//�E�ɐ���
		m_rot.y -= 0.05f;
		m_posR[NumCameraZero].x = m_posV[NumCameraZero].x + sinf(m_rot.y) * m_fDistance;
		m_posR[NumCameraZero].z = m_posV[NumCameraZero].z + cosf(m_rot.y) * m_fDistance;
	}

	//���_�̐���
	if (pInputKeyboard->Press(DIK_E))
	{//���ɐ���
		m_rot.y += 0.05f;
	}
	else if (pInputKeyboard->Press(DIK_Q))
	{//�E�ɐ���
		m_rot.y -= 0.05f;
	}

	int mode = CApplication::Getinstnce()->GetMode();
	if (mode == CApplication::MODE_GAME || mode == CApplication::MODE_GAME1)
	{
		//�v���C���[���
		D3DXVECTOR3 pPlayerPos = CApplication::Getinstnce()->GetpMode()->GetPlayer()->GetPos();

		//�v�Z�p�}�g���b�N�X
		D3DXMATRIX mtxRot, mtxTrans;

		for (int cameranum = 0; cameranum <2; cameranum++)
		{
			//���[���h�}�g���b�N�X�̏�����
			D3DXMatrixIdentity(&m_mtxView[cameranum]);		//�s�񏉊����֐�(�������̍s���P�ʍs��ɏ�����)

			//�����𔽉f
			D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z); //�s���]�֐�(�������Ƀ��[(y)�s�b�`(x)���[��(z)�����̉�]�s����쐬)
			D3DXMatrixMultiply(&m_mtxView[cameranum], &m_mtxView[cameranum], &mtxRot);				//�s��|���Z�֐�(��2���� * ��O������������Ɋi�[)

			//�ʒu�𔽉f
			D3DXMatrixTranslation(&mtxTrans, pPlayerPos.x, pPlayerPos.y, pPlayerPos.z);		//�s��ړ��֐�(��������x,y,z�����̈ړ��s����쐬)
			D3DXMatrixMultiply(&m_mtxView[cameranum], &m_mtxView[cameranum], &mtxTrans);

			D3DXVec3TransformCoord(&m_CamPosV[cameranum], &m_posV[cameranum], &m_mtxView[cameranum]);	//���[���h�ϊ��s��
			D3DXVec3TransformCoord(&m_CamPosR[cameranum], &m_posR[cameranum], &m_mtxView[cameranum]);	//���[���h�ϊ��s��
		}
	}
	if (mode == CApplication::MODE_SELECT_STAGE)
	{
		SetCameraType(ONE_CAMERA);

		//�v���C���[���
		D3DXVECTOR3 pos1 = D3DXVECTOR3(700.0f, 10.0f, 0.0f);
		D3DXVECTOR3 pos = D3DXVECTOR3(0.0f, 10.0f, 0.0f);

		int modecount = CSelectStage::GetModeCount();
		//�v�Z�p�}�g���b�N�X
		D3DXMATRIX mtxRot, mtxTrans;

		//���[���h�}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&m_mtxView[1]);		//�s�񏉊����֐�(�������̍s���P�ʍs��ɏ�����)

		//�����𔽉f
		D3DXMatrixRotationYawPitchRoll(&mtxRot, m_rot.y, m_rot.x, m_rot.z); //�s���]�֐�(�������Ƀ��[(y)�s�b�`(x)���[��(z)�����̉�]�s����쐬)
		D3DXMatrixMultiply(&m_mtxView[1], &m_mtxView[1], &mtxRot);				//�s��|���Z�֐�(��2���� * ��O������������Ɋi�[)

		if (modecount ==1)
		{
			//�ʒu�𔽉f
			D3DXMatrixTranslation(&mtxTrans, pos1.x, pos1.y, pos1.z);		//�s��ړ��֐�(��������x,y,z�����̈ړ��s����쐬)
		}
		if (modecount == 2)
		{
			//�ʒu�𔽉f
			D3DXMatrixTranslation(&mtxTrans, pos.x, pos.y, pos.z);		//�s��ړ��֐�(��������x,y,z�����̈ړ��s����쐬)
		}
		D3DXMatrixMultiply(&m_mtxView[1], &m_mtxView[1], &mtxTrans);


		D3DXVec3TransformCoord(&m_CamPosV[1], &m_posV[1], &m_mtxView[1]);	//���[���h�ϊ��s��
		D3DXVec3TransformCoord(&m_CamPosR[1], &m_posR[1], &m_mtxView[1]);	//���[���h�ϊ��s��
	}
	else
	{
		SetCameraType(CAMERA_MAP);

	}


}

//=============================================================================
// �ݒ菈��	(����1 true �Œ�J���� false �t���[�J����)(����2 true ���e false ���s���e)(����3 true ��ʕ������� false ����)
//=============================================================================
void CCamera::SetCamera(bool bfixed, bool btypecom, int numCamera)
{
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::Getinstnce()->GetRenderer()->GetDevice();

	switch (m_cameratype)
	{
	case CCamera::NONE:
		break;
	case CCamera::ONE_CAMERA:		//�v���C���[��
		pDevice->SetViewport(&m_game_viewport[NumCameraZero]);
		if (bfixed)	//�Œ�J�������邩���Ȃ���
		{
			//�r���[�}�g���b�N�X�̍쐬
			D3DXMatrixLookAtLH(&m_mtxView[NumCameraZero],
				&m_CamPosV[NumCameraZero],
				&m_CamPosR[NumCameraZero],
				&m_vecU[NumCameraZero]);
		}
		else
		{
			//�r���[�}�g���b�N�X�̍쐬
			D3DXMatrixLookAtLH(&m_mtxView[NumCameraZero],
				&m_posV[NumCameraZero],
				&m_posR[NumCameraZero],
				&m_vecU[NumCameraZero]);
		}
		//�r���[�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_VIEW, &m_mtxView[NumCameraZero]);
		//�v���W�F�N�V�����}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&m_mtxProjection[NumCameraZero]);
		if (btypecom)	//���e���@
		{
			//�v���W�F�N�V�����}�g���b�N�X�̍쐬
			D3DXMatrixPerspectiveFovLH(&m_mtxProjection[NumCameraZero],
				D3DXToRadian(45.0f),							//����p
				(float)m_game_viewport[NumCameraZero].Width / (float)m_game_viewport[NumCameraZero].Height,		//�A�X�y�N�g��
				10.0f,											//�j�A�i�ǂ�����ǂ��܂ŃJ�����ŕ\�����邩�ݒ�j
				1000.0f);										//�t�@�[
		}
		else
		{
			// �v���W�F�N�V�����}�g���b�N�X�̍쐬(���s���e)
			D3DXMatrixOrthoLH(&m_mtxProjection[NumCameraZero],				// �v���W�F�N�V�����}�g���b�N�X
				(float)m_game_viewport[NumCameraZero].Width,				// ��
				(float)m_game_viewport[NumCameraZero].Height,				// ����
				10.0f,													// �j�A
				1000.0f);												// �t�@�[
		}
		//�v���W�F�N�V�����}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection[NumCameraZero]);
		break;
	case CCamera::CAMERA_MAP:		//����ȊO�̏���

		//�r���[�|�[�g�̐ݒ�
		pDevice->SetViewport(&m_game_viewport[numCamera]);

		//�r���[�}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&m_mtxView[NumCameraOne]);

		//�r���[�}�g���b�N�X�̍쐬
		D3DXMatrixLookAtLH(&m_mtxView[numCamera],
			&m_CamPosV[numCamera],
			&m_CamPosR[numCamera],
			&m_vecU[numCamera]);

		//�r���[�}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_VIEW, &m_mtxView[numCamera]);

		//�v���W�F�N�V�����}�g���b�N�X�̏�����
		D3DXMatrixIdentity(&m_mtxProjection[numCamera]);

		//�v���W�F�N�V�����}�g���b�N�X�̍쐬
		D3DXMatrixPerspectiveFovLH(&m_mtxProjection[numCamera],
			D3DXToRadian(45.0f),																//����p
			(float)m_game_viewport[numCamera].Width / (float)m_game_viewport[numCamera].Height,			//�A�X�y�N�g��
			10.0f,																				//�ǂ�����(�j�A)�ǂ��܂�(�t�@�[)���J������
			50000.0f);																			//�\�����邩�ݒ�

		//�v���W�F�N�V�����}�g���b�N�X�̐ݒ�
		pDevice->SetTransform(D3DTS_PROJECTION, &m_mtxProjection[numCamera]);
		break;
	case CCamera::CAMERA_INVALID:
		break;
	default:
		break;
	}
}

//=============================================================================
// ��������
//=============================================================================
CCamera * CCamera::Create(CAMERATYPE cameratype)
{
	//�|�C���^�錾
	CCamera *pCamera = nullptr;

	//�C���X�^���X����
	pCamera = new CCamera;

	if (pCamera != nullptr)
	{//�|�C���^�����݂�������s

		pCamera->Init();

		pCamera->SetCameraType(cameratype);

	}
	else
	{//�|�C���^����������������s
		assert(false);
	}

	//�|�C���^��Ԃ�
	return pCamera;
}

void CCamera::SetCameraType(CAMERATYPE cameratype)
{
	m_cameratype = cameratype;
}

void CCamera::SetSIz_Camera(D3DXVECTOR2 siz)
{
	m_game_viewport[NumCameraZero].Height = (DWORD)siz.y;
	m_game_viewport[NumCameraZero].Width = (DWORD)siz.x;

}

void CCamera::SetPos_Camera(D3DXVECTOR2 pos)
{
	m_game_viewport[NumCameraZero].X = (DWORD)pos.x;
	m_game_viewport[NumCameraZero].Y = (DWORD)pos.y;

}