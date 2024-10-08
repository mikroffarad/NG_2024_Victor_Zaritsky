#include <iostream>

using namespace std;

int main()
{
        double firstNumber;
        double secondNumber;
        char operation;

        cout << "Type number a: ";
        cin >> firstNumber;

        cout << "Type number b: ";
        cin >> secondNumber;

        cout << "Select operation (+, -, *, /): ";
        cin >> operation;

        switch(operation) {
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
                if (secondNumber != 0) {
                    cout << firstNumber / secondNumber << endl;
                } else {
                    cout << "Division by zero!" << endl;
                }
                break;
            default:
                cout << "Error!" << endl;
            }
}
