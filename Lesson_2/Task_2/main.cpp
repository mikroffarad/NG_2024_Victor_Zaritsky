#include <iostream>

using namespace std;

int main()
{
    int MAX_INPUTS = 5;
    int values[MAX_INPUTS];

    for (int counter = 0; counter < MAX_INPUTS; counter++) {
        cout << "Enter " << counter + 1 << " value: ";
        cin >> values[counter];
    }

    for (int row = 1; row <= MAX_INPUTS; row++) {
        for (int counter = 0; counter < MAX_INPUTS; counter++) {
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
