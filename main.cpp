
#include <stdio.h>

void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                // Заміна місцями
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");  // Відкриваємо файл для читання
    if (!inputFile) {
        printf("Не вдалося відкрити файл для читання!\n");
        return 1;
    }

    const int MAX_NUMBERS = 1000; // Максимальна кількість чисел
    int numbers[MAX_NUMBERS];
    int count = 0;

    // Зчитуємо числа з файлу
    while (fscanf(inputFile, "%d", &numbers[count]) == 1) {
        ++count;
        if (count >= MAX_NUMBERS) break; // Перевірка на переповнення масиву
    }
    fclose(inputFile);

    // Сортуємо числа у порядку зменшення
    sortDescending(numbers, count);

    FILE* outputFile = fopen("output.bin", "wb");  // Відкриваємо файл для запису в бінарному режимі
    if (!outputFile) {
        printf("Не вдалося відкрити файл для запису!\n");
        return 1;
    }

    // Записуємо відсортовані числа у файл
    size_t written = fwrite(numbers, sizeof(int), count, outputFile);
    if (written != count) {
        printf("Помилка запису у файл!\n");
    }
    fclose(outputFile);

    printf("Числа успішно відсортовані та записані у файл output.bin\n");
    return 0;
}
