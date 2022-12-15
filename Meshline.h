#ifndef _MESHLINE_H_
#define _MESHLINE_H_

//前方宣言
class CTexture;

//=============================================================================
// インクルードファイル
//=============================================================================
#include "objectX.h"
#include "object.h"
 
class CMeshLine : public CObject
{
public:
	//生成ライン回数
	const int MaxLine = 1000;
	//回収判定繰り返す回数
	const int MaxHitBox = 13;


public:
	explicit CMeshLine(int nPriority = PRIORITY_LEVEL3);
	~CMeshLine() override;

	//-------------------------------------------------------------------------
	// メンバー関数
	//-------------------------------------------------------------------------
	HRESULT Init()override;							// 初期化処理
	void Uninit() override;							// 終了処理
	void Update() override;							// 更新処理
	void Draw()   override;							// 描画処理

	void BindTexture(LPDIRECT3DTEXTURE9 pTexture);				// 派生のテクスチャポインタを親のテクスチャポインタに代入する処理

	void LoadTexture(const char *aFileName);					// テクスチャの読み込み

	//セッター
	void SetMtxParent(D3DXMATRIX *pMtx);
	void SetOfSetPos(D3DXVECTOR3 ofsetpos);

	void SetPos(D3DXVECTOR3 pos);			// 座標設定処理
	void SetCol(D3DXCOLOR col);				// 色設定処理
	void SetRot(D3DXVECTOR3 rot);			// 向き設定処理

	//ゲッター
	D3DXVECTOR3 GetOfSetPos() { return OfSetPos; }			//サイズ変更
	D3DXVECTOR3 GetRot(void) { return m_rot; }		// 向き取得処理
	D3DXCOLOR GetCol(void) { return m_col; }			// 色取得処理

	static bool GetMoveFlg() { return MoveMaxFlg; }			//移動制限フラグ
	static void SetMoveFlg(bool movemaxflg);

	static CMeshLine *Create(D3DXCOLOR col, D3DXVECTOR3 distancepos);		// 生成処理
	bool Collision(D3DXVECTOR3 *PlayerPos, D3DXVECTOR3 *PlayerSize);	//当たり判定
	bool ReturnCollision(D3DXVECTOR3 * PlayerPos, D3DXVECTOR3 * PlayerPosOld, D3DXVECTOR3 * PlayerSize);

	bool CollisionReturn(D3DXVECTOR3 * PlayerPos, D3DXVECTOR3 * PlayerPosOld, D3DXVECTOR3 * PlayerSize);


	float Vec2Cross(D3DXVECTOR3* v1, D3DXVECTOR3* v2);
	float Vec2Dot(D3DXVECTOR3* v1, D3DXVECTOR3* v2);


private:
	D3DXMATRIX *m_pMtxParent;	//軌跡の親モデルのマトリックス

	LPDIRECT3DTEXTURE9 m_pTexture;			// テクスチャのポインタ
	LPDIRECT3DVERTEXBUFFER9 m_pVtxBuff;		// 頂点バッファのポインタ
	D3DXMATRIX m_mtxWorld;					// ワールドマトリックス

	D3DXVECTOR3 m_rot;
	D3DXVECTOR3 m_pos;
	D3DXCOLOR m_col;
	D3DXVECTOR3 OfSetPos;	//	縦座標の変換 サイズ変更可能

	int m_pVtxMax;	//最大数

	static bool MoveMaxFlg;

	bool bUseflg;

	int m_Vtxcount;
};

#endif