#include "duLinkedList.h"
/**
 *  @name        : Status InitList_DuL(DuLinkedList *L)
 *	@description : initialize an empty linked list with only the head node
 *	@param		 : L(the head node)
 *	@return		 : Status
 *  @notice      : None
 */
Status InitList_DuL(DuLinkedList *L) {
    DuLinkedList pNew;

    pNew = (DuLinkedList)malloc(sizeof(DuLNode));
    if(pNew == NULL)
    {
	    printf("内存分配失败\n");
        return ERROR;
    }
    pNew->next = NULL;
    pNew->prior = NULL;
    *L = pNew;

    return SUCCESS;

}

/**
 *  @name        : void DestroyList_DuL(DuLinkedList *L)
 *	@description : destroy a linked list
 *	@param		 : L(the head node)
 *	@return		 : status
 *  @notice      : None
 */
void DestroyList_DuL(DuLinkedList *L) {
    DuLinkedList p1;

    while((*L) != NULL)
    {
        p1 = *L;
        *L = (*L)->next;
        free(p1);
    }

    free(*L);

    return SUCCESS;
}

/**
 *  @name        : Status InsertBeforeList_DuL(DuLNode *p, LNode *q)
 *	@description : insert node q before node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertBeforeList_DuL(DuLNode *p, DuLNode *q) {
     if(p->next == NULL)
    //当链表为空时,p,q视为同一个结点
    {
        p->next = q;
        q->prior = p;
    }

    else
    {
        DuLinkedList temp;
        temp = p->next;
        p->next = q;
        q->next = temp;
        temp->prior = q;
        q->prior = p;

        return SUCCESS;
    }
}

/**
 *  @name        : Status InsertAfterList_DuL(DuLNode *p, DuLNode *q)
 *	@description : insert node q after node p
 *	@param		 : p, q
 *	@return		 : status
 *  @notice      : None
 */
Status InsertAfterList_DuL(DuLNode *p, DuLNode *q) {

    while(p->next != NULL)
    {
        p=p->next;
    }

    p->next = q;
    q->prior = p;
}

/**
 *  @name        : Status DeleteList_DuL(DuLNode *p, ElemType *e)
 *	@description : delete the first node after the node p and assign its value to e
 *	@param		 : p, e
 *	@return		 : status
 *  @notice      : None
 */
Status DeleteList_DuL(DuLNode *p, ElemType *e) {
    if(p->next->next == NULL)
    {
        DuLinkedList m = p->next;
        *e = m->data;
        p->next = NULL;
        free(m);

    }

    else
    {
    DuLinkedList q = p->next;

    *e = q->data;

    p->next = p->next->next;
    p->next->prior = p;

    q->next = NULL;
    q->prior = NULL;

    free(q);
    }
    return SUCCESS;
}

/**
 *  @name        : void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e))
 *	@description : traverse the linked list and call the funtion visit
 *	@param		 : L(the head node), visit
 *	@return		 : Status
 *  @notice      : None
 */
void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
    if(L == NULL)
        printf("链表不存在\n\n");

    else if(L->next == NULL)
        printf("链表为空\n");

    else
    {
    L = L->next;

    while(L!=NULL)
    {
        visit(L->data);
        L = L->next;
    }
    }
    printf("\n\n");
}

void visit(ElemType e)
{
    printf("%d\t", e);
}

void show(void)
{
    printf("请输入你需要的操作（1-7）:\n");
    printf("1.初始化链表\n");
    printf("2.销毁链表\n");
    printf("3.在一结点前方插入结点\n");
    printf("4.在一结点后方插入结点\n");
    printf("5.删除结点\n");
    printf("6.遍历结点\n");
    printf("7.退出\n");

}

