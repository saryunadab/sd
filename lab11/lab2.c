#include <stdio.h>

int countNegative(int arr[], int n) {
    if (n == 0) {
        return 0;
    } else {
        if (arr[n - 1] < 0) {
            return 1 + countNegative(arr, n - 1);
        } else {
            return countNegative(arr, n - 1);
        }
    }
}

int main() {
    int arr[] = {3, -5, 7, -2, 0, -8, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int result = countNegative(arr, n);
    printf("Количество отрицательных чисел в массиве: %dn", result);
    
    return 0;
}
