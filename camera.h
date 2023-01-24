#ifndef _CAMERA_H_
#define _CAMERA_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "main.h"

//=============================================================================
//マクロ定義
//=============================================================================
#define CAMERA_SPEED	(5.0f)		//カメラの移動速度

//=============================================================================
// クラスの定義
//=============================================================================
class CCamera
{
public:
	//-------------------------------------------------------------------------
	// コンストラクタとデストラクタ
	//-------------------------------------------------------------------------
	explicit CCamera();
	virtual ~CCamera();

	//-------------------------------------------------------------------------
	// メンバー関数
	//-------------------------------------------------------------------------
	virtual HRESULT Init(void);					// 初期化処理
	virtual void Uninit(void);					// 終了処理
	virtual void Update(void);					// 更新処理

	void SetCamera(bool bfixed, bool btypecom);				// 設定処理
	static CCamera *Create();		// 生成処理

	void SetTarget();
	void SetCameraType();

	void SetSIz_Camera(D3DXVECTOR2 siz);
	void SetPos_Camera(D3DXVECTOR2 pos);

	void SetPosV(D3DXVECTOR3 posv) { m_posV = posv; }
	D3DXVECTOR3 GetPosV() { return m_posV; }

	void SetPosR(D3DXVECTOR3 posr) { m_posR = posr; }
	D3DXVECTOR3 GetPosR() { return m_posR; }
	
	static D3DXVECTOR3 GetRot() { return m_rot; }



	static D3DXMATRIX GetMtxView() { return m_mtxView; }
	static D3DXMATRIX GetProjection() { return m_mtxProjection; }

private:
	//-------------------------------------------------------------------------
	// メンバー変数
	//-------------------------------------------------------------------------

	D3DXVECTOR3	m_posV;				//[2]視点
	D3DXVECTOR3	m_posR;				//[2]注視点
	D3DXVECTOR3	m_vecU;				//[2]上方向ベクトル
	D3DXVECTOR3	m_posVDest;			//目的の視点
	D3DXVECTOR3	m_posRDest;			//目的の注視点
	static D3DXMATRIX	m_mtxProjection;	// [2]プロジェクションマトリックス
	static D3DXMATRIX	m_mtxView;			//[2] ビューマトリックス
	float		m_fDistance;		//視点から注視点の距離

	D3DXVECTOR3 m_CamPosV;	// [2]計算後
	D3DXVECTOR3 m_CamPosR;	//[2]

	D3DXVECTOR2 m_Siz;		//画面サイズ

	D3DVIEWPORT9 m_game_viewport;	//[2]画面分割

	int m_cnt;

	bool bcam;
	bool bcom1;
	bool flgstp;

protected:
	static D3DXVECTOR3 m_rot;		//向き

	CRenderer * m_prenderer;
};

#endif