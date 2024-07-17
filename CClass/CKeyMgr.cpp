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
	// 윈도우 포커싱
	HWND hWnd = GetFocus();
	
	// O 
	if (nullptr != hWnd) {
		// 키를 누르고 있는가?
		for (int i = 0; i < (int)KEY::LAST; ++i) {
			if (GetAsyncKeyState(arrVK[i]) & 0x8000) {
				if (vecKey[i].Prev) {
					vecKey[i].State = KEY_TYPE::HOLD;
				}
				else {
					vecKey[i].State = KEY_TYPE::TAP;
				}
				vecKey[i].Prev = true;
			}
			else {
				if (vecKey[i].Prev) {
					vecKey[i].State = KEY_TYPE::AWAY;
				}
				else {
					vecKey[i].State = KEY_TYPE::NONE;
				}
				vecKey[i].Prev = false;
			}
		}
	}

	// X
	else {
		for (int i = 0; i < (int)KEY::LAST; ++i) {
			vecKey[i].Prev = false;
			if (KEY_TYPE::TAP == vecKey[i].State || KEY_TYPE::HOLD == vecKey[i].State) {
				vecKey[i].State = KEY_TYPE::AWAY;
			}
			else if (KEY_TYPE::AWAY == vecKey[i].State)
				vecKey[i].State = KEY_TYPE::NONE;
		}
	}
}
