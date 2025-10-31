#include <iostream>
#include "ElectricField.h"
#include "MagneticField.h"

int main() {
    std::cout << "=== Assignment 8: Inheritance and Operator Overloading ===" << std::endl << std::endl;
    
    // Create electric and magnetic field objects using constructors with values
    std::cout << "1. Creating Electric Field with components (0, 1e5, 1e3):" << std::endl;
    ElectricField eField1(0, 1e5, 1e3);
    eField1.printMagnitude();
    
    std::cout << std::endl << "2. Creating Magnetic Field with components (1e-3, 2e-3, 5e-4):" << std::endl;
    MagneticField mField1(1e-3, 2e-3, 5e-4);
    mField1.printMagnitude();
    
    // Calculate electric field using Gauss' Law
    std::cout << std::endl << "3. Calculating Electric Field using Gauss' Law:" << std::endl;
    double charge = 1e-6;      // 1 microCoulomb
    double distanceE = 0.1;    // 10 cm = 0.1 m
    eField1.calculateElectricField(charge, distanceE);
    std::cout << "Charge Q = " << charge << " C" << std::endl;
    std::cout << "Distance r = " << distanceE << " m" << std::endl;
    std::cout << "Calculated Electric Field E = " << eField1.getCalculatedField() << " N/C" << std::endl;
    
    // Calculate magnetic field using Ampere's Law
    std::cout << std::endl << "4. Calculating Magnetic Field using Ampere's Law:" << std::endl;
    double current = 5.0;      // 5 Amperes
    double distanceB = 0.05;   // 5 cm = 0.05 m
    mField1.calculateMagneticField(current, distanceB);
    std::cout << "Current I = " << current << " A" << std::endl;
    std::cout << "Distance r = " << distanceB << " m" << std::endl;
    std::cout << "Calculated Magnetic Field B = " << mField1.getCalculatedField() << " T" << std::endl;
    
    // Demonstrate overloaded + operator for Electric Field
    std::cout << std::endl << "5. Demonstrating overloaded + operator for Electric Field:" << std::endl;
    ElectricField eField2(1e4, 2e4, 3e4);
    ElectricField eField3;
    std::cout << "eField2: ";
    eField2.printMagnitude();
    std::cout << "eField1: ";
    eField1.printMagnitude();
    eField3 = eField1 + eField2;
    std::cout << "eField3 = eField1 + eField2: ";
    eField3.printMagnitude();
    
    // Demonstrate overloaded << operator for Electric Field
    std::cout << std::endl << "6. Demonstrating overloaded << operator for Electric Field:" << std::endl;
    std::cout << eField1 << std::endl;
    std::cout << eField2 << std::endl;
    std::cout << eField3 << std::endl;
    
    // Demonstrate overloaded + operator for Magnetic Field
    std::cout << std::endl << "7. Demonstrating overloaded + operator for Magnetic Field:" << std::endl;
    MagneticField mField2(2e-3, 3e-3, 1e-3);
    MagneticField mField3;
    std::cout << "mField2: ";
    mField2.printMagnitude();
    std::cout << "mField1: ";
    mField1.printMagnitude();
    mField3 = mField1 + mField2;
    std::cout << "mField3 = mField1 + mField2: ";
    mField3.printMagnitude();
    
    // Demonstrate overloaded << operator for Magnetic Field
    std::cout << std::endl << "8. Demonstrating overloaded << operator for Magnetic Field:" << std::endl;
    std::cout << mField1 << std::endl;
    std::cout << mField2 << std::endl;
    std::cout << mField3 << std::endl;
    
    return 0;
}

