#include <iostream>
using namespace std;

void printCube(double num) {
    double cube = num * num * num;
    cout << "The cube of " << num << " is: " << cube << endl;
}

int main() {
    double number;
    
    // Get number from user
    cout << "Enter a number to find its cube: ";
    cin >> number;
    
    // Call the function to print cube
    printCube(number);
    
    return 0;
}