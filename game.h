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
class CScore;
class CMovelife;
class CMeshLine;
class CGoal;
class CItem;
class Cpreparation;
class CBillboard;
class CTimer;
class CParticle2D;
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

	static CMeshfield *GetMeshfield() { return m_pMeshField; }
private:
	//-------------------------------------------------------------------------
	// メンバー変数
	//-------------------------------------------------------------------------
	CObject2D *m_pObject2D;					// オブジェクト2Dのポインタ
	static LPDIRECT3DTEXTURE9 m_pTexture;	// テクスチャのポインタ
	static CLight *m_pLight;				// ライトのポインタ
	static CMeshfield *m_pMeshField;		// メッシュフィールドのポインタ	
	static CGoal *m_pGoal;				//ゴールポインタ
	static CItem *m_pItem;

	CTimer *m_Timer;

	Cpreparation *m_pPreparation;	//ゲーム開始の合図ポインタ

	CFade *m_pFade;
	CCamera *m_pCamera;

	CObject2D* m_pCompass;

	CObject2D* m_pTimeUi;
	CObject2D* m_pTime_Lope_Ui;

	D3DXVECTOR3 m_rot;

	//スコア
	static CScore* GetScore() { return pScore; }
	static CScore* pScore;

	//移動可能距離
	static CMovelife* GetMovelife() { return pMovelife; }
	static CMovelife* pMovelife;

	int CntTime;
	//メッシュライン
	CMeshLine *m_pMeshLine;

	CParticle2D* m_particle2d;
};
#endif