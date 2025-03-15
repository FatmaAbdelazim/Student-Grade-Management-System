#include<conio.h>
#include "student.h"

void displayAllAverage(Student *arr[], int count) {
    for (int i = 0; i < count; i++) {
        printf(" Average for Student\t%s: %i\n", arr[i]->name, arr[i]->averageOfSubjects);
    }
     printf("\nPress any key to return to the menu");
 _getch();
}
