#include <stdio.h>
#include <math.h>

int main() {
    FILE *outputFile = fopen("output.txt", "w");
    double x, y, z;

    for (x = 0; x <= 3; x += 0.1) {
        y = sin(x);
        z = tan(x);

        fprintf(outputFile, "%.1f %.2f %.2e\n", x, y, z);
    }

    fclose(outputFile);

    return 0;
}