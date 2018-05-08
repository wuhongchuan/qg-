#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "BinartTree.h"

//�������������ն�����T
Status InitBiTree(BiTree *T)
{
	*T = NULL;
	return SUCCESS;
}

Status DestroyBiTree(BiTree T) 
{
	if(T)
	{
		DestroyBiTree(T->lchild);
		DestroyBiTree(T->rchild);		
		free(T);
		printf("���������ٳɹ�!\n");
		return SUCCESS;
	}
	else
	{
		return ERROR;	
	}
}
	
Status CreateBiTree(BiTree &T)  
{//�������������������н���ֵ���ո��ַ���ʾ������������������ʾ�Ķ�����T��  
	char ch;
	scanf("%c",&ch);
	{
		if(ch!='*'&&ch!='+'&&ch!='-'&&ch!='/')
		{
			T = (BiTNode *)malloc(sizeof(BiTNode));
			T->data = ch;
			T->lchild = NULL;
			T->rchild = NULL;	 
		}
		else
		{
			T = (BiTNode *)malloc(sizeof(BiTNode));
			T->data = ch;      //���ɸ����  
    		CreateBiTree(T->lchild);//����������  
    		CreateBiTree(T->rchild);//���������� 	
			return SUCCESS; 
		}		
	}	
}  

Status PreOrderTraverse(BiTree T,Status(* visit)(TElemType e))  //�������
{//���ö�������洢�ṹ��visit�Ƕ�����Ԫ�ز�����Ӧ�ú���     
    if(T)
	{  
        visit(T->data);
		PreOrderTraverse(T->lchild,visit);
		PreOrderTraverse(T->rchild,visit);
		return SUCCESS;  					
    }  
    else
	{
		return ERROR;  
	} 
}  


Status InOrderTraverse(BiTree T, Status(* visit)(TElemType e))	//�������
{
	if(T)
	{          
		InOrderTraverse(T->lchild,visit);
		visit(T->data);
		InOrderTraverse(T->rchild,visit);
		return SUCCESS;  					
    }  
    else
	{
		return ERROR;  
	} 
}


Status PostOrderTraverse(BiTree T, Status(* visit)(TElemType e))	//�������
{
	if(T)
	{  
        
		PostOrderTraverse(T->lchild,visit);
		PostOrderTraverse(T->rchild,visit);
		visit(T->data);
		return SUCCESS;  					
    }  
    else
	{
		return ERROR;  
	} 
}


Status LevelOrderTraverse(BiTree T)  //�������
{
    BiTree q[100];
    q[0] = T;
    int front = 0;
    int rear = 1;
    if(T)
    {
    	while (front < rear)
    	{
        	int last = rear;
        	while (front < last)
        	{
            	printf("%c", q[front]->data);
            	if (q[front]->lchild)
            	{
            		q[rear++] = q[front]->lchild;
				}
                if (q[front]->rchild)
                {
                	q[rear++] = q[front]->rchild;
				}    
            ++front;
        	}
    	}
	}   
}

int Value(BiTree T)			//������Ķ�������ֵ
{	
 	BiTree p;//�� 
 	BiTree q;//�� 
 	p = T;
 	q = T->rchild; 
 	if(q->data=='+'||q->data == '-'||q->data == '*'||q->data == '/')
 	{
		Value(q);
		op(q);
	}
	if(q->data>'0'&&q->data<='9')
	{	
		if(p->data == '*')
		{
			p->data = (p->lchild->data-48)*(q->data-48);
			free(p->lchild);
 			free(q);
		}
		if(p->data == '/')
		{
			p->data = (p->lchild->data-48)/(q->data-48);
			free(p->lchild);
 			free(q);
		}
		if(p->data == '+')
		{
			p->data = (p->lchild->data-48)+(q->data-48);
			free(p->lchild);
 			free(q);
		}
		if(p->data == '-')
		{
			p->data = (p->lchild->data-48)-(q->data-48);
			free(p->lchild);
 			free(q);
		}
	}	
}

int main()
{
	BiTree T;
	int temp;
	printf("����ǰ׺���ʽ: (�磺+2*34)\n");
    if(CreateBiTree(T))  
    {  
        printf("�����������ɹ�\n");  
    }  
    else
	{
		printf("����������ʧ��\n"); 
		return 0;
	} 
    printf("����������Ϊ��\n");  
    if(PreOrderTraverse(T, Print))  
    {  
        printf("\n");  
    }  
    else 
	{
    	printf("����ʧ��\n");  
	}         
    printf("����������Ϊ��\n");  
    if(InOrderTraverse(T, Print))  
    {  
        printf("\n");  
    }  
    else 
	{
    	printf("����ʧ��\n");  
	} 
    printf("����������Ϊ��\n");  
    if(PostOrderTraverse(T, Print))  
    {  
        printf("\n");  
    }  
    else 
	{
    	printf("����ʧ��\n");  
	} 
	printf("����������Ϊ��\n");  
	if(LevelOrderTraverse(T))
    {  
        printf("\n");  
    }  
    else 
	{
    	printf("����ʧ��\n");  
	} 
	Value(T);
	op(T);
	printf("����������Ϊ��%d\n",T->data);  
	system("pause");		
	return 0;
}

