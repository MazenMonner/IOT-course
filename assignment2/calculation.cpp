#include <iostream>
using namespace std;

bool calculate(char op, double num1, double num2, double &result) {
    switch(op) {
        case '+':
            result = num1 + num2;
            return true;
            
        case '-':
            result = num1 - num2;
            return true;
            
        case '*':
            result = num1 * num2;
            return true;
            
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                return true;
            } else {
                cout << "Error: Division by zero!" << endl;
                return false;
            }
            
        default:
            cout << "Error: Invalid operation!" << endl;
            return false;
    }
}

int main() {
    char operation;
    double num1, num2, result;
    
    // Get operation from user
    cout << "Enter operation (+, -, *, /): ";
    cin >> operation;
    
    // Get two numbers from user
    cout << "Enter two numbers: ";
    cin >> num1 >> num2;
    
    // Call the function and check if successful
    if (calculate(operation, num1, num2, result)) {
        cout << "The result is: " << result << endl;
    }
    
    return 0;
}