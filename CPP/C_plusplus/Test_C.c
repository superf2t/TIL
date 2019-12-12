#pragma warning (disable: 4996)

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




// 예약어 const
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




// ★동적 메모리 할당★ : C++에서는 메모리 사이즈 할당 말고도 또 다른 정보를 요구! 그 정보에 대해서는 malloc으로 처리 못 해..
#if 0
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int size;
	//char data[size];		// 컴파일 타임 때 이 size를 알 수 없으므로, 이 것은 에러가 뜨는 것!!
	int * p;

	printf("Size : ");
	scanf("%d", &size);		// Runtime에 입력을 받음

	p = (int *)malloc(size);
	if ( p == (int *)0x0 ) return;

	/*
	*p = 100;
	p++;		// ★free로 제대로 메모리를 반환해주기 위해서는 p가 변화해서는 안된다!!! (즉, 처음에 할당해줬던 주소값을 그대로 프리해주어야 함!!)
	*p = 200;

	// cf> 처음에 할당해줬던 메모리의 주소에서 16바이트 이전에 size가 저장되어 있다고 함!
	// 그런데 p가 증가했고, 이것을 다시 free 시켜주려고 한다면, 그 주소에서 16바이트 전에 있는 값을 읽고 작동을 할 것인데
	// 전혀 엉뚱한 값이 적혀있을 것이므로 오작동을 할 것!!!!!!!!!
	*/
	
	p[0] = 100;
	p[1] = 200;
	printf("%d %d\n", p[0], p[1]);
	printf("Size = %d\n", p[-4]);
	printf("Size = %d\n", *(int *)((char *) p - 16));
						  // (int *)는 4바이트 수로 읽기 위한 형변환, (char *)은 1바이트 단위로 바꿔주기 위한 형변환
	*(int *)((char *)p - 16) = 0;
	printf("Size = %d\n", _msize(p));
	*(int *)((char *)p - 16) = size;
	
	free(p);
}

#endif