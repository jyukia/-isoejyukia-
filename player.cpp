//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include <assert.h>
#include "application.h"
#include "camera.h"
#include "input.h"
#include "main.h"
#include "objectX.h"
#include "player.h"
#include "shadow.h"
#include "renderer.h"
#include "meshfield.h"
#include "game.h"
#include"DebugProc.h"
#include"meshorbit.h"
#include "title.h"
#include "Meshline.h"

//=============================================================================
// �萔��`
//=============================================================================
const float CPlayer::SPEED_POWER = 4.0f;
const float CPlayer::JUMP_POWER = 12.0f;
const float CPlayer::GRAVITY_POWER = 0.775f;

int CPlayer::keyCnt = 1;


//=============================================================================
// �R���X�g���N�^
//=============================================================================
CPlayer::CPlayer(int nPriority) :
	m_nSpeed(0.0f),
	m_bJumpFlag(false),
	m_bIsLanding(false),
	m_bIsLandingUp(false),
	m_inertia(0.0f)
{
	//�I�u�W�F�N�g�̃^�C�v�Z�b�g����
	CObject::SetType(OBJTYPE_PLAYER);
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CPlayer::~CPlayer()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CPlayer::Init()
{
	{//������ 
		m_inertia = 0.05f;	//����

		m_nSpeed = 5.0f;	//�ړ��X�s�[�h
	}
	//objectx��pos��rot
	D3DXVECTOR3 pos = CObjectX::GetPos();

	D3DXVECTOR3 size = CObjectX::GetSize();

	D3DXVECTOR3 rot = CObjectX::GetRot();

	//�I�u�W�F�N�g�̏�����
	CObjectX::Init();


	//�N�H�[�^�j�I���̎g�p
	SetbQuaternion(true);

	//�ړI�̊p�x�̏�����
	m_rotDest = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

	//�e�̐���
	CShadow::Create(pos, size, CObject::PRIORITY_LEVEL3);

	//���b�V���G�t�F�N�g
	//m_MeshEffect = CMeshOrbit::Create(D3DXCOLOR(0.0f,1.0f,0.0f,0.7f));
	//m_MeshEffect->SetMtxParent(GetMtxWorld());

	//�ю���
	m_pMeshLine = CMeshLine::Create(D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f), D3DXVECTOR3(50.0f, 0.0f, 0.0f));
	m_pMeshLine->SetMtxParent(GetMtxTransPos());


	SetScale(D3DXVECTOR3(1.0f, 1.0f, 1.0f));

	return S_OK;
}
//=============================================================================
// �X�V����
//=============================================================================
void CPlayer::Update()
{
	//���͐��J�E���g
	keyCnt = 1;

	// �L�[�{�[�h�̏��擾
	CInput *pInputKeyboard = CApplication::GetInput();

	// ���W�擾
	D3DXVECTOR3 pos = GetPos();

	SetPosOld(pos);

	//1�t���[���O
	// �����擾
	D3DXVECTOR3 rot = GetRot();
	// �ړ��͎擾
	D3DXVECTOR3 move = GetMove();

	//�X�P�[���Ή������T�C�Y���v�Z		�����蔻��g�p
	D3DXVECTOR3 Scale = CObjectX::GetScale();
	D3DXVECTOR3 Size = CObjectX::GetSize();
	{
		//�X�P�[���ƃT�C�Y
		Size.x = Scale.x * Size.x;
		Size.y = Scale.y * Size.y;
		Size.z = Scale.z * Size.z;
	}


	//���b�V���G�t�F�N�g
	//D3DXVECTOR3 ofsetpos = m_MeshEffect->GetOfSetPos();
	//ofsetpos.x = 0.0f;
	//ofsetpos.y = 100.0f;
	//ofsetpos.z = 0.0f;
	//m_MeshEffect->SetOfSetPos(ofsetpos);


	//���b�V�����C��
	D3DXVECTOR3 ofsetpos = m_pMeshLine->GetOfSetPos();
	ofsetpos.x = 10.0f;
	ofsetpos.y = 0.0f;
	ofsetpos.z = 0.0f;
	m_pMeshLine->SetOfSetPos(ofsetpos);

	//�N�H�[�^�j�I���擾
	D3DXQUATERNION fst = CObjectX::GetQuaternionFst();
	{// �f�o�b�N�\��
#ifdef _DEBUG

	//�v���C���[ ���W
	CDebugProc::Print("�v���C���[�̈ʒu       (pos)       | X : %.2f | Y : %.2f | Z : %.2f |\n", pos.x, pos.y, pos.z);
	//��]
	CDebugProc::Print("�v���C���[�̉�]       (rot)       | X : %.2f | Y : %.2f | Z : %.2f |\n", rot.x, rot.y, rot.z);
	//�ړ�
	CDebugProc::Print("�v���C���[�̈ړ�       (move)      | X : %.2f | Y : %.2f | Z : %.2f |\n", move.x, move.y, move.z);
	//�ړI�̊p�x
	CDebugProc::Print("�v���C���[�̖ړI�̊p�x (m_rotDest) | X : %.2f | Y : %.2f | Z : %.2f |\n", m_rotDest.x, m_rotDest.y, m_rotDest.z);
	//�N�H�[�^�j�I��
	CDebugProc::Print("�v���C���[[�N�H�[�^�j�I��] (fst) | %f |\n", fst);
	//�v���C���[�W�����v����
	if (m_bJumpFlag)
	{//�W�����v
		CDebugProc::Print("�v���C���[�̃W�����v���� (m_bJumpFlag) �W�����v \n", m_bJumpFlag);
	}
	else
	{//���n
		CDebugProc::Print("�v���C���[�̃W�����v���� (m_bJumpFlag) ���n \n", m_bJumpFlag);
	}
#endif // _DEBUG
	}

	// �O��̈ʒu��ۑ�
	m_posOld = pos;

	// �J�����̏��擾
	D3DXVECTOR3 pCameraRot = CCamera::GetRot();
	CDebugProc::Print("�J�����̏��       (pCameraRot)       | X : %.2f | Y : %.2f | Z : %.2f |\n", pCameraRot.x, pCameraRot.y, pCameraRot.z);

	bool flg = CMeshLine::GetMoveFlg();	//�ړ������̃t���O
	//���T�C�Y�܂ōs���ƕύX���Ȃ��悤
	if (Scale.x <= 0.2f || Scale.y <= 0.2f || Scale.z <= 0.2f)
	{
		flg = true;	//�ړ����Ȃ��悤�t���O�Őݒ�
		Scale.x = 0.2f;
		Scale.y = 0.2f;
		Scale.z = 0.2f;
		CMeshLine::SetMoveFlg(flg);
	}

		if (pInputKeyboard->Press(DIK_W))
		{// ��Ɉړ�
			if (pInputKeyboard->Press(DIK_A))
			{
				keyCnt++;

				move.x += sinf(D3DX_PI * -0.25f + pCameraRot.y) * m_nSpeed;
				move.z += cosf(D3DX_PI * -0.25f + pCameraRot.y) * m_nSpeed;
				//m_rotDest.y = pCameraRot.y + D3DX_PI * 0.75f;
			}
			else if (pInputKeyboard->Press(DIK_D))
			{
				keyCnt++;

				move.x += sinf(D3DX_PI * 0.25f + pCameraRot.y) * m_nSpeed;
				move.z += cosf(D3DX_PI * 0.25f + pCameraRot.y) * m_nSpeed;
				//m_rotDest.y = pCameraRot.y + -D3DX_PI * 0.75f;
			}
			else
			{
				keyCnt++;

				move.x += sinf(pCameraRot.y) * m_nSpeed;
				move.z += cosf(pCameraRot.y) * m_nSpeed;
				//m_rotDest.y = pCameraRot.y + D3DX_PI;
			}
		}
		if (pInputKeyboard->Press(DIK_S))
		{// ���Ɉړ�
			if (pInputKeyboard->Press(DIK_A))
			{
				keyCnt++;

				move.x += sinf(D3DX_PI * -0.75f + pCameraRot.y) * m_nSpeed;
				move.z += cosf(D3DX_PI * -0.75f + pCameraRot.y) * m_nSpeed;

				//m_rotDest.y = pCameraRot.y + D3DX_PI * 0.25f;
			}
			else if (pInputKeyboard->Press(DIK_D))
			{
				keyCnt++;

				move.x += sinf(D3DX_PI * 0.75f + pCameraRot.y) * m_nSpeed;
				move.z += cosf(D3DX_PI * 0.75f + pCameraRot.y) * m_nSpeed;

				//	m_rotDest.y = pCameraRot.y + -D3DX_PI * 0.25f;
			}
			else
			{
				keyCnt++;

				move.x -= sinf(pCameraRot.y) * m_nSpeed;
				move.z -= cosf(pCameraRot.y) * m_nSpeed;
				//	m_rotDest.y = pCameraRot.y + 0.0f;
			}
		}
		else if (pInputKeyboard->Press(DIK_A))
		{// ���Ɉړ�
			keyCnt++;

			move.x -= sinf(D3DX_PI * 0.5f + pCameraRot.y) * m_nSpeed;
			move.z -= cosf(D3DX_PI * 0.5f + pCameraRot.y) * m_nSpeed;
			//m_rotDest.y = pCameraRot.y + D3DX_PI * 0.5f;
		}
		else if (pInputKeyboard->Press(DIK_D))
		{// �E�Ɉړ�
			keyCnt++;

			move.x += sinf(D3DX_PI * 0.5f + pCameraRot.y) * m_nSpeed;
			move.z += cosf(D3DX_PI * 0.5f + pCameraRot.y) * m_nSpeed;
			//	m_rotDest.y = pCameraRot.y + -D3DX_PI * 0.5f;
		}

		//�T�C�Y�̕ύX
		if (pInputKeyboard->Press(DIK_W) || pInputKeyboard->Press(DIK_A) || pInputKeyboard->Press(DIK_S) || pInputKeyboard->Press(DIK_D))
		{
			Scale.x -= 0.001f;
			Scale.y -= 0.001f;
			Scale.z -= 0.001f;
		}
	if (!flg)	//�����鎞
	{}

	//�p�x�̐��K��(�ړI�̊p�x)
	if (m_rotDest.y - rot.y > D3DX_PI)
	{
		m_rotDest.y = m_rotDest.y - D3DX_PI * 2;
	}
	else if (m_rotDest.y - rot.y < -D3DX_PI)
	{
		m_rotDest.y = m_rotDest.y + D3DX_PI * 2;
	}

	// �ړI�̒l�ɋ߂Â���
	rot.y += (m_rotDest.y - rot.y) * PurposeRot;

	// �W�����v����
	if (pInputKeyboard->Trigger(DIK_SPACE))
	{
		m_bJumpFlag = true;
		move.y = 0.0f;
		move.y += 14.0f;
	}

	// �d�͐ݒ�
	move.y -= GRAVITY_POWER;

	// �p�x�̐��K��(���݂̊p�x)
	if (rot.y > D3DX_PI)
	{
		rot.y = rot.y - D3DX_PI * 2;
	}
	else if (rot.y < -D3DX_PI)
	{
		rot.y = rot.y + D3DX_PI * 2;
	}

	// �ړ��ʉ��Z
	pos += move;
	move.x *= 0.03f;
	move.z *= 0.03f;

	//�N�H�[�^�j�I���v�Z
	move.x += (0.0f - move.x)* m_inertia;
	move.y += (0.0f - move.y)* m_inertia;
	move.z += (0.0f - move.z)* m_inertia;
	QuaternionCalculation(25.0f, &move, &fst);
	SetQuaternion(fst);

	// �|�C���^�錾
	CObject *pObject = CObject::GetTop(PRIORITY_LEVEL3);
	// �n�ʂɂ��邩�ǂ���
	m_bIsLandingUp = false;

	// �v���C���[�ƃ��f���̓����蔻��
	while (pObject != nullptr)
	{
		if (pObject == this)
		{
			pObject = pObject->GetNext();
			continue;
		}

		//�ϐ��錾
		CObject::EObjType objType;

		//�I�u�W�F�N�g�̃^�C�v���擾
		objType = pObject->GetObjType();

		if (objType == OBJTYPE_MODEL)
		{
			CObjectX *pObjectX = (CObjectX*)pObject;
			m_bIsLanding = pObjectX->Collision(&pos, &m_posOld, &Size, true);
			m_bIsLandingUp = pObjectX->UpCollision(&pos, &m_posOld, &Size, &move, true);
		}

		//�|�C���^�����ɐi�߂�
		pObject = pObject->GetNext();
	}

	// ���b�V���t�B�[���h�̃|�C���^���擾
	CMeshfield *pMeshField = CGame::GetMeshfield();
	// �v���C���[��pos��rot�̐ݒ�
	if (pos.y < pMeshField->GetAnswer())
	{
		m_bJumpFlag = false;
	}
	// ���b�V���t�B�[���h�Ƃ̓����蔻��
	if (m_bJumpFlag == false)
	{
		m_bIsLandingMesh = pMeshField->Collision(&pos, &Size, true);
	}
	// y�����ړ����ĂȂ������ꍇ
	if (pos.y == m_posOld.y)
	{
		move.y = 0.0f;
	}



	CObjectX::SetScale(Scale);

	//for (int nCnt = 0; nCnt < 12; nCnt++)
	//{
	//	m_Line[nCnt]->SetPos(GetPos());
	//}
	// �v���C���[��pos��rot��move�̐ݒ�
	CObjectX::SetPos(pos);
	CObjectX::SetRot(rot);
	CObjectX::SetMove(move);

	// CObjectX�̍X�V����
	CObjectX::Update();
}


//=============================================================================
// ��������
//=============================================================================
CPlayer * CPlayer::Create(const D3DXVECTOR3 pos, int nPriority)
{
	CPlayer *pPlayer = new CPlayer(nPriority);

	if (pPlayer != nullptr)
	{
		pPlayer->Init();
		pPlayer->SetPos(pos);
		pPlayer->m_shadow = CShadow::Create(D3DXVECTOR3(pos.x, 0.5f, pos.z), D3DXVECTOR3(10.0f, 0.0f, 10.0f), CObject::PRIORITY_LEVEL3);
		//pPlayer->SetLine(pos);

	}
	else
	{
		assert(false);
	}

	return pPlayer;
}

////=============================================================================
//// �Z�b�g���[�V��������
////=============================================================================
//void CPlayer::SetMotionType(EMotion inMotion)
//{
//	// �������[�V�����ɂ͑J�ڂ��Ȃ��B
//	if (m_moutionType == inMotion)
//	{
//		return;
//	}
//
//	m_moutionType = inMotion;
//	GetMotion()->SetNumMotion(m_moutionType);
//}
////=============================================================================
//// �Z�b�g���C������
////=============================================================================
//void CPlayer::SetLine(const D3DXVECTOR3 pos)
//{
//	D3DXVECTOR3 size = D3DXVECTOR3(25.0f, 67.0f, 17.0f);
//
//	D3DXVECTOR3 rot = GetRot();
//
//	D3DXVECTOR3 VtxPos[8] = {};
//	VtxPos[0] = D3DXVECTOR3(-size.x, 0.0f, size.z);
//	VtxPos[1] = D3DXVECTOR3(size.x, 0.0f, size.z);
//	VtxPos[2] = D3DXVECTOR3(size.x, 0.0f, -size.z);
//	VtxPos[3] = D3DXVECTOR3(-size.x, 0.0f, -size.z);
//	VtxPos[4] = D3DXVECTOR3(-size.x, size.y, size.z);
//	VtxPos[5] = D3DXVECTOR3(size.x, size.y, size.z);
//	VtxPos[6] = D3DXVECTOR3(size.x, size.y, -size.z);
//	VtxPos[7] = D3DXVECTOR3(-size.x, size.y, -size.z);
//
//	m_Line[0] = CLine::Create(pos, rot, VtxPos[0], VtxPos[1], D3DXCOLOR(0.5f, 1.0f, 0.0f, 1.0f), CObject::PRIORITY_LEVEL5);
//	m_Line[1] = CLine::Create(pos, rot, VtxPos[1], VtxPos[2], D3DXCOLOR(0.5f, 1.0f, 0.0f, 1.0f), CObject::PRIORITY_LEVEL5);
//	m_Line[2] = CLine::Create(pos, rot, VtxPos[2], VtxPos[3], D3DXCOLOR(0.5f, 1.0f, 0.0f, 1.0f), CObject::PRIORITY_LEVEL5);
//	m_Line[3] = CLine::Create(pos, rot, VtxPos[3], VtxPos[0], D3DXCOLOR(0.5f, 1.0f, 0.0f, 1.0f), CObject::PRIORITY_LEVEL5);
//
//	m_Line[4] = CLine::Create(pos, rot, VtxPos[0], VtxPos[4], D3DXCOLOR(0.5f, 1.0f, 0.0f, 1.0f), CObject::PRIORITY_LEVEL5);
//	m_Line[5] = CLine::Create(pos, rot, VtxPos[1], VtxPos[5], D3DXCOLOR(0.5f, 1.0f, 0.0f, 1.0f), CObject::PRIORITY_LEVEL5);
//	m_Line[6] = CLine::Create(pos, rot, VtxPos[2], VtxPos[6], D3DXCOLOR(0.5f, 1.0f, 0.0f, 1.0f), CObject::PRIORITY_LEVEL5);
//	m_Line[7] = CLine::Create(pos, rot, VtxPos[3], VtxPos[7], D3DXCOLOR(0.5f, 1.0f, 0.0f, 1.0f), CObject::PRIORITY_LEVEL5);
//
//	m_Line[8] = CLine::Create(pos, rot, VtxPos[4], VtxPos[5], D3DXCOLOR(0.5f, 1.0f, 0.0f, 1.0f), CObject::PRIORITY_LEVEL5);
//	m_Line[9] = CLine::Create(pos, rot, VtxPos[5], VtxPos[6], D3DXCOLOR(0.5f, 1.0f, 0.0f, 1.0f), CObject::PRIORITY_LEVEL5);
//	m_Line[10] = CLine::Create(pos, rot, VtxPos[6], VtxPos[7], D3DXCOLOR(0.5f, 1.0f, 0.0f, 1.0f), CObject::PRIORITY_LEVEL5);
//	m_Line[11] = CLine::Create(pos, rot, VtxPos[7], VtxPos[4], D3DXCOLOR(0.5f, 1.0f, 0.0f, 1.0f), CObject::PRIORITY_LEVEL5);
//}