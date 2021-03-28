#include "linkedList.h"
#include "malloc.h"
#include "stdlib.h"
#include "stdio.h"
#include "windows.h"
//第十个功能没写出来，我的锅
int main(void)
{
    LinkedList pHead = NULL;
    LinkedList pNew = NULL;
    ElemType choice, num = 0, e, val, c, q;

    do{
        show();
        printf("请输入你的操作:");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1://用于初始化链表
            if(InitList(&pHead))
                printf("初始化成功\n\n\n");

            else
                printf("初始化失败\n");

            break;

        case 2://销毁链表
            if(pHead == NULL || pHead->next == NULL)
                {
                    printf("这是空链表\n\n");
                }
            DestroyList(&pHead);
            printf("销毁成功\n\n\n");
            break;

        case 3://用于插入结点
            printf("请输入你想插入的数据:");
            scanf("%d", &num);

            if(pHead == NULL)
                {
                    printf("该链表不存在，插入失败\n\n");
                    break;
                }
            if(InsertList(pHead, pNew, num))
                printf("插入成功\n\n\n");

            else
                printf("插入失败\n");

            break;

        case 4://用于删除结点

            if(pHead == NULL || pHead->next == NULL)
                {
                    printf("这是空链表\n\n");
                    return SUCCESS;
                }

            if(DeleteList(pHead, &q))
            {
                printf("删除成功，删除的元素是%d\n\n\n", q);
            }

            else
                printf("删除失败\n");

            break;

        case 5://用于遍历结点
            if(pHead == NULL || pHead->next == NULL)
            {
                printf("链表为空\n");
                printf("\n");
                break;
            }
            else
                TraverseList(pHead, &visit);

            break;

        case 6://用于反转链表
            if(pHead == NULL || pHead->next == NULL)
            {
                printf("爷反转不了\n\n");
                break;
            }

            else{
                if(ReverseList(&pHead))
                    printf("反转成功\n\n");

                else
                    printf("反转失败\n");

                break;
            }
        case 7://用于判断链表是否成环
            if(pHead == NULL || pHead->next == NULL)
                {
                    printf("链表为空\n\n");
                    break;
                }

            else
            {
                if(IsLoopList(pHead))
                    printf("成环\n\n");

                else
                    printf("不成环\n\n");

                break;
            }
        case 8://用于寻找中间结点
            if(pHead == NULL || pHead->next == NULL)
                {
                    printf("这是空链表\n\n");
                }
                else
                {
                    FindMidNode(&pHead);
                }
                break;

        case 9://查询链表
                {
                printf("请输入你要查找的数据：");
                scanf("%d", &c);
                if(SearchList(pHead, c))
                {
                    printf("该数存在\n\n");
                }
                else
                {
                    printf("该数不存在\n\n");
                }
                break;

                }

        case 10://交换相邻的结点
            if(pHead == NULL || pHead->next == NULL)
                {
                    printf("链表为空\n\n");
                    break;
                }

            else
            {
                pHead = ReverseEvenList(&pHead);

                break;
            }
        case 11://用于退出
            break;

        default:
            printf("你在干什么，你在现实生活中也是这样的吗\n");
            break;
        }



    }while(choice!=11);


    return 0;
}



