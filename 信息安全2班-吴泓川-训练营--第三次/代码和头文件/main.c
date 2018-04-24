#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "queue.h"

int main()
{
	AQueue *Q;
	Q = (AQueue*)malloc(sizeof(AQueue));
	void* data = 0;
	int data1;
	int length = 0;
	int i;
    InitAQueue(&Q);
	printf("丢进十个数字：\n");
	for (i = 0; i < 10; i++)
	{
		data = i;
		printf("%d\t", i);
		EnAQueue(&Q, data);
	}
	printf("\n");
	printf("丢出十个数字：\n");
	for ( i = 0; i < 10; i++)
	{
		data1 = DeAQueue(&Q);
		printf("%d\t", data1);
	}
	printf("\n");
	system("pause");
	return 0;
}