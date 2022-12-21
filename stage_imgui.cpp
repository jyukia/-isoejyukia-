//**************************************************
//
// Hackathon ( imgui_property.cpp )
// Author  : katsuki mizuki
// Author  : Tanaka Kouta
// Author  : Hamada Ryuga
// Author  : Yuda Kaito
//
////**************************************************

//-----------------------------------------------------------------------------
// include
//-----------------------------------------------------------------------------
#include "stage_imgui.h"
//-----------------------------------------------------------------------------
// imgui
//-----------------------------------------------------------------------------
#define IMGUI_DEFINE_MATH_OPERATORS
//#include "imgui_internal.h"
//#include <implot.h>

//-----------------------------------------------------------------------------
// json
//-----------------------------------------------------------------------------
#include <fstream>

//-----------------------------------------------------------------------------
// stage
//-----------------------------------------------------------------------------
#include "main.h"
#include "application.h"
#include "texture.h"
#include "object.h"
#include "camera.h"
#include "meshfield.h"

#include"game.h"
#include"Player.h"
//-----------------------------------------------------------------------------
// コンストラクタ
//-----------------------------------------------------------------------------
CStageImgui::CStageImgui() :
	sliderIntmodel(0),
	sliderIntmesh(0)
{
}

//-----------------------------------------------------------------------------
// デストラクタ
//-----------------------------------------------------------------------------
CStageImgui::~CStageImgui()
{
}

//-----------------------------------------------------------------------------
// 初期化
//-----------------------------------------------------------------------------
HWND CStageImgui::Init(HWND hWnd, LPDIRECT3DDEVICE9 pDevice)
{
	// 初期化
	HWND outWnd = CImguiProperty::Init(hWnd, pDevice);

	for (int nCnt = 0; nCnt < 3; nCnt++)
	{// 初期化
		m_fMeshPos[nCnt] = 0;
	}

	return outWnd;
}

//-----------------------------------------------------------------------------
// 終了
//-----------------------------------------------------------------------------
void CStageImgui::Uninit(HWND hWnd, WNDCLASSEX wcex)
{
	CImguiProperty::Uninit(hWnd, wcex);
}

//-----------------------------------------------------------------------------
// 更新
//-----------------------------------------------------------------------------
bool CStageImgui::Update()
{
#ifdef _DEBUG

	CImguiProperty::Update();

	// テキスト表示
	ImGui::Text("FPS  : %.2f", ImGui::GetIO().Framerate);
	ImGui::Separator();

	//TaskBarUpdate();	// タスクバーの更新
	//ImGui::SliderFloat3(u8"ロット", &sliderRot.x, -3.14f, 3.14f);
	//ImGui::Separator();

	static bool checkBox = true;

	int AnimationKeySet;

	// メッシュのposス変更
	ImGui::DragFloat3("pos", &m_fMeshPos[0], 10.0f, 10000.0f, 0.5f);
	//CGame::GetPlayer()->SetPos(D3DXVECTOR3(m_fMeshPos[0], m_fMeshPos[1], m_fMeshPos[2]));

	ImGui::Separator();
	ImGui::SliderInt(u8"キーフレーム数", &AnimationKeySet, 1, 1000);

	if (ImGui::Button(u8"メッシュの生成"))
	{// ボタンが押された
		checkBox = !checkBox;
	}

	ImGui::End();
	return false;
#endif // _DEBUG
}

//--------------------------------------------------
// 描画
//--------------------------------------------------
void CStageImgui::Draw()
{
	CImguiProperty::Draw();
}

//--------------------------------------------------
// ポスのセット
//--------------------------------------------------
void CStageImgui::SetMeshPos(float x, float y, float z)
{
	m_fMeshPos[0] = x;
	m_fMeshPos[1] = y;
	m_fMeshPos[2] = z;
}

//--------------------------------------------------
// タスクバーの更新
//--------------------------------------------------
//void CStageImgui::TaskBarUpdate(void)
//{
//	//if (!ImGui::BeginMenuBar())
//	//{//タスクバー
//	//	return;
//	//}
//
//	//auto SaveLoad = [](const char* name,const char* path)
//	//{
//	//	if (ImGui::BeginMenu(name))
//	//	{
//	//		//HWND Wnd = GetWnd();
//	//		if (ImGui::MenuItem("Save"))
//	//		{
//	//			//MessageBox(Wnd, "セーブしますか？", "今消したら保存されてないよ！", MB_OK);
//	//			//CGame::GetStage()->SavefileMesh(path);
//	//		}
//	//		else if (ImGui::MenuItem("Load"))
//	//		{
//	//			//MessageBox(Wnd, "ロードしますか？", "今消したら保存されてないよ！", MB_OK);
//	//			//CGame::GetStage()->LoadfileMesh(path);
//	//		}
//
//	//		ImGui::EndMenu();
//	//	}
//	//};
//
//	//auto SaveLoadModel = [](const char* name, const char* path)
//	//{
//	//	if (ImGui::BeginMenu(name))
//	//	{
//	//		HWND Wnd = GetWnd();
//	//		if (ImGui::MenuItem("Save"))
//	//		{
//	//			MessageBox(Wnd, "セーブしますか？", "今消したら保存されてないよ！", MB_OK);
//	//			CGame::GetStage()->Savefile(path);
//	//		}
//	//		else if (ImGui::MenuItem("Load"))
//	//		{
//	//			MessageBox(Wnd, "ロードしますか？", "今消したら保存されてないよ！", MB_OK);
//	//			CGame::GetStage()->Loadfile(path);
//	//		}
//
//	//		ImGui::EndMenu();
//	//	}
//	//};
//	//SaveLoad(u8"メッシュ", "data\\testmesh.json");
//	//SaveLoadModel(u8"モデル", "data\\testBil.json");
//
//	//ImGui::EndMenuBar();
//}
