#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int num;
    int sqrt_num;
    
    cout << "Enter a positive integer: ";
    cin >> num;
    
    sqrt_num = sqrt(num);
    
    if (sqrt_num * sqrt_num == num) {
        cout << num << " is a perfect square." << endl;
    } else {
        cout << num << " is not a perfect square." << endl;
    }
    
    return 0;
}