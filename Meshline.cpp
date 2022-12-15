#include "Meshline.h"
#include"application.h"
#include "renderer.h"
#include "object3D.h"
#include "player.h"
#include "game.h"
#include"DebugProc.h"

bool CMeshLine::MoveMaxFlg = false;


CMeshLine::CMeshLine(int nPriority) :m_pVtxMax(0), m_col(0.0f, 0.0f, 0.0f, 0.0f), m_Vtxcount(0), bUseflg(false)
{

}

CMeshLine::~CMeshLine()
{
}

HRESULT CMeshLine::Init()
{
	{//������
		m_pVtxMax = MaxLine;	//���_���ő吔
	}

	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//���_�o�b�t�@�̐���
	pDevice->CreateVertexBuffer((sizeof(VERTEX_3D) * m_pVtxMax),
		D3DUSAGE_WRITEONLY,
		FVF_VERTEX_3D,
		D3DPOOL_MANAGED,
		&m_pVtxBuff,
		NULL);

	//���_���ւ̃|�C���^
	VERTEX_3D*pVtx;

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	for (int Cnt = 0; Cnt < m_pVtxMax; Cnt++)
	{
		// ���_����ݒ�
		pVtx[Cnt].pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);

		//�e���_�̖@���̐ݒ�i���x�N�g���̑傫����1�ɂ���K�v������j
		pVtx[Cnt].nor = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

		// ���_�J���[�̐ݒ�
		pVtx[Cnt].col = D3DXCOLOR(0.0f, 0.0f, 0.0f,1.0f);

		//�e�N�X�`���̍��W�ݒ�
		pVtx[Cnt].tex = D3DXVECTOR2(0.0f, 0.0f);


	}

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();

	return S_OK;
}

void CMeshLine::Uninit()
{
	//���_�o�b�t�@�̉���E�폜
	if (m_pVtxBuff != nullptr)
	{
		m_pVtxBuff->Release();
		m_pVtxBuff = nullptr;
	}
}

void CMeshLine::Update()
{
	//���_���ւ̃|�C���^
//	VERTEX_3D*pVtx;
//
//	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
//	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);
//
//	for (int Cnt = m_pVtxMax - 3; Cnt >= 0; Cnt--)
//	{
//		if (pVtx[m_pVtxMax -1].pos == pVtx[m_pVtxMax -3].pos)
//		{
//			pVtx[Cnt + 2].pos = pVtx[Cnt].pos;
//		}
//	}
//	if (pVtx[m_pVtxMax - 1].pos == pVtx[m_pVtxMax - 3].pos)
//	{
//		D3DXVECTOR3 Pos(0.0f, 0.0f, 0.0f);	//���_
//
//		D3DXVec3TransformCoord(&OfSetPos, &OfSetPos, m_pMtxParent);
//		D3DXVec3TransformCoord(&Pos, &Pos, m_pMtxParent);
//		pVtx[1].pos = OfSetPos;	//�����ύX
//		pVtx[0].pos = Pos;//���_
//
//	}
//	//���_�o�b�t�@���A�����b�N����
//	m_pVtxBuff->Unlock();

	bUseflg = true;

	D3DXVECTOR3 axis = CObjectX::GetAxis();
	//�v���C���[���
	D3DXVECTOR3 pPlayerPos = CGame::GetPlayer()->GetPos();
	D3DXVECTOR3 pPlayerPosOld = CGame::GetPlayer()->GetPosOld();

	//���_���ւ̃|�C���^
	VERTEX_3D*pVtx;

	//���_�o�b�t�@�����b�N���A���_���ւ̃|�C���^���擾
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);


	if (m_Vtxcount == 6)
	{
//		CollisionReturn(&pPlayerPos, &pPlayerPosOld, &D3DXVECTOR3(50.0f, 50.0f, 50.0f));
		for (int CollisionCount = 0; CollisionCount < 2; CollisionCount++)
		{
		}

			//�߂����ۂ̓����蔻�� (�����߂�)
			bUseflg = CollisionReturn(&pPlayerPos, &pPlayerPosOld, &D3DXVECTOR3(50.0f, 50.0f, 50.0f));

	}
	if (bUseflg)	//����
	{
		if (pPlayerPosOld != pPlayerPos && !(axis.x == 0 && axis.y == 0 && axis.z == 0))	//�����Ă�Ƃ����s
		{
			for (int Cnt = m_pVtxMax - 3; Cnt >= 0; Cnt--)
			{
				pVtx[Cnt + 2].pos = pVtx[Cnt].pos;
			}
			pVtx[1].pos = pPlayerPos + axis * 30.0f;			//�����ύX
			pVtx[0].pos = pPlayerPos - axis * 30.0f;			//���_
			m_Vtxcount += 2;
		}
	}

	//���_�o�b�t�@���A�����b�N����
	m_pVtxBuff->Unlock();


#ifdef _DEBUG
	CDebugProc::Print("�v���C���[�̐i�s����       (axis)       | X : %.2f | Y : %.2f | Z : %.2f |\n", axis.x, axis.y, axis.z);

	CDebugProc::Print("�v���C���[�̍��W       (pPlayerPos)       | X : %.2f | Y : %.2f | Z : %.2f |\n", pPlayerPos.x, pPlayerPos.y, pPlayerPos.z);
#endif // _DEBUG
}

void CMeshLine::Draw()
{
	//GetDevive�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
	//���C�g�ݒ�false�ɂ���ƃ��C�g�ƐH���Ȃ�
	pDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	//�v�Z�p�}�g���b�N�X
	D3DXMATRIX mtxRot, mtxTrans;

	//���[���h�}�g���b�N�X�̏�����
	D3DXMatrixIdentity(&m_mtxWorld);				//�s�񏉊����֐�(�������̍s���P�ʍs��ɏ�����)

	//�����𔽉f
	D3DXMatrixRotationYawPitchRoll(&mtxRot, 0.0f, 0.0f, 0.0f); //�s���]�֐�(�������Ƀ��[(y)�s�b�`(x)���[��(z)�����̉�]�s����쐬)
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxRot);				//�s��|���Z�֐�(��2���� * ��O������������Ɋi�[)

	//�ʒu�𔽉f
	D3DXMatrixTranslation(&mtxTrans, m_pos.x, m_pos.y, m_pos.z);		//�s��ړ��֐�(��������x,y,z�����̈ړ��s����쐬)
	D3DXMatrixMultiply(&m_mtxWorld, &m_mtxWorld, &mtxTrans);

	//���[���h�}�g���b�N�X�̐ݒ�
	pDevice->SetTransform(D3DTS_WORLD, &m_mtxWorld);		//���[���h���W�s��̐ݒ�

	//���_�o�b�t�@���f�[�^�X�g���[���ɐݒ�
	pDevice->SetStreamSource(0, m_pVtxBuff, 0, sizeof(VERTEX_3D));

	//���_�t�H�[�}�b�g�̐ݒ�
	pDevice->SetFVF(FVF_VERTEX_3D);

	//�e�N�X�`���̐ݒ�
	pDevice->SetTexture(0, NULL);

	//�|���S���̕`��
	pDevice->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, m_pVtxMax - 2);

	pDevice->SetRenderState(D3DRS_LIGHTING, TRUE);
	pDevice->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW);

	//�e�N�X�`���̉���
	pDevice->SetTexture(0, NULL);

}

void CMeshLine::BindTexture(LPDIRECT3DTEXTURE9 pTexture)
{
}

void CMeshLine::LoadTexture(const char * aFileName)
{
}

void CMeshLine::SetMtxParent(D3DXMATRIX * pMtx)
{
	m_pMtxParent = pMtx;
}

void CMeshLine::SetOfSetPos(D3DXVECTOR3 ofsetpos)
{
	OfSetPos = ofsetpos;
}

void CMeshLine::SetPos(D3DXVECTOR3 pos)
{
	m_pos = pos;

}

void CMeshLine::SetCol(D3DXCOLOR col)
{
	m_col = col;

}

void CMeshLine::SetRot(D3DXVECTOR3 rot)
{
	m_rot = rot;

}

void CMeshLine::SetMoveFlg(bool movemaxflg)
{
	MoveMaxFlg = movemaxflg;
}

CMeshLine * CMeshLine::Create(D3DXCOLOR col, D3DXVECTOR3 distancepos)
{
	CMeshLine *pMeshLine = new CMeshLine(2);

	if (pMeshLine != nullptr)
	{
		pMeshLine->SetCol(col);
		pMeshLine->Init();
		pMeshLine->SetOfSetPos(distancepos);

	}
	else
	{
		assert(false);
	}

	return pMeshLine;
}
//�ю�����Q���ɐG�ꂽ�ېڐG�����ۂ���鏈��
bool CMeshLine::Collision(D3DXVECTOR3 * PlayerPos, D3DXVECTOR3 * PlayerSize)
{
	//���_���ւ̃|�C���^
	VERTEX_3D * pVtx = nullptr;
	//WORD * pIdx;
	D3DXVECTOR3 IdxPos[3];				//Idx��pos
	D3DXVECTOR3 VecA[3];				//VecA
	D3DXVECTOR3 VecB[3];				//VecB

	bool bIsLanding = false;

	//���_�o�b�t�@�����b�N
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);




	//���_�o�b�t�@���A�����b�N
	m_pVtxBuff->Unlock();

	return bIsLanding;
}
//�v���C���[���߂����ۖю��̉�����s��
bool CMeshLine::ReturnCollision(D3DXVECTOR3 * PlayerPos, D3DXVECTOR3 * PlayerPosOld, D3DXVECTOR3 * PlayerSize)
{
	//���_���ւ̃|�C���^
	VERTEX_3D * pVtx = nullptr;

	D3DXVECTOR3 Answer;					//�O�ς̌v�Z����
	bool bIsLanding = false;

	//���_�o�b�t�@�����b�N
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	D3DXVECTOR3 MoveVec = pVtx[22].pos - pVtx[20].pos;
	D3DXVECTOR3 VecLine = *PlayerPos - *PlayerPosOld + (MoveVec);			//�x�N�g�����݂�POS�Ǝn�_�܂ł̋���
	D3DXVECTOR3 VecPos = pVtx[22].pos - *PlayerPosOld;

	//�O�όv�Z
	float vecCalculation = Vec2Cross(&VecPos, &VecLine);

	if (vecCalculation <= 0.0f)	//2�_�̒��ɂ��邩�O�ɂ��邩
	{
		//�x�N�g��v
		D3DXVECTOR3 vecOld = *PlayerPosOld - pVtx[20].pos;

		//�v�Z�p�̔�
		float vecCalculation[2];
		//T1���߂�
		vecCalculation[0] = Vec2Cross(&vecOld, &VecLine);
		vecCalculation[1] = Vec2Cross(&MoveVec, &VecLine);

		//posOld�����_�܂ł̋���
		float t1 = vecCalculation[0] / vecCalculation[1];
		//T2���߂�
		vecCalculation[0] = Vec2Cross(&vecOld, &MoveVec);
		vecCalculation[1] = Vec2Cross(&MoveVec, &VecLine);

		//�ǂ̎��_�����_�܂ł̋���
		float t2 = vecCalculation[0] / vecCalculation[1];
		//��
		float eps = 0.00001f;

		//�v���C���[���
		D3DXVECTOR3 pPlayerPos = CGame::GetPlayer()->GetPos();
		D3DXVECTOR3 pPlayerPosOld = CGame::GetPlayer()->GetPosOld();

		if (MoveMaxFlg)
		{
			if (t1 + eps < 0 || t1 - eps > 1 || t2 + eps < 0 || t2 - eps > 1)
			{	//�������ĂȂ��Ƃ��̔���

				pPlayerPos = pPlayerPosOld;

				SetPos(pPlayerPos);
			}
			else
			{	//�������Ă�Ƃ��̔���
				for (int Cnt = 0; Cnt < m_pVtxMax - 3; Cnt++)
				{
					pVtx[21].pos - pVtx[19].pos;
				}
				bIsLanding = true;
			}
		}
	}

	//���_�o�b�t�@���A�����b�N
	m_pVtxBuff->Unlock();

	return bIsLanding;
}

//=============================================================================
// �����蔻�� �v���C���[���߂����ۖю��̉�����s��
//=============================================================================
bool CMeshLine::CollisionReturn(D3DXVECTOR3 * PlayerPos, D3DXVECTOR3 * PlayerPosOld, D3DXVECTOR3 * PlayerSize)
{
	//�v���C���[���
	D3DXVECTOR3 pPlayerPos = CGame::GetPlayer()->GetPos();
	D3DXVECTOR3 pPlayerPosOld = CGame::GetPlayer()->GetPosOld();

	//���_���ւ̃|�C���^
	VERTEX_3D * pVtx = nullptr;
	WORD * pIdx;
	D3DXVECTOR3 VecA[6];				//VecA
	D3DXVECTOR3 VecB[6];				//VecB
	float Calculation2D[6];				//2�����O�ς̌v�Z����
	bool bIsLanding = false;

	//���_�o�b�t�@�����b�N
	m_pVtxBuff->Lock(0, 0, (void**)&pVtx, 0);

	D3DXVECTOR3 SIZE = D3DXVECTOR3(1.0f,1.0f,1.0f);

	//�x�N�g���̎擾 VecA 2 3 4
	VecA[0] = pVtx[2].pos + SIZE - pVtx[4].pos + SIZE;
	VecA[1] = pVtx[3].pos + SIZE - pVtx[4].pos + SIZE;
	VecA[2] = pVtx[2].pos + SIZE - pVtx[3].pos + SIZE;

	//�x�N�g���̎擾 VecA 3 4 5
	VecA[3] = pVtx[4].pos + SIZE - pVtx[3].pos + SIZE;
	VecA[4] = pVtx[4].pos + SIZE - pVtx[5].pos + SIZE;
	VecA[5] = pVtx[5].pos + SIZE - pVtx[3].pos + SIZE;

	//�v���C���[	���_�𑪂�
	VecB[0] = *PlayerPos - pVtx[2].pos;
	VecB[1] = *PlayerPos - pVtx[3].pos;
	VecB[2] = *PlayerPos - pVtx[4].pos;

	VecB[3] = *PlayerPos - pVtx[3].pos;
	VecB[4] = *PlayerPos - pVtx[4].pos;
	VecB[5] = *PlayerPos - pVtx[5].pos;

	//2�����O�ς̌v�Z����
	Calculation2D[0] = Vec2Cross(&VecA[0], &VecB[0]);
	Calculation2D[1] = Vec2Cross(&VecA[1], &VecB[1]);
	Calculation2D[2] = Vec2Cross(&VecA[2], &VecB[2]);

	Calculation2D[3] = Vec2Cross(&VecA[3], &VecB[3]);
	Calculation2D[4] = Vec2Cross(&VecA[4], &VecB[4]);
	Calculation2D[5] = Vec2Cross(&VecA[5], &VecB[5]);

	//�v���C���[�̈ʒu���S��-��+
		if ((Calculation2D[0] >= 0 && Calculation2D[1] >= 0 && Calculation2D[2] >= 0) || (Calculation2D[0] <= 0 && Calculation2D[1] <= 0 && Calculation2D[2] <= 0) ||
			(Calculation2D[3] >= 0 && Calculation2D[4] >= 0 && Calculation2D[5] >= 0) || (Calculation2D[3] <= 0 && Calculation2D[4] <= 0 && Calculation2D[5] <= 0))
		{//����������
			if (MoveMaxFlg)	//�����Ȃ��Ȃ����� (�ړ��ʂ��ׂĎg���؂�����)
			{
				//�����������ꏊ�����߂��悤��
			}
			for (int Cnt = 0; Cnt < m_pVtxMax-3; Cnt++)
			{
				m_Vtxcount = 0;


				// ���_�J���[�̐ݒ�
				pVtx[Cnt].col = D3DXCOLOR(0.0f, 0.0f, 1.0f, 1.0f);				//����@������₷���F��ς���

			}
			//false��������
			bUseflg = false;
			bIsLanding = true;
		}
		else
		{
			//����@������₷���F��ς���
			for (int Cnt = 0; Cnt < m_pVtxMax -3; Cnt++)
			{

				//�z������ւ��鎖�ŏ����Ă���
				pVtx[Cnt] = pVtx[Cnt + 2];


				// ���_�J���[�̐ݒ�
				pVtx[Cnt].col = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
			}
		}

	//���_�o�b�t�@���A�����b�N
	m_pVtxBuff->Unlock();

	return bIsLanding;
}


//=========================================
// 2D�x�N�g���̊O��
// Author: Yuda Kaito
//=========================================
float CMeshLine::Vec2Cross(D3DXVECTOR3* v1, D3DXVECTOR3* v2)
{
	return v1->x * v2->z - v1->z * v2->x;
}

//=========================================
// 2D�x�N�g���̓���
// Author: hamada ryuuga
//=========================================
float CMeshLine::Vec2Dot(D3DXVECTOR3* v1, D3DXVECTOR3* v2)
{
	return v1->x * v2->x + v1->z * v2->z;
}
