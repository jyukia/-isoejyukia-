#ifndef _LOAD_STAGE_H_
#define _LOAD_STAGE_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "objectX.h"

//=============================================================================
// クラスの定義
//=============================================================================
class CLoadStage
{
public:
	//-------------------------------------------------------------------------
	// コンストラクタとデストラクタ
	//-------------------------------------------------------------------------
	CLoadStage();
	~CLoadStage();

	//-------------------------------------------------------------------------
	// メンバー関数
	//-------------------------------------------------------------------------
	static void LoadAll(const D3DXVECTOR3& inPos = D3DXVECTOR3(0.0f, 0.0f, 0.0f));		// 全ての読み込み
	static void SaveAll();		// 全ての書込み

	static void LoadAllTest();

private: /* プライベート関数 */

private:
};
#endif