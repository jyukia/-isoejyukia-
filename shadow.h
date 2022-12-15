#ifndef _SHADOW_H_
#define _SHADOW_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "main.h"
#include "object3D.h"

//=============================================================================
// クラスの定義
//=============================================================================
class CShadow : public CObject3D
{
public:
	//-------------------------------------------------------------------------
	// コンストラクタとデストラクタ
	//-------------------------------------------------------------------------
	explicit CShadow(int nPriority = PRIORITY_LEVEL3);
	~CShadow() override;

	//-------------------------------------------------------------------------
	// メンバー関数
	//-------------------------------------------------------------------------
	HRESULT Init(void) override;    // 初期化処理
	void Uninit(void) override;     // 終了処理
	void Update(void) override;     // 更新処理
	void Draw(void) override;		// 描画処理

	static CShadow *Create(const D3DXVECTOR3 pos, const D3DXVECTOR3 size, int nPriority);    // 生成

private:
	//-------------------------------------------------------------------------
	// メンバー変数
	//-------------------------------------------------------------------------
	LPDIRECT3DTEXTURE9 m_pTexture = NULL;        //テクスチャへのポインタ
};

#endif