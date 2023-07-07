#include <stdio.h>
#define MAX_SIZE 100

// Dizideki tekrar eden elemanları bulan fonksiyon
void findDuplicates(int arr[], int size) {
    int hashTable[MAX_SIZE] = {0};

    printf("Tekrar Eden Elemanlar: ");

    for (int i = 0; i < size; i++) {
        hashTable[arr[i]]++;
        if (hashTable[arr[i]] == 2) {
            printf("%d ", arr[i]);
        }
    }

    printf("\n");
}

int main() {
    int array[] = {5, 2, 9, 2, 1, 7, 5, 3, 9};
    int size = sizeof(array) / sizeof(array[0]);

    findDuplicates(array, size);

    return 0;
}
