#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stddef.h>
#include <string.h>
#include <math.h>
#include "queue.h"

void InitAQueue(AQueue *Q)
{
	*(Q->data) = (void *)malloc(Q->data_size * MAXQUEUE);
	Q->front = 0;
	Q->rear = 0;
}

void DestoryAQueue(AQueue *Q)
{
	while (*(Q->data) != NULL)
	{
		free(*(Q->data));
		*(Q->data) = NULL;
	}
}

Status IsFullAQueue(const AQueue *Q)
{
	if (Q->front == ((Q->rear + 1) % MAXQUEUE))
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Status IsEmptyAQueue(const AQueue *Q)
{
	if (Q->front == Q->rear)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

Status GetHeadAQueue(AQueue *Q, void *e)
{
	if (IsEmptyAQueue(Q))
	{
		return FALSE;
	}
	else
	{
		memcpy(e, (Q->data)[Q->front], Q->data_size);   //发现一个神奇的函数，由第二个参数指向地址为起始地址的连续（第三个参数）个字节的数据复制到以（第一个参数）指向地址为起始地址的空间内。
		return TRUE;
	}
}

int LengthAQueue(AQueue *Q)
{ 
	int temp = Q->rear - Q->front;
	if (temp < 0)
	{
		return 10 - temp;
	}
	else
	{
		return temp;
	}	
}

Status EnAQueue(AQueue *Q, void *data)
{
	if (IsFullAQueue(Q))
	{
		return FALSE;
	}
	void *e = (char *)(*(Q->data)) + (Q->rear)*(Q->data_size);
	memcpy(e, data, Q->data_size);
	/*Q->data[Q->rear] = data;
	Q->rear = (Q->rear + 1) % MAXQUEUE;*/
	return TRUE;
}

Status DeAQueue(AQueue *Q)
{	
	if (IsEmptyAQueue(Q))
	{
		return FALSE;
	}
	Q->front = (Q->front + 1) % MAXQUEUE;
	return TRUE;	
}

void ClearAQueue(AQueue *Q)
{
	int i = Q->front;
	if (IsEmptyAQueue(Q))
	{
		return FALSE;
	}
	while (i != Q->rear)
	{
		i = 0;
		i++;
	}
	Q->front = Q->rear = 0;
}

Status TraverseAQueue(const AQueue *Q, void(*foo)(void *q)) //遍历函数操作
{
	if (IsEmptyAQueue(Q))
	{
		return FALSE;
	}
	(*foo)((void *)Q);
	return TRUE;
}

void APrint(void *q)
{
	AQueue *Q = (AQueue *)q;
	int temp = Q->front;
	printf("队列如下：");
	while (temp != Q->rear)
	{
		printf("%d\t", *(int *)(Q->data) + temp * 4);
		temp++;
	}
}

//链表




void InitLQueue(LQueue *Q)
{
	Q->front = Q->rear = (Node *)malloc(sizeof(Node));
	Q->rear->next = NULL;   //rear.next始终指向NULL,头结点front不动
}


void DestoryLQueue(LQueue *Q)
{
	while (Q->front)
	{
		Q->rear = Q->rear->next;
		free(Q->front);
		Q->front = Q->rear;
	}
}


Status IsEmptyLQueue(const LQueue *Q)
{
	if (Q->front->next == NULL)
	{
		return FALSE;
	}
	else
	{
		return TRUE;
	}
}

Status GetHeadLQueue(LQueue *Q, void *e)
{
	int data;
	data = e;
	if (Q->front == NULL)
	{
		return FALSE;
	}
	data = Q->front->data;
}

int LengthLQueue(LQueue *Q)
{
	int k = 0;
	Node *f, *r;
	f = r = (Node*)malloc(sizeof(Node));
	f = Q->front;
	r = Q->rear;
	if (r == NULL)
	{
		return 0;
	}
	else
	{
		while (f!=NULL)
		{
			k++;
			f = f->next;
		}
		return k;
	}
}

Status EnLQueue(LQueue *Q, void *data)
{
	Node *p;
	int data1;
	data1 = data;
	p = (Node *)malloc(sizeof(Node));
	p->data = data1;
	p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	return TRUE;
}

Status DeLQueue(LQueue *Q)
{
	Node *p;
	int i;
	pritnf("出队列：\n");
	scanf("%d", &i);
	while (i != 0)
	{
		p = Q->front;
		Q->front = Q->front->next;
		free(p);
		i--;
	}
	p = NULL;
	return TRUE;
}

void ClearLQueue(LQueue *Q)
{
	Node *p = Q->front;
	while (p != NULL)
	{
		Q->front = Q->front->next;
		free(p);
		p = Q->front;
	}
}

Status TraverseLQueue(const LQueue *Q, void(*foo)(void *q))
{
	if (Q->rear == Q->front)
	{
		return FALSE;
	}
	Node *p = Q->front->next;
	while (p)
	{
		printf("%d\t", p->data);
		p = p->next;
	}
	return TRUE;
}

void LPrint(void *q)
{
	Node *p;
	LQueue	*Q;
	Q = q;
	p = Q->front->next;
	printf("队列为：\n");
	while (p != NULL)
	{
		printf("%d", p->data);
		p = p->next;
	}
}
