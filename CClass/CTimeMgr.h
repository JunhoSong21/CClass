#pragma once

class CTimeMgr {
	SINGLE(CTimeMgr);
private:
	LARGE_INTEGER	curCount;	// ���� �ð�
	LARGE_INTEGER	prevCount;	// ���� �ð�
	LARGE_INTEGER	preQuency;	// ���� ī���Ͱ� �ʴ� �� �� ����Ǿ��°� ����

	double			dDT;		// �� ������ ������ �ð� �� > (����ð� - �����ð�)/�ý��� ���� ī������ ���ļ�
	double			dAcc;		// ���� ��� �ð�
	UINT			iCallCount; // Update�� �Լ� ȣ�� ��
	UINT			iFPS;		// ������ �ӵ� : 1�ʴ� Update ȣ�� ��

public:
	void			Init();
	void			Update();
	void			Render();
	double			GetDT() { return dDT; }
	float			GetfDT() { return (float)dDT; }
};