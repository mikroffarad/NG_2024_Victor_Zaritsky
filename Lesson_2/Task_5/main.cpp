#include <iostream>

using namespace std;

int main()
{
    char string[256];
    cout << "Enter a string: ";
    cin.getline(string, 256);

    int element = 0;
    int wordCount = 0;
    int isWord = false;

    while (string[element] != 0) {

        if ((string[element] >= 'a' && string[element] <= 'z')
            || (string[element] >= 'A' && string[element] <= 'Z')) {
            if (!isWord) {
                isWord = true;
                wordCount++;
            }
        } else {
            isWord = false;
        }
        element++;
    }

    cout << "You entered " << wordCount << " words" << endl;
}
