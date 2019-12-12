#ifndef _CONSOLE_H_
#define _CONSOLE_H_

#include <windows.h>
#include <conio.h>

#define F1 		0x3B00
#define F2		0x3C00
#define F3 		0x3D00
#define F4 		0x3E00
#define F10 	0x4400
#define LEFT 	0x4B00
#define RIGHT 	0x4D00
#define UP 		0x4800
#define DOWN 	0x5000
#define PGUP 	0x4900
#define PGDN 	0x5100
#define HOME 	0x4700
#define END 	0x4F00
#define ENTER 	0x000D
#define BKSP	0x0008 
#define ESC 	0x001B
#define SPACE 	0x0020
#define ALTX 	0x78E0

union KEY {
	short code;
	struct {
		char ascii;
		char scan;
	};
};

#define HitKbd() _kbhit()  // conio.h

KEY GetKey(void);
int InputInt(int x, int y, int * data);
int InputString(int x, int y, char * data, size_t size);


/* Color Value
7   6   5   4   3   2   1   0  // Bit
b   B   B   B   F   F   F   F  // Attribute
 
In this 8-bit parameter,
 - FFFF = 4-bit Foreground color (0 to 15)
 - BBB  = 3-bit Background color (0 to 7)
 -  b    = Blink(DOS) or Bright enable bit
*/

#define BLACK		0X00
#define DBLUE 		0X01
#define DGREEN 		0X02
#define DCYAN		0X03
#define DRED		0X04
#define DMAGENTA	0X05
#define DYELLOW		0X06
#define DWHITE		0X07
#define GRAY		0X08
#define BLUE		0X09
#define GREEN		0X0A
#define CYAN		0X0B
#define RED			0X0C
#define MAGENTA		0X0D
#define YELLOW		0X0E
#define WHITE		0X0F

void Cls(void);
void SetDefColor(void);
void SetTextColor(int bgcolor, int textcolor);
void GotoXY(int x, int y);
void WriteChar(int x, int y, char c, int color);
size_t WriteString(int x, int y, const char * str, int color);
size_t WriteInt(int x, int y, int data, int color);
void Paint(int left, int top, int right, int bottom, int color);
void Box(int left, int top, int right, int bottom, int style, int color);

#endif // _CONSOLE_H_


