
#include "student.h"

char calcGrade(int index, Student *arr[], int count) {
    long long average = calcAverage(index, arr, count);
    if (average < 60) {
        arr[index]->grade = 'F';
    } else if (average >= 60 && average < 70) {
        arr[index]->grade = 'D';
    } else if (average >= 70 && average < 80) {
        arr[index]->grade = 'C';
    } else if (average >= 80 && average < 90) {
        arr[index]->grade = 'B';
    } else if (average >= 90) {
        arr[index]->grade = 'A';
    }
    return arr[index]->grade;
}
