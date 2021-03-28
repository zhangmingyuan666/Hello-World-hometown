#include "linkedList.h"
#include "malloc.h"
#include "stdlib.h"
#include "stdio.h"
#include "windows.h"
//��ʮ������ûд�������ҵĹ�
int main(void)
{
    LinkedList pHead = NULL;
    LinkedList pNew = NULL;
    ElemType choice, num = 0, e, val, c, q;

    do{
        show();
        printf("��������Ĳ���:");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1://���ڳ�ʼ������
            if(InitList(&pHead))
                printf("��ʼ���ɹ�\n\n\n");

            else
                printf("��ʼ��ʧ��\n");

            break;

        case 2://��������
            if(pHead == NULL || pHead->next == NULL)
                {
                    printf("���ǿ�����\n\n");
                }
            DestroyList(&pHead);
            printf("���ٳɹ�\n\n\n");
            break;

        case 3://���ڲ�����
            printf("������������������:");
            scanf("%d", &num);

            if(pHead == NULL)
                {
                    printf("���������ڣ�����ʧ��\n\n");
                    break;
                }
            if(InsertList(pHead, pNew, num))
                printf("����ɹ�\n\n\n");

            else
                printf("����ʧ��\n");

            break;

        case 4://����ɾ�����

            if(pHead == NULL || pHead->next == NULL)
                {
                    printf("���ǿ�����\n\n");
                    return SUCCESS;
                }

            if(DeleteList(pHead, &q))
            {
                printf("ɾ���ɹ���ɾ����Ԫ����%d\n\n\n", q);
            }

            else
                printf("ɾ��ʧ��\n");

            break;

        case 5://���ڱ������
            if(pHead == NULL || pHead->next == NULL)
            {
                printf("����Ϊ��\n");
                printf("\n");
                break;
            }
            else
                TraverseList(pHead, &visit);

            break;

        case 6://���ڷ�ת����
            if(pHead == NULL || pHead->next == NULL)
            {
                printf("ү��ת����\n\n");
                break;
            }

            else{
                if(ReverseList(&pHead))
                    printf("��ת�ɹ�\n\n");

                else
                    printf("��תʧ��\n");

                break;
            }
        case 7://�����ж������Ƿ�ɻ�
            if(pHead == NULL || pHead->next == NULL)
                {
                    printf("����Ϊ��\n\n");
                    break;
                }

            else
            {
                if(IsLoopList(pHead))
                    printf("�ɻ�\n\n");

                else
                    printf("���ɻ�\n\n");

                break;
            }
        case 8://����Ѱ���м���
            if(pHead == NULL || pHead->next == NULL)
                {
                    printf("���ǿ�����\n\n");
                }
                else
                {
                    FindMidNode(&pHead);
                }
                break;

        case 9://��ѯ����
                {
                printf("��������Ҫ���ҵ����ݣ�");
                scanf("%d", &c);
                if(SearchList(pHead, c))
                {
                    printf("��������\n\n");
                }
                else
                {
                    printf("����������\n\n");
                }
                break;

                }

        case 10://�������ڵĽ��
            if(pHead == NULL || pHead->next == NULL)
                {
                    printf("����Ϊ��\n\n");
                    break;
                }

            else
            {
                pHead = ReverseEvenList(&pHead);

                break;
            }
        case 11://�����˳�
            break;

        default:
            printf("���ڸ�ʲô��������ʵ������Ҳ����������\n");
            break;
        }



    }while(choice!=11);


    return 0;
}



