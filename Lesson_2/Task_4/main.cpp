#include <iostream>

using namespace std;

int main()
{
    char string[256];
    cout << "Enter a string: ";
    cin.getline(string, 256);
    int element = 0;
    while (string[element] != 0) {
        element++;
    }
    cout << "You entered " << element << " characters" << endl;
}
