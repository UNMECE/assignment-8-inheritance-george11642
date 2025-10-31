#include "Field.h"
#include <iostream>

// Default constructor - sets components to 0
Field::Field() {
    value = new double[3];
    value[0] = 0.0;
    value[1] = 0.0;
    value[2] = 0.0;
}

// Constructor with 3 values
Field::Field(double x, double y, double z) {
    value = new double[3];
    value[0] = x;
    value[1] = y;
    value[2] = z;
}

// Copy constructor
Field::Field(const Field& other) {
    value = new double[3];
    value[0] = other.value[0];
    value[1] = other.value[1];
    value[2] = other.value[2];
}

// Destructor
Field::~Field() {
    delete[] value;
}

// Assignment operator
Field& Field::operator=(const Field& other) {
    if (this != &other) {
        value[0] = other.value[0];
        value[1] = other.value[1];
        value[2] = other.value[2];
    }
    return *this;
}

// Print magnitude function
void Field::printMagnitude() const {
    std::cout << "Components: (" << value[0] << ", " << value[1] << ", " << value[2] << ")" << std::endl;
}

