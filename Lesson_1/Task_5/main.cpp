#include <iostream>
using namespace std;

int main() {
    int treeHeight;
    cout << "Enter a number: ";
    cin >> treeHeight;

    for(int currentRow = 0; currentRow < treeHeight; currentRow++) {

        for(int spaceIndex = 0; spaceIndex < treeHeight-currentRow-1; spaceIndex++)
            cout << " ";

        for(int starIndex = 0; starIndex < 2*currentRow+1; starIndex++)
            cout << "*";
        cout << endl;
    }

    for(int spaceIndex = 0; spaceIndex < treeHeight-1; spaceIndex++)
        cout << " ";
    cout << "*" << endl;

    return 0;
}
