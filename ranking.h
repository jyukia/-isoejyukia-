#ifndef _RANKING_H_
#define _RANKING_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "mode.h"

//=============================================================================
// �O����`
//=============================================================================
class CObject2D;
class CFade;
class CNumber;

//=============================================================================
// �}�N����`
//=============================================================================
#define MAX_RANKING        (5)        //�����L���O�̌���
#define MAX_RANKINGRANK    (5)        //�����L���O�̏��ʕ�
#define MAX_TEXTURE        (4)        //�e�N�X�`���̐�

//=============================================================================
// �N���X�̒�`
//=============================================================================
class CRanking : public CMode
{
public:
	CRanking();
	~CRanking();

	//�v���g�^�C�v�錾
	HRESULT Init(void);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void Load(void);
	void Save(void);
	static void SetRankingScore();
	static void GetRanking(int Ranking);

	static CRanking * Create();

private:
	LPDIRECT3DTEXTURE9 m_pTexture[MAX_TEXTURE] = {};
	CObject2D * m_pObject2D[3];
	static CNumber * m_apNumber[MAX_RANKINGRANK][MAX_RANKING]; 
	static int m_nRanking;
	static int aData[MAX_RANKINGRANK];

	bool m_bmodeflg;
	CFade *m_pFade;
};
#endif