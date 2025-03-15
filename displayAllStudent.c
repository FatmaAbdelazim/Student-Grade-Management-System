#include<conio.h>
#include "student.h"

void displayAllStudent(Student *arr[], int count) {
    for (int i = 0; i < count; i++) {
        printf(" Student id: %i\t", arr[i]->id);
        printf("Student name: %s\t", arr[i]->name);
        printf(" Number of Subjects: %i\t", arr[i]->numberOfSubjects);
        printf("\n");
        for (int j = 0; j < arr[i]->numberOfSubjects; j++) {
            printf(" Name of Subject: %s\t",arr[i]->subjects[j]);
            printf("Score of Subject: %i\t", arr[i]->score[j]);
            printf("\n");
        }
        printf(" Student average: %i\t", arr[i]->averageOfSubjects);
        printf("Student grade: %c", arr[i]->grade);
        printf("\n============================================\n\n");
    }

 printf("\nPress any key to return to the menu");
 _getch();
}
