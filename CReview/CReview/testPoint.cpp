#include <stdio.h>
#include <malloc.h>

void f(int * x) {
	*x = 100;
}

int main (void){

	int * p;
	int a = 0;
	int b;
	int * x;
	int c[5] = { 1,2,3,4,5 };

	p = &a;
	b = *p;
	x = &*p;

	a++;
	f(&a);

	for (int i = 0; i < 10; i++)
	{
		a++;
		if (a >= 109)
		{
			break;
		}
	}

	printf("%d\n%d\n%d\n%d\n", a, *p, b, *x);
	printf("%d\n", sizeof(int));
	int len = 5;
	int * parr = (int *)malloc(sizeof(int) * len);
	*parr = 4;
	parr[1] = 5;
	printf("%d\n", parr[0]);
	free(parr);
//	for (int i = 0; i < sizeof(c); i++)
//	{
//		c[i] = a + c[i];
//		printf("%d\n", c[i]);
//	}

	int * pnew;//�����һ��ָ�����
	//ָ��Ҳ��ָ���ֵ�ı����ַ
	newObj(&pnew);//���ｫָ������ĵ�ַ����ȥ

	return NULL;

}

int newObj(int **q) {//ͨ��**q����ָ������ĵ�ַ
	*q = (int *)malloc(4);//
}