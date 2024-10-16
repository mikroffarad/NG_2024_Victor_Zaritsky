#include <iostream>

using namespace std;

int main()
{
    int numValues = 5;
    int values[numValues];

    for (int counter = 0; counter < numValues; counter++) {
        cout << "Enter " << counter + 1 << " value: ";
        cin >> values[counter];
    }

    for (int row = 1; row <= numValues; row++) {
        for (int counter = 0; counter < numValues; counter++) {
            if (values[counter] >= row) {
                cout << "*";
            } else {
                cout << " ";
            }
            cout << " ";
        }
        cout << endl;
    }

    return 0;
}
