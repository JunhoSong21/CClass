#pragma once

class CObject;

class CScene {
private:
	vector<CObject*>	arrObj[(UINT)GROUP_TYPE::END];
	wstring				strName;

public:
	CScene();
	~CScene();

	void Update();
	void Render(HDC hDC);

	virtual void Enter() = 0;
	virtual void Exit() = 0;
};