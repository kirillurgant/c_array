#include <stdio.h>
#include "../../cArray.h"

void swap(int *a, int *b);

int main(int argc, char const *argv[]) {
  int const SIZE = 10;
  int *arr = getRandomArray(SIZE, 0, 100);
  printf("Array before sorting: \n");
  printArr(arr, SIZE);

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE - 1; j++) {
      if (arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
    }
  }

  printf("Array after sorting: \n");
  printArr(arr, SIZE);
  return 0;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
};
