#include <stdio.h>

int main()
{
    int n;
    printf("Введите размер массива: ");
    scanf("%d", &n);

    int A[n];
    printf("Введите элементы массива: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    int s = 0;
    for (int i = 0; i < n && A[i] > 0; i++)
    {
        s = s + A[i];
    }

    printf("Сумма положительных элементов массива: %d", s);

    return 0;
}
