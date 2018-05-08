typedef char TElemType;     // �������������Ԫ������Ϊ�ַ�

typedef struct {
	char *elem;            // 0�ŵ�Ԫ����
	int lastIndex;              // ���������һ�����ı��
} SqBiTree;    // ˳��洢�Ķ�����


typedef struct BiTNode { // ���ṹ                              
	TElemType data;  
	struct BiTNode  *lchild, *rchild; //���Һ���ָ��  
} BiTNode, *BiTree;  
	

typedef enum Status
{
    ERROR = 0,SUCCESS = 1
}Status;


Status Print(TElemType e)  
{  
    printf("%c",e);
    return SUCCESS;  
}      

Status InitBiTree(BiTree *T);
Status DestroyBiTree(BiTree T);
Status CreateBiTree(BiTree &T);
Status PreOrderTraverse(BiTree T,Status(* visit)(TElemType e));
Status InOrderTraverse(BiTree T, Status(* visit)(TElemType e));
Status PostOrderTraverse(BiTree T, Status(* visit)(TElemType e));
Status LevelOrderTraverse(BiTree T);
int Value(BiTree T);

void op(BiTree T)
{
	if(T->data == '+')
	{
		T->data = T->lchild->data-48+T->rchild->data;
	}
	if(T->data == '-')
	{
		T->data = (T->lchild->data-48)+(T->rchild->data);
	}
		if(T->data == '*')
	{
		T->data = (T->lchild->data-48)*(T->rchild->data);
	}
		if(T->data == '/')
	{
		T->data = (T->lchild->data-48)/(T->rchild->data);
	}
}

