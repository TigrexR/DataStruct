#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

typedef struct Node {
	int data;
	struct Node * pNode;
	//链表存在头节点、尾节点、头指针、尾指针、头结点
}Node;

Node * createNode();//创建一个非循环单链表，并将该链表的头结点指针传回

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