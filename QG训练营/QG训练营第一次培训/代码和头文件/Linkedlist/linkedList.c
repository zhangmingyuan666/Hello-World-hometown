#include "malloc.h"
#include "stdio.h"
#include "stdlib.h"
#include "linkedList.h"
/**
 *  @name        : Status InitList(LinkList *L);
 *	@description : initialize an empty linked list with only the head node without value
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList(LinkedList *L) {
    LinkedList pNew = (LinkedList)malloc(sizeof(LNode));

    if(pNew == NULL)
    {
        printf("内存空间分配失败\n");
        exit(-1);
    }

    else
    {
        pNew->next = NULL;
        *L = pNew;

        return SUCCESS;
    }
}

/**
 *  @name        : void DestroyList(LinkedList *L)
 *	@description : destroy a linked list, free all the nodes
 *	@param		 : L(the head node)
 *	@return		 : None
 *  @notice      : None
 */
void DestroyList(LinkedList *L) {
    LinkedList p;

    while(*L != NULL)
    {
        p = *L;
        *L = (*L)->next;
        free(p);
    }

    free(*L);
}

/**
 *  @name        : Status InsertList(LNode *p, LNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : Status
 *  @notice      : None
 */
Status InsertList(LNode *p, LNode *q, int val) {

    LinkedList current = p;
    q = (LinkedList)malloc(sizeof(LNode));

    if(q == NULL)
    {
        printf("内存分配失败\n");
        return ERROR;
    }
    q->data = val;
    q->next = NULL;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = q;
    return SUCCESS;
}
/**
 *  @name        : Status DeleteList(LNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : Status
 *  @notice      : None
 */
Status DeleteList(LNode *p, ElemType *e) {
    LinkedList q;
    LinkedList m;
    q=p->next;

    *e = q->data;

    m=q;
    p->next = p->next->next;
    free(m);
    return SUCCESS;
}

/**
 *  @name        : void TraverseList(LinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : None
 *  @notice      : None
 */
void TraverseList(LinkedList L, void (*visit)(ElemType e)) {

    L = L->next;

    while(L != NULL)
    {
        visit(L->data);
        L = L->next;
    }

    printf("\n\n");
}

void visit(ElemType e)
{
    printf("%d\t", e);
}
/**
 *  @name        : Status SearchList(LinkedList L, ElemType e)
 *	@description : find the first node in the linked list according to e
 *	@param		 : L(the head node), e
 *	@return		 : Status
 *  @notice      : None
 */
Status SearchList(LinkedList L, ElemType e) {

     while(L != NULL)
    {
        if(L->data == e)
        {
            return SUCCESS;
        }
        L = L->next;
    }
    return ERROR;

}

/**
 *  @name        : Status ReverseList(LinkedList *L)
 *	@description : reverse the linked list
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status ReverseList(LinkedList *L) {
    LinkedList pNew;
    LinkedList p1;
    LinkedList p2;

    p1 = (*L)->next;
    p2 = p1->next;
    p1->next = NULL;
    pNew = p1;

    while(p2 != NULL)
    {
        p1 = p2;
        p2 = p1->next;
        p1->next = pNew;
        pNew = p1;
    }

    (*L)->next = pNew;

    return SUCCESS;
}

/**
 *  @name        : Status IsLoopList(LinkedList L)
 *	@description : judge whether the linked list is looped
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status IsLoopList(LinkedList L) {
    LinkedList p1,p2;

    p1 = L;
    p2 = L;

    while(p1->next != NULL != p2->next == NULL)
    {
        p1 = p1->next;
        p2 = p2->next->next;

        if(p1 == p2)
            return 1;
    }

    return 0;
}

/**
 *  @name        : LNode* ReverseEvenList(LinkedList *L)
 *	@description : reverse the nodes which value is an even number in the linked list, input: 1 -> 2 -> 3 -> 4  output: 2 -> 1 -> 4 -> 3
 *	@param		 : L(the head node)
 *	@return		 : LNode(the new head node)
 *  @notice      : choose to finish
 */
LNode* ReverseEvenList(LinkedList *L) {
    LinkedList p1=(LinkedList)malloc(sizeof(LNode));
    LinkedList p2=(LinkedList)malloc(sizeof(LNode));

    p1 = (*L)->next;
    p2 = (*L)->next->next;

    while(p1->next != NULL)
    {
        p1->next = p1->next->next;
        (*L)->next = p2;
        p2->next=p1;

        p1 = p1->next;
        p2 = p1->next;
    }

    printf("调换成功\n");

    return *L;
}

/**
 *  @name        : LNode* FindMidNode(LinkedList *L)
 *	@description : find the middle node in the linked list
 *	@param		 : L(the head node)
 *	@return		 : LNode
 *  @notice      : choose to finish
 */
LNode* FindMidNode(LinkedList *L) {
    LinkedList p1;
    LinkedList p2;
    p1 = *L;
    p2 = *L;

    while(p2->next != NULL)
    {
        p1 = p1->next;
        p2 = p2->next->next;
    }
    printf("%d\n\n\n", p1->data);
}

void show(void)
{
    printf("请输入你需要的操作:\n");
    printf("1.初始化链表\n");
    printf("2.销毁链表\n");
    printf("3.插入结点\n");
    printf("4.删除结点\n");
    printf("5.遍历链表\n");
    printf("6.反转链表\n");
    printf("7.判断链表是否成环\n");
    printf("8.查找中间结点\n");
    printf("9.查询链表\n");
    printf("10.交换相邻结点的值\n");
    printf("11.退出\n");
}

