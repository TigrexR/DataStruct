#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node * pNode;
	//�������ͷ�ڵ㡢β�ڵ㡢ͷָ�롢βָ�롢ͷ���
}Node;

Node * createNode();//����һ����ѭ�������������������ͷ���ָ�봫��

int main() {
	Node * pNode = createNode();
	return 0;
}

Node * createNode() {

	Node * pHead = (Node *)malloc(sizeof(Node));
	if (NULL == pHead)
		exit(-1);

	Node * pTail = pHead;
	pTail->pNode = NULL;

	int len = 10;
	for (int i = 0; i < len; i++)
	{

		Node * pNew = (Node *)malloc(sizeof(Node));
		if (NULL == pNew)
			exit(-1);

		pNew->data = 1;
		pTail->pNode = pNew;
		pNew->pNode = NULL;
		pTail = pNew;

	}

}