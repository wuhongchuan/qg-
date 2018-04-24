#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "stack.h" 

int main()
{
	printf("现在是数组栈：\n\n\n"); 
	int i = 1;
	SqStack s;
	initStack(&s, STACK_H_INCLUDED);
			printf("已经弹入了1~10\n"); 
	for(;i < 11; i++)
	{
		pushStack(&s, i);
	}
	int e, length;
	popStack(&s, &e);
	printf("弹出的栈顶元素 %d\n", e); 
	printf("栈自觉看看是不是空的：%d(1：是 0：否)\n", isEmptyStack(&s));  
    getTopStack(&s, &e); 
    printf("现在的栈顶元素%d\n", e);  
    clearStack(&s); 
    printf("清栈咯！\n清栈之后，自觉判断栈是不是空的：%d(1：是 0：否)\n",isEmptyStack(&s));  
/*	while(!isEmptyStack(&s))
	{
		int temp;
		popStack(&s, &temp);
		printf("%d\n",temp);*/
	printf("\n\n\n现在是链表栈：");
	ElemType data;
	int j,h,g;
	LinkStack s1;
	initLStack(&s1);
	int k;
	printf("请输入五个要入栈的值：\n");  
	for(k = 0;k < 5;k++)
	{
		scanf("%d",&data);  
   		pushLStack(&s1, data);
	}
	printf("自觉判断栈是不是空的：%d(1：是 0：否)\n",isEmptyLStack(&s1));
	popLStack(&s1, &j);
	printf("弹出的栈顶元素 %d\n", j); 
	getTopLStack(&s1, &h);
	LStackLength(&s1,&g);
	clearLStack(&s1);
	printf("清栈咯！\n清栈之后，自觉判断栈是不是空的：%d(1：是 0：否)\n",isEmptyLStack(&s1)); 
	system("pause");
	return 0;
}








