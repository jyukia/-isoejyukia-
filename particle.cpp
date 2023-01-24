//=============================================================================
//
// Particle.cpp
// Author : 磯江寿希亜
//
//=============================================================================
//*****************************************************************************
// インクルードファイル
//*****************************************************************************
#include "Particle.h"
#include "application.h"
#include"game.h"
#include"player.h"

//*****************************************************************************
//前方宣言
//*****************************************************************************


//*****************************************************************************
//マクロ定義
//*****************************************************************************


//-----------------------------------------
//コンストラクタ
//-----------------------------------------
CParticle::CParticle(int list) :CObject3D(list)
{
}
//-----------------------------------------
//デストラクタ
//-----------------------------------------
CParticle::~CParticle()
{
}
HRESULT CParticle::Init()
{
	D3DXVECTOR3 rot =GetRot();

	rot.y = D3DX_PI / 2;

	SetRot(rot);

	CObject3D::Init();

	return S_OK;
}
void CParticle::Update()
{
	D3DXVECTOR3 pos = GetPos();

	//寿命
	m_nLife--;

	m_nLife = ((rand() + 1));

	size.x--;
	size.x -= 0.05f;

	size.y--;
	size.y -= 0.05f;

	size.z--;
	size.z -= 0.05f;


	if (size.x <= 0)
	{
		size.x = 0;
	}
	if (size.z <= 0)
	{
		size.z = 0;
	}
	if (size.y <= 0)
	{
		size.y = 0;
	}

	SetSize(size);


	//移動方向
	D3DXVECTOR3 maxmove;
	pos += maxmove;

	maxmove.x -= 20;//cosf(((float)(rand() % 360) / 10) * ((float)(rand() % 10)) * 1.f
	maxmove.y += 15;//sinf((float)(rand() % 360) / 10) * ((float)(rand() % 10)) * 1.f

	SetMove(maxmove);

	if (m_nLife <= 0.0f)
	{
		Uninit();
		return;
	}
	CObject3D::Update();
}
void CParticle::Draw()
{
	//デバイスの取得
	LPDIRECT3DDEVICE9 pDevice = CApplication::Getinstnce()->GetRenderer()->GetDevice();

	//アルファブレンディングを加算合成に設定
	//pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	//pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	//pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	CObject3D::Draw();

	//αブレンディングを元に戻す
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
}


//------------------------------------
// 初期化
//------------------------------------
void CParticle::Uninit()
{
	CObject3D::Uninit();
}
CParticle * CParticle::Create(D3DXVECTOR3 pos, D3DXVECTOR3 size)
{
	CParticle * pObject = nullptr;
	pObject = new CParticle(1);

	if (pObject != nullptr)
	{
		pObject->Init();
		pObject->LoadTexture("SMOKE");//テクスチャ選択
		pObject->SetSize(size);//サイズ設定
		pObject->SetPos(pos);//座標設定
		pObject->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));//色設定

		 //↓引数(1横の枚数,2縦の枚数,3Animation速度,４基本ゼロだけど表示するまでのタイムラグ,5無限にアニメーション再生するかどうか)
		//pObject->SetAnimation(5, 4, 4, 0, true);//Animation画像だった場合これを書く,一枚絵なら消さないとバグる
	}
	return pObject;
}

void CParticle::move()
{
}
