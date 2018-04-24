#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

typedef struct Node
{
	int data;
	struct Node *next;
}*ptr_Node, Node;   //起别名

typedef enum Status
{
	SUCCESS,
	ERROR
}Status;

//根据数组生成一条链表，成功则返回头节点，失败返回 NULL 
ptr_Node create(int n)
{
	ptr_Node head, p, q;
	head = (ptr_Node)malloc(sizeof(Node));   
	head->next = NULL;
	p = head;                                  //令p指向第一个结点
	if (p == NULL)
	{
		return NULL;
	}
	for (int i = 1; i < n+1 ; i++)
	{
		q = (ptr_Node)malloc(sizeof(ptr_Node));
		printf("\n输入第%d个数据：",i);
		scanf("%d",&q->data);
		p->next = q;
		p = q;
	}
	q->next = NULL;                  //把尾节点置空
	return head;                     //返回头指针
}

//在第 index 位后面插入 node 结点 
//插入成功返回 SUCCESS，失败返回 ERROR 
void insert(ptr_Node head,int index, int data)
{
	ptr_Node q,p;
	int j;
	if(index < 1)
	{
		printf("\n出错啦！！"); 
	} 
	else
	{
		j = 0;
		p = head;
		while(j < index - 1)
		{
			p = p->next;
			j++;
		}
		q = (ptr_Node)malloc(sizeof(ptr_Node));
		q->data = data;
		q->next = p->next;
		p->next = q;
	}
} 

//删除第 index 位节点后面的节点，将删除的结点的值保存到（*data）中 
//删除成功返回 SUCCESS，其他情况返回 ERROR 
void deleted(ptr_Node head, int index, int data1)
{
	ptr_Node q,p;
	int j;
	if(index < 1)
	{
		printf("\n出错啦！！"); 
	} 
	else
	{
		j = 0;
		p = head;
		while(j < index - 1)
		{
			p = p->next;
			j++;
		}
		q = (ptr_Node)malloc(sizeof(ptr_Node));
		q = p->next;
		p->next = q->next;
		data1 = q->data;
		free(q);
	}	
} 
//在链表中查找节点值与 data 相等的节点，并返回找到的第一个节点的前一个节点的位置 
//（例：头节点相等，返回 0），没找到或者其他情况返回-1
void search(ptr_Node head, int data)
{
	ptr_Node p;
	p = head;
	int i = 1;
	while (p != NULL)
	{
		if (p->data == data)
		{
			printf("\n这个元素在所有与它相同的元素中，最靠前的位于第%d位\n",i-1);
			break;
		}
		p = p->next;
		i++;
	}
}

//将链表中 index 位点后面的结点的值修改为(*data)，将原值保存到(*data) 
//修改成功返回 SUCCESS，其他情况返回 ERROR 
void edit(ptr_Node head, int index, int data)
{
	ptr_Node p;
	int temp;
	p = head;
	int i=0;
	while (p != NULL)
	{
		++i;
		if ( i == index)
		{
			break;
		}
		p = p->next;
	}
	head = p;
	head->data = data;
}

//此题选做,实现单链表按照节点值大小升序排序 
void sort(ptr_Node head)
{
	struct Node *p, *q;
	int t;
	for (p = head; p != NULL; p = p->next)
	{
		for (q = p->next ; q != NULL; q=q->next)
		{
			if (p->data < q->data)
			{
				t = q->data;
				q->data = p->data;
				p->data = t;
			}
		}
	}
}

//将链表结点值按照一定的格式输出（每行多少个自己定义，格式越漂亮越好） 
void print(ptr_Node head)
{
	ptr_Node p;
	p = head->next; 
	while (p != NULL)
	{
		printf("%d\t",p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	int x,index,data,data1,data2,data3;
	int i = 1; 
	ptr_Node head;
	while(i)
	{
		printf("\n\n\n请进行下一步操作：");
		printf("\n1--建立新链表\n2--添加结点\n3--删除结点\n4--找到表中的元素，并且输出这个元素的位置\n5--修改表中的元素\n6--把链表里元素降序排序一下\n7--输出当前表中的元素\n0--退出\n");
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
    			printf("\n输入个想添加数字的位置:");
    			scanf("%d",&index);
    			printf("\n输入这个数字:");
    			scanf("%d",&data);
    			insert(head, index, data);
    			printf("\n这个链表添加元素后变为:\n");
    			print(head);
    			break;
    		case 3:
    			printf("\n你想删除第几个元素？");
    			scanf("%d",&index);
    			deleted(head, index, data1);
    			printf("\n这个链表删除后变为:\n");
    			print(head);
    			break;
    		case 4:
    			printf("\n输入想查找的元素，我会告诉你第一个它的位置:");
				scanf("%d",&data2);
				search(head, data2);
				break;
			case 5:
				printf("\n你想修改第几个元素？");
				scanf("%d",&index);
				printf("\n输入这个数字替换掉它:");
    			scanf("%d",&data3);
    			edit(head, index+1, data3);
    			printf("\n这个链表变为:\n");
    			print(head);
				break;
			case 6:
				sort(head);
				printf("\n当前链表元素排序后如下 : \n");
				print(head);
				break;
			case 7:
      			printf("\n当前链表如下 : \n");
     			print(head);
      			break;
    		case 0:
     			break;
     		default:
      			printf("出错啦！再试一次\n");
    	}
	} 
	system("pause");
	return 0;
}

/*    ptr_Node head;
      struct Node *head;      */


