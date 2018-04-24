#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "stack.h" 

//顺序栈(基于数组的)
Status initStack(SqStack *s, int sizes)  //初始化链表
{
	s->top = -1;
	s->size = sizes;
	return OK;
}

Status isEmptyStack(SqStack *s)   //判断链表是否为空
{
	if (s->top == -1)
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}


Status getTopStack(SqStack *s, ElemType *e)   //得到链表头元素
{	
	if (s == NULL)
	{
		return ERROR;
	}
	*e = s->elem[s->top];
	return OK;
}


Status clearStack(SqStack *s)   //清空链表
{
	if (s == NULL)
	{
		return ERROR;
	}
	s->top = -1;
	return OK;
}


Status destoryStack(SqStack *s)  //销毁链表
{
	if (s == NULL)
	{
		return ERROR;
	}
	free(s);
	return OK;
}


Status stackLength(SqStack *s, int length)   //检测链表长度
{

	if (s == NULL)
	{
		return ERROR;
	}
	length = s->size;
	return OK;
}

Status pushStack(SqStack *s, ElemType datas)  //入栈
{
	if (s->top == s->size - 1)
	{
		return ERROR;
	}
	s->top++;
	s->elem[s->top] = datas;
	return OK;
}

Status popStack(SqStack *s, ElemType *datas)   //出栈
{
	if (isEmptyStack(s))
	{
		return ERROR;
	}
	*datas = s->elem[s->top];
	s->top--;
	return OK;
}



//链栈(基于链表的)
Status initLStack(LinkStack *s)   //初始化
{
	LinkStackPtr S=(LinkStackPtr)malloc(sizeof(StackNode));
	S->next = NULL;
	s->top = S;
	return OK;
}

Status isEmptyLStack(LinkStack *s)  //判断链表是否为空
{
	if (s->top == NULL)
	{
		return OK;
	}
	else
	{
		return ERROR;
	}
}

Status getTopLStack(LinkStack *s, ElemType *e)  //得到链表头元素
{
	if (s == NULL)
	{
		return ERROR;
	}
	*e = s->top->data;
	return OK;
}

Status clearLStack(LinkStack *s)   //清空链表
{
	if (s == NULL)
	{
		return ERROR;
	}
	s->top = NULL;
	return OK;

}

Status destoryLStack(LinkStack *s)   //销毁链表
{
	if (s == NULL)
	{
		return ERROR;
	}
	s->top = NULL;
	free(s);
	return OK;
	
}

Status LStackLength(LinkStack *s, int *length)    //检测链表长度
{
	if (s == NULL)
	{
		return ERROR;
	}
	*length = s->count - 1;
	return OK;
}

Status pushLStack(LinkStack *s, ElemType datas)   //入栈
{
	LinkStackPtr p;
	if(p==NULL)
	{
		return ERROR;
	}
	else
	{
		p->data = datas;
		p->next = s->top;
		s->top = p;
	}
}

Status popLStack(LinkStack *s, ElemType *datas)   //出栈
{
	LinkStackPtr p;
	if (p == NULL)
	{
		return ERROR;
	}
	*datas = s->top->data;
	p = s->top;
	s->top = s->top->next;
	free(p);
	return OK;
}


