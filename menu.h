#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void clearScreen() {
    system("cls");
}
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void drawFrame(int startX, int startY, int width, int height) {
    setColor(14);
    for (int i = 0; i < width; i++) {
        gotoxy(startX + i, startY);
        printf("-");
        gotoxy(startX + i, startY + height);
        printf("-");
    }
    for (int i = 0; i <= height; i++) {
        gotoxy(startX, startY + i);
        printf("|");
        gotoxy(startX + width, startY + i);
        printf("|");
    }
    gotoxy(startX, startY);
    printf("+");
    gotoxy(startX + width, startY);
    printf("+");
    gotoxy(startX, startY + height);
    printf("+");
    gotoxy(startX + width, startY + height);
    printf("+");
    setColor(15);
}

void displayOperation(const char *operationName) {
    clearScreen();
    int width = 40;
    int height = 5;
    int startX = (80 - width) / 2;
    int startY = 1;

    drawFrame(startX-4, startY, width, height);

    gotoxy(startX + 1, startY + 2);
    setColor(12);
    printf("%s", operationName);

    setColor(15);

    gotoxy(0, startY + height + 2);
}

int displayMenu() {
    const char *options[] = {
        "Add Student",
        "Update Student",
        "Find Student",
        "Display All Students",
        "Display Highest Average",
        "Display All Averages",
        "Display All Students Passed",
        "Display All Students Failed",
        "Close"
    };
    int choice = 0;
    int numOptions = sizeof(options) / sizeof(options[0]);

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    int screenWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int screenHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    int startX = (screenWidth - 50) / 2;
    int startY = screenHeight / 3;

    drawFrame(startX-4, startY - 1, 50, numOptions + 5);

    while (1) {
        clearScreen();
        drawFrame(startX-4, startY - 1, 50, numOptions + 5);
        gotoxy(startX + 1, startY);
        setColor(12);
        printf("\t Student Grade Management System\n");
        setColor(15);
        for (int i = 0; i < numOptions; i++) {
            gotoxy(startX + 1, startY + 3 + i);
            if (i == choice) {
                setColor(11);
                printf(">> %s\n", options[i]);
                setColor(15);
            } else {
                printf("   %s\n", options[i]);
            }
        }

        char key = _getch();
        if (key == 72) {
            choice = (choice - 1 + numOptions) % numOptions;
        } else if (key == 80) {
            choice = (choice + 1) % numOptions;
        } else if (key == '\r') {
            return choice;
        }
    }
}

#endif
