#ifndef ARRAY_H_
#define ARRAY_H_

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int *getRandomArray(const int ARRAY_SIZE, const int MIN_VAL, const int MAX_VAL) {
  int *arr = (int*)calloc(ARRAY_SIZE, sizeof(int));
  srand(time(NULL));

  for (int i = 0; i < ARRAY_SIZE; i++) {
    arr[i] = (rand() % (MAX_VAL - MIN_VAL + 1)) + MIN_VAL;
  }

  return arr;
}

void printArr(int *arr, const int SIZE) {
  for (int i = 0; i < SIZE; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

#endif /* ARRAY_H_ */
