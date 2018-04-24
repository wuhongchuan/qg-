#include <stdio.h>  
#include <stdlib.h>  

typedef enum Status
{
	ERROR = 0, OK = 1
}Status;

typedef int ElemType;

typedef struct StackNode  
{  
    ElemType data;  
    struct StackNode *next;  
}StackNode, *LinkStackPtr;  
  
typedef struct linkStack  
{  
    LinkStackPtr top;     //栈顶指针
    int count;            //栈中元素个数
}LinkStack;  