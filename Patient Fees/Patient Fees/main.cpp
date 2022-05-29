/// Patient Fees.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "PatientAccount.h"
#include "Surgery.h"
#include "Pharmacy.h"

int main()
{
    PatientAccount account(34.65, 14);
    Surgery surgeryType("Hand Surgery", "Hernia Surgery", "Meniscus Repair Surgery", "Dental Restoration", "Sinus Endoscopy", 345.45, 125.90, 540.32, 400.0, 264.34);
    Pharmacy medication("Alagesic LQ", "Amoxicillin", "Aspirin", "Biaxin", "Magnesium", 12.45, 10.12, 8.32, 14.45, 7.68);
    int choice;
    string typeOfSurgery = "";
    double priceOfSurgery = 0.0;
    string typeOfMedicine = "";
    double priceOfMedicine = 0.0;
    int numberOfItems = 0;
    double total = 0.0;

    cout << R"(Enter the type of surgery:

1 - Hand Surgery
2 - Hernia Surgery
3 - Meniscus Repair Surgery
4 - Dental Restoration
5 - Sinus Endoscopy
)";
    cin >> choice;
    switch (choice)
    {
    case 1:
        typeOfSurgery = surgeryType.getSurgery1();
        priceOfSurgery = surgeryType.getSurgeryCharges1();
        total = surgeryType.getSurgeryCharges1();
        break;
    case 2:
        typeOfSurgery = surgeryType.getSurgery2();
        priceOfSurgery = surgeryType.getSurgeryCharges2();
        total = account.getTotalCharges() + surgeryType.getSurgeryCharges2();
        break;
    case 3:
        typeOfSurgery = surgeryType.getSurgery3();
        priceOfSurgery = surgeryType.getSurgeryCharges3();
        total = account.getTotalCharges() + surgeryType.getSurgeryCharges3();
        break;
    case 4:
        typeOfSurgery = surgeryType.getSurgery4();
        priceOfSurgery = surgeryType.getSurgeryCharges4();
        total = account.getTotalCharges() + surgeryType.getSurgeryCharges4();
        break;
    case 5:
        typeOfSurgery = surgeryType.getSurgery5();
        priceOfSurgery = surgeryType.getSurgeryCharges5();
        total = account.getTotalCharges() + surgeryType.getSurgeryCharges5();
        break;
    default:
        cout << "Wrong number! Try again: " << endl;
        cin >> choice;
        break;
    }

    cout << R"(Enter the type of medication:

1 - Alagesic LQ
2 - Amoxicillin
3 - Aspirin
4 - Biaxin
5 - Magnesium
)";
    cin >> choice;
    cout << "How many items? ";
    cin >> numberOfItems;
    medication.setNumOfItemsBought(numberOfItems);
    switch (choice)
    {
    case 1:
        typeOfMedicine = medication.getMedication1();
        priceOfMedicine = medication.getMedicationPrice1() * numberOfItems;
        total += priceOfMedicine;
        break;
    case 2:
        typeOfMedicine = medication.getMedication2();
        priceOfMedicine = medication.getMedicationPrice2() * numberOfItems;
        total += priceOfMedicine;
        break;
    case 3:
        typeOfMedicine = medication.getMedication3();
        priceOfMedicine = medication.getMedicationPrice3() * numberOfItems;
        total += priceOfMedicine;
        break;
    case 4:
        typeOfMedicine = medication.getMedication4();
        priceOfMedicine = medication.getMedicationPrice4() * numberOfItems;
        total += priceOfMedicine;
        break;
    case 5:
        typeOfMedicine = medication.getMedication5();
        priceOfMedicine = medication.getMedicationPrice5() * numberOfItems;
        total += priceOfMedicine;
        break;
    default:
        break;
    }
    cout << "\n\n------------------------------------\n";
    cout << "Surgery type: " << typeOfSurgery << endl;
    cout << "Surgery charges: $" << priceOfSurgery << endl;
    cout << "Medicine type: " << typeOfMedicine << endl;
    cout << "Items: " << medication.getNumberOfItemsBought() << endl;
    cout << "Medication charges: $" << priceOfMedicine << endl;
    cout << "Total charges for " << account.getNumOfDays() << " days: $" << total + account.getTotalCharges() << endl;

    return 0;
}


