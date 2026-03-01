#include <iostream>
using namespace std;

int main() {
    char ch;
    
    cout << "Enter a character: ";
    cin >> ch;
    
    if (ch >= 'a' && ch <= 'z') {
        ch = ch - 32;
    }
    
    cout << "Uppercase version: " << ch << endl;
    
    return 0;
}