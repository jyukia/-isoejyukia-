#ifndef _ITEM_H_
#define _ITEM_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "objectX.h"

//=============================================================================
// �O����`
//=============================================================================
class CShadow;
class CItem : public CObjectX
{
public:
	enum TypeItem
	{
		ITEM_NONE = 0,

		ITEM_SIZ_UP,
		ITEM_SIZ_DOWN,

		ITEM_MAX
	};


	//-------------------------------------------------------------------------
	// �R���X�g���N�^�ƃf�X�g���N�^
	//-------------------------------------------------------------------------
	explicit CItem(int nPriority = PRIORITY_LEVEL3);
	~CItem() override;

	//-------------------------------------------------------------------------
	// �����o�[�֐�
	//-------------------------------------------------------------------------
	HRESULT Init() override;			// ����������
	void Update() override;				// �X�V����

	void Uninit() override;				// �I������
	bool Collision(D3DXVECTOR3 * pPos, D3DXVECTOR3 * pPosOld, D3DXVECTOR3 * pSize, bool bQuaternion);

	void SetType(TypeItem type) { typeItem = type; }


	static CItem *Create(const D3DXVECTOR3 pos, int nPriority, TypeItem type);    // ��������

	 bool GetHitFlg(void) { return HitFlg; }

	 bool GetSizupflg(void) { return sizupflg; }
	 bool GetSizdownflg(void) { return sizdownflg; }

private:
	CShadow *m_shadow;					// �e�̃|�C���^

	TypeItem typeItem;

	 bool HitFlg;

	 bool sizupflg;
	 bool sizdownflg;
};


#endif