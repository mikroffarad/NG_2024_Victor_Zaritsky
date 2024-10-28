#include <iostream>

using namespace std;

int main()
{
    const int MAX_INPUT = 256;
    char string[MAX_INPUT];
    cin.getline(string, MAX_INPUT);

    int count[MAX_INPUT] = {0};

    for (int counter = 0; string[counter] != '\0'; counter++) {
        count[string[counter]]++;
    }

    for (int counter = 0; string[counter] != '\0'; counter++) {
        if (count[string[counter]] != 0) {
            cout << char(39) << string[counter] << char(39) << ": " << count[string[counter]] << endl;
            count[string[counter]] = 0;
        }
    }
}
