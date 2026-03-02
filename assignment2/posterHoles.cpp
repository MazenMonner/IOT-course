#include <iostream>
using namespace std;

// Function to count holes in a single digit using if statements
int countHolesInDigit(int digit) {
    if (digit == 0 || digit == 4 || digit == 6 || digit == 9) {
        return 1;  // 1 hole
    }
    if (digit == 8) {
        return 2;  // 2 holes
    }
    if (digit == 1 || digit == 2 || digit == 3 || digit == 5 || digit == 7) {
        return 0;  // 0 holes
    }
    return 0;
}

// Function to count total holes in a number
int countTotalHoles(int num) {
    int totalHoles = 0;
    
    // Handle negative numbers
    if (num < 0) {
        num = -num;
    }
    
    // Special case for 0
    if (num == 0) {
        return 1;
    }
    
    // Process each digit
    while (num > 0) {
        int digit = num % 10;  // Get last digit
        totalHoles = totalHoles + countHolesInDigit(digit);
        num = num / 10;        // Remove last digit
    }
    
    return totalHoles;
}

int main() {
    int number;
    
    // Get input from user
    cout << "Enter an integer: ";
    cin >> number;
    
    // Calculate and display total holes
    int holes = countTotalHoles(number);
    cout << "Total holes in " << number << " is: " << holes << endl;
    
    return 0;
}