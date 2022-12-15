#ifndef _OBJECTX_H_
#define _OBJECTX_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "main.h"
#include "object.h"
#include <string>

//=============================================================================
// �O����`
//=============================================================================
class CLine;

//=============================================================================
// �N���X�̒�`
//=============================================================================
class CObjectX : public CObject
{
public:
	//-------------------------------------------------------------------------
	// �R���X�g���N�^�ƃf�X�g���N�^
	//-------------------------------------------------------------------------
	explicit CObjectX(int nPriority = PRIORITY_LEVEL3);
	~CObjectX() override;

	//-------------------------------------------------------------------------
	// �����o�[�֐�
	//-------------------------------------------------------------------------
	HRESULT Init() override;								// ����������
	void Uninit() override;									// �I������
	void Update() override;									// �X�V����
	void Draw() override;									// �`�揈��
	void Draw(D3DXMATRIX mtxParent);						// �`�揈��
	void VtxUpdate() override {};							// ���_���W�X�V����

	void CalculationVtx();									// ���_�ő召�l�̌v�Z����

	// Setter
	//�N�H�[�^�j�I��
	void SetbQuaternion(bool useflg) { bQuaternion = useflg; }	//�N�H�[�^�j�I���̃Z�b�g
	void SetQuaternion(D3DXQUATERNION quaternion) { m_quaternion = quaternion; }
	void SetPos(D3DXVECTOR3 pos) override;					// ���W�ݒ菈��
	void SetPosOld(D3DXVECTOR3 posold) { m_posold  = posold;}					// ���W�ݒ菈�� 1�t���[���O

	void SetSize(D3DXVECTOR3 size) override;				// �T�C�Y�ݒ菈��
	void SetMove(D3DXVECTOR3 move) override;				// �ړ��ʐݒ菈��
	void SetCol(D3DXCOLOR col) override;					// �F�ݒ菈��
	void SetRot(D3DXVECTOR3 rot) override;					// �����ݒ菈��
	void SetMaxVtx(D3DXVECTOR3 Maxvtx);						// ���_�ő�l�ݒ菈��
	void SetMinVtx(D3DXVECTOR3 Minvtx);						// ���_�ŏ��l�ݒ菈��
	void SetParent(CObjectX* inParent) { m_pParent = inParent; }			// �e���f���̏��
	void SetCollisionFlag(bool inFlag) { m_isCollision = inFlag; }

	void SetScale(D3DXVECTOR3 scale) { m_scale = scale; };				// �X�P�[��

	void SetMtxTransPos(D3DXMATRIX TransPos) { mtxTransPos = TransPos; };				// �X�P�[��

	static void SetAxis(D3DXVECTOR3 axis) { m_axis = axis; };	//�v���C���[�̐i�s�x�N�g��
	
	// Getter
	D3DXVECTOR3 GetPos(void) override { return m_pos; }		// ���W�擾����
	D3DXVECTOR3 GetPosOld(void) { return m_posold; }		// ���W�擾����	1�t���[���O�̎擾

	D3DXVECTOR3 GetSize(void) override { return m_size; }	// �T�C�Y�擾����
	D3DXVECTOR3 GetMove(void) override { return m_move; }	// �ړ��ʎ擾����
	D3DXVECTOR3 GetRot(void) override { return m_rot; }		// �����擾����
	D3DXCOLOR GetCol(void) override { return m_col; }		// �F�擾����
	D3DXVECTOR3 GetMaxVtx(void) { return m_MaxVtx; }		// ���_�ő�l�擾����
	D3DXVECTOR3 GetMinVtx(void) { return m_MinVtx; }		// ���_�ŏ��l�擾����
	CObjectX* GetParent(void) { return m_pParent; }			// �e���f���̏��
	D3DXMATRIX *GetMtxWorld(void) { return &m_mtxWorld; }
	D3DXVECTOR3 GetScale(void) { return m_scale; }	// �X�P�[��
	D3DXMATRIX *GetMtxTransPos(void) { return &mtxTransPos; }
	static D3DXVECTOR3 GetAxis(void) {return m_axis; }			//�v���C���[�̐i�s�x�N�g��

	bool GetQuaternion() { return bQuaternion; }		//�N�H�[�^�j�I���t���O

	bool IsCollision() { return m_isCollision; }

	//�N�H�[�^�j�I��	
	D3DXQUATERNION GetQuaternionFst(void) { return m_quaternion; }

	static CObjectX *Create(const char *aFileName, D3DXVECTOR3 pos, int nPriority);	// ��������
	static CObjectX *Create(D3DXVECTOR3 pos, int nPriority);	// ��������
	void LoadModel(const char *aFileName);						// ���f���̓ǂݍ��ݏ���
	void BindTexture(std::string inPath);						// �h���̃e�N�X�`���|�C���^��e�̃e�N�X�`���|�C���^�ɑ�����鏈��
	void Projection(void);										// ���s���e����
	void SetLine(const D3DXVECTOR3 pos);						// ���C���Z�b�g����

	// Collision
	bool Collision(D3DXVECTOR3 *pPos, D3DXVECTOR3 *pPosOld, D3DXVECTOR3 *pSize, bool bQuaternion);							// �����蔻�� (���E, ��, ��O)
	bool UpCollision(D3DXVECTOR3 *pPos, D3DXVECTOR3 *pPosOld, D3DXVECTOR3 *pSize, D3DXVECTOR3 *pMove, bool bQuaternion);	// �����蔻�� (�㑤)

	//�N�H�[�^�j�I��
	void QuaternionCalculation(float ModelDiameter/*���f���̒��a*/, D3DXVECTOR3 *move, D3DXQUATERNION *FstQuaternion);

private:
	//-------------------------------------------------------------------------
	// �����o�[�ϐ�
	//-------------------------------------------------------------------------
	D3DXVECTOR3 m_pos;					// ���W
	D3DXVECTOR3 m_posold;					// ���W 1�t���[���O�̎擾

	D3DXVECTOR3 m_rot;					// �p�x
	D3DXVECTOR3 m_size;					// ���W
	D3DXVECTOR3 m_move;					// �p�x
	D3DXVECTOR3 m_MinVtx;				// ���f���̒��_�ŏ��l
	D3DXVECTOR3 m_MaxVtx;				// ���f���̒��_�ő�l
	D3DXCOLOR m_col;					// �F
	D3DXMATRIX m_mtxWorld;				// ���[���h�}�g���b�N�X

	LPDIRECT3DTEXTURE9 m_pTexture;		// �e�N�X�`���̃|�C���^
	D3DXMATRIX mtxTransPos;		//��]�폜

	D3DXVECTOR3 m_scale;	

	LPD3DXMESH m_pMesh;					// ���b�V�����ւ̃|�C���^
	LPD3DXBUFFER m_pBuffMat;			// �}�e���A�����ւ̃|�C���^
	DWORD m_NumMat;						// �}�e���A�����̐�

	CLine *m_pLine[12];					// ���C���̃|�C���^
	CObjectX *m_pParent;				// �e���f���̏��
	bool m_isCollision;					// �����蔻�肪�K�v��

	//-------------------------------------------------------------------------
	//�N�H�[�^�j�I��
	D3DXQUATERNION m_quaternion;

	static D3DXVECTOR3 m_axis;    // ��]��

	bool bQuaternion;	//�N�H�[�^�j�I���t���O

};
#endif