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
		printf("���������%d��Ԫ��:",i+1);
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

//˫������,�ڵ� index λ������� node ��� 
//����ɹ����� SUCCESS��ʧ�ܷ��� ERROR 
void insert_T(ptr_TNode head, int x, int index)
{
	ptr_TNode h,p,q;
	h = (ptr_TNode)malloc(sizeof(ptr_TNode));
	int i;
	if(index < 1)
	{
		printf("\n����������"); 
	} 
	h->data = x;
	p = head;
	q = p->next;
	for(i = 1;i < index; i++)//����ָ����λ��//
	{
		p=p->next;
		q=p->next;
	}
	p->next=h;
	h->pre=p;
	h->next=q;
	q->pre=h;
}

//˫�������ɾ��
Status delete_T(ptr_TNode head, int index)
{
	ptr_TNode p = NULL;
	int i;
	if(index < 1)
	{
		printf("\n����������"); 
	} 
	for(i = 1;i < index; i++)//����ָ����λ��//
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

//��������ֵ����һ���ĸ�ʽ�����ÿ�ж��ٸ��Լ����壬��ʽԽƯ��Խ�ã�
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
		printf("********************** ���ֲ��� **********************\n");
		printf(" 1.����˫������\n");
		printf(" 2.���˫������\n");
		printf(" 3.˫������Ĳ���\n");
		printf(" 4.˫�������ɾ��\n");
		printf(" 0.�˳�\n");
		printf("******************************************************\n");
		scanf("%d",&i);
    	switch(i)
    	{
    		case 1:
      			printf("\n���������ж೤��\n");
				scanf("%d",&x);
     			head = create(x);
				printf("\n��������������£�\n");
    			print(head);
    			break;
    		case 2:
    			printf("\n��������������£�\n");
    			print(head);
    			break;
			case 3:
    			printf("\n����������������:");
    			scanf("%d",&index);
    			printf("\n����������ĸ�λ��:");
    			scanf("%d",&data);
    			insert_T(head, index, data);
    			printf("\n����������Ԫ�غ��Ϊ:\n");
    			print(head);
    			break;
    		case 4:
    			printf("\n����ɾ���ڼ���Ԫ�أ�");
    			scanf("%d",&index);
    			delete_T(head, index);
    			printf("\n�������ɾ�����Ϊ:\n");
    			print(head);
    			break;
    		default:
      			printf("������������һ��\n");
    	}
	}
	system("pause");
	return 0;
	
}
