#include <iostream>
using namespace std;

int main() {
    float num1, num2;
    float sum;
    int floorValue;
    
    // Get two floating numbers from user
    cout << "Enter the first floating number: ";
    cin >> num1;
    
    cout << "Enter the second floating number: ";
    cin >> num2;
    
    // Calculate the sum
    sum = num1 + num2;
    
    // Determine the integer floor (truncate decimal part)
    floorValue = (int)sum;
    
    // Display results with formatting
    cout << "--------------------------------" << endl;
    cout << "Sum: " << sum << endl;
    cout << "Integer Floor: " << floorValue << endl;
    cout << "--------------------------------" << endl;
    
    return 0;
}