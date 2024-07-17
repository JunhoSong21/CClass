#include "pch.h"
#include "CCore.h"

#include "CKeyMgr.h"
#include "CTimeMgr.h"

#include "CObject.h"

CObject obj;

CCore::CCore()
	: handle(0)
	, ptResolution{}
	, hDC(0)
	, hBit(0)
	, mDC(0)
{
}

CCore::~CCore() {
	ReleaseDC(handle, hDC);

	DeleteDC(mDC);
	DeleteObject(hBit);
}

void CCore::Update() {
	CTimeMgr::Instance()->Update();
	CKeyMgr::Instance()->Update();

	Vec2 vPos = obj.GetPos();

	if (CKeyMgr::Instance()->GetKeyState(KEY::LEFT) == KEY_TYPE::HOLD) {
		vPos.x -= 200.f * fDT;
	}
	if (CKeyMgr::Instance()->GetKeyState(KEY::RIGHT) == KEY_TYPE::HOLD) {
		vPos.x += 200.f * fDT;
	}
	if (CKeyMgr::Instance()->GetKeyState(KEY::UP) == KEY_TYPE::HOLD) {
		vPos.y -= 200.f * fDT;
	}
	if (CKeyMgr::Instance()->GetKeyState(KEY::DOWN) == KEY_TYPE::HOLD) {
		vPos.y += 200.f * fDT;
	}

	obj.SetPos(vPos);
}

void CCore::Render() {
	CTimeMgr::Instance()->Render();

	Rectangle(mDC, -1, -1, ptResolution.x + 1, ptResolution.y + 1);

	Vec2 vPos = obj.GetPos();
	Vec2 vScale = obj.GetScale();

	Rectangle(hDC, (int)(vPos.x - vScale.x / 2)
		, (int)(vPos.y - vScale.y / 2)
		, (int)(vPos.x + vScale.x / 2)
		, (int)(vPos.y + vScale.y / 2));

	BitBlt(hDC, 0, 0, ptResolution.x, ptResolution.y,
		mDC, 0, 0, SRCCOPY);
}

int CCore::Init(HWND _handle, POINT _pt) {
	handle = _handle;
	ptResolution = _pt;

	RECT rt = { 0, 0, ptResolution.x, ptResolution.y };
	AdjustWindowRect(&rt, WS_OVERLAPPEDWINDOW, true);
	SetWindowPos(handle, nullptr, 100, 100, rt.right - rt.left, rt.bottom - rt.top, 0);

	hDC = GetDC(handle);

	// 더블 버퍼링 용도의 비트맵과 DC를 만듦
	hBit = CreateCompatibleBitmap(hDC, ptResolution.x, ptResolution.y);
	mDC = CreateCompatibleDC(hDC);

	HBITMAP oldBit = (HBITMAP)SelectObject(mDC, hBit);
	DeleteObject(oldBit);

	obj.SetPos(Vec2((float)(ptResolution.x / 2), (float)(ptResolution.y / 2)));
	obj.SetScale(Vec2(100, 100));

	CTimeMgr::Instance()->Init();
	CKeyMgr::Instance()->Init();

	return S_OK;
}

void CCore::Progress() {
	Update();
	Render();
}