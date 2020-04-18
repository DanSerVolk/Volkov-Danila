#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


struct node
{
    int data;
    struct node* next;
};


    int n, a, s=0,flag=0;


void Push(struct node** headRef, int data) //�������� ������� � ������ ������
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}


void Add_element_end(struct node** headRef, int data) //�������� ������� � ����� ������
{
    // ��������� ������ ��� ������ ������
    struct node* newNode = malloc(sizeof(struct node));
    // ������������ �������� ����
    newNode -> data = data;
    // ������������ ��������� �� ��������� ������� �������� NULL
    newNode -> next = NULL;

        if (*headRef != NULL)
            {
                struct node* p = *headRef;
                // ����� ��������� p � ����� ����� ��������������� ������
                while (p -> next != NULL)
                p = p -> next;
                p -> next = newNode;
            }

        else
        *headRef = newNode;

}

void Remove_last(struct node** headRef) //������� ��������� ������� ������
{
    struct node* p = *headRef;

    if (p->next == NULL)
        {
            free(p);
            *headRef = NULL;

            return;
        }

    while (p->next->next != NULL)
        {
            p = p->next;
        }

        free(p->next);
        p->next = NULL;
}

void remove_all(struct node** headRef) //������� ���� ������
{
    // ����� ��������� head � ����� ����� ��������������� ������
    while (*headRef != NULL)
        {
            // ������������ ������ ��������� ��������� head
            struct node* p = *headRef;
            *headRef = p -> next;
            // ������������ ������ ��� ��������� p
            free(p);
        }
}


void Contains(struct node* head, int x) // ����� ��������
{
    struct node* p = head;

    while (p != NULL)
        {
            if (p -> data == x)
                {
                    flag = 1;
                }
            p = p->next;
        }
    if (flag == 1)
        {
            printf("   ������� ������� � ������ ������������");
        }

    else printf("   ������� ������� � ������ �����������");
    flag = 0;
}

void menu ()
{
    //��������� �� �������
    setlocale(LC_ALL, "Rus");

    int n, a, s=0;

    struct node* head = NULL; // �������� ������� ��������
    struct node* w;

    //����
    printf("               ����.\n ������� ������ ������� ������������ ������(1)\n �������� ������� � ����� ������������ ������(2)\n ������� ������� � ����� ������������ ������(3)\n ����������� ����������� ������(4)\n ������� ���� ����������� ������(5)\n ��������� ���������������� ����� ��������� �������� � ����������� ������(6)\n ����� �� ���������(7)\n �-------------------------------------------------------------\n\n ");

    //����� ������ � ����
    while (s<7)
        {
            scanf("%d", &n);
            switch (n)
                {
                    case 1:

                            printf("   ����� ���� ������ �������\n   ");
                            scanf("%d", &a);
                            Push(&head, a);
                            printf("   ������� ��������\n ");

                        break;

                    case 2:

                            printf("   ����� ������� ��� ����������\n   ");
                            scanf("%d", &a);
                            Add_element_end(&head, a);
                            printf("   ������� ��������\n ");

                        break;

                    case 3:

                            Remove_last(&head);
                            printf("   ��������� ������� ������\n ");

                        break;

                    case 4:

                            w = head;
                            printf("   ������ ���������: ");

                            while (w != NULL) //�����
                                {
                                    // ����� �������� ����
                                    printf("%d ", w -> data);
                                    // ����� ��������� � ���������� ����
                                    w = w -> next;
                                }

                            printf("\n ");

                        break;

                    case 5:

                            remove_all(&head);
                            printf("   ������ �����\n ");

                        break;

                    case 6:

                            printf("   ������� ����� ������� �� �����?\n   ");
                            scanf("%d", &a);
                            Contains (head,a);
                            printf("\n ");

                        break;

                    case 7:

                            printf("   ����� �� ���������, ������� Enter\n");
                            s =7;

                        break;

                    default:

                            printf("   �� ����� ������������ ��������\n ");

                        break;
                }
        }
}

int main()
{

    //��������� �� �������
    setlocale(LC_ALL, "Rus");

    menu();

}
