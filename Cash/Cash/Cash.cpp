// Cash.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "InventoryItem.h"
#include "CashRegister.h"
#include <iomanip>

int main()
{
    CashRegister cash;
    InventoryItem item;
    int inStock = 50;

    cout << fixed << showpoint << setprecision(2);
    cash.itemAndQuantity(item);
    cout << "There are " << inStock << " items on hand" << endl;
    item.setOnHand(inStock);
    cout << "\n\nItem: " << item.getDescription() << endl;
    cout << "The item cost is: $" << cash.getItemCost(item);
    cout << "\nUnit price is: $" << cash.getUnitPrice(item) << endl;
    cash.display(cash, item);
    cout << "Quantity left: " << item.quantityLeft(item);
    cout << endl;

    return 0;


}

