#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#include "func.h"
#include "bin.h"

#define RED "\033[1;31m"
#define RESET "\033[0m" // == in hex "\x1B[0m"
#define BLACK "\e[0;30m"
#define WHITE "\e[0;37m"

// Главная функция
int main()
{
    int n_values[] = {100, 200, 300, 400, 500};
    int num_values = sizeof(n_values) / sizeof(n_values[0]);

    printf("n\tShell Sort\tBinary Insertion Sort\tCocktail Sort\tBubble Sort\tInsertion Sort\n");

    for (int i = 0; i < num_values; i++)
    {
        int n = n_values[i];
        int arr[n];
        double time_taken;
        int choice, sorting_method;

        printf("Выберите способ заполнения массива (1 - случайные числа, 2 - ввод с клавиатуры): ");
        scanf("%d", &choice);
        printf("%d\n", choice);

        // Заполнение массива в зависимости от выбора пользователя
        switch (choice)
        {
        case 1:
            fill_random(arr, n);
            break;
        case 2:
            printf("Введите %d элементов массива:\n", n);
            for (int i = 0; i < n; i++)
            {
                arr[i] = i + 1;
            }
            break;
        default:
            printf(RED "Некорректный выбор.   \n");
            return 1;
        }
        print_array(arr, n);

        printf("Выберите метод сортировки (1 - Шелл, 2 - Бинарное включение, 3 - Шейкерная, 4 - Пузырьковая, 5 - Простое включение): ");
        scanf("%d", &sorting_method);
        printf("%d\n", sorting_method);

        // переменные для подсчета времени
        double t_start, t_end;

        // Выполняем сортировку в зависимости от выбранного метода
        switch (sorting_method)
        {
        case 1:
            t_start = wtime();
            shell_sort(arr, n);
            t_end = wtime();
            break;
        case 2:
            t_start = wtime();
            binary_insertion_sort(arr, n);
            t_end = wtime();
            break;
        case 3:
            t_start = wtime();
            cocktail_sort(arr, n);
            t_end = wtime();
            break;
        case 4:
            t_start = wtime();
            bubble_sort(arr, n);
            t_end = wtime();
            break;
        case 5:
            t_start = wtime();
            insertion_sort(arr, n);
            t_end = wtime();
            break;
        default:
            printf(RED "Некорректный выбор метода сортировки.\n");
            return 1;
        }

        // Вычисляем время сортировки
        time_taken = t_end - t_start;
        printf("\n");
        print_array(arr, n);

        // Выводим результаты
        printf("   %d\t%f\n", n, time_taken);
    }

    return 0;
}
