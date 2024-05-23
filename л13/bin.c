#include <stdio.h>

// Функция для выполнения бинарного поиска
int binary_search(int arr[], int item, int low, int high)
{
    if (high <= low)
        return (item > arr[low]) ? (low + 1) : low;

    int mid = (low + high) / 2;

    if (item == arr[mid])
        return mid + 1;

    if (item > arr[mid])
        return binary_search(arr, item, mid + 1, high);
    return binary_search(arr, item, low, mid - 1);
}
// Функция сортировки методом бинарного включения
void binary_insertion_sort(int arr[], int n)
{
    int i, loc, j, selected, swap = 0, count = 0;

    for (i = 1; i < n; ++i)
    {
        count++;
        j = i - 1;
        selected = arr[i];

        // находим позицию для вставки
        loc = binary_search(arr, selected, 0, j);
        count += 3;
        // передвигаем большие элементы вправо
        while (j >= loc)
        {
            arr[j + 1] = arr[j];
            swap++;
            j--;
        }
        arr[j + 1] = selected;
        swap++;
    }
    printf("M+C =  %d ", swap + count);
}
