//
//  Patient.cpp
//  Patient Charges
//
//  Created by Alexander Korchak on 30.04.2022.
//

#include "Header.h"
#include "Procedure.h"

using namespace std;

Patient::Patient(string fn, string mn, string ln, string add, string c, string s, int z, int p, string en, int ep)
{
    firstName = fn;
    middleName = mn;
    lastName = ln;
    address = add;
    city = c;
    state = s;
    zip = z;
    phone = p;
    emergencyName = en;
    emergencyPhone = ep;
}

//setters
void Patient::setFirstName(string fn)
{
    firstName = fn;
}
void Patient::setMiddleName(string mn)
{
    middleName = mn;
}
void Patient::setLastName(string ln)
{
    lastName = ln;
}
void Patient::setAddress(string ad)
{
    address = ad;
}
void Patient::setCity(string c)
{
    city = c;
}
void Patient::setState(string s)
{
    state = s;
}
void Patient::setZip(int z)
{
    zip = z;
}
void Patient::setPhone(int p)
{
    phone = p;
}
void Patient::setEmergencyName(string en)
{
    emergencyName = en;
}
void Patient::setEmergencyPhone(int ep)
{
    emergencyPhone = ep;
}

//getters
string Patient::getFirstName() const
{
    return firstName;
}
string Patient::getMiddleName() const
{
    return middleName;;
}
string Patient::getLastName() const
{
    return lastName;
}
string Patient::getAddress() const
{
    return address;
}
string Patient::getCity() const
{
    return city;
}
string Patient::getState() const
{
    return state;
}
int Patient::getZip() const
{
    return zip;
}
int Patient::getPhone() const
{
    return phone;
}
string Patient::getEmergencyName() const
{
    return emergencyName;
}
int Patient::getEmergencyPhone() const
{
    return emergencyPhone;
}
