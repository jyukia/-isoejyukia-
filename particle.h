//
//�t�@�C���w�b�_�[�R�����g
//
#ifndef _PARTICLE_H_
#define _PARTICLE_H_

#include "renderer.h"
#include "object3D.h"

//*****************************************************************************
//�O���錾
//*****************************************************************************


//*****************************************************************************
//�}�N����`
//*****************************************************************************

class CParticle : public CObject3D
{
private:
	//�ړ�����
	const float m_fmaxmove = 20.0f;
	//���C�t
	int m_nLife = 15;
	//�T�C�Y
	D3DXVECTOR3 size = D3DXVECTOR3(20, 20, 20);

public:
	//�R���X�g���N�^
	CParticle(const int list);

	//�f�X�g���N�^
	~CParticle() override;

	//������
	HRESULT Init() override;

	void Uninit() override;
	//�X�V
	void Update() override;
	//�`��
	void Draw() override;

	static CParticle* Create(D3DXVECTOR3 pos, D3DXVECTOR3 size);

private:
	void move();
	D3DXVECTOR3 m_Move;

};

#endif