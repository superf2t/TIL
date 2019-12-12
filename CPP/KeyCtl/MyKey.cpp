#include "MyKey.h"
#include "Console.H"


MyKey::MyKey()	// 기본 생성자
{
	x = 40, y = 12;
	ch = 'Y';
	color = YELLOW;
	::WriteChar(x, y, ch, color);
}


MyKey::~MyKey()
{
}


void MyKey::OnLeftDown(void)
{
	::WriteChar(x, y, ' ', color);
	if (x <= 0) x = 79;
	else x--;
	::WriteChar(x, y, ch, color);
}

void MyKey::OnRightDown(void)
{
	::WriteChar(x, y, ' ', color);
	if (x >= 79) x = 0;
	else x++;
	::WriteChar(x, y, ch, color);
}

void MyKey::OnUpDown(void)
{
	::WriteChar(x, y, ' ', color);
	if (y <= 0) y = 24;
	else y--;
	::WriteChar(x, y, ch, color);
}

void MyKey::OnDownDown(void)
{
	::WriteChar(x, y, ' ', color);
	if (y >= 24) y = 0;
	else y++;
	::WriteChar(x, y, ch, color);
}

BOOL MyKey::OnALTXDown(void)
{
	int res;

	res = ::MessageBox(::GetConsoleWindow(), L"종료할까요?", L"종료", MB_YESNO);
	if (res == IDOK) return KeyCtl::OnALTXDown();
	return FALSE;
}