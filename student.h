#ifndef STUDENT_H
#define STUDENT_H
#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    int id;
    char name[30];
    char **subjects;
    int *score;
    int numberOfSubjects;
    int averageOfSubjects;
    char grade;
} Student;

void ResizeArray(Student ***arr, int *oldSize, int newSize);
int exist(int id, Student *arr[], int count);
void find(int id, Student *arr[], int count);
int  calcAverage(int index, Student *arr[], int count);
char calcGrade(int index, Student *arr[], int count);
void add(Student ***arr, int *size, int *count);
void update(int id, Student *arr[], int count);
void displayAllStudent(Student *arr[], int count);
void displayHighestAverage(Student *arr[], int count);
void displayAllAverage(Student *arr[], int count);
void displayAllStudentPassed(Student *arr[], int count);
void displayAllStudentFailed(Student *arr[], int count);
#endif
