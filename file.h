#ifndef _FILE_H_	// ���̃}�N����`������ĂȂ�������
#define _FILE_H_	// ��d�C���N���[�h�h�~�̃}�N����`

#include "nlohmann/json.hpp"

//=====================================
// �v���g�^�C�v�錾
//=====================================
nlohmann::json LoadJsonStage(const wchar_t* cUrl);

#endif
