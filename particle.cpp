//=============================================================================
//
// Particle.cpp
// Author : ��]����
//
//=============================================================================
//*****************************************************************************
// �C���N���[�h�t�@�C��
//*****************************************************************************
#include "Particle.h"
#include "application.h"
#include"game.h"
#include"player.h"

//*****************************************************************************
//�O���錾
//*****************************************************************************


//*****************************************************************************
//�}�N����`
//*****************************************************************************


//-----------------------------------------
//�R���X�g���N�^
//-----------------------------------------
CParticle::CParticle(int list) :CObject3D(list)
{
}
//-----------------------------------------
//�f�X�g���N�^
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

	//����
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


	//�ړ�����
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
	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::Getinstnce()->GetRenderer()->GetDevice();

	//�A���t�@�u�����f�B���O�����Z�����ɐݒ�
	//pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	//pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	//pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

	CObject3D::Draw();

	//���u�����f�B���O�����ɖ߂�
	pDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);
	pDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	pDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
}


//------------------------------------
// ������
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
		pObject->LoadTexture("SMOKE");//�e�N�X�`���I��
		pObject->SetSize(size);//�T�C�Y�ݒ�
		pObject->SetPos(pos);//���W�ݒ�
		pObject->SetCol(D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f));//�F�ݒ�

		 //������(1���̖���,2�c�̖���,3Animation���x,�S��{�[�������Ǖ\������܂ł̃^�C�����O,5�����ɃA�j���[�V�����Đ����邩�ǂ���)
		//pObject->SetAnimation(5, 4, 4, 0, true);//Animation�摜�������ꍇ���������,�ꖇ�G�Ȃ�����Ȃ��ƃo�O��
	}
	return pObject;
}

void CParticle::move()
{
}
