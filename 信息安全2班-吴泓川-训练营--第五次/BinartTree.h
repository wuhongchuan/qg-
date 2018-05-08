typedef char TElemType;     // 假设二叉树结点的元素类型为字符

typedef struct {
	char *elem;            // 0号单元闲置
	int lastIndex;              // 二叉树最后一个结点的编号
} SqBiTree;    // 顺序存储的二叉树


typedef struct BiTNode { // 结点结构                              
	TElemType data;  
	struct BiTNode  *lchild, *rchild; //左右孩子指针  
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

