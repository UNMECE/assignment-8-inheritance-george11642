#include "ElectricField.h"
#include <iostream>

const double EPSILON_0 = 8.854e-12;  // Permittivity of free space in F/m
const double PI = 3.14159265358979323846;

// Default constructor
ElectricField::ElectricField() : Field() {
    calculatedField = 0.0;
}

// Constructor with 3 values - calls base class constructor
ElectricField::ElectricField(double x, double y, double z) : Field(x, y, z) {
    calculatedField = 0.0;
}

// Copy constructor
ElectricField::ElectricField(const ElectricField& other) : Field(other) {
    calculatedField = other.calculatedField;
}

// Assignment operator
ElectricField& ElectricField::operator=(const ElectricField& other) {
    if (this != &other) {
        Field::operator=(other);
        calculatedField = other.calculatedField;
    }
    return *this;
}

// Calculate electric field using Gauss' Law: E = Q/(4πr²ε₀)
void ElectricField::calculateElectricField(double Q, double r) {
    if (r > 0) {
        calculatedField = Q / (4.0 * PI * r * r * EPSILON_0);
    } else {
        calculatedField = 0.0;
    }
}

// Overloaded + operator
ElectricField ElectricField::operator+(const ElectricField& other) const {
    ElectricField result;
    result.value[0] = this->value[0] + other.value[0];
    result.value[1] = this->value[1] + other.value[1];
    result.value[2] = this->value[2] + other.value[2];
    return result;
}

// Overloaded << operator
std::ostream& operator<<(std::ostream& os, const ElectricField& field) {
    os << "Electric Field Components: (" << field.value[0] << ", " 
       << field.value[1] << ", " << field.value[2] << ")";
    return os;
}

