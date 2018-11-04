#include <stdio.h>
#include "../../cArray.h"

void swap(int *a, int *b);

int main(int argc, char const *argv[]) {
  int const SIZE = 10;
  int *arr = getRandomArray(SIZE, 0, 100);
  int minIndex, minJ = 1;
  printf("Array before sorting: \n");
  printArr(arr, SIZE);

  for (int i = 0; i < SIZE - 1; i++) {
    minIndex = i;

    for (int j = minJ; j < SIZE; j++) {
      if (arr[j] < arr[minIndex]) minIndex = j;
    }

    swap(&arr[i], &arr[minIndex]);
    minJ +=1;
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
