#include <stdio.h>
#include <sys/time.h>

// Функция для вывода массива на экран
void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Функция для заполнения массива случайными числами
void fill_random(int arr[], int n)
{
    srand(time(NULL)); // инициализация генератора случайных чисел
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 1000; // случайное число от 0 до 999
    }
}

// Функция для заполнения массива с клавиатуры
void fill_keyboard(int arr[], int n)
{
    printf("Введите %d элементов массива:\n", n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]); // Здесь считываем элементы массива с клавиатуры
    }
}

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}
