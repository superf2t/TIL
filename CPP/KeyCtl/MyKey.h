#pragma once
#include "KeyCtl.h"
class MyKey :
	public KeyCtl
{
	int x, y;		// ���ϴ� ��ǥ����
	char ch;		// ���ϴ� ���ڸ�
	int color;		// ���ϴ� ����� �ѷ��ְڴ�!
public:
	MyKey();
	~MyKey();
	void OnLeftDown(void);
	void OnRightDown(void);
	void OnUpDown(void);
	void OnDownDown(void);
	BOOL OnALTXDown(void);

};

