#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct ArrayList
{
	int * data;//数组存储的数据
	int len;//数组的长度
	int cnt;//当前长度
	int increment;//增长因子
} ArrayList;

bool init(ArrayList *, int len, int increment);
void append(ArrayList *, int value);
void insert(ArrayList *, int index, int value);
void remove();
int get(ArrayList *, int index);
bool isFull(ArrayList *);
bool isEmpty(ArrayList *);


int main(void) {
	ArrayList al;
	init(&al, 2, 2);
	printf("%d\n", al.len);
	printf("%d\n", isEmpty(&al));
	printf("%d\n", isFull(&al));
	append(&al, 1);
	printf("%d\n", al.data[0]);
	append(&al, 2);
	printf("%d\n", al.data[1]);
	append(&al, 3);
	printf("%d\n", al.data[2]);
	append(&al, 4);
	append(&al, 5);
	append(&al, 6);
	append(&al, 7);
	append(&al, 8);
	printf("%d\n", al.cnt);
	printf("%d\n", al.len);
	insert(&al, 5, 7);
	printf("%d\n", get(&al, 2));
	printf("%d\n", get(&al, 5));
	return 0;
}

bool init(ArrayList * al, int len, int increment) {
	al->data = (int *)malloc(sizeof(int) * len);
	if (NULL == al->data) {
		printf("内存不足，分配失败\n");
		exit(-1);
	}
	else {
		al->len = len;
		al->cnt = 0;
		al->increment = increment;
	}
	return true;
}

void append(ArrayList * al, int value) {
	if (isFull(al)) {
		al->len = al->len * al->increment;
		realloc(al->data, al->len * sizeof(int));
		al->data[al->cnt] = value;
		al->cnt++;
	}
	else {
		al->data[al->cnt] = value;
		al->cnt++;
	}
}

void insert(ArrayList * al, int index, int value) {
	if (isFull(al)) {
		al->len = al->len * al->increment;
		realloc(al->data, al->len * sizeof(int));
		al->cnt++;
		for (int i = 0; i < (al->cnt - index -1); i++)
		{
			al->data[al->cnt - i] = al->data[al->cnt - i - 1];
		}
		al->data[index] = value;
	}
	else {
		al->cnt++;
		for (int i = 0; i < (al->cnt - index - 1); i++)
		{
			al->data[al->cnt - i] = al->data[al->cnt - i - 1];
		}
		al->data[index] = value;
	}
}

void remove() {

}

int get(ArrayList * al, int index) {
	return al->data[index];
}

bool isFull(ArrayList * al) {
	if (al->cnt == al->len)
		return true;
	return false;
}

bool isEmpty(ArrayList * al) {
	if (0 == al->cnt)
		return true;
	return false;
}

