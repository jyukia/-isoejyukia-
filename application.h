#ifndef _APPLICATION_H_
#define _APPLICATION_H_

//=============================================================================
// �C���N���[�h�t�@�C��
//=============================================================================
#include "main.h"

//=============================================================================
// �N���X�̑O����`
//=============================================================================
class CInput;
class CCamera;
class CLight;
class CObjectX;
class CMeshfield;
class CTime;
class CTexture;
class CObjectXGroup;
class CSound;
class CDebugProc;
class CStageImgui;
class CMode;
//=============================================================================
// �N���X�̒�`
//=============================================================================
class CApplication
{
private:
	CApplication();

	static CApplication *m_pApplication;
public:
	//�V���O���g���ł̃C���X�^���X�̎擾

	static CApplication* Getinstnce() {return m_pApplication != nullptr ? m_pApplication : m_pApplication = new CApplication;}

	//=============================================================================
	// �񋓌^
	//=============================================================================
	enum MODE
	{
		MODE_TITLE = 0,
		MODE_GAME,
		MODE_GAME1,
		MODE_SELECT_STAGE,
		MODE_RESULT,
		MODE_RANKING,
		MODE_TUTORIAL,
		MODE_MAX
	};

	//-------------------------------------------------------------------------
	// �R���X�g���N�^�ƃf�X�g���N�^
	//-------------------------------------------------------------------------
	~CApplication();
	//-------------------------------------------------------------------------
	// �����o�[�֐�
	//-------------------------------------------------------------------------
	HRESULT Init(HINSTANCE hInstance, HWND hWnd, bool bWindow);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	void SetMode(MODE mode);
	MODE GetMode();
	CRenderer *GetRenderer();
	CInput *GetInput();
	CCamera *GetCamera() { return m_pCamera; }
	CTexture *GetTexture() { return m_pTexture; }
	CObjectXGroup *GetObjectXGroup() { return m_pObjectXGroup; }
	CSound *GetSound() { return m_pSound; }
	CStageImgui *GetImgui() { return m_Imgui; }
	CMode *GetpMode() { return m_pMode; }
private:
	//-------------------------------------------------------------------------
	// �����o�[�ϐ�
	//-------------------------------------------------------------------------
	CRenderer *m_pRenderer;
	CInput *m_pInput;
	MODE m_mode;
	CMode *m_pMode;
	CCamera *m_pCamera;
	CTexture *m_pTexture;
	CObjectXGroup *m_pObjectXGroup;
	CSound *m_pSound;
	CDebugProc *m_pDebugProc;			// �f�o�b�N�\��

	CStageImgui *m_Imgui;
};

#endif