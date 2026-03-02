#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    // Private member variables
    string company;
    string model;
    int year;

public:
    // Setter functions to set the values
    void setCompany(string c) {
        company = c;
    }

    void setModel(string m) {
        model = m;
    }

    void setYear(int y) {
        year = y;
    }

    // Getter functions to get the values
    string getCompany() {
        return company;
    }

    string getModel() {
        return model;
    }

    int getYear() {
        return year;
    }
};

int main() {
    // Creating an object of the Car class
    Car myCar;

    // Using setters to assign the example values
    myCar.setCompany("Toyota");
    myCar.setModel("Corolla");
    myCar.setYear(2022);

    // Using getters to display the information
    cout << "--- Car Information ---" << endl;
    cout << "Company: " << myCar.getCompany() << endl;
    cout << "Model:   " << myCar.getModel() << endl;
    cout << "Year:    " << myCar.getYear() << endl;

    return 0;
}