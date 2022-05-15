//
//  main.cpp
//  Tossing Coins For A Dollar
//
//  Created by Alexander Korchak on 15.05.2022.
//

#include <iostream>
#include <cstdlib>

using namespace std;

class Coin
{
    string sideUp;
public:
    Coin()
    {
        if (rand() % 2 == 1)
            sideUp = "heads";
        else
            sideUp = "tails";
    }
    
    void toss()
    {
        if (rand() % 2 + 0 == 1)
            sideUp = "heads";
        else
            sideUp = "tails";
    }
    
    string getSideUp()
    {return sideUp;}
};

void checkBalance(int &balance)
{
    if (balance == 100)
    {
        cout << "You won!" << endl;
        exit(0);
    }
    else if (balance > 100)
    {
        cout << "You lost!" << endl;
        exit(0);
    }
}

int main(int argc, const char * argv[])
{
    srand(time(0));
    
    int balance = 0;
    Coin quarter, dime, nickel;
  
    while (true)
    {
        quarter.toss();
        if (quarter.getSideUp() == "heads")
            balance += 25;
        else
            balance = balance;
        
        cout << "Balance is " << balance << endl;
        
        checkBalance(balance);
        
        dime.toss();
        if (dime.getSideUp() == "heads")
            balance += 10;
        else
            balance = balance;
        
        cout << "Balance is " << balance << endl;
        
        checkBalance(balance);
        
        
        nickel.toss();
        if (nickel.getSideUp()== "heads")
            balance += 5;
        else
            balance = balance;
        
        cout << "Balance is " << balance << endl;
        
        checkBalance(balance);
        
    }

    return 0;
}
