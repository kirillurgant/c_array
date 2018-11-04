#include <stdio.h>
#include "../../cArray.h"

void swap(int *a, int *b);
int bubbleSort(int *arr, int SIZE);
int shakerSort(int *arr, int SIZE);
int selectionSort(int *arr, int SIZE);

int main(int argc, char const *argv[]) {
  int const SIZE = 10;
  int *arr = getRandomArray(SIZE, 0, 100);
  printf("Count of operations: %d \n", bubbleSort(cloneArray(arr, SIZE), SIZE));
  puts("");
  printf("Count of operations: %d \n", shakerSort(cloneArray(arr, SIZE), SIZE));
  puts("");
  printf("Count of operations: %d \n", selectionSort(cloneArray(arr, SIZE), SIZE));
  return 0;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int bubbleSort(int *arr, int SIZE) {
  int count = 0;
  printf("Array before sorting: \n");
  printArr(arr, SIZE);

  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE - 1; j++) {
      count += 1;
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
        count += 1;
      }
    }
  }

  printf("Array after sorting: \n");
  printArr(arr, SIZE);
  return count;
}

int shakerSort(int *arr, int SIZE) {
  int count = 0;
  int maxI = SIZE - 1, minI = 0;

  printf("Array before sorting: \n");
  printArr(arr, SIZE);

  for (int i = 0; i < SIZE; i++) {
    if (i % 2 == 0) {
      for (int j = minI; j < maxI; j++) {
        count += 1;
        if (arr[j] > arr[j + 1]) {
          swap(&arr[j], &arr[j + 1]);
          count += 1;
        }
      }
      maxI -= 1;
    } else {
      for (int j = maxI; j > minI; j--) {
        count += 1;
        if (arr[j] < arr[j - 1]) {
          swap(&arr[j], &arr[j - 1]);
          count += 1;
        }
      }
      minI += 1;
    }
  }

  printf("Array after sorting: \n");
  printArr(arr, SIZE);
  return count;
}

int selectionSort(int *arr, int SIZE) {
  int count = 0;
  int minIndex, minJ = 1;
  printf("Array before sorting: \n");
  printArr(arr, SIZE);

  for (int i = 0; i < SIZE - 1; i++) {
    minIndex = i;

    for (int j = minJ; j < SIZE; j++) {
      count += 1;
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
        count += 1;
      }
    }

    swap(&arr[i], &arr[minIndex]);
    minJ +=1;
  }

  printf("Array after sorting: \n");
  printArr(arr, SIZE);
  return count;
}
