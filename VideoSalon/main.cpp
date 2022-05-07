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
    if (!movieList)
    {
        cout << "Memory allocation error!";
        exit(0);
    }
    delete [] movieList;
    movieList = nullptr;
    return 0;
}
