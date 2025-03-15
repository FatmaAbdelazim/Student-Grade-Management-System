
#include "student.h"

int exist(int id, Student *arr[], int count) {
    for (int i = 0; i < count; i++) {
        if (arr[i]->id == id) {
            return i;
        }
    }
    return -1;
}
