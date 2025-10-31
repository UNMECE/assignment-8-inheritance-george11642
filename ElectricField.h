#ifndef ELECTRICFIELD_H
#define ELECTRICFIELD_H

#include "Field.h"
#include <iostream>

class ElectricField : public Field {
private:
    double calculatedField;  // Stores calculated electric field value

public:
    // Default constructor
    ElectricField();
    
    // Constructor with 3 values - calls base class constructor
    ElectricField(double x, double y, double z);
    
    // Copy constructor
    ElectricField(const ElectricField& other);
    
    // Assignment operator
    ElectricField& operator=(const ElectricField& other);
    
    // Calculate electric field using Gauss' Law: E = Q/(4πr²ε₀)
    // Q is charge in Coulombs, r is distance in meters
    void calculateElectricField(double Q, double r);
    
    // Getter for calculated field
    double getCalculatedField() const { return calculatedField; }
    
    // Overloaded + operator
    ElectricField operator+(const ElectricField& other) const;
    
    // Overloaded << operator
    friend std::ostream& operator<<(std::ostream& os, const ElectricField& field);
};

#endif // ELECTRICFIELD_H

