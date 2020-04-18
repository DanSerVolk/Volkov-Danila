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


void Push(struct node** headRef, int data) //Вставить элемент в начало списка
{
    struct node* newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = *headRef;
    *headRef = newNode;
}


void Add_element_end(struct node** headRef, int data) //Вставить элемент в конец списка
{
    // Выделение памяти под корень списка
    struct node* newNode = malloc(sizeof(struct node));
    // Присваивание значения узлу
    newNode -> data = data;
    // Присваивание указателю на следующий элемент значения NULL
    newNode -> next = NULL;

        if (*headRef != NULL)
            {
                struct node* p = *headRef;
                // Сдвиг указателя p в самый конец первоначального списка
                while (p -> next != NULL)
                p = p -> next;
                p -> next = newNode;
            }

        else
        *headRef = newNode;

}

void Remove_last(struct node** headRef) //Удалить последний элемент списка
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

void remove_all(struct node** headRef) //Удалить весь список
{
    // Сдвиг указателя head в самый конец первоначального списка
    while (*headRef != NULL)
        {
            // Присваивание новому указателю указателя head
            struct node* p = *headRef;
            *headRef = p -> next;
            // Освобождение памяти для указателя p
            free(p);
        }
}


void Contains(struct node* head, int x) // Поиск элемента
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
            printf("   Искомый элемент в списке присутствует");
        }

    else printf("   Искомый элемент в списке отсутствует");
    flag = 0;
}

void menu ()
{
    //переводим на русский
    setlocale(LC_ALL, "Rus");

    int n, a, s=0;

    struct node* head = NULL; // создание первого элемента
    struct node* w;

    //меню
    printf("               Меню.\n Создать первый элемент односвязного списка(1)\n Добавить элемент в конец односвязного списка(2)\n Удалить элемент с конца односвязного списка(3)\n Просмотреть односвязный список(4)\n Удалить весь односвязный список(5)\n Выполнить последовательный поиск заданного элемента в односвязном списке(6)\n Выйти из программы(7)\n —-------------------------------------------------------------\n\n ");

    //выюор пункта в меню
    while (s<7)
        {
            scanf("%d", &n);
            switch (n)
                {
                    case 1:

                            printf("   Введи свой первый элемент\n   ");
                            scanf("%d", &a);
                            Push(&head, a);
                            printf("   Элемент добавлен\n ");

                        break;

                    case 2:

                            printf("   Введи элемент для добавления\n   ");
                            scanf("%d", &a);
                            Add_element_end(&head, a);
                            printf("   Элемент добавлен\n ");

                        break;

                    case 3:

                            Remove_last(&head);
                            printf("   Последний элемент удален\n ");

                        break;

                    case 4:

                            w = head;
                            printf("   Список элементов: ");

                            while (w != NULL) //вывод
                                {
                                    // Вывод значения узла
                                    printf("%d ", w -> data);
                                    // Сдвиг указателя к следующему узлу
                                    w = w -> next;
                                }

                            printf("\n ");

                        break;

                    case 5:

                            remove_all(&head);
                            printf("   Список удалён\n ");

                        break;

                    case 6:

                            printf("   Введите какой элемент вы ищете?\n   ");
                            scanf("%d", &a);
                            Contains (head,a);
                            printf("\n ");

                        break;

                    case 7:

                            printf("   Выход из программы, нажмите Enter\n");
                            s =7;

                        break;

                    default:

                            printf("   Вы ввели неправильное значение\n ");

                        break;
                }
        }
}

int main()
{

    //переводим на русский
    setlocale(LC_ALL, "Rus");

    menu();

}
