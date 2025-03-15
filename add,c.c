#include "student.h"

void add(Student ***arr, int *size, int *count) {
    if (*count >= *size) {
        ResizeArray(arr, size, *size * 2);
    }

    int numberStudentSubjects, id;
    (*arr)[*count] = malloc(sizeof(Student));
    printf("Enter Student id: ");
    scanf("%i", &id);

    int index = exist(id, *arr, *count);
    if (index != -1) {
        printf("Student with ID %i already exists!\n", id);
        free((*arr)[*count]);
        return;
    }

    (*arr)[*count]->id = id;
    printf("Enter Student name: ");
    scanf("%s", (*arr)[*count]->name);
    printf("Enter Number Of Subjects For This Student: ");
    scanf("%i", &numberStudentSubjects);
    (*arr)[*count]->numberOfSubjects = numberStudentSubjects;
    (*arr)[*count]->subjects = malloc(numberStudentSubjects * sizeof(char *));
    (*arr)[*count]->score = malloc(numberStudentSubjects * sizeof(int));

    for (int i = 0; i < numberStudentSubjects; i++) {
        printf("Enter Name of Subject Number %i: ", i + 1);
        (*arr)[*count]->subjects[i] = malloc(30 * sizeof(char));
        scanf("%s", (*arr)[*count]->subjects[i]);
        printf("Enter Score of Subject Number %i: ", i + 1);
        scanf("%i", &(*arr)[*count]->score[i]);
    }

    (*arr)[*count]->averageOfSubjects = calcAverage(*count, *arr, *count);
    (*arr)[*count]->grade = calcGrade(*count, *arr, *count);

    (*count)++;
}
