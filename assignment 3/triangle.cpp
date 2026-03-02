#include <iostream>

using namespace std;

class Triangle {
private:
    // Private member variables
    double side1, side2, side3;

public:
    // Constructor to set the side lengths
    Triangle(double s1, double s2, double s3) {
        side1 = s1;
        side2 = s2;
        side3 = s3;
    }

    // Function to check if the triangle is valid
    bool isValid() {
        return (side1 + side2 > side3) && 
               (side2 + side3 > side1) && 
               (side1 + side3 > side2);
    }

    // Function to determine and print the triangle type
    void determineType() {
        if (!isValid()) {
            cout << "These sides do not form a valid triangle." << endl;
            return;
        }

        if (side1 == side2 && side2 == side3) {
            cout << "The triangle is equilateral." << endl;
        } else if (side1 == side2 || side2 == side3 || side1 == side3) {
            cout << "The triangle is isosceles." << endl;
        } else {
            cout << "The triangle is scalene." << endl;
        }
    }
};

int main() {
    double s1, s2, s3;

    cout << "Enter the lengths of the three sides: ";
    cin >> s1 >> s2 >> s3;

    // Create Triangle object
    Triangle myTriangle(s1, s2, s3);

    // Determine and display result
    myTriangle.determineType();

    return 0;
}