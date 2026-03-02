#include <iostream>
using namespace std;

// Function to check if number is power of 2 or power of 3
// Returns: 1 if power of 2, 0 if power of 3, -1 otherwise
int checkPower(int num) {
    // Handle invalid input (0 or negative)
    if (num <= 0) {
        return -1;
    }
    
    // Check if power of 2
    // A number is power of 2 if it has exactly one bit set in binary
    // Property: n & (n-1) == 0 for powers of 2 (except 0)
    int temp = num;
    if ((temp & (temp - 1)) == 0) {
        return 1;  // Power of 2
    }
    
    // Check if power of 3
    // Keep dividing by 3 until we get 1 (if power of 3) or not divisible
    temp = num;
    while (temp % 3 == 0) {
        temp = temp / 3;
    }
    if (temp == 1) {
        return 0;  // Power of 3
    }
    
    // Neither power of 2 nor power of 3
    return -1;
}

int main() {
    int number;
    
    // Get input from user
    cout << "Enter a number to check: ";
    cin >> number;
    
    // Call the function and get result
    int result = checkPower(number);
    
    // Display result with description
    cout << "Result code: " << result;
    if (result == 1) {
        cout << " (Power of 2)";
    } else if (result == 0) {
        cout << " (Power of 3)";
    } else {
        cout << " (Neither)";
    }
    cout << endl;
    
    return 0;
}