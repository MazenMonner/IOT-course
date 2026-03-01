#include <iostream>
using namespace std;

int main() {
    char op;
    double num1, num2;
    double result;
    
    // Get the operator from user
    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;
    
    // Get two numbers from user
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    
    // Perform calculation based on operator using switch-case
    switch(op) {
        case '+':
            result = num1 + num2;
            cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
            break;
            
        case '-':
            result = num1 - num2;
            cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
            break;
            
        case '*':
            result = num1 * num2;
            cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
            break;
            
        case '/':
            // Check for division by zero
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
            } else {
                cout << "Error: Division by zero is not allowed." << endl;
            }
            break;
            
        default:
            cout << "Error: Invalid operator." << endl;
    }
    
    return 0;
}