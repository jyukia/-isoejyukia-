#ifndef _CAMERA_H_
#define _CAMERA_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "main.h"

//=============================================================================
//�}�N����`
//=============================================================================
#define CAMERA_SPEED	(5.0f)		//�J�����̈ړ����x

//=============================================================================
// �N���X�̒�`
//=============================================================================
class CCamera
{
public:
	const int NumCameraZero = 1;
	const int NumCameraOne = 0;

	enum CAMERATYPE		//�J�����^�C�v
	{
		NONE = 0,

		ONE_CAMERA,	//�Q�[����
		CAMERA_MAP,		//�}�b�v

		CAMERA_MAX,
		CAMERA_INVALID
	};


	//-------------------------------------------------------------------------
	// �R���X�g���N�^�ƃf�X�g���N�^
	//-------------------------------------------------------------------------
	CCamera();
	~CCamera();

	//-------------------------------------------------------------------------
	// �����o�[�֐�
	//-------------------------------------------------------------------------
	HRESULT Init(void);					// ����������
	void Uninit(void);					// �I������
	void Update(void);					// �X�V����

	void SetCamera(bool bfixed, bool btypecom, int numCamera);				// �ݒ菈��
	static CCamera *Create(CAMERATYPE cameratype);		// ��������

	void SetCameraType(CAMERATYPE cameratype);

	void SetSIz_Camera(D3DXVECTOR2 siz);
	void SetPos_Camera(D3DXVECTOR2 pos);
	void SetPosV(D3DXVECTOR3 posv) { m_posV[0] = posv; }
	void SetPosR(D3DXVECTOR3 posr) { m_posR[0] = posr; }

	static D3DXVECTOR3 GetRot() { return m_rot; }

private:
	//-------------------------------------------------------------------------
	// �����o�[�ϐ�
	//-------------------------------------------------------------------------
	CAMERATYPE m_cameratype;

	D3DXVECTOR3	m_posV[2];				//���_
	D3DXVECTOR3	m_posR[2];				//�����_
	D3DXVECTOR3	m_vecU[2];				//������x�N�g��
	D3DXVECTOR3	m_posVDest;			//�ړI�̎��_
	D3DXVECTOR3	m_posRDest;			//�ړI�̒����_
	D3DXMATRIX	m_mtxProjection[2];	//�v���W�F�N�V�����}�g���b�N�X
	D3DXMATRIX	m_mtxView[2];			//�r���[�}�g���b�N�X
	float		m_fDistance;		//���_���璍���_�̋���

	D3DXVECTOR3 m_CamPosV[2];	//�v�Z��
	D3DXVECTOR3 m_CamPosR[2];	//

	D3DXVECTOR2 m_Siz;		//��ʃT�C�Y

	D3DVIEWPORT9 m_game_viewport[2];	//��ʕ���

protected:
	static D3DXVECTOR3 m_rot;		//����

	CRenderer * m_prenderer;
};

#endif