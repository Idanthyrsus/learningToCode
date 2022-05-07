//
//  main.cpp
//  VideoSalon
//
//  Created by Alexander Korchak on 12.04.2022.
//

#include "Description.h"

using namespace std;

int main(int argc, const char * argv[])
{
    int numMovies;
    Description movie{};
    Description *movieList = nullptr;
    cout << "How many movies are there: ";
    cin >> numMovies;
    
    movieList = new Description[numMovies];
    
    for (int i = 0; i < numMovies; i++)
    {
        getItem(movie);
        showItem(movie);
        outToFile("Movie List", movie);

    }
    
//
//    for (int i = 0; i < numMovies; i++)
//    {
//        cin.ignore();
//        cout << "Enter movie name: ";
//        getline(cin, movieList[i].name);
//        cout << "Genre: ";
//        getline(cin, movieList[i].genre);
//        cout << "Year of release: ";
//        cin >> movieList[i].year;
//        cout << "Movie price: ";
//        cin >> movieList[i].price;
//        cout << endl;
//
////        cout << "\t---" << movieList[i].name << "---" << endl;
////        cout << "Genre: \t\t\t" << movieList[i].genre << endl;
////        cout << "Year of release:" << movieList[i].year << endl;
////        cout << "Price: \t\t\t" << movieList[i].price << endl;
////        cout << endl;
//    }
    
//    cout << "Enter the name of the movie you are searching for: ";
//    cin.ignore();
//    getline(cin, movie.name);
//
//    for (int i = 0; i < numMovies; i++)
//    {
//        if (movieList[i].name == movie.name)
//        {
//            cout << "Here are the details of your movie: " << endl;
//            cout << "\t---" << movieList[i].name << "---" << endl;
//            cout << "Genre: \t\t\t" << movieList[i].genre << endl;
//            cout << "Year of release:" << movieList[i].year << endl;
//            cout << "Price: \t\t\t" << movieList[i].price << endl;
//            cout << endl;
//
//        }
//    }
    
   
    
    if (!movieList)
    {
        cout << "Memory allocation error!";
        exit(0);
    }
    delete [] movieList;
    movieList = nullptr;
    
   
    return 0;
}
