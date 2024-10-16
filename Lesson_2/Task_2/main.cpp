#include <iostream>

using namespace std;

int main()
{
    int MAX_INPUTS = 20;
    int values[MAX_INPUTS];

    int maxValue = 0;
    int maxEnteredInputs = 0;

    for (int counter = 0; counter < MAX_INPUTS; counter++) {
        cout << "Enter " << counter + 1 << " value: ";
        cin >> values[counter];

        if (values[counter] > maxValue) {
            maxValue = values[counter];
        }

        if (values[counter] == 0) {
            maxEnteredInputs = counter;
            break;
        }
    }

    for (int counterValues = 0; counterValues < maxEnteredInputs; counterValues++) {

        int spaces = (maxValue - values[counterValues]) / 2;

        for (int counterSpaces = 0; counterSpaces < spaces; counterSpaces++) {
            cout << " ";
        }

        for (int counterStars = 0; counterStars < values[counterValues]; counterStars++) {
            cout << "*";
        }

        cout << endl;
    }

}
