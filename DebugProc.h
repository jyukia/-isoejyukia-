#ifndef _DebugProc_H_
#define _DebugProc_H_

//*****************************************************************************
// インクルード
//*****************************************************************************
#include "main.h"

class CDebugProc
{
public:

//--------------------------------------------------------------------
// コンストラクタとデストラクタ
//--------------------------------------------------------------------
	CDebugProc();
	~CDebugProc();

	//--------------------------------------------------------------------
	// メンバ関数
	//--------------------------------------------------------------------
	void Init();				// 初期化
	void Uninit();				// 終了	
	//--------------------------------------------------------------------
	// 静的メンバ関数
	//--------------------------------------------------------------------
	static void Print(const char *pFormat, ...);		// 文字列の登録
	static void Draw(void);								// 表示

private:
	//--------------------------------------------------------------------
	// 静的メンバ変数
	//--------------------------------------------------------------------
	static LPD3DXFONT	m_pFont;			// フォント情報
	static TCHAR			m_aStr[0xfff];		// 登録文字列
};

#endif


