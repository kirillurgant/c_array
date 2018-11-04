#include <stdio.h>
#include "../../cArray.h"

void swap(int *a, int *b);

int main(int argc, char const *argv[]) {
  int const SIZE = 10;
  int *arr = getRandomArray(SIZE, 0, 100);
  int maxI = SIZE - 1, minI = 0;

  printf("Array before sorting: \n");
  printArr(arr, SIZE);

  for (int i = 0; i < SIZE; i++) {
    if (i % 2 == 0) {
      for (int j = minI; j < maxI; j++) {
        if (arr[j] > arr[j + 1]) swap(&arr[j], &arr[j + 1]);
      }
      maxI -= 1;
    } else {
      for (int j = maxI; j > minI; j--) {
        if (arr[j] < arr[j - 1]) swap(&arr[j], &arr[j - 1]);
      }
      minI += 1;
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
