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
	const int NumCameraZero = 1;
	const int NumCameraOne = 0;

	enum CAMERATYPE		//カメラタイプ
	{
		NONE = 0,

		ONE_CAMERA,	//ゲーム中
		CAMERA_MAP,		//マップ

		CAMERA_MAX,
		CAMERA_INVALID
	};


	//-------------------------------------------------------------------------
	// コンストラクタとデストラクタ
	//-------------------------------------------------------------------------
	CCamera();
	~CCamera();

	//-------------------------------------------------------------------------
	// メンバー関数
	//-------------------------------------------------------------------------
	HRESULT Init(void);					// 初期化処理
	void Uninit(void);					// 終了処理
	void Update(void);					// 更新処理

	void SetCamera(bool bfixed, bool btypecom, int numCamera);				// 設定処理
	static CCamera *Create(CAMERATYPE cameratype);		// 生成処理

	void SetCameraType(CAMERATYPE cameratype);

	void SetSIz_Camera(D3DXVECTOR2 siz);
	void SetPos_Camera(D3DXVECTOR2 pos);
	void SetPosV(D3DXVECTOR3 posv) { m_posV[0] = posv; }
	void SetPosR(D3DXVECTOR3 posr) { m_posR[0] = posr; }

	static D3DXVECTOR3 GetRot() { return m_rot; }

private:
	//-------------------------------------------------------------------------
	// メンバー変数
	//-------------------------------------------------------------------------
	CAMERATYPE m_cameratype;

	D3DXVECTOR3	m_posV[2];				//視点
	D3DXVECTOR3	m_posR[2];				//注視点
	D3DXVECTOR3	m_vecU[2];				//上方向ベクトル
	D3DXVECTOR3	m_posVDest;			//目的の視点
	D3DXVECTOR3	m_posRDest;			//目的の注視点
	D3DXMATRIX	m_mtxProjection[2];	//プロジェクションマトリックス
	D3DXMATRIX	m_mtxView[2];			//ビューマトリックス
	float		m_fDistance;		//視点から注視点の距離

	D3DXVECTOR3 m_CamPosV[2];	//計算後
	D3DXVECTOR3 m_CamPosR[2];	//

	D3DXVECTOR2 m_Siz;		//画面サイズ

	D3DVIEWPORT9 m_game_viewport[2];	//画面分割

protected:
	static D3DXVECTOR3 m_rot;		//向き

	CRenderer * m_prenderer;
};

#endif