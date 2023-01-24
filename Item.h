#ifndef _ITEM_H_
#define _ITEM_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "objectX.h"

//=============================================================================
// 前方定義
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
	// コンストラクタとデストラクタ
	//-------------------------------------------------------------------------
	explicit CItem(int nPriority = PRIORITY_LEVEL3);
	~CItem() override;

	//-------------------------------------------------------------------------
	// メンバー関数
	//-------------------------------------------------------------------------
	HRESULT Init() override;			// 初期化処理
	void Update() override;				// 更新処理

	void Uninit() override;				// 終了処理
	bool Collision(D3DXVECTOR3 * pPos, D3DXVECTOR3 * pPosOld, D3DXVECTOR3 * pSize, bool bQuaternion);

	void SetType(TypeItem type) { typeItem = type; }


	static CItem *Create(const D3DXVECTOR3 pos, int nPriority, TypeItem type);    // 生成処理

	 bool GetHitFlg(void) { return HitFlg; }

	 bool GetSizupflg(void) { return sizupflg; }
	 bool GetSizdownflg(void) { return sizdownflg; }

private:
	CShadow *m_shadow;					// 影のポインタ

	TypeItem typeItem;

	 bool HitFlg;

	 bool sizupflg;
	 bool sizdownflg;
};


#endif