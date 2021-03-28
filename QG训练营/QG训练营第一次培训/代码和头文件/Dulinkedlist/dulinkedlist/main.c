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
        printf("��������Ĳ���:");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1://���ڳ�ʼ������
            if(InitList_DuL(&pHead))
                printf("��ʼ���ɹ�\n\n\n");

            else
                printf("��ʼ��ʧ��\n");
            break;
        case 2://��������
            if( pHead == NULL )
            {
                printf("����Ϊ�գ��޷�ɾ��\n\n\n");
            }

            else
            {
                DestroyList_DuL(&pHead);
                printf("�ݻٳɹ��ɹ�\n\n\n");
            }

            break;

        case 3://��һ�����ǰ������һ���ڵ�
            if(pHead == NULL)
            {
                printf("����ʧ��");
            }

            else{
                DuLinkedList pFront;
                InitList_DuL(&pFront);

                printf("����Ҫ������ǰ����ֵ�ǣ�");
                scanf("%d", &pFront->data);

                if(InsertBeforeList_DuL(pHead, pFront))
                {
                    printf("����ɹ�\n\n\n");
                }

                else
                    printf("����ʧ��\n");

                break;

            }
        case 4://��һ���ڵ�󷽲���һ���ڵ�
            if(pHead == NULL)
            {
                printf("����ʧ��");
            }

            else{
                DuLinkedList pBehind;
                InitList_DuL(&pBehind);
                printf("����Ҫ�����ں󷽵�ֵ�ǣ�");
                scanf("%d", &pBehind->data);

                if(InsertAfterList_DuL(pHead, pBehind))
                {
                    printf("����ɹ�\n\n\n");
                }

                else
                    printf("����ʧ��\n");

                break;

            }
        case 5://ɾ���ڵ�
            if(NULL == pHead)
            {
                printf("�������ڣ��޷�ɾ��");
            }

            else if(NULL == pHead->next)
            {
                printf("����Ϊ�գ��޷�ɾ��");
            }

            else
            {
                if( DeleteList_DuL(pHead,&num))
                    printf("ɾ���ɹ���ɾ����Ԫ����%d\n\n", num);


                else
                    printf("ɾ��ʧ��\n\n");
            }

            break;
        case 6://�����ڵ�
            if(pHead == NULL || pHead->next == NULL)
                printf("�޷�����������Ϊ��");

            else
                TraverseList_DuL(pHead, &visit);
            break;

        case 7://�˳�
            break;
        default:
            printf("���ڸ�ʲô������ʵ������Ҳ����������?\n");
            break;
        }

    }while(choice != 7);

    return 0;
}
