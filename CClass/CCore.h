#pragma once

class CCore {
	SINGLE(CCore);
private:
	HWND	handle;
	POINT	ptResolution;
	HDC		hDC;

	void Update();
	void Render();

public:
	int Init(HWND _handle, POINT _pt);
	void Progress();

	HWND GetMainHandle() { return handle; }
};