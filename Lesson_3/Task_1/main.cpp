#include <iostream>

using namespace std;

int askValue(char str[]) {
    int value;
    cout << str;
    cin >> value;
    return value;
}

void drawRow(int size) {
    if (size > 0) {
        drawRow(size - 1);
        cout << "*";
    }
}

void drawSpaces(int size) {
    if (size > 0) {
        drawSpaces (size - 1);
        cout << " ";
    }
}

void drawTreeRow(int row, int treeHeight) {
    if (row < treeHeight) {
        drawSpaces(treeHeight - row - 1);
        drawRow(row * 2 + 1);
        cout << endl;
        drawTreeRow(row + 1, treeHeight);
    }
}

void drawTrunk(int treeHeight) {
    drawSpaces(treeHeight - 1);
    cout << "*" << endl;
}

int main() {
    int treeHeight = askValue("Enter a tree height: ");
    drawTreeRow(0, treeHeight);
    drawTrunk(treeHeight);
}
