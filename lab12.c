#include <stdio.h>
#include "header.h"

int main() {
    int K;
    printf("Enter the number of lines: ");
    scanf("%d", &K);

    struct Line lines[K];

    for (int i = 0; i < K; i++) {
        printf("Enter the coordinates of two points for line %d (x1 y1 x2 y2): ", i+1);
        scanf("%d %d %d %d", &lines[i].x1, &lines[i].y1, &lines[i].x2, &lines[i].y2);
    }

    for (int i = 0; i < K; i++) {
        printf("Line %d: ", i+1);
        printEquation(lines[i]);
    }

    return 0;
}