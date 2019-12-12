#include <iostream>
using namespace std;
#include "KeyCtl.h"

KeyCtl::KeyCtl()
{
}

KeyCtl::~KeyCtl()
{
}

void KeyCtl::KeyProc(void)
{
	KEY key;
	while(1){
		if(::HitKbd()){ // sync code
			key = ::GetKey();
			switch(key.code){
			case LEFT: OnLeftDown(); break;
			case RIGHT: OnRightDown(); break;
			case UP: OnUpDown(); break;
			case DOWN: OnDownDown(); break;
			case PGUP: OnPgUpDown(); break;
			case PGDN: OnPgDnDown(); break;
			case SPACE: OnSpaceDown(); break;
			case ESC: OnESCDown(); break;
			case ENTER: OnEnterDown(); break;
			case ALTX: 
				if(TRUE == OnALTXDown()) goto FIN;
				else break;
			default: DefaultProc(key.code); break;
			}
		}
		else{ // async code
			ASyncProc();
		}
	}
FIN:;
	GotoXY(1, 24);
	SetDefColor();
}

void KeyCtl::DefaultProc(short code)
{
	// Basic Code
}

void KeyCtl::ASyncProc(void)
{
	// Basic Code
}

void KeyCtl::OnLeftDown(void)	// øﬁ¬  πÊ«‚≈∞ ¥≠∑∂¿ª ∂ß
{
	// Basic Code
}

void KeyCtl::OnRightDown(void)
{
	// Basic Code
}

void KeyCtl::OnUpDown(void)
{
	// Basic Code
}

void KeyCtl::OnDownDown(void)
{
	// Basic Code
}

void KeyCtl::OnPgUpDown(void)
{
	// Basic Code
}

void KeyCtl::OnPgDnDown(void)
{
	// Basic Code
}

BOOL KeyCtl::OnALTXDown(void)
{
	// Basic Code
	return TRUE;
}

void KeyCtl::OnEnterDown(void)
{
	// Basic Code
}

void KeyCtl::OnESCDown(void)
{
	// Basic Code
}

void KeyCtl::OnSpaceDown(void)
{
	// Basic Code
}






