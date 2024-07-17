#include "pch.h"

#define SINGLE(type) public:\
					static type* Instance()\
					{\
					static type mgr;\
					return &mgr;\
					}\
					private:\
					type();\
					~type();

#define fDT CTimeMgr::Instance()->GetfDT()
#define DT CTimeMgr::Instance()->GetDT()

enum class GROUP_TYPE {
	DEFAULT,
	PLAYER,
	MISSILE,
	MONSTER,

	END = 32,
};

enum class SCENE_TYPE {
	TOOL,
	START,
	STAGE_01,
	STAGE_02,

	END,
};