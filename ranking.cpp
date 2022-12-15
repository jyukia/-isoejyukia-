//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include <stdio.h>
#include "application.h"
#include "fade.h"
#include "input.h"
#include "ranking.h"
#include "renderer.h"
#include "object.h"
#include "object2D.h"

//=============================================================================
// �ÓI�����o�ϐ��錾
//=============================================================================
CNumber *CRanking::m_apNumber[MAX_RANKINGRANK][MAX_RANKING] = {};
int CRanking::aData[MAX_RANKINGRANK] = {};
int CRanking::m_nRanking = 0;

//=============================================================================
// �R���X�g���N�^
//=============================================================================
CRanking::CRanking(): m_bmodeflg(false)
{
}

//=============================================================================
// �f�X�g���N�^
//=============================================================================
CRanking::~CRanking()
{
}

//=============================================================================
// ����������
//=============================================================================
HRESULT CRanking::Init(void)
{
	{//������
		m_bmodeflg = false;
	}


	//�f�o�C�X�̎擾
	LPDIRECT3DDEVICE9 pDevice = CApplication::GetRenderer()->GetDevice();

	//�^�C�g���z�u
	m_pObject2D[0] = CObject2D::Create("RANKING", D3DXVECTOR3(1280.0f / 2, -20.0f, 0.0f), D3DXVECTOR3(500.0f, 500.0f, 0.0f), PRIORITY_LEVEL0);


	////�e�N�X�`���̓ǂݍ���
	//D3DXCreateTextureFromFile(pDevice,
	//	"data\\TEXTURE\\ranking.png",
	//	&m_pTexture[0]);

	////�e�N�X�`���̓ǂݍ���
	//D3DXCreateTextureFromFile(pDevice,
	//	"data\\TEXTURE\\ranking_logo.png",
	//	&m_pTexture[1]);

	////�e�N�X�`���̓ǂݍ���
	//D3DXCreateTextureFromFile(pDevice,
	//	"data\\TEXTURE\\ranking_rank.png",
	//	&m_pTexture[2]);

	////�e�N�X�`���̓ǂݍ���
	//D3DXCreateTextureFromFile(pDevice,
	//	"data\\TEXTURE\\number000.png",
	//	&m_pTexture[3]);

	//�^�C�g���摜(��)�̐���
	//CObject2D* test = CObject2D::Create("INIESUTA", D3DXVECTOR3(SCREEN_WIDTH_HALF, SCREEN_HEIGHT_HALF, 0.0f), D3DXVECTOR3(700.0f, 500.0f, 0.0f), CObject::PRIORITY_LEVEL3);

	//�t�@�C���ǂݍ��ݏ���
	Load();

	return S_OK;
}

//=============================================================================
// �I������
//=============================================================================
void CRanking::Uninit(void)
{
	//�C���X�^���X�̉������
	CObject::Release();
}

//=============================================================================
// �X�V����
//=============================================================================
void CRanking::Update(void)
{
	//���͏����p�̃|�C���^�錾
	CInput *pInput = CApplication::GetInput();

	if (!m_bmodeflg)
	{
		if (pInput->Trigger(DIK_RETURN))
		{
			m_bmodeflg = true;
		}
	}


	if (pInput->Trigger(DIK_RETURN) && m_pFade->GetFade() == CFade::FADE_NONE)
	{// ENTER�L�[�������ꂽ����s
		//�t�@�C�������o������
		Save();

		//���[�h�ݒ�
		CFade::SetFade(CApplication::MODE_TITLE);
	}

	D3DXVECTOR3 pos = m_pObject2D[0]->GetPos();

	if (pos.y >= SCREEN_HEIGHT_HALF)
	{
		m_pObject2D[0]->SetMove(D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	}
	else
	{
		m_pObject2D[0]->SetMove(D3DXVECTOR3(0.0f, 2.0f, 0.0f));
	}

	if (m_bmodeflg)
	{
		m_pObject2D[0]->SetPos(D3DXVECTOR3(SCREEN_WIDTH_HALF, SCREEN_HEIGHT_HALF, 0.0f));
	}

}

//=============================================================================
// �`�揈��
//=============================================================================
void CRanking::Draw(void)
{
}

//=============================================================================
// �t�@�C���ǂݍ��ݏ���
//=============================================================================
void CRanking::Load(void)
{
	//�t�@�C���|�C���^�錾
	FILE*pFile;

	//�t�@�C�����J��
	pFile = fopen("Data\\SAVE\\ranking.txt", "r");

	if (pFile != NULL)
	{//�t�@�C�����J�����ꍇ
		for (int nCntData = 0; nCntData < MAX_RANKINGRANK; nCntData++)
		{
			//�t�@�C���ɐ��l�������o��
			fscanf(pFile, "%d\n", &aData[nCntData]);
		}
		//�t�@�C�������
		fclose(pFile);
	}
	else
	{//�t�@�C�����J���Ȃ������ꍇ
		printf("***�t�@�C�����J���܂���ł���***");
	}
}

//=============================================================================
// �t�@�C�������o������
//=============================================================================
void CRanking::Save(void)
{
	//�t�@�C���|�C���^�錾
	FILE*pFile;

	//�t�@�C�����J��
	pFile = fopen("data\\ranking.txt", "w");

	if (pFile != NULL)
	{//�t�@�C�����J�����ꍇ
		for (int nCnt = 0; nCnt < MAX_RANKINGRANK; nCnt++)
		{
			//�t�@�C���ɐ��l�������o��
			fprintf(pFile, "%d\n", aData[nCnt]);
		}
		//�t�@�C�������
		fclose(pFile);
	}
	else
	{//�t�@�C�����J���Ȃ������ꍇ
		printf("***�t�@�C�����J���܂���ł���***");
	}
}

//=============================================================================
// �X�R�A�̐ݒ菈��
//=============================================================================
void CRanking::SetRankingScore()
{
	int aPosTexU[MAX_RANKINGRANK][MAX_RANKING];

	if (m_nRanking > aData[MAX_RANKINGRANK - 1])
	{
		aData[MAX_RANKINGRANK - 1] = m_nRanking;
	}

	for (int nCount = 0; nCount < MAX_RANKINGRANK - 1; nCount++)
	{
		for (int nCount2 = nCount + 1; nCount2 < MAX_RANKINGRANK; nCount2++)
		{
			if (aData[nCount] < aData[nCount2])
			{
				int nMin = aData[nCount];
				aData[nCount] = aData[nCount2];
				aData[nCount2] = nMin;
			}
		}
	}

	for (int nCntScore = 0; nCntScore < MAX_RANKINGRANK; nCntScore++)
	{
		aPosTexU[nCntScore][0] = aData[nCntScore] % 100000 / 10000;
		aPosTexU[nCntScore][1] = aData[nCntScore] % 10000 / 1000;
		aPosTexU[nCntScore][2] = aData[nCntScore] % 1000 / 100;
		aPosTexU[nCntScore][3] = aData[nCntScore] % 100 / 10;
		aPosTexU[nCntScore][4] = aData[nCntScore] % 10 / 1;
	}

	////�e�N�X�`�����W�̐ݒ�
	//for (int nCnt = 0; nCnt < MAX_RANKINGRANK; nCnt++)
	//{
	//	for (int nCntScore = 0; nCntScore < MAX_RANKING; nCntScore++)
	//	{
	//		float fShiftWidth = 1.0f / 10;
	//		m_apNumber[nCnt][nCntScore]->SetUV((float)aPosTexU[nCnt][nCntScore] * fShiftWidth, (fShiftWidth + (float)aPosTexU[nCnt][nCntScore] * fShiftWidth), 0.0f, 1.0f);
	//	}
	//}
}

//=============================================================================
// ���̎擾
//=============================================================================
void CRanking::GetRanking(int Ranking)
{
	m_nRanking = Ranking;
}

//=============================================================================
// ��������
//=============================================================================
CRanking * CRanking::Create()
{
	CRanking *pRanking = new CRanking;

	if (pRanking != nullptr)
	{
		pRanking->Init();
	}

	return pRanking;
}
