#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    // Private member variables
    string name;
    int employeeID;
    double salary;

public:
    // Constructor to initialize employee details
    Employee(string n, int id, double s) {
        name = n;
        employeeID = id;
        salary = s;
    }

    // Function to calculate and set salary based on performance
    void updateSalary(int performanceLevel) {
        double bonusPercentage = 0.0;

        // Performance Scale Logic
        if (performanceLevel == 1) {        // Excellent
            bonusPercentage = 0.20; 
        } else if (performanceLevel == 2) { // Good
            bonusPercentage = 0.10;
        } else if (performanceLevel == 3) { // Average
            bonusPercentage = 0.05;
        } else {                            // Any other
            bonusPercentage = 0.00;
        }

        salary += (salary * bonusPercentage);
    }

    // Function to display the profile
    void displayProfile() {
        cout << "--- Employee Profile ---" << endl;
        cout << "Name: " << name << endl;
        cout << "ID:   " << employeeID << endl;
        cout << "Current Salary: $" << salary << endl;
    }
};

int main() {
    // Initializing with example data
    Employee emp("Amit", 1001, 50000);

    cout << "Initial Profile:" << endl;
    emp.displayProfile();

    // Updating salary based on "Excellent" performance (Level 1)
    int rating;
    cout << "\nEnter performance rating (1: Excellent, 2: Good, 3: Average): ";
    cin >> rating;

    emp.updateSalary(rating);

    cout << "\nUpdated Profile:" << endl;
    emp.displayProfile();

    return 0;
}