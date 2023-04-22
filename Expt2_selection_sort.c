#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int array[], int size) {
  for (int step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (int i = step + 1; i < size; i++) {
      if (array[i] < array[min_idx])
        min_idx = i;
    }
    swap(&array[min_idx], &array[step]);
  }
}

int main() {
    int size, *Arr;
    printf("Enter size of array: ");
    scanf("%d", &size);
    Arr = (int *) malloc(size * sizeof(int));
    printf("Enter element of array: ");
    for(int i=0; i < size; i++)
        scanf("%d", &Arr[i]);
    selectionSort(Arr, size);
    printf("Sorted array in Acsending Order:\n");
    printArray(Arr, size);
}
