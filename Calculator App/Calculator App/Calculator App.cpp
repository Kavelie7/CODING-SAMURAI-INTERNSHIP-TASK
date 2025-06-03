// Calculator.cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Welcome to the Simple Calculator App!" << endl;
    cout << "This app can perform basic arithmetic operations." << endl;
    cout << "You will enter two numbers and choose an operation." << endl;

    double num1, num2;
    char operation;

    // Input
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    // Process & Output
    switch (operation) {
    case '+':
        cout << "Result: " << num1 + num2 << endl;
        break;
    case '-':
        cout << "Result: " << num1 - num2 << endl;
        break;
    case '*':
        cout << "Result: " << num1 * num2 << endl;
        break;
    case '/':
        if (num2 != 0)
            cout << "Result: " << num1 / num2 << endl;
        else
            cout << "Error: Division by zero is not allowed." << endl;
        break;
    default:
        cout << "Error: Invalid operation selected." << endl;
    }

    return 0;
}
