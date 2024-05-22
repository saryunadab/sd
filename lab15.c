#include <stdio.h>
#include <string.h>

#define MAX_LEN 50

// Структура для хранения информации о рейсе
typedef struct {
    char destination[MAX_LEN];
    int flightNumber;
    char aircraftType[MAX_LEN];
} FlightInfo;

int main() {
    FILE *file;
    FlightInfo info;

    // Создание файла Spravka.dat
    file = fopen("Spravka.dat", "wb");
    if (file == NULL) {
        printf("error.\n");
        return 1;
    }

    // Запись информации о рейсах в файл
    strcpy(info.destination, "moscow");
    info.flightNumber = 101;
    strcpy(info.aircraftType, "rusairo");
    fwrite(&info, 1, sizeof(FlightInfo), file);

    fclose(file);

    // Открытие файла для чтения
    file = fopen("Spravka.dat", "rb");
    if (file == NULL) {
        printf("error.\n");
        return 1;
    }

    char searchType[MAX_LEN];
    int found = 0;

    printf("vvedite tip samoleta: ");
    scanf("%s", searchType);

    // Поиск рейсов по типу самолета
    while (fscanf(file, "%s %d %s", info.destination, &info.flightNumber, info.aircraftType) != EOF) {
        if (strcmp(info.aircraftType, searchType) == 0) {
            printf("reis: %d, punct naznachenuya: %s\n", info.flightNumber, info.destination);
            found = 1;
        }
    }

    if (!found) {
        printf("reisov na camolet %s ne naideno\n", searchType);
    }

    fclose(file);

    return 0;
}
