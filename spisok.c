
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Spisok
{
    struct Spisok *start;
    int value;
    struct Spisok *next;
} Spisok;

typedef struct Big
{

    struct Spisok *head;
    struct Spisok *tail;
    struct Spisok *tail_a1;
} Big;

Spisok *create(int data, Big *parts)
{
    Spisok *tmp = (Spisok *)malloc(sizeof(Spisok));
    tmp->value = data;
    tmp->next = NULL;
    tmp->start = NULL;

    parts->tail_a1 = tmp;

    return tmp;
}

Big *creat()
{
    Big *tmp = (Big *)malloc(sizeof(Big));
    tmp->head = NULL;
    tmp->tail = NULL;
    tmp->tail_a1 = NULL;

    return tmp;
}
Spisok *add_element_start(int data, Spisok *head, Big *parts, int size)
{
    Spisok *tmp = (Spisok *)malloc(sizeof(Spisok));

    tmp->value = data;
    tmp->next = head;
    tmp->start = NULL;

    Spisok *p = head;
    while (p->next != NULL)
        p = p->next;
    //|tmp|1|next|

    if (size % 2 == 0)
    {
        p->start = tmp;
    }
    parts->head = tmp;
    return (tmp);
}

Spisok *add_element_start_2(int data, Spisok *head, Big *parts)
{
    Spisok *tmp = (Spisok *)malloc(sizeof(Spisok));

    tmp->value = data;
    tmp->next = parts->tail_a1;
    tmp->start = NULL;

    parts->head = tmp;
    return (tmp);
}

void add_element_end(int data, Spisok *head, Big *parts)
{
    Spisok *tmp = (Spisok *)malloc(sizeof(Spisok));
    tmp->value = data;
    tmp->next = NULL;
    tmp->start = NULL;

    Spisok *p = head;
    while (p->next != NULL)
        p = p->next;
    p->next = tmp;

    tmp->start = parts->head;
    parts->tail = p->next;
}
void connect(Spisok *head, Big *parts)
{
    Spisok *p = head;
    while (p->next != parts->tail_a1)
        p = p->next;
    parts->tail->next = p;
}
int print(Spisok *list, Big *parts)
{
    while (list)
    {
        printf("%d ", list->value);
        if (list == parts->tail)
        {
            return 0;
        }
        list = list->next;
    }
}

void menu()
{
    printf("\nsdelayte vybor\n");
    printf("Vyhod - 1\n");
    printf("Napravo - 6\n");
    printf("Vniz - 2\n");
    printf("Naverh - 8 (Tolko esli vy na 2 elemente!)\n");
    printf("snachala - 3");
    printf("\nSdelayte vybor = ");
}

Spisok *up(Spisok *list, Big *patrs)
{
    if (list->next == patrs->tail_a1)
    {
        list = (list->next);
        printf("Value = %d\n", list->value);
    }
    else
    {
        printf("Net vyhoda \n");
    }
    return list;
}

Spisok *down(Spisok *list, Big *patrs)
{
    if (list->start != NULL)
    {
        list = (list->start);
        printf("Value = %d\n", list->value);
    }
    else
    {
        printf("net vyhoda \n");
    }
    return list;
}

Spisok *rigth(Spisok *list, Big *patrs)
{
    if (list->next != NULL)
    {
        list = (list->next);
        printf("Value = %d\n", list->value);
    }
    else
    {
        printf("net vyhoda \n");
    }
    return list;
}

int main()
{
    int n, size;
    srand(time(NULL));
    Spisok *list = NULL;

    Big *parts;
    parts = creat();
    int array[100], x, xi = 0;

    printf("Vvedite razmer massiva = ");
    scanf("%d", &n);

    list = create(1, parts);

    for (int i = 2; i <= n; i++)
    {
        if (i == 2)
        {
            list = add_element_start_2(i, list, parts);
        }
        else if (i % 2 == 1)
        {
            add_element_end(i, list, parts);
        }
        else
        {
            list = add_element_start(i, list, parts, n);
        }
    }
    connect(list, parts);
    int choice = 1;
    printf("\n");
    print(parts->head, parts);

    // menu();
    Spisok *kok = parts->tail_a1;
    printf("\n\nValue = %d\n", kok->value);
    while (choice != 0)
    {
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
            return 0;
            break;
        case 1:
            menu();
            break;
        case 2:
            kok = down(kok, parts);
            break;
        case 3:
            kok = (parts->tail_a1);
            printf("\n\nValue = %d\n", kok->value);
            break;
        case 6:
            kok = rigth(kok, parts);
            break;
        case 8:
            kok = up(kok, parts);
            break;
        default:
            menu();
            break;
        }
    }
    return 0;
}
