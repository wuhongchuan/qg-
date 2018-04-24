#include <stdio.h>  
#include <stdlib.h>  
#include <malloc.h> 

typedef struct TNode 
{ 
	int data; 
	struct TNode *next;
	struct TNode *pre;
}TNode, *ptr_TNode;

typedef enum Status 
{
	SUCCESS,
	ERROR 
}Status;

ptr_TNode create(int n)
{
	ptr_TNode head,p,q;
	int x;
	head = (ptr_TNode)malloc(sizeof(ptr_TNode));
	head->next = NULL;
	head->pre = NULL;
	p = head;
	for(int i=0;i < n; i++)
	{
		printf("输入链表第%d个元素:",i+1);
		q = (ptr_TNode)malloc(sizeof(ptr_TNode));
		scanf("%d",&x);
		q->data = x;
		q->next = NULL;
		q->pre = p;
		p->next = q;
		p = q;
	}
	printf("\n\n");
	return head;	
} 

//双向链表,在第 index 位后面插入 node 结点 
//插入成功返回 SUCCESS，失败返回 ERROR 
void insert_T(ptr_TNode head, int x, int index)
{
	ptr_TNode h,p,q;
	h = (ptr_TNode)malloc(sizeof(ptr_TNode));
	int i;
	if(index < 1)
	{
		printf("\n出错啦！！"); 
	} 
	h->data = x;
	p = head;
	q = p->next;
	for(i = 1;i < index; i++)//查找指定的位置//
	{
		p=p->next;
		q=p->next;
	}
	p->next=h;
	h->pre=p;
	h->next=q;
	q->pre=h;
}

//双向链表的删除
Status delete_T(ptr_TNode head, int index)
{
	ptr_TNode p = NULL;
	int i;
	if(index < 1)
	{
		printf("\n出错啦！！"); 
	} 
	for(i = 1;i < index; i++)//查找指定的位置//
	{
		head = head->next;
	}
	p = (ptr_TNode)malloc(sizeof(ptr_TNode));
	p = head->next->next;
	free(head->next);
	head->next = p;
	if( p != NULL)
	{
		p->pre = head;
	}
}

//将链表结点值按照一定的格式输出（每行多少个自己定义，格式越漂亮越好）
void print(ptr_TNode head)
{
	ptr_TNode p;
	p = head->next;
	while(p != NULL)
	{
		printf("%d\t",p->data);
		p = p->next;
	}
	printf("\n\n");
}

int main()
{
	int x,index,data,data1,data2,data3;
	int i = 1; 
	ptr_TNode head;
	while(i)
	{
		printf("********************** 各种操作 **********************\n");
		printf(" 1.构建双向链表\n");
		printf(" 2.输出双向链表\n");
		printf(" 3.双向链表的插入\n");
		printf(" 4.双向链表的删除\n");
		printf(" 0.退出\n");
		printf("******************************************************\n");
		scanf("%d",&i);
    	switch(i)
    	{
    		case 1:
      			printf("\n你想链表有多长？\n");
				scanf("%d",&x);
     			head = create(x);
				printf("\n链表数据输出如下：\n");
    			print(head);
    			break;
    		case 2:
    			printf("\n链表数据输出如下：\n");
    			print(head);
    			break;
			case 3:
    			printf("\n输入你想插入的数字:");
    			scanf("%d",&index);
    			printf("\n想把它插在哪个位置:");
    			scanf("%d",&data);
    			insert_T(head, index, data);
    			printf("\n这个链表添加元素后变为:\n");
    			print(head);
    			break;
    		case 4:
    			printf("\n你想删除第几个元素？");
    			scanf("%d",&index);
    			delete_T(head, index);
    			printf("\n这个链表删除后变为:\n");
    			print(head);
    			break;
    		default:
      			printf("出错啦！再试一次\n");
    	}
	}
	system("pause");
	return 0;
	
}
