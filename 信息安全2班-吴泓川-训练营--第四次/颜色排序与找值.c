#include<stdio.h>
#include<stdlib.h>

/*�����������ָ�룬p��ǰ���������ָ���һ����0λ�ã�p2�Ӻ���ǰ������ָ���һ����2λ��
  p0��p��ʼ�������������0�ͺ�p����������1ɶ������������2�ͺ�p2������p2��ǰ��������һ����2λ��
  ���������¼��p0��ֵ��ֱ��p0��p2���� 
*/
void colour()
{
	int a[14] = {0,1,2,1,2,0,2,0,1,2,2,1,0,2};
	int temp;
	int i;	
	int p = 0, p0 = 0, p2 = sizeof(a)/4 - 1;
	printf("��ɫ����ǰ��");
	for(i = 0; i < sizeof(a)/4; ++i)
	{
		printf("%d  ",a[i]);
	}	
	while(a[p] == 0)
	{
		++p;
	}
	while(a[p2] == 2)
	{
		--p2;
	}
	p0 = p;
	while(p0 <= p2)
	{
		if(a[p0] == 0)
		{
			temp = a[p0];
			a[p0] = a[p];
			a[p] = temp;
			++p;		
		}
		else if(a[p0] == 2)
		{
			temp = a[p0];
			a[p0] = a[p2];
			a[p2] = temp;
			if(a[p0] == 0)  //���������p0ָ��Ԫ��Ϊ0���������p0��pָ���ֵ���н��� 
			{
				temp = a[p0];
				a[p0] = a[p];
				a[p] = temp;
				++p;  //p����ƶ�һλ
			}
			--p2;  //p2��ǰ�ƶ�һλ 
			while(a[p2] == 2)
			{
				--p2;
			}
		}
		++p0;	 //��p0����ƶ�һλ 
	}
	printf("\n��ɫ�����");
	for(i = 0; i < sizeof(a)/4; ++i)
	{
		printf("%d  ",a[i]);
	}		
} 





struct node
{
	int min;
 	int max;
};

void fun(int min,int max,int a[])
{
 	int key = a[min];
 	int i = min;
 	int j = max;
 	int temp;
    struct node Stack[100];
    int top = 0;
    Stack[top].min = min;
    Stack[top].max = max;
 	while(top>-1)
 	{
    //min max��¼��ǰ����������������޺��Ҽ���
    	i = min = Stack[top].min;
   	 	j = max = Stack[top].max;
    	top--;
    	key = a[min];
   	 	while(i<j)
    	{
         	while((i<j) && (key <= a[j]))
         	{j--;}
        	if(i < j)
        	{
          	temp = a[i];a[i] = a[j];a[j] = temp;  
          	i++;
        	}
        	while((i<j) && (key >= a[i]))
        	{i++;}
       		if(i < j)
       		{
         	temp = a[i];a[i] = a[j];a[j] = temp; 
         	j--;
       		} 
     	}//����һ�Σ����Ȱ�ֵС��ȫ������ߣ��Ȱ�ֵ��ķ��ұ�
    	if(min < i-1)
    	{
        	top++;
        	Stack[top].min = min;
        	Stack[top].max = i-1;
    	}
    	if(max>i+1)
    	{
       		top++;
        	Stack[top].min = i+1;
        	Stack[top].max = max;
    	}
 	} 
}

void Find()
{
	int a[7] = {5, 2, 8, 4, 3, 7, 6};
	int i;      
	printf("\n����ǰ��");
	for(i = 0;i < 7;i++ )
	{
		printf("%d\t",a[i]);
	}
    fun(0, 6, a);
	printf("\n����С��ֵΪ��%d\n",a[2]);
} 


int main()
{
	colour();
	Find();	
	printf("\n");
	system("pause");
	return 0;
}
