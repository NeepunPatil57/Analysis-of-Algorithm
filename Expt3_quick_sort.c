#include <stdio.h>
#include <stdlib.h>

void printArray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int array[], int low, int high) {
  int pivot = array[high];
  int i = (low - 1);

  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(&array[i], &array[j]);
    }
  }
  swap(&array[i + 1], &array[high]);
  return (i + 1);
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int mid = partition(array, low, high);
    quickSort(array, low, mid - 1);
    quickSort(array, mid + 1, high);
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

    printf("Unsorted Array\n");
    printArray(Arr, size);

    quickSort(Arr, 0, size - 1);
    printf("Sorted array in ascending order: \n");
    printArray(Arr, size);
}
