//
//  Header.h
//  Patient Charges
//
//  Created by Alexander Korchak on 30.04.2022.
//

#ifndef Header_h
#define Header_h

#include <iostream>
#include <string>
using namespace std;

class Patient
{
    string firstName;
    string middleName;
    string lastName;
    string address;
    string city;
    string state;
    int zip;
    int phone;
    string emergencyName;
    int emergencyPhone;
public:
    Patient(string, string, string, string, string, string, int, int, string, int);
    
    //setters
    void setFirstName(string);
    void setMiddleName(string);
    void setLastName(string);
    void setAddress(string);
    void setCity(string);
    void setState(string);
    void setZip(int);
    void setPhone(int);
    void setEmergencyName(string);
    void setEmergencyPhone(int);
    
    //getters
    string getFirstName() const;
    string getMiddleName() const;
    string getLastName() const;
    string getAddress() const;
    string getCity() const;
    string getState() const;
    int getZip() const;
    int getPhone() const;
    string getEmergencyName() const;
    int getEmergencyPhone() const;
};

#endif /* Header_h */
