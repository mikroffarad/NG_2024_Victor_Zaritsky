#include <iostream>

using namespace std;

int main()
{
    int arrayLength = 5;
    int array[arrayLength];

    for (int counter = 0; counter < arrayLength; counter++) {
        cout << "Enter " << counter + 1 << " value: ";
        cin >> array[counter];
    }

    for (int counter = 0; counter < arrayLength; counter++) {
        cout << array[counter];
        if (arrayLength - counter != 1) {
            cout << ",";
        }
    }
    cout << endl;
}
