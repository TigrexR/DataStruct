#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node * pNext;
}Node, * pNode;

typedef struct Stack
{
	pNode pTop;
	pNode pBottom;
} Stack, * PStack;

bool initStack(PStack);
bool pushStack(PStack, int);
bool deleteStack(PStack, int);
bool popStack(PStack, int *);
bool clearStack(PStack);
bool isEmpty(PStack);

int main(void) {

	Stack stack;

	initStack(&stack);
	pushStack(&stack, 1);

	int value;
	popStack(&stack, &value);

	return 0;

}

bool initStack(PStack pStack) {

	pStack->pTop = (pNode)malloc(sizeof(Node));
	if (NULL == pStack->pTop)
		exit(-1);

	pStack->pTop->pNext = NULL;
	pStack->pBottom = pStack->pTop;

	return true;

}

bool pushStack(PStack pStack, int value) {

	pNode pNew = (pNode)malloc(sizeof(Node));
	if (NULL == pNew)
		exit(-1);

	pNew->data = value;
	pNew->pNext = pStack->pTop;
	pStack->pTop = pNew;
	return true;

}

bool deleteStack(PStack pStack, int pos) {

	int len = 0;

	while (NULL != pStack->pTop->pNext)
	{
		len++;
	}

	if (pos > len) {
		printf("没有次节点");
		return false;
	}

}

bool popStack(PStack pStack, int * value) {

	if (isEmpty(pStack))
		return false;

	value = &pStack->pTop->data;
	pNode freeNode = pStack->pTop;
	pStack->pTop = freeNode->pNext;
	free(freeNode);
	return true;

}

bool clearStack(PStack pStack) {

	if (isEmpty(pStack))
		return false;

	pNode freeNode = pStack->pTop;

	while (NULL != pStack->pTop->pNext)
	{
		pStack->pTop = freeNode->pNext;
		free(freeNode);
		freeNode = pStack->pTop;
	}

	free(freeNode);
	return true;

}

bool isEmpty(PStack pStack) {
	if (NULL == pStack->pTop->pNext)
		return true;
	return false;
}