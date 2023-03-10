#ifndef _MAIN_H_
#define _MAIN_H_

//*****************************************************************************
// ライブラリーリンク
//*****************************************************************************
#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"winmm.lib")
#pragma comment(lib,"dxguid.lib")        //DirectXコンポーネント（部品）使用に必要
#pragma comment(lib,"dinput8.lib")       //入力処理に必要
#pragma comment(lib,"xinput.lib")        //入力処理に必要

//*****************************************************************************
// インクルード
//*****************************************************************************

//=============================================================================
// マクロ定義
//=============================================================================
#define SCREEN_SPLIT_WIDTH	(200.0f)		//分割画面の幅
#define SCREEN_SPLIT_HEIGHT	(740.0f)		//分割画面の高さ


#ifdef _DEBUG
#define CHECK_MEM_LEAK
#endif // _DEBUG

//普段使用禁止
#ifdef CHECK_MEM_LEAK
//#define new new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#endif // CHECK_MEM_LEAK

//*****************************************************************************
// 定数定義
//*****************************************************************************
namespace
{
	// ウインドウのクラス名
	LPCTSTR CLASS_NAME = _T("AppClass");
	// ウインドウのキャプション名
	LPCTSTR WINDOW_NAME = _T("kedama");
}

// スクリーンの幅
const int SCREEN_WIDTH = 1280;
// スクリーンの幅の真ん中
const float SCREEN_WIDTH_HALF = 640.0f;
// スクリーンの高さ
const int SCREEN_HEIGHT = 720;
// スクリーンの高さの真ん中
const float SCREEN_HEIGHT_HALF = 360.0f;


//*****************************************************************************
// 前方宣言
//*****************************************************************************
class CRenderer;
class CObject;

//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
int GetFPS(void);

#endif