#ifndef MAGNETICFIELD_H
#define MAGNETICFIELD_H

#include "Field.h"
#include <iostream>

class MagneticField : public Field {
private:
    double calculatedField;  // Stores calculated magnetic field value

public:
    // Default constructor
    MagneticField();
    
    // Constructor with 3 values - calls base class constructor
    MagneticField(double x, double y, double z);
    
    // Copy constructor
    MagneticField(const MagneticField& other);
    
    // Assignment operator
    MagneticField& operator=(const MagneticField& other);
    
    // Calculate magnetic field using Ampere's Law: B = I/(2πrμ₀)
    // I is current in Amperes, r is distance in meters
    void calculateMagneticField(double I, double r);
    
    // Getter for calculated field
    double getCalculatedField() const { return calculatedField; }
    
    // Overloaded + operator
    MagneticField operator+(const MagneticField& other) const;
    
    // Overloaded << operator
    friend std::ostream& operator<<(std::ostream& os, const MagneticField& field);
};

#endif // MAGNETICFIELD_H

