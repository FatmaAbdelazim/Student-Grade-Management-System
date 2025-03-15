#include "student.h"

void find(int id, Student *arr[], int count) {
    int index = exist(id, arr, count);
    if (index != -1) {
        printf("Student id: %i\n", arr[index]->id);
        printf("Student name: %s\n", arr[index]->name);
        for (int j = 0; j < arr[index]->numberOfSubjects; j++) {
            printf("Name of Subject Number %i: %s\n", j + 1, arr[index]->subjects[j]);
            printf("Score of Subject Number %i: %i\n", j + 1, arr[index]->score[j]);
        }
        printf("Student average: %i\n", arr[index]->averageOfSubjects);
        printf("Student grade: %c \n", arr[index]->grade);
    } else {
        printf("Student with ID %i not found.\n", id);
    }
}
