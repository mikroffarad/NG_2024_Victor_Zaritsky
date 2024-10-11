#include <iostream>

using namespace std;

int main()
{
    int salary;
    cout << "Enter your salary: ";
    cin >> salary;

    if (salary < 1000) {
        cout << "Work more and harder!" << endl;
    }

    if (salary > 999) {

        if (salary < 1000000) {
            cout << "Well done!" << endl;
        }

        if (salary > 999999) {
            cout << "You're a millioner!" << endl;
        }
    }


}
