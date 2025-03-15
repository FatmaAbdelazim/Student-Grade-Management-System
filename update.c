#include "student.h"

void update(int id, Student *arr[], int count) {
    int index = exist(id, arr, count);
    if (index == -1) {
        printf("Student with ID %i not exists!\n", id);
        return;
    }
    for (int j = 0; j < arr[index]->numberOfSubjects; j++) {
        printf("Enter New score of Subject %s: ", arr[index]->subjects[j]);
        scanf("%i", &arr[index]->score[j]);
    }
    arr[index]->averageOfSubjects = calcAverage(index, arr, count);
    arr[index]->grade = calcGrade(index, arr, count);
}
