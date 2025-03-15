#include "student.h"

int calcAverage(int index, Student *arr[], int count) {
    long long average = 0;
    for (int j = 0; j < arr[index]->numberOfSubjects; j++) {
        average += arr[index]->score[j];
    }
    return (int)average / arr[index]->numberOfSubjects;
}
