#include<conio.h>
#include "student.h"

void displayHighestAverage(Student *arr[], int count) {
    long long highestAverage = 0;
    int index = 0;
    for (int i = 0; i < count; i++) {
        if (arr[i]->averageOfSubjects >= highestAverage) {
            highestAverage = arr[i]->averageOfSubjects;
            index = i;
        }
    }
    printf("Highest Average %i for Student:  %s \n", highestAverage, arr[index]->name);
     printf("\nPress any key to return to the menu");
 _getch();
}
