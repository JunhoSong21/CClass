#pragma once

class CScene;

class CSceneMgr {
	SINGLE(CSceneMgr);

private:
	CScene* arrScene[(UINT)SCENE_TYPE::END];
	CScene* currScene;

public:
	void Init();
	void Update();
	void Render(HDC hDC);
};

