#include <iostream>

using namespace std;

int main()
{
    int treeHeight = 0;
    cout << "Enter a number: ";
    cin >> treeHeight;

    for (int currentRow = 1; currentRow <= treeHeight + 1; currentRow++) {

        int maxWidth = (treeHeight * 2 - 1);
        int starsCount = 2 * currentRow - 1;

        if (currentRow - treeHeight == 1) {
            starsCount = 1;
        }

        int spacesCount = (maxWidth - starsCount) / 2;

        for (int spaceIndex = 0; spaceIndex < spacesCount; spaceIndex++) {
            cout << " ";
        }

        for (int starIndex = 0; starIndex < starsCount; starIndex++) {
            cout << "*";
        }

        cout << endl;
    }
}
