//
//�t�@�C���w�b�_�[�R�����g
//
#ifndef _movelife_H_
#define _movelife_H_

#include"Number.h"
#include "renderer.h"
#include"application.h"
#include"mode.h"
//�O���錾
class CNumber;

class CMovelife : public CObject2D
{
public:
	//�R���X�g���N�^
	explicit CMovelife(int nPriority);
	//�f�X�g���N�^
	~CMovelife() override;

	//������
	HRESULT Init() override;
	//�I��
	void Uninit() override;
	//�X�V
	void Update() override;
	//�`��
	void Draw() override;

	void Addlife(int nValue);

	void Sublife(int nDecrease);

	void Setlife(int nLife);

	static CMovelife* Create(D3DXVECTOR3 pos,int nPriority);

private:

	CNumber* pNumber[3];
	int m_Life;	//���ۑ�

};

#endif