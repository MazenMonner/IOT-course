#include <iostream>
using namespace std;

int main() {
    int temperature;
    int heatingTime;
    
    cout << "Enter the water temperature: ";
    cin >> temperature;
    
    if (temperature > 100) {
        cout << "Invalid temperature." << endl;
    } else if (temperature > 90) {
        heatingTime = 1;
        cout << "output = " << heatingTime << endl;
    } else if (temperature > 60) {
        heatingTime = 3;
        cout << "output = " << heatingTime << endl;
    } else if (temperature > 30) {
        heatingTime = 5;
        cout << "output = " << heatingTime << endl;
    } else if (temperature >= 0) {
        heatingTime = 7;
        cout << "output = " << heatingTime << endl;
    } else {
        cout << "Invalid temperature." << endl;
    }
    
    return 0;
}