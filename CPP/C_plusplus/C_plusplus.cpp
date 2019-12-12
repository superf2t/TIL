#pragma warning (disable: 4996)

/***********************************************************************/
/*							[ 2019.09.30 월 ]						   */
/***********************************************************************/

// C++에서의 구조체 활용과 C와의 차이점
#if 0
#include <stdio.h>

/* 가만히 살펴보면, 구조체가 없으면 함수는 의미가 없고, 함수가 없으면 구조체의 값을 읽거나 쓸 수 없다.
즉, 둘의 관계는 불가분의 관계이다.
=> 그럼 같이 묶어서 관리할 수는 없을까? 그렇다면 재사용에 유리하지 않을까?
=> C++에 가서는 함수를 구조체 안에 둘 수 있도록 했다! */

struct st
{
private:	// 주로 member 변수/데이터들은 private 접근 권한을, 함수들은 public 접근 권한을 줌 (★재사용을 위함★)
	int no;
	char ch;

public:
	// 값을 담아오기 위한 함수
	void InitStruct(int n, char c)
	{
		if (!(n & 1)) n++;	// no가 항상 짝수가 아닌 홀수가 되도록 만들고 싶어서!!
		no = n;
		ch = c;
	}
	// 값을  ★읽기★ 위한 함수 -> const를 써줌 ㅋ(상수화 시켜줌! 즉, 바꾸지 못함. 하지만 C의 const는 완전한 상수화를 시켜주지 못한다고 함!)
	// 재사용을 염두에 둔다면, 이렇게 사용! 가독성이 높아짐.
	void PrintStruct(void) const	// ★const struct st * p가 인자로 없어서 가독성이 떨어질 수 있음. 이렇게 표현함으로써 알려줌!!
	{
		printf("You can read struct st type variable thanks to me! : ");
		printf("%d, %c\n", no, ch);
	}
};
// 이렇게 구조체 내에 있는 함수를 "지역 함수"라고 하고, 그 밖에 있는 함수들을 "전역 함수"라고 함!
// 그래서 C++ 입장에서 C의 모든 함수는 전역함수임!
// ★지역함수는 이름으로만 호출되지 않고, 자신을 호출해주는 주체가 있어야 함! (이 예시에서는 aa) => OBJECT에 의해 호출됨!!!!!
// 구조체 내에 포함되어 있기 때문에 Call by Addr을 위해 인수로 struct st * p를 줄 필요도 없고, p->no로 접근할 필요 없음

void main(void)
{
	/*struct*/ st aa;
	/* ★C++에서는 st 자체가 식별자가 아니라, 데이터 타입이다!!
	   (C언어의 기본형은 int, C의 많은 연산자들은 정수에 대해서는 관대하지만 다른 데이터 타입에는 적용할 수 없다는 편향성이 있음...
	   C++(객체지향)에서는 모든 데이터 타입을 정수형처럼 만들어 주어서 기존 라이브러리의 함수에 다 적용할 수 있도록,.,,(?)) */
	
	// aa.no = 4; => 이거 풀어보면 no에 빨간줄 그어질 것임. 구조체 내의 변수가 private이기 때문에 함부로 접근할 수 없음

	aa.InitStruct(5, 'A');	// ★구조체 내에 있는 함수이므로 aa.을 통해 호출해야 함!★
	aa.PrintStruct();
}
#endif


// cout
#if 0
#include <iostream>
#include <iomanip>
using namespace std;		// cout을 사용하기 위해 꼭 필요한 것!!

void main(void)
{
	cout << "kia~";
	cout << 10 << " " << 3.14 << 'A' << endl;
	cout << hex << 20 << endl;	// endl은 endline으로써 개행문자와 같은 기능을 함!
			// oct(8), dec(10), hex(16) 진수로!
	
	int no = 10;

	cout << "hello world." << endl; // printf(“hello world.\n”);
	cout << no << endl;
	cout << hex << 10 << endl; // oct, dec
	cout << left << setw(10) << "seoul" << "KOREA" << endl;
	cout << fixed << setprecision(2) << 3.141592653589793238 << endl;
}
#endif



// cin
#if 0
#include <iostream>
using namespace std;		// cout을 사용하기 위해 꼭 필요한 것!!

void main(void)
{
	int num;
	cout << "Input Decimal : ";
	cin >> num; // scanf("%d", &num); // call by address
	cout << "Hexa : " << hex << num << endl;
	cout << 30 << endl;	/* 얘도 Hexa로 나옴.. 근데 왜 그럴까? cout는 iostream 전역으로 선언이 되어 있음!!
						   그래서 바로 위의 cout과 같은 애라고 봐야 함!! 문장은 서로 다르더라도 같은 object! */
	cout << dec << 30 << endl; // 이렇게 다시 재지정 해줘야 Decimal 값을 출력함!


	const int n = 5;	// => ★컴파일 타임에 상수로 인식이 된다고 함!! (in C++)
	int ARR[n];		// 이게 가능하다니!!!ㅋㅋ

	int age;
	char name[30], addr[30];
	cout << "What's your name? : ";
	cin >> name;
	cout << "How old are you? : ";
	cin >> age;	// scanf("%d", &age);와 다르게 &값이 아니네!!!
	cout << "What's your address? : ";
	//cin >> addr;
	
	// 얘가 없다면, cin.getline은 위에 age를 입력한 후 친 개행문자(enter)를 받게 됨!! 그래서 버퍼를 비워주어야 함!
	cin.ignore();  // fflush(stdin); 얘랑 같은 역할!!
	cin.getline(addr, 30);	// 최대 29자까지 입력을 받음 (★버퍼 검사를 하면서!!! && ★개행/여백도 받을 수 있어!!)
	// gets(addr);은 편하기는 하지만, 버퍼 검사를 해주지 않음!
	// scanf("%s", addr); 또한 많이 사용하긴 했지만, 공백을 받을 수 없음


	cout << name << " " << age << " " << addr << endl;	
}
#endif


// 변수 선언
#if 0
#include <iostream>
using namespace std;		// cout을 사용하기 위해 꼭 필요한 것!!

int sub(int r) // int r = 5; // int r(5); // 인수전달 수식 == 선언과 동시에 초기화 (可)
{
	int imsi;

	return imsi = r * 2; // int imsi = r; // int imsi(r); // 리턴 수식 == 선언과 동시에 초기화 (可)
}


void main(void)
{
	int m;
	cout << sub(m = 5) << endl;
	cout << sub(int(5)) << endl;

	int array[] = { 10, 20, 30, 40 };
	for (int n : array) // 배열의 0번째 요소부터 순차적으로 순회하는 for문(현 위치에서 변수 선언 요함)
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



// Scope 연산자 - 1
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

void st::PrintStruct(void) const	// 이 const를 보고 후배들이 '아, 얘는 읽기만 하는 함수구나!' 라고 알 수 있음
{
	printf("You can read struct st type variable thanks to me! : ");
	printf("%d, %c\n", no, ch);
}
// 보통 구조체 안에는 함수를 선언만 해주고, 이렇게 함수의 정의는 밖으로 빼는 경우가 많음!
// 훗날 후배들이 알 수 있도록 st::라고 ★소속을 밝혀줌(scope를 밝혀줌!)★

void main(void)
{
	
}
#endif

// Scope 연산자 - 2
#if 0
#include <iostream>
#include <iomanip>
using namespace std;

int no = 10;

void main(void)
{
	int no = 5; // 선언과 동시에 초기화
	cout << no << endl;		// ★전역보다 지역을 우선★
	cout << ::no << endl;	// ★지역보다 "전역"을 우선★ (함수의 경우 더욱 자주 있는 일!) => scope를 붙여 전역임을 알려줌!
							// 뿐만 아니라 전역임을 쉽게 알려주기 위해서 같은 이름이 없더라도 ::(scope)를 붙이는 경우도 많다.
	/* 생각보다 전역과 지역을 구분해야 하는 일이 많음. 특히 함수에서!!
	   과거에 자신이 만들었던 라이브러리 함수를 그럼 갖다 버려야 하나? 아니다!!
	   cpp를 쓴다고 과거의 C코드를 버리는 것은 말도 안됨. 특히 재사용을 염두에 둔 cpp잖아? */
}
#endif



// 예약어 const : C와 다른 점을 보자!
#if 0
/*
// 예약어 const in C
#if 0
#include <stdio.h>

void main(void)
{
	//const int n;	// const를 썼다는 것은 상수라는 것이고, 그럼 const int n = 5와 같이 값을 지정해주어야 함!
	//char str[n];	// 그렇기 때문에 n을 요소 크기로 줄 수 없음!!!

	//const int n = 5;
	//n = 10;		// 에러 뜸 ㅋ

	const int n = 5;
	int * p = &n;
	*p = 10;
	printf("%d\n", n);	// 10으로 바뀌어서 출력됨. 컴파일러가 const임에도 제대로 인식해주지 못하는 것!(그럼 안되는데)
	// => 즉, C에서는 const로 완벽한 상수화를 시켜주지 못했다는 한계가 있음!!!
}
#endif
*/


// 예약어 const : C와 다른 점을 보자!
#include <iostream>
#include <iomanip>
using namespace std;

void main(void)
{
	// volatile: 컴파일러가 컴파일할 때 최적화 및 선처리를 하는데 그것을 못 하게 해주는 것.
	// volatile const int n = 5; 라고 선언을 해준다면, 마지막 출력 부분이 달라질 것! (10, 10으로 출력됨!)

	const int n = 5;
	//char str[n];	// ★컴파일 시간에 n이 상수값인 5(const)라는 값을 가지므로 이러한 선언 가능!!
	//int *p = &n;	// ★n의 번지형은 자료형이 const int *이므로 타입이 달라서 에러가 뜸!!!★

	//const int *p = &n; // 선언 시 얘는 에러는 뜨지 않음.
	//*p = 10;			// ★하지만 바꿀 수 없는 상수 값을 바꾸려고 하는 접근에는 에러가 뜸!!

	int *p = (int *)&n;
	*p = 10;			
	cout << n << endl;	// n은 const이므로 바뀌지 않음. n은 바뀌지 않고 5로 출력
	cout << *p << endl;	// p는 n을 캐스팅해서 "바꾸고야 말 것이다!" 라는 의지가 있었음. *p는 바뀌어 10으로 출력
}
// => ★★ 포인터 사용할 때 예약어 const를 꼭! 꼭! 사용해주자!!!
#endif

#if 0
#include <iostream>
#include <iomanip>
using namespace std;

void main(void)
{
	int n = 5, k = 6;

	// 둘은 다른 표현!!
	const int * p;	// p가 가리키는 대상인 *p가 const, 즉 상수로 보겠다는 것! 그 대상이 상수가 아니더라도

	//int * const q;	// q 자체가 const, 즉 상수로 보겠다는 것 -> 그렇기 때문에 q는 현재 값이 없으므로 에러가 뜸.
	int * const q = &k;	// -> 그래서 이렇게 선언과 동시에 초기화를 해주어야 함!
	// 그런데 q가 가리키는 대상이 상수라면?
	const int * const r = &k; // -> 이와 같이 선언을 해주어야 함;;

	p = &n;
	// *p = 10;		=> 이미 위에서 p가 가리키는 대상을 const로 봐주겠다고 했기 때문에 값 변경 불가. n = 10;과 같이 n 자체적으로 값 바꾸는 것은 가능ㅋ
	cout << *p << endl;

	*q = 100;		// q 자체가 const이지만, q가 가리키는 대상이 const인 것은 아님!!
	//q = &n;		=> 그래서 얘는 에러가 남!	
	cout << *q << endl;

	sub(&p);
	func(&q);
}

// t : 나는 포인터 변수야(t 바로 앞에 있는 *, 즉 t는 주소값이라는 뜻!). 그런데 내가 가리키는 것은 int * const 야!
void func(int * const *t)		// ★인자 타입에 주목★
{

}

// t : 나는 포인터 변수야(t 바로 앞에 있는 *, 즉 t는 주소값이라는 뜻!). 그런데 내가 가리키는 것은 const int 야!
void sub(const int * *t)		// ★인자 타입에 주목★
{

}
/*
< ★ 정리 !! ★ >
const int * onlyread; // 읽기만 할거야
int * const onlyyou = &data; // 오직 data만 가리킬거야, 난 변하지 않아.
int const * icp = &cdata; // 가리키는 데이터는 const int(int const)형이야
const int * const readonlyyou = &data; // data만을 가리키고 그 대상을 읽기만 할거야.
*/
#endif

// 관련 예제 (함수의 return 타입이 const? : 리턴이 되면서 값이 변하는 것을 막기 위함)
#if 0
#include <iostream>
using namespace std;

int * sub(void);

void main(void)
{
	// *sub();	// *(변수 n의 주소) => 리턴되는 변수의 주소의 값!?
				// => n은 지역 변수이고, 함수가 종료되면서 Stack에 있던 것들이 다시 반환됨. 그래서 읽히지 않음!!
	cout << *sub() << endl;	// 아래와 같은 경우, 주소가 가리키는 값을 읽을 수 있게 됨!!
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
*/					// => 이와 같은 경우, 리턴 타입이 const이므로 읽기만 할 수 있고, 데이터 가리킬 수 없음..(?)
// ★★ return 타입이 const인 경우, 리턴이 되면서 값이 변하는 것을 막기 위함!! ★★
#endif



// ★★ 오버로딩 : 함수의 중복 정의 ★★
#if 0
#include <iostream>
#include <stdlib.h>	// 동적 할당을 위해!
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

void Swap(double * p, double * q)	// 파라미터의 타입이 다르므로 오버로딩 가능!!
{
	double tmp;

	tmp = *p;
	*p = *q;
	*q = tmp;
}


//  ★★
void Swap(void *a, void *b, size_t size)	// size_t는 unsigned int 타입임
{
	void * tmp = malloc(size);	// 인자인 size는 runtime 때 들어 옴. 그렇기 때문에 동적 할당을 통해 메모리를 가져야 함!
	if ( tmp == (void *)0x0 ) return;

	Memcpy(tmp, a, size);
	Memcpy(a, b, size);
	Memcpy(b, tmp, size);
	
	free(tmp);	// free 안하면 메모리 누수 날 수도
// cf> 최근 고급 언어들은 free를 굳이 해주지 않아도 알아서 해주는 스마트 포인터(C++), 가비지 컬렉터(JAVA) 등의 기능 지원
}

void Memcpy(void * p, const void * q, size_t cnt)	// 왜 const를 써줄까? : 읽어주기 위한 인자이기 때문!!
{
	char * dest = (char *)p;
	const char * src = (char *)q;

	for ( ;cnt > 0; cnt--) *dest++ = *src++;
}
//  ★★
#endif

// 중복정의(이어서)
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
	stream c;		// 딱 보면, cout처럼 들어오는 데이터의 타입에 맞게 알아서 출력을 해주는 것을 볼 수 있음!
					// ostream도 이렇게 정의가 되어 있을 것이라는 것을 알 수 있다!
					// 특히 같은 이름인데 다른 타입들에 다 대비(?)가 되어 있는 것을 보아 중복정의가 되어 있을 것!!
	c.printf(5);
	c.printf(3.14);
	c.printf("seoul");
}

#endif



// 디폴트 파라미터
#if 0
#include <time.h>
#include <iostream>
using namespace std;

void DisplayDate(int day, int month = 12, int year = 2019);	// 함수 선언 시 디폴트 파라미터를 정의해주어야 함!
void DisplayDate(void);	// 이런 거는 중복정의 불가함!!

void main(void)
{
	DisplayDate(30);			// 2019/12/30
	DisplayDate(30, 9);			// 2019/9/30
	DisplayDate(30, 9, 2018);	// 2018/9/30

	DisplayDate();
}

void DisplayDate(int day, int month, int year)	// ★디폴트 파라미터 값은 오른쪽에서부터! 디폴트 파라미터는 함수 선언 시 정의!★
{												// Argument pass order는 오른쪽에서부터 왼쪽으로 가기 때문! (C와 똑같음!)
	cout << year << "/" << month << "/" << day << endl;
}

void DisplayDate(void)
{
	time_t lt;
	tm *ct;
	tm tct;		// tm은 연월일을 담는 구조체 타입임!

	time(&lt);	// time 위에 커서를 올려 놓으면 "time_t __cdecl(time_t * Time)" 이라고 뜸. 즉, 인자로 time_t *가 들어가야 함!
	
	ct = localtime(&lt);	// 위의 과정에서 lt
	DisplayDate(ct->tm_mday, ct->tm_mon, ct->tm_year + 1900);	// 오늘 날짜 출력하는 함수!

	localtime_s(&tct, &lt);	// 같은 값이 나옴!
	DisplayDate(tct.tm_mday, tct.tm_mon, tct.tm_year + 1900);	// 오늘 날짜 출력하는 함수!
	// 이 때 DisplayDate 함수는 바로 위에 정의한 void DisplayDate(int day, int month, int year)임!!
}
#endif



// ★★ Reference ----- Union이랑 비슷 : 같은 공간을 다른 이름으로 부름! (별명) ★★
// 별도로 별명에 대한 선언이 있어야 함! by using &
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
	int & rn = n;	// ★ 번지(&)는 자료형(l-value)에 올 수 없음!! 즉, 이 &는 참조의 &!!!

	cout << rn << endl;
	rn = 10;
	cout << rn << endl;
	cout << &n << " " << &rn << endl;	// 같은 주소 값이 나올 것! 또 다른 공간이 할당되는 것이 아니기 때문!!

	subv(n);
	cout << n << endl;	// (Call by Value) 값이 바뀌지 않고 10으로 그대로 유지!

	subp(&n);
	cout << n << endl;	// (Call by Address) 주소값을 통해 접근 -> 값이 변화함! => 그래서 입력 받는 함수들(scanf, gets, fgets들이 다 주소값을 인자로 받는 것!!)

	subr(n);			// ★(Call by Reference) 값이 변화함!!!!
	cout << n << endl;
	// 하지만 주소로 접근하지 않았는데 값이 변화되네...
	/*
	★그래서 const를 사용하게 된다!
	Like => void subr(const int & r) => 함수 내에서 "r = ~~"와 같이 r 값을 변경시킬 수 없다!! 에러 뜬다!
	*/

	cout << vsub(n) << endl;	// vsub 함수의 리턴 타입은 int.	// int imsi = n;
	cout << psub(n) << endl;	// psub 함수 리턴 타입은 int *.	// int * insi = &n;
	rsub(n) = 0;												// int & imsi = r;	: imsi는 변수 r의 변수(또 다른 공간 할당 X!!!!)
	/*
	위와 마찬가지로 값을 변화시키고 싶지 않으면,
	Like => const int & rsub(int & r)와 같이 사용!!!
	*/
	cout << n << endl;
	// ★ n의 Reference(별명)인 r이 바로 위에서 r = 0;으로 값이 변경되었고, 그렇기 때문에 n 또한 0으로... ★
}

void subv(int k)	// int k = n;
{
	k = 0;
}

void subp(int * t)	// int * p = &n;
{
	*t = 100;

}

void subr(int & r)	// int & r = n;	=> 함수 안에서 인자로 받은 n을 r이라고 부르겠다!
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
예]
// 포인터 참조
const char * cstr = "seoul";
char * & rstr = (char * &)cstr;
// *rstr = 'A'; // 읽기 전용 메모리에 기록하기 때문에 런타임 오류 발생
rstr = "korea";
const char * const & rcstr = cstr; // 다른 주소를 갖지 않기 위한 참조
// rcstr = "KOREA"; // 변경불가

예]
// 배열, 배열포인터, 포인터배열, 더블포인터 참조
char str[] = "seoul";
char (& rstr)[6] = str; // 배열참조의 경우 요소 개수를 상수로 명시하고 괄호사용

char name[][5] = {"kim", "park"}; // 2차원배열
char (& rname)[2][5] = name; // 모든 차원에 배열의 크기를 상수로 명시 (의미 : rname은 name의 별명!)
char (* pname)[5] = name; // 배열포인터
char (* & rpname)[5] = pname; // 배열포인터의 참조

const char * cname[] = {"kim", "park"};
const char * (& rcname)[2] = cname; // 포인터배열의 참조
const char * * pcname = cname; // 더블포인터
const char * * & rpcname = pcname; // 더블포인터의 참조

예]
// 다른 크기로 참조
long data = 0x12345678;
short & k = (short &)data;

short(& word)[2] = ( short(&)[2] ) data;
char (& byte)[4] = ( char(&)[4] ) data;
*/
#endif

// Reference(이어서)
#if 0
#include <iostream>
using namespace std;

void main(void)
{
	long data = 0x12345678;
	// 4바이트
	long & word = data;	// 나는 long 타입으로 참조(&)할거야. word라는 이름으로. 무엇을? data를!!
	// 2바이트
	short & sword = (short &)data;
	short (& asword)[2] = (short (&)[2])data;
	char(&casword)[4] = (char(&)[4])data;

	cout << hex << word << endl;
	cout << hex << sword << endl;	// 0x5678이 나옴! 리틀 엔디안으로
	cout << hex << asword[1] << endl;
	cout << hex << (int)casword[2] << endl;	// 34가 뽑힘...ㄷㄷ
}
#endif



// inline 함수
// ★ 함수화는 재사용을 염두에 둔 것!! 미래에 호출되어 사용되기 위해 함수를 만드는 것!! ★
/* => 하지만 함수를 호출하기 위해 기존의 정보를 저장해 두는 prefix 코드와 함수가 끝난 후의 suffix 코드가 필요하기 때문에
	  함수 호출 자체가 최적화에 최적인 것은 아님! (오버헤드 발생)
*/






// 입력 오류 처리
#if 0
#include <iostream>
using namespace std;

void main(void)
{
	int score;
	char * grade = "FFFFFFDCBAA";

	do
	{
		cout << "점수를 입력해주세요! : ";
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail());
		cin >> score;
	} while (cin.fail() || score < 0 || score > 100);
			// 문자 등 처리,  음수 처리  ,  100점 초과 처리

	cout << grade[score / 10] << endl;

	/*	// < 안 좋은 코드 : 데이터가 늘어나는 만큼 코드도 많이 늘어나게 되는... >
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




// 동적 메모리 연산자
// 우리는 언제 malloc을 사용했나? : 데이터의 크기를 컴파일 시간에 결정할 수 없었을 때
// C에서의 malloc은 함수이고, C++에서의 new는 연산자이다!!! (C++에서도 C에서처럼 malloc 사용 가능!ㅋ 하지만 사용할 수 없는 경우도 있어..)
// => new는 malloc이 할 수 없는 일까지도 한다!! 근데 그게 무엇!?!?
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

	cout << *(int *)(acp - 16) << endl;	// 13이 출력될 것!!


	delete cp;
	delete cpp;
	delete acp;
}

#endif





// ★ 문자열 입력 받는 갯수만큼 + 1 할당 ★
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
		cin.getline(temp, 100);	// 최대 99자까지 받고, 그보다 초과되는 부분은 무시됨!!
		// 얘가 cin >> temp;와 비슷한데, 100 - 1자까지 받도록 한다!!

		len = strlen(temp);
		str[i] = new char[++len];	// NULL문자까지 포함하기 위해서!

		strcpy_s(str[i], len, temp);	// 동적할당이므로 인수를 3개 써야 함!!
	}

	for (i = 0; i < cnt; i++)	cout << str[i] << endl;

	for (i = 0; i < cnt; i++)	delete [] str[i];	// ★new + 배열일 때는 delete + 배열로 반환하자!1
	
	delete [] str;
}
#endif





// 이름 없는 공용체
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




// 공간이름(namespace)과 예약어 using
// 과거의 코드를 그대로 가져다 쓰면, 내가 쓰던 변수 이름과 가져온 코드의 이름이 중첩되는 경우가 있어!
// => 다른 공간에 두어 중첩을 피함!
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
	sub();		// A라는 공간의 sub임!!

	using namespace B;
	sub();		// 얘는 에러다!! 이미 위에 A 공간을 사용하겠다고 선언을 했기 때문에...
	B::sub();	// 그래서 B의 scope를 밝혀야 함!!
}

/*
void sub(void)
{
	cout << no << endl;
}*/
#endif

// 예시
#if 0
#include <iostream>
#include <iomanip>
using namespace std;

void main(void)
{
					// 10자리
	cout << left << setw(10) << "Seoul " << 10 << endl;
			// 왼쪽 정렬

	int left = 5;
	cout << left << setw(10) << "Seoul " << 10 << endl;	// 얘는 left가 변수이고, 5로 초기화 되어 잇기 때문에 5가 출력 됨

	cout << std::left << setw(10) << "Seoul " << 10 << endl; // 혼동을 막기 위해 scope 설정!
}
#endif




// 1.16 C++ 구조체를 이용한 요일 출력
#if 0
#include <iostream>
#include <time.h>
using namespace std;

#define IsLeap(Y) ((!(Y % 4) && (Y % 100)) || !(Y % 400))


struct Date
{
private:
	int year, month, day, week;
	void CalcDate(void); // 요일 계산하는 멤버함수
public:
	void InitDate(void); // 년, 월, 일 정보를 시스템에서 읽어오는 멤버함수
	void InitDate(int d, int m, int y = 2019); // 년, 월, 일 정보를 인수로 전달받는 멤버함수
	void DisplayDate(void); // 년, 월, 일, 요일 출력하는 멤버함수
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

void Date::InitDate(void) // 년, 월, 일 정보를 시스템에서 읽어오는 멤버함수
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

	::time(&lt);				// 전역 함수 호출
	::localtime_s(&cur, &lt);	// 전역 함수 호출
	year = cur.tm_year + 1900;
	month = cur.tm_mon + 1;
	day = cur.tm_mday;
	week = cur.tm_wday;			// 0 = 일 ~ 6 = 토
	*/
}

void Date::InitDate(int d, int m, int y) // 년, 월, 일 정보를 인수로 전달받는 멤버함수
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

void Date::CalcDate(void) // 요일 계산하는 멤버함수
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

void Date::DisplayDate(void) // 년, 월, 일, 요일 출력하는 멤버함수
{
	const char * strweek[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	cout << year << '/' << month << '/' << day << '/' << strweek[week] << endl;

	/*
	cout << year << "/" << month << "/" << day;
	cout << " (" << week << ") " << endl;
	*/
}
#endif
// 선생님
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




// 1.17 C++ 구조체를 이용한 성적처리
#if 0
#include <iostream>
#include <iomanip>
#define MAX_NAME	(10)
using namespace std;

#define ScoreRng(S) (((S >= 0) && (S <= 100)) ? (S) : (0))

struct Score
{
private:
	char * name; // 동적 할당
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
	student = new Score [num];		// ★ 구조 익히기

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

void Score::Init_Score(void)	// ★
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
		S[i].name = new char[++len];	// NULL문자까지 포함하기 위해서!
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

void Score::Delete_Score(void)	// ★
{
	delete [] name;
}
#endif

// 선생님
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
/*							[ 2019.10.01 화 ]						   */
/***********************************************************************/

// Class!!!!
// 구조체의 default는 public(개방형), Class는 Private이 기본형!! -> 재사용성이 더욱 좋다.

// 2.1 Class
#if 0
#include <iostream>
using namespace std;

class A
{// 접근지정자를 설정해주지 않으면 default로! -> private로
	int no = 5;	// int no = 5;는 "초기화?" => Nope! default 값을 지정해준다는 의미.
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
	A aa;		// => 이렇게 개체가 선언( "선언" means "기억 공간에 할당해!" )됐을 때 비로소 공간이 할당 됨!

	cout << sizeof(aa) << endl;	// size가 12 == int no(4B)와 int sum(4B)를 기준으로 이것의 배수 -> 12B (함수는 공간 차지하지 않음!!)

	aa.sub();
}
#endif



// 2.2 생성자 함수 (Constructor) : 초기화를 위함!
// 다양한 생성자 함수 호출 및 할당 방법
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
	A aa;	// Ctrl + F5 눌러보면, 디폴트 생성자가 실행됐음을 알 수 있다 => 클래스 개체 선언될 때, 생성자 호출됨!!
			// 원래 "A aa = A();"
			// "A aa();"와 같이 사용하지 않는 이유는 컴파일러에서 A타입의 리턴을 갖는 함수 aa를 찾는 것으로 받아들이기 때문!
	cout << endl;

	A bb(5); // 생성자 호출의 기본형은 원래 "A bb = A(5);" 이런 식임. 이거봐 함수 호출하는 방식이랑 똑같잖아!
			 // 이런 것들을 보아 생성자의 이름을 클래스의 이름과 똑같이 정해준 이유가 있군
	cout << endl;

	A cc(6, 'A'); // 생성자 호출의 기본형은 원래 "A cc = A(6, 'A');" 이런 식임.
	cout << endl;

	A arr[3];	// 0, 1, 2번째 클래스 배열이 모두 default 생성자 호출
	cout << endl;

	A brr[3] = { A(), A(5), A(6, 'B') };	// 각각 원하는 생성자 실행시킬 수도 있음!
	cout << endl;

	A crr[3]{ A(), A(5), A(6, 'B') };
	cout << endl;

	A * ap = new A(5);	// 동적 할당도 가능!
	// A * ap = (A *)malloc(sizeof(A));  =>  malloc으로 동적할당하는 것은 생성자 호출을 할 수 없어!
	// malloc은 공간의 할당은 해주지만, 생성자 호출 불가능. new와 delete를 이용하는 것이 더욱 효율적!
	delete ap;
	cout << endl;

	ap = new A[3]{A(), A(5), A(6, 'A')};	// Object는 3개 만들어지는 것

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
	int no;		// 멤버 변수만 있고, 생성자 함수가 없는 경우!? => 그래도 컴파일러가 Default Constructor를 만들어 준다고 함.
public:
	//A(){};  없다고 해보자
	A(int n);	// 이것만 있다고 하면? => "기본 생성자가 없습니다." 라는 에러 메세지가 뜸
};				// => 생성자가 아무 것도 없을 때는 기본 생성자를 제공하지만, 그렇지 않는 지금과 같은 경우에는 기본생성자가 제공되지 않음!!

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


// 1.16(구조체)를 클래스로!	=>	에러 뜨는데 다시 보자..ㅠ
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
	Date(void); // 년, 월, 일 정보를 시스템에서 읽어오는 멤버함수
	Date(int d, int m, int y = 2019); // 년, 월, 일 정보를 인수로 전달받는 멤버함수
	void CalcDate(void); // 요일 계산하는 멤버함수
	void DisplayDate(void); // 년, 월, 일, 요일 출력하는 멤버함수
};

static int days[12] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 };

void main(void)
{
	Date today;		// 바로 기본 생성자 함수 호출 가능
	today.DisplayDate();

	Date oneday(19, 12);
	oneday.DisplayDate();
}

Date::Date(void) // 년, 월, 일 정보를 시스템에서 읽어오는 멤버함수
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

	::time(&lt);				// 전역 함수 호출
	::localtime_s(&cur, &lt);	// 전역 함수 호출
	year = cur.tm_year + 1900;
	month = cur.tm_mon + 1;
	day = cur.tm_mday;
	week = cur.tm_wday;			// 0 = 일 ~ 6 = 토
	*/
}

Date::Date(int d, int m, int y) // 년, 월, 일 정보를 인수로 전달받는 멤버함수
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

void Date::CalcDate(void) // 요일 계산하는 멤버함수
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

void Date::DisplayDate(void) // 년, 월, 일, 요일 출력하는 멤버함수
{
	const char * strweek[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	cout << year << '/' << month << '/' << day << '/' << strweek[week] << endl;

	/*
	cout << year << "/" << month << "/" << day;
	cout << " (" << week << ") " << endl;
	*/
}
#endif



// 2.3 소멸자 함수(Destructor)
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
	delete ap;	// 할당이 반납되면서 이 ap->~A를 호출하게 될 것!
	*/





	A * bp = new A[3];
	cout << *(int *)((char *)bp - 16) << endl;	// 엥? 16바이트 전의 메모리에 할당 받은 메모리 정보가 없는데?
												// 소멸자가 있는 클래스로부터 동적 할당될 때는 개체 개수 정보가 있어야 하므로 아래와 같이 됨.
												// 하지만 소멸자를 없애면, 전과 동일하게 16바이트 전의 메모리에 개체들의 할당 받은 메모리 담겨 있음
												// 소멸자가 없다는 것은 굳이 개체 마무리 작업을 해야 할 의무가 없기 때문!
												// 그리고 생성자와 다르게 소멸자는 자동으로 만들어지지 않음!!

	cout << *(int *)((char *)bp - 20) << endl;	// 할당 받은 메모리 바이트 수가 담겨 있음 (16바이트)
						//=> Object 3개 12바이트와 개체 개수 정보가 담겨 있는 int 4바이트 => 합쳐서 16바이트
	
	cout << *(int *)((char *)bp - 4) << endl;	// Object의 개수 정보가 담겨 있음 (3개)
	
	delete [] bp;	// 이렇게 [] 배열로 delete를 해주면 이런 개체 개수 정보가 담겨 있는 메모리도 반환 가능!!!
	// 1) bp가 클래스 타입인가? 2) 클래스 안에 소멸자가 있는가? 3) A 클래스가 지금이 아니라 미래 만들어진다면 어떻게 할까?
	// 이런 것들을 다 판단해주어야 delete해줄 때 []를 넣어야 할지 말지 알 수 있게 된다. 귀찮으니까 "new [배열]"에는 다 delete [] 해주자!!


	/*	// 반환 방법이 다름을 알아랏!!
	ap = new A[3]{A(), A(5), A(6, 'A')};
	delete[] ap;


	A * bp[3] = { new A(), new A(5), new A(10, 'A') };
	for (int i = 0; i < 3; i++) delete bp[i];
	*/

	cout << "end main" << endl;

	// aa.~A 호출할 것
	// bb.~A 호출할 것

	// 선언과 생성자 호출, 할당, 반납과 소멸자 호출 모두 Runtime에 이루어짐!
}
#endif

// 이어서
#if 0
#include <iostream>
using namespace std;

class A
{
	int no = 5;	// int no; 이렇게만 해놓고 기본 생성자를 따로 만들지 않는다면, 디스어셈블리로 이동했을 때 생성자가 호출되지 않은 것을 볼 수 있음.
public:			// 하지만 int no = 5;라고 (초기화 아님!!) default 값을 지정해준다면, 기본 생성자 없어도 자동으로 컴파일러가 호출함!! 오오오
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




// 2.4 예약어 this
#if 0
#include <iostream>
using namespace std;

class A
{
	int no;
public:
	A(){};
	A(int n);
					// 특별히 마무리할 작업이 없다면, 소멸자는 만들 필요 없다.
	void sub(int dummy);
};

A::A(int n)
{
	no = n;		// this->no = n; 과 같은 표현임!! default이니까 생략해서 사용했던 것임

	cout << (*this).no << endl;

	cout << this << endl;		// this는 멤버함수 내에서만 사용할 수 있음!! 생성자는 당연히 멤버함수
								// 출력되는 것은 이 함수를 호출한 Object aa의 "주소"이다!
}

void A::sub(int dummy)		// "void __thiscall A::sub(int dummy)" 얘가 디폴트 형태임
{
	cout << "16B 전의 값: " << hex << *(int *)((char *)&dummy - 16) << endl;
	//*(int *)((char *)&dummy - 16) = 0;	: 이렇게 해주면 this 가 0이 됨을 알 수 있다. 즉, 같은 주소에 있다는 것을 알 수 있다
	// this는 상수처럼 사용되기 때문에 this = 0;과 같이 this에 값을 대입해주려 한다면 l-value 오류!
	cout << this << endl;
	cout << "==========둘이 같아?==========" << endl;
}


void main(void)
{
	A aa(15);		// aa.A(15)라고 aa라는 Object가 생성자를 호출한 것!
	cout << &aa << endl;
	aa.sub(0);

	A bb;
	bb.sub(0);
}

#endif

// C에서는 this 예약어는 없지만, 주소를 인자로 넘겨줌으로써 사용했다.
// 그리고 밑은 그것의 예시이다.
// 클래스는 그냥 앞에서 aa.~~();와 같이 호출을 할 수 있기 때문에 주소로 넘겨줄 필요는 없다.
#if 0
#include <stdio.h>

struct st
{
	int no;
	char ch;
};

void InitStruct(struct st * this, int n, char c); // main 안에서 함수 선언 가능 ㅋㅋ 단, main 안에서만 사용 가능!
// 값을 담아오기 위한 함수
void PrintStruct(const struct st * this);
// 값을  ★읽기★ 위한 함수 -> const를 써줌 ㅋ(상수화 시켜줌! 즉, 바꾸지 못함.
//										  하지만 C의 const는 완전한 상수화를 시켜주지 못한다고 함!)
// 재사용을 염두에 둔다면, 이렇게 사용! 가독성이 높아짐.

/* 가만히 살펴보면, 구조체가 없으면 함수는 의미가 없고, 함수가 없으면 구조체의 값을 읽거나 쓸 수 없다.
즉, 둘의 관계는 불가분의 관계이다.
=> 그럼 같이 묶어서 관리할 수는 없을까? 그렇다면 재사용에 유리하지 않을까?
=> C++에 가서는 함수를 구조체 안에 둘 수 있도록 했다! */

void main(void)
{
	struct st aa;	// 구조체 변수 선언!
	printf("size of struct st? = %d\n", sizeof(aa));	// 가장 큰 바이트인 int를 기준으로 그의 배수(=> 8바이트)

	InitStruct(&aa, 5, 'A');	// Call by Address
	PrintStruct(&aa);			// 구조체는 크기가 커서 Call by Value는 잘 사용 안함!
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
	return *this;		// A imsi = * this;	이렇게 임시 개체가 만들어짐!!
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
	// 하지만 Reference로 타입을 맞춰서 주면 개체가 하나만 만들어짐!! A aa;할 때
}

// Destructor에서 출력이 네 번이나 되는 것으로 보아 개체가 4번이나 만들어졌다는 것을 알 수 있다.
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
//	return *this;		// A imsi = * this;	이렇게 임시 개체가 만들어짐!!
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

// cout의 구조를 printf로 만든 예시로 보기
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

	c.printf(5).printf(3.14).printf("seoul");	// cout은 이렇게 되어 있음!!
	// printf 함수가 value로 리턴했다면 그 때마다 계속 계속 개체를 생성했을 것. 비효율
}

#endif




// 2.5 포함된 개체(embedded object)와 콜론(colon, : ) 초기화
#if 0
#include <iostream>
using namespace std;

class A
{
	int no;
public:
	A(){ cout << "A Default Constructor" << endl; };
	A(int n) { no = n; cout << "A int Construct" << endl; };					// 그냥 내부에서 정의
	void sub(void) { cout << no << endl; };	// 클래스 멤버 변수를 읽기 위한 함수
};

class B
{
	char ch;
	A aa;	// 얘가 바로 "embedded object"임!!! 이 때 클래스 B를 "surrounded class"라고 함
public:
	B();
	B(char c, int n);
	void func(void);
};

B::B() //: aa()	// 컴파일러는 이렇게 인지를 하기 때문에 포함된 개체인 aa에 대해서 먼저 생성자 호출 (암묵적인 콜론 초기화)
	   //: aa(0)	//과 같이 "명시적인 콜론 초기화"도 가능! -> A(int n); 생성자로 가게 됨 ㅋ OhOh~
{ 
	cout << "B Default Constructor" << endl;
}

B::B(char c, int n) : aa(n),	// 여기도 마찬가지로 "콜론 초기화", 즉 aa의 생성자 초기화가 됨!!
						ch(c)	// ★얘도 콜론 초기화. 이 함수 내부에서 "ch = c;"는 대입! 둘은 서로 다름! 콜론 초기화가 더욱 효과적!
{ // B클래스는 A 멤버 변수에 마음대로 접근할 수 없음. 하지만 클래스 A를 보면 A(int n); 생성자가 있음!! 이것을 통해 접근!
	
	//aa = A(n);	// A라는 이름의 생성자 함수를 호출, 이에 따라 임시 오브젝트가 만들어 지고, 이는 곧 이름 없는/빈 Object.
				// => 좋은 방법의 초기화가 아님!! => ★콜론초기화가 더욱 효과적!!
	//ch = c;		// ★얘도 마찬가지로 효과적이지 못함! 콜론 초기화!
}

void B::func(void)
{
	cout << ch;
	aa.sub();	// B에서는 A의 private(default) 멤버 변수에 직접 접근 못 하므로 sub라는 public 함수 호출!
}

void gsub(B rb)	// 얘는 전역함수
{

}

void main(void)
{
	B bb;	// B 클래스로부터 개체를 만들었는데 포함된 개체의 생성자 또한 만들어짐!
			// (위 줄에 커서를 놓고 Ctrl + F10을 통해 디버깅 모드로, 그리고 F11을 누르며 어떤 순서로 실행되는지 보아라!)
			// 만약 A 클래스의 기본 생성자를 만들어주지 않았다면(or 없다면) 런타임 에러가 난닫고 함!
			// => 교훈 : 무조건 기본 생성자는 항상 만들어 두도록 한다! 아무런 코드가 없다고 하더라도!

	B bibi('A', 10);

	bibi.func();

	//B('B', 5);	// 생성자 함수를 호출한 것이지만, 멤버 함수를 호출할 수 있다는 것은 그 Object뿐!!
	B('B', 5).func();	// ★하지만 바로 .을 찍어서 함수를 호출했다면, 이건 다른 Object가 만들어진 것이라고 볼 수 있음!
	gsub(B('B', 5));	// ★임시 Object를 넘겨준 것이고, 함수가 끝나면 이 임시 Object도 소멸됨! (Stack)
}
#endif

// 참조형 멤버 데이터와 const 멤버 데이터의 콜론 초기화
#if 0
#include <iostream>
using namespace std;

int go = 5;

class A	// 이 클래스는 총 12바이트임.. 참조형 변수는 컴파일러에서 포인터랑 똑같이 인식됨. 누군가를 받아줘야 하기 때문에 4B
{
	int no = 5;
	int & ro = no;	// 최근 컴파일러에서는 클래스 내부에서 기본값을 지정해줄 수 있음!! -> 콜론 초기화 깜빡 잊고 안해도 이 Default value를 갖게 됨!! (클래스 개체 생성 시!)
					// ★하지만 이것이 "초기화"가 아니라 기본값을 주기 위함이라는 것을 알아야 함!!!
	const int co = 7;
public:
	A();
	A(int n);

};

A::A() : ro(go), co(5)	// 참조형 멤버 데이터와 const 멤버 데이터는 콜론 초기화 필수!! 안 해주면 Compile Error!
{
	// 이 안에다가 대입해주면 안되나? 안된다! 얘는 대입이고, 이는 콜론 "초기화"와 다르기 때문!!
	// const에 어떻게 대입해! 위험해
}

A::A(int n) : ro(no), co(10)	// 1)  2)
{
	no = n;						// 3) 순서로 초기화가 진행됨!
								// ro는 변수의 별명으로 삼는 것이고, int & ro = no;와 같이 식을 써줄 수 있음.
}

void main(void)
{
	A aa(7);

	int n = 5;
	int & k = n;	// 얘(k)는 생성과 동시에 초기화가 됐기 때문에 다른 저장 공간 할당되지 않음!
}
#endif





// 2.6 const 개체와 const 멤버함수
#if 0
#include <iostream>
using namespace std;

class A
{
	int no;
	char ch;
	mutable char cha;	// mutable로 선언된 멤버 변수만큼은 const 함수들도 변경시킬 수 있다고....
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

void A::sub2(void) const	// 멤버 데이터의 변경은 되지 않음!
							// 이 함수가 값을 바꾸는 행위만 하지 않는다면 const 함수 뿐만 아니라 일반 함수들도 부를 수 있음!
							// 그럼 그 호출되는 함수들도 값을 변경하는 행위를 하면 안됨!
{
	cout << no << " " << ch << endl;
	// 당연히 const 함수 안에서 func호출할 수 없음!!
	// => 선언 시 "this->func();"랑 똑같은 것이다. 근데 this의 타입은 무엇인가? const A * 타입!! 그렇기에 const 함수가 아닌 함수는 호출 막아 놓음!
	
	((A *)this)->func();	// 1) 강제로 타입 캐스팅을 해주면 호출할 수 있음. 하지만 값이 변경되는 것은 각오 하고 있어야..
	func();		// 2) 오버로딩 함수..ㅋ
	// 첫 번째 방법으로 호출을 하든, 두 번째 방법으로 호출을 하든 그건 선택. 안전한 방법은 두 번째.
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
	const A aa(5, 'A');	// const 개체. 항상 선언과 동시에 초기값을 주어야 하고, 변경할 수 없음!
	//aa.sub();			// 그렇기에 값을 바꿀 수 없도록 에러 메세지가 뜸! 호출을 못 하도록
						// ★값을 바꾸지 않는 함수는 호출할 수 있다!! : const함수!★ 그래서 func도 부를 수 없음!
	aa.sub2();
}
#endif


// 멤버 함수의 리턴 타입도 const....
#if 0
#include <iostream>
using namespace std;

class A
{
	int no;
public:
	A(){};
	A(int n) : no(n) {};
	const int * psub(void) const;	// "int * psub(void) const" 얘는 멤버 데이터 변수를 변경시키지 않으므로 const 함수..!
									// 하지만 리턴값인 그 주소를 이용하여 리턴을 받은 놈이 변경할 수도 있잖아?
									// 호출을 받는 이 함수 내부뿐만 아니라 호출하는 쪽엣어도 값을 변경 못 하도록!!!
									// 그것도 못 하게 막으려고 "const int * psub(void) const"로 선언!;;;
	const int & rsub(void) const;	// 얘도 받는 쪽에서 값을 변경할 수 있으므로 const ~~ const로 선언!
	const A * pfunc(void) const;
	const A & rfunc(void) const;
};

// ★ 멤버 데이터의 주소나 참조형을 리턴할 때는 const 리턴형으로 선언해주어야 에러가 뜨지 않음!! ★
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


// ★이해 잘 안됨★
// 멤버 함수를 만들면서 멤버 데이터를 바꾸지 않는다면 const 함수로 선언을 해주는 것을 고려해볼만 하지만,
// 이와 같은 경우, 모든 printf 함수를 const 함수로 만들어 버린다면 내부에 ::printf()에서 형식지정자가 그대로 고정이 되어 버려
// 유연하지 않은(?) 함수 클래스가 되어 버림..
// 이런 경우에는 const로 선언하지 않는다고...;;
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

	c.printf(5).printf(3.14).printf("seoul");	// cout은 이렇게 되어 있음!!
	// printf 함수가 value로 리턴했다면 그 때마다 계속 계속 개체를 생성했을 것. 비효율
}

#endif



// [다시 해보자!!]
// 하하  int * const * .... const...
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
	//*res = 0;	// 얘는 no 멤버 변수에 접근을 하기는 함. 하지만 컴파일러는 이거까지 신경 못 씀
	// 컴파일러는 오직 리턴되는 np값이 바뀔 여지가 있는지 여부만 판단할 뿐! 그런데 np 자체는 바뀌지 않으므로 아직까지는 const int *를 써줘야만 하는지 판단 안 섬.
	// 하지만 방금 말했다 시피 no가 변경될 여지가 잇으므로, 여기에서 리턴 타입을 const로 바꿔줘야 겠다고 판단!!!
	
	
	
	// 이거 다시 해보자! ㅋㅋㅋ
	**(aa.GetPP()) = 111;
	aa.Print();
}

#endif




// 2.7 static 멤버데이터 : 완벽한 OOP는 모든 변수가 전역이 아닌 지역으로 선언된다!!
#if 0
#include <iostream>
using namespace std;

class A
{
	int no;
public:
	static int sum;
};

/* ★★★★ */ // 선언 시 static을 쓰지 않는다!! 쓰면? : 다른 파일들의 헤더로 이것을 선언해 주었을 때, 각각의 파일마다 다른 변수가 됨!
int A::sum = 10;	// 그냥 int sum;이라고 선언하면, 이것은 전역변수 sum이라고 선언을 해준 것!!
			// 그리고 static int sum; 이라고 클래스 내에서 선언을 해주었더라도 전역에 int A::sum;이라고 다시 선언을 해주어야 함!!
			// 그리고 이 곳에서 초기화도 가능하다!!! (초기값 없으면 0으로 초기화됨!)
			// 선언되고 초기화되는 곳이 전역이므로 당연히 콜론 초기화가 불가능한 것이다!!
			// 하지만 static int sum;을 private 나 protected에 선언을 해놓으면, 접근 권한은 제한되지만, 선언은 가능!!

void main(void)
{
	A aa;

	cout << sizeof(aa) << endl;	// static 멤버는 개체의 크기에 포함되지 않음!!! 별도의 공간!!

	A bb;
	aa.sum = 0;	// 모든 A 클래스 개체들이 sum을 공유하므로 aa와 bb가 같은 값을 씀. aa가 바꾸더라도 bb의 sum값이 바뀜!
	// 그런데 이것도 public에 선언되었기 때문에 이렇게 공유가 가능한 것!!
	cout << bb.sum << endl;	// cout << sum << endl; 이라고 하면 에러 뜸!! 선언되지 않은 식별자라고 ㅋㅋ
}
#endif


// (접근권한 private의) static 멤버 데이터에 접근하기 위한 static 멤버 함수!
#if 0
#include <iostream>
using namespace std;

class A
{
	int no;
	static int sum;	// private로 선언을 했따면, 여기에 접근할 수 있는 public 함수를 만들어서 접근해야 함!!
public:
	static void sub(int s);
	static void func(void);
};

int A::sum = 10;	// 얘는 A aa;가 만들어지기 훨씬 전부터 만들어져 있는 것!
					// 그럼 A aa;가 선언되기 전에 sum에 접근하고 싶으면 어떻게 하지..?
					// => Object 없이도 sum(static 멤버 데이터)에 접근하고 싶다면, ★static 멤버함수...!★
// static 멤버함수 : Object 없이도 멤버 데이터에 접근할 수 있음!!!!

void A::sub(int s)		// 여기에서 정의해줄 때는 static void A::sub(int s) ~ 와 같이 선언할 수 없다고 함!!
{
	A::sum = s;	// sum을 사용할 때도 A::sum이라고 함!!
}

void A::func(void)
{
	cout << A::sum << endl;
}

void main(void)
{
	A::sub(5);	// static 멤버 데이터가 있다면, 자연스럽게 그 데이터에 접근하기 위한 static 함수가 따라오게 되어있음!
	A::func();

	A aa;

	cout << sizeof(aa) << endl;	// static 멤버는 개체의 크기에 포함되지 않음!!! 별도의 공간!!

	aa.sub(0);	// sum을 0으로 바꾸고
	aa.func();	// sum을 출력
}
#endif




// ★★ 전체적인 구조 이해!! ★★
// 2.8 static 멤버함수
// 생성자를 private 권한으로.. -> 어디서나 자유롭게 Object를 만들지 못하도록
#if 0
#include <iostream>
using namespace std;

class CMainFrame	// MFS에서 제공하는 기본 클래스 중 하나!
{
	CMainFrame();	// 어디서나 자유롭게 Object를 만들지 못하도록 public에서 private로 감춰버림!!
					// 생성자를 이렇게 감춰둔 이유? : 동적으로 Object를 만들고 삭제하고 할 수 있도록!
public:
	static CMainFrame * CreateObject(void);	// 바깥에다가 static으로 함수 선언 Nope!
	~CMainFrame();
	void ShowWindow(void);
	void DestroyWindow(void);
};

CMainFrame * CMainFrame::CreateObject(void)	// Object(개체) 만들어지기 전에도 클래스에 접근 가능!! -> CMainFrame에 접근할 것이다!
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

	delete this;	// 여기서!!
}

void main(void)
{
	CMainFrame * pFrame = CMainFrame::CreateObject();
	
	pFrame->ShowWindow();		// 
	pFrame->DestroyWindow();	// 사용자가 우측 상단에 X(close) 버튼을 누르면 실행됨

	//delete pFrame;		=> 근데 여기서 delete 하지 않더라도 delete 되게 할 수 없을까?
							// => DestroyWindow(즉, x클릭으로 끌 때)에서 하면 되잖아?
}
#endif

// 더 좋은 방법이 있대 ㅋㅋ => 이게 뭐지?
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





// friend 함수 
#if 0
#include <iostream>
using namespace std;

class A;	// B에게 A는 클래스야! 라고 알려주는 느낌

class B		// Bsub 함수 안에다가 써도 됨!
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
	friend void Gsub(const A & ra);	// 전역변수를 멤버 있는 쪽에 friend로 선언해두면, private한 접근까지도 허용해줌!
	friend void B::Bsub(A * ap);	// 일단 다른 클래스의 멤버이므로 스코프는 꼭 써줘야 해!!
};

void A::sub(void) const
{
	cout << no << endl;
}

void Gsub(const A & ra)	// 전역함수 , 참조로 받아줌(새로운 공간 할당 안해주기 위하여!)
{
	//cout << ra.no << endl;	// private 권한이라 no에 대한 접근 못함!!
							// 그런데 이 전역함수를 멤버 안에다가 friend로 선언해놓으면 접근 가능..!! 오오

	ra.sub();			// 그런데 위에서처럼 멤버 변수를 그대로 노출시키기 위해 사용하면 좋지 않음..
						// 물론 결과적으로는 똑같더라도, 값을 바꿀 수 없도록 sub 함수에 접근하여 이용하는 것이 더욱 좋음!!
}

void B::Bsub(A * ap)
{
	ap->sub();	// 엥? 잠시만, 바로 접근하려고?? 친구하자!하고 A 쪽으로 감
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
/*							[ 2019.10.02 수 ]						   */
/***********************************************************************/

// 2.12 복사 생성자함수(copy constructor)
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

// 컴파일러가 자동으로 만들어주는 "디폴트 복사 생성자 함수"
/*
		A(A ra);	// 자기 자신을 "참조"하는 생성자 함수가 아니라면, RTE 발생!
		Why?
		: A ra = aa; (== A ra(aa);)라는 생성자 함수를 호출할 것이고.
		그럼 계속 A(A ra); 라는 생성자 함수를 계에에에엥에ㅔ속 호출하는 것이기 때문에 RTE 발생!!
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

	A bb = aa;	// bb.operator =(aa); 라는 함수가 호출되는 것 아님!! 지금 이 식은 "선언 && 초기화 식"임!!
				// ★ A bb(aa); 생성자 함수 호출!	얘가 호출되는 것! 자동으로 A 타입 인자를 받는 생성자 함수 만들어 주는 것★
	bb.sub();
}

#endif




// [★★★★★]
// 2.13 R-value 참조	( L-value : 저장 공간 // R-value : 상수 )
#if 0
#include <iostream>
using namespace std;

int & sub(int & nn)	// 그냥 int nn을 인자로 받아주면 또 다른 기억공간이 만들어져 거기에 저장하게 됨!
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


	int & k = n;	// L-value 참조


	int && r = 5;	// R-value 참조 (상수형 참조)
	r = 10;			// R-value 참조는 const형 참조와 달리 값 변경 가능
	cout << r << endl;


	const int & c = 10;
	cout << c << endl;
	//c = 5;			// const 형으로 선언됐기 때문에 값 변경 불가!


	// ★ 참조에 대한 이해 필요!! ★
	int & res1 = ++n;
	int && res2 = n++;	// 임시값을 받고 그 임시값을 변경해양할 때


	// ★ 참조에 대한 이해 필요!! ★
	int & s1 = sub(n); // int & 타입의 리턴이므로 그 공간(노 임시!)이 안 없어진 것. -> L-value 참조로 받아야...;;
	// l-value 참조 변수인 s1에 대한 다른 공간이 마련되는 것 아님.

	int && s2 = func();// 함수 안에서 n이 임시에 만들어져 n이 대입됨. n은 함수 끝나면서 공간 없어짐.
	// r-value 참조 변수인 s2에 대한 다른 공간이 마련되는 것.
	// 이러한 R-value 참조는 "2.14 이동 생성자함수(move constructor)"에서 필요!!
}
#endif



//2.14 이동 생성자함수(move constructor)
#if 0
#include <iostream>
using namespace std;

class A
{
	int no;
public:
	A(){ cout << "Default Cons ..." << endl; };							// 디폴트 생성자
	A(int n) : no(n) { cout << "Integer Cons ..." << endl; };
	A(const A & ra) : no(ra.no) { cout << "Copy Cons ..." << endl; };	// 복사 생성자
	A(A && ra) { cout << "Move Cons ..." << endl; };					// 이동 생성자
	// 이동 생성자 : 잠깐 만들어졌다가 곧 소멸될 임시 개체에 대해서 복사 생성자보다 우선해서 생성되게 됨!
	// 그냥 막 복사하기 위한 생성자를 사용하는 것이 아니라, 비교적 저렴한 이동을 위한 생성자를 호출하는 것이 효율적! 
	// 복사 생성자보다 저렴한 비용의 코드! 그렇기 때문에 개체 내의 정보의 이동은 복사 생성자보다 효율적으로 "코더"가 짜야 함!!
	~A(){ cout << "Des ..." << endl; };
};

A sub(void)
{
	A aa;
	return aa;	// (value로 리턴) ★imsi Object★를 만들고, 그것을 리턴!-> "des..." 라는 메시지 뜰 것이다~
					// A imsi(aa); -> 원래 복사생성자가 호출되는데, 없으므로 디폴트 생성자로 임시 개체가 초기화 될 것!
					// (cf> 2.12 복사 생성자함수(copy constructor) 참고)
					// => 복사 생성자 함수가 호출 된다면...


	//return A();		// NRVO ( Return Value Optimazation )
}

void main(void)
{
	// 1) 임시 생성자 변수가
	//sub();		// => "des..." 라는 메시지 2개
	A res = sub();	// => "des..." 라는 메시지 2개 -> but, 위치가 다름!!

	// 2) 이동 생성자가
	cout << "end main" << endl; // => "des..." 라는 메시지 2개 -> but, 위치가 다름!!
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
	//A(){};				   이런 기본 생성자를 만들지 않고,
	A(int n) : no(n) {};	// 다른 생성자를 만들었다면? => 컴파일러는 디폴트 생성자를 자동으로 만들어주지 않음!
	//A(const A & ra){};	   기본 복사생성자는 기본을오 제공!
	A(A && ra) {};			// 단, 이동 생성자를 만들지 않았을 경우에만 복사생성자 기본으로 제공..!!;;
*/

	A() = default;
	A(int n) : no(n) {};
	A(const A & ra) = default;		// 이런 식으로 default 값을 정의해놓으면, 디폴트로 이것들이 우선순위로 실행!!
	A(A && ra) {};
};

void main(void)
{
	A aa;
	A bb(aa);
}

#endif







// 2.18 위치지정(placement) 초기화의 new : 미리 할당을 해놓고, 나중에 원할 때 다시 초기화!
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
	// 2.18 위치지정(placement) 초기화의 new : 미리 할당을 해놓고, 나중에 원할 때 다시 초기화!
	/*
	int no;

	int * np = new (&no) int (15);	// 정적 공간 할당이래..!!
	cout << *np << endl;

	
	int * p = new int;				// 동적 공간 할당!
	int * ap = new (p) int(5);

	cout << *ap << endl;

	delete ap;	// ★ap로 반환하는게 맞다고 함!!★
	*/


	//A * p = new A;			// Object를 생성하면서 동적할당! (이 때는 티폴트 생성자를 호출하게 되겠지?)
	A * p = (A *)malloc(sizeof(A));	// malloc으로 해주는 경우가 많다고..;;

	A * ap = new (p)A(5);	// ★메모리 할당 하는 것 아님!★ 이 때 ★int 생성자를 Call★ 하는 것!!!!

	ap->~A();	// 필요하다면 소멸할 수 있음. 가지고 있던 자원을 반납! 하지만 개체 자체가 풀린 것 아니야!!
				// 그러면 다시 생성자를 불러낼 수 있어!!


}

#endif





/***********************************************************************/
/*							[ 2019.10.04 금 ]						   */
/***********************************************************************/


// 상속 기본
#if 0
#include <iostream>
using namespace std;

class A	// 선배들이 만든 코드
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

class B : public A	// 오늘날 후배들이 만든 코드
{
	//A::sum;	// 이런 경우 가능!
public:
	A::ch;		// protected 권한이었던 것을 public으로 변경 가능!(private 였던 것을 변경하진 못함!)
};

void main(void)
{
	B bb;
	cout << sizeof(bb) << endl;	// A클래스(기반/부모 클래스)의 크기 그대로!(12B)

	//bb.no = 5;					// 부모의 private 멤버에 대한 직접적 접근 불가 (외부에서)
	//bb.ch = 'A';					// 부모의 protected 멤버에 대한 직접적 접근 제한 (외부에서)
	bb.sum = 100;
	// 그렇다면 부모 멤버에 대한 접근 권한 변경 가능한가? 가능!! : public: A::ch; 라고 선언해주면 가능!
	bb.ch = 'A';// 이렇게! 하지만 부모의 private 멤버를 public으로 바꿀 수 없어!!!!
}
#endif

// 파생클래스의 생성자, 소멸자 함수
#if 0
#include <iostream>
using namespace std;

class A	// 선배들이 만든 코드
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


class B : public A	// 오늘날 후배들이 만든 코드
{
	char * str;
public:
	B();
	B(char * s);
	B(int n, char c, char * s);	// 자식 클래스의 생성자에는 컴파일러가 자동적으로 :초기화가 들어감! : A()로
};

B::B()	// : A() - 단, A에 기본 생성자가 아닌 다른 생성자만 만들었다면, 이 기본 생성자 함수가 안 만들어지고, 호출되지 않음!!
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
	B bb("Seoul");	// A(부모/기반) 클래스의 생성자 먼저 호출됨! <-> 소멸자는 생성자 함수의 역순으로(자식/파생 클래스의 소멸자 먼저 호출됨!)
	cout << sizeof(bb) << endl;	// 부모 크기와 char *(4B)를 더한 16B가 나옴!
}
#endif




// string 클래스
#if 0
#include <string>
#include <iostream>
using namespace std;

class mstring : public string
{
// 1) 파생 클래스에서 필요한 멤버 함수/변수 만들기
// 2) 파생 클래스에 맞는 생성자, 소멸자 함수 만들기

	string::c_str;
public:
	mstring();
	mstring(const char * str);
	operator const char *(void) const; // 멤버 데이터를 변경하지 않으므로 const 타입 함수
										// "const char *"이 필요하면 호출됨!!
};

mstring::mstring()
{

}

mstring::mstring(const char * str) : string(str)	// 부모에게 일임 가능하면 일임!
{
}

mstring::operator const char *(void) const
{
	return c_str();		// 파생 클래스 private로 "string::c_str;" (함수 이름만 적으면 됨!).... 함부로 못 씀
}

// 전역함수s
void Gfunc(char * str)
{
	
}

void Gsub(const char * s)
{
	cout << s << endl;
}

void main(void)
{
	string str("Seoul");	// ()내의 문자열로 생성자를 호출하여 초기화(?)하고, 직접 동적할당까지도 하는!
	cout << str << endl;

	Gsub(str.c_str());	// str은 string 타입이고, 인자로는 cahr *가 들어가야 함!
						// string은 형변환 함수가 없다고 함!
						// string 클래스에는 c_str 함수가 있어서 "주소"를 부여 받음!
	cout << ::strlen(str.c_str()) << endl;


	mstring mstr("Seoul");
	cout << mstr << endl;

	Gsub(mstr);
	cout << ::strlen(mstr) << endl;
	Gfunc( (char *)(const char *)mstr ); // char *로 형변환 해주는 함수를 더 만들어주는 방법도 있지만, 
					// const가 없다는 것은 "변경하겠다"라고 명시하는 것이므로 아예 접근을 못하도록 
					// 안 만드는 것이 나은 경우가 많음.
					// 굳이 넘기고 싶으면.. 더블 캐스팅으로 직접 해서 넘기는 것이,,,!

}

#endif





// 3.3 기반클래스의 포인터와 참조 (부모 포인터...??)
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
	sub();	// public으로 A로부터 상속을 받았기 때문에 A에서의 public 멤버를 자식이 public으로 접근 가능!
}

// 전역함수
void Gsub(A * p)	// 부모의 포인터는 자식을 가리킬 수 있기 땜누에 A도 B도 가리키게 하기 위해서는 A* 타입으로
{
	p->sub();

	// C++에서는 RTTI(RunTime Type Information)을 제공.. 런타임에도 타입을 확인한다는 것. C에서는 컴파일 타임에만 하던 것을..
	if (typeid(*p) == typeid(B))
	{
		((B *)p)->func();	// B로부터 만들어진 개체만 이 함수를 사용하게 만들고 싶어!
	}
}

void main(void)
{
	/*
	B bb('A', 5);
	bb.func();
	*/

	//A * p = new B;	// B * p = new B;가 기본이겠지만, 형 변환 안 하더라도 A로도 가능!! 상속 받았잖아?
					// 부모가 자식의 포인터로 사용될 수 없는 경우? : void *인 경우(알 수 없는 데이터 타입인 경우!!)
					// 훗날(미래에) 만들어질 B가 어떤 것인지 모르기 때문에!...........
					// 하지만 잘 사용하지는 않는다고.. 위험성이 있때....ㅋㅋ : 자식의 소멸자가 수행되지 않음!
					// A 클래스는 컴파일 타임에 어떤 것인지 알 수 있지만, B는 지정되지 않음(?)
					// 그렇기 때문에 딜리트 할 때도 B는 모르므로 A를 가리키게 되는 것!
					// => virtual ~A();라고 선언해주면, delete 시에 ~A가 가상이므로 컴파일 타임에 이 소멸자와 연결되지 않음!
					//    근데 runtime 때 B로부터 만들어질 것이므로 B의 소멸자를 실행하고, 거기서 부모의 소멸자를 불러 부모의 소멸자도 실행됨...
					//   - 동적 바인딩 개념!! (런타임에 결정되기 때문에 속도는 조금 느려질 수 있겠지만, 이런 경우 효율적!)

	//A * p = new B;
	//delete p;

	A aa(5);
	B bb('A', 10);
	Gsub(&aa);	// 5가 출력될 것
	Gsub(&bb);	// 10이 출력될 것
	cout << typeid(aa).name() << endl;	// 타입의 이름을 알려주는 함수임..ㅋㅋ
	cout << typeid(&aa).name() << endl;
	cout << typeid(bb).name() << endl;
	cout << typeid(&bb).name() << endl;
}

#endif




// 3.4 재정의(overriding)
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
	void sub(void);	// 일반적으로 부모의 함수와 똑같이 사용한다!!
};

void B::sub(void)
{
	A::sub();
	cout << "B" << endl;
}



void main(void)
{
	B aa;	// B타입 개체 aa
	aa.sub();
}

#endif

// 재정의 추가
// 3.6 가상함수(virtual function)
#if 0
#include <iostream>
using namespace std;

class CWnd
{
public:
	void OnLButtonDown(void);
	virtual void OnRButtonUp(void);	// 동적 바인딩 : 컴파일 시간에 호출할 object가 불분명한 경우, 미래를 위해서 가상 함수 설정
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
			OnRButtonUp();	// this->OnRButtonUp();에서 this가 생략되어 있음. this는 CWnd *타입임..
							// 이 코드는 과거에 만들어져서 호출하고 있고, 아직Mywnd를 모르는 상태잖아? (미래 만들어질 가상의 함수를 호출하고 있는 것!)
							// 
			break;
		case 0:
			if( OnClose() == true ) goto FIN;	// 복합적인 중괄호 다 빠져나갈 때! (break는 하나밖에 못 빠져 나가잖아)
			break;
		}
	}
FIN:;
}


class MyWnd : public CWnd	// 나만의 기능을 만들고 싶어!
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
	virtual ~A(){ cout << "A des..." << endl; };	// 일반적으로 부모의 소멸자 함수를 virtual로 둠. - 자식의 소멸자 함수가 호출되지 않을 우려 피하기 위해!
	void sub(void);
	virtual void func(void);
};

void A::sub(void)
{
	func();	// 미래에 상속되어 재정의되어 호출될 놈을 virtual로 선언
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
	void func(void);						// 오버라이딩(재정의)된 함수
};

void B::func(void)
{
	cout << "B func" << endl;
}


void main(void)
{
	B bb;
	bb.sub();
	cout << sizeof(bb) << endl;	// 왜 12B일까? 8B가 아니라? : 클래스 내 가상 함수를 포함하면 무조건 4B 포함!!
								// 가상 함수가 1500개라도 4B 늘어남!ㅋㅋㅋ
								// => 주소를 저장할 배열이 필요하고, 또 그 배열을 저장할 "더블 포인터"가 필요!!
}
#endif




// 3.7 순수 가상함수(pure virtual function)




// 3.8 클래스 멤버 포인터 : 클래스 안에 있는 멤버 변수를 가리키는 포인터 / static 멤버는 가리킬 수 없다
//						그 포인터가 증가 및 감소할 수 없다. (정수형 ++해주면 4 증가하는데, 그 곳에 정수형이 있대? 없을 수도 있잖아! 그러니 증감 못함!)
#if 0
#include <stdio.h>
#include <iostream>
using namespace std;

int go;

class A
{
public:
	int & ro = go;	// l-value 참조형 변수는 전역변수의 번지도 받을 수 있기 때문에 클래스 멤버 포인터로 접근 불가!
	int no;
	char ch;
	//A(){};
	//~A(){};
};

void main(void)
{
	//int & A::*rp = &A::ro;		// 참조 형식의 멤버 포인터를 사용할 수 없다고 오류 뜸!
	int A::* p = &A::no;		// 없는 공간의 주소를 가지고 있따? 말이 안된다.. 근데 값을 가진다!!
	char A::* cp = &A::ch;		// 무슨 값을 가질까?

	// cout은 멤버 포인터를 지원하지 않으므로 printf로 출력해보자!
	printf("p = %d, cp = %d\n", p, cp);	// 상대주소로 나옴! 나오긴 나오지만 제대로 된 결과값은 아님!
										// class A는 8B임. 먼저 쓰여진 int no는 0번째, char ch는 4번째 주소
										// 그래서 답이 0, 4가 나옴!
	// 공간도 할당 안 되었는데 주소 값을 갖는다? 그럴 이유가 있다는데 과연 무엇일까!?

	A aa;
	A * ap = &aa;
	aa.*p = 10;		// aa라는 개체에 p가 가리키는 내용!
	aa.*cp = 'A';	// aa라는 개체에 cp가 가리키는 내용!

	cout << ap->*p << ap->*cp << endl;
	cout << aa.*p << aa.*cp << endl;   // 둘은 같은 표현!	=> but, ".*"는 이항연산자라 우선순위가 비교적 낮음!!
}
#endif





// 함수 포인터
#if 0
#include <iostream>
using namespace std;

void __cdecl sub(int n, char c)	// 함수에는 기본적으로 " __cdecl "와 같은 콜 프로토콜이 생략되어 있음
{

}

void __cdecl func(int n, char c)
{

}

void main(void)
{
	int n;
	void(__cdecl * fp)(int, char);	// 함수의 이름은 함수의 주소!! 함수 이름 앞에도 & 붙여서 주소로! 안 써도 되지만 다른 변수들과 통일시켜주기 위해 써주기로 한다!

	cout << "n : ";
	cin >> n;
	if (n == 0) fp = sub;		// n이 0이면 sub 함수의 주소를 갖고,
	else if (n == 1) fp = func;	// n이 1이면 func 함수의 주소를 갖는다.
	// 마치 동적 바인딩처럼 함수 포인터도 컴파일타임이 아닌 런타임 때 어떤 함수를 사용할 지 결정!

	fp(5, 'A');

}

#endif

// 클래스 멤버 함수 포인터
// 호출 규약이 __cdecl에서 __thiscall로 바뀜
// void(__thiscall A::* fp)(int, char); 로 바뀜
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

void __thiscall A::sub(int n, char c)	// " __thiscall " 가 생략되어 있음
{
	cout << n << " " << c << endl;
}

void A::func(void)
{
	void(__thiscall A::* fp)(int, char) = &A::sub;// 가상함수가 있다면 클래스 크기에 추가되는 4B void ** 변수의 [0] 요소 : 함수 결정(?)
	(this->*fp)(10, 'E');						  // [1] 요소	:	함수 호출
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
	void(__thiscall A::* fp)(int, char) = &A::sub;	// &는 반드시 써야 함!!!!!

	(aa.*fp)(5, 'A');	// object가 반드시 있어야만 호출이 가능!!! 함수 포인터와 달리
					// ".*" 연산자와 "() 함수 호출 연산자" 두개의 연산자가 있고, .*가 우선순위가 낮으므로 ()로 묶어줘야...

	(A().*fp)(6, 'Z');	// 임시 object를 이용하여 call을 하는 것!

	aa.func();

	cout << endl;

	void(__thiscall A::* fp3)(void) const = &A::func;	// void A::func(void) const 호출

	void(__thiscall A::* fp2[3])(void) = 
	{
		&A::func,			// void A::func(void) 호출
		(void(__thiscall A::*)(void)) (void(__thiscall A::*)(void) const) &A::func,	// void A::func(void) const 호출
		(void(__thiscall A::*)(void)) (void(__thiscall A::*)(int)) &A::func
	};
	// => 호출할 때는!?!?
	(A().*fp2[0])();	// void A::func(void) 호출
	(A().*fp2[1])();	// void A::func(void) const 호출
	(A().* (void(__thiscall A::*)(int))fp2[2])(5);
}

#endif





// 마지막 예
// 클래스 내 가상 함수를 두면, 그 가상함수 주소를 초기화 하기 위한 디폴트 생성자가 자동적으로 생성된다!
// (전에 배웠던 것) 멤버 변수를 선언해주고, 디폴트 값을 줬을 때 디폴트 생성자가 자동적으로 생성됨
#if 0
#include <iostream>
using namespace std;

class A;
typedef void(__thiscall A::* VFPTR)(void);

class A
{
	VFPTR m_vfptr;	// 타입 변수 순서
	int no;
public:
	A() : m_vfptr(&A::func) {};
	A(VFPTR vfptr) : m_vfptr(vfptr) {};
	A(int n) : no(n) {};
	virtual ~A(){ cout << "A des..." << endl; };// 일반적으로 부모의 소멸자 함수를 virtual로 둠. - 자식의 소멸자 함수가 호출되지 않을 우려 피하기 위해!
	void sub(void);
	/*virtual*/ void func(void);
};

void A::sub(void)
{
	(this->* this->m_vfptr)();	// 미래에 상속되어 재정의되어 호출될 놈을 virtual로 선언
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
	void func(void);						// 오버라이딩(재정의)된 함수
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
