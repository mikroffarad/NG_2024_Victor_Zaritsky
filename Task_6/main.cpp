#include <iostream>
#include "windows.h"

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void drawPattern1(int rows) {
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void drawPattern2(int rows) {
    for (int i = rows; i >= 1; i--) {
        for (int j = i; j > 0; j--) {
            cout << "* ";
        }
        cout << endl;
    }
}

void drawPattern3(int rows) {
    for (int i = 1; i <= rows; i++) {
        for (int k = rows - i; k > 0; k--) {
            cout << "  ";
        }
        for (int j = 1; j <= i; j++) {
            cout << "* ";
        }
        cout << endl;
    }
}

void drawPattern4(int rows) {
    for (int i = rows; i >= 1; i--) {
        for (int k = rows - i; k > 0; k--) {
            cout << "  ";
        }
        for (int j = i; j > 0; j--) {
            cout << " *";
        }
        cout << endl;
    }
}

int main()
{
    int rows;
    cout << "Enter a number of rows: ";
    cin >> rows;
    clearScreen();
    while(true) {
        drawPattern1(rows);
        Sleep(200);
        clearScreen();
        drawPattern3(rows);
        Sleep(200);
        clearScreen();
        drawPattern4(rows);
        Sleep(200);
        clearScreen();
        drawPattern2(rows);
        Sleep(200);
        clearScreen();
    }
}

