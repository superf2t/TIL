#pragma once
#include "KeyCtl.h"
class MyKey :
	public KeyCtl
{
	int x, y;		// 원하는 좌표점에
	char ch;		// 원하는 문자를
	int color;		// 원하는 색깔로 뿌려주겠다!
public:
	MyKey();
	~MyKey();
	void OnLeftDown(void);
	void OnRightDown(void);
	void OnUpDown(void);
	void OnDownDown(void);
	BOOL OnALTXDown(void);

};

