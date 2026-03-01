#include <iostream>
using namespace std;

int main() {
    char ch;
    
    // Get character input from user
    cout << "Enter any character: ";
    cin >> ch;
    
    // Check if character is an alphabet (a-z or A-Z)
    if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
        cout << ch << " is an alphabet." << endl;
    } else {
        cout << ch << " is not an alphabet." << endl;
    }
    
    return 0;
}