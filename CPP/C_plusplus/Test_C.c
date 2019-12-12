#pragma warning (disable: 4996)

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




// ����� const
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




// �ڵ��� �޸� �Ҵ�� : C++������ �޸� ������ �Ҵ� ���� �� �ٸ� ������ �䱸! �� ������ ���ؼ��� malloc���� ó�� �� ��..
#if 0
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int size;
	//char data[size];		// ������ Ÿ�� �� �� size�� �� �� �����Ƿ�, �� ���� ������ �ߴ� ��!!
	int * p;

	printf("Size : ");
	scanf("%d", &size);		// Runtime�� �Է��� ����

	p = (int *)malloc(size);
	if ( p == (int *)0x0 ) return;

	/*
	*p = 100;
	p++;		// ��free�� ����� �޸𸮸� ��ȯ���ֱ� ���ؼ��� p�� ��ȭ�ؼ��� �ȵȴ�!!! (��, ó���� �Ҵ������ �ּҰ��� �״�� �������־�� ��!!)
	*p = 200;

	// cf> ó���� �Ҵ������ �޸��� �ּҿ��� 16����Ʈ ������ size�� ����Ǿ� �ִٰ� ��!
	// �׷��� p�� �����߰�, �̰��� �ٽ� free �����ַ��� �Ѵٸ�, �� �ּҿ��� 16����Ʈ ���� �ִ� ���� �а� �۵��� �� ���ε�
	// ���� ������ ���� �������� ���̹Ƿ� ���۵��� �� ��!!!!!!!!!
	*/
	
	p[0] = 100;
	p[1] = 200;
	printf("%d %d\n", p[0], p[1]);
	printf("Size = %d\n", p[-4]);
	printf("Size = %d\n", *(int *)((char *) p - 16));
						  // (int *)�� 4����Ʈ ���� �б� ���� ����ȯ, (char *)�� 1����Ʈ ������ �ٲ��ֱ� ���� ����ȯ
	*(int *)((char *)p - 16) = 0;
	printf("Size = %d\n", _msize(p));
	*(int *)((char *)p - 16) = size;
	
	free(p);
}

#endif