#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "menu.h"
#include "student.h"

int askToRepeat() {
    char response[10];
    while (1) {
        printf("Do you want to perform this action again? (yes/no): ");
        scanf("%s", response);
        if (strcasecmp(response, "yes") == 0) {
            return 1;
        } else if (strcasecmp(response, "no") == 0) {
            return 0;
        } else {
            printf("Invalid response. Please type 'yes' or 'no'.\n");
        }
    }
}

int main() {
    int id, count = 0;
    int size = 2;
    Student **student = malloc(size * sizeof(Student *));
    while (1) {
        int choice = displayMenu();
        const char *operationNames[] = {
            "Add Student",
            "Update Student",
            "Find Student",
            "Display All Students",
            "Display Highest Average",
            "Display All Averages",
            "Display All Students Passed",
            "Display All Students Failed",
            "Closing Application"
        };

        displayOperation(operationNames[choice]);

        switch (choice) {
            case 0: {
                do {
                    add(&student, &size, &count);
                } while (askToRepeat());
                break;
            }
            case 1: {
                do {
                    printf("Enter Id to update a student:\n");
                    scanf("%i", &id);
                    update(id, student, count);
                } while (askToRepeat());
                break;
            }
            case 2: {
                do {
                    printf("Enter Id to find a student:\n");
                    scanf("%i", &id);
                    find(id, student, count);
                } while (askToRepeat());
                break;
            }
            case 3: {
                displayAllStudent(student, count);
                break;
            }
            case 4: {
                displayHighestAverage(student, count);
                break;
            }
            case 5: {
                displayAllAverage(student, count);
                break;
            }
            case 6: {
                displayAllStudentPassed(student, count);
                break;
            }
            case 7: {
                displayAllStudentFailed(student, count);
                break;
            }
            case 8:
                clearScreen();
                printf("Thank you :) :)\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
