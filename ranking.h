#ifndef _RANKING_H_
#define _RANKING_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "mode.h"

//=============================================================================
// 前方定義
//=============================================================================
class CObject2D;
class CFade;
class CNumber;
class CLight;
class CGoal;
//=============================================================================
// マクロ定義
//=============================================================================
#define MAX_RANKING        (5)        //ランキングの桁数
#define MAX_RANKINGRANK    (5)        //ランキングの順位分
#define MAX_TEXTURE        (4)        //テクスチャの数

//=============================================================================
// クラスの定義
//=============================================================================
class CRanking : public CMode
{
public:
	CRanking();
	~CRanking();

	//プロトタイプ宣言
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void Load(void);
	void Save(void);
	static void SetRankingScore();
	static void GetRanking(int Ranking);

	static CRanking * Create();

private:
	LPDIRECT3DTEXTURE9 m_pTexture[MAX_TEXTURE] = {};
	CObject2D * m_pObject2D[3];
	static CNumber * m_apNumber[MAX_RANKINGRANK][MAX_RANKING]; 
	static int m_nRanking;
	static int aData[MAX_RANKINGRANK];
	static CLight *m_pLight;				// ライトのポインタ
	static CGoal *m_pGoal;				//ゴールポインタ
	static CMeshfield *m_pMeshField;		// メッシュフィールドのポインタ	

	bool m_bmodeflg;
	CFade *m_pFade;
};
#endif