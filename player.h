#ifndef _PLAYER_H_
#define _PLAYER_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "objectX.h"

//=============================================================================
// �O����`
//=============================================================================
class CShadow;
class CMeshOrbit;
class CMeshLine;
//=============================================================================
// �N���X�̒�`
//=============================================================================
class CPlayer : public CObjectX
{
public:
	const D3DXVECTOR3 m_PlayerPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);


	static const float SPEED_POWER;
	static const float JUMP_POWER;
	static const float GRAVITY_POWER;

	//�v���C���[�̐U��ނ�����
	const float PurposeRot = 0.08f;
public:
	//-------------------------------------------------------------------------
	// �R���X�g���N�^�ƃf�X�g���N�^
	//-------------------------------------------------------------------------
	explicit CPlayer(int nPriority = PRIORITY_LEVEL3);
	~CPlayer() override;

	//-------------------------------------------------------------------------
	// �����o�[�֐�
	//-------------------------------------------------------------------------
	HRESULT Init() override;			// ����������
	void Update() override;				// �X�V����

	D3DXVECTOR3 PlayerMove();

	static CPlayer *Create(const D3DXVECTOR3 pos, int nPriority);    // ��������

	static int GetKeyCnt(void) { return keyCnt; }		// �J�E���g�擾����

	void SetJumpFlag(bool fFlag) { m_bJumpFlag = fFlag; }


private:
	//-------------------------------------------------------------------------
	// �����o�[�ϐ�
	//-------------------------------------------------------------------------
	CShadow *m_shadow;					// �e�̃|�C���^
	CMeshOrbit *m_MeshEffect;	//���b�V���G�t�F�N�g

	D3DXVECTOR3 m_rotDest;				// �ړI�̊p�x
	D3DXVECTOR3 m_posOld;				// �O��̈ʒu
	float m_nSpeed;						// �X�s�[�h
	float m_inertia;					//����
	bool m_bIsLandingUp;				// �㑤�����蔻��t���O
	bool m_bIsLanding;					// �����蔻��t���O
	bool m_bJumpFlag;					// �W�����v�������ǂ����̃t���O
	bool m_bIsLandingMesh;				// ���b�V�������蔻��t���O

	CMeshLine *m_pMeshLine;

	//�N�H�[�^�j�I���v�Z���g�p
	static int keyCnt;
	//�N�H�[�^�j�I���g�p�̃t���O�擾
	bool Quaternionflg;
};
#endif