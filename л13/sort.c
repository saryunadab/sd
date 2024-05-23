#include <stdio.h>

// Функция сортировки методом Шелла
void shell_sort(int arr[], int n)
{
    int gap, i, j, temp, count = 0, swap = 0;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (i = gap; i < n; i++)
        {
            count++;
            temp = arr[i];
            swap++;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
            {
                count++;
                arr[j] = arr[j - gap];
                swap++;
            }
            arr[j] = temp;
            swap++;
        }
    }
    printf("M+C = %d", swap + count);
}

// Функция сортировки методом пузырьковой сортировки
void bubble_sort(int arr[], int n)
{
    int i, j, temp, swap = 0, count = 0;
    for (i = 0; i < n - 1; i++)
    {
        // Last i elements are already in place
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                count++;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swap += 3;
            }
        }
    }
    printf("M+C = %d", swap + count);
}

// Функция сортировки методом шейкерной сортировки (шейкерной сортировки)
void cocktail_sort(int arr[], int n)
{
    int left = 0, right = n - 1, swapped = 0, count = 0, swap = 0;

    while (left < right && !swapped)
    {
        count++;
        swapped = 1;
        for (int i = left; i < right; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                count++;
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
                swap += 3;
                swapped = 0;
            }
        }
        right--;

        if (!swapped)
        {
            swapped = 1;
            for (int i = right; i > left; i--)
            {
                if (arr[i] < arr[i - 1])
                {
                    count++;
                    int temp = arr[i];
                    arr[i] = arr[i - 1];
                    arr[i - 1] = temp;
                    swap += 3;
                    swapped = 0;
                }
            }
            left++;
        }
    }
    printf("M+C = %d", swap + count);
}

// Функция сортировки методом простого включения (Insertion Sort)
void insertion_sort(int arr[], int n)
{
    int i, key, j, swap = 0, count = 0;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        swap++;

        /* Move elements of arr[0..i-1], that are
           greater than key, to one position ahead
           of their current position */
        while (j >= 0 && arr[j] > key)
        {
            count++;
            arr[j + 1] = arr[j];
            j = j - 1;
            swap += 2;
        }
        arr[j + 1] = key;
        swap++;
    }
    printf("M+C = %d", swap + count);
}
