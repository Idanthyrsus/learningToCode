//
//  Procedure.cpp
//  Patient Charges
//
//  Created by Alexander Korchak on 30.04.2022.
//

#include "Procedure.h"

Procedure::Procedure(string n, int d, int m, int y, string pr, double ch)
{
    name = n;
    day = d;
    month = m;
    year = y;
    practitioner = pr;
    charges = ch;
}

//setters
void Procedure::setName(string n)
{
    name = n;
}
void Procedure::setDate(int d, int m, int y)
{
    day = d;
    month = m;
    year = y;
}
void Procedure::setPractitioner(string pr)
{
    practitioner = pr;
}
void Procedure::setCharges(double ch)
{
    charges = ch;
}

//getters

string Procedure::getName() const
{
    return name;
}
int Procedure::getDay() const
{
    return day;
}
int Procedure::getMonth() const
{
    return month;
}
int Procedure::getYear() const
{
    return year;
}
string Procedure::getPractitioner() const
{
    return practitioner;
}
double Procedure::getCharges() const
{
    return charges;
}
