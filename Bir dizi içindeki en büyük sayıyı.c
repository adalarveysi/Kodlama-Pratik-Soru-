#include <stdio.h>

int findMax(int arr[], int size) {
    int max = arr[0]; // Başlangıçta en büyük sayıyı dizinin ilk elemanı olarak varsayıyoruz

    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i]; // Daha büyük bir sayı bulunduğunda en büyüğü güncelliyoruz
        }
    }

    return max;
}

int main() {
    int array[] = {5, 2, 9, 1, 7, 3};
    int size = sizeof(array) / sizeof(array[0]);

    int maxNumber = findMax(array, size);
    printf("En büyük sayı: %d\n", maxNumber);

    return 0;
}