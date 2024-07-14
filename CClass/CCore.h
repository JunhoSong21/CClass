#pragma once

class CCore {
	SINGLE(CCore);
private:
	HWND	handle;
	POINT	ptResolution;
	HDC		hDC;

	HBITMAP hBit; // 더블 버퍼링 사용을 위한 선언
	HDC		mDC;  //

	void Update();
	void Render();

public:
	int Init(HWND _handle, POINT _pt);
	void Progress();

	HWND GetMainHandle() { return handle; }
};