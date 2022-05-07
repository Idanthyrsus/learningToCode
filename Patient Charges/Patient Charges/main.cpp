//
//  main.cpp
//  Patient Charges
//
//  Created by Alexander Korchak on 30.04.2022.
//

#include "Header.h"
#include "Procedure.h"
#include <iomanip>
using namespace std;



int main(int argc, const char * argv[])
{
    Patient patient("Bobby", "Ray", "McGee", "Sunset Strip", "Los Angeles", "California", 120000, 13456789, "Lily", 13456777);
    Procedure procedure1("Physical Exam", 12, 5, 2022, "Dr. Irvine", 250.00);
    Procedure procedure2("X-Ray", 12, 5, 2022, "Dr. Jamison", 500.00);
    Procedure procedure3("Blood test", 12, 5, 2022, "Dr. Smith", 200.00);
    double total = procedure1.getCharges() + procedure2.getCharges() + procedure3.getCharges();
    
    cout << "Patient information:" << endl;
    cout << "---------------------\n";
    cout << "Name: " << patient.getFirstName() << endl;
    cout << "Middle name: " << patient.getMiddleName() << endl;
    cout << "Last name: " << patient.getLastName() << endl;
    cout << "Address: " << patient.getAddress() << endl;
    cout << "City: " << patient.getCity() << endl;
    cout << "State: " << patient.getState() << endl;
    cout << "ZIP: " << patient.getZip() << endl;
    cout << "Phone: " << patient.getPhone() << endl;
    cout << "Emergency contact:" << endl;
    cout << "------------------" << endl;
    cout << "Name: " << patient.getEmergencyName() << endl;
    cout << "Phone: " << patient.getEmergencyPhone() << endl;
    
    cout << "\n---------------------------------------------------------------------------------------------\n";
    cout << "Procedure #1:\t\t\t\t\t\tProcedure #2:\t\t\t\t\tProcedure #3:\n";
    cout << "---------------------------------------------------------------------------------------------\n";
    cout << "Procedure name: " << procedure1.getName() << "\t\tProcedure name: " << procedure2.getName() << "\t\t\tProcedure name: " << procedure3.getName() << endl;
    cout << "Date: " << procedure1.getDay() << "." << procedure1.getMonth() << "." << procedure1.getYear()
            << "\t\t\t\t\t\tDate: " << procedure2.getDay() << "." << procedure2.getMonth() << "." << procedure2.getYear()
            << "\t\t\t\t\tDate: " << procedure3.getDay() << "." << procedure3.getMonth() << "." << procedure3.getYear() << endl;
 
    cout << "Practitioner: " << procedure1.getPractitioner() << "\t\t\t" << "Practitioner: " << procedure2.getPractitioner() << "\t\t"
         << "Practitioner: " << procedure3.getPractitioner() << endl;
    
    cout << fixed << showpoint << setprecision(2);
    cout << "Charge: " << procedure1.getCharges() << "\t\t\t\t\t\t" << "Charge: " << procedure2.getCharges() << "\t\t\t\t\t" << "Charge: " << procedure3.getCharges() << endl;

    cout << "\n----------------------------------------------------------------------------------------------\n";
    cout << "Total charges:\n";
    cout << "------------------\n";
    cout << "$" << total << endl;
    
    return 0;
}
