#include<conio.h>
#include "student.h"

void displayAllStudentFailed(Student *arr[], int count) {
    int fi=0;
    for (int i = 0; i < count; i++) {
        if (arr[i]->grade == 'F') {
            printf(" Student id:%i\t", arr[i]->id);
            printf("Student Name:%s\t", arr[i]->name);
            printf("Student Average:%i\t", arr[i]->averageOfSubjects);
            printf("Student Grade:%c\t", arr[i]->grade);
              fi++;
        }
    }
    if(fi == 0)
    {
     printf("No Student Failed");
    }
     printf("\nPress any key to return to the menu");
 _getch();
}
