//-----------------------------------------------------------------------------
// include
//-----------------------------------------------------------------------------
#include "load_stage.h"
#include "file.h"
#include "objectX_group.h"
#include"object.h"

//=============================================================================
// コンストラクタ
//=============================================================================
CLoadStage::CLoadStage()
{
}

//=============================================================================
// デストラクタ
//=============================================================================
CLoadStage::~CLoadStage()
{
}

//-----------------------------------------------------------------------------
// ステージの読込み
//-----------------------------------------------------------------------------
void CLoadStage::LoadAll(const D3DXVECTOR3& inPos)
{
	nlohmann::json list = LoadJsonStage(L"Data/FILE/stage.json");

	int size = (int)list["STAGE"].size();

	for (int i = 0; i < size; ++i)
	{
		D3DXVECTOR3 pos = D3DXVECTOR3(list["STAGE"][i]["POS"][0], list["STAGE"][i]["POS"][1], list["STAGE"][i]["POS"][2]);
		pos += inPos;
		CObjectX* objectX = CObjectX::Create(pos, CObject::PRIORITY_LEVEL3);

		// 角度の設定
		D3DXVECTOR3 rot = D3DXVECTOR3(list["STAGE"][i]["ROT"][0], list["STAGE"][i]["ROT"][1], list["STAGE"][i]["ROT"][2]);
		objectX->SetRot(rot);

		bool collision = list["STAGE"][i]["COLLISION"] == "TRUE";
		objectX->SetCollisionFlag(collision);

		// モデルの設定
		std::string tag = list["STAGE"][i]["MODEL"];
		objectX->LoadModel(tag.c_str());

		// 位置の再計算
		objectX->CalculationVtx();
	}
}

void CLoadStage::SaveAll()
{
	int nIndex = 0;
	nlohmann::json list;

	for (int maxObje =0; maxObje <= CObject::PRIORITY_LEVELMAX; maxObje++)
	{
		CObject* pObje = CObject::GetTop(maxObje);

		while (pObje != nullptr)
		{
			if (pObje->GetObjType() == CObject::OBJTYPE_MODEL)
			{
				CObjectX* pObjeX = dynamic_cast<CObjectX*>(pObje);  // ダウンキャスト

				std::string name = "OBJECTX";
				std::string Number = std::to_string(nIndex);
				name += Number;

				list[name] = {
					{ "POS",{
						{ "X", pObjeX->GetPos().x } ,
						{ "Y", pObjeX->GetPos().y } ,
						{ "Z", pObjeX->GetPos().z } } }, };

				nIndex++;
			}
			//pObjectにpObjectのpNextを代入
			pObje = pObje->GetNext();
		}
	}

	auto jobj = list.dump();
	std::ofstream writing_file;
	const std::string pathToJSON = "Data/FILE/Save.Json";
	writing_file.open(pathToJSON, std::ios::out);
	writing_file << jobj << std::endl;
	writing_file.close();
}
