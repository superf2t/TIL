// cout을 정의해보자!
#include "MOStream.h"

void sub(int);
void sub(double) = delete;	// 

void main(void)
{
	char ch;
	int nn;
	double dd;

	cout << 5 << 'A' << 3.14 << "seoul" << (void *)&ch << &nn << &dd << endl;
	cout << hex << 10 << endl;
	cout << oct << 10 << endl;
	cout << dec << 0x11 << endl;

	//MOStream b;		// 이러면 안 만들어짐.
	MOStream c(0);	// 이래야 만들어짐.


	sub(5);
	sub('A');
	//sub(3.14);

}


void sub(int n)
{
	cout << n << endl;
}