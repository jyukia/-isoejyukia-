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
			{ "ROT" ,{ { "X",inRot.x },{ "Y",inRot.y },{ "Z",inRot.z } } }
		};
	};

	{//	ボトル(小瓶)
		std::string a = "BOTTLE";
		std::string b = std::to_string(1);
		a += b;

		//情報
		JsoninD3DXVVECTOR3(j, a, D3DXVECTOR3(0.0f, 0.0f, 0.0f), D3DXVECTOR3(0.0f, 0.0f, 0.0f));
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

		{//小瓶
			std::string a = "BOTTLE";
			std::string b = std::to_string(1);
			a += b;

			//右
			D3DXVECTOR3 pos = D3DXVECTOR3(j[a]["POS"]["X"], j[a]["POS"]["Y"], j[a]["POS"]["Z"]);
			D3DXVECTOR3 rot = D3DXVECTOR3(j[a]["ROT"]["X"], j[a]["ROT"]["Y"], j[a]["ROT"]["Z"]);
			CObjectX* bottle = CObjectX::Create("BOTTLE", pos,3);
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
