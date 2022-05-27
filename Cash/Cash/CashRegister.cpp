#include "CashRegister.h"


void CashRegister::itemAndQuantity(InventoryItem& i)
{
	string item;
	int quantity;
	double cost;

	cout << "Enter the item: ";
	cin >> item;
	i.setDescription(item);
	cout << "Enter the quantity: ";
	cin >> quantity;
	i.setUnits(quantity);
	cout << "Enter unit cost: ";
	cin >> cost;
	i.setCost(cost);
}

double CashRegister::getItemCost(InventoryItem &i)
{
	return i.getCost();
}

double CashRegister::getUnitPrice(InventoryItem& i)
{
	double percent = (i.getCost() / 100) * 30;
	double unitPrice = i.getCost() + percent;
	
	return unitPrice;
}

double CashRegister::getPurchaseSubtotal(CashRegister& cash, InventoryItem& i)
{
	return cash.getUnitPrice(i) * i.getUnits();
}

double CashRegister::getPurchaseTotal(CashRegister& cash, InventoryItem& i)
{
	double percent = (cash.getPurchaseSubtotal(cash, i) / 100) * 6;
	return cash.getPurchaseSubtotal(cash, i) - percent;
}

void CashRegister::display(CashRegister& cash, InventoryItem& i)
{
	cout << "Purchase subtotal: $" << cash.getPurchaseSubtotal(cash, i) << endl;
	cout << "Tax is: $"<< (cash.getPurchaseSubtotal(cash, i) / 100) * 6 << endl;
	cout << "Total is: $" << cash.getPurchaseTotal(cash, i) << endl;
}




