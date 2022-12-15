#ifndef _GAME_H_
#define _GAME_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "main.h"
#include "object2D.h"
#include "mode.h"

//=============================================================================
// 前方定義
//=============================================================================
class CPlayer;
class CCamera;
class CMeshfield;
class CFade;
class CLight;
//=============================================================================
// クラスの定義
//=============================================================================
class CGame : public CMode
{
public:
	//-------------------------------------------------------------------------
	// コンストラクタとデストラクタ
	//-------------------------------------------------------------------------
	CGame();
	~CGame() override;

	//-------------------------------------------------------------------------
	// メンバー関数
	//-------------------------------------------------------------------------
	HRESULT Init(void) override;	// 初期化処理
	void Uninit(void) override;		// 終了処理
	void Update(void) override;		// 更新処理
	void Draw(void) override;		// 描画処理
	static CGame *Create();			// 生成処理

	static CPlayer *GetPlayer() { return m_pPlayer; }
	static CMeshfield *GetMeshfield() { return m_pMeshField; }
private:
	//-------------------------------------------------------------------------
	// メンバー変数
	//-------------------------------------------------------------------------
	CObject2D *m_pObject2D;					// オブジェクト2Dのポインタ
	static LPDIRECT3DTEXTURE9 m_pTexture;	// テクスチャのポインタ
	static CPlayer *m_pPlayer;				// プレイヤーのポインタ
	static CLight *m_pLight;				// ライトのポインタ
	static CMeshfield *m_pMeshField;		// メッシュフィールドのポインタ	
	CFade *m_pFade;
	CCamera *m_pCamera;

	CObject2D* m_pCompass;

};

#endif