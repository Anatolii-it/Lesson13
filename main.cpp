#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");  // Відкриваємо файл
    if (!inputFile) {
        printf("Не вдалося відкрити файл!\n");
        return 1;
    }

    const int MAX_NUMBERS = 1000; // Максимальна кількість чисел
    int numbers[MAX_NUMBERS];
    int count = 0;

    
    while (fscanf(inputFile, "%d", &numbers[count]) == 1) {
        ++count;
        if (count >= MAX_NUMBERS) break; // Перевірка на переповнення масиву
    }
    fclose(inputFile);

    
    sortDescending(numbers, count);

    FILE* outputFile = fopen("output.txt", "w"); 
    if (!outputFile) {
        printf("Не вдалося відкрити файл для запису!\n");
        return 1;
    }

    
    for (int i = 0; i < count; ++i) {
        fprintf(outputFile, "%d\n", numbers[i]);
    }
    fclose(outputFile);

    printf("Числа успішно відсортовані та записані у  output.txt\n");
    return 0;
}
