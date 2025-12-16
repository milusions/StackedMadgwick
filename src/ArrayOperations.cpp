#include "ArrayOperations.h"

void addElementFirst(float element, float arr[], int size) {
    
    for (int i = size - 1; i > 0; --i) {
        arr[i] = arr[i - 1];
    }

    arr[0] = element;
}

float calculateMean(float arr[],int size) {
  long sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return ((float)sum) / size;
}

void nullify(float arr[],int size) {
  
  for (int i = 0; i < size; i++) {
    arr[i]=0;
  }
 
}

