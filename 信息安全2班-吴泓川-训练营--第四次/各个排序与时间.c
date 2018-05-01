#include<stdio.h>
#include<time.h>
#include <stdlib.h>
#define ONE 10000
#define FIVE 50000
#define TWO 200000
#define KEYNUM_31 31     //整形位数 

int Random()
{
	return rand() % 1000;
}
//插入排序 
int i,j;
int iTemp;
int iPos; 

int InsertOne() 
{
	clock_t start = clock();
	int a[ONE];
	for(i=0;i<ONE;i++)
	{
		a[i] = Random();
	}
	for(i=1;i<ONE;i++)
	{
		iTemp=a[i];                //拿出来的值 
		iPos=i-1;
		while((iPos>=0)&&(iTemp<a[iPos]))    //当值小于左边的值时 
		{
			a[iPos+1]=a[iPos];              //左边的值右移一位 
			iPos--;         
		}
		a[iPos+1]=iTemp;                   //插入相应的位置上 
	}
	clock_t diff = clock() - start;
	printf("插入排序：\n");
	printf("10000数据的排序时间为：\t"); 
	printf("%dms\n",diff);
	return diff;
}

int InsertFive() 
{
	clock_t start = clock();
	int a[FIVE];
	for(i=0;i<FIVE;i++)
	{
		a[i] = Random();
	}
	for(i=1;i<FIVE;i++)
	{
		iTemp=a[i];                //拿出来的值 
		iPos=i-1;
		while((iPos>=0)&&(iTemp<a[iPos]))    //当值小于左边的值时 
		{
			a[iPos+1]=a[iPos];              //左边的值右移一位 
			iPos--;         
		}
		a[iPos+1]=iTemp;                   //插入相应的位置上 
	}
	clock_t diff = clock() - start;
	printf("50000数据的排序时间为：\t"); 
	printf("%dms\n",diff);
	return diff;
}

int InsertTwo() 
{
	clock_t start = clock();
	int a[TWO];
	for(i=0;i<TWO;i++)
	{
		a[i] = Random();
	}
	for(i=1;i<TWO;i++)
	{
		iTemp=a[i];                //拿出来的值 
		iPos=i-1;
		while((iPos>=0)&&(iTemp<a[iPos]))    //当值小于左边的值时 
		{
			a[iPos+1]=a[iPos];              //左边的值右移一位 
			iPos--;         
		}
		a[iPos+1]=iTemp;                   //插入相应的位置上 
	}
	clock_t diff = clock() - start;
	printf("200000数据的排序时间为：\t"); 
	printf("%dms\n",diff);
	return diff;
}


//归并排序
void merge(int a[], int low, int mid, int high)
{
	int i, k;
	int *tmp = (int *)malloc((high - low + 1)*sizeof(int));
	int left_low = low;
	int left_high = mid;
	int right_low = mid + 1;
	int right_high = high;
	
	for(k = 0; left_low <= left_high && right_low <= right_high; k++) // 比较两个指针所指向的元素
	{
		if(a[left_low] <= a[right_low])
		{
			tmp[k] = a[left_low++];
		}
		else
		{
			tmp[k] = a[right_low++];
		}
	}
		
	if(left_low <= left_high)
	{
		for(i = left_low; i <= left_high; i++)
		{
			tmp[k++] = a[i];
		}
	} 	
	
	if(right_low <= right_high)
	{
		for(i = right_low; i <= right_high; i++)
		{
			tmp[k++] = a[i];
		}
	} 
	
	for( i = 0; i < high - low + 1; i++)
	{
		a[low + i] = tmp[i];
	}
	free(tmp);		
}

void merge_sort(int a[], int first, int last)
{
	int mid = 0;
	if( first < last)
	{
		mid = (first + last)/2;
		merge_sort(a, first, mid);
		merge_sort(a, mid + 1, last);
		merge(a, first, mid, last);		
	}
}

int MergeOne() 
{
	int i;
	clock_t start = clock();
	int a[ONE];
	for(i=0;i<ONE;i++)
	{
		a[i] = Random();
	}
	merge_sort(a,0,ONE-1);  
	clock_t diff = clock() - start;
	printf("\n\n归并排序：\n");
	printf("10000数据的排序时间为：\t"); 
	printf("%dms\n",diff);
	return diff;

}

int MergeFive() 
{
	int i;
	clock_t start = clock();
	int a[FIVE];
	for(i=0;i<FIVE;i++)
	{
		a[i] = Random();
	}
	merge_sort(a,0,FIVE-1);  // 排序
	clock_t diff = clock() - start;
	printf("50000数据的排序时间为：\t"); 
	printf("%dms\n",diff);
	return diff;
}

int MergeTwo() 
{
	int i;
	clock_t start = clock();
	int a[TWO];
	for(i=0;i<TWO;i++)
	{
		a[i] = Random();
	}
	merge_sort(a,0,TWO-1);  // 排序
	clock_t diff = clock() - start;
	printf("200000数据的排序时间为：\t"); 
	printf("%dms\n",diff);
	return diff;

}
 

//基数排序
// 找到num的从低到高的第pos位的数据  
int GetNumInPos(int num,int pos)  
{  
	int i;
    int temp = 1;  
    for(i = 0; i < pos - 1; i++)
	{
	    temp *= 10; 	
	}
    return (num / temp) % 10;  
}  
  
  
//pDataArray 无序数组, iDataNum为无序数据个数  
void RadixSort(int* pDataArray, int iDataNum)  
{  
	int i, k, j, pos;
    int *radixArrays[10];    //分别为0~9的序列空间  
    for (i = 0; i < 10; i++)  
    {  
        radixArrays[i] = (int *)malloc(sizeof(int) * (iDataNum + 1));  
        radixArrays[i][0] = 0;    //index为0处记录这组数据的个数  
    }  
      
    for (pos = 1; pos <= KEYNUM_31; pos++)    //从个位开始到31位  
    {  
        for (i = 0; i < iDataNum; i++)    //分配过程  
        {  
            int num = GetNumInPos(pDataArray[i], pos);  
            int index = ++radixArrays[num][0];  
            radixArrays[num][index] = pDataArray[i];  
        }  
          
        for (i = 0, j =0; i < 10; i++)    //收集  
        {  
            for (k = 1; k <= radixArrays[i][0]; k++)  
                pDataArray[j++] = radixArrays[i][k];  
            radixArrays[i][0] = 0;    //复位  
        }  
    }  
}

int RadixCountOne()
{
	int n, i; 
	clock_t start = clock();
	n = 10000;;
    int *a = (int *)malloc(sizeof(int) * n);
	for (i = 0; i<n; i++)  
    {  
        a[i] = rand() % 100;  
    }     
    RadixSort(a, n);  
	clock_t diff = clock() - start;
	printf("\n\n基数排序：\n");
	printf("%d数据的排序时间为：\t",n); 
	printf("%dms\n",diff);
	return diff;
}  

int RadixCountFive()
{
	int n, i; 
	clock_t start = clock();
	n = 50000;
    int *a = (int *)malloc(sizeof(int) * n);
	for (i = 0; i<n; i++)  
    {  
        a[i] = rand() % 100;  
    }     
    RadixSort(a, n);  
	clock_t diff = clock() - start;
	printf("%d数据的排序时间为：\t",n); 
	printf("%dms\n",diff);
	return diff;
}

int RadixCountTwo()
{
	int n, i; 
	clock_t start = clock();
	n = 200000;
    int *a = (int *)malloc(sizeof(int) * n);
	for (i = 0; i<n; i++)  
    {  
        a[i] = rand() % 100;  
    }     
    RadixSort(a, n);  
	clock_t diff = clock() - start;
	printf("%d数据的排序时间为：\t",n); 
	printf("%dms\n",diff);
	return diff;
}



//计数排序

void count_sort(int *a, int *sorted_a, int n)  
{  
    int *count_a = (int *)malloc(sizeof(int) * 100);  
    int i;      //初始化计数数组   
    for(i = 0; i<100; i++)
	{
		count_a[i] = 0;  
	}      
    //统计i的次数   
    for(i = 0;i<n;i++)
	{
		count_a[a[i]]++; 
	}      
    //对所有的计数累加   
    for(i = 1; i<100; i++)
	{
		count_a[i] += count_a[i-1];   
	}          
    //逆向遍历源数组（保证稳定性），根据计数数组中对应的值填充到先的数组中   
    for(i = n; i>0; i--)  
    {  
        sorted_a[count_a[a[i-1]]-1] = a[i-1];  
        count_a[a[i-1]]--;    
    }   
    free(count_a);  
} 

int CountOne()
{
	int n,i;  
	clock_t start = clock();
   	n = 10000;        
    int *arr = (int *)malloc(sizeof(int) * n);  
    int *sorted_arr = (int *)malloc(sizeof(int) * n);   
    for (i = 0; i<n; i++)  
    {  
        arr[i] = rand() % 100;  
    }  
    count_sort(arr, sorted_arr, n);   
    clock_t diff = clock() - start;
    printf("\n\n计数排序：\n");
	printf("%d数据的排序时间为：\t",n); 
	printf("%dms\n",diff);
    return diff;
} 

int CountFive()
{
	int n,i;  
	clock_t start = clock();
   	n = 50000;        
    int *arr = (int *)malloc(sizeof(int) * n);  
    int *sorted_arr = (int *)malloc(sizeof(int) * n);   
    for (i = 0; i<n; i++)  
    {  
        arr[i] = rand() % 100;  
    }  
    count_sort(arr, sorted_arr, n);   
    clock_t diff = clock() - start;
	printf("%d数据的排序时间为：\t",n); 
	printf("%dms\n",diff);
    return diff;
} 

int CountTwo()
{
	int n,i;  
	clock_t start = clock();
   	n = 200000;        
    int *arr = (int *)malloc(sizeof(int) * n);  
    int *sorted_arr = (int *)malloc(sizeof(int) * n);   
    for (i = 0; i<n; i++)  
    {  
        arr[i] = rand() % 100;  
    }  
    count_sort(arr, sorted_arr, n);   
    clock_t diff = clock() - start;
	printf("%d数据的排序时间为：\t",n); 
	printf("%dms\n",diff);
    return diff;
} 
 
 
//快速排序递归 

//快速排序一次划分算法
int Partition(int a[], int first, int end)
{
    int i, j, temp;
    i = first;
    j = end;
    while (i < j)
	{
        //右侧扫描
        while (i < j&&a[i] < a[j])j--;
        if (i < j)
		{
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
        }
        //左侧扫描
        while (i < j&&a[i] <= a[j])i++;
        if (i < j)
		{
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            j--;
        }
    }
    return i;
}

//递归
void QuickSort(int a[], int first, int end)
{
    int p;
    if (first < end)
	{
        p = Partition(a, first, end);
        QuickSort(a, first, p - 1);
        QuickSort(a, p + 1, end);
    }
}

int QSort_RecursionOne()
{
	int n,i;  
	clock_t start = clock();
    n = 10000;         
    int *a = (int *)malloc(sizeof(int) * n);  
    for (i = 0; i<n; i++)  
    {  
        a[i] = rand() % 100;  
    }  
    QuickSort(a, 0, n - 1);
    clock_t diff = clock() - start;
    printf("\n\n快排递归：\n");
	printf("%d数据的排序时间为：\t",n); 
	printf("%dms\n",diff);  
	return diff;  
}  

int QSort_RecursionTwo()
{
	int n,i;  
	clock_t start = clock();
    n = 200000;         
    int *a = (int *)malloc(sizeof(int) * n);  
    for (i = 0; i<n; i++)  
    {  
        a[i] = rand() % 100;  
    }  
    QuickSort(a, 0, n - 1);
    clock_t diff = clock() - start;
	printf("%d数据的排序时间为：\t",n); 
	printf("%dms\n",diff);  
	return diff;  
}

int QSort_RecursionFive()
{
	int n,i;  
	clock_t start = clock();
    n = 50000;         
    int *a = (int *)malloc(sizeof(int) * n);  
    for (i = 0; i<n; i++)  
    {  
        a[i] = rand() % 100;  
    }  
    QuickSort(a, 0, n - 1);
    clock_t diff = clock() - start;
	printf("%d数据的排序时间为：\t",n); 
	printf("%dms\n",diff);  
	return diff;  
}


//快排非递归
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


int QSortOne()
{
	int n,i;  
	clock_t start = clock();
    n = 10000;        
    int *a = (int *)malloc(sizeof(int) * n);  
    for (i = 0; i<n; i++)  
    {  
        a[i] = rand() % 100;  
    }  
    fun(0, n - 1, a);
    clock_t diff = clock() - start;
    printf("\n\n快排非递归：\n");
	printf("%d数据的排序时间为：\t",n); 
	printf("%dms\n",diff);  
	return diff;  
} 

int QSortFive()
{
	int n,i;  
	clock_t start = clock();
    n = 50000;        
    int *a = (int *)malloc(sizeof(int) * n);  
    for (i = 0; i<n; i++)  
    {  
        a[i] = rand() % 100;  
    }  
    fun(0, n - 1, a);
    clock_t diff = clock() - start;
	printf("%d数据的排序时间为：\t",n); 
	printf("%dms\n",diff);
	return diff;    
} 

int QSortTwo()
{
	int n,i;  
	clock_t start = clock();
    n = 200000;        
    int *a = (int *)malloc(sizeof(int) * n);  
    for (i = 0; i<n; i++)  
    {  
        a[i] = rand() % 100;  
    }  
    fun(0, n - 1, a);
    clock_t diff = clock() - start;
	printf("%d数据的排序时间为：\t",n); 
	printf("%dms\n",diff); 
	return diff;   
} 

int main()
{
	int Insert1, Insert5, Insert2, Merge1, Merge5, Merge2, RadixCount1, RadixCount5, RadixCount2, Count1, Count5, Count2;
	int QSort_Recursion1, QSort_Recursion5, QSort_Recursion2, QSort1, QSort5, QSort2; 
	srand((unsigned)time(NULL));         /*srand函数*/
	Insert1 = InsertOne();
	Insert5 = InsertFive();
	Insert2 = InsertTwo();
	Merge1 = MergeOne();
	Merge5 = MergeFive();
	Merge2 = MergeTwo();
	RadixCount1 = RadixCountOne();
	RadixCount5 = RadixCountFive();
	RadixCount2 = RadixCountTwo();
	Count1 = CountOne();
	Count5 = CountFive();
	Count2 = CountTwo();
	QSort_Recursion1 = QSort_RecursionOne();
	QSort_Recursion5 = QSort_RecursionFive();
	QSort_Recursion2 = QSort_RecursionTwo();
	QSort1 = QSortOne();
	QSort5 = QSortFive();
	QSort2 = QSortTwo();
	printf("┌───────────────┬──────────────┬───────────┐\n");
	printf("│   排序方式    │     数据     │   时间/ms │\n");
	printf("├───────────────┼──────────────┼───────────┤\n");
	printf("│   插入排序    │       10000  │   %d      │\n",Insert1);
	printf("├───────────────┼──────────────┼───────────┤\n");
	printf("│               │       50000  │   %d    │\n",Insert5);
	printf("├───────────────┼──────────────┼───────────┤\n");
	printf("│               │       200000 │   %d   │\n",Insert2);
	printf("├───────────────┼──────────────┼───────────┤\n");
	printf("│   归并排序    │       10000  │   %d       │\n",Merge1);
	printf("├───────────────┼──────────────┼───────────┤\n");
	printf("│               │       50000  │   %d      │\n",Merge5);
	printf("├───────────────┼──────────────┼───────────┤\n");
	printf("│               │       200000 │   %d      │\n",Merge2);
	printf("├───────────────┼──────────────┼───────────┤\n");
	printf("│   基数排序    │       10000  │   %d      │\n",RadixCount1);
	printf("├───────────────┼──────────────┼───────────┤\n");
	printf("│               │       50000  │   %d      │\n",RadixCount5);
	printf("├───────────────┼──────────────┼───────────┤\n");
	printf("│               │       200000 │   %d     │\n",RadixCount2);
	printf("├───────────────┼──────────────┼───────────┤\n");
	printf("│   计数排序    │       10000  │   %d       │\n",Count1);
	printf("├───────────────┼──────────────┼───────────┤\n");
	printf("│               │       50000  │   %d       │\n",Count5);
	printf("├───────────────┼──────────────┼───────────┤\n");
	printf("│               │       200000 │   %d       │\n",Count2);
	printf("├───────────────┼──────────────┼───────────┤\n");
	printf("│   快排递归    │       10000  │   %d       │\n",QSort_Recursion1);
	printf("├───────────────┼──────────────┼───────────┤\n");
	printf("│               │       50000  │   %d      │\n",QSort_Recursion5);
	printf("├───────────────┼──────────────┼───────────┤\n");
	printf("│               │       200000 │   %d     │\n",QSort_Recursion2);
	printf("├───────────────┼──────────────┼───────────┤\n");
	printf("│   快排非递    │       10000  │   %d       │\n",QSort1);
	printf("├───────────────┼──────────────┼───────────┤\n");
	printf("│               │       50000  │   %d      │\n",QSort5);
	printf("├───────────────┼──────────────┼───────────┤\n");
	printf("│               │       200000 │   %d     │\n",QSort2);
	printf("├───────────────┴──────────────┴───────────┤\n");
	FILE *p;
	char ch[1000000] = {'\0'};
	int i = 0;    
	p = fopen("sort.txt", "r");        
	while(!feof(p))    
	{        
		if(fgetc(p) == '>')       
		{            
			while((ch[i++] = fgetc(p)) != '<')
			ch[i-1] = '\n';        
		}    
	}
	fprintf(p,"%s",ch);  
    printf("\n");
	system("pause");
	return 0;
	fclose(p);
 } 
 
