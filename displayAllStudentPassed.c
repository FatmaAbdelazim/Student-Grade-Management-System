#include<conio.h>
#include "student.h"

void displayAllStudentPassed(Student *arr[], int count) {
    int  pa=0;
    for (int i = 0; i < count; i++) {
        if (arr[i]->grade != 'F') {
            printf(" Student id:%i\t", arr[i]->id);
            printf("Student Name:%s\t", arr[i]->name);
            printf("Student Average:%i\t", arr[i]->averageOfSubjects);
            printf("Student Grade:%c\n", arr[i]->grade);
             pa++;

        }
    }
    if(pa == 0)
    {
     printf("No Student Passed");
    }
     printf("\nPress any key to return to the menu");
 _getch();
}
