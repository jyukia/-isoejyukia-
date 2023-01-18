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
class CMapcamera;
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
class CMeshLine;
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

	//===============================
	//�v�Z�̂��ߒǉ�
	//===============================
	struct VALUE_INT
	{
		// �ϐ��錾
		int   x, y;

		constexpr VALUE_INT() : x(0), y(0) { }
		constexpr VALUE_INT(int _x, int _y) : x(_x), y(_y) { }

		// ���Z
		VALUE_INT operator +(const VALUE_INT &texPattern) {
			VALUE_INT value;
			value.x = x + texPattern.x;
			value.y = y + texPattern.y;
			return value;
		}

		// ���Z(+=)
		VALUE_INT &operator +=(const VALUE_INT &texPattern) {
			x += texPattern.x;
			y += texPattern.y;
			return *this;
		}

		// ���Z
		VALUE_INT operator -(const VALUE_INT &texPattern) {
			VALUE_INT value;
			value.x = x - texPattern.x;
			value.y = y - texPattern.y;
			return value;
		}

		// ���Z(-=)
		VALUE_INT &operator -=(const VALUE_INT &texPattern) {
			x -= texPattern.x;
			y -= texPattern.y;
			return *this;
		}

		// ��Z
		VALUE_INT operator *(const VALUE_INT &texPattern) {
			VALUE_INT value;
			value.x = x * texPattern.x;
			value.y = y * texPattern.y;
			return value;
		}

		// ��Z(*=)
		VALUE_INT &operator *=(const VALUE_INT &texPattern) {
			x *= texPattern.x;
			y *= texPattern.y;
			return *this;
		}

		// ���
		VALUE_INT &operator =(const VALUE_INT &texPattern) {
			x = texPattern.x;
			y = texPattern.y;
			return *this;
		}
	};


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
	CMapcamera*GetMapCamera() { return m_pMapCamera; }

	CMeshLine* Getmeshline() { return m_meshline; }

	CTexture *GetTexture() { return m_pTexture; }
	CObjectXGroup *GetObjectXGroup() { return m_pObjectXGroup; }
	CSound *GetSound() { return m_pSound; }
	CStageImgui *GetImgui() { return m_Imgui; }
	CMode *GetpMode() { return m_pMode; }

	CLight *GetLight() { return m_Light; }

	HWND GetHWnd() { return Hwnd; }

private:
	//-------------------------------------------------------------------------
	// �����o�[�ϐ�
	//-------------------------------------------------------------------------
	HWND Hwnd;
	
	CRenderer *m_pRenderer;
	CInput *m_pInput;
	MODE m_mode;
	VALUE_INT m_calculation;
	CMode *m_pMode;
	CMeshLine *m_meshline;

	CCamera *m_pCamera;
	CMapcamera *m_pMapCamera;

	CTexture *m_pTexture;
	CObjectXGroup *m_pObjectXGroup;
	CSound *m_pSound;
	CDebugProc *m_pDebugProc;			// �f�o�b�N�\��

	CStageImgui *m_Imgui;
	CLight *m_Light;

};


////--------------------------------------------------
//// Author : Hamada Ryuuga
//// Author : Yuda Kaito
//// ����1  : float X        // ����	0.0f �` 1.0f�̊�
//// �Ԓl  : float / �v�Z����
////--------------------------------------------------
//namespace ease
//{
//	// �����ŎZ�o
//	float InSine(float x);
//	float OutSine(float x);
//	float InOutSine(float x);
//
//	// 2�̗ݏ�ŎZ�o
//	float InQuad(float x);
//	float OutQuad(float x);
//	float InOutQuad(float x);
//
//	// 3�̗ݏ�ŎZ�o
//	float InCubic(float x);
//	float OutCubic(float x);
//	float InOutCubic(float x);
//
//	// 4�̗ݏ�ŎZ�o
//	float InQuart(float x);
//	//float OutQuart(float x);
//	//float InOutQuart(float x);
//
//	// 5�̗ݏ�ŎZ�o
//	float InQuint(float x);
//	//float OutQuint(float x);
//	//float InOutQuint(float x);
//
//	// �w���֐��ŎZ�o
//	float InExpo(float x);
//	//float OutExpo(float x);
//	//float InOutExpo(float x);
//
//	float InCirc(float x);
//	//float OutCirc(float x);
//	//float InOutCirc(float x);
//
//	float InBack(float x, float s = 1.70158f);
//	//float OutBack(float x);
//	//float InOutBack(float x);
//
//	float InElastic(float x, float c = (2.f * D3DX_PI) / 3.f);
//	float OutElastic(float x, float c = (2.f * D3DX_PI) / 3.f);
//	float InOutElastic(float x, float c = (2.f * D3DX_PI) / 4.5f);
//
//	float OutBounce(float x, float n = 7.5625f, float d = 2.75f);
//	float InBounce(float x, float n = 7.5625f, float d = 2.75f);
//	float InOutBounce(float x, float n = 7.5625f, float d = 2.75f);
//}
////�A�v���P�[�V����
//namespace ease
//{
//
//	// �����ŎZ�o
//	float InSine(float x) { return 1 - cosf((x * D3DX_PI) * 0.5f); }
//	float OutSine(float x) { return sinf((x * D3DX_PI) * 0.5f); }
//	float InOutSine(float x) { return -(cosf(D3DX_PI * x) - 1.0f) * 0.5f; }
//
//	// 2�̗ݏ�ŎZ�o
//	float InQuad(float x) { return x * x; }
//	float OutQuad(float x) { return 1.0f - (1.0f - x) * (1 - x); }
//	float InOutQuad(float x) { return x < 0.5f ? 2.0f * x * x : 1.0f - powf(-2.0f * x + 2.0f, 2) * 0.5f; }
//
//	// 3�̗ݏ�ŎZ�o
//	float InCubic(float x) { return x * x * x; }
//	float OutCubic(float x) { return 1 - powf(1.0f - x, 3.0f); }
//	float InOutCubic(float x) { return x < 0.5f ? 4.0f * x * x * x : 1.0f - powf(-2.0f * x + 2.0f, 3) * 0.5f; }
//
//	// 4�̗ݏ�ŎZ�o
//	float InQuart(float x) { return x * x * x * x; }
//	//float OutQuart(float x);
//	//float InOutQuart(float x);
//
//	// 5�̗ݏ�ŎZ�o
//	float InQuint(float x) { return x * x * x * x * x; }
//	//float OutQuint(float x);
//	//float InOutQuint(float x);
//
//	// �w���֐��ŎZ�o
//	float InExpo(float x) { return x == 0.0f ? 0 : powf(2.0f, 10.0f * x - 10.0f); }
//	//float OutExpo(float x);
//	//float InOutExpo(float x);
//
//	float InCirc(float x) { return 1.0f - sqrtf(1.0f - powf(x, 2)); }
//	//float OutCirc(float x);
//	//float InOutCirc(float x);
//
//	float InBack(float x, float s) { return (s + 1.0f) * x * x * x - s * x * x; }
//	//float OutBack(float x);
//	//float InOutBack(float x);
//
//	float InElastic(float x, float c) { return x == 0 ? 0 : x == 1 ? 1 : -powf(2.f, 10.f * x - 10.f) * sinf((x * 10.f - 10.75f) * c); }
//	float OutElastic(float x, float c) { return x == 0 ? 0 : x == 1 ? 1 : powf(2.f, -10.f * x) * sinf((x * 10.f - 0.75f) * c) + 1.f; }
//	float InOutElastic(float x, float c) { return x == 0 ? 0 : x == 1 ? 1 : x < 0.5f ? -(powf(2.f, 20.f * x - 10.f) * sinf((x * 20.f - 11.125f) * c)) * 0.5f : (powf(2.f, -20.f * x + 10.f) * sinf((x * 20.f - 11.125f) * c)) * 0.5f + 1.f; }
//
//	float InBounce(float x, float n, float d) { return 1.0f - OutBounce(1 - x, n, d); }
//	float OutBounce(float x, float n, float d)
//	{
//		if (x < 1.0f / d)
//		{
//			return n * x * x;
//		}
//		else if (x < 2.0f / d)
//		{
//			return n * (x -= 1.5f / d) * x + 0.75f;
//		}
//		else if (x < 2.5f / d)
//		{
//			return n * (x -= 2.25f / d) * x + 0.9375f;
//		}
//		else
//		{
//			return n * (x -= 2.625f / d) * x + 0.984375f;
//		}
//	}
//	float InOutBounce(float x, float n, float d) { return x < 0.5f ? (1.0f - OutBounce(1.0f - 2.0f * x, n, d)) * 0.5f : (1.0f + OutBounce(2.0f * x - 1.0f, n, d)) * 0.5f; }
//
//}

#endif