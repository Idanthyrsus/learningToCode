//
//  Procedure.h
//  Patient Charges
//
//  Created by Alexander Korchak on 30.04.2022.
//

#ifndef Procedure_h
#define Procedure_h

#include <iostream>
#include <string>
using namespace std;

class Procedure
{
    string name;
    int day;
    int month;
    int year;
    string practitioner;
    double charges;
public:
    Procedure(string, int, int, int, string, double);
    
    //setters
    void setName(string);
    void setDate(int, int, int);
    void setPractitioner(string);
    void setCharges(double);

    //getters
    
    string getName() const;
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    string getPractitioner() const;
    double getCharges() const;
};

#endif /* Procedure_h */
