#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "stack.h" 

int main()
{
	printf("����������ջ��\n\n\n"); 
	int i = 1;
	SqStack s;
	initStack(&s, STACK_H_INCLUDED);
			printf("�Ѿ�������1~10\n"); 
	for(;i < 11; i++)
	{
		pushStack(&s, i);
	}
	int e, length;
	popStack(&s, &e);
	printf("������ջ��Ԫ�� %d\n", e); 
	printf("ջ�Ծ������ǲ��ǿյģ�%d(1���� 0����)\n", isEmptyStack(&s));  
    getTopStack(&s, &e); 
    printf("���ڵ�ջ��Ԫ��%d\n", e);  
    clearStack(&s); 
    printf("��ջ����\n��ջ֮���Ծ��ж�ջ�ǲ��ǿյģ�%d(1���� 0����)\n",isEmptyStack(&s));  
/*	while(!isEmptyStack(&s))
	{
		int temp;
		popStack(&s, &temp);
		printf("%d\n",temp);*/
	printf("\n\n\n����������ջ��");
	ElemType data;
	int j,h,g;
	LinkStack s1;
	initLStack(&s1);
	int k;
	printf("���������Ҫ��ջ��ֵ��\n");  
	for(k = 0;k < 5;k++)
	{
		scanf("%d",&data);  
   		pushLStack(&s1, data);
	}
	printf("�Ծ��ж�ջ�ǲ��ǿյģ�%d(1���� 0����)\n",isEmptyLStack(&s1));
	popLStack(&s1, &j);
	printf("������ջ��Ԫ�� %d\n", j); 
	getTopLStack(&s1, &h);
	LStackLength(&s1,&g);
	clearLStack(&s1);
	printf("��ջ����\n��ջ֮���Ծ��ж�ջ�ǲ��ǿյģ�%d(1���� 0����)\n",isEmptyLStack(&s1)); 
	system("pause");
	return 0;
}








