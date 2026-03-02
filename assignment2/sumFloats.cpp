#include <iostream>
using namespace std;

int main() {
    float num1, num2;
    float sum;
    int floorValue;
    
    // Get two floating numbers from user
    cout << "Enter first floating number: ";
    cin >> num1;
    
    cout << "Enter second floating number: ";
    cin >> num2;
    
    // Calculate the sum
    sum = num1 + num2;
    floorValue = (int)sum;
    cout << "Sum: " << sum << endl;
    cout << "Floor value: " << floorValue << endl;
    
    return 0;
}