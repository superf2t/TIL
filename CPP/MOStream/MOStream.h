#pragma once
#ifndef _MOSTREAM_H_
#define _MOSTREAM_H_

//    0    1    2    3
enum ftype { oct, dec, hex, endl };	// 위치 중요!

class MOStream
{
	const char * format;
public:
	MOStream() = delete;					// 지원질 함수로 만듬!! =>  함부로 Object 생성하지 못 하도록!
	MOStream(const MOStream &) = delete;	// 복사 생성자도 삭제를 해줘야됨!!
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
