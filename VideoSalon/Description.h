//
//  Header.h
//  VideoSalon
//
//  Created by Alexander Korchak on 12.04.2022.
//

#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

struct Description
{
    string name;
    string genre;
    int year;
    double price;
};



void getItem(Description &movie)
{
    cin.ignore();
    cout << "Enter movie name: ";
    getline(cin, movie.name);
    cout << "Genre: ";
    getline(cin, movie.genre);
    cout << "Year of release: ";
    cin >> movie.year;
    cout << "Movie price: ";
    cin >> movie.price;
}

void showItem(Description movie)
{
    cout << "\t---" << movie.name << "---" << endl;
    cout << "Genre: \t\t\t" << movie.genre << endl;
    cout << "Year of release:" << movie.year << endl;
    cout << "Price: \t\t\t" << movie.price << endl;
    cout << endl;
}

void outToFile(string name, Description m)
{
    name += ".txt";
    
    string division(100, '-');
    
    if (!ifstream(name))
    {
        ofstream out(name);
        if (out.is_open())
        {
            out << "\t\t\t\t\t\tMovie list: " << endl;
            out << " " << division << endl;
            out << "|\t\tName\t\t|\tGenre\t|\tRelease year\t|\tPrice\t\t|" << endl;
            out << " " << division << endl;
            out.close();
        }
        else
        {
            cout << "Couldn't open file!" << endl;
            return;
        }
    }
    
    ofstream outF(name, ios::app);
    
    if (outF.is_open())
    {
        outF <<"|\t\t"<<m.name<<"\t\t|\t"<<m.genre<<"\t|"<< "\t" << m.year<<"\t\t|"<< "\t" << m.price << "\t\t|"<<endl;
                outF << " " << division << endl;
                outF.close(); //закрытие потока и файла
    }
        else
            cout << "Couldn't open file!" << endl;
    
}
