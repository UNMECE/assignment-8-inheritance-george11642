#include "MagneticField.h"
#include <iostream>

const double MU_0 = 4.0 * 3.14159265358979323846 * 1e-7;  // Permeability of free space in H/m
const double PI = 3.14159265358979323846;

// Default constructor
MagneticField::MagneticField() : Field() {
    calculatedField = 0.0;
}

// Constructor with 3 values - calls base class constructor
MagneticField::MagneticField(double x, double y, double z) : Field(x, y, z) {
    calculatedField = 0.0;
}

// Copy constructor
MagneticField::MagneticField(const MagneticField& other) : Field(other) {
    calculatedField = other.calculatedField;
}

// Assignment operator
MagneticField& MagneticField::operator=(const MagneticField& other) {
    if (this != &other) {
        Field::operator=(other);
        calculatedField = other.calculatedField;
    }
    return *this;
}

// Calculate magnetic field using Ampere's Law: B = I/(2πrμ₀)
void MagneticField::calculateMagneticField(double I, double r) {
    if (r > 0) {
        calculatedField = I / (2.0 * PI * r * MU_0);
    } else {
        calculatedField = 0.0;
    }
}

// Overloaded + operator
MagneticField MagneticField::operator+(const MagneticField& other) const {
    MagneticField result;
    result.value[0] = this->value[0] + other.value[0];
    result.value[1] = this->value[1] + other.value[1];
    result.value[2] = this->value[2] + other.value[2];
    return result;
}

// Overloaded << operator
std::ostream& operator<<(std::ostream& os, const MagneticField& field) {
    os << "Magnetic Field Components: (" << field.value[0] << ", " 
       << field.value[1] << ", " << field.value[2] << ")";
    return os;
}

