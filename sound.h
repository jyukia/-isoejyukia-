//**************************************************
//
// sound.h
// Author  : katsuki mizuki
//
//**************************************************
#ifndef _SOUND_H_	//���̃}�N����`������ĂȂ�������
#define _SOUND_H_	//�Q�d�C���N���[�h�h�~�̃}�N����`

//==================================================
// �C���N���[�h
//==================================================
#include <d3dx9.h>
#include <xaudio2.h>

//==================================================
// ��`
//==================================================
class CSound
{
	/* ����`�� */
public:
	enum ELabel
	{
		LABEL_NONE = -1,
		LABEL_BGM_TITLE = 0,	// �^�C�g��
		LABEL_BGM_GAME,			// �Q�[��
		LABEL_BGM_RESULT,		// ���U���g
		LABEL_SE_CHAKUCHI_01,	// ���n��_01
		LABEL_SE_CHAKUCHI_02,	// ���n��_02
		LABEL_SE_COUNTDOWN,		// �J�E���g�_�E��
		LABEL_SE_ENTER_KEY_01,	// ����{�^��_01
		LABEL_SE_ENTER_KEY_02,	// ����{�^��_02
		LABEL_SE_ENTER_KEY_03,	// ����{�^��_03
		LABEL_SE_GAMECLEAR,		// �Q�[���N���A
		LABEL_SE_GIMIKKU_CLEAR,	// �M�~�b�N�N���A
		LABEL_SE_HAGURUMA_KAITEN,	// ���ԂƉ�]
		LABEL_SE_HASHIRI,		// ���鉹
		LABEL_SE_HIKIZURI,		// �������艹
		LABEL_SE_JUMP_01,		// �W�����v��_01
		LABEL_SE_JUMP_02,		// �W�����v��_02
		LABEL_SE_NEGIMAKI,		// �˂�������
		LABEL_SE_RAKKA,			// ������
		LABEL_SE_RESPAWN,		// ���X�|�[����
		LABEL_MAX,
	};

	struct SParam
	{
		char *pFileName;	// �t�@�C����
		int loop;			// ���[�v
	};

	static const SParam PARAM[];	// �p�����[�^�̏��

	/* �������o�֐��� */
public:
	CSound();	// �f�t�H���g�R���X�g���N�^
	~CSound();	// �f�X�g���N�^

public:
	HRESULT Init(HWND hWnd);
	void Uninit();
	HRESULT Play(ELabel sound);
	void Stop(ELabel label);
	void Stop();

private:
	HRESULT CheckChunk(HANDLE hFile, DWORD format, DWORD* pChunkSize, DWORD* pChunkDataPosition);	// �`�����N�̃`�F�b�N
	HRESULT LoadChunkData(HANDLE hFile, void* pBuffer, DWORD dwBuffersize, DWORD dwBufferoffset);	// �`�����N�f�[�^�̓ǂݍ���

	/* �������o�ϐ��� */
private: 
	IXAudio2* m_pXAudio2;							// XAudio2�I�u�W�F�N�g�ւ̃C���^�[�t�F�C�X
	IXAudio2MasteringVoice* m_pMasteringVoice;		// �}�X�^�[�{�C�X
	IXAudio2SourceVoice* m_pSourceVoice[LABEL_MAX];	// �\�[�X�{�C�X
	BYTE* m_pDataAudio[LABEL_MAX];					// �I�[�f�B�I�f�[�^
	DWORD m_sizeAudio[LABEL_MAX];					// �I�[�f�B�I�f�[�^�T�C�Y
};

#endif // !_SOUND_H_
