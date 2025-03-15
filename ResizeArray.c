#include "student.h"

void ResizeArray(Student ***arr, int *oldSize, int newSize) {
    Student **newArr = malloc(newSize * sizeof(Student *));
    for (int i = 0; i < *oldSize; i++) {
        newArr[i] = (*arr)[i];
    }
    free(*arr);
    *arr = newArr;
    *oldSize = newSize;
}
