#ifndef QUEUE_H_INCLUDED
#define QUEUE_H_INCLUDED
#define MAXQUEUE 10

//ѭ�����нṹ
typedef struct Aqueue
{
	void *data[MAXQUEUE];  	//������
	int front;
	int rear;
	size_t data_size;		//�������ڴ��С
} AQueue;

//��ʽ���нṹ
typedef struct node
{
	void* data;       			//������ָ��
	struct node *next;			//ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
	Node *front;       			//��ͷ
	Node *rear;        			//��β
	size_t data_size;			//�������ڴ��С
} LQueue;

typedef enum
{
	FALSE = 0, TRUE = 1
} Status;







/**************************************************************
*	Prototype Declare Section
**************************************************************/

/**
*  @name        : void InitAQueue(AQueue *Q)
*	@description : ��ʼ������
*	@param		 : ����ָ��Q
*	@return		 : None
*  @notice      : None
*/
void InitAQueue(AQueue *Q);

/**
*  @name        : void InitLQueue(LQueue *Q)
*	@description : ��ʼ������
*	@param		 : ����ָ��Q
*	@return		 : None
*  @notice      : None
*/
void InitLQueue(LQueue *Q);

/**
*  @name        : void DestoryAQueue(AQueue *Q)
*	@description : ���ٶ���
*	@param		 : ����ָ��Q
*	@return		 : None
*  @notice      : None
*/
void DestoryAQueue(AQueue *Q);

/**
*  @name        : void DestoryLQueue(LQueue *Q)
*	@description : ���ٶ���
*	@param		 : ����ָ��Q
*	@return		 : None
*  @notice      : None
*/
void DestoryLQueue(LQueue *Q);

/**
*  @name        : Status IsFullAQueue(const AQueue *Q)
*	@description : �������Ƿ�����
*	@param		 : ����ָ��Q
*	@return		 : ��-TRUE; δ��-FLASE
*  @notice      : None
*/
Status IsFullAQueue(const AQueue *Q);

/**
*  @name        : Status IsEmptyAQueue(const AQueue *Q)
*	@description : �������Ƿ�Ϊ��
*	@param		 : ����ָ��Q
*	@return		 : ��-TRUE; δ��-FLASE
*  @notice      : None
*/
Status IsEmptyAQueue(const AQueue *Q);

/**
*  @name        : Status IsEmptyLQueue(const LQueue *Q)
*	@description : �������Ƿ�Ϊ��
*	@param		 : ����ָ��Q
*	@return		 : ��-TRUE; δ��-FLASE
*  @notice      : None
*/
Status IsEmptyLQueue(const LQueue *Q);

/**
*  @name        : Status GetHeadAQueue(AQueue *Q, void *e)
*	@description : �鿴��ͷԪ��
*	@param		 : ����ָ��Q�����Ԫ��e
*	@return		 : �ɹ�-TRUE; ʧ��-FLASE
*  @notice      : �����Ƿ��
*/
Status GetHeadAQueue(AQueue *Q, void *e);

/**
*  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
*	@description : �鿴��ͷԪ��
*	@param		 : ����ָ��Q�����Ԫ��e
*	@return		 : �ɹ�-TRUE; ʧ��-FLASE
*  @notice      : �����Ƿ��
*/
Status GetHeadLQueue(LQueue *Q, void *e);

/**
*  @name        : int LengthAQueue(AQueue *Q)
*	@description : ȷ�����г���
*	@param		 : ����ָ��Q
*	@return		 : ���г���count
*  @notice      : None
*/
int LengthAQueue(AQueue *Q);

/**
*  @name        : int LengthLQueue(LQueue *Q)
*	@description : ȷ�����г���
*	@param		 : ����ָ��Q
*	@return		 : ���г���count
*  @notice      : None
*/
int LengthLQueue(LQueue *Q);

/**
*  @name        : Status EnAQueue(AQueue *Q, void *data)
*	@description : ��Ӳ���
*	@param		 : ����ָ��Q,�������ָ��data
*	@return		 : �ɹ�-TRUE; ʧ��-FLASE
*  @notice      : �����Ƿ����˻�Ϊ��
*/
Status EnAQueue(AQueue *Q, void *data);

/**
*  @name        : Status EnLQueue(LQueue *Q, void *data)
*	@description : ��Ӳ���
*	@param		 : ����ָ��Q,�������ָ��data
*	@return		 : �ɹ�-TRUE; ʧ��-FLASE
*  @notice      : �����Ƿ�Ϊ��
*/
Status EnLQueue(LQueue *Q, void *data);

/**
*  @name        : Status DeAQueue(AQueue *Q)
*	@description : ���Ӳ���
*	@param		 : ����ָ��Q
*	@return		 : �ɹ�-TRUE; ʧ��-FLASE
*  @notice      : None
*/
Status DeAQueue(AQueue *Q);

/**
*  @name        : Status DeLQueue(LQueue *Q)
*	@description : ���Ӳ���
*	@param		 : ����ָ��Q
*	@return		 : �ɹ�-TRUE; ʧ��-FLASE
*  @notice      : None
*/
Status DeLQueue(LQueue *Q);

/**
*  @name        : void ClearAQueue(Queue *Q)
*	@description : ��ն���
*	@param		 : ����ָ��Q
*	@return		 : None
*  @notice      : None
*/
void ClearAQueue(AQueue *Q);

/**
*  @name        : void ClearLQueue(AQueue *Q)
*	@description : ��ն���
*	@param		 : ����ָ��Q
*	@return		 : None
*  @notice      : None
*/
void ClearLQueue(LQueue *Q);

/**
*  @name        : Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
*	@description : ������������
*	@param		 : ����ָ��Q����������ָ��foo
*	@return		 : None
*  @notice      : None
*/
Status TraverseAQueue(const AQueue *Q, void(*foo)(void *q));

/**
*  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
*	@description : ������������
*	@param		 : ����ָ��Q����������ָ��foo
*	@return		 : None
*  @notice      : None
*/
Status TraverseLQueue(const LQueue *Q, void(*foo)(void *q));

/**
*  @name        : void APrint(void *q)
*	@description : ��������
*	@param		 : ָ��q
*	@return		 : None
*  @notice      : None
*/
void APrint(void *q);

/**
*  @name        : void LPrint(void *q)
*	@description : ��������
*	@param		 : ָ��q
*	@return		 : None
*  @notice      : None
*/
void LPrint(void *q);

/**************************************************************
*	End-Multi-Include-Prevent Section
**************************************************************/
#endif // QUEUE_H_INCLUDED
#pragma once
