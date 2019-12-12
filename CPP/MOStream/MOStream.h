#pragma once
#ifndef _MOSTREAM_H_
#define _MOSTREAM_H_

//    0    1    2    3
enum ftype { oct, dec, hex, endl };	// ��ġ �߿�!

class MOStream
{
	const char * format;
public:
	MOStream() = delete;					// ������ �Լ��� ����!! =>  �Ժη� Object �������� �� �ϵ���!
	MOStream(const MOStream &) = delete;	// ���� �����ڵ� ������ ����ߵ�!!
	MOStream(const char * f);
	~MOStream();
	MOStream & operator <<(int n);
	MOStream & operator <<(double d);
	MOStream & operator <<(char c);
	MOStream & operator <<(const char * str);
	MOStream & operator <<(const void * addr);
	MOStream & operator <<(ftype t);
};

extern MOStream cout;


#endif // _MOSTREAM_H_
