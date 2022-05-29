#pragma once
#include <iostream>
#include <string>
using namespace std;

class Surgery
{
 string surgery1,
        surgery2,
        surgery3,
        surgery4,
        surgery5;
 double surgeryCharges1,
        surgeryCharges2,
        surgeryCharges3,
        surgeryCharges4,
        surgeryCharges5;
public:
    Surgery(): surgery1(""), surgery2(""), surgery3(""), surgery4(""), surgery5(""),
               surgeryCharges1(0.0), surgeryCharges2(0.0), surgeryCharges3(0.0),
               surgeryCharges4(0.0), surgeryCharges5(0.0) {}

    Surgery(string s1, string s2, string s3, string s4, string s5,
            double c1, double c2, double c3, double c4, double c5): surgery1(s1), surgery2(s2), surgery3(s3),
                                                                    surgery4(s4), surgery5(s5), surgeryCharges1(c1),
                                                                    surgeryCharges2(c2), surgeryCharges3(c3),
                                                                    surgeryCharges4(c4), surgeryCharges5(c5) {}
    ~Surgery() {}

    // setting surgery types
    void setSurgery1(string s) { surgery1 = s; }
    void setSurgery2(string s) { surgery2 = s; }
    void setSurgery3(string s) { surgery3 = s; }
    void setSurgery4(string s) { surgery4 = s; }
    void setSurgery5(string s) { surgery5 = s; }
    // setting surgery charges
    void setSurgeryCharges1(double c) { surgeryCharges1 = c; }
    void setSurgeryCharges2(double c) { surgeryCharges2 = c; }
    void setSurgeryCharges3(double c) { surgeryCharges3 = c; }
    void setSurgeryCharges4(double c) { surgeryCharges4 = c; }
    void setSurgeryCharges5(double c) { surgeryCharges5 = c; }
    
    // getting surgery types
    string getSurgery1() const { return surgery1; }
    string getSurgery2() const { return surgery2; }
    string getSurgery3() const { return surgery3; }
    string getSurgery4() const { return surgery4; }
    string getSurgery5() const { return surgery5; }
    // getting surgery charges
    double getSurgeryCharges1() const { return surgeryCharges1; }
    double getSurgeryCharges2() const { return surgeryCharges2; }
    double getSurgeryCharges3() const { return surgeryCharges3; }
    double getSurgeryCharges4() const { return surgeryCharges4; }
    double getSurgeryCharges5() const { return surgeryCharges5; }
};


