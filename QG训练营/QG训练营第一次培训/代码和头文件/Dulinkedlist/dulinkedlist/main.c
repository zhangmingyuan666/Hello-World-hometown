# include <stdio.h>
# include <malloc.h>
# include <stdlib.h>
# include "duLinkedList.h"

int main(void)
{
    ElemType val, choice, num;
    DuLinkedList pHead = NULL;


    do{
        show();
        printf("请输入你的操作:");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1://用于初始化链表
            if(InitList_DuL(&pHead))
                printf("初始化成功\n\n\n");

            else
                printf("初始化失败\n");
            break;
        case 2://销毁链表
            if( pHead == NULL )
            {
                printf("链表为空，无法删除\n\n\n");
            }

            else
            {
                DestroyList_DuL(&pHead);
                printf("摧毁成功成功\n\n\n");
            }

            break;

        case 3://在一个结点前方插入一个节点
            if(pHead == NULL)
            {
                printf("插入失败");
            }

            else{
                DuLinkedList pFront;
                InitList_DuL(&pFront);

                printf("你想要插入于前方的值是：");
                scanf("%d", &pFront->data);

                if(InsertBeforeList_DuL(pHead, pFront))
                {
                    printf("插入成功\n\n\n");
                }

                else
                    printf("插入失败\n");

                break;

            }
        case 4://在一个节点后方插入一个节点
            if(pHead == NULL)
            {
                printf("插入失败");
            }

            else{
                DuLinkedList pBehind;
                InitList_DuL(&pBehind);
                printf("你想要插入于后方的值是：");
                scanf("%d", &pBehind->data);

                if(InsertAfterList_DuL(pHead, pBehind))
                {
                    printf("插入成功\n\n\n");
                }

                else
                    printf("插入失败\n");

                break;

            }
        case 5://删除节点
            if(NULL == pHead)
            {
                printf("链表不存在，无法删除");
            }

            else if(NULL == pHead->next)
            {
                printf("链表为空，无法删除");
            }

            else
            {
                if( DeleteList_DuL(pHead,&num))
                    printf("删除成功，删除的元素是%d\n\n", num);


                else
                    printf("删除失败\n\n");
            }

            break;
        case 6://遍历节点
            if(pHead == NULL || pHead->next == NULL)
                printf("无法遍历，链表为空");

            else
                TraverseList_DuL(pHead, &visit);
            break;

        case 7://退出
            break;
        default:
            printf("你在干什么，你现实生活里也是这样的吗?\n");
            break;
        }

    }while(choice != 7);

    return 0;
}
