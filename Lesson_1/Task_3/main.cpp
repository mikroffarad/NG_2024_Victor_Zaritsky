#include <iostream>

using namespace std;

int main()
{
    char action;
    cout << "Choose an action: \n+ (add)\n- (subtract)\n* (multiply)\n/ (divide)\nYour action: ";
    cin >> action;

    double firstNumber;
    double secondNumber;

    cout << "Enter your first number: ";
    cin >> firstNumber;

    cout << "Enter your second number: ";
    cin >> secondNumber;

    cout << "Result is: ";
    switch(action) {
    case '+':
        cout << firstNumber + secondNumber << endl;
        break;
    case '-':
        cout << firstNumber - secondNumber << endl;
        break;
    case '*':
        cout << firstNumber * secondNumber << endl;
        break;
    case '/':
        cout << firstNumber / secondNumber << endl;
        break;
    }
}
