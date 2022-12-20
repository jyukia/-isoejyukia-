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

//=============================================================================
// �N���X�̒�`
//=============================================================================
class CApplication
{
public:

	//=============================================================================
	// �񋓌^
	//=============================================================================
	enum MODE
	{
		MODE_TITLE = 0,
		MODE_GAME,
		MODE_RESULT,
		MODE_RANKING,
		MODE_TUTORIAL,
		MODE_MAX
	};

	//-------------------------------------------------------------------------
	// �R���X�g���N�^�ƃf�X�g���N�^
	//-------------------------------------------------------------------------
	CApplication();
	~CApplication();

	//-------------------------------------------------------------------------
	// �����o�[�֐�
	//-------------------------------------------------------------------------
	HRESULT Init(HINSTANCE hInstance, HWND hWnd, bool bWindow);
	void Uninit(void);
	void Update(void);
	void Draw(void);
	static void SetMode(MODE mode);
	static MODE GetMode();
	static CRenderer *GetRenderer();
	static CInput *GetInput();
	static CCamera *GetCamera() { return m_pCamera; }
	static CTexture *GetTexture() { return m_pTexture; }
	static CObjectXGroup *GetObjectXGroup() { return m_pObjectXGroup; }
	static CSound *GetSound() { return m_pSound; }

private:
	//-------------------------------------------------------------------------
	// �����o�[�ϐ�
	//-------------------------------------------------------------------------
	static CRenderer *m_pRenderer;
	static CInput *m_pInput;
	static MODE m_mode;
	static CObject *m_pMode;
	static CCamera *m_pCamera;
	static CTexture *m_pTexture;
	static CObjectXGroup *m_pObjectXGroup;
	static CSound *m_pSound;
	static CDebugProc *m_pDebugProc;			// �f�o�b�N�\��

	static CStageImgui *m_Imgui;
};

#endif