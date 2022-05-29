#pragma once
#include <iostream>
using namespace std;

class PatientAccount
{
    double dailyRate;
    int numOfDays;
public:
    PatientAccount() : dailyRate(0.0), numOfDays(0) {}
    PatientAccount(double d, int n): dailyRate(d), numOfDays(n) {}
    ~PatientAccount() {}

    void setDailyRate(double d) { dailyRate = d; }

    void setNumOfDays(int n) { numOfDays = n; }

    double getTotalCharges() { return dailyRate * numOfDays; }

    double getDailyRate() const { return dailyRate; }

    int getNumOfDays() const { return numOfDays; }


};


