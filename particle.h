//
//ファイルヘッダーコメント
//
#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#include "renderer.h"
#include "object3D.h"

//*****************************************************************************
//前方宣言
//*****************************************************************************


//*****************************************************************************
//マクロ定義
//*****************************************************************************

class CParticle : public CObject3D
{
private:
	//移動速さ
	const float m_fmaxmove = 20.0f;
	//ライフ
	int m_nLife = 15;
	//サイズ
	D3DXVECTOR3 size = D3DXVECTOR3(20, 20, 20);

public:
	//コンストラクタ
	CParticle(const int list);

	//デストラクタ
	~CParticle() override;

	//初期化
	HRESULT Init() override;

	void Uninit() override;
	//更新
	void Update() override;
	//描画
	void Draw() override;

	static CParticle* Create(D3DXVECTOR3 pos, D3DXVECTOR3 size);

private:
	void move();
	D3DXVECTOR3 m_Move;

};

#endif