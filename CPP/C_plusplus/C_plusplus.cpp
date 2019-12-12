#pragma warning (disable: 4996)

/***********************************************************************/
/*							[ 2019.09.30 �� ]						   */
/***********************************************************************/

// C++������ ����ü Ȱ��� C���� ������
#if 0
#include <stdio.h>

/* ������ ���캸��, ����ü�� ������ �Լ��� �ǹ̰� ����, �Լ��� ������ ����ü�� ���� �аų� �� �� ����.
��, ���� ����� �Ұ����� �����̴�.
=> �׷� ���� ��� ������ ���� ������? �׷��ٸ� ���뿡 �������� ������?
=> C++�� ������ �Լ��� ����ü �ȿ� �� �� �ֵ��� �ߴ�! */

struct st
{
private:	// �ַ� member ����/�����͵��� private ���� ������, �Լ����� public ���� ������ �� (�������� ���ԡ�)
	int no;
	char ch;

public:
	// ���� ��ƿ��� ���� �Լ�
	void InitStruct(int n, char c)
	{
		if (!(n & 1)) n++;	// no�� �׻� ¦���� �ƴ� Ȧ���� �ǵ��� ����� �;!!
		no = n;
		ch = c;
	}
	// ����  ���б�� ���� �Լ� -> const�� ���� ��(���ȭ ������! ��, �ٲ��� ����. ������ C�� const�� ������ ���ȭ�� �������� ���Ѵٰ� ��!)
	// ������ ���ο� �дٸ�, �̷��� ���! �������� ������.
	void PrintStruct(void) const	// ��const struct st * p�� ���ڷ� ��� �������� ������ �� ����. �̷��� ǥ�������ν� �˷���!!
	{
		printf("You can read struct st type variable thanks to me! : ");
		printf("%d, %c\n", no, ch);
	}
};
// �̷��� ����ü ���� �ִ� �Լ��� "���� �Լ�"��� �ϰ�, �� �ۿ� �ִ� �Լ����� "���� �Լ�"��� ��!
// �׷��� C++ ���忡�� C�� ��� �Լ��� �����Լ���!
// �������Լ��� �̸����θ� ȣ����� �ʰ�, �ڽ��� ȣ�����ִ� ��ü�� �־�� ��! (�� ���ÿ����� aa) => OBJECT�� ���� ȣ���!!!!!
// ����ü ���� ���ԵǾ� �ֱ� ������ Call by Addr�� ���� �μ��� struct st * p�� �� �ʿ䵵 ����, p->no�� ������ �ʿ� ����

void main(void)
{
	/*struct*/ st aa;
	/* ��C++������ st ��ü�� �ĺ��ڰ� �ƴ϶�, ������ Ÿ���̴�!!
	   (C����� �⺻���� int, C�� ���� �����ڵ��� ������ ���ؼ��� ���������� �ٸ� ������ Ÿ�Կ��� ������ �� ���ٴ� ���⼺�� ����...
	   C++(��ü����)������ ��� ������ Ÿ���� ������ó�� ����� �־ ���� ���̺귯���� �Լ��� �� ������ �� �ֵ���,.,,(?)) */
	
	// aa.no = 4; => �̰� Ǯ��� no�� ������ �׾��� ����. ����ü ���� ������ private�̱� ������ �Ժη� ������ �� ����

	aa.InitStruct(5, 'A');	// �ڱ���ü ���� �ִ� �Լ��̹Ƿ� aa.�� ���� ȣ���ؾ� ��!��
	aa.PrintStruct();
}
#endif


// cout
#if 0
#include <iostream>
#include <iomanip>
using namespace std;		// cout�� ����ϱ� ���� �� �ʿ��� ��!!

void main(void)
{
	cout << "kia~";
	cout << 10 << " " << 3.14 << 'A' << endl;
	cout << hex << 20 << endl;	// endl�� endline���ν� ���๮�ڿ� ���� ����� ��!
			// oct(8), dec(10), hex(16) ������!
	
	int no = 10;

	cout << "hello world." << endl; // printf(��hello world.\n��);
	cout << no << endl;
	cout << hex << 10 << endl; // oct, dec
	cout << left << setw(10) << "seoul" << "KOREA" << endl;
	cout << fixed << setprecision(2) << 3.141592653589793238 << endl;
}
#endif



// cin
#if 0
#include <iostream>
using namespace std;		// cout�� ����ϱ� ���� �� �ʿ��� ��!!

void main(void)
{
	int num;
	cout << "Input Decimal : ";
	cin >> num; // scanf("%d", &num); // call by address
	cout << "Hexa : " << hex << num << endl;
	cout << 30 << endl;	/* �굵 Hexa�� ����.. �ٵ� �� �׷���? cout�� iostream �������� ������ �Ǿ� ����!!
						   �׷��� �ٷ� ���� cout�� ���� �ֶ�� ���� ��!! ������ ���� �ٸ����� ���� object! */
	cout << dec << 30 << endl; // �̷��� �ٽ� ������ ����� Decimal ���� �����!


	const int n = 5;	// => �������� Ÿ�ӿ� ����� �ν��� �ȴٰ� ��!! (in C++)
	int ARR[n];		// �̰� �����ϴٴ�!!!����

	int age;
	char name[30], addr[30];
	cout << "What's your name? : ";
	cin >> name;
	cout << "How old are you? : ";
	cin >> age;	// scanf("%d", &age);�� �ٸ��� &���� �ƴϳ�!!!
	cout << "What's your address? : ";
	//cin >> addr;
	
	// �갡 ���ٸ�, cin.getline�� ���� age�� �Է��� �� ģ ���๮��(enter)�� �ް� ��!! �׷��� ���۸� ����־�� ��!
	cin.ignore();  // fflush(stdin); ��� ���� ����!!
	cin.getline(addr, 30);	// �ִ� 29�ڱ��� �Է��� ���� (�ڹ��� �˻縦 �ϸ鼭!!! && �ڰ���/���鵵 ���� �� �־�!!)
	// gets(addr);�� ���ϱ�� ������, ���� �˻縦 ������ ����!
	// scanf("%s", addr); ���� ���� ����ϱ� ������, ������ ���� �� ����


	cout << name << " " << age << " " << addr << endl;	
}
#endif


// ���� ����
#if 0
#include <iostream>
using namespace std;		// cout�� ����ϱ� ���� �� �ʿ��� ��!!

int sub(int r) // int r = 5; // int r(5); // �μ����� ���� == ����� ���ÿ� �ʱ�ȭ (ʦ)
{
	int imsi;

	return imsi = r * 2; // int imsi = r; // int imsi(r); // ���� ���� == ����� ���ÿ� �ʱ�ȭ (ʦ)
}


void main(void)
{
	int m;
	cout << sub(m = 5) << endl;
	cout << sub(int(5)) << endl;

	int array[] = { 10, 20, 30, 40 };
	for (int n : array) // �迭�� 0��° ��Һ��� ���������� ��ȸ�ϴ� for��(�� ��ġ���� ���� ���� ����)
	{
		cout << n << endl;
	}


	const char * names[3] = { "kim", "park", "lee" };
	for (const char * irum : names)
	{
		cout << irum << endl;
	}

}
#endif



// Scope ������ - 1
#if 0
#include <iostream>

struct st
{
private:
	int no;
	char ch;

public:
	void InitStruct(int n, char c);
	void PrintStruct(void) const;
};

void st:: InitStruct(int n, char c)
{
	if (!(n & 1)) n++;
	no = n;
	ch = c;
}

void st::PrintStruct(void) const	// �� const�� ���� �Ĺ���� '��, ��� �б⸸ �ϴ� �Լ�����!' ��� �� �� ����
{
	printf("You can read struct st type variable thanks to me! : ");
	printf("%d, %c\n", no, ch);
}
// ���� ����ü �ȿ��� �Լ��� ���� ���ְ�, �̷��� �Լ��� ���Ǵ� ������ ���� ��찡 ����!
// �ʳ� �Ĺ���� �� �� �ֵ��� st::��� �ڼҼ��� ������(scope�� ������!)��

void main(void)
{
	
}
#endif

// Scope ������ - 2
#if 0
#include <iostream>
#include <iomanip>
using namespace std;

int no = 10;

void main(void)
{
	int no = 5; // ����� ���ÿ� �ʱ�ȭ
	cout << no << endl;		// ���������� ������ �켱��
	cout << ::no << endl;	// ���������� "����"�� �켱�� (�Լ��� ��� ���� ���� �ִ� ��!) => scope�� �ٿ� �������� �˷���!
							// �Ӹ� �ƴ϶� �������� ���� �˷��ֱ� ���ؼ� ���� �̸��� ������ ::(scope)�� ���̴� ��쵵 ����.
	/* �������� ������ ������ �����ؾ� �ϴ� ���� ����. Ư�� �Լ�����!!
	   ���ſ� �ڽ��� ������� ���̺귯�� �Լ��� �׷� ���� ������ �ϳ�? �ƴϴ�!!
	   cpp�� ���ٰ� ������ C�ڵ带 ������ ���� ���� �ȵ�. Ư�� ������ ���ο� �� cpp�ݾ�? */
}
#endif



// ����� const : C�� �ٸ� ���� ����!
#if 0
/*
// ����� const in C
#if 0
#include <stdio.h>

void main(void)
{
	//const int n;	// const�� ��ٴ� ���� ������ ���̰�, �׷� const int n = 5�� ���� ���� �������־�� ��!
	//char str[n];	// �׷��� ������ n�� ��� ũ��� �� �� ����!!!

	//const int n = 5;
	//n = 10;		// ���� �� ��

	const int n = 5;
	int * p = &n;
	*p = 10;
	printf("%d\n", n);	// 10���� �ٲ� ��µ�. �����Ϸ��� const�ӿ��� ����� �ν������� ���ϴ� ��!(�׷� �ȵǴµ�)
	// => ��, C������ const�� �Ϻ��� ���ȭ�� �������� ���ߴٴ� �Ѱ谡 ����!!!
}
#endif
*/


// ����� const : C�� �ٸ� ���� ����!
#include <iostream>
#include <iomanip>
using namespace std;

void main(void)
{
	// volatile: �����Ϸ��� �������� �� ����ȭ �� ��ó���� �ϴµ� �װ��� �� �ϰ� ���ִ� ��.
	// volatile const int n = 5; ��� ������ ���شٸ�, ������ ��� �κ��� �޶��� ��! (10, 10���� ��µ�!)

	const int n = 5;
	//char str[n];	// �������� �ð��� n�� ������� 5(const)��� ���� �����Ƿ� �̷��� ���� ����!!
	//int *p = &n;	// ��n�� �������� �ڷ����� const int *�̹Ƿ� Ÿ���� �޶� ������ ��!!!��

	//const int *p = &n; // ���� �� ��� ������ ���� ����.
	//*p = 10;			// �������� �ٲ� �� ���� ��� ���� �ٲٷ��� �ϴ� ���ٿ��� ������ ��!!

	int *p = (int *)&n;
	*p = 10;			
	cout << n << endl;	// n�� const�̹Ƿ� �ٲ��� ����. n�� �ٲ��� �ʰ� 5�� ���
	cout << *p << endl;	// p�� n�� ĳ�����ؼ� "�ٲٰ�� �� ���̴�!" ��� ������ �־���. *p�� �ٲ�� 10���� ���
}
// => �ڡ� ������ ����� �� ����� const�� ��! ��! ���������!!!
#endif

#if 0
#include <iostream>
#include <iomanip>
using namespace std;

void main(void)
{
	int n = 5, k = 6;

	// ���� �ٸ� ǥ��!!
	const int * p;	// p�� ����Ű�� ����� *p�� const, �� ����� ���ڴٴ� ��! �� ����� ����� �ƴϴ���

	//int * const q;	// q ��ü�� const, �� ����� ���ڴٴ� �� -> �׷��� ������ q�� ���� ���� �����Ƿ� ������ ��.
	int * const q = &k;	// -> �׷��� �̷��� ����� ���ÿ� �ʱ�ȭ�� ���־�� ��!
	// �׷��� q�� ����Ű�� ����� ������?
	const int * const r = &k; // -> �̿� ���� ������ ���־�� ��;;

	p = &n;
	// *p = 10;		=> �̹� ������ p�� ����Ű�� ����� const�� ���ְڴٰ� �߱� ������ �� ���� �Ұ�. n = 10;�� ���� n ��ü������ �� �ٲٴ� ���� ���ɤ�
	cout << *p << endl;

	*q = 100;		// q ��ü�� const������, q�� ����Ű�� ����� const�� ���� �ƴ�!!
	//q = &n;		=> �׷��� ��� ������ ��!	
	cout << *q << endl;

	sub(&p);
	func(&q);
}

// t : ���� ������ ������(t �ٷ� �տ� �ִ� *, �� t�� �ּҰ��̶�� ��!). �׷��� ���� ����Ű�� ���� int * const ��!
void func(int * const *t)		// ������ Ÿ�Կ� �ָ��
{

}

// t : ���� ������ ������(t �ٷ� �տ� �ִ� *, �� t�� �ּҰ��̶�� ��!). �׷��� ���� ����Ű�� ���� const int ��!
void sub(const int * *t)		// ������ Ÿ�Կ� �ָ��
{

}
/*
< �� ���� !! �� >
const int * onlyread; // �б⸸ �Ұž�
int * const onlyyou = &data; // ���� data�� ����ų�ž�, �� ������ �ʾ�.
int const * icp = &cdata; // ����Ű�� �����ʹ� const int(int const)���̾�
const int * const readonlyyou = &data; // data���� ����Ű�� �� ����� �б⸸ �Ұž�.
*/
#endif

// ���� ���� (�Լ��� return Ÿ���� const? : ������ �Ǹ鼭 ���� ���ϴ� ���� ���� ����)
#if 0
#include <iostream>
using namespace std;

int * sub(void);

void main(void)
{
	// *sub();	// *(���� n�� �ּ�) => ���ϵǴ� ������ �ּ��� ��!?
				// => n�� ���� �����̰�, �Լ��� ����Ǹ鼭 Stack�� �ִ� �͵��� �ٽ� ��ȯ��. �׷��� ������ ����!!
	cout << *sub() << endl;	// �Ʒ��� ���� ���, �ּҰ� ����Ű�� ���� ���� �� �ְ� ��!!
}

/*int * sub(void)
{
	int n = 5;

	return &n;
}*/
int * sub(void)
{
	static int n = 5;
	cout << n << endl;
	return &n;
}
/*
const int * sub(void)
{
	static int n = 5;
	cout << n << endl;
	return &n;
}
*/					// => �̿� ���� ���, ���� Ÿ���� const�̹Ƿ� �б⸸ �� �� �ְ�, ������ ����ų �� ����..(?)
// �ڡ� return Ÿ���� const�� ���, ������ �Ǹ鼭 ���� ���ϴ� ���� ���� ����!! �ڡ�
#endif



// �ڡ� �����ε� : �Լ��� �ߺ� ���� �ڡ�
#if 0
#include <iostream>
#include <stdlib.h>	// ���� �Ҵ��� ����!
using namespace std;

void Swap(int * p, int * q);
void Swap(double * p, double * q);
void Swap(void *p, void *q, size_t size);
void Memcpy(void * p, const void * q, size_t cnt);

void main(void)
{
	int n = 5, k = 6;
	double d1 = 3.14, d2 = 2.54;

	//Swap(&n, &k);
	//Swap(&d1, &d2);
	Swap(&n, &k);
	Swap(&d1, &d2, sizeof(double));

	cout << n << " " << k << endl;
	cout << d1 << " " << d2 << endl;
}


void Swap(int * p, int * q)
{
	int tmp;

	tmp = *p;
	*p = *q;
	*q = tmp;
}

void Swap(double * p, double * q)	// �Ķ������ Ÿ���� �ٸ��Ƿ� �����ε� ����!!
{
	double tmp;

	tmp = *p;
	*p = *q;
	*q = tmp;
}


//  �ڡ�
void Swap(void *a, void *b, size_t size)	// size_t�� unsigned int Ÿ����
{
	void * tmp = malloc(size);	// ������ size�� runtime �� ��� ��. �׷��� ������ ���� �Ҵ��� ���� �޸𸮸� ������ ��!
	if ( tmp == (void *)0x0 ) return;

	Memcpy(tmp, a, size);
	Memcpy(a, b, size);
	Memcpy(b, tmp, size);
	
	free(tmp);	// free ���ϸ� �޸� ���� �� ����
// cf> �ֱ� ��� ������ free�� ���� ������ �ʾƵ� �˾Ƽ� ���ִ� ����Ʈ ������(C++), ������ �÷���(JAVA) ���� ��� ����
}

void Memcpy(void * p, const void * q, size_t cnt)	// �� const�� ���ٱ�? : �о��ֱ� ���� �����̱� ����!!
{
	char * dest = (char *)p;
	const char * src = (char *)q;

	for ( ;cnt > 0; cnt--) *dest++ = *src++;
}
//  �ڡ�
#endif

// �ߺ�����(�̾)
#if 0
#include <iostream>

struct stream
{
	void printf(int);
	void printf(char);
	void printf(double);
	void printf(const char *);
};

void stream::printf(int n)
{
	::printf("%d\n", n);
}

void stream::printf(char c)
{
	::printf("%c\n", c);
}

void stream::printf(double d)
{
	::printf("%lf\n", d);
}

void stream::printf(const char * str)
{
	::printf("%s\n", str);
}

void main(void)
{
	stream c;		// �� ����, coutó�� ������ �������� Ÿ�Կ� �°� �˾Ƽ� ����� ���ִ� ���� �� �� ����!
					// ostream�� �̷��� ���ǰ� �Ǿ� ���� ���̶�� ���� �� �� �ִ�!
					// Ư�� ���� �̸��ε� �ٸ� Ÿ�Ե鿡 �� ���(?)�� �Ǿ� �ִ� ���� ���� �ߺ����ǰ� �Ǿ� ���� ��!!
	c.printf(5);
	c.printf(3.14);
	c.printf("seoul");
}

#endif



// ����Ʈ �Ķ����
#if 0
#include <time.h>
#include <iostream>
using namespace std;

void DisplayDate(int day, int month = 12, int year = 2019);	// �Լ� ���� �� ����Ʈ �Ķ���͸� �������־�� ��!
void DisplayDate(void);	// �̷� �Ŵ� �ߺ����� �Ұ���!!

void main(void)
{
	DisplayDate(30);			// 2019/12/30
	DisplayDate(30, 9);			// 2019/9/30
	DisplayDate(30, 9, 2018);	// 2018/9/30

	DisplayDate();
}

void DisplayDate(int day, int month, int year)	// �ڵ���Ʈ �Ķ���� ���� �����ʿ�������! ����Ʈ �Ķ���ʹ� �Լ� ���� �� ����!��
{												// Argument pass order�� �����ʿ������� �������� ���� ����! (C�� �Ȱ���!)
	cout << year << "/" << month << "/" << day << endl;
}

void DisplayDate(void)
{
	time_t lt;
	tm *ct;
	tm tct;		// tm�� �������� ��� ����ü Ÿ����!

	time(&lt);	// time ���� Ŀ���� �÷� ������ "time_t __cdecl(time_t * Time)" �̶�� ��. ��, ���ڷ� time_t *�� ���� ��!
	
	ct = localtime(&lt);	// ���� �������� lt
	DisplayDate(ct->tm_mday, ct->tm_mon, ct->tm_year + 1900);	// ���� ��¥ ����ϴ� �Լ�!

	localtime_s(&tct, &lt);	// ���� ���� ����!
	DisplayDate(tct.tm_mday, tct.tm_mon, tct.tm_year + 1900);	// ���� ��¥ ����ϴ� �Լ�!
	// �� �� DisplayDate �Լ��� �ٷ� ���� ������ void DisplayDate(int day, int month, int year)��!!
}
#endif



// �ڡ� Reference ----- Union�̶� ��� : ���� ������ �ٸ� �̸����� �θ�! (����) �ڡ�
// ������ ���� ���� ������ �־�� ��! by using &
#if 0
#include <iostream>
using namespace std;

void subv(int k);
void subp(int * t);
void subr(int & r);
int vsub(int n);
int * psub(int n);
int & rsub(int & r);

void main(void)
{
	int n = 5;
	int & rn = n;	// �� ����(&)�� �ڷ���(l-value)�� �� �� ����!! ��, �� &�� ������ &!!!

	cout << rn << endl;
	rn = 10;
	cout << rn << endl;
	cout << &n << " " << &rn << endl;	// ���� �ּ� ���� ���� ��! �� �ٸ� ������ �Ҵ�Ǵ� ���� �ƴϱ� ����!!

	subv(n);
	cout << n << endl;	// (Call by Value) ���� �ٲ��� �ʰ� 10���� �״�� ����!

	subp(&n);
	cout << n << endl;	// (Call by Address) �ּҰ��� ���� ���� -> ���� ��ȭ��! => �׷��� �Է� �޴� �Լ���(scanf, gets, fgets���� �� �ּҰ��� ���ڷ� �޴� ��!!)

	subr(n);			// ��(Call by Reference) ���� ��ȭ��!!!!
	cout << n << endl;
	// ������ �ּҷ� �������� �ʾҴµ� ���� ��ȭ�ǳ�...
	/*
	�ڱ׷��� const�� ����ϰ� �ȴ�!
	Like => void subr(const int & r) => �Լ� ������ "r = ~~"�� ���� r ���� �����ų �� ����!! ���� ���!
	*/

	cout << vsub(n) << endl;	// vsub �Լ��� ���� Ÿ���� int.	// int imsi = n;
	cout << psub(n) << endl;	// psub �Լ� ���� Ÿ���� int *.	// int * insi = &n;
	rsub(n) = 0;												// int & imsi = r;	: imsi�� ���� r�� ����(�� �ٸ� ���� �Ҵ� X!!!!)
	/*
	���� ���������� ���� ��ȭ��Ű�� ���� ������,
	Like => const int & rsub(int & r)�� ���� ���!!!
	*/
	cout << n << endl;
	// �� n�� Reference(����)�� r�� �ٷ� ������ r = 0;���� ���� ����Ǿ���, �׷��� ������ n ���� 0����... ��
}

void subv(int k)	// int k = n;
{
	k = 0;
}

void subp(int * t)	// int * p = &n;
{
	*t = 100;

}

void subr(int & r)	// int & r = n;	=> �Լ� �ȿ��� ���ڷ� ���� n�� r�̶�� �θ��ڴ�!
{
	r = 200;
}

int vsub(int n)
{
	return n;
}

int * psub(int n)
{
	return &n;
}

int & rsub(int & r)
{
	return r;
}
/*
��]
// ������ ����
const char * cstr = "seoul";
char * & rstr = (char * &)cstr;
// *rstr = 'A'; // �б� ���� �޸𸮿� ����ϱ� ������ ��Ÿ�� ���� �߻�
rstr = "korea";
const char * const & rcstr = cstr; // �ٸ� �ּҸ� ���� �ʱ� ���� ����
// rcstr = "KOREA"; // ����Ұ�

��]
// �迭, �迭������, �����͹迭, ���������� ����
char str[] = "seoul";
char (& rstr)[6] = str; // �迭������ ��� ��� ������ ����� ����ϰ� ��ȣ���

char name[][5] = {"kim", "park"}; // 2�����迭
char (& rname)[2][5] = name; // ��� ������ �迭�� ũ�⸦ ����� ��� (�ǹ� : rname�� name�� ����!)
char (* pname)[5] = name; // �迭������
char (* & rpname)[5] = pname; // �迭�������� ����

const char * cname[] = {"kim", "park"};
const char * (& rcname)[2] = cname; // �����͹迭�� ����
const char * * pcname = cname; // ����������
const char * * & rpcname = pcname; // ������������ ����

��]
// �ٸ� ũ��� ����
long data = 0x12345678;
short & k = (short &)data;

short(& word)[2] = ( short(&)[2] ) data;
char (& byte)[4] = ( char(&)[4] ) data;
*/
#endif

// Reference(�̾)
#if 0
#include <iostream>
using namespace std;

void main(void)
{
	long data = 0x12345678;
	// 4����Ʈ
	long & word = data;	// ���� long Ÿ������ ����(&)�Ұž�. word��� �̸�����. ������? data��!!
	// 2����Ʈ
	short & sword = (short &)data;
	short (& asword)[2] = (short (&)[2])data;
	char(&casword)[4] = (char(&)[4])data;

	cout << hex << word << endl;
	cout << hex << sword << endl;	// 0x5678�� ����! ��Ʋ ���������
	cout << hex << asword[1] << endl;
	cout << hex << (int)casword[2] << endl;	// 34�� ����...����
}
#endif



// inline �Լ�
// �� �Լ�ȭ�� ������ ���ο� �� ��!! �̷��� ȣ��Ǿ� ���Ǳ� ���� �Լ��� ����� ��!! ��
/* => ������ �Լ��� ȣ���ϱ� ���� ������ ������ ������ �δ� prefix �ڵ�� �Լ��� ���� ���� suffix �ڵ尡 �ʿ��ϱ� ������
	  �Լ� ȣ�� ��ü�� ����ȭ�� ������ ���� �ƴ�! (������� �߻�)
*/






// �Է� ���� ó��
#if 0
#include <iostream>
using namespace std;

void main(void)
{
	int score;
	char * grade = "FFFFFFDCBAA";

	do
	{
		cout << "������ �Է����ּ���! : ";
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> score;
	} while (cin.fail() || score < 0 || score > 100);
			// ���� �� ó��,  ���� ó��  ,  100�� �ʰ� ó��

	cout << grade[score / 10] << endl;

	/*	// < �� ���� �ڵ� : �����Ͱ� �þ�� ��ŭ �ڵ嵵 ���� �þ�� �Ǵ�... >
	switch (score / 10)
	{
	case 10:
	case 9:
		grade = 'A';
		break;
	case 8:
		grade = 'B';
		break;
	case 7:
		grade = 'C';
		break;
	case 6:
		grade = 'D';
		break;
	default:
		grade = 'F';
		break;
	}
	cout << grade << endl;
	*/
}
#endif




// ���� �޸� ������
// �츮�� ���� malloc�� ����߳�? : �������� ũ�⸦ ������ �ð��� ������ �� ������ ��
// C������ malloc�� �Լ��̰�, C++������ new�� �������̴�!!! (C++������ C����ó�� malloc ��� ����!�� ������ ����� �� ���� ��쵵 �־�..)
// => new�� malloc�� �� �� ���� �ϱ����� �Ѵ�!! �ٵ� �װ� ����!?!?
#if 0
#include <iostream>
#include <stdlib.h>
using namespace std;

void main(void)
{
	int * np = new int;
	int ** npp = new int *;

	cout << *(int *)((char *)np - 16) << endl;
	cout << *(int *)((char *)npp - 16) << endl;

	delete np;
	delete npp;


	int size;
	char * cp = new char;
	char ** cpp = new char *;
	char * acp = new char[13];

	cout << *(int *)(cp - 16) << endl;
	cout << *(int *)((char *)cpp - 16) << endl;

	cout << "Size : ";
	cin >> size;

	cout << *(int *)(acp - 16) << endl;	// 13�� ��µ� ��!!


	delete cp;
	delete cpp;
	delete acp;
}

#endif





// �� ���ڿ� �Է� �޴� ������ŭ + 1 �Ҵ� ��
#if 0
#include <iostream>
#include <string.h>
using namespace std;

void main(void)
{
	char temp[100];
	int len;
	int i;
	int cnt;
	char * * str;

	cout << "Count : ";
	cin >> cnt;

	str = new char *[cnt];

	for (i = 0; i < cnt; i++)
	{
		cout << "String Input : ";
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(temp, 100);	// �ִ� 99�ڱ��� �ް�, �׺��� �ʰ��Ǵ� �κ��� ���õ�!!
		// �갡 cin >> temp;�� ����ѵ�, 100 - 1�ڱ��� �޵��� �Ѵ�!!

		len = strlen(temp);
		str[i] = new char[++len];	// NULL���ڱ��� �����ϱ� ���ؼ�!

		strcpy_s(str[i], len, temp);	// �����Ҵ��̹Ƿ� �μ��� 3�� ��� ��!!
	}

	for (i = 0; i < cnt; i++)	cout << str[i] << endl;

	for (i = 0; i < cnt; i++)	delete [] str[i];	// ��new + �迭�� ���� delete + �迭�� ��ȯ����!1
	
	delete [] str;
}
#endif





// �̸� ���� ����ü
#if 0
#include <iostream>
using namespace std;

/*static union
{
	long data;
	short word;
	char byte;
};*/

void main(void)
{
	union
	{
		long data;
		short word;
		char byte;
	};

	data = 0x12345678;
	cout << hex << word << endl;
	cout << hex << (int)byte << endl;
}

#endif




// �����̸�(namespace)�� ����� using
// ������ �ڵ带 �״�� ������ ����, ���� ���� ���� �̸��� ������ �ڵ��� �̸��� ��ø�Ǵ� ��찡 �־�!
// => �ٸ� ������ �ξ� ��ø�� ����!
#if 0
#include <iostream>
using namespace std;
namespace A{
	int no = 5;
	void sub(void)
	{
		cout << no << endl;
	}
}
namespace B{
	int no = 10;
	void sub(void)
	{
		cout << no << endl;
	}
}
//void sub(void);


int no = 30;

void main(void)
{
	A::sub();

	B::sub();

	//sub();

	using namespace A;
	sub();		// A��� ������ sub��!!

	using namespace B;
	sub();		// ��� ������!! �̹� ���� A ������ ����ϰڴٰ� ������ �߱� ������...
	B::sub();	// �׷��� B�� scope�� ������ ��!!
}

/*
void sub(void)
{
	cout << no << endl;
}*/
#endif

// ����
#if 0
#include <iostream>
#include <iomanip>
using namespace std;

void main(void)
{
					// 10�ڸ�
	cout << left << setw(10) << "Seoul " << 10 << endl;
			// ���� ����

	int left = 5;
	cout << left << setw(10) << "Seoul " << 10 << endl;	// ��� left�� �����̰�, 5�� �ʱ�ȭ �Ǿ� �ձ� ������ 5�� ��� ��

	cout << std::left << setw(10) << "Seoul " << 10 << endl; // ȥ���� ���� ���� scope ����!
}
#endif




// 1.16 C++ ����ü�� �̿��� ���� ���
#if 0
#include <iostream>
#include <time.h>
using namespace std;

#define IsLeap(Y) ((!(Y % 4) && (Y % 100)) || !(Y % 400))


struct Date
{
private:
	int year, month, day, week;
	void CalcDate(void); // ���� ����ϴ� ����Լ�
public:
	void InitDate(void); // ��, ��, �� ������ �ý��ۿ��� �о���� ����Լ�
	void InitDate(int d, int m, int y = 2019); // ��, ��, �� ������ �μ��� ���޹޴� ����Լ�
	void DisplayDate(void); // ��, ��, ��, ���� ����ϴ� ����Լ�
};

static int days[12] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };

void main(void)
{
	Date today;
	today.InitDate();
	today.DisplayDate();

	Date oneday;
	oneday.InitDate(19, 12);
	oneday.DisplayDate();
}

void Date::InitDate(void) // ��, ��, �� ������ �ý��ۿ��� �о���� ����Լ�
{
	time_t lt;
	tm * ct;
	
	time(&lt);
	ct = localtime(&lt);

	year = ct->tm_year + 1900;
	month = ct->tm_mon + 1;
	day = ct->tm_mday;
	week = ct->tm_wday;

	/*
	time_t lt;
	tm cur;

	::time(&lt);				// ���� �Լ� ȣ��
	::localtime_s(&cur, &lt);	// ���� �Լ� ȣ��
	year = cur.tm_year + 1900;
	month = cur.tm_mon + 1;
	day = cur.tm_mday;
	week = cur.tm_wday;			// 0 = �� ~ 6 = ��
	*/
}

void Date::InitDate(int d, int m, int y) // ��, ��, �� ������ �μ��� ���޹޴� ����Լ�
{
	year = y;
	month = m;
	day = d;

	/*
	if (y < 1 || y > 4000) y = 1;
	year = y;
	if (IsLeap(year)) ::days[2] = 29;
	else ::days[2] = 28;
	if (m < 1 || m > 12) m = 1;
	month = m;
	if (d < 1 || d > ::days[month]) d = 1;
	day = d;
	CalcDate();
	*/
}

void Date::CalcDate(void) // ���� ����ϴ� ����Լ�
{
	int y, sum;
	y = year - 1;
	sum = y * 365 + (y / 4) - (y / 100) + (y / 400);
	for (int n = 1; n < month; n++) sum += ::days[n];
	sum += day;
	week = sum % 7;

	/*
	int check = (::days[month - 1] + day) % 7;
	week = check;
	*/
}

void Date::DisplayDate(void) // ��, ��, ��, ���� ����ϴ� ����Լ�
{
	const char * strweek[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	cout << year << '/' << month << '/' << day << '/' << strweek[week] << endl;

	/*
	cout << year << "/" << month << "/" << day;
	cout << " (" << week << ") " << endl;
	*/
}
#endif
// ������
#if 0
#include <time.h>
#include <iostream>
using namespace std;

#define IsLeap(Y) ((!(Y % 4) && (Y % 100)) || !(Y % 400))

struct Date{
private:
	int year, month, day;
	int week;
	void CalcDate(void);
public:
	void InitDate(void);
	void InitDate(int d, int m, int y = 2019);
	void DisplayDate(void);
};

static int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

void Date::InitDate(void)
{
	time_t lt;
	tm cur;

	::time(&lt);
	::localtime_s(&cur, &lt);
	year = cur.tm_year + 1900;
	month = cur.tm_mon + 1;
	day = cur.tm_mday;
	week = cur.tm_wday;
}

void Date::InitDate(int d, int m, int y)
{
	if (y < 1 || y > 4000) y = 1;
	year = y;
	if (IsLeap(year)) ::days[2] = 29;
	else ::days[2] = 28;
	if (m < 1 || m > 12) m = 1;
	month = m;
	if (d < 1 || d > ::days[month]) d = 1;
	day = d;
	CalcDate();
}

void Date::CalcDate(void)
{
	int y, sum;
	y = year - 1;
	sum = y * 365 + (y / 4) - (y / 100) + (y / 400);
	for (int n = 1; n < month; n++) sum += ::days[n];
	sum += day;
	week = sum % 7;
}

void Date::DisplayDate(void)
{
	const char * strweek[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	cout << year << '/' << month << '/' << day << '/' << strweek[week] << endl;
}

int main(void)
{
	Date today;
	today.InitDate();
	today.DisplayDate();

	Date someday;
	someday.InitDate(1, 1, 1);
	someday.DisplayDate();
}
#endif




// 1.17 C++ ����ü�� �̿��� ����ó��
#if 0
#include <iostream>
#include <iomanip>
#define MAX_NAME	(10)
using namespace std;

#define ScoreRng(S) (((S >= 0) && (S <= 100)) ? (S) : (0))

struct Score
{
private:
	char * name; // ���� �Ҵ�
	int  kor, eng, mat;
	int tot;
	double ave;
public:
	void Init_Score(void);
	void InitScore(const char * irum, int k, int e, int m);
	void Clac_Score(void);
	void PrintScore(void);
	void Delete_Score(void);
};

static char *grade = "FFFFFFDCBAA";

void main(void)
{
	int num, n;
	Score * student = (Score *)0x0;

	cout << "Count : ";
	cin >> num;
	student = new Score [num];		// �� ���� ������

	for (n = 0; n < num; n++){
		student[n].Init_Score();
	}

	for (n = 0; n < num; n++){
		student[n].Clac_Score();
	}

	for (n = 0; n < num; n++){
		student[n].Delete_Score();
	}

	/*
	student->Init_Score(student, num);
	student->Clac_Score(student, num);
	*/

	delete student;
}

void Score::Init_Score(void)	// ��
{
	char temp[10];
	size_t len;

	do{
		cout << "Name : ";
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(temp, MAX_NAME);
	} while ( cin.fail() );

	len = ::strlen(temp);
	name = new char[++len];
	::strcpy_s(name, len, temp);

	do{
		cout << "Score(K, E, M):";
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> kor >> eng >> mat;
	} while ( cin.fail() || !ScoreRng(kor) || !ScoreRng(eng) || !ScoreRng(mat) );

	Clac_Score();

	/*
	int i, len;
	char tmp[10];

	for (i = 0; i < n; i++)
	{
		cout << "Name : ";
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(tmp, MAX_NAME);
		len = strlen(tmp);
		S[i].name = new char[++len];	// NULL���ڱ��� �����ϱ� ���ؼ�!
		strcpy_s(S[i].name, len, tmp);

		cout << "Score : ";
		cin >> S[i].kor >> S[i].eng >> S[i].mat;

		S[i].tot = S[i].kor + S[i].eng + S[i].mat;
		S[i].ave = (1.0) * S[i].tot / 3;
	}
	*/
}

void Score::InitScore(const char * irum, int k, int e, int m)
{
	size_t len;

	len = ::strlen(irum);
	name = new char[len + 1];
	::strcpy_s(name, len + 1, irum);
	kor = ScoreRng(k), eng = ScoreRng(e), mat = ScoreRng(m);

	Clac_Score();
}

void Score::Clac_Score(void)
{
	tot = kor + eng + mat;
	ave = tot / 3.0;

	/*
	int i;

	for (i = 0; i < n; i++)
	{
		cout << setw(5) << S[i].name << setw(5) << grade[S[i].kor / 10]
			<< setw(5) << grade[S[i].eng / 10] << setw(5) << grade[S[i].mat / 10]
			<< setw(5) << S[i].tot;
		cout << fixed;
		cout.precision(2);
		cout << setw(8) << S[i].ave << endl;

		delete S[i].name;
	*/
}

void Score::PrintScore(void)
{
	cout << std::setw(10) << std::left << name
		<< setw(5) << ::grade[kor / 10] << setw(5) << ::grade[eng / 10] << setw(5) << ::grade[mat / 10]
		<< setw(5) << tot << setw(8) << std::fixed << std::setprecision(2) << ave << endl;
}

void Score::Delete_Score(void)	// ��
{
	delete [] name;
}
#endif

// ������
#if 0
#include <iostream>
#include <iomanip>
using namespace std;

#define ScoreRng(S) (((S >= 0) && (S <= 100)) ? (S) : (0))

struct Score{
private:
	char * name;
	int kor, eng, mat, tot;
	double ave;
	void CalcScore(void);
public:
	void InitScore(void);
	void InitScore(const char * irum, int k, int e, int m);
	void PrintScore(void);
	void DeleteScore(void);
};

void Score::InitScore(void)
{
	char temp[20];
	size_t len;

	do{
		cout << "Name:";
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin.getline(temp, 20);
	} while (cin.fail());
	len = ::strlen(temp);
	name = new char[len + 1];
	::strcpy_s(name, len + 1, temp);

	do{
		cout << "Score(K, E, M):";
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> kor >> eng >> mat;
	} while (cin.fail() || !ScoreRng(kor) || !ScoreRng(eng) || !ScoreRng(mat));

	CalcScore();
}

void Score::InitScore(const char * irum, int k, int e, int m)
{
	size_t len;

	len = ::strlen(irum);
	name = new char[len + 1];
	::strcpy_s(name, len + 1, irum);
	kor = ScoreRng(k), eng = ScoreRng(e), mat = ScoreRng(m);

	CalcScore();
}

void Score::CalcScore(void)
{
	tot = kor + eng + mat;
	ave = tot / 3.0;
}

void Score::PrintScore(void)
{
	static char ch[] = "FFFFFFDCBAA";

	cout << std::setw(10) << std::left << name
		<< setw(3) << ch[kor / 10] << setw(3) << ch[eng / 10] << setw(3) << ch[mat / 10]
		<< setw(5) << tot << setw(8) << std::fixed << std::setprecision(2) << ave << endl;
}

void Score::DeleteScore(void)
{
	delete[] name;
}

void main(void)
{
	unsigned int cnt, n;
	Score * pScore;

	cout << "Count:";
	cin >> cnt;
	pScore = new Score[cnt];

	for (n = 0; n < cnt; n++){
		pScore[n].InitScore();
	}

	for (n = 0; n < cnt; n++){
		pScore[n].PrintScore();
	}

	for (n = 0; n < cnt; n++){
		pScore[n].DeleteScore();
	}

	delete[] pScore;
}
#endif






/***********************************************************************/
/*							[ 2019.10.01 ȭ ]						   */
/***********************************************************************/

// Class!!!!
// ����ü�� default�� public(������), Class�� Private�� �⺻��!! -> ���뼺�� ���� ����.

// 2.1 Class
#if 0
#include <iostream>
using namespace std;

class A
{// ���������ڸ� ���������� ������ default��! -> private��
	int no = 5;	// int no = 5;�� "�ʱ�ȭ?" => Nope! default ���� �������شٴ� �ǹ�.
protected:
	char ch;
public:
	int sum;
	void sub(void);
};

void A::sub(void)
{
	cout << "A::sub" << endl;
}

void main(void)
{
	A aa;		// => �̷��� ��ü�� ����( "����" means "��� ������ �Ҵ���!" )���� �� ��μ� ������ �Ҵ� ��!

	cout << sizeof(aa) << endl;	// size�� 12 == int no(4B)�� int sum(4B)�� �������� �̰��� ��� -> 12B (�Լ��� ���� �������� ����!!)

	aa.sub();
}
#endif



// 2.2 ������ �Լ� (Constructor) : �ʱ�ȭ�� ����!
// �پ��� ������ �Լ� ȣ�� �� �Ҵ� ���
#if 0
#include <iostream>
using namespace std;

class A
{
	int no;
	char ch;
public:
	A();
	A(int n);
	A(int n, char c);
};

A::A()
{
	cout << "Default Constructor" << endl;
}

A::A(int n)
{
	cout << "integer Constructor" << endl;

}

A::A(int n, char c)
{
	cout << "integer, character Constructor" << endl;

}

void main(void)
{
	A aa;	// Ctrl + F5 ��������, ����Ʈ �����ڰ� ��������� �� �� �ִ� => Ŭ���� ��ü ����� ��, ������ ȣ���!!
			// ���� "A aa = A();"
			// "A aa();"�� ���� ������� �ʴ� ������ �����Ϸ����� AŸ���� ������ ���� �Լ� aa�� ã�� ������ �޾Ƶ��̱� ����!
	cout << endl;

	A bb(5); // ������ ȣ���� �⺻���� ���� "A bb = A(5);" �̷� ����. �̰ź� �Լ� ȣ���ϴ� ����̶� �Ȱ��ݾ�!
			 // �̷� �͵��� ���� �������� �̸��� Ŭ������ �̸��� �Ȱ��� ������ ������ �ֱ�
	cout << endl;

	A cc(6, 'A'); // ������ ȣ���� �⺻���� ���� "A cc = A(6, 'A');" �̷� ����.
	cout << endl;

	A arr[3];	// 0, 1, 2��° Ŭ���� �迭�� ��� default ������ ȣ��
	cout << endl;

	A brr[3] = { A(), A(5), A(6, 'B') };	// ���� ���ϴ� ������ �����ų ���� ����!
	cout << endl;

	A crr[3]{ A(), A(5), A(6, 'B') };
	cout << endl;

	A * ap = new A(5);	// ���� �Ҵ絵 ����!
	// A * ap = (A *)malloc(sizeof(A));  =>  malloc���� �����Ҵ��ϴ� ���� ������ ȣ���� �� �� ����!
	// malloc�� ������ �Ҵ��� ��������, ������ ȣ�� �Ұ���. new�� delete�� �̿��ϴ� ���� ���� ȿ����!
	delete ap;
	cout << endl;

	ap = new A[3]{A(), A(5), A(6, 'A')};	// Object�� 3�� ��������� ��

	delete[] ap;
	cout << endl;


	A * bp[3] = { new A(), new A(5), new A(10, 'A') };

	for (int i = 0; i < 3; i++) delete bp[i];
	cout << endl;

	
	A * cp[] = { new A(), new A(5), new A(10, 'A'), new A[2] };

	for (int i = 0; i < 3; i++) delete cp[i];

	cout << *(int *)((char *)cp[3] - 16) << endl;

	delete [] cp[3];
	cout << endl;

}

#endif


// 
#if 0
#include <iostream>
using namespace std;

class A
{
	int no;		// ��� ������ �ְ�, ������ �Լ��� ���� ���!? => �׷��� �����Ϸ��� Default Constructor�� ����� �شٰ� ��.
public:
	//A(){};  ���ٰ� �غ���
	A(int n);	// �̰͸� �ִٰ� �ϸ�? => "�⺻ �����ڰ� �����ϴ�." ��� ���� �޼����� ��
};				// => �����ڰ� �ƹ� �͵� ���� ���� �⺻ �����ڸ� ����������, �׷��� �ʴ� ���ݰ� ���� ��쿡�� �⺻�����ڰ� �������� ����!!

A::A(int n)
{
	no = n;
}

void main(void)
{
	//A aa;

	A bb(5);
}

#endif


// 1.16(����ü)�� Ŭ������!	=>	���� �ߴµ� �ٽ� ����..��
#if 0
#include <iostream>
#include <time.h>
using namespace std;

#define IsLeap(Y) ((!(Y % 4) && (Y % 100)) || !(Y % 400))


class Date
{
private:
	int year, month, day, week;
public:
	Date(void); // ��, ��, �� ������ �ý��ۿ��� �о���� ����Լ�
	Date(int d, int m, int y = 2019); // ��, ��, �� ������ �μ��� ���޹޴� ����Լ�
	void CalcDate(void); // ���� ����ϴ� ����Լ�
	void DisplayDate(void); // ��, ��, ��, ���� ����ϴ� ����Լ�
};

static int days[12] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };

void main(void)
{
	Date today;		// �ٷ� �⺻ ������ �Լ� ȣ�� ����
	today.DisplayDate();

	Date oneday(19, 12);
	oneday.DisplayDate();
}

Date::Date(void) // ��, ��, �� ������ �ý��ۿ��� �о���� ����Լ�
{
	time_t lt;
	tm * ct;

	time(&lt);
	ct = localtime(&lt);

	year = ct->tm_year + 1900;
	month = ct->tm_mon + 1;
	day = ct->tm_mday;
	week = ct->tm_wday;

	/*
	time_t lt;
	tm cur;

	::time(&lt);				// ���� �Լ� ȣ��
	::localtime_s(&cur, &lt);	// ���� �Լ� ȣ��
	year = cur.tm_year + 1900;
	month = cur.tm_mon + 1;
	day = cur.tm_mday;
	week = cur.tm_wday;			// 0 = �� ~ 6 = ��
	*/
}

Date::Date(int d, int m, int y) // ��, ��, �� ������ �μ��� ���޹޴� ����Լ�
{
	year = y;
	month = m;
	day = d;

	/*
	if (y < 1 || y > 4000) y = 1;
	year = y;
	if (IsLeap(year)) ::days[2] = 29;
	else ::days[2] = 28;
	if (m < 1 || m > 12) m = 1;
	month = m;
	if (d < 1 || d > ::days[month]) d = 1;
	day = d;
	CalcDate();
	*/
}

void Date::CalcDate(void) // ���� ����ϴ� ����Լ�
{
	int y, sum;
	y = year - 1;
	sum = y * 365 + (y / 4) - (y / 100) + (y / 400);
	for (int n = 1; n < month; n++) sum += ::days[n];
	sum += day;
	week = sum % 7;

	/*
	int check = (::days[month - 1] + day) % 7;
	week = check;
	*/
}

void Date::DisplayDate(void) // ��, ��, ��, ���� ����ϴ� ����Լ�
{
	const char * strweek[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	cout << year << '/' << month << '/' << day << '/' << strweek[week] << endl;

	/*
	cout << year << "/" << month << "/" << day;
	cout << " (" << week << ") " << endl;
	*/
}
#endif



// 2.3 �Ҹ��� �Լ�(Destructor)
#if 0
#include <iostream>
using namespace std;

class A
{
	int no;
public:
	A();
	A(int n);
	~A();
};

A::A()
{

}

A::A(int n)
{
	no = n;
}

A::~A()
{
	cout << "A::Destructor" << endl;
}

void main(void)
{
	/*
	A aa;

	A bb(5);

	A * ap = new A;
	delete ap;	// �Ҵ��� �ݳ��Ǹ鼭 �� ap->~A�� ȣ���ϰ� �� ��!
	*/





	A * bp = new A[3];
	cout << *(int *)((char *)bp - 16) << endl;	// ��? 16����Ʈ ���� �޸𸮿� �Ҵ� ���� �޸� ������ ���µ�?
												// �Ҹ��ڰ� �ִ� Ŭ�����κ��� ���� �Ҵ�� ���� ��ü ���� ������ �־�� �ϹǷ� �Ʒ��� ���� ��.
												// ������ �Ҹ��ڸ� ���ָ�, ���� �����ϰ� 16����Ʈ ���� �޸𸮿� ��ü���� �Ҵ� ���� �޸� ��� ����
												// �Ҹ��ڰ� ���ٴ� ���� ���� ��ü ������ �۾��� �ؾ� �� �ǹ��� ���� ����!
												// �׸��� �����ڿ� �ٸ��� �Ҹ��ڴ� �ڵ����� ��������� ����!!

	cout << *(int *)((char *)bp - 20) << endl;	// �Ҵ� ���� �޸� ����Ʈ ���� ��� ���� (16����Ʈ)
						//=> Object 3�� 12����Ʈ�� ��ü ���� ������ ��� �ִ� int 4����Ʈ => ���ļ� 16����Ʈ
	
	cout << *(int *)((char *)bp - 4) << endl;	// Object�� ���� ������ ��� ���� (3��)
	
	delete [] bp;	// �̷��� [] �迭�� delete�� ���ָ� �̷� ��ü ���� ������ ��� �ִ� �޸𸮵� ��ȯ ����!!!
	// 1) bp�� Ŭ���� Ÿ���ΰ�? 2) Ŭ���� �ȿ� �Ҹ��ڰ� �ִ°�? 3) A Ŭ������ ������ �ƴ϶� �̷� ��������ٸ� ��� �ұ�?
	// �̷� �͵��� �� �Ǵ����־�� delete���� �� []�� �־�� ���� ���� �� �� �ְ� �ȴ�. �������ϱ� "new [�迭]"���� �� delete [] ������!!


	/*	// ��ȯ ����� �ٸ��� �˾ƶ�!!
	ap = new A[3]{A(), A(5), A(6, 'A')};
	delete[] ap;


	A * bp[3] = { new A(), new A(5), new A(10, 'A') };
	for (int i = 0; i < 3; i++) delete bp[i];
	*/

	cout << "end main" << endl;

	// aa.~A ȣ���� ��
	// bb.~A ȣ���� ��

	// ����� ������ ȣ��, �Ҵ�, �ݳ��� �Ҹ��� ȣ�� ��� Runtime�� �̷����!
}
#endif

// �̾
#if 0
#include <iostream>
using namespace std;

class A
{
	int no = 5;	// int no; �̷��Ը� �س��� �⺻ �����ڸ� ���� ������ �ʴ´ٸ�, �𽺾������ �̵����� �� �����ڰ� ȣ����� ���� ���� �� �� ����.
public:			// ������ int no = 5;��� (�ʱ�ȭ �ƴ�!!) default ���� �������شٸ�, �⺻ ������ ��� �ڵ����� �����Ϸ��� ȣ����!! ������
	//A();
};

//A::A()
//{
//
//}

void main(void)
{
	A aa;

	cout << "end main" << endl;
}

#endif




// 2.4 ����� this
#if 0
#include <iostream>
using namespace std;

class A
{
	int no;
public:
	A(){};
	A(int n);
					// Ư���� �������� �۾��� ���ٸ�, �Ҹ��ڴ� ���� �ʿ� ����.
	void sub(int dummy);
};

A::A(int n)
{
	no = n;		// this->no = n; �� ���� ǥ����!! default�̴ϱ� �����ؼ� ����ߴ� ����

	cout << (*this).no << endl;

	cout << this << endl;		// this�� ����Լ� �������� ����� �� ����!! �����ڴ� �翬�� ����Լ�
								// ��µǴ� ���� �� �Լ��� ȣ���� Object aa�� "�ּ�"�̴�!
}

void A::sub(int dummy)		// "void __thiscall A::sub(int dummy)" �갡 ����Ʈ ������
{
	cout << "16B ���� ��: " << hex << *(int *)((char *)&dummy - 16) << endl;
	//*(int *)((char *)&dummy - 16) = 0;	: �̷��� ���ָ� this �� 0�� ���� �� �� �ִ�. ��, ���� �ּҿ� �ִٴ� ���� �� �� �ִ�
	// this�� ���ó�� ���Ǳ� ������ this = 0;�� ���� this�� ���� �������ַ� �Ѵٸ� l-value ����!
	cout << this << endl;
	cout << "==========���� ����?==========" << endl;
}


void main(void)
{
	A aa(15);		// aa.A(15)��� aa��� Object�� �����ڸ� ȣ���� ��!
	cout << &aa << endl;
	aa.sub(0);

	A bb;
	bb.sub(0);
}

#endif

// C������ this ������ ������, �ּҸ� ���ڷ� �Ѱ������ν� ����ߴ�.
// �׸��� ���� �װ��� �����̴�.
// Ŭ������ �׳� �տ��� aa.~~();�� ���� ȣ���� �� �� �ֱ� ������ �ּҷ� �Ѱ��� �ʿ�� ����.
#if 0
#include <stdio.h>

struct st
{
	int no;
	char ch;
};

void InitStruct(struct st * this, int n, char c); // main �ȿ��� �Լ� ���� ���� ���� ��, main �ȿ����� ��� ����!
// ���� ��ƿ��� ���� �Լ�
void PrintStruct(const struct st * this);
// ����  ���б�� ���� �Լ� -> const�� ���� ��(���ȭ ������! ��, �ٲ��� ����.
//										  ������ C�� const�� ������ ���ȭ�� �������� ���Ѵٰ� ��!)
// ������ ���ο� �дٸ�, �̷��� ���! �������� ������.

/* ������ ���캸��, ����ü�� ������ �Լ��� �ǹ̰� ����, �Լ��� ������ ����ü�� ���� �аų� �� �� ����.
��, ���� ����� �Ұ����� �����̴�.
=> �׷� ���� ��� ������ ���� ������? �׷��ٸ� ���뿡 �������� ������?
=> C++�� ������ �Լ��� ����ü �ȿ� �� �� �ֵ��� �ߴ�! */

void main(void)
{
	struct st aa;	// ����ü ���� ����!
	printf("size of struct st? = %d\n", sizeof(aa));	// ���� ū ����Ʈ�� int�� �������� ���� ���(=> 8����Ʈ)

	InitStruct(&aa, 5, 'A');	// Call by Address
	PrintStruct(&aa);			// ����ü�� ũ�Ⱑ Ŀ�� Call by Value�� �� ��� ����!
}

void InitStruct(struct st * this, int n, char c)
{
	this->no = n;
	this->ch = c;
}

void PrintStruct(const struct st * this)
{
	printf("You can read struct st type variable thanks to me! : ");
	printf("%d, %c\n", this->no, this->ch);
}
#endif

#if 0
#include <iostream>
using namespace std;

class A
{
	int no;
public:
	A(){};
	A & sub(void);
	A * func(void);
	~A(){ cout << "A Destructor" << endl; };
};

A & A::sub(void)
{
	cout << "sub" << endl;
	return *this;		// A imsi = * this;	�̷��� �ӽ� ��ü�� �������!!
}

A * A::func(void)
{
	cout << "func" << endl;
	return this;
}


void main(void)
{
	A aa;
	aa.sub().func()->sub().sub();
	aa.func();
	// ������ Reference�� Ÿ���� ���缭 �ָ� ��ü�� �ϳ��� �������!! A aa;�� ��
}

// Destructor���� ����� �� ���̳� �Ǵ� ������ ���� ��ü�� 4���̳� ��������ٴ� ���� �� �� �ִ�.
//class A
//{
//	int no;
//public:
//	A(){};
//	A sub(void);
//	A * func(void);
//	~A(){ cout << "A Destructor" << endl; };
//};
//
//A A::sub(void)
//{
//	cout << "sub" << endl;
//	return *this;		// A imsi = * this;	�̷��� �ӽ� ��ü�� �������!!
//}
//
//A * A::func(void)
//{
//	cout << "func" << endl;
//	return this;
//}
//
//
//void main(void)
//{
//	A aa;
//	aa.sub().func()->sub().sub();
//	aa.func();
//}
#endif

// cout�� ������ printf�� ���� ���÷� ����
#if 0
#include <iostream>
using namespace std;

struct stream
{
	stream & printf(int);
	stream & printf(char);
	stream & printf(double);
	stream & printf(const char *);
};

stream & stream::printf(int n)
{
	::printf("%d\n", n);
	return *this;
}

stream & stream::printf(char c)
{
	::printf("%c\n", c);
	return *this;
}

stream & stream::printf(double d)
{
	::printf("%lf\n", d);
	return *this;
}

stream & stream::printf(const char * str)
{
	::printf("%s\n", str);
	return *this;
}

void main(void)
{
	stream c;

	c.printf(5).printf(3.14).printf("seoul");	// cout�� �̷��� �Ǿ� ����!!
	// printf �Լ��� value�� �����ߴٸ� �� ������ ��� ��� ��ü�� �������� ��. ��ȿ��
}

#endif




// 2.5 ���Ե� ��ü(embedded object)�� �ݷ�(colon, : ) �ʱ�ȭ
#if 0
#include <iostream>
using namespace std;

class A
{
	int no;
public:
	A(){ cout << "A Default Constructor" << endl; };
	A(int n) { no = n; cout << "A int Construct" << endl; };					// �׳� ���ο��� ����
	void sub(void) { cout << no << endl; };	// Ŭ���� ��� ������ �б� ���� �Լ�
};

class B
{
	char ch;
	A aa;	// �갡 �ٷ� "embedded object"��!!! �� �� Ŭ���� B�� "surrounded class"��� ��
public:
	B();
	B(char c, int n);
	void func(void);
};

B::B() //: aa()	// �����Ϸ��� �̷��� ������ �ϱ� ������ ���Ե� ��ü�� aa�� ���ؼ� ���� ������ ȣ�� (�Ϲ����� �ݷ� �ʱ�ȭ)
	   //: aa(0)	//�� ���� "������� �ݷ� �ʱ�ȭ"�� ����! -> A(int n); �����ڷ� ���� �� �� OhOh~
{ 
	cout << "B Default Constructor" << endl;
}

B::B(char c, int n) : aa(n),	// ���⵵ ���������� "�ݷ� �ʱ�ȭ", �� aa�� ������ �ʱ�ȭ�� ��!!
						ch(c)	// �ھ굵 �ݷ� �ʱ�ȭ. �� �Լ� ���ο��� "ch = c;"�� ����! ���� ���� �ٸ�! �ݷ� �ʱ�ȭ�� ���� ȿ����!
{ // BŬ������ A ��� ������ ������� ������ �� ����. ������ Ŭ���� A�� ���� A(int n); �����ڰ� ����!! �̰��� ���� ����!
	
	//aa = A(n);	// A��� �̸��� ������ �Լ��� ȣ��, �̿� ���� �ӽ� ������Ʈ�� ����� ����, �̴� �� �̸� ����/�� Object.
				// => ���� ����� �ʱ�ȭ�� �ƴ�!! => ���ݷ��ʱ�ȭ�� ���� ȿ����!!
	//ch = c;		// �ھ굵 ���������� ȿ�������� ����! �ݷ� �ʱ�ȭ!
}

void B::func(void)
{
	cout << ch;
	aa.sub();	// B������ A�� private(default) ��� ������ ���� ���� �� �ϹǷ� sub��� public �Լ� ȣ��!
}

void gsub(B rb)	// ��� �����Լ�
{

}

void main(void)
{
	B bb;	// B Ŭ�����κ��� ��ü�� ������µ� ���Ե� ��ü�� ������ ���� �������!
			// (�� �ٿ� Ŀ���� ���� Ctrl + F10�� ���� ����� ����, �׸��� F11�� ������ � ������ ����Ǵ��� ���ƶ�!)
			// ���� A Ŭ������ �⺻ �����ڸ� ��������� �ʾҴٸ�(or ���ٸ�) ��Ÿ�� ������ ���ݰ� ��!
			// => ���� : ������ �⺻ �����ڴ� �׻� ����� �ε��� �Ѵ�! �ƹ��� �ڵ尡 ���ٰ� �ϴ���!

	B bibi('A', 10);

	bibi.func();

	//B('B', 5);	// ������ �Լ��� ȣ���� ��������, ��� �Լ��� ȣ���� �� �ִٴ� ���� �� Object��!!
	B('B', 5).func();	// �������� �ٷ� .�� �� �Լ��� ȣ���ߴٸ�, �̰� �ٸ� Object�� ������� ���̶�� �� �� ����!
	gsub(B('B', 5));	// ���ӽ� Object�� �Ѱ��� ���̰�, �Լ��� ������ �� �ӽ� Object�� �Ҹ��! (Stack)
}
#endif

// ������ ��� �����Ϳ� const ��� �������� �ݷ� �ʱ�ȭ
#if 0
#include <iostream>
using namespace std;

int go = 5;

class A	// �� Ŭ������ �� 12����Ʈ��.. ������ ������ �����Ϸ����� �����Ͷ� �Ȱ��� �νĵ�. �������� �޾���� �ϱ� ������ 4B
{
	int no = 5;
	int & ro = no;	// �ֱ� �����Ϸ������� Ŭ���� ���ο��� �⺻���� �������� �� ����!! -> �ݷ� �ʱ�ȭ ���� �ذ� ���ص� �� Default value�� ���� ��!! (Ŭ���� ��ü ���� ��!)
					// �������� �̰��� "�ʱ�ȭ"�� �ƴ϶� �⺻���� �ֱ� �����̶�� ���� �˾ƾ� ��!!!
	const int co = 7;
public:
	A();
	A(int n);

};

A::A() : ro(go), co(5)	// ������ ��� �����Ϳ� const ��� �����ʹ� �ݷ� �ʱ�ȭ �ʼ�!! �� ���ָ� Compile Error!
{
	// �� �ȿ��ٰ� �������ָ� �ȵǳ�? �ȵȴ�! ��� �����̰�, �̴� �ݷ� "�ʱ�ȭ"�� �ٸ��� ����!!
	// const�� ��� ������! ������
}

A::A(int n) : ro(no), co(10)	// 1)  2)
{
	no = n;						// 3) ������ �ʱ�ȭ�� �����!
								// ro�� ������ �������� ��� ���̰�, int & ro = no;�� ���� ���� ���� �� ����.
}

void main(void)
{
	A aa(7);

	int n = 5;
	int & k = n;	// ��(k)�� ������ ���ÿ� �ʱ�ȭ�� �Ʊ� ������ �ٸ� ���� ���� �Ҵ���� ����!
}
#endif





// 2.6 const ��ü�� const ����Լ�
#if 0
#include <iostream>
using namespace std;

class A
{
	int no;
	char ch;
	mutable char cha;	// mutable�� ����� ��� ������ŭ�� const �Լ��鵵 �����ų �� �ִٰ�....
public:
	A(){};
	A(int n, char c) : no(n), ch(c) {};
	void sub(void);
	void sub2(void) const;
	void func(void);
	void func(void) const;
};

void A::sub(void)
{
	no = 0;
	ch = 'A';
}

void A::sub2(void) const	// ��� �������� ������ ���� ����!
							// �� �Լ��� ���� �ٲٴ� ������ ���� �ʴ´ٸ� const �Լ� �Ӹ� �ƴ϶� �Ϲ� �Լ��鵵 �θ� �� ����!
							// �׷� �� ȣ��Ǵ� �Լ��鵵 ���� �����ϴ� ������ �ϸ� �ȵ�!
{
	cout << no << " " << ch << endl;
	// �翬�� const �Լ� �ȿ��� funcȣ���� �� ����!!
	// => ���� �� "this->func();"�� �Ȱ��� ���̴�. �ٵ� this�� Ÿ���� �����ΰ�? const A * Ÿ��!! �׷��⿡ const �Լ��� �ƴ� �Լ��� ȣ�� ���� ����!
	
	((A *)this)->func();	// 1) ������ Ÿ�� ĳ������ ���ָ� ȣ���� �� ����. ������ ���� ����Ǵ� ���� ���� �ϰ� �־��..
	func();		// 2) �����ε� �Լ�..��
	// ù ��° ������� ȣ���� �ϵ�, �� ��° ������� ȣ���� �ϵ� �װ� ����. ������ ����� �� ��°.
}

void A::func(void)
{
	no = 100;
	ch = 'Z';
}

void A::func(void) const
{
	cout << "const func" << endl;
}


void main(void)
{
	const A aa(5, 'A');	// const ��ü. �׻� ����� ���ÿ� �ʱⰪ�� �־�� �ϰ�, ������ �� ����!
	//aa.sub();			// �׷��⿡ ���� �ٲ� �� ������ ���� �޼����� ��! ȣ���� �� �ϵ���
						// �ڰ��� �ٲ��� �ʴ� �Լ��� ȣ���� �� �ִ�!! : const�Լ�!�� �׷��� func�� �θ� �� ����!
	aa.sub2();
}
#endif


// ��� �Լ��� ���� Ÿ�Ե� const....
#if 0
#include <iostream>
using namespace std;

class A
{
	int no;
public:
	A(){};
	A(int n) : no(n) {};
	const int * psub(void) const;	// "int * psub(void) const" ��� ��� ������ ������ �����Ű�� �����Ƿ� const �Լ�..!
									// ������ ���ϰ��� �� �ּҸ� �̿��Ͽ� ������ ���� ���� ������ ���� ���ݾ�?
									// ȣ���� �޴� �� �Լ� ���λӸ� �ƴ϶� ȣ���ϴ� �ʿ�� ���� ���� �� �ϵ���!!!
									// �װ͵� �� �ϰ� �������� "const int * psub(void) const"�� ����!;;;
	const int & rsub(void) const;	// �굵 �޴� �ʿ��� ���� ������ �� �����Ƿ� const ~~ const�� ����!
	const A * pfunc(void) const;
	const A & rfunc(void) const;
};

// �� ��� �������� �ּҳ� �������� ������ ���� const ���������� �������־�� ������ ���� ����!! ��
const int * A::psub(void) const
{
	return &no;
}

const int & A::rsub(void) const
{
	return no;
}

const A * A::pfunc(void) const
{
	return this;
}

const A & A::rfunc(void) const
{
	return *this;
}

void main(void)
{
	A aa(5);
	cout << *(aa.psub()) << endl;
	cout << aa.rsub() << endl;
	cout << aa.pfunc() << endl;
	aa.rfunc();
}

#endif


// ������ �� �ȵʡ�
// ��� �Լ��� ����鼭 ��� �����͸� �ٲ��� �ʴ´ٸ� const �Լ��� ������ ���ִ� ���� ����غ��� ������,
// �̿� ���� ���, ��� printf �Լ��� const �Լ��� ����� �����ٸ� ���ο� ::printf()���� ���������ڰ� �״�� ������ �Ǿ� ����
// �������� ����(?) �Լ� Ŭ������ �Ǿ� ����..
// �̷� ��쿡�� const�� �������� �ʴ´ٰ�...;;
#if 0
#include <iostream>
using namespace std;

struct stream
{
	stream & printf(int);
	stream & printf(char);
	stream & printf(double);
	stream & printf(const char *);
};

stream & stream::printf(int n)
{
	::printf("%d\n", n);
	return *this;
}

stream & stream::printf(char c)
{
	::printf("%c\n", c);
	return *this;
}

stream & stream::printf(double d)
{
	::printf("%lf\n", d);
	return *this;
}

stream & stream::printf(const char * str)
{
	::printf("%s\n", str);
	return *this;
}

void main(void)
{
	stream c;

	c.printf(5).printf(3.14).printf("seoul");	// cout�� �̷��� �Ǿ� ����!!
	// printf �Լ��� value�� �����ߴٸ� �� ������ ��� ��� ��ü�� �������� ��. ��ȿ��
}

#endif



// [�ٽ� �غ���!!]
// ����  int * const * .... const...
#if 0
#include <iostream>
using namespace std;

class A
{
	int no;
	int * np;
public:
	A(){};
	A(int n) : no(n), np(&n) {};
	const int * GetP(void) const;
	int ** GetPP(void);
	int * const * GetPP(void) const;
	void Print(void) const;
};

int * const * A::GetPP(void) const
{
	return &np;
}

int ** A::GetPP(void)
{
	return &np;
}

const int * A::GetP(void) const
{
	return np;
}

void A::Print(void) const
{
	cout << no << endl;
}

void main(void)
{
	A aa(5);

	//int * res = aa.GetP();
	//*res = 0;	// ��� no ��� ������ ������ �ϱ�� ��. ������ �����Ϸ��� �̰ű��� �Ű� �� ��
	// �����Ϸ��� ���� ���ϵǴ� np���� �ٲ� ������ �ִ��� ���θ� �Ǵ��� ��! �׷��� np ��ü�� �ٲ��� �����Ƿ� ���������� const int *�� ����߸� �ϴ��� �Ǵ� �� ��.
	// ������ ��� ���ߴ� ���� no�� ����� ������ �����Ƿ�, ���⿡�� ���� Ÿ���� const�� �ٲ���� �ڴٰ� �Ǵ�!!!
	
	
	
	// �̰� �ٽ� �غ���! ������
	**(aa.GetPP()) = 111;
	aa.Print();
}

#endif




// 2.7 static ��������� : �Ϻ��� OOP�� ��� ������ ������ �ƴ� �������� ����ȴ�!!
#if 0
#include <iostream>
using namespace std;

class A
{
	int no;
public:
	static int sum;
};

/* �ڡڡڡ� */ // ���� �� static�� ���� �ʴ´�!! ����? : �ٸ� ���ϵ��� ����� �̰��� ������ �־��� ��, ������ ���ϸ��� �ٸ� ������ ��!
int A::sum = 10;	// �׳� int sum;�̶�� �����ϸ�, �̰��� �������� sum�̶�� ������ ���� ��!!
			// �׸��� static int sum; �̶�� Ŭ���� ������ ������ ���־����� ������ int A::sum;�̶�� �ٽ� ������ ���־�� ��!!
			// �׸��� �� ������ �ʱ�ȭ�� �����ϴ�!!! (�ʱⰪ ������ 0���� �ʱ�ȭ��!)
			// ����ǰ� �ʱ�ȭ�Ǵ� ���� �����̹Ƿ� �翬�� �ݷ� �ʱ�ȭ�� �Ұ����� ���̴�!!
			// ������ static int sum;�� private �� protected�� ������ �س�����, ���� ������ ���ѵ�����, ������ ����!!

void main(void)
{
	A aa;

	cout << sizeof(aa) << endl;	// static ����� ��ü�� ũ�⿡ ���Ե��� ����!!! ������ ����!!

	A bb;
	aa.sum = 0;	// ��� A Ŭ���� ��ü���� sum�� �����ϹǷ� aa�� bb�� ���� ���� ��. aa�� �ٲٴ��� bb�� sum���� �ٲ�!
	// �׷��� �̰͵� public�� ����Ǿ��� ������ �̷��� ������ ������ ��!!
	cout << bb.sum << endl;	// cout << sum << endl; �̶�� �ϸ� ���� ��!! ������� ���� �ĺ��ڶ�� ����
}
#endif


// (���ٱ��� private��) static ��� �����Ϳ� �����ϱ� ���� static ��� �Լ�!
#if 0
#include <iostream>
using namespace std;

class A
{
	int no;
	static int sum;	// private�� ������ �ߵ���, ���⿡ ������ �� �ִ� public �Լ��� ���� �����ؾ� ��!!
public:
	static void sub(int s);
	static void func(void);
};

int A::sum = 10;	// ��� A aa;�� ��������� �ξ� ������ ������� �ִ� ��!
					// �׷� A aa;�� ����Ǳ� ���� sum�� �����ϰ� ������ ��� ����..?
					// => Object ���̵� sum(static ��� ������)�� �����ϰ� �ʹٸ�, ��static ����Լ�...!��
// static ����Լ� : Object ���̵� ��� �����Ϳ� ������ �� ����!!!!

void A::sub(int s)		// ���⿡�� �������� ���� static void A::sub(int s) ~ �� ���� ������ �� ���ٰ� ��!!
{
	A::sum = s;	// sum�� ����� ���� A::sum�̶�� ��!!
}

void A::func(void)
{
	cout << A::sum << endl;
}

void main(void)
{
	A::sub(5);	// static ��� �����Ͱ� �ִٸ�, �ڿ������� �� �����Ϳ� �����ϱ� ���� static �Լ��� ������� �Ǿ�����!
	A::func();

	A aa;

	cout << sizeof(aa) << endl;	// static ����� ��ü�� ũ�⿡ ���Ե��� ����!!! ������ ����!!

	aa.sub(0);	// sum�� 0���� �ٲٰ�
	aa.func();	// sum�� ���
}
#endif




// �ڡ� ��ü���� ���� ����!! �ڡ�
// 2.8 static ����Լ�
// �����ڸ� private ��������.. -> ��𼭳� �����Ӱ� Object�� ������ ���ϵ���
#if 0
#include <iostream>
using namespace std;

class CMainFrame	// MFS���� �����ϴ� �⺻ Ŭ���� �� �ϳ�!
{
	CMainFrame();	// ��𼭳� �����Ӱ� Object�� ������ ���ϵ��� public���� private�� �������!!
					// �����ڸ� �̷��� ����� ����? : �������� Object�� ����� �����ϰ� �� �� �ֵ���!
public:
	static CMainFrame * CreateObject(void);	// �ٱ����ٰ� static���� �Լ� ���� Nope!
	~CMainFrame();
	void ShowWindow(void);
	void DestroyWindow(void);
};

CMainFrame * CMainFrame::CreateObject(void)	// Object(��ü) ��������� ������ Ŭ������ ���� ����!! -> CMainFrame�� ������ ���̴�!
{
	return (new CMainFrame);
}

CMainFrame::CMainFrame()
{
	cout << "Create CMainFrame" << endl;
}

CMainFrame::~CMainFrame()
{
	cout << "Bye CMainFrame" << endl;
}

void CMainFrame::ShowWindow(void)
{
	cout << "Show CMainFrame" << endl;
}

void CMainFrame::DestroyWindow(void)
{
	cout << "Destroy CMainFrame" << endl;

	delete this;	// ���⼭!!
}

void main(void)
{
	CMainFrame * pFrame = CMainFrame::CreateObject();
	
	pFrame->ShowWindow();		// 
	pFrame->DestroyWindow();	// ����ڰ� ���� ��ܿ� X(close) ��ư�� ������ �����

	//delete pFrame;		=> �ٵ� ���⼭ delete ���� �ʴ��� delete �ǰ� �� �� ������?
							// => DestroyWindow(��, xŬ������ �� ��)���� �ϸ� ���ݾ�?
}
#endif

// �� ���� ����� �ִ� ���� => �̰� ����?
#if 0
#include <iostream>
using namespace std;

class CMainFrame
{
	//CMainFrame();
public:
	CMainFrame() = delete;
	static CMainFrame * CreateObject(void);
	~CMainFrame();
	void ShowWindow(void);
	void DestroyWindow(void);
};

CMainFrame * CMainFrame::CreateObject(void)	
{
	return (new CMainFrame);
}

CMainFrame::CMainFrame()
{
	cout << "Create CMainFrame" << endl;
}

CMainFrame::~CMainFrame()
{
	cout << "Bye CMainFrame" << endl;
}

void CMainFrame::ShowWindow(void)
{
	cout << "Show CMainFrame" << endl;
}

void CMainFrame::DestroyWindow(void)
{
	cout << "Destroy CMainFrame" << endl;

	delete this;
}

void main(void)
{
	CMainFrame * pFrame = CMainFrame::CreateObject();

	pFrame->ShowWindow(); 
	pFrame->DestroyWindow();
}
#endif





// friend �Լ� 
#if 0
#include <iostream>
using namespace std;

class A;	// B���� A�� Ŭ������! ��� �˷��ִ� ����

class B		// Bsub �Լ� �ȿ��ٰ� �ᵵ ��!
{
public:
	void Bsub(class A * ap);
};

class A
{
	int no;
public:
	A(){};
	A(int n) : no(n) {};
	void sub(void) const;
	friend void Gsub(const A & ra);	// ���������� ��� �ִ� �ʿ� friend�� �����صθ�, private�� ���ٱ����� �������!
	friend void B::Bsub(A * ap);	// �ϴ� �ٸ� Ŭ������ ����̹Ƿ� �������� �� ����� ��!!
};

void A::sub(void) const
{
	cout << no << endl;
}

void Gsub(const A & ra)	// �����Լ� , ������ �޾���(���ο� ���� �Ҵ� �����ֱ� ���Ͽ�!)
{
	//cout << ra.no << endl;	// private �����̶� no�� ���� ���� ����!!
							// �׷��� �� �����Լ��� ��� �ȿ��ٰ� friend�� �����س����� ���� ����..!! ����

	ra.sub();			// �׷��� ������ó�� ��� ������ �״�� �����Ű�� ���� ����ϸ� ���� ����..
						// ���� ��������δ� �Ȱ�����, ���� �ٲ� �� ������ sub �Լ��� �����Ͽ� �̿��ϴ� ���� ���� ����!!
}

void B::Bsub(A * ap)
{
	ap->sub();	// ��? ��ø�, �ٷ� �����Ϸ���?? ģ������!�ϰ� A ������ ��
}

void main(void)
{
	A aa(58);

	Gsub(aa);

	B bb;
	bb.Bsub(&aa);
}

#endif




/***********************************************************************/
/*							[ 2019.10.02 �� ]						   */
/***********************************************************************/

// 2.12 ���� �������Լ�(copy constructor)
#if 0
#include <iostream>
using namespace std;

class A
{
	int no;
	char ch;
public:
	A(){};
	A(int n, char c) : no(n), ch(c) {};
	A(const A &ra);
	void sub(void) { cout << no << " " << ch << endl; };
};

// �����Ϸ��� �ڵ����� ������ִ� "����Ʈ ���� ������ �Լ�"
/*
		A(A ra);	// �ڱ� �ڽ��� "����"�ϴ� ������ �Լ��� �ƴ϶��, RTE �߻�!
		Why?
		: A ra = aa; (== A ra(aa);)��� ������ �Լ��� ȣ���� ���̰�.
		�׷� ��� A(A ra); ��� ������ �Լ��� �迡���������ļ� ȣ���ϴ� ���̱� ������ RTE �߻�!!
*/
A::A(const A &ra)
{
	no = ra.no;
	ch = ra.ch;
}


void main(void)
{
	A aa(5, 'A');
	aa.sub();

	A bb = aa;	// bb.operator =(aa); ��� �Լ��� ȣ��Ǵ� �� �ƴ�!! ���� �� ���� "���� && �ʱ�ȭ ��"��!!
				// �� A bb(aa); ������ �Լ� ȣ��!	�갡 ȣ��Ǵ� ��! �ڵ����� A Ÿ�� ���ڸ� �޴� ������ �Լ� ����� �ִ� �͡�
	bb.sub();
}

#endif




// [�ڡڡڡڡ�]
// 2.13 R-value ����	( L-value : ���� ���� // R-value : ��� )
#if 0
#include <iostream>
using namespace std;

int & sub(int & nn)	// �׳� int nn�� ���ڷ� �޾��ָ� �� �ٸ� �������� ������� �ű⿡ �����ϰ� ��!
{
	return nn;
}

int func(void)
{
	int n = 5;

	return n;
}

void main(void)
{
	int n = 5;


	int & k = n;	// L-value ����


	int && r = 5;	// R-value ���� (����� ����)
	r = 10;			// R-value ������ const�� ������ �޸� �� ���� ����
	cout << r << endl;


	const int & c = 10;
	cout << c << endl;
	//c = 5;			// const ������ ����Ʊ� ������ �� ���� �Ұ�!


	// �� ������ ���� ���� �ʿ�!! ��
	int & res1 = ++n;
	int && res2 = n++;	// �ӽð��� �ް� �� �ӽð��� �����ؾ��� ��


	// �� ������ ���� ���� �ʿ�!! ��
	int & s1 = sub(n); // int & Ÿ���� �����̹Ƿ� �� ����(�� �ӽ�!)�� �� ������ ��. -> L-value ������ �޾ƾ�...;;
	// l-value ���� ������ s1�� ���� �ٸ� ������ ���õǴ� �� �ƴ�.

	int && s2 = func();// �Լ� �ȿ��� n�� �ӽÿ� ������� n�� ���Ե�. n�� �Լ� �����鼭 ���� ������.
	// r-value ���� ������ s2�� ���� �ٸ� ������ ���õǴ� ��.
	// �̷��� R-value ������ "2.14 �̵� �������Լ�(move constructor)"���� �ʿ�!!
}
#endif



//2.14 �̵� �������Լ�(move constructor)
#if 0
#include <iostream>
using namespace std;

class A
{
	int no;
public:
	A(){ cout << "Default Cons ..." << endl; };							// ����Ʈ ������
	A(int n) : no(n) { cout << "Integer Cons ..." << endl; };
	A(const A & ra) : no(ra.no) { cout << "Copy Cons ..." << endl; };	// ���� ������
	A(A && ra) { cout << "Move Cons ..." << endl; };					// �̵� ������
	// �̵� ������ : ��� ��������ٰ� �� �Ҹ�� �ӽ� ��ü�� ���ؼ� ���� �����ں��� �켱�ؼ� �����ǰ� ��!
	// �׳� �� �����ϱ� ���� �����ڸ� ����ϴ� ���� �ƴ϶�, ���� ������ �̵��� ���� �����ڸ� ȣ���ϴ� ���� ȿ����! 
	// ���� �����ں��� ������ ����� �ڵ�! �׷��� ������ ��ü ���� ������ �̵��� ���� �����ں��� ȿ�������� "�ڴ�"�� ¥�� ��!!
	~A(){ cout << "Des ..." << endl; };
};

A sub(void)
{
	A aa;
	return aa;	// (value�� ����) ��imsi Object�ڸ� �����, �װ��� ����!-> "des..." ��� �޽��� �� ���̴�~
					// A imsi(aa); -> ���� ��������ڰ� ȣ��Ǵµ�, �����Ƿ� ����Ʈ �����ڷ� �ӽ� ��ü�� �ʱ�ȭ �� ��!
					// (cf> 2.12 ���� �������Լ�(copy constructor) ����)
					// => ���� ������ �Լ��� ȣ�� �ȴٸ�...


	//return A();		// NRVO ( Return Value Optimazation )
}

void main(void)
{
	// 1) �ӽ� ������ ������
	//sub();		// => "des..." ��� �޽��� 2��
	A res = sub();	// => "des..." ��� �޽��� 2�� -> but, ��ġ�� �ٸ�!!

	// 2) �̵� �����ڰ�
	cout << "end main" << endl; // => "des..." ��� �޽��� 2�� -> but, ��ġ�� �ٸ�!!
}
#endif

// 
#if 0
#include <iostream>
using namespace std;

class A
{
	int no;
public:
/*
	//A(){};				   �̷� �⺻ �����ڸ� ������ �ʰ�,
	A(int n) : no(n) {};	// �ٸ� �����ڸ� ������ٸ�? => �����Ϸ��� ����Ʈ �����ڸ� �ڵ����� ��������� ����!
	//A(const A & ra){};	   �⺻ ��������ڴ� �⺻���� ����!
	A(A && ra) {};			// ��, �̵� �����ڸ� ������ �ʾ��� ��쿡�� ��������� �⺻���� ����..!!;;
*/

	A() = default;
	A(int n) : no(n) {};
	A(const A & ra) = default;		// �̷� ������ default ���� �����س�����, ����Ʈ�� �̰͵��� �켱������ ����!!
	A(A && ra) {};
};

void main(void)
{
	A aa;
	A bb(aa);
}

#endif







// 2.18 ��ġ����(placement) �ʱ�ȭ�� new : �̸� �Ҵ��� �س���, ���߿� ���� �� �ٽ� �ʱ�ȭ!
#if 0
#include <iostream>
using namespace std;
#include <stdlib.h>

class A
{
	int no;
public:
	A(){};
	A(int n) : no(n) {};
	int sub(void){ return no; };
};

void main(void)
{
	// 2.18 ��ġ����(placement) �ʱ�ȭ�� new : �̸� �Ҵ��� �س���, ���߿� ���� �� �ٽ� �ʱ�ȭ!
	/*
	int no;

	int * np = new (&no) int (15);	// ���� ���� �Ҵ��̷�..!!
	cout << *np << endl;

	
	int * p = new int;				// ���� ���� �Ҵ�!
	int * ap = new (p) int(5);

	cout << *ap << endl;

	delete ap;	// ��ap�� ��ȯ�ϴ°� �´ٰ� ��!!��
	*/


	//A * p = new A;			// Object�� �����ϸ鼭 �����Ҵ�! (�� ���� Ƽ��Ʈ �����ڸ� ȣ���ϰ� �ǰ���?)
	A * p = (A *)malloc(sizeof(A));	// malloc���� ���ִ� ��찡 ���ٰ�..;;

	A * ap = new (p)A(5);	// �ڸ޸� �Ҵ� �ϴ� �� �ƴ�!�� �� �� ��int �����ڸ� Call�� �ϴ� ��!!!!

	ap->~A();	// �ʿ��ϴٸ� �Ҹ��� �� ����. ������ �ִ� �ڿ��� �ݳ�! ������ ��ü ��ü�� Ǯ�� �� �ƴϾ�!!
				// �׷��� �ٽ� �����ڸ� �ҷ��� �� �־�!!


}

#endif





/***********************************************************************/
/*							[ 2019.10.04 �� ]						   */
/***********************************************************************/


// ��� �⺻
#if 0
#include <iostream>
using namespace std;

class A	// ������� ���� �ڵ�
{
	int no;
protected:
	char ch;
public:
	int sum;
	void sub(void);
};

void A::sub(void)
{
	cout << no << ch << endl;
}

class B : public A	// ���ó� �Ĺ���� ���� �ڵ�
{
	//A::sum;	// �̷� ��� ����!
public:
	A::ch;		// protected �����̾��� ���� public���� ���� ����!(private ���� ���� �������� ����!)
};

void main(void)
{
	B bb;
	cout << sizeof(bb) << endl;	// AŬ����(���/�θ� Ŭ����)�� ũ�� �״��!(12B)

	//bb.no = 5;					// �θ��� private ����� ���� ������ ���� �Ұ� (�ܺο���)
	//bb.ch = 'A';					// �θ��� protected ����� ���� ������ ���� ���� (�ܺο���)
	bb.sum = 100;
	// �׷��ٸ� �θ� ����� ���� ���� ���� ���� �����Ѱ�? ����!! : public: A::ch; ��� �������ָ� ����!
	bb.ch = 'A';// �̷���! ������ �θ��� private ����� public���� �ٲ� �� ����!!!!
}
#endif

// �Ļ�Ŭ������ ������, �Ҹ��� �Լ�
#if 0
#include <iostream>
using namespace std;

class A	// ������� ���� �ڵ�
{
	int no;
protected:
	char ch;
public:
	A(){ cout << "A def. cons..." << endl; };
	A(int n) : no(n) { cout << "A int cons..." << endl; };
	int sum;
	void sub(void);
};

void A::sub(void)
{
	cout << no << ch << endl;
}


class B : public A	// ���ó� �Ĺ���� ���� �ڵ�
{
	char * str;
public:
	B();
	B(char * s);
	B(int n, char c, char * s);	// �ڽ� Ŭ������ �����ڿ��� �����Ϸ��� �ڵ������� :�ʱ�ȭ�� ��! : A()��
};

B::B()	// : A() - ��, A�� �⺻ �����ڰ� �ƴ� �ٸ� �����ڸ� ������ٸ�, �� �⺻ ������ �Լ��� �� ���������, ȣ����� ����!!
{
	cout << "B def. cons..." << endl;
}

B::B(char * s)	// : A()
{
	cout << "B char. * cons..." << endl;
}

B::B(int n, char c, char * s)	// : A()
{
	cout << "B int, char., char. * cons..." << endl;
}


void main(void)
{
	B bb("Seoul");	// A(�θ�/���) Ŭ������ ������ ���� ȣ���! <-> �Ҹ��ڴ� ������ �Լ��� ��������(�ڽ�/�Ļ� Ŭ������ �Ҹ��� ���� ȣ���!)
	cout << sizeof(bb) << endl;	// �θ� ũ��� char *(4B)�� ���� 16B�� ����!
}
#endif




// string Ŭ����
#if 0
#include <string>
#include <iostream>
using namespace std;

class mstring : public string
{
// 1) �Ļ� Ŭ�������� �ʿ��� ��� �Լ�/���� �����
// 2) �Ļ� Ŭ������ �´� ������, �Ҹ��� �Լ� �����

	string::c_str;
public:
	mstring();
	mstring(const char * str);
	operator const char *(void) const; // ��� �����͸� �������� �����Ƿ� const Ÿ�� �Լ�
										// "const char *"�� �ʿ��ϸ� ȣ���!!
};

mstring::mstring()
{

}

mstring::mstring(const char * str) : string(str)	// �θ𿡰� ���� �����ϸ� ����!
{
}

mstring::operator const char *(void) const
{
	return c_str();		// �Ļ� Ŭ���� private�� "string::c_str;" (�Լ� �̸��� ������ ��!).... �Ժη� �� ��
}

// �����Լ�s
void Gfunc(char * str)
{
	
}

void Gsub(const char * s)
{
	cout << s << endl;
}

void main(void)
{
	string str("Seoul");	// ()���� ���ڿ��� �����ڸ� ȣ���Ͽ� �ʱ�ȭ(?)�ϰ�, ���� �����Ҵ������ �ϴ�!
	cout << str << endl;

	Gsub(str.c_str());	// str�� string Ÿ���̰�, ���ڷδ� cahr *�� ���� ��!
						// string�� ����ȯ �Լ��� ���ٰ� ��!
						// string Ŭ�������� c_str �Լ��� �־ "�ּ�"�� �ο� ����!
	cout << ::strlen(str.c_str()) << endl;


	mstring mstr("Seoul");
	cout << mstr << endl;

	Gsub(mstr);
	cout << ::strlen(mstr) << endl;
	Gfunc( (char *)(const char *)mstr ); // char *�� ����ȯ ���ִ� �Լ��� �� ������ִ� ����� ������, 
					// const�� ���ٴ� ���� "�����ϰڴ�"��� ����ϴ� ���̹Ƿ� �ƿ� ������ ���ϵ��� 
					// �� ����� ���� ���� ��찡 ����.
					// ���� �ѱ�� ������.. ���� ĳ�������� ���� �ؼ� �ѱ�� ����,,,!

}

#endif





// 3.3 ���Ŭ������ �����Ϳ� ���� (�θ� ������...??)
#if 0
#include <typeinfo>
#include <iostream>
using namespace std;

class A
{
	int no;
public:
	A(){};
	A(int n) : no(n) {};
	virtual ~A(){ cout << "A Des..." << endl; }
	void sub(void) const { cout << no << endl; };
};


class B : public A
{
	char ch;
public:
	B(){};
	B(char c, int n) : A(n), ch(c) {};
	~B(){ cout << "B Des..." << endl; };
	void func(void);

};

void B::func(void)
{
	cout << ch << " ";
	sub();	// public���� A�κ��� ����� �޾ұ� ������ A������ public ����� �ڽ��� public���� ���� ����!
}

// �����Լ�
void Gsub(A * p)	// �θ��� �����ʹ� �ڽ��� ����ų �� �ֱ� ������ A�� B�� ����Ű�� �ϱ� ���ؼ��� A* Ÿ������
{
	p->sub();

	// C++������ RTTI(RunTime Type Information)�� ����.. ��Ÿ�ӿ��� Ÿ���� Ȯ���Ѵٴ� ��. C������ ������ Ÿ�ӿ��� �ϴ� ����..
	if (typeid(*p) == typeid(B))
	{
		((B *)p)->func();	// B�κ��� ������� ��ü�� �� �Լ��� ����ϰ� ����� �;�!
	}
}

void main(void)
{
	/*
	B bb('A', 5);
	bb.func();
	*/

	//A * p = new B;	// B * p = new B;�� �⺻�̰�����, �� ��ȯ �� �ϴ��� A�ε� ����!! ��� �޾��ݾ�?
					// �θ� �ڽ��� �����ͷ� ���� �� ���� ���? : void *�� ���(�� �� ���� ������ Ÿ���� ���!!)
					// �ʳ�(�̷���) ������� B�� � ������ �𸣱� ������!...........
					// ������ �� ��������� �ʴ´ٰ�.. ���輺�� �ֶ�....���� : �ڽ��� �Ҹ��ڰ� ������� ����!
					// A Ŭ������ ������ Ÿ�ӿ� � ������ �� �� ������, B�� �������� ����(?)
					// �׷��� ������ ����Ʈ �� ���� B�� �𸣹Ƿ� A�� ����Ű�� �Ǵ� ��!
					// => virtual ~A();��� �������ָ�, delete �ÿ� ~A�� �����̹Ƿ� ������ Ÿ�ӿ� �� �Ҹ��ڿ� ������� ����!
					//    �ٵ� runtime �� B�κ��� ������� ���̹Ƿ� B�� �Ҹ��ڸ� �����ϰ�, �ű⼭ �θ��� �Ҹ��ڸ� �ҷ� �θ��� �Ҹ��ڵ� �����...
					//   - ���� ���ε� ����!! (��Ÿ�ӿ� �����Ǳ� ������ �ӵ��� ���� ������ �� �ְ�����, �̷� ��� ȿ����!)

	//A * p = new B;
	//delete p;

	A aa(5);
	B bb('A', 10);
	Gsub(&aa);	// 5�� ��µ� ��
	Gsub(&bb);	// 10�� ��µ� ��
	cout << typeid(aa).name() << endl;	// Ÿ���� �̸��� �˷��ִ� �Լ���..����
	cout << typeid(&aa).name() << endl;
	cout << typeid(bb).name() << endl;
	cout << typeid(&bb).name() << endl;
}

#endif




// 3.4 ������(overriding)
#if 0
#include <iostream>
using namespace std;

class A
{
public:
	void sub(void);
};

void A::sub(void)
{
	cout << "class " << endl;
}


class B : public A
{
public:
	void sub(void);	// �Ϲ������� �θ��� �Լ��� �Ȱ��� ����Ѵ�!!
};

void B::sub(void)
{
	A::sub();
	cout << "B" << endl;
}



void main(void)
{
	B aa;	// BŸ�� ��ü aa
	aa.sub();
}

#endif

// ������ �߰�
// 3.6 �����Լ�(virtual function)
#if 0
#include <iostream>
using namespace std;

class CWnd
{
public:
	void OnLButtonDown(void);
	virtual void OnRButtonUp(void);	// ���� ���ε� : ������ �ð��� ȣ���� object�� �Һи��� ���, �̷��� ���ؼ� ���� �Լ� ����
	bool OnClose(void);
	void WndProc(void);
};

void CWnd::OnLButtonDown(void)
{
	cout << "left down";
}

void CWnd::OnRButtonUp(void)
{
	cout << "context menu";
}

bool CWnd::OnClose(void)
{
	cout << "close" << endl;
	return true;
}

void CWnd::WndProc(void)
{
	int evnt;

	while (1)
	{	
		do
		{
			cout << "Event :";
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cin >> evnt;
		} while (cin.fail() || evnt < 0 || evnt > 2);
		switch (evnt)
		{
		case 1:
			OnLButtonDown();
			break;
		case 2:
			OnRButtonUp();	// this->OnRButtonUp();���� this�� �����Ǿ� ����. this�� CWnd *Ÿ����..
							// �� �ڵ�� ���ſ� ��������� ȣ���ϰ� �ְ�, ����Mywnd�� �𸣴� �����ݾ�? (�̷� ������� ������ �Լ��� ȣ���ϰ� �ִ� ��!)
							// 
			break;
		case 0:
			if( OnClose() == true ) goto FIN;	// �������� �߰�ȣ �� �������� ��! (break�� �ϳ��ۿ� �� ���� �����ݾ�)
			break;
		}
	}
FIN:;
}


class MyWnd : public CWnd	// ������ ����� ����� �;�!
{
public:
	void OnRButtonUp(void);
};

void MyWnd::OnRButtonUp(void)
{
	cout << "My ";
	CWnd::OnRButtonUp();
}


void main(void)
{
	MyWnd wndw;
	wndw.WndProc();
}

#endif

// 
#if 0
#include <iostream>
using namespace std;

class A
{
	int no;
public:
	A(){};
	A(int n) : no(n) {};
	virtual ~A(){ cout << "A des..." << endl; };	// �Ϲ������� �θ��� �Ҹ��� �Լ��� virtual�� ��. - �ڽ��� �Ҹ��� �Լ��� ȣ����� ���� ��� ���ϱ� ����!
	void sub(void);
	virtual void func(void);
};

void A::sub(void)
{
	func();	// �̷��� ��ӵǾ� �����ǵǾ� ȣ��� ���� virtual�� ����
}

void A::func(void)
{
	cout << "A func" << endl;
}


class B : public A
{
	char ch;
public:
	B(){};
	B(char c, int n) : A(n), ch(c) {};
	~B(){ cout << "B des..." << endl; };
	void func(void);						// �������̵�(������)�� �Լ�
};

void B::func(void)
{
	cout << "B func" << endl;
}


void main(void)
{
	B bb;
	bb.sub();
	cout << sizeof(bb) << endl;	// �� 12B�ϱ�? 8B�� �ƴ϶�? : Ŭ���� �� ���� �Լ��� �����ϸ� ������ 4B ����!!
								// ���� �Լ��� 1500���� 4B �þ!������
								// => �ּҸ� ������ �迭�� �ʿ��ϰ�, �� �� �迭�� ������ "���� ������"�� �ʿ�!!
}
#endif




// 3.7 ���� �����Լ�(pure virtual function)




// 3.8 Ŭ���� ��� ������ : Ŭ���� �ȿ� �ִ� ��� ������ ����Ű�� ������ / static ����� ����ų �� ����
//						�� �����Ͱ� ���� �� ������ �� ����. (������ ++���ָ� 4 �����ϴµ�, �� ���� �������� �ִ�? ���� ���� ���ݾ�! �׷��� ���� ����!)
#if 0
#include <stdio.h>
#include <iostream>
using namespace std;

int go;

class A
{
public:
	int & ro = go;	// l-value ������ ������ ���������� ������ ���� �� �ֱ� ������ Ŭ���� ��� �����ͷ� ���� �Ұ�!
	int no;
	char ch;
	//A(){};
	//~A(){};
};

void main(void)
{
	//int & A::*rp = &A::ro;		// ���� ������ ��� �����͸� ����� �� ���ٰ� ���� ��!
	int A::* p = &A::no;		// ���� ������ �ּҸ� ������ �ֵ�? ���� �ȵȴ�.. �ٵ� ���� ������!!
	char A::* cp = &A::ch;		// ���� ���� ������?

	// cout�� ��� �����͸� �������� �����Ƿ� printf�� ����غ���!
	printf("p = %d, cp = %d\n", p, cp);	// ����ּҷ� ����! ������ �������� ����� �� ������� �ƴ�!
										// class A�� 8B��. ���� ������ int no�� 0��°, char ch�� 4��° �ּ�
										// �׷��� ���� 0, 4�� ����!
	// ������ �Ҵ� �� �Ǿ��µ� �ּ� ���� ���´�? �׷� ������ �ִٴµ� ���� �����ϱ�!?

	A aa;
	A * ap = &aa;
	aa.*p = 10;		// aa��� ��ü�� p�� ����Ű�� ����!
	aa.*cp = 'A';	// aa��� ��ü�� cp�� ����Ű�� ����!

	cout << ap->*p << ap->*cp << endl;
	cout << aa.*p << aa.*cp << endl;   // ���� ���� ǥ��!	=> but, ".*"�� ���׿����ڶ� �켱������ ���� ����!!
}
#endif





// �Լ� ������
#if 0
#include <iostream>
using namespace std;

void __cdecl sub(int n, char c)	// �Լ����� �⺻������ " __cdecl "�� ���� �� ���������� �����Ǿ� ����
{

}

void __cdecl func(int n, char c)
{

}

void main(void)
{
	int n;
	void(__cdecl * fp)(int, char);	// �Լ��� �̸��� �Լ��� �ּ�!! �Լ� �̸� �տ��� & �ٿ��� �ּҷ�! �� �ᵵ ������ �ٸ� ������� ���Ͻ����ֱ� ���� ���ֱ�� �Ѵ�!

	cout << "n : ";
	cin >> n;
	if (n == 0) fp = sub;		// n�� 0�̸� sub �Լ��� �ּҸ� ����,
	else if (n == 1) fp = func;	// n�� 1�̸� func �Լ��� �ּҸ� ���´�.
	// ��ġ ���� ���ε�ó�� �Լ� �����͵� ������Ÿ���� �ƴ� ��Ÿ�� �� � �Լ��� ����� �� ����!

	fp(5, 'A');

}

#endif

// Ŭ���� ��� �Լ� ������
// ȣ�� �Ծ��� __cdecl���� __thiscall�� �ٲ�
// void(__thiscall A::* fp)(int, char); �� �ٲ�
#if 0
#include <iostream>
using namespace std;

class A
{
public:
	void __thiscall sub(int n, char c);
	void func(void);
	void func(void) const;
	void func(int n);
};

void __thiscall A::sub(int n, char c)	// " __thiscall " �� �����Ǿ� ����
{
	cout << n << " " << c << endl;
}

void A::func(void)
{
	void(__thiscall A::* fp)(int, char) = &A::sub;// �����Լ��� �ִٸ� Ŭ���� ũ�⿡ �߰��Ǵ� 4B void ** ������ [0] ��� : �Լ� ����(?)
	(this->*fp)(10, 'E');						  // [1] ���	:	�Լ� ȣ��
}

void A::func(void) const
{
	cout << "func const" << endl;
}

void A::func(int n)
{
	cout << "func (int n)" << endl;
}


void main(void)
{
	A aa;
	void(__thiscall A::* fp)(int, char) = &A::sub;	// &�� �ݵ�� ��� ��!!!!!

	(aa.*fp)(5, 'A');	// object�� �ݵ�� �־�߸� ȣ���� ����!!! �Լ� �����Ϳ� �޸�
					// ".*" �����ڿ� "() �Լ� ȣ�� ������" �ΰ��� �����ڰ� �ְ�, .*�� �켱������ �����Ƿ� ()�� �������...

	(A().*fp)(6, 'Z');	// �ӽ� object�� �̿��Ͽ� call�� �ϴ� ��!

	aa.func();

	cout << endl;

	void(__thiscall A::* fp3)(void) const = &A::func;	// void A::func(void) const ȣ��

	void(__thiscall A::* fp2[3])(void) = 
	{
		&A::func,			// void A::func(void) ȣ��
		(void(__thiscall A::*)(void)) (void(__thiscall A::*)(void) const) &A::func,	// void A::func(void) const ȣ��
		(void(__thiscall A::*)(void)) (void(__thiscall A::*)(int)) &A::func
	};
	// => ȣ���� ����!?!?
	(A().*fp2[0])();	// void A::func(void) ȣ��
	(A().*fp2[1])();	// void A::func(void) const ȣ��
	(A().* (void(__thiscall A::*)(int))fp2[2])(5);
}

#endif





// ������ ��
// Ŭ���� �� ���� �Լ��� �θ�, �� �����Լ� �ּҸ� �ʱ�ȭ �ϱ� ���� ����Ʈ �����ڰ� �ڵ������� �����ȴ�!
// (���� ����� ��) ��� ������ �������ְ�, ����Ʈ ���� ���� �� ����Ʈ �����ڰ� �ڵ������� ������
#if 0
#include <iostream>
using namespace std;

class A;
typedef void(__thiscall A::* VFPTR)(void);

class A
{
	VFPTR m_vfptr;	// Ÿ�� ���� ����
	int no;
public:
	A() : m_vfptr(&A::func) {};
	A(VFPTR vfptr) : m_vfptr(vfptr) {};
	A(int n) : no(n) {};
	virtual ~A(){ cout << "A des..." << endl; };// �Ϲ������� �θ��� �Ҹ��� �Լ��� virtual�� ��. - �ڽ��� �Ҹ��� �Լ��� ȣ����� ���� ��� ���ϱ� ����!
	void sub(void);
	/*virtual*/ void func(void);
};

void A::sub(void)
{
	(this->* this->m_vfptr)();	// �̷��� ��ӵǾ� �����ǵǾ� ȣ��� ���� virtual�� ����
}

void A::func(void)
{
	cout << "A func" << endl;
}


class B : public A
{
	char ch;
public:
	B() : A((VFPTR)&B::func) {};
	B(char c, int n) : A(n), ch(c) {};
	~B(){ cout << "B des..." << endl; };
	void func(void);						// �������̵�(������)�� �Լ�
};

void B::func(void)
{
	cout << "B func" << endl;
}


void main(void)
{
	B bb;
	bb.sub();	//


}
#endif
