//============================
//
// ファイル設定
// Author:磯江寿希亜 
//
//============================

#include "file.h"
#include "letter.h"
#include "object3D.h"
#include "objectX.h"
#include "player.h"

#include"SelectStage.h"

#include <fstream>


//===============================
//ゲーム内ヘッター
//===============================
Set DataSet;
namespace nl = nlohmann;
nl::json j;//リストの生成

//============================
//ゲット関数
//============================
Set *GetStatus(void)
{
	return &DataSet;
}

//============================
// 全部出力（置くだけ）
//============================
void OutputStatus()
{
	auto JsoninD3DXVVECTOR3 = [](nl::json& jsonf, std::string a, D3DXVECTOR3 inPos, D3DXVECTOR3 inRot)
	{
		jsonf[a] = {
			{ "POS" ,{ { "X",inPos.x },{ "Y",inPos.y },{ "Z",inPos.z } } },
			{ "ROT" ,{ { "X",inRot.x },{ "Y",inRot.y },{ "Z",inRot.z } } },

		};
	};

	{//	ボトル(小瓶)
		std::string a = "BOTTLE";
		std::string b = std::to_string(0);
		a += b;

		//情報
		JsoninD3DXVVECTOR3(j, a, D3DXVECTOR3(500.0f, 600.0f, -1200.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	}
	{//テ―ブル
		
		std::string a = "TABLE";
		std::string b = std::to_string(0);
		a += b;

		//情報
		JsoninD3DXVVECTOR3(j, a, D3DXVECTOR3(1000.0f, 0.0f, -1500.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	}
	for (int Cnt = 0; Cnt < 2; Cnt++)
	{//椅子 横

	std::string a = "CHAIRX";
	std::string b = std::to_string(Cnt);
	a += b;

	//情報
	JsoninD3DXVVECTOR3(j, a, D3DXVECTOR3(-500.0f +2800 * Cnt, 0.0f, -1500.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	}
	for (int Cnt = 0; Cnt < 2; Cnt++)
	{//椅子 奥
		std::string a = "CHAIRZ";
		std::string b = std::to_string(Cnt);
		a += b;

		//情報
		JsoninD3DXVVECTOR3(j, a, D3DXVECTOR3(1000.0f, 0.0f, -3000.0f + 2800 * Cnt), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	}
	float lch = -2600;
	for (int Cnt = 0; Cnt < 2; Cnt++)
	{//コップ
		std::string a = "CUPX";
		std::string b = std::to_string(Cnt);
		a += b;

		//情報
		JsoninD3DXVVECTOR3(j, a, D3DXVECTOR3(100.0f + 1500.0f * Cnt, 620.0f, -1700.0f + 200.0f * Cnt), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	}
	for (int Cnt = 0; Cnt < 2; Cnt++)
	{//皿
		std::string a = "PLATE";
		std::string b = std::to_string(Cnt);
		a += b;

		//情報
		JsoninD3DXVVECTOR3(j, a, D3DXVECTOR3(100.0f + 1500.0f * Cnt, 610.0f, -1700.0f + 200.0f * Cnt), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	}

	for (int Cnt = 0; Cnt < 2; Cnt++)
	{//スプーン
		std::string a = "SPOON";
		std::string b = std::to_string(Cnt);
		a += b;

		//情報
		JsoninD3DXVVECTOR3(j, a, D3DXVECTOR3(0.0f + 1700.0f * Cnt, 600.0f, -1700.0f + 300.0f * Cnt), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	}
	{//写真
		std::string a = "PICTURE";
		std::string b = std::to_string(0);
		a += b;

		//情報
		JsoninD3DXVVECTOR3(j, a, D3DXVECTOR3(100.0f, 600.0f, -1700.0f + lch), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	}
	{//自分写真
		std::string a = "01";
		std::string b = std::to_string(0);
		a += b;

		//情報
		JsoninD3DXVVECTOR3(j, a, D3DXVECTOR3(100.0f, 920.0f, -1680.0f+ lch), D3DXVECTOR3(-D3DX_PI / 2.0f, 0.0f, D3DX_PI));
	}

	{//宝箱
	std::string a = "CHEST";
	std::string b = std::to_string(0);
	a += b;

	//情報
	JsoninD3DXVVECTOR3(j, a, D3DXVECTOR3(4000.0f, 0.0f, -3700.0f), D3DXVECTOR3(0.0f, D3DX_PI / 2, 0.0f));
	}

	{//本棚
		std::string a = "BOOKSHELF";
		std::string b = std::to_string(0);
		a += b;

		//情報
		JsoninD3DXVVECTOR3(j, a, D3DXVECTOR3(-1500.0f, 0.0f, -3700.0f), D3DXVECTOR3(0.0f, -D3DX_PI/2, 0.0f));
	}
	{//ドア
		std::string a = "DOOR";
		std::string b = std::to_string(0);
		a += b;

		//情報
		JsoninD3DXVVECTOR3(j, a, D3DXVECTOR3(-1150.0f, 0.0f, 1700.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
	}
	{//壁 後ろ
		std::string a = "WALL";
		std::string b = std::to_string(0);
		a += b;

		//情報
		JsoninD3DXVVECTOR3(j, a, D3DXVECTOR3(1300.0f, 700.0f, 1750.0f), D3DXVECTOR3(-D3DX_PI /2.0f, 0.0f, 0.0f));
	}
	{//壁 前
		std::string a = "WALL1";
		std::string b = std::to_string(0);
		a += b;

		//情報
		JsoninD3DXVVECTOR3(j, a, D3DXVECTOR3(1300.0f, 700.0f, -4300.0f), D3DXVECTOR3(-D3DX_PI / 2.0f, 0.0f, D3DX_PI));
	}
	{//壁 左
		std::string a = "WALL2";
		std::string b = std::to_string(0);
		a += b;

		//情報
		JsoninD3DXVVECTOR3(j, a, D3DXVECTOR3(4300.0f, 700.0f, -1300.0f), D3DXVECTOR3(-D3DX_PI / 2.0f, 0.0f, D3DX_PI/2));
	}
	{//壁 右
		std::string a = "WALL3";
		std::string b = std::to_string(0);
		a += b;


		//情報
		JsoninD3DXVVECTOR3(j, a, D3DXVECTOR3(-1700.0f, 700.0f, -1300.0f), D3DXVECTOR3(-D3DX_PI / 2.0f, 0.0f, -D3DX_PI / 2));
	}

	auto jobj = j.dump();

	std::ofstream writing_fileL;
	const std::string pathToJSON = "Data/FILE/output_params.json";
	writing_fileL.open(pathToJSON, std::ios::out);
	writing_fileL << jobj << std::endl;
	writing_fileL.close();
}
//読み込み関数
void Load()
{
	std::ifstream ifs("Data/FILE/output_params.json");
	if (ifs)
	{
		ifs >> j;

		{//ロード統括
		}
		
		//選択されたカウントによってモデル配置を変える
		int SelectCount = CSelectStage::GetModeCount();

		{//小瓶
			std::string a = "BOTTLE";
			std::string b = std::to_string(0);
			a += b;

			//
			D3DXVECTOR3 pos = D3DXVECTOR3(j[a]["POS"]["X"], j[a]["POS"]["Y"], j[a]["POS"]["Z"]);
			D3DXVECTOR3 rot = D3DXVECTOR3(j[a]["ROT"]["X"], j[a]["ROT"]["Y"], j[a]["ROT"]["Z"]);
			CObjectX* bottle = CObjectX::Create("BOTTLE", pos,3);
		}
		{//テーブル
			std::string a = "TABLE";
			std::string b = std::to_string(0);
			a += b;

			//右
			D3DXVECTOR3 pos = D3DXVECTOR3(j[a]["POS"]["X"], j[a]["POS"]["Y"], j[a]["POS"]["Z"]);
			D3DXVECTOR3 rot = D3DXVECTOR3(j[a]["ROT"]["X"], j[a]["ROT"]["Y"], j[a]["ROT"]["Z"]);
			CObjectX* table = CObjectX::Create("TABLE", pos, 3);
		}
		for (int Cnt = 0; Cnt < 2; Cnt++)
		{//椅子
		std::string a = "CHAIRX";
		std::string b = std::to_string(Cnt);
		a += b;

		//右
		D3DXVECTOR3 pos = D3DXVECTOR3(j[a]["POS"]["X"], j[a]["POS"]["Y"], j[a]["POS"]["Z"]);
		D3DXVECTOR3 rot = D3DXVECTOR3(j[a]["ROT"]["X"], j[a]["ROT"]["Y"], j[a]["ROT"]["Z"]);
		CObjectX* chair = CObjectX::Create("CHAIR", pos, 3);
		}
		for (int Cnt = 0; Cnt < 2; Cnt++)
		{//椅子
		std::string a = "CHAIRZ";
		std::string b = std::to_string(Cnt);
		a += b;

		//右
		D3DXVECTOR3 pos = D3DXVECTOR3(j[a]["POS"]["X"], j[a]["POS"]["Y"], j[a]["POS"]["Z"]);
		D3DXVECTOR3 rot = D3DXVECTOR3(j[a]["ROT"]["X"], j[a]["ROT"]["Y"], j[a]["ROT"]["Z"]);
		CObjectX* chair = CObjectX::Create("CHAIR", pos, 3);
		}
		for (int Cnt = 0; Cnt < 2; Cnt++)
		{//
			std::string a = "CUPX";
			std::string b = std::to_string(Cnt);
			a += b;

			//
			D3DXVECTOR3 pos = D3DXVECTOR3(j[a]["POS"]["X"], j[a]["POS"]["Y"], j[a]["POS"]["Z"]);
			D3DXVECTOR3 rot = D3DXVECTOR3(j[a]["ROT"]["X"], j[a]["ROT"]["Y"], j[a]["ROT"]["Z"]);
			CObjectX* chair = CObjectX::Create("CUP", pos, 3);
		}
		for (int Cnt = 0; Cnt < 2; Cnt++)
		{//
			std::string a = "PLATE";
			std::string b = std::to_string(Cnt);
			a += b;

			//
			D3DXVECTOR3 pos = D3DXVECTOR3(j[a]["POS"]["X"], j[a]["POS"]["Y"], j[a]["POS"]["Z"]);
			D3DXVECTOR3 rot = D3DXVECTOR3(j[a]["ROT"]["X"], j[a]["ROT"]["Y"], j[a]["ROT"]["Z"]);
			CObjectX* chair = CObjectX::Create("PLATE", pos, 3);
		}
		for (int Cnt = 0; Cnt < 2; Cnt++)
		{//
			std::string a = "SPOON";
			std::string b = std::to_string(Cnt);
			a += b;

			//
			D3DXVECTOR3 pos = D3DXVECTOR3(j[a]["POS"]["X"], j[a]["POS"]["Y"], j[a]["POS"]["Z"]);
			D3DXVECTOR3 rot = D3DXVECTOR3(j[a]["ROT"]["X"], j[a]["ROT"]["Y"], j[a]["ROT"]["Z"]);
			CObjectX* pSpoon = CObjectX::Create("SPOON", pos, 3);
		}
		{//写真
			std::string a = "PICTURE";
			std::string b = std::to_string(0);
			a += b;

			//
			D3DXVECTOR3 pos = D3DXVECTOR3(j[a]["POS"]["X"], j[a]["POS"]["Y"], j[a]["POS"]["Z"]);
			D3DXVECTOR3 rot = D3DXVECTOR3(j[a]["ROT"]["X"], j[a]["ROT"]["Y"], j[a]["ROT"]["Z"]);
			CObjectX* picture = CObjectX::Create("PICTURE", pos, 3);
		}
		{//本棚
			std::string a = "BOOKSHELF";
			std::string b = std::to_string(0);
			a += b;

			//
			D3DXVECTOR3 pos = D3DXVECTOR3(j[a]["POS"]["X"], j[a]["POS"]["Y"], j[a]["POS"]["Z"]);
			D3DXVECTOR3 rot = D3DXVECTOR3(j[a]["ROT"]["X"], j[a]["ROT"]["Y"], j[a]["ROT"]["Z"]);
			CObjectX* pbookshelf = CObjectX::Create("BOOKSHELF", rot, pos, 3);
		}
		{//宝箱
			std::string a = "CHEST";
		std::string b = std::to_string(0);
		a += b;

		//
		D3DXVECTOR3 pos = D3DXVECTOR3(j[a]["POS"]["X"], j[a]["POS"]["Y"], j[a]["POS"]["Z"]);
		D3DXVECTOR3 rot = D3DXVECTOR3(j[a]["ROT"]["X"], j[a]["ROT"]["Y"], j[a]["ROT"]["Z"]);
		CObjectX* pchest = CObjectX::Create("CHEST", rot, pos, 3);
		}

		{//自分写真
			std::string a = "01";
			std::string b = std::to_string(0);
			a += b;

			D3DXVECTOR3 pos = D3DXVECTOR3(j[a]["POS"]["X"], j[a]["POS"]["Y"], j[a]["POS"]["Z"]);
			D3DXVECTOR3 rot = D3DXVECTOR3(j[a]["ROT"]["X"], j[a]["ROT"]["Y"], j[a]["ROT"]["Z"]);

			CObject3D* me = CObject3D::Create(pos, rot, D3DXVECTOR3(150, 0.0f, 250.0f), 3);
			me->LoadTexture("Data/TEXTURE/01.png");
		}
		{//ドア
			std::string a = "DOOR";
			std::string b = std::to_string(0);
			a += b;

			//右
			D3DXVECTOR3 pos = D3DXVECTOR3(j[a]["POS"]["X"], j[a]["POS"]["Y"], j[a]["POS"]["Z"]);
			D3DXVECTOR3 rot = D3DXVECTOR3(j[a]["ROT"]["X"], j[a]["ROT"]["Y"], j[a]["ROT"]["Z"]);
			CObjectX* door = CObjectX::Create("DOOR", pos, 3);
		}
		{//壁
			std::string a = "WALL";
			std::string b = std::to_string(0);
			a += b;

			//
			D3DXVECTOR3 pos = D3DXVECTOR3(j[a]["POS"]["X"], j[a]["POS"]["Y"], j[a]["POS"]["Z"]);
			D3DXVECTOR3 rot = D3DXVECTOR3(j[a]["ROT"]["X"], j[a]["ROT"]["Y"], j[a]["ROT"]["Z"]);

			CObject3D* wallX = CObject3D::Create(pos, rot, D3DXVECTOR3(3050,0.0f,1000.0f),3);
			wallX->LoadTexture("Data/TEXTURE/Background_6.png");
		}
		{//壁
			std::string a = "WALL1";
		std::string b = std::to_string(0);
		a += b;

		//
		D3DXVECTOR3 pos = D3DXVECTOR3(j[a]["POS"]["X"], j[a]["POS"]["Y"], j[a]["POS"]["Z"]);
		D3DXVECTOR3 rot = D3DXVECTOR3(j[a]["ROT"]["X"], j[a]["ROT"]["Y"], j[a]["ROT"]["Z"]);

		CObject3D* wallX = CObject3D::Create(pos, rot, D3DXVECTOR3(3050,0.0f,1000.0f),3);
		wallX->LoadTexture("Data/TEXTURE/Background_6.png");
		}
		{//壁
			std::string a = "WALL2";
			std::string b = std::to_string(0);
			a += b;

			//
			D3DXVECTOR3 pos = D3DXVECTOR3(j[a]["POS"]["X"], j[a]["POS"]["Y"], j[a]["POS"]["Z"]);
			D3DXVECTOR3 rot = D3DXVECTOR3(j[a]["ROT"]["X"], j[a]["ROT"]["Y"], j[a]["ROT"]["Z"]);

			CObject3D* wallX = CObject3D::Create(pos, rot, D3DXVECTOR3(3050, 0.0f, 1000.0f), 3);
			wallX->LoadTexture("Data/TEXTURE/Background_6.png");
		}
		{//壁
			std::string a = "WALL3";
		std::string b = std::to_string(0);
		a += b;

		//
		D3DXVECTOR3 pos = D3DXVECTOR3(j[a]["POS"]["X"], j[a]["POS"]["Y"], j[a]["POS"]["Z"]);
		D3DXVECTOR3 rot = D3DXVECTOR3(j[a]["ROT"]["X"], j[a]["ROT"]["Y"], j[a]["ROT"]["Z"]);

		CObject3D* wallX = CObject3D::Create(pos, rot, D3DXVECTOR3(3050, 0.0f, 1000.0f), 3);
		wallX->LoadTexture("Data/TEXTURE/Background_6.png");
		}

	}
}
//============================
// 読込み
//============================
nlohmann::json LoadJsonStage(const wchar_t* cUrl)
{
	std::ifstream ifs(cUrl);

	if (ifs)
	{
		nlohmann::json list;	// リストの作成

		ifs >> list;
		return list;
	}

	/* ↓ファイルを開くのを失敗した場合↓ */

	return nullptr;
}
