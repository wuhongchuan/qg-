#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "BinartTree.h"

//操作结果：构造空二叉树T
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
		printf("二叉树销毁成功!\n");
		return SUCCESS;
	}
	else
	{
		return ERROR;	
	}
}
	
Status CreateBiTree(BiTree &T)  
{//按先序次序输入二叉树中结点的值，空格字符表示空树，构造二叉链表表示的二叉树T。  
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
			T->data = ch;      //生成根结点  
    		CreateBiTree(T->lchild);//构造左子树  
    		CreateBiTree(T->rchild);//构造右子树 	
			return SUCCESS; 
		}		
	}	
}  

Status PreOrderTraverse(BiTree T,Status(* visit)(TElemType e))  //先序遍历
{//采用二叉链表存储结构，visit是对数据元素操作的应用函数     
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


Status InOrderTraverse(BiTree T, Status(* visit)(TElemType e))	//中序遍历
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


Status PostOrderTraverse(BiTree T, Status(* visit)(TElemType e))	//后序遍历
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


Status LevelOrderTraverse(BiTree T)  //层序遍历
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

int Value(BiTree T)			//构造出的二叉树求值
{	
 	BiTree p;//根 
 	BiTree q;//右 
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
	printf("输入前缀表达式: (如：+2*34)\n");
    if(CreateBiTree(T))  
    {  
        printf("创建二叉树成功\n");  
    }  
    else
	{
		printf("创建二叉树失败\n"); 
		return 0;
	} 
    printf("先序遍历结果为：\n");  
    if(PreOrderTraverse(T, Print))  
    {  
        printf("\n");  
    }  
    else 
	{
    	printf("遍历失败\n");  
	}         
    printf("中序遍历结果为：\n");  
    if(InOrderTraverse(T, Print))  
    {  
        printf("\n");  
    }  
    else 
	{
    	printf("遍历失败\n");  
	} 
    printf("后序遍历结果为：\n");  
    if(PostOrderTraverse(T, Print))  
    {  
        printf("\n");  
    }  
    else 
	{
    	printf("遍历失败\n");  
	} 
	printf("层序遍历结果为：\n");  
	if(LevelOrderTraverse(T))
    {  
        printf("\n");  
    }  
    else 
	{
    	printf("遍历失败\n");  
	} 
	Value(T);
	op(T);
	printf("四则运算结果为：%d\n",T->data);  
	system("pause");		
	return 0;
}

