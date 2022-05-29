#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pharmacy
{
 string medication1,
        medication2,
        medication3,
        medication4,
        medication5;
 double medicationPrice1,
        medicationPrice2,
        medicationPrice3,
        medicationPrice4,
        medicationPrice5;
 int numOfItemsBought;
public:
    Pharmacy(): medication1(""), medication2(""), medication3(""), medication4(""), medication5(""),
                medicationPrice1(0.0), medicationPrice2(0.0), medicationPrice3(0.0),
                medicationPrice4(0.0), medicationPrice5(0.0), numOfItemsBought(0) {}
    Pharmacy(string m1, string m2, string m3, string m4, string m5,
             double p1, double p2, double p3, double p4, double p5) : medication1(m1), medication2(m2), medication3(m3), medication4(m4),
                                                                      medication5(m5), medicationPrice1(p1), medicationPrice2(p2),
                                                                      medicationPrice3(p3), medicationPrice4(p4), medicationPrice5(p5) {}
    ~Pharmacy() {}
    // setting medications names
    void setMedication1(string m) { medication1 = m; }
    void setMedication2(string m) { medication2 = m; }
    void setMedication3(string m) { medication3 = m; }
    void setMedication4(string m) { medication4 = m; }
    void setMedication5(string m) { medication5 = m; }
    // setting medication prices
    void setMedicationPrice1(double p) { medicationPrice1 = p; }
    void setMedicationPrice2(double p) { medicationPrice2 = p; }
    void setMedicationPrice3(double p) { medicationPrice3 = p; }
    void setMedicationPrice4(double p) { medicationPrice4 = p; }
    void setMedicationPrice5(double p) { medicationPrice5 = p; }
    // setting the number of items bought by a patient
    void setNumOfItemsBought(int n) { numOfItemsBought = n; }
    // getting medication names
    string getMedication1() const { return medication1; }
    string getMedication2() const { return medication2; }
    string getMedication3() const { return medication3; }
    string getMedication4() const { return medication4; }
    string getMedication5() const { return medication5; }
    //getting medication prices
    double getMedicationPrice1() const { return medicationPrice1; }
    double getMedicationPrice2() const { return medicationPrice2; }
    double getMedicationPrice3() const { return medicationPrice3; }
    double getMedicationPrice4() const { return medicationPrice4; }
    double getMedicationPrice5() const { return medicationPrice5; }
    // getting number of items bought by a patient
    int getNumberOfItemsBought() const { return numOfItemsBought; }

    


};


