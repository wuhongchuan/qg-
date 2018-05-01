#include<stdio.h>
#include<stdlib.h>

/*设置三个标记指针，p从前往后遍历，指向第一个非0位置，p2从后往前遍历，指向第一个非2位置
  p0从p开始往后遍历，遇到0就和p交换，遇到1啥都不做，遇到2就和p2交换，p2向前滑动到下一个非2位置
  交换后重新检查p0的值，直到p0和p2相遇 
*/
void colour()
{
	int a[14] = {0,1,2,1,2,0,2,0,1,2,2,1,0,2};
	int temp;
	int i;	
	int p = 0, p0 = 0, p2 = sizeof(a)/4 - 1;
	printf("颜色排序前：");
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
			if(a[p0] == 0)  //如果交换后，p0指向元素为0，则继续将p0和p指向的值进行交换 
			{
				temp = a[p0];
				a[p0] = a[p];
				a[p] = temp;
				++p;  //p向后移动一位
			}
			--p2;  //p2向前移动一位 
			while(a[p2] == 2)
			{
				--p2;
			}
		}
		++p0;	 //将p0向后移动一位 
	}
	printf("\n颜色排序后：");
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
    //min max记录当前处理的这个区间的左极限和右极限
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
     	}//处理一次，将比绑定值小的全部放左边，比绑定值大的放右边
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
	printf("\n排序前：");
	for(i = 0;i < 7;i++ )
	{
		printf("%d\t",a[i]);
	}
    fun(0, 6, a);
	printf("\n第三小的值为：%d\n",a[2]);
} 


int main()
{
	colour();
	Find();	
	printf("\n");
	system("pause");
	return 0;
}
