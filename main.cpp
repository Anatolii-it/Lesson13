
#include <stdio.h>

void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                // ����� ������
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE* inputFile = fopen("input.txt", "r");  // ³�������� ���� ��� �������
    if (!inputFile) {
        printf("�� ������� ������� ���� ��� �������!\n");
        return 1;
    }

    const int MAX_NUMBERS = 1000; // ����������� ������� �����
    int numbers[MAX_NUMBERS];
    int count = 0;

    // ������� ����� � �����
    while (fscanf(inputFile, "%d", &numbers[count]) == 1) {
        ++count;
        if (count >= MAX_NUMBERS) break; // �������� �� ������������ ������
    }
    fclose(inputFile);

    // ������� ����� � ������� ���������
    sortDescending(numbers, count);

    FILE* outputFile = fopen("output.bin", "wb");  // ³�������� ���� ��� ������ � �������� �����
    if (!outputFile) {
        printf("�� ������� ������� ���� ��� ������!\n");
        return 1;
    }

    // �������� ���������� ����� � ����
    size_t written = fwrite(numbers, sizeof(int), count, outputFile);
    if (written != count) {
        printf("������� ������ � ����!\n");
    }
    fclose(outputFile);

    printf("����� ������ ���������� �� ������� � ���� output.bin\n");
    return 0;
}
