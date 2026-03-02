#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    // Private member variables
    string name;
    int age;
    string country;

public:
    // Setter functions (to set values)
    void setName(string n) {
        name = n;
    }

    void setAge(int a) {
        age = a;
    }

    void setCountry(string c) {
        country = c;
    }

    // Getter functions (to retrieve values)
    string getName() {
        return name;
    }

    int getAge() {
        return age;
    }

    string getCountry() {
        return country;
    }
};

int main() {
    // Create an object of the Person class
    Person p;

    // Use setters to assign values
    p.setName("Amit");
    p.setAge(25);
    p.setCountry("Egypt");

    // Use getters to display the values
    cout << "Person Details:" << endl;
    cout << "Name: " << p.getName() << endl;
   cout << "Age: " << p.getAge() << endl;
    cout << "Country: " << p.getCountry() << endl;

    return 0;
}