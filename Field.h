#ifndef FIELD_H
#define FIELD_H

class Field {
protected:
    double *value;  // Pointer to array of 3 components [x, y, z]

public:
    // Default constructor - sets components to 0
    Field();
    
    // Constructor with 3 values
    Field(double x, double y, double z);
    
    // Copy constructor
    Field(const Field& other);
    
    // Destructor
    ~Field();
    
    // Assignment operator
    Field& operator=(const Field& other);
    
    // Print magnitude function
    void printMagnitude() const;
    
    // Getter functions
    double getX() const { return value[0]; }
    double getY() const { return value[1]; }
    double getZ() const { return value[2]; }
};

#endif // FIELD_H

