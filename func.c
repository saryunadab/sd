#include "header.h"

void uravnenie(struct Line l) {
    float a = (float)(l.y2 - l.y1) / (l.x2 - l.x1);
    float b = l.y1 - a * l.x1;

    printf("uravnenie pryamoy: y = %f x + %f\n", a, b);
}