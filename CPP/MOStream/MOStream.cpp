
#include <stdio.h>
#include "MOStream.h"

MOStream cout("%d");

//MOStream::MOStream()
//{
//	format = "%d";
//}

MOStream::MOStream(const char * f)
{
	format = f;
}



MOStream::~MOStream()
{
}


// 
MOStream & MOStream::operator <<(int n)
{
	::printf(format, n);
	
	return *this;
}

MOStream & MOStream::operator <<(double d)
{
	::printf("%.2lf", d);

	return *this;
}

MOStream & MOStream::operator <<(char c)
{
	::printf("%c", c);

	return *this;
}

MOStream & MOStream::operator <<(const char * str)
{
	::printf("%s", str);

	return *this;
}

MOStream & MOStream::operator <<(const void * addr)
{
	::printf("%#x", addr);

	return *this;
}

MOStream & MOStream::operator <<(ftype t)
{
	// const 꼭 적어줘야 함! RT 때 혹시나 값이 바뀌게 된다면 RTE 뜸
	const char * fftype[] = { "%#o", "%d", "%#x" };

	if (t == endl)
	{
		::printf("\n");
		::fflush(stdout);
	}
	else format = fftype[t];

	return *this;
}

