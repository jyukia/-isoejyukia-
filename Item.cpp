//============================
//
// �A�C�e���ݒ�
// Author:��]����
//
//============================

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "Item.h"
#include "shadow.h"
#include "application.h"
#include "player.h"
#include "mode.h"
#include "particle.h"

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CItem::CItem(int nPriority)
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CItem::~CItem()
{
}

//=============================================================================
// ������
//=============================================================================
HRESULT CItem::Init()
{
	{
		HitFlg = false;

		sizupflg = false;	//�g�p�Ȃ�
		sizdownflg = false;
	}
	D3DXVECTOR3 pos = CObjectX::GetPos();

	D3DXVECTOR3 size = CObjectX::GetSize();

	D3DXVECTOR3 rot = CObjectX::GetRot();

	//�I�u�W�F�N�g�̏�����
	CObjectX::Init();

	//�e�̐���
	CShadow::Create(pos, size, CObject::PRIORITY_LEVEL3);


	return S_OK;
}

//=============================================================================
// �X�V
//=============================================================================
void CItem::Update()
{

	CObject3D* particle = CParticle::Create(D3DXVECTOR3(890.0f, 685.0f, -2300.0f), D3DXVECTOR3(20, 20, 20));

	if (CApplication::Getinstnce()->GetpMode()->GetPlayer() != nullptr)
	{
		D3DXVECTOR3 pPlayerPos = CApplication::Getinstnce()->GetpMode()->GetPlayer()->GetPos();
		D3DXVECTOR3 pPlayerPosOld = CApplication::Getinstnce()->GetpMode()->GetPlayer()->GetPosOld();
		D3DXVECTOR3 pSize = CApplication::Getinstnce()->GetpMode()->GetPlayer()->GetSize();
		// ���W�擾
		D3DXVECTOR3 pos = GetPos();
		// �|�C���^�錾
		CObject *pObject = CObject::GetTop(PRIORITY_LEVEL3);
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

			if (objType == OBJTYPE_PLAYER)	//�ڐG���v���C���[�̎�
			{
				CObjectX *pObjectX = (CObjectX*)pObject;

				D3DXVECTOR3 size = D3DXVECTOR3(100, 100, 100);
				HitFlg = Collision(&pPlayerPos, &pPlayerPosOld, &size, false);
			}
			//�|�C���^�����ɐi�߂�
			pObject = pObject->GetNext();
		}
		if (HitFlg)	//�S�[���ƃv���C���[���G�ꂽ��
		{

			switch (typeItem)
			{
			case CItem::ITEM_SIZ_UP:

				sizupflg = true;

				break;
			case CItem::ITEM_SIZ_DOWN:

				sizdownflg = true;
				break;
			default:
				break;
			}


		}
	}

}
void CItem::Uninit()
{
	CObjectX::Uninit();
}
//=============================================================================
// �����蔻�� (���E,��,��O)
//=============================================================================
bool CItem::Collision(D3DXVECTOR3 * pPos, D3DXVECTOR3 * pPosOld, D3DXVECTOR3 * pSize, bool bQuaternion)
{
	// �ϐ��錾
	bool bIsLanding = false;

	// ���W�擾
	D3DXVECTOR3 pos = GetPos();

	D3DXVECTOR3 Min = GetMinVtx();

	D3DXVECTOR3 Max = GetMaxVtx();

	if (bQuaternion)
	{
		// ���f���̍��������蔻��(�N�H�[�^�j�I��Ver)
		if ((pPos->z - pSize->z / 2.0f < pos.z + Max.z) &&
			(pPos->z + pSize->z / 2.0f > pos.z + Min.z) &&
			(pPosOld->x + pSize->x / 2.0f <= pos.x + Min.x) &&
			(pPos->x + pSize->x / 2.0f > pos.x + Min.x) &&
			(pPos->y + pSize->y > pos.y) &&
			(pPos->y < pos.y + Max.y))
		{
			bIsLanding = true;
			Uninit();

		}
		// ���f���̉E�������蔻��(�N�H�[�^�j�I��Ver)
		if ((pPos->z - pSize->z / 2.0f < pos.z + Max.z) &&
			(pPos->z + pSize->z / 2.0f > pos.z + Min.z) &&
			(pPosOld->x - pSize->x / 2.0f >= pos.x + Max.x) &&
			(pPos->x - pSize->x / 2.0f < pos.x + Max.x) &&
			(pPos->y + pSize->y > pos.y) &&
			(pPos->y < pos.y + Max.y))
		{
			bIsLanding = true;
			Uninit();

		}
		// ���f���̉��������蔻��(�N�H�[�^�j�I��Ver)
		if ((pPos->x - pSize->x / 2.0f < pos.x + Max.x) &&
			(pPos->x + pSize->x / 2.0f > pos.x + Min.x) &&
			(pPosOld->z - pSize->z / 2.0f >= pos.z + Max.z) &&
			(pPos->z - pSize->z / 2.0f < pos.z + Max.z) &&
			(pPos->y + pSize->y > pos.y) &&
			(pPos->y < pos.y + Max.y))
		{
			bIsLanding = true;
			Uninit();

		}
		// ���f���̎�O�������蔻��(�N�H�[�^�j�I��Ver)
		if ((pPos->x - pSize->x / 2.0f < pos.x + Max.x) &&
			(pPos->x + pSize->x / 2.0f > pos.x + Min.x) &&
			(pPosOld->z + pSize->z / 2.0f <= pos.z + Min.z) &&
			(pPos->z + pSize->z / 2.0f > pos.z + Min.z) &&
			(pPos->y + pSize->y > pos.y) &&
			(pPos->y < pos.y + Max.y))
		{
			bIsLanding = true;
			Uninit();

		}
	}
	else
	{
		// ���f���̍��������蔻��
		if ((pPos->z - pSize->z / 2.0f < pos.z + Max.z) &&
			(pPos->z + pSize->z / 2.0f > pos.z + Min.z) &&
			(pPosOld->x + pSize->x / 2.0f <= pos.x + Min.x / 2.0f) &&
			(pPos->x + pSize->x / 2.0f > pos.x + Min.x / 2.0f) &&
			(pPos->y + pSize->y > pos.y) &&
			(pPos->y < pos.y + Max.y))
		{
			bIsLanding = true;
			Uninit();


		}
		// ���f���̉E�������蔻��
		if ((pPos->z - pSize->z / 2.0f < pos.z + Max.z) &&
			(pPos->z + pSize->z / 2.0f > pos.z + Min.z) &&
			(pPosOld->x - pSize->x / 2.0f >= pos.x + Max.x / 2.0f) &&
			(pPos->x - pSize->x / 2.0f < pos.x + Max.x / 2.0f) &&
			(pPos->y + pSize->y > pos.y) &&
			(pPos->y < pos.y + Max.y))
		{
			bIsLanding = true;
			Uninit();


		}
		// ���f���̉��������蔻��
		if ((pPos->x - pSize->x / 2.0f < pos.x + Max.x) &&
			(pPos->x + pSize->x / 2.0f > pos.x + Min.x) &&
			(pPosOld->z - pSize->z / 2.0f >= pos.z + Max.z / 2.0f) &&
			(pPos->z - pSize->z / 2.0f < pos.z + Max.z / 2.0f) &&
			(pPos->y + pSize->y > pos.y) &&
			(pPos->y < pos.y + Max.y))
		{
			bIsLanding = true;
			Uninit();


		}
		// ���f���̎�O�������蔻��
		if ((pPos->x - pSize->x / 2.0f < pos.x + Max.x) &&
			(pPos->x + pSize->x / 2.0f > pos.x + Min.x) &&
			(pPosOld->z + pSize->z / 2.0f <= pos.z + Min.z / 2.0f) &&
			(pPos->z + pSize->z / 2.0f > pos.z + Min.z / 2.0f) &&
			(pPos->y + pSize->y > pos.y) &&
			(pPos->y < pos.y + Max.y))
		{
			bIsLanding = true;
			Uninit();


		}
	}

	// �l��Ԃ�
	return bIsLanding;
}
//=============================================================================
// ��������
//=============================================================================
CItem * CItem::Create(const D3DXVECTOR3 pos, int nPriority, TypeItem item)
{
	CItem *pItem = new CItem(nPriority);

	if (pItem != nullptr)
	{
		pItem->Init();
		pItem->SetPos(pos);
		pItem->SetType(item);
		pItem->m_shadow = CShadow::Create(D3DXVECTOR3(pos.x, 0.5f, pos.z), D3DXVECTOR3(10.0f, 0.0f, 10.0f), CObject::PRIORITY_LEVEL3);
	
	}
	else
	{
		assert(false);
	}

	return pItem;
}
