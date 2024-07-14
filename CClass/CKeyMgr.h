#pragma once

enum class KEY_TYPE {
	NONE,
	TAP,
	HOLD,
	AWAY,
};

enum class KEY {
	LEFT,
	RIGHT,
	UP,
	DOWN,
	Q, W, E, R, T, Y, U, I, O, P,
	A, S, D, F, G, H, J, K, L,
	Z, X, C, V, B, N, M,
	ALT,
	LSHIFT,
	SPACE,
	ENTER,
	ESC,

	LAST,
};

// 키의 타입을 구별하려면 이전 프레임에 눌렸는지 확인해야함

struct KeyInfo {
	KEY_TYPE	State;
	bool		Prev;
};

class CKeyMgr {
	SINGLE(CKeyMgr);
private:
	vector<KeyInfo> vecKey;

public:
	void Init();
	void Update();

	KEY_TYPE GetKeyState(KEY key) { return vecKey[(int)key].State; }
};

