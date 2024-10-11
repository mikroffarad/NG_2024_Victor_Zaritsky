#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}
void drawTriangle(int size, bool isLeftAligned, bool isPointingDown) {
    for (int row = 1; row <= size; row++) {
        int stars = isPointingDown ? size - row + 1 : row;
        int spaces = isLeftAligned ? 0 : size - stars;

        for (int spaceIndex = 0; spaceIndex < spaces; spaceIndex++) {
            cout << " ";
        }

        for (int starIndex = 0; starIndex < stars; starIndex++) {
            cout << "*";
        }

        cout << endl;
        // cout << string(spaces, ' ') << string(stars, '*') << '\n';
    }
}

int main() {
    int size;
    cout << "Введите размер треугольника: ";
    cin >> size;

    int DELAY_INTERVAL = 200;

    while (true) {
        clearScreen();
        drawTriangle(size, true, false);
        this_thread::sleep_for(chrono::milliseconds(DELAY_INTERVAL));

        clearScreen();
        drawTriangle(size, false, false);
        this_thread::sleep_for(chrono::milliseconds(DELAY_INTERVAL));

        clearScreen();
        drawTriangle(size, false, true);
        this_thread::sleep_for(chrono::milliseconds(DELAY_INTERVAL));

        clearScreen();
        drawTriangle(size, true, true);
        this_thread::sleep_for(chrono::milliseconds(DELAY_INTERVAL));
    }
}
