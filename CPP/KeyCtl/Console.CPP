#include <stdio.h>
#include <iostream>
using namespace std;
#include "Console.H"

KEY GetKey(void)
{
	KEY key;

	key.code = _getch();
	if (key.ascii == 0 || key.ascii & 0x80) {
		key.code = _getch();
		key.code <<= 8;
	}
	else {
		if (GetAsyncKeyState(VK_LMENU) & 0x8000) { // ALT Virtual key code 
			key.scan = key.ascii;
			key.ascii = (char)0xE0; // division value of ALT Key 
		}
	}
	return key;
}

int InputInt(int x, int y, int * data)
{
	KEY key;
	char buffer[20];
	int n;

	n = 0;
	GotoXY(x, y);
	while (1) {
		key = GetKey();
		if (key.ascii != 0) {
			switch (key.ascii) {
			case ESC:
				buffer[0] = '\0';
				return 0;
			case ENTER:
				buffer[n] = '\0';
				*data = atoi(buffer);
				return 1;
			case BKSP:
				if (n > 0) {
					n--;
					WriteChar(--x, y, ' ', 0x07);
					GotoXY(x, y);
				}
				break;
			default:
				if (key.ascii >= '0' && key.ascii <= '9') {
					if (n < 19) {
						WriteChar(x++, y, key.ascii, 0x07);
						buffer[n] = key.ascii;
						n++;
					}
				}
			}
		}
	}
}

int InputString(int x, int y, char * data, size_t size)
{
	KEY key;
	size_t n;

	n = 0;
	GotoXY(x, y);
	while (1) {
		key = GetKey();
		if (key.ascii != 0) {
			switch (key.ascii) {
			case ESC:
				data[0] = '\0';
				return 0;
			case ENTER:
				data[n] = '\0';
				return 1;
			case BKSP:
				if (n > 0) {
					n--;
					WriteChar(--x, y, ' ', 0x07);
					GotoXY(x, y);
				}
				break;
			default:
				if (n < size - 1) {
					WriteChar(x++, y, key.ascii, 0x07);
					data[n] = key.ascii;
					n++;
				}
			}
		}
	}
}

void Cls(void)
{
	system("cls");
}

void SetDefColor(void)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (BLACK << 4) | DWHITE);
}

void SetTextColor(int bgcolor, int textcolor)
{
	textcolor &= 0xF;
	bgcolor &= 0xF;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (bgcolor << 4 | textcolor));
}

void GotoXY(int x, int y)
{
	COORD Pos = {(short)x, (short)y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void WriteChar(int x, int y, char c, int color)
{
	GotoXY(x, y);
	SetTextColor((color & 0xF0) >> 4, color);
	cout << c;
}

size_t WriteString(int x, int y, const char * str, int color)
{
	size_t cnt = 0;
	while(*str){
		WriteChar(x++, y, *str++, color);
		cnt++;
	}
	return cnt;
}

size_t WriteInt(int x, int y, int data, int color)
{
	char temp[20]; 
	sprintf_s(temp, 20, "%d", data);
	return WriteString(x, y, temp, color);
}

void Paint(int left, int top, int right, int bottom, int color)
{
	int x, y;
	for(y = top; y <= bottom; y++){
		for(x = left; x <= right; x++){
			WriteChar(x, y, ' ', color << 4);
		}
	}
}

void Box(int left, int top, int right, int bottom, int style, int color)
{
	int x, y;
	int line[2][6] = {
		{218, 191, 192, 217, 196, 179},
		{201, 187, 200, 188, 205, 186}
	};
	if(!(style >= 1 && style <= 2)) style = 1;
	style--;
	WriteChar(left, top, line[style][0], color);
	WriteChar(right, top, line[style][1], color);
	WriteChar(left, bottom, line[style][2], color);
	WriteChar(right, bottom, line[style][3], color);
	for(y = top + 1; y < bottom; y++){
		WriteChar(left, y, line[style][5], color);
		WriteChar(right, y, line[style][5], color);
	}
	for(x = left + 1; x < right; x++){
		WriteChar(x, top, line[style][4], color);
		WriteChar(x, bottom, line[style][4], color);
	}
}
