#include<stdio.h>
#include<stdlib.h>
#include <time.h>


//��������

InsertOne() 
{
	clock_t start = clock();
	int n = 100;
	int i, j, k;  
	int iTemp;
	int iPos;       
    int *a = (int *)malloc(sizeof(int) * n);  	
    for(i = 0; i < 100000; i++)
    {
    	for (j = 0; j < n; j++)  
    	{  
        	a[j] = rand() % 100;  
    	}  
    	printf("\n\n��%d������\n",i+1);
    	for(k = 1;k < n; k++)
		{
			iTemp=a[k];                //�ó�����ֵ 
			iPos=k-1;
			while((iPos>=0)&&(iTemp<a[iPos]))    //��ֵС����ߵ�ֵʱ 
			{
				a[iPos+1]=a[iPos];              //��ߵ�ֵ����һλ 
				iPos--;         
			}
			a[iPos+1]=iTemp;                   //������Ӧ��λ���� 
		}	
    	for( j = 0; j < 100; j++)
		{
			printf("%d ",a[j]);	
		}			
	}	
	clock_t diff = clock() - start;
	printf("\n\n\n��������С����ʮ�������ʱ��Ϊ��\t"); 
	printf("%dms\n",diff);	
}

 

//�鲢���� 
void merge(int a[], int low, int mid, int high)
{
	int i, k;
	int *tmp = (int *)malloc((high - low + 1)*sizeof(int));
	int left_low = low;
	int left_high = mid;
	int right_low = mid + 1;
	int right_high = high;
	
	for(k = 0; left_low <= left_high && right_low <= right_high; k++) // �Ƚ�����ָ����ָ���Ԫ��
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

void mergeOne() 
{
	clock_t start = clock();
	int n = 100;
	int i, j, k;        
    int *a = (int *)malloc(sizeof(int) * n);  
    for(i = 0; i < 100000; i++)
    {
    	for (j = 0; j < n; j++)  
    	{  
        	a[j] = rand() % 100;  
    	}  
    	printf("\n\n��%d������\n",i+1);
    	merge_sort(a,0,n-1);  // ����
    	for( j = 0; j < 100; j++)
		{
			printf("%d ",a[j]);	
		}			
	}		
	clock_t diff = clock() - start;
	printf("\n\n\n�鲢����С����ʮ�������ʱ��Ϊ��\t"); 
	printf("%dms\n",diff);
}

//��������

void count_sort(int *arr, int *sorted_arr, int n)  
{  
    int *count_arr = (int *)malloc(sizeof(int) * 100);  
    int i;   
    //��ʼ����������   
    for(i = 0; i<100; i++)  
        count_arr[i] = 0;  
    //ͳ��i�Ĵ���   
    for(i = 0;i<n;i++)  
        count_arr[arr[i]]++;  
    //�����еļ����ۼ�   
    for(i = 1; i<100; i++)  
        count_arr[i] += count_arr[i-1];     
    for(i = n; i>0; i--)  
    {  
        sorted_arr[count_arr[arr[i-1]]-1] = arr[i-1];  
        count_arr[arr[i-1]]--;    
    }   
    free(count_arr);  
}  

void countOne()
{
	clock_t start = clock();
	int n = 100;
	int i, j, k;        
    int *a = (int *)malloc(sizeof(int) * n);  
    int *sorted_arr = (int *)malloc(sizeof(int) * n); 
    for(i = 0; i < 100000; i++)
    {
    	for (j = 0; j < n; j++)  
    	{  
        	a[j] = rand() % 100;  
    	}  
    	printf("\n\n��%d������\n",i+1);
    	count_sort(a, sorted_arr, n);;    
    	for( j = 0; j < 100; j++)
		{
			printf("%d ",sorted_arr[j]);	
		}			
	}	
	clock_t diff = clock() - start;
	printf("\n\n\n��������С����ʮ�������ʱ��Ϊ��\t"); 
	printf("%dms\n",diff);
	  
} 
 


//�������� 
// �ҵ�num�Ĵӵ͵��ߵĵ�posλ������  
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
//pDataArray ��������, iDataNumΪ�������ݸ���  
void RadixSort(int* pDataArray, int iDataNum)  
{  
	int i, k, j, pos;
    int *radixArrays[10];    //�ֱ�Ϊ0~9�����пռ�  
    for (i = 0; i < 10; i++)  
    {  
        radixArrays[i] = (int *)malloc(sizeof(int) * (iDataNum + 1));  
        radixArrays[i][0] = 0;    //indexΪ0����¼�������ݵĸ���  
    }  
      
    for (pos = 1; pos <= 31; pos++)    //�Ӹ�λ��ʼ��31λ  
    {  
        for (i = 0; i < iDataNum; i++)    //�������  
        {  
            int num = GetNumInPos(pDataArray[i], pos);  
            int index = ++radixArrays[num][0];  
            radixArrays[num][index] = pDataArray[i];  
        }  
          
        for (i = 0, j =0; i < 10; i++)    //�ռ�  
        {  
            for (k = 1; k <= radixArrays[i][0]; k++)  
                pDataArray[j++] = radixArrays[i][k];  
            radixArrays[i][0] = 0;    //��λ  
        }  
    }  
}

void RadixOne()
{	
	clock_t start = clock();
	int n = 100;
	int i, j, k;        
    int *a = (int *)malloc(sizeof(int) * n);  
    for(i = 0; i < 100000; i++)
    {
    	for (j = 0; j < n; j++)  
    	{  
        	a[j] = rand() % 100;  
    	}  
    	printf("\n\n��%d������\n",i+1);
    	RadixSort(a, n);  
    	for( j = 0; j < 100; j++)
		{
			printf("%d ",a[j]);	
		}			
	}	
	clock_t diff = clock() - start;
	printf("\n\n\n��������С����ʮ�������ʱ��Ϊ��\t"); 
	printf("%dms\n",diff);
} 
 

//��������һ�λ����㷨
int Partition(int a[], int first, int end)
{
    int i, j, temp;
    i = first;
    j = end;
    while (i < j)
	{
        //�Ҳ�ɨ��
        while (i < j&&a[i] < a[j])j--;
        if (i < j)
		{
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
        }
        //���ɨ��
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

//�ݹ�
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

void QuickOne()
{
	clock_t start = clock();
	int n = 100;
	int i, j, k;        
    int *a = (int *)malloc(sizeof(int) * n);  
    for(i = 0; i < 100000; i++)
    {
    	for (j = 0; j < n; j++)  
    	{  
        	a[j] = rand() % 100;  
    	}  
    	printf("\n\n��%d������\n",i+1);
    	QuickSort(a, 0, n - 1);
    	for( j = 0; j < 100; j++)
		{
			printf("%d ",a[j]);	
		}			
	}	
	clock_t diff = clock() - start;
	printf("\n\n\n�鲢����С����ʮ�������ʱ��Ϊ��\t"); 
	printf("%dms\n",diff);
} 

int main() 
{    
	int temp;
	printf("��ѡ��һ�����򷽷�����ʮ���С��������\n");
	printf("1.��������\n");
	printf("2.�鲢����\n");
	printf("3.��������\n");
	printf("4.��������\n");
	printf("5.��������\n");
	scanf("%d",&temp);
	switch(temp)
	{
		case 1:	InsertOne();break;
		case 2: mergeOne();break;
		case 3: RadixOne();break;
		case 4: countOne();break;
		case 5:	QuickOne();break;
		default: 
			printf("������󣡣���\n");
			break;
	} 	
    return 0;  
    system ("pause");  
      
}  
