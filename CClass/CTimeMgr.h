#pragma once

class CTimeMgr {
	SINGLE(CTimeMgr);
private:
	LARGE_INTEGER	curCount;	// 현재 시간
	LARGE_INTEGER	prevCount;	// 이전 시간
	LARGE_INTEGER	preQuency;	// 성능 카운터가 초당 몇 번 진행되었는가 저장

	double			dDT;		// 두 프레임 사이의 시간 값 > (현재시간 - 이전시간)/시스템 성능 카운터의 주파수
	double			dAcc;		// 누적 경과 시간
	UINT			iCallCount; // Update한 함수 호출 수
	UINT			iFPS;		// 프레임 속도 : 1초당 Update 호출 수

public:
	void			Init();
	void			Update();
	void			Render();
	double			GetDT() { return dDT; }
	float			GetfDT() { return (float)dDT; }
};