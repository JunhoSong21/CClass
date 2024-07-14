#include "pch.h"
#include "CKeyMgr.h"

#include "CCore.h"

int arrVK[(int)KEY::LAST] = {
	VK_LEFT,
	VK_RIGHT,
	VK_UP,
	VK_DOWN,
	'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P',
	'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L',
	'Z', 'X', 'C', 'V', 'B', 'N', 'M',
	VK_MENU,
	VK_LSHIFT,
	VK_SPACE,
	VK_RETURN,
	VK_ESCAPE,
};

CKeyMgr::CKeyMgr() 
{
}

CKeyMgr::~CKeyMgr()
{
}

void CKeyMgr::Init() {
	for (int i = 0; i < (int)KEY::LAST; ++i) {
		vecKey.emplace_back(KeyInfo{ KEY_TYPE::NONE, false });
	}
}

void CKeyMgr::Update() {

}
