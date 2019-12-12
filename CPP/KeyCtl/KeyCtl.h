#ifndef _KEYCTL_H_
#define _KEYCTL_H_

#include "Console.H"

class KeyCtl{
public:
	KeyCtl();
	~KeyCtl();
	void KeyProc(void);
	virtual void DefaultProc(short code);
	virtual void ASyncProc(void);
	virtual void OnLeftDown(void);
	virtual void OnRightDown(void);
	virtual void OnUpDown(void);
	virtual void OnDownDown(void);
	virtual void OnPgUpDown(void);
	virtual void OnPgDnDown(void);
	virtual void OnEnterDown(void);
	virtual void OnESCDown(void);
	virtual void OnSpaceDown(void);
	virtual BOOL OnALTXDown(void);
};

#endif // _KEYCTL_H_