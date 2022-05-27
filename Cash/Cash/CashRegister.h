#pragma once
#include "InventoryItem.h"
#include <iostream>
#include <string>


using namespace std;
class CashRegister : public InventoryItem
{  
	double subtotal;
	double total;
	int itemsLeft;
public:
	CashRegister(): subtotal(0.0), total(0.0), itemsLeft(0){}
	~CashRegister() {};

	void setSubtotal(double s)
	{
		subtotal = s;
	}
	
	void setTotal(double t)
	{
		total = t;
	}

	void setItemsLeft(int i)
	{
		itemsLeft = i;
	}

	void itemAndQuantity(InventoryItem& i);
	double getItemCost(InventoryItem&);
	double getUnitPrice(InventoryItem&);
	double getPurchaseSubtotal(CashRegister&, InventoryItem&);
	double getPurchaseTotal(CashRegister&, InventoryItem& i);
	void display(CashRegister& cash, InventoryItem& i);
};

