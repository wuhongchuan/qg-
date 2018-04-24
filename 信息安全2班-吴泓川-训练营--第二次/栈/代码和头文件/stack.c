#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "stack.h" 

//˳��ջ(���������)
Status initStack(SqStack *s, int sizes)  //��ʼ������
{
	s->top = -1;
	s->size = sizes;
	return OK;
}

Status isEmptyStack(SqStack *s)   //�ж������Ƿ�Ϊ��
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


Status getTopStack(SqStack *s, ElemType *e)   //�õ�����ͷԪ��
{	
	if (s == NULL)
	{
		return ERROR;
	}
	*e = s->elem[s->top];
	return OK;
}


Status clearStack(SqStack *s)   //�������
{
	if (s == NULL)
	{
		return ERROR;
	}
	s->top = -1;
	return OK;
}


Status destoryStack(SqStack *s)  //��������
{
	if (s == NULL)
	{
		return ERROR;
	}
	free(s);
	return OK;
}


Status stackLength(SqStack *s, int length)   //���������
{

	if (s == NULL)
	{
		return ERROR;
	}
	length = s->size;
	return OK;
}

Status pushStack(SqStack *s, ElemType datas)  //��ջ
{
	if (s->top == s->size - 1)
	{
		return ERROR;
	}
	s->top++;
	s->elem[s->top] = datas;
	return OK;
}

Status popStack(SqStack *s, ElemType *datas)   //��ջ
{
	if (isEmptyStack(s))
	{
		return ERROR;
	}
	*datas = s->elem[s->top];
	s->top--;
	return OK;
}



//��ջ(���������)
Status initLStack(LinkStack *s)   //��ʼ��
{
	LinkStackPtr S=(LinkStackPtr)malloc(sizeof(StackNode));
	S->next = NULL;
	s->top = S;
	return OK;
}

Status isEmptyLStack(LinkStack *s)  //�ж������Ƿ�Ϊ��
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

Status getTopLStack(LinkStack *s, ElemType *e)  //�õ�����ͷԪ��
{
	if (s == NULL)
	{
		return ERROR;
	}
	*e = s->top->data;
	return OK;
}

Status clearLStack(LinkStack *s)   //�������
{
	if (s == NULL)
	{
		return ERROR;
	}
	s->top = NULL;
	return OK;

}

Status destoryLStack(LinkStack *s)   //��������
{
	if (s == NULL)
	{
		return ERROR;
	}
	s->top = NULL;
	free(s);
	return OK;
	
}

Status LStackLength(LinkStack *s, int *length)    //���������
{
	if (s == NULL)
	{
		return ERROR;
	}
	*length = s->count - 1;
	return OK;
}

Status pushLStack(LinkStack *s, ElemType datas)   //��ջ
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

Status popLStack(LinkStack *s, ElemType *datas)   //��ջ
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


