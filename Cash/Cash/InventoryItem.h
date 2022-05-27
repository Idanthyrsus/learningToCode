//
//  InventoryItem.h
//  InvetoryItem
//
//  Created by Alexander Korchak on 23.04.2022.
//

#ifndef InventoryItem_h
#define InventoryItem_h

#include <string>
using namespace std;

class InventoryItem
{
private:
    string description;
    double cost;
    int units;
    int onHand;
public:
    InventoryItem()
    {
        description = "";
        cost = 0.0;
        units = 0;
        onHand = 0;
    }

    InventoryItem(string desc)
    {
        description = desc;
        cost = 0.0;
        units = 0;
        onHand = 0;
    }

    InventoryItem(string desc, double c, int u, int o)
    {
        description = desc;
        cost = c;
        units = u;
        onHand = o;
    }

    void setDescription(string d)
    {
        description = d;
    }

    void setCost(double c)
    {
        cost = c;
    }

    void setUnits(int u)
    {
        units = u;
    }

    void setOnHand(int o)
    {
        onHand = o;
    }
    string getDescription() const
    {
        return description;
    }

    double getCost() const
    {
        return cost;
    }

    int getUnits() const
    {
        return units;
    }

    int getOnHand() const
    {
        return onHand;
    }

    int quantityLeft(InventoryItem& i)
    {
        return i.getOnHand() - i.getUnits();
    }
};

#endif /* InventoryItem_h */


