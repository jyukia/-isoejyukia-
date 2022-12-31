#ifndef _APPLICATION_H_
#define _APPLICATION_H_

//=============================================================================
// インクルードファイル
//=============================================================================
#include "main.h"

//=============================================================================
// クラスの前方定義
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
// クラスの定義
//=============================================================================
class CApplication
{
private:
	CApplication();

	static CApplication *m_pApplication;
public:
	//シングルトンでのインスタンスの取得

	static CApplication* Getinstnce() {return m_pApplication != nullptr ? m_pApplication : m_pApplication = new CApplication;}

	//=============================================================================
	// 列挙型
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
	// コンストラクタとデストラクタ
	//-------------------------------------------------------------------------
	~CApplication();
	//-------------------------------------------------------------------------
	// メンバー関数
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
	// メンバー変数
	//-------------------------------------------------------------------------
	CRenderer *m_pRenderer;
	CInput *m_pInput;
	MODE m_mode;
	CMode *m_pMode;
	CCamera *m_pCamera;
	CTexture *m_pTexture;
	CObjectXGroup *m_pObjectXGroup;
	CSound *m_pSound;
	CDebugProc *m_pDebugProc;			// デバック表示

	CStageImgui *m_Imgui;
};

#endif