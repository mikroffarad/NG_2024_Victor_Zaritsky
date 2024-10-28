#include <iostream>
using namespace std;

int main()
{
    const int MAX_INPUTS = 5;
    int values[MAX_INPUTS];

    for (int i = 0; i < MAX_INPUTS; i++) {
        cout << "Enter " << i + 1 << " value: ";
        cin >> values[i];
    }

    char line[MAX_INPUTS * 2];

    for (int row = 1; row <= MAX_INPUTS; row++) {
        for (int col = 0; col < MAX_INPUTS * 2; col++) {
            line[col] = ' ';
        }
        for (int col = 0; col < MAX_INPUTS; col++) {
            if (values[col] >= row) {
                line[col * 2] = '*';
            }
        }
        cout << line << endl;
    }

}
