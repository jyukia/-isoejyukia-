#ifndef _MODE_H_
#define _MODE_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "main.h"
#include "object.h"

//=============================================================================
// �O����`
//=============================================================================
class CTitle;
class CGame;
class CResult;

//=============================================================================
// �N���X�̒�`
//=============================================================================
class CMode : public CObject
{
public:
	//-------------------------------------------------------------------------
	// �R���X�g���N�^�ƃf�X�g���N�^
	//-------------------------------------------------------------------------
	CMode();
	~CMode() override;

	//-------------------------------------------------------------------------
	// �����o�[�֐�
	//-------------------------------------------------------------------------
	HRESULT Init() override { return S_OK; };		// ����������
	void Uninit() override {};						// �I������						
	void Update() override {};						// �X�V����
	void Draw() override {};						// �`�揈��
	void VtxUpdate() override {};					// ���_���W�X�V����
	void SetPos(D3DXVECTOR3 pos) override { D3DXVECTOR3 i = pos; };		// ���W�ݒ菈��
	void SetSize(D3DXVECTOR3 size) override { D3DXVECTOR3 i = size; };		// �T�C�Y�ݒ菈��
	void SetMove(D3DXVECTOR3 move) override { D3DXVECTOR3  i = move; };		// �ړ��ʐݒ菈��
	void SetCol(D3DXCOLOR col) override { D3DXCOLOR i = col; };			// �F�ݒ菈��
	void SetRot(D3DXVECTOR3 rot) override { D3DXVECTOR3 i = rot; };		// �����ݒ菈��
	D3DXVECTOR3 GetPos(void) override { return D3DXVECTOR3(); }			// ���W�擾����
	D3DXVECTOR3 GetSize(void) override { return D3DXVECTOR3(); }		// �T�C�Y�擾����
	D3DXVECTOR3 GetMove(void) override { return D3DXVECTOR3(); }		// �ړ��ʎ擾����
	D3DXVECTOR3 GetRot(void) override { return D3DXVECTOR3(); }			// �����擾����
	D3DXCOLOR GetCol(void) override { return D3DXCOLOR(); }			// �F�擾����

private:
	//-------------------------------------------------------------------------
	// �����o�[�ϐ�
	//-------------------------------------------------------------------------
	CTitle *m_pTitle;
	CGame *m_pGame;
	CResult *m_pResult;
};

#endif