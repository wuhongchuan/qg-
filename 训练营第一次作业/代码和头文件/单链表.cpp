#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

typedef struct Node
{
	int data;
	struct Node *next;
}*ptr_Node, Node;   //�����

typedef enum Status
{
	SUCCESS,
	ERROR
}Status;

//������������һ�������ɹ��򷵻�ͷ�ڵ㣬ʧ�ܷ��� NULL 
ptr_Node create(int n)
{
	ptr_Node head, p, q;
	head = (ptr_Node)malloc(sizeof(Node));   
	head->next = NULL;
	p = head;                                  //��pָ���һ�����
	if (p == NULL)
	{
		return NULL;
	}
	for (int i = 1; i < n+1 ; i++)
	{
		q = (ptr_Node)malloc(sizeof(ptr_Node));
		printf("\n�����%d�����ݣ�",i);
		scanf("%d",&q->data);
		p->next = q;
		p = q;
	}
	q->next = NULL;                  //��β�ڵ��ÿ�
	return head;                     //����ͷָ��
}

//�ڵ� index λ������� node ��� 
//����ɹ����� SUCCESS��ʧ�ܷ��� ERROR 
void insert(ptr_Node head,int index, int data)
{
	ptr_Node q,p;
	int j;
	if(index < 1)
	{
		printf("\n����������"); 
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

//ɾ���� index λ�ڵ����Ľڵ㣬��ɾ���Ľ���ֵ���浽��*data���� 
//ɾ���ɹ����� SUCCESS������������� ERROR 
void deleted(ptr_Node head, int index, int data1)
{
	ptr_Node q,p;
	int j;
	if(index < 1)
	{
		printf("\n����������"); 
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
//�������в��ҽڵ�ֵ�� data ��ȵĽڵ㣬�������ҵ��ĵ�һ���ڵ��ǰһ���ڵ��λ�� 
//������ͷ�ڵ���ȣ����� 0����û�ҵ����������������-1
void search(ptr_Node head, int data)
{
	ptr_Node p;
	p = head;
	int i = 1;
	while (p != NULL)
	{
		if (p->data == data)
		{
			printf("\n���Ԫ��������������ͬ��Ԫ���У��ǰ��λ�ڵ�%dλ\n",i-1);
			break;
		}
		p = p->next;
		i++;
	}
}

//�������� index λ�����Ľ���ֵ�޸�Ϊ(*data)����ԭֵ���浽(*data) 
//�޸ĳɹ����� SUCCESS������������� ERROR 
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

//����ѡ��,ʵ�ֵ������սڵ�ֵ��С�������� 
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

//��������ֵ����һ���ĸ�ʽ�����ÿ�ж��ٸ��Լ����壬��ʽԽƯ��Խ�ã� 
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
		printf("\n\n\n�������һ��������");
		printf("\n1--����������\n2--��ӽ��\n3--ɾ�����\n4--�ҵ����е�Ԫ�أ�����������Ԫ�ص�λ��\n5--�޸ı��е�Ԫ��\n6--��������Ԫ�ؽ�������һ��\n7--�����ǰ���е�Ԫ��\n0--�˳�\n");
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
    			printf("\n�������������ֵ�λ��:");
    			scanf("%d",&index);
    			printf("\n�����������:");
    			scanf("%d",&data);
    			insert(head, index, data);
    			printf("\n����������Ԫ�غ��Ϊ:\n");
    			print(head);
    			break;
    		case 3:
    			printf("\n����ɾ���ڼ���Ԫ�أ�");
    			scanf("%d",&index);
    			deleted(head, index, data1);
    			printf("\n�������ɾ�����Ϊ:\n");
    			print(head);
    			break;
    		case 4:
    			printf("\n��������ҵ�Ԫ�أ��һ�������һ������λ��:");
				scanf("%d",&data2);
				search(head, data2);
				break;
			case 5:
				printf("\n�����޸ĵڼ���Ԫ�أ�");
				scanf("%d",&index);
				printf("\n������������滻����:");
    			scanf("%d",&data3);
    			edit(head, index+1, data3);
    			printf("\n��������Ϊ:\n");
    			print(head);
				break;
			case 6:
				sort(head);
				printf("\n��ǰ����Ԫ����������� : \n");
				print(head);
				break;
			case 7:
      			printf("\n��ǰ�������� : \n");
     			print(head);
      			break;
    		case 0:
     			break;
     		default:
      			printf("������������һ��\n");
    	}
	} 
	system("pause");
	return 0;
}

/*    ptr_Node head;
      struct Node *head;      */


