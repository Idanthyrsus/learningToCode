

//
//  main.cpp
//  ShipBattle
//
//  Created by Alexander Korchak on 10.04.2022.
//


//Создаём два двухмерных массива
//Выводим поле и радар (наполняем символами)
//Выводим пользовательское меню
//Создаём 4 типа кораблей
//Располагаем свои корабли (компьютер сам располагает свои корабли)
//Выводим поле

//Начало игры

//Ход игрока

//Запрашиваем координату
//Игрок вводит координату
//Отмечаем координату на радаре
// Если не попал - "." (то есть координата поля ПК не содержит корабль)
//Ход переходит к противнику
//Если попал - "Х" (координата поля ПК содержит корабль)
//Общее количество кораблей --
//Даётся ещё один ход

//Ход компьютера



//Игра продолжается до тех пор, пока не потоплены корабли одного из противников
//Объявление победителя и предложение сыграть снова


#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <unistd.h>


using namespace std;

const int SIZE = 10;

string battleField[SIZE][SIZE] = {"◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                                  "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                                  "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                                  "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                                  "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                                  "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                                  "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                                  "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                                  "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                                  "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇"
};

string battleField1[SIZE][SIZE] = {"◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                                   "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                                   "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                                   "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                                   "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                                   "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                                   "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                                   "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                                   "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                                   "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇"
};

string radar[SIZE][SIZE] {"◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                          "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                          "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                          "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                          "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                          "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                          "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                          "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                          "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇",
                          "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇", "◇"};

void displayBattlefield();
void displayBattlefield1();
void displayRadar();
void placeShips();
void computerShips();
void inputValidation(char&, int&);
void inputValidation1(int&, int&);

int main(int argc, const char * argv[])
{
    srand(static_cast<unsigned int>(time(nullptr)));

    int totalPcShips = 20;
    int totalPlayerShips = 20;
    bool hit = false;
    char a = ' ';
    int a1 = 0;
    int b = 0;

    placeShips();
    cout << "Компьютер располагает корабли..." << endl;
    sleep(5);
    computerShips();
    cout << endl;
    
    system("cls");
    cout << "---Начинается Морской Бой. Пусть победит сильнейший!---" << endl;
    sleep(5);

    do {

        do {
            
            system("cls");
            if (totalPlayerShips == 0)
            {
                break;
            }
            displayRadar();
            cout << "Ход игрока. Назовите координаты: " << endl;
            cout << "Буква: ";
            cin >> a;

            while (toupper(a) != 'A' && toupper(a) != 'B' && toupper(a) != 'C' && toupper(a) != 'D'
                   && toupper(a) != 'E' && toupper(a) != 'F' && toupper(a) != 'G' && toupper(a) != 'H'
                   && toupper(a) != 'I' && toupper(a) != 'J')
            {
                cout << "Ошибка ввода! Попробуйте ещё раз!" << endl;
                cin >> a;
            }

            switch (a)
            {
                case 'A':
                case 'a':
                    a1 = 0;
                    break;
                case 'B':
                case 'b':
                    a1 = 1;
                    break;
                case 'C':
                case 'c':
                    a1 = 2;
                    break;
                case 'D':
                case 'd':
                    a1 = 3;
                    break;
                case 'E':
                case 'e':
                    a1 = 4;
                    break;
                case 'F':
                case 'f':
                    a1 = 5;
                    break;
                case 'G':
                case 'g':
                    a1 = 6;
                    break;
                case 'H':
                case 'h':
                    a1 = 7;
                    break;
                case 'I':
                case 'i':
                    a1 = 8;
                    break;
                case 'J':
                case 'j':
                    a1 = 9;
                    break;
            }

            cout << "Цифра: ";
            cin >> b;

            while (b <= 0 || b > 10)
            {
                cout << "Ошибка ввода! Попробуйте ещё раз!" << endl;
                cin >> b;
            }

            if (battleField1[a1][b-1] == "▥")
            {

                sleep(2);
                cout << "Попал!" << endl;
                radar[a1][b-1] = "X";
                displayRadar();
                totalPcShips--;
                if (totalPcShips == 0)
                {
                    displayBattlefield1();
                    hit = false;
                    break;

                }

                hit = true;
            }
            else
            {
                sleep(2);
                cout << "Мимо!" << endl;
                radar[a1][b-1] = ".";
                cout << endl;
                displayRadar();
                hit = false;
            }

        } while (hit == true);

        if (totalPcShips == 0)
            break;

        do {
            if (totalPcShips == 0)
            {
                hit = false;
                break;
            }
            
            cout << "Ход компьютера." << endl;
            
            for (int i = 0; i <= 3; i++)
            {
                cout << ".";
                sleep(1);
            }
            cout << endl;
            
            
            a1 = rand() % 9;

            b = rand() % 9;

            if (battleField[a1][b] == "▥")
            {
                cout << "Компьютер попал!" << endl;
                battleField[a1][b] = "X";
                cout << endl;
                displayBattlefield();
                totalPlayerShips--;
                if (totalPcShips == 0)
                {
                    hit = false;
                    break;

                }
                hit = true;
            }
            else
            {
                cout << "Компьютер промахнулся!" << endl;
                hit = false;
                sleep(2);
            }

        } while (hit == true);

        if (totalPlayerShips == 0)
            break;

    } while (totalPcShips != 0 || totalPlayerShips != 0);

    if (totalPcShips == 0)
    {
        cout << "Вы победили! Поздравляем!" << endl;
    }
    else if (totalPlayerShips == 0)
    {
        cout << "Вы проиграли это сражение..." << endl;
    }

    return 0;
}

//***************************************
//функция вывода игрового поля на экран *
//***************************************

void displayBattlefield()
{
    cout << "     1   2   3   4   5   6   7   8   9   10\n";
    cout <<"   -----------------------------------------" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        if (i == 0)
            cout << "A ";
        if (i == 1)
            cout << "B ";
        if (i == 2)
            cout << "C ";
        if (i == 3)
            cout << "D ";
        if (i == 4)
            cout << "E ";
        if (i == 5)
            cout << "F ";
        if (i == 6)
            cout << "G ";
        if (i == 7)
            cout << "H ";
        if (i == 8)
            cout << "I ";
        if (i == 9)
            cout << "J ";
        cout << "| ";
        for (int j = 0; j < SIZE; j++)
        {
            cout << " " << battleField[i][j] << "  ";
            if (j == 9)
            {
                cout << "|";
            }
        }

        cout << endl;
        cout << endl;
    }
    cout << "   -----------------------------------------" << endl;

}

void displayBattlefield1()
{
    cout << "     1   2   3   4   5   6   7   8   9   10\n";
    cout <<"   -----------------------------------------" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        if (i == 0)
            cout << "A ";
        if (i == 1)
            cout << "B ";
        if (i == 2)
            cout << "C ";
        if (i == 3)
            cout << "D ";
        if (i == 4)
            cout << "E ";
        if (i == 5)
            cout << "F ";
        if (i == 6)
            cout << "G ";
        if (i == 7)
            cout << "H ";
        if (i == 8)
            cout << "I ";
        if (i == 9)
            cout << "J ";
        cout << "| ";
        for (int j = 0; j < SIZE; j++)
        {
            cout << " " << battleField1[i][j] << "  ";
            if (j == 9)
            {
                cout << "|";
            }
        }

        cout << endl;
        cout << endl;
    }
    cout << "   -----------------------------------------" << endl;

}

void displayRadar()
{
    cout << "     1   2   3   4   5   6   7   8   9   10\n";
    cout <<"   -----------------------------------------" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        if (i == 0)
            cout << "A ";
        if (i == 1)
            cout << "B ";
        if (i == 2)
            cout << "C ";
        if (i == 3)
            cout << "D ";
        if (i == 4)
            cout << "E ";
        if (i == 5)
            cout << "F ";
        if (i == 6)
            cout << "G ";
        if (i == 7)
            cout << "H ";
        if (i == 8)
            cout << "I ";
        if (i == 9)
            cout << "J ";
        cout << "| ";
        for (int j = 0; j < SIZE; j++)
        {
            cout << " " << radar[i][j] << "  ";
            if (j == 9)
            {
                cout << "|";
            }
        }

        cout << endl;
        cout << endl;
    }
    cout << "   -----------------------------------------" << endl;

}


void placeShips()
{
    char x = ' ';
    int y = 0;
    int choice = 0;
    int x1 = 0;

    int patrol = 4;
    int cruiser = 3;
    int submarine = 2;
    int carrier = 1;


    do {

        cout << "Расположите корабли:" << endl;
        displayBattlefield();
        cout << "Патрульный катер (1 палуба, 4 единицы)." << endl;
        do {
            cout << "Назовите координаты: " << endl;

            cout << "\nБуква: ";
            cin >> x;
            while (toupper(x) != 'A' && toupper(x) != 'B' && toupper(x) != 'C' && toupper(x) != 'D'
                   && toupper(x) != 'E' && toupper(x) != 'F' && toupper(x) != 'G' && toupper(x) != 'H'
                   && toupper(x) != 'I' && toupper(x) != 'J')
            {
                cout << "Ошибка ввода! Попробуйте ещё раз!" << endl;
                cin >> x;
            }

            // Координата Х. Меняем буквы на цифры

            switch (x)
            {
                case 'A':
                case 'a':
                    x1 = 0;
                    break;
                case 'B':
                case 'b':
                    x1 = 1;
                    break;
                case 'C':
                case 'c':
                    x1 = 2;
                    break;
                case 'D':
                case 'd':
                    x1 = 3;
                    break;
                case 'E':
                case 'e':
                    x1 = 4;
                    break;
                case 'F':
                case 'f':
                    x1 = 5;
                    break;
                case 'G':
                case 'g':
                    x1 = 6;
                    break;
                case 'H':
                case 'h':
                    x1 = 7;
                    break;
                case 'I':
                case 'i':
                    x1 = 8;
                    break;
                case 'J':
                case 'j':
                    x1 = 9;
                    break;

            }

            //Вводим координату Y

            cout << "Цифра: ";
            cin >> y;
            while (y <= 0 || y > 10)
            {
                cout << "Ошибка ввода! Попробуйте ещё раз!" << endl;
                cin >> y;
            }
            if (battleField[x1][y-1] == "▥")
            {
                cout << "Эта клетка уже занята! Попробуйте ещё раз: ";
                inputValidation(x, y);
            }
            else if (battleField[x1][y-1] == ".")
            {
                cout << "Командование доложило, что располагать корабли так близко угрожает их безопасности. Попробуйте ещё раз: ";
                inputValidation(x, y);
            }

            battleField[x1][y-1] = "▥";

            if (x1 == 0 && y == 1)
            {
                battleField[x1][y] = ".";
                battleField[x1+1][y-1] = ".";
                battleField[x1+1][y] = ".";
            }

            if (x1 == 0 && y == 10)
            {
                battleField[x1][y-2] = ".";
                battleField[x1+1][y-1] = ".";
                battleField[x1+1][y-2] = ".";
            }
            if (x1 == 0 && y > 1 && y < 10)
            {
                battleField[x1][y] = ".";
                battleField[x1][y-2] = ".";
                battleField[x1+1][y] = ".";
                battleField[x1+1][y-1] = ".";
                battleField[x1+1][y-2] = ".";
            }
            if (x1 == 9 && y > 1 && y < 10)
            {
                battleField[x1][y] = ".";
                battleField[x1][y-2] = ".";
                battleField[x1-1][y] = ".";
                battleField[x1-1][y-1] = ".";
                battleField[x1-1][y-2] = ".";
            }

            if (x1 == 9 && y == 1)
            {
                battleField[x1-1][y-1] = ".";
                battleField[x1-1][y] = ".";
                battleField[x1][y] = ".";
            }
            if (x1 == 9 && y == 10)
            {
                battleField[x1-1][y-1] = ".";
                battleField[x1-1][y-2] = ".";
                battleField[x1][y-2] = ".";
            }
            if (y == 1 && x1 > 0 && x1 < 9)
            {
                battleField[x1][y] = ".";
                battleField[x1-1][y] = ".";
                battleField[x1-1][y-1] = ".";
                battleField[x1+1][y] = ".";
                battleField[x1+1][y-1] = ".";
            }
            if (y == 10 && x1 > 0 && x1 < 9)
            {
                battleField[x1][y-2] = ".";
                battleField[x1-1][y-2] = ".";
                battleField[x1-1][y-1] = ".";
                battleField[x1+1][y-2] = ".";
                battleField[x1+1][y-1] = ".";
            }

            if (x1 != 0 && x1 != 9 && y != 1 && y != 10)
            {
                battleField[x1][y-2] = ".";
                battleField[x1][y] = ".";
                battleField[x1+1][y] = ".";
                battleField[x1+1][y-1] = ".";
                battleField[x1+1][y-2] = ".";
                battleField[x1-1][y] = ".";
                battleField[x1-1][y-1] = ".";
                battleField[x1-1][y-2] = ".";
            }
            displayBattlefield();
            patrol--;


        } while (patrol != 0);

        cout << "Крейсер (2 палубы, 3 единицы)." << endl;
        do {

            cout << "Назовите начальную координату: " << endl;

            cout << "\nБуква: ";
            cin >> x;
            while (toupper(x) != 'A' && toupper(x) != 'B' && toupper(x) != 'C' && toupper(x) != 'D'
                   && toupper(x) != 'E' && toupper(x) != 'F' && toupper(x) != 'G' && toupper(x) != 'H'
                   && toupper(x) != 'I' && toupper(x) != 'J')
            {
                cout << "Ошибка ввода! Попробуйте ещё раз!" << endl;
                cin >> x;
            }


            switch (x)
            {
                case 'A':
                case 'a':
                    x1 = 0;
                    break;
                case 'B':
                case 'b':
                    x1 = 1;
                    break;
                case 'C':
                case 'c':
                    x1 = 2;
                    break;
                case 'D':
                case 'd':
                    x1 = 3;
                    break;
                case 'E':
                case 'e':
                    x1 = 4;
                    break;
                case 'F':
                case 'f':
                    x1 = 5;
                    break;
                case 'G':
                case 'g':
                    x1 = 6;
                    break;
                case 'H':
                case 'h':
                    x1 = 7;
                    break;
                case 'I':
                case 'i':
                    x1 = 8;
                    break;
                case 'J':
                case 'j':
                    x1 = 9;
                    break;

            }


            cout << "Цифра: ";
            cin >> y;
            while (y <= 0 || y > 10)
            {
                cout << "Ошибка ввода! Попробуйте ещё раз!" << endl;
                cin >> y;
            }
            while (battleField[x1][y-1] == "▥")
            {
                cout << "Эта клетка уже занята! Попробуйте ещё раз: ";
                inputValidation(x, y);
            }
            while (battleField[x1][y-1] == ".")
            {
                cout << "Держите дистанцию! Попробуйте ещё раз: ";
                inputValidation(x, y);
            }

            battleField[x1][y-1] = "▥";
            displayBattlefield();


            do {
                cout << R"(
Выберите вариант расположения корабля:
1. -> ▥ ▥   Горизонтально вправо

2.  ▥ ▥ <-  Горизонтально влево

3. ^        Вертикально вверх
   |  ▥
      ▥

4. |  ▥    Вертикально вниз
   V  ▥

)";
                cin >> choice;

            } while (choice < 1 || choice > 4);

            switch (choice)
            {
                case 1:
                    if (y == 10)
                    {
                        cout << "Так нельзя располагать корабль! Попробуйте ещё:" << endl;
                        battleField[x1][y-1] = "◇";
                        break;
                    }
                    if (battleField[x1][y] != "▥" && battleField[x1][y] != ".")
                    {
                        battleField[x1][y] = "▥";
                    }
                    else
                    {
                        cout << "Нет места для манёвра! Попробуйте другой вариант:" << endl;
                        battleField[x1][y-1] = "◇";
                        break;
                    }

                    if (x1 == 0 && y == 1)
                    {
                        battleField[x1][y+1] = ".";
                        battleField[x1+1][y+1] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y-1] = ".";
                    }

                    else if (x1 == 9 && y == 1)
                    {
                        battleField[x1][y+1] = ".";
                        battleField[x1-1][y+1] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";
                    }


                    else if (x1 > 0 && x1 < 9 && y == 1)
                    {
                        battleField[x1][y+1] = ".";
                        battleField[x1-1][y+1] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1+1][y+1] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y-1] = ".";
                    }
                    else if (x1 > 0 && x1 < 9 && y == 9)
                    {
                        battleField[x1][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y] = ".";
                    }

                    else if (x1 == 0 && y == 9)
                    {
                        battleField[x1][y-2] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y] = ".";
                    }
                    else if (x1 == 9 && y == 9)
                    {
                        battleField[x1][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y] = ".";
                    }


                    else if (x1 == 0 && y > 1 && y < 9)
                    {
                        battleField[x1][y+1] = ".";
                        battleField[x1+1][y+1] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1+1][y-2] = ".";
                    }

                    else if (x1 == 9 && y > 1 && y < 9)
                    {
                        battleField[x1][y+1] = ".";
                        battleField[x1-1][y+1] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                    }

                    else
                    {
                        battleField[x1][y+1] = ".";
                        battleField[x1-1][y+1] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1+1][y+1] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1+1][y-2] = ".";

                    }



                    displayBattlefield();
                    cruiser--;
                    break;

                case 2:
                    if (y == 1)
                    {
                        cout << "Так нельзя располагать корабль! Попробуйте ещё:" << endl;
                        battleField[x1][y-1] = "◇";
                        break;
                    }

                    if (battleField[x1][y-2] != "▥" && battleField[x1][y-2] != ".")
                    {
                        battleField[x1][y-2] = "▥";
                    }
                    else
                    {
                        cout << "Нет места для манёвра! Попробуйте другой вариант:" << endl;
                        battleField[x1][y-1] = "◇";
                        break;
                    }


                    if (y == 10 && x1 > 0 && x1 < 9)
                    {
                        battleField[x1+1][y-1] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1-1][y-3] = ".";
                        battleField[x1][y-3] = ".";
                        battleField[x1+1][y-3] = ".";
                    }
                    else if (y == 10 && x1 == 0)
                    {
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+1][y-3] = ".";
                        battleField[x1][y-3] = ".";
                    }

                    else if (y == 10 && x1 == 9)
                    {
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-1][y-3] = ".";
                        battleField[x1][y-3] = ".";
                    }

                    else if (y > 1 && y < 10 && x1 == 9)
                    {
                        battleField[x1][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-1][y-3] = ".";
                        battleField[x1][y-3] = ".";

                    }
                    else if (y == 2 && x1 == 9)
                    {
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1][y] = ".";

                    }
                    else if (y == 2 && x1 > 0 && x1 < 9)
                    {
                        battleField[x1][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y-2] = ".";
                    }
                    else if (y == 2 && x1 == 0)
                    {
                        battleField[x1][y] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y-2] = ".";
                    }
                    else if (x1 == 0 && y > 1 && y < 10)
                    {
                        battleField[x1][y] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+1][y-3] = ".";
                        battleField[x1][y-3] = ".";

                    }
                    else
                    {
                        battleField[x1][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-1][y-3] = ".";
                        battleField[x1][y-3] = ".";
                        battleField[x1+1][y-3] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y] = ".";
                    }

                    displayBattlefield();
                    cruiser--;
                    break;

                case 3:
                    if (x1 == 0)
                    {
                        cout << "Так нельзя располагать корабль! Попробуйте ещё:" << endl;
                        battleField[x1][y-1] = "◇";
                        break;
                    }

                    if (battleField[x1-1][y-1] != "▥" && battleField[x1-1][y-1] != ".")
                    {
                        battleField[x1-1][y-1] = "▥";
                    }
                    else
                    {
                        cout << "Нет места для манёвра! Попробуйте другой вариант:" << endl;
                        battleField[x1][y-1] = "◇";
                        break;
                    }

                    if (x1 == 1 && y == 1)
                    {
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1][y] = ".";

                    }
                    else if (x1 == 9 && y == 1)
                    {
                        battleField[x1-2][y-1] = ".";
                        battleField[x1-2][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1][y] = ".";
                    }
                    else if (x1 > 1 && x1 < 9 && y == 1)
                    {

                        battleField[x1-2][y-1] = ".";
                        battleField[x1-2][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1][y] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y] = ".";

                    }

                    else if (x1 == 1 && y == 10)
                    {
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1][y-2] = ".";

                    }
                    else if (x1 == 9 && y == 10)
                    {
                        battleField[x1-2][y-1] = ".";
                        battleField[x1-2][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1][y-2] = ".";
                    }
                    else if (x1 > 1 && x1 < 9 && y == 10)
                    {

                        battleField[x1-2][y-1] = ".";
                        battleField[x1-2][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y-2] = ".";
                    }

                    else if (y > 1 && y < 10 && x1 == 9)
                    {
                        battleField[x1-2][y] = ".";
                        battleField[x1-2][y-1] = ".";
                        battleField[x1-2][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1][y] = ".";
                        battleField[x1][y-2] = ".";
                    }
                    else if (y > 1 && y < 10 && x1 == 1)
                    {
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1][y] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-2] = ".";
                    }

                    else
                    {
                        battleField[x1-2][y] = ".";
                        battleField[x1-2][y-1] = ".";
                        battleField[x1-2][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1][y] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y] = ".";
                    }

                    displayBattlefield();
                    cruiser--;
                    break;

                case 4:
                    if (x1 == 9)
                    {
                        cout << "Так нельзя располагать корабль!\n";
                        battleField[x1][y-1] = "◇";
                        break;
                    }
                    if ((battleField[x1+1][y-1] != "▥") && (battleField[x1+1][y-1] != "."))
                    {
                        battleField[x1+1][y-1] = "▥";
                    }
                    else
                    {
                        cout << "Недостаточно места для манёвра." << endl;
                        battleField[x1][y-1] = "◇";
                        break;
                    }

                    if (y == 10 && x1 > 0 && x1 < 8)
                    {
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+2][y-2] = ".";
                        battleField[x1+2][y-1] = ".";
                    }
                    else if (y == 10 && x1 == 0)
                    {
                        battleField[x1][y-2] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+2][y-2] = ".";
                        battleField[x1+2][y-1] = ".";
                    }

                    else  if (y == 10 && x1 == 8)
                    {
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1+1][y-2] = ".";
                    }

                    else if (y > 1 && y < 10 && x1 == 8)
                    {
                        battleField[x1][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1+1][y-2] = ".";
                    }
                    else  if (y == 1 && x1 == 8)
                    {
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1][y] = ".";
                        battleField[x1+1][y] = ".";
                    }
                    else if (y == 1 && x1 > 0 && x1 < 8)
                    {
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1][y] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+2][y] = ".";
                        battleField[x1+2][y-1] = ".";
                    }
                    else if (y == 1 && x1 == 0)
                    {
                        battleField[x1][y] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+2][y] = ".";
                        battleField[x1+2][y-1] = ".";
                    }
                    else  if (x1 == 0 && y > 1 && y < 10)
                    {
                        battleField[x1][y] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+2][y] = ".";
                        battleField[x1+2][y-1] = ".";
                        battleField[x1+2][y-2] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1][y-2] = ".";

                    }

                    else
                    {
                        battleField[x1-1][y-2] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+2][y-2] = ".";
                        battleField[x1+2][y-1] = ".";
                        battleField[x1+2][y] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";
                    }
                    displayBattlefield();
                    cruiser--;
                    break;

            }




        } while(cruiser != 0);

        cout << "Жёлтая подводная лодка (3 палубы, 2 единицы)." << endl;
        do {
            cout << "Назовите начальную координату: " << endl;

            cout << "\nБуква: ";
            cin >> x;
            while (toupper(x) != 'A' && toupper(x) != 'B' && toupper(x) != 'C' && toupper(x) != 'D'
                   && toupper(x) != 'E' && toupper(x) != 'F' && toupper(x) != 'G' && toupper(x) != 'H'
                   && toupper(x) != 'I' && toupper(x) != 'J')
            {
                cout << "Ошибка ввода! Попробуйте ещё раз!" << endl;
                cin >> x;
            }

            switch (x)
            {
                case 'A':
                case 'a':
                    x1 = 0;
                    break;
                case 'B':
                case 'b':
                    x1 = 1;
                    break;
                case 'C':
                case 'c':
                    x1 = 2;
                    break;
                case 'D':
                case 'd':
                    x1 = 3;
                    break;
                case 'E':
                case 'e':
                    x1 = 4;
                    break;
                case 'F':
                case 'f':
                    x1 = 5;
                    break;
                case 'G':
                case 'g':
                    x1 = 6;
                    break;
                case 'H':
                case 'h':
                    x1 = 7;
                    break;
                case 'I':
                case 'i':
                    x1 = 8;
                    break;
                case 'J':
                case 'j':
                    x1 = 9;
                    break;

            }

            cout << "Цифра: ";
            cin >> y;
            while (y <= 0 || y > 10)
            {
                cout << "Ошибка ввода! Попробуйте ещё раз!" << endl;
                cin >> y;
            }
            while (battleField[x1][y-1] == "▥")
            {
                cout << "Эта клетка уже занята! Попробуйте ещё раз: ";
                inputValidation(x, y);
            }
            while (battleField[x1][y-1] == ".")
            {
                cout << "Держите дистанцию! Попробуйте ещё раз: ";
                inputValidation(x, y);
            }

            battleField[x1][y-1] = "▥";
            displayBattlefield();

            do {
                cout << R"(
        Выберите вариант расположения корабля:
        1. -> ▥ ▥ ▥  Горизонтально вправо

        2. ▥ ▥ ▥ <-  Горизонтально влево

        3.   ^  ▥      Вертикально вверх
             |  ▥
                ▥

        4. |  ▥    Вертикально вниз
           V  ▥
              ▥
        )";
                cin >> choice;
            } while (choice < 1 || choice > 4);

            switch (choice)
            {
                case 1:

                    if (y > 8)
                    {
                        cout << "Так нельзя располагать корабль! Попробуйте ещё:" << endl;
                        battleField[x1][y-1] = "◇";
                        break;
                    }
                    if ((battleField[x1][y] != "▥" && battleField[x1][y+1] != "▥") && (battleField[x1][y] != "." && battleField[x1][y+1] != "."))
                    {

                        battleField[x1][y] = "▥";
                        battleField[x1][y+1] = "▥";
                    }
                    else
                    {

                        cout << "Нет места для манёвра! Попробуйте другой вариант:" << endl;
                        battleField[x1][y-1] = "◇";
                        break;
                    }

                    if (x1 == 0 && y == 1)
                    {
                        battleField[x1][y+2] = ".";
                        battleField[x1+1][y+2] = ".";
                        battleField[x1+1][y+1] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y-1] = ".";
                    }
                    else if (x1 == 9 && y == 1)
                    {
                        battleField[x1][y+2] = ".";
                        battleField[x1-1][y+2] = ".";
                        battleField[x1-1][y+1] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";

                    }

                    else if (x1 > 0 && x1 < 9 && y == 1)
                    {
                        battleField[x1][y+2] = ".";
                        battleField[x1-1][y+2] = ".";
                        battleField[x1-1][y+1] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1+1][y+2] = ".";
                        battleField[x1+1][y+1] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y-1] = ".";
                    }
                    else if (x1 > 0 && x1 < 9 && y == 8)
                    {
                        battleField[x1][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y+1] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y+1] = ".";
                    }

                    else if (x1 == 0 && y == 8)
                    {
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y+1] = ".";
                        battleField[x1][y-2] = ".";

                    }
                    else if (x1 == 9 && y == 8)
                    {
                        battleField[x1][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y+1] = ".";
                    }


                    else if (x1 == 0 && y > 1 && y < 8)
                    {
                        battleField[x1][y+2] = ".";
                        battleField[x1+1][y+2] = ".";
                        battleField[x1+1][y+1] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1+1][y-2] = ".";
                    }

                    else if (x1 == 9 && y > 1 && y < 9)
                    {
                        battleField[x1][y+2] = ".";
                        battleField[x1-1][y+2] = ".";
                        battleField[x1-1][y+1] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                    }

                    else
                    {
                        battleField[x1][y+2] = ".";

                        battleField[x1-1][y+2] = ".";
                        battleField[x1-1][y+1] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";

                        battleField[x1+1][y+2] = ".";
                        battleField[x1+1][y+1] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y-1] = ".";

                        battleField[x1-1][y-2] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1+1][y-2] = ".";

                    }

                    displayBattlefield();
                    submarine--;
                    break;

                case 2:
                    if (y < 3)
                    {
                        cout << "Так нельзя располагать корабль! Попробуйте ещё:" << endl;
                        battleField[x1][y-1] = "◇";
                        break;
                    }

                    if ((battleField[x1][y-2] != "▥" && battleField[x1][y-3] != "▥") && (battleField[x1][y-2] != "." && battleField[x1][y-3] != "."))
                    {
                        battleField[x1][y-2] = "▥";
                        battleField[x1][y-3] = "▥";
                    }
                    else
                    {
                        cout << "Нет места для манёвра! Попробуйте другой вариант:" << endl;
                        battleField[x1][y-1] = "◇";
                        break;
                    }


                    if (y == 10 && x1 > 0 && x1 < 9)
                    {
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+1][y-3] = ".";
                        battleField[x1+1][y-4] = ".";
                        battleField[x1][y-4] = ".";

                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-1][y-3] = ".";
                        battleField[x1-1][y-4] = ".";


                    }
                    else if (y == 10 && x1 == 0)
                    {
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+1][y-3] = ".";
                        battleField[x1+1][y-4] = ".";
                        battleField[x1][y-4] = ".";
                    }

                    else if (y == 10 && x1 == 9)
                    {
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-1][y-3] = ".";
                        battleField[x1-1][y-4] = ".";
                        battleField[x1][y-4] = ".";
                    }

                    else if (y > 3 && y < 10 && x1 == 9)
                    {
                        battleField[x1][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-1][y-3] = ".";
                        battleField[x1-1][y-4] = ".";
                        battleField[x1][y-4] = ".";

                    }
                    else if (y == 3 && x1 == 9)
                    {
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-1][y-3] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1][y] = ".";

                    }
                    else if (y == 3 && x1 > 0 && x1 < 9)
                    {
                        battleField[x1][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-1][y-3] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+1][y-3] = ".";
                    }
                    else if (y == 3 && x1 == 0)
                    {
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+1][y-3] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1][y] = ".";
                    }
                    else if (x1 == 0 && y > 3 && y < 10)
                    {
                        battleField[x1][y] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+1][y-3] = ".";
                        battleField[x1+1][y-4] = ".";
                        battleField[x1][y-4] = ".";

                    }
                    else
                    {
                        battleField[x1][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-1][y-3] = ".";
                        battleField[x1-1][y-4] = ".";
                        battleField[x1][y-4] = ".";
                        battleField[x1+1][y-4] = ".";
                        battleField[x1+1][y-3] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y] = ".";
                    }

                    displayBattlefield();
                    submarine--;
                    break;

                case 3:
                    if (x1 < 2)
                    {
                        cout << "Так нельзя располагать корабль! Попробуйте ещё:" << endl;
                        battleField[x1][y-1] = "◇";
                        break;
                    }

                    if ((battleField[x1-1][y-1] != "▥" && battleField[x1-2][y-1] != "▥") && (battleField[x1-1][y-1] != "." && battleField[x1-2][y-1] != "."))
                    {
                        battleField[x1-1][y-1] = "▥";
                        battleField[x1-2][y-1] = "▥";

                    }
                    else
                    {
                        cout << "Нет места для манёвра! Попробуйте другой вариант:" << endl;
                        battleField[x1][y-1] = "◇";
                        break;
                    }

                    if (x1 == 2 && y == 1)
                    {
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1-2][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1][y] = ".";

                    }
                    else if (x1 == 9 && y == 1)
                    {
                        battleField[x1-3][y-1] = ".";
                        battleField[x1-3][y] = ".";
                        battleField[x1-2][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1][y] = ".";
                    }
                    else if (x1 > 2 && x1 < 9 && y == 1)
                    {

                        battleField[x1-3][y-1] = ".";
                        battleField[x1-3][y] = ".";
                        battleField[x1-2][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1][y] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y] = ".";

                    }

                    else if (x1 == 2 && y == 10)
                    {
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1-2][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1][y-2] = ".";

                    }
                    else if (x1 == 9 && y == 10)
                    {
                        battleField[x1-3][y-1] = ".";
                        battleField[x1-3][y-2] = ".";
                        battleField[x1-2][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1][y-2] = ".";
                    }
                    else if (x1 > 2 && x1 < 9 && y == 10)
                    {

                        battleField[x1-3][y-1] = ".";
                        battleField[x1-3][y-2] = ".";
                        battleField[x1-2][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y-2] = ".";
                    }

                    else if (y > 1 && y < 10 && x1 == 9)
                    {
                        battleField[x1-3][y-1] = ".";
                        battleField[x1-3][y] = ".";
                        battleField[x1-2][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1][y] = ".";
                        battleField[x1-3][y-2] = ".";
                        battleField[x1-2][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1][y-2] = ".";

                    }
                    else if (y > 1 && y < 10 && x1 == 2)
                    {
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y-2] = ".";

                        battleField[x1][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-2][y] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-2][y-2] = ".";
                    }

                    else
                    {
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y-2] = ".";

                        battleField[x1][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-2][y] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-2][y-2] = ".";

                        battleField[x1-3][y] = ".";
                        battleField[x1-3][y-1] = ".";
                        battleField[x1-3][y-2] = ".";
                    }

                    displayBattlefield();
                    submarine--;
                    break;

                case 4:
                    if (x1 > 7)
                    {
                        cout << "Так нельзя располагать корабль! Попробуйте ещё:" << endl;
                        battleField[x1][y-1] = "◇";
                        break;
                    }

                    if ((battleField[x1+1][y-1] != "▥" && battleField[x1+2][y-1] != "▥") && (battleField[x1+1][y-1] != "." && battleField[x1+2][y-1] != "."))
                    {
                        battleField[x1+1][y-1] = "▥";
                        battleField[x1+2][y-1] = "▥";
                    }
                    else
                    {
                        cout << "Нет места для манёвра! Попробуйте другой вариант:" << endl;
                        battleField[x1][y-1] = "◇";
                        break;
                    }


                    if (y == 10 && x1 > 0 && x1 < 7)
                    {

                        battleField[x1+3][y-1] = ".";
                        battleField[x1+3][y-2] = ".";
                        battleField[x1+2][y-2] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";

                    }
                    else if (y == 10 && x1 == 0)
                    {
                        battleField[x1+3][y-1] = ".";
                        battleField[x1+3][y-2] = ".";
                        battleField[x1+2][y-2] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1][y-2] = ".";
                    }

                    else  if (y == 10 && x1 == 7)
                    {
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+2][y-2] = ".";
                    }

                    else if (y > 1 && y < 10 && x1 == 7)
                    {
                        battleField[x1][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+2][y] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+2][y-2] = ".";
                    }

                    else  if (y == 1 && x1 == 7)
                    {
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1][y] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+2][y] = ".";
                    }

                    else if (y == 1 && x1 > 0 && x1 < 7)
                    {

                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1][y] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+2][y] = ".";
                        battleField[x1+3][y] = ".";
                        battleField[x1+3][y-1] = ".";
                    }
                    else if (y == 1 && x1 == 0)
                    {
                        battleField[x1+3][y-1] = ".";
                        battleField[x1+3][y] = ".";
                        battleField[x1+2][y] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1][y] = ".";
                    }


                    else  if (x1 == 0 && y > 1 && y < 10)
                    {
                        battleField[x1][y] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+2][y] = ".";
                        battleField[x1+3][y] = ".";
                        battleField[x1+3][y-1] = ".";
                        battleField[x1+3][y-2] = ".";
                        battleField[x1+2][y-2] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1][y-2] = ".";

                    }

                    else
                    {
                        battleField[x1][y] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+2][y] = ".";
                        battleField[x1+3][y] = ".";
                        battleField[x1+3][y-1] = ".";
                        battleField[x1+3][y-2] = ".";
                        battleField[x1+2][y-2] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                    }

                    displayBattlefield();
                    submarine--;
                    break;

            }


        }while (submarine != 0);

        cout << "Авианосец - гордость нашего флота! (4 палубы, 1 единица)." << endl;
        do {
            cout << "Назовите начальную координату: " << endl;

            cout << "\nБуква: ";
            cin >> x;
            while (toupper(x) != 'A' && toupper(x) != 'B' && toupper(x) != 'C' && toupper(x) != 'D'
                   && toupper(x) != 'E' && toupper(x) != 'F' && toupper(x) != 'G' && toupper(x) != 'H'
                   && toupper(x) != 'I' && toupper(x) != 'J')
            {
                cout << "Ошибка ввода! Попробуйте ещё раз!" << endl;
                cin >> x;
            }

            switch (x)
            {
                case 'A':
                case 'a':
                    x1 = 0;
                    break;
                case 'B':
                case 'b':
                    x1 = 1;
                    break;
                case 'C':
                case 'c':
                    x1 = 2;
                    break;
                case 'D':
                case 'd':
                    x1 = 3;
                    break;
                case 'E':
                case 'e':
                    x1 = 4;
                    break;
                case 'F':
                case 'f':
                    x1 = 5;
                    break;
                case 'G':
                case 'g':
                    x1 = 6;
                    break;
                case 'H':
                case 'h':
                    x1 = 7;
                    break;
                case 'I':
                case 'i':
                    x1 = 8;
                    break;
                case 'J':
                case 'j':
                    x1 = 9;
                    break;

            }

            cout << "Цифра: ";
            cin >> y;
            while (y <= 0 || y > 10)
            {
                cout << "Ошибка ввода! Попробуйте ещё раз!" << endl;
                cin >> y;
            }
            while (battleField[x1][y-1] == "▥")
            {
                cout << "Эта клетка уже занята! Попробуйте ещё раз: ";
                inputValidation(x, y);
            }
            while (battleField[x1][y-1] == ".")
            {
                cout << "Держите дистанцию! Попробуйте ещё раз: ";
                inputValidation(x, y);
            }

            battleField[x1][y-1] = "▥";
            displayBattlefield();

            do {
                cout << R"(
        Выберите вариант расположения корабля:
        1. -> ▥ ▥ ▥ ▥  Горизонтально вправо

        2. ▥ ▥ ▥ ▥ <-  Горизонтально влево

        3. ^  ▥      Вертикально вверх
           |  ▥
              ▥
              ▥

        4. |  ▥    Вертикально вниз
           V  ▥
              ▥
              ▥
        )";
                cin >> choice;
            } while (choice < 1 || choice > 4);

            switch (choice)
            {
                case 1:

                    if (y > 7)
                    {
                        cout << "Так нельзя располагать корабль! Попробуйте ещё:" << endl;
                        battleField[x1][y-1] = "◇";
                        break;
                    }


                    if ((battleField[x1][y] != "▥" && battleField[x1][y+1] != "▥" && battleField[x1][y+2] != "▥") && (battleField[x1][y] != "." && battleField[x1][y+1] != "." && battleField[x1][y+2] != "."))
                    {
                        battleField[x1][y] = "▥";
                        battleField[x1][y+1] = "▥";
                        battleField[x1][y+2] = "▥";
                    }
                    else
                    {
                        cout << "Нет места для манёвра! Попробуйте другой вариант:" << endl;
                        battleField[x1][y-1] = "◇";
                        break;
                    }

                    if (x1 == 0 && y == 1)
                    {
                        battleField[x1][y+3] = ".";
                        battleField[x1+1][y+3] = ".";
                        battleField[x1+1][y+2] = ".";
                        battleField[x1+1][y+1] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y-1] = ".";
                    }
                    else if (x1 == 9 && y == 1)
                    {
                        battleField[x1][y+3] = ".";
                        battleField[x1-1][y+3] = ".";
                        battleField[x1-1][y+2] = ".";
                        battleField[x1-1][y+1] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";

                    }

                    else if (x1 > 0 && x1 < 8 && y == 1)
                    {
                        battleField[x1][y+3] = ".";
                        battleField[x1-1][y+3] = ".";
                        battleField[x1-1][y+2] = ".";
                        battleField[x1-1][y+1] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1+1][y+3] = ".";
                        battleField[x1+1][y+2] = ".";
                        battleField[x1+1][y+1] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y-1] = ".";
                    }
                    else if (x1 > 0 && x1 < 9 && y == 7)
                    {
                        battleField[x1][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y+1] = ".";
                        battleField[x1-1][y+2] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y+1] = ".";
                        battleField[x1+1][y+2] = ".";
                    }

                    else if (x1 == 0 && y == 7)
                    {
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y+1] = ".";
                        battleField[x1+1][y+2] = ".";
                        battleField[x1][y-2] = ".";

                    }
                    else if (x1 == 9 && y == 7)
                    {
                        battleField[x1][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y+1] = ".";
                        battleField[x1-1][y+2] = ".";
                    }


                    else if (x1 == 0 && y > 1 && y < 7)
                    {
                        battleField[x1][y+3] = ".";
                        battleField[x1+1][y+3] = ".";
                        battleField[x1+1][y+2] = ".";
                        battleField[x1+1][y+1] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1+1][y-2] = ".";
                    }

                    else if (x1 == 9 && y > 1 && y < 7)
                    {
                        battleField[x1][y+3] = ".";
                        battleField[x1-1][y+3] = ".";
                        battleField[x1-1][y+2] = ".";
                        battleField[x1-1][y+1] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                    }

                    else
                    {
                        battleField[x1][y+3] = ".";
                        battleField[x1-1][y+3] = ".";
                        battleField[x1-1][y+2] = ".";
                        battleField[x1-1][y+1] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";

                        battleField[x1+1][y+3] = ".";
                        battleField[x1+1][y+2] = ".";
                        battleField[x1+1][y+1] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y-1] = ".";

                        battleField[x1-1][y-2] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1+1][y-2] = ".";

                    }

                    displayBattlefield();
                    carrier--;
                    break;

                case 2:
                    if (y < 4)
                    {
                        cout << "Так нельзя располагать корабль! Попробуйте ещё:" << endl;
                        battleField[x1][y-1] = "◇";
                        break;
                    }

                    if ((battleField[x1][y-2] != "▥" && battleField[x1][y-3] != "▥" && battleField[x1][y-4] != "▥") && (battleField[x1][y-2] != "." && battleField[x1][y-3] != "." && battleField[x1][y-4] != "."))
                    {
                        battleField[x1][y-2] = "▥";
                        battleField[x1][y-3] = "▥";
                        battleField[x1][y-4] = "▥";
                    }
                    else
                    {
                        cout << "Нет места для манёвра! Попробуйте другой вариант:" << endl;
                        battleField[x1][y-1] = "◇";
                        break;
                    }

                    if (y == 10 && x1 > 0 && x1 < 9)
                    {
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+1][y-3] = ".";
                        battleField[x1+1][y-4] = ".";
                        battleField[x1+1][y-5] = ".";
                        battleField[x1][y-5] = ".";

                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-1][y-3] = ".";
                        battleField[x1-1][y-4] = ".";
                        battleField[x1-1][y-5] = ".";


                    }
                    else if (y == 10 && x1 == 0)
                    {
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+1][y-3] = ".";
                        battleField[x1+1][y-4] = ".";
                        battleField[x1+1][y-5] = ".";
                        battleField[x1][y-5] = ".";
                    }

                    else if (y == 10 && x1 == 9)
                    {
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-1][y-3] = ".";
                        battleField[x1-1][y-4] = ".";
                        battleField[x1-1][y-5] = ".";
                        battleField[x1][y-5] = ".";
                    }

                    else if (y > 4 && y < 10 && x1 == 9)
                    {
                        battleField[x1][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-1][y-3] = ".";
                        battleField[x1-1][y-4] = ".";
                        battleField[x1-1][y-5] = ".";
                        battleField[x1][y-5] = ".";

                    }
                    else if (y == 4 && x1 == 9)
                    {
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-1][y-3] = ".";
                        battleField[x1-1][y-4] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1][y] = ".";

                    }
                    else if (y == 4 && x1 > 0 && x1 < 9)
                    {
                        battleField[x1][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-1][y-3] = ".";
                        battleField[x1-1][y-4] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+1][y-3] = ".";
                        battleField[x1+1][y-4] = ".";
                    }
                    else if (y == 4 && x1 == 0)
                    {
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+1][y-3] = ".";
                        battleField[x1+1][y-4] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1][y] = ".";
                    }
                    else if (x1 == 0 && y > 4 && y < 10)
                    {
                        battleField[x1][y] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+1][y-3] = ".";
                        battleField[x1+1][y-4] = ".";
                        battleField[x1+1][y-5] = ".";
                        battleField[x1][y-5] = ".";

                    }
                    else
                    {
                        battleField[x1][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-1][y-3] = ".";
                        battleField[x1-1][y-4] = ".";
                        battleField[x1-1][y-5] = ".";
                        battleField[x1][y-5] = ".";
                        battleField[x1+1][y-5] = ".";
                        battleField[x1+1][y-4] = ".";
                        battleField[x1+1][y-3] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y] = ".";
                    }

                    displayBattlefield();
                    carrier--;
                    break;

                case 3:
                    if (x1 < 3)
                    {
                        cout << "Так нельзя располагать корабль! Попробуйте ещё:" << endl;
                        battleField[x1][y-1] = "◇";
                        break;
                    }

                    if ((battleField[x1-1][y-1] != "▥" && battleField[x1-2][y-1] != "▥" && battleField[x1-3][y-1] != "▥") && (battleField[x1-1][y-1] != "." && battleField[x1-2][y-1] != "." && battleField[x1-3][y-1] != "."))
                    {
                        battleField[x1-1][y-1] = "▥";
                        battleField[x1-2][y-1] = "▥";
                        battleField[x1-3][y-1] = "▥";
                    }
                    else
                    {
                        cout << "Нет места для манёвра! Попробуйте другой вариант:" << endl;
                        battleField[x1][y-1] = "◇";
                        break;
                    }

                    if (x1 == 3 && y == 1)
                    {
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1-3][y] = ".";
                        battleField[x1-2][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1][y] = ".";

                    }
                    else if (x1 == 9 && y == 1)
                    {
                        battleField[x1-4][y-1] = ".";
                        battleField[x1-4][y] = ".";
                        battleField[x1-3][y] = ".";
                        battleField[x1-2][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1][y] = ".";
                    }


                    else if (x1 > 3 && x1 < 9 && y == 1)
                    {

                        battleField[x1-4][y-1] = ".";
                        battleField[x1-4][y] = ".";
                        battleField[x1-3][y] = ".";
                        battleField[x1-2][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1][y] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y] = ".";

                    }

                    else if (x1 == 3 && y == 10)
                    {
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1-3][y-2] = ".";
                        battleField[x1-2][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1][y-2] = ".";

                    }
                    else if (x1 == 9 && y == 10)
                    {
                        battleField[x1-4][y-1] = ".";
                        battleField[x1-4][y-2] = ".";
                        battleField[x1-3][y-2] = ".";
                        battleField[x1-2][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1][y-2] = ".";
                    }
                    else if (x1 > 3 && x1 < 9 && y == 10)
                    {

                        battleField[x1-4][y-1] = ".";
                        battleField[x1-4][y-2] = ".";
                        battleField[x1-3][y-2] = ".";
                        battleField[x1-2][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y-2] = ".";
                    }

                    else if (y > 1 && y < 10 && x1 == 9)
                    {
                        battleField[x1-4][y-1] = ".";
                        battleField[x1-4][y] = ".";
                        battleField[x1-3][y] = ".";
                        battleField[x1-2][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1][y] = ".";
                        battleField[x1-4][y-2] = ".";
                        battleField[x1-3][y-2] = ".";
                        battleField[x1-2][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1][y-2] = ".";

                    }
                    else if (y > 1 && y < 10 && x1 == 3)
                    {
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-2][y] = ".";
                        battleField[x1-3][y] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-2][y-2] = ".";
                        battleField[x1-3][y-2] = ".";
                    }

                    else
                    {
                        battleField[x1+1][y] = ".";
                        battleField[x1+1][y-1] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-2][y] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1-2][y-2] = ".";
                        battleField[x1-3][y-2] = ".";
                        battleField[x1-4][y-2] = ".";
                        battleField[x1-4][y] = ".";
                        battleField[x1-4][y-1] = ".";

                    }

                    displayBattlefield();
                    carrier--;
                    break;

                case 4:
                    if (x1 > 6)
                    {
                        cout << "Так нельзя располагать корабль! Попробуйте ещё:" << endl;
                        battleField[x1][y-1] = "◇";
                        break;
                    }


                    if ((battleField[x1+1][y-1] != "▥" && battleField[x1+2][y-1] != "▥" && battleField[x1+3][y-1] != "▥") && (battleField[x1+1][y-1] != "." && battleField[x1+2][y-1] != "." && battleField[x1+3][y-1] != "."))
                    {
                        battleField[x1+1][y-1] = "▥";
                        battleField[x1+2][y-1] = "▥";
                        battleField[x1+3][y-1] = "▥";
                    }
                    else
                    {
                        cout << "Нет места для манёвра! Попробуйте другой вариант:" << endl;
                        battleField[x1][y-1] = "◇";
                        break;
                    }



                    if (y == 10 && x1 > 0 && x1 < 6)
                    {
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+2][y-2] = ".";
                        battleField[x1+3][y-2] = ".";
                        battleField[x1+4][y-2] = ".";
                        battleField[x1+4][y-1] = ".";


                    }
                    else if (y == 10 && x1 == 0)
                    {
                        battleField[x1+4][y-1] = ".";
                        battleField[x1+4][y-2] = ".";
                        battleField[x1+3][y-2] = ".";
                        battleField[x1+2][y-2] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1][y-2] = ".";
                    }

                    else  if (y == 10 && x1 == 6)
                    {
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+2][y-2] = ".";
                        battleField[x1+3][y-2] = ".";
                        battleField[x1+4][y-2] = ".";
                    }



                    else if (y > 1 && y < 10 && x1 == 6)
                    {
                        battleField[x1][y] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+2][y] = ".";
                        battleField[x1+3][y] = ".";
                        battleField[x1+4][y] = ".";

                        battleField[x1][y-2] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1+2][y-2] = ".";
                        battleField[x1+3][y-2] = ".";
                        battleField[x1+4][y-2] = ".";
                    }

                    else  if (y == 1 && x1 == 6)
                    {
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1][y] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+2][y] = ".";
                        battleField[x1+3][y] = ".";
                        battleField[x1+4][y] = ".";

                    }

                    else if (y == 1 && x1 > 0 && x1 < 6)
                    {

                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1][y] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+2][y] = ".";
                        battleField[x1+3][y] = ".";
                        battleField[x1+4][y] = ".";
                        battleField[x1+4][y-1] = ".";
                    }
                    else if (y == 1 && x1 == 0)
                    {
                        battleField[x1+4][y-1] = ".";
                        battleField[x1+4][y] = ".";
                        battleField[x1+3][y] = ".";
                        battleField[x1+2][y] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1][y] = ".";
                    }

                    else  if (x1 == 0 && y > 1 && y < 10)
                    {
                        battleField[x1][y] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+2][y] = ".";
                        battleField[x1+3][y] = ".";
                        battleField[x1+4][y] = ".";
                        battleField[x1+4][y-1] = ".";
                        battleField[x1+4][y-2] = ".";
                        battleField[x1+3][y-2] = ".";
                        battleField[x1+2][y-2] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1][y-2] = ".";

                    }

                    else
                    {
                        battleField[x1][y] = ".";
                        battleField[x1+1][y] = ".";
                        battleField[x1+2][y] = ".";
                        battleField[x1+3][y] = ".";
                        battleField[x1+4][y] = ".";
                        battleField[x1+4][y-1] = ".";
                        battleField[x1+4][y-2] = ".";
                        battleField[x1+3][y-2] = ".";
                        battleField[x1+2][y-2] = ".";
                        battleField[x1+1][y-2] = ".";
                        battleField[x1][y-2] = ".";
                        battleField[x1-1][y] = ".";
                        battleField[x1-1][y-1] = ".";
                        battleField[x1-1][y-2] = ".";
                    }
                    displayBattlefield();
                    carrier--;
                    break;

            }

        } while (carrier != 0);

    }while (patrol != 0 && cruiser != 0 && carrier != 0 && submarine != 0);

}

void computerShips()
{
    int x1 = 0;
    int y = 0;
    int choice = 0;

    int patrol = 4;
    int cruiser = 3;
    int submarine = 2;
    int carrier = 1;

    srand( static_cast<unsigned int>(time(nullptr)));

    do {

        do {

            x1 = rand() % 9;
            y = rand() % 10 + 1;

            while (battleField1[x1][y-1] == "▥" || battleField1[x1][y-1] == ".")
            {

                inputValidation1(x1, y);
            }

            battleField1[x1][y-1] = "▥";

            if (x1 == 0 && y == 1)
            {
                battleField1[x1][y] = ".";
                battleField1[x1+1][y-1] = ".";
                battleField1[x1+1][y] = ".";
            }

            if (x1 == 0 && y == 10)
            {
                battleField1[x1][y-2] = ".";
                battleField1[x1+1][y-1] = ".";
                battleField1[x1+1][y-2] = ".";
            }
            if (x1 == 0 && y > 1 && y < 10)
            {
                battleField1[x1][y] = ".";
                battleField1[x1][y-2] = ".";
                battleField1[x1+1][y] = ".";
                battleField1[x1+1][y-1] = ".";
                battleField1[x1+1][y-2] = ".";
            }
            if (x1 == 9 && y > 1 && y < 10)
            {
                battleField1[x1][y] = ".";
                battleField1[x1][y-2] = ".";
                battleField1[x1-1][y] = ".";
                battleField1[x1-1][y-1] = ".";
                battleField1[x1-1][y-2] = ".";
            }

            if (x1 == 9 && y == 1)
            {
                battleField1[x1-1][y-1] = ".";
                battleField1[x1-1][y] = ".";
                battleField1[x1][y] = ".";
            }
            if (x1 == 9 && y == 10)
            {
                battleField1[x1-1][y-1] = ".";
                battleField1[x1-1][y-2] = ".";
                battleField1[x1][y-2] = ".";
            }
            if (y == 1 && x1 > 0 && x1 < 9)
            {
                battleField1[x1][y] = ".";
                battleField1[x1-1][y] = ".";
                battleField1[x1-1][y-1] = ".";
                battleField1[x1+1][y] = ".";
                battleField1[x1+1][y-1] = ".";
            }
            if (y == 10 && x1 > 0 && x1 < 9)
            {
                battleField1[x1][y-2] = ".";
                battleField1[x1-1][y-2] = ".";
                battleField1[x1-1][y-1] = ".";
                battleField1[x1+1][y-2] = ".";
                battleField1[x1+1][y-1] = ".";
            }

            if (x1 != 0 && x1 != 9 && y != 1 && y != 10)
            {
                battleField1[x1][y-2] = ".";
                battleField1[x1][y] = ".";
                battleField1[x1+1][y] = ".";
                battleField1[x1+1][y-1] = ".";
                battleField1[x1+1][y-2] = ".";
                battleField1[x1-1][y] = ".";
                battleField1[x1-1][y-1] = ".";
                battleField1[x1-1][y-2] = ".";
            }

            patrol--;

        } while (patrol != 0);

        do {

            x1 = rand() % 9;
            y = rand() % 10 + 1;


            while (battleField1[x1][y-1] == "▥" || battleField1[x1][y-1] == ".")
            {

                inputValidation1(x1, y);
            }

            battleField1[x1][y-1] = "▥";


            choice = rand() % 4 + 1;



            switch (choice)
            {
                case 1:

                    if (y == 10)
                    {
                        battleField1[x1][y-1] = "◇";
                        break;
                    }
                    if (battleField1[x1][y] != "▥" && battleField1[x1][y] != ".")
                    {
                        battleField1[x1][y] = "▥";
                    }
                    else
                    {

                        battleField1[x1][y-1] = "◇";
                        break;
                    }

                    if (x1 == 0 && y == 1)
                    {
                        battleField1[x1][y+1] = ".";
                        battleField1[x1+1][y+1] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y-1] = ".";
                    }

                    else if (x1 == 9 && y == 1)
                    {
                        battleField1[x1][y+1] = ".";
                        battleField1[x1-1][y+1] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";
                    }


                    else if (x1 > 0 && x1 < 9 && y == 1)
                    {
                        battleField1[x1][y+1] = ".";
                        battleField1[x1-1][y+1] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1+1][y+1] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y-1] = ".";
                    }
                    else if (x1 > 0 && x1 < 9 && y == 9)
                    {
                        battleField1[x1][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y] = ".";
                    }

                    else if (x1 == 0 && y == 9)
                    {
                        battleField1[x1][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y] = ".";
                    }
                    else if (x1 == 9 && y == 9)
                    {
                        battleField1[x1][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y] = ".";
                    }


                    else if (x1 == 0 && y > 1 && y < 9)
                    {
                        battleField1[x1][y+1] = ".";
                        battleField1[x1+1][y+1] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";
                    }

                    else if (x1 == 9 && y > 1 && y < 9)
                    {
                        battleField1[x1][y+1] = ".";
                        battleField1[x1-1][y+1] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                    }

                    else
                    {
                        battleField1[x1][y+1] = ".";
                        battleField1[x1-1][y+1] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1+1][y+1] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";

                    }




                    cruiser--;
                    break;

                case 2:
                    if (y == 1)
                    {

                        battleField1[x1][y-1] = "◇";
                        break;
                    }

                    if (battleField1[x1][y-2] != "▥" && battleField1[x1][y-2] != ".")
                    {
                        battleField1[x1][y-2] = "▥";
                    }
                    else
                    {

                        battleField1[x1][y-1] = "◇";
                        break;
                    }


                    if (y == 10 && x1 > 0 && x1 < 9)
                    {
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1-1][y-3] = ".";
                        battleField1[x1][y-3] = ".";
                        battleField1[x1+1][y-3] = ".";
                    }
                    else if (y == 10 && x1 == 0)
                    {
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+1][y-3] = ".";
                        battleField1[x1][y-3] = ".";
                    }

                    else if (y == 10 && x1 == 9)
                    {
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-1][y-3] = ".";
                        battleField1[x1][y-3] = ".";
                    }

                    else if (y > 1 && y < 10 && x1 == 9)
                    {
                        battleField1[x1][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-1][y-3] = ".";
                        battleField1[x1][y-3] = ".";

                    }
                    else if (y == 2 && x1 == 9)
                    {
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1][y] = ".";

                    }
                    else if (y == 2 && x1 > 0 && x1 < 9)
                    {
                        battleField1[x1][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y-2] = ".";
                    }
                    else if (y == 2 && x1 == 0)
                    {
                        battleField1[x1][y] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y-2] = ".";
                    }
                    else if (x1 == 0 && y > 1 && y < 10)
                    {
                        battleField1[x1][y] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+1][y-3] = ".";
                        battleField1[x1][y-3] = ".";

                    }
                    else
                    {
                        battleField1[x1][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-1][y-3] = ".";
                        battleField1[x1][y-3] = ".";
                        battleField1[x1+1][y-3] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y] = ".";
                    }


                    cruiser--;
                    break;

                case 3:
                    if (x1 == 0)
                    {

                        battleField1[x1][y-1] = "◇";
                        break;
                    }

                    if (battleField1[x1-1][y-1] != "▥" && battleField1[x1-1][y-1] != ".")
                    {
                        battleField1[x1-1][y-1] = "▥";
                    }
                    else
                    {

                        battleField1[x1][y-1] = "◇";
                        break;
                    }

                    if (x1 == 1 && y == 1)
                    {
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1][y] = ".";

                    }
                    else if (x1 == 9 && y == 1)
                    {
                        battleField1[x1-2][y-1] = ".";
                        battleField1[x1-2][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1][y] = ".";
                    }
                    else if (x1 > 1 && x1 < 9 && y == 1)
                    {

                        battleField1[x1-2][y-1] = ".";
                        battleField1[x1-2][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1][y] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y] = ".";

                    }

                    else if (x1 == 1 && y == 10)
                    {
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1][y-2] = ".";

                    }
                    else if (x1 == 9 && y == 10)
                    {
                        battleField1[x1-2][y-1] = ".";
                        battleField1[x1-2][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1][y-2] = ".";
                    }
                    else if (x1 > 1 && x1 < 9 && y == 10)
                    {

                        battleField1[x1-2][y-1] = ".";
                        battleField1[x1-2][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y-2] = ".";
                    }

                    else if (y > 1 && y < 10 && x1 == 9)
                    {
                        battleField1[x1-2][y] = ".";
                        battleField1[x1-2][y-1] = ".";
                        battleField1[x1-2][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1][y] = ".";
                        battleField1[x1][y-2] = ".";
                    }
                    else if (y > 1 && y < 10 && x1 == 1)
                    {
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1][y] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-2] = ".";
                    }

                    else
                    {
                        battleField1[x1-2][y] = ".";
                        battleField1[x1-2][y-1] = ".";
                        battleField1[x1-2][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1][y] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y] = ".";
                    }


                    cruiser--;
                    break;

                case 4:
                    if (x1 == 9)
                    {

                        battleField1[x1][y-1] = "◇";
                        break;
                    }
                    if ((battleField1[x1+1][y-1] != "▥") && (battleField1[x1+1][y-1] != "."))
                    {
                        battleField1[x1+1][y-1] = "▥";
                    }
                    else
                    {

                        battleField1[x1][y-1] = "◇";
                        break;
                    }

                    if (y == 10 && x1 > 0 && x1 < 8)
                    {
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+2][y-2] = ".";
                        battleField1[x1+2][y-1] = ".";
                    }
                    else if (y == 10 && x1 == 0)
                    {
                        battleField1[x1][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+2][y-2] = ".";
                        battleField1[x1+2][y-1] = ".";
                    }

                    else  if (y == 10 && x1 == 8)
                    {
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";
                    }

                    else if (y > 1 && y < 10 && x1 == 8)
                    {
                        battleField1[x1][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";
                    }
                    else  if (y == 1 && x1 == 8)
                    {
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1][y] = ".";
                        battleField1[x1+1][y] = ".";
                    }
                    else if (y == 1 && x1 > 0 && x1 < 8)
                    {
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1][y] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+2][y] = ".";
                        battleField1[x1+2][y-1] = ".";
                    }
                    else if (y == 1 && x1 == 0)
                    {
                        battleField1[x1][y] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+2][y] = ".";
                        battleField1[x1+2][y-1] = ".";
                    }
                    else  if (x1 == 0 && y > 1 && y < 10)
                    {
                        battleField1[x1][y] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+2][y] = ".";
                        battleField1[x1+2][y-1] = ".";
                        battleField1[x1+2][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1][y-2] = ".";

                    }

                    else
                    {
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+2][y-2] = ".";
                        battleField1[x1+2][y-1] = ".";
                        battleField1[x1+2][y] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";
                    }

                    cruiser--;
                    break;

            }


        } while(cruiser != 0);

        do {

            x1 = rand() % 9;
            y = rand() % 10 + 1;


            while (battleField1[x1][y-1] == "▥" || battleField1[x1][y-1] == ".")
            {

                inputValidation1(x1, y);
            }

            battleField1[x1][y-1] = "▥";


            choice = rand() % 4 + 1;



            switch (choice)
            {
                case 1:

                    if (y > 8)
                    {
                        battleField1[x1][y-1] = "◇";
                        break;
                    }
                    if ((battleField1[x1][y] != "▥" && battleField1[x1][y+1] != "▥") && (battleField1[x1][y] != "." && battleField1[x1][y+1] != "."))
                    {
                        battleField1[x1][y] = "▥";
                        battleField1[x1][y+1] = "▥";
                    }
                    else
                    {
                        battleField1[x1][y-1] = "◇";
                        break;
                    }

                    if (x1 == 0 && y == 1)
                    {
                        battleField1[x1][y+2] = ".";
                        battleField1[x1+1][y+2] = ".";
                        battleField1[x1+1][y+1] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y-1] = ".";
                    }
                    else if (x1 == 9 && y == 1)
                    {
                        battleField1[x1][y+2] = ".";
                        battleField1[x1-1][y+2] = ".";
                        battleField1[x1-1][y+1] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";

                    }

                    else if (x1 > 0 && x1 < 9 && y == 1)
                    {
                        battleField1[x1][y+2] = ".";
                        battleField1[x1-1][y+2] = ".";
                        battleField1[x1-1][y+1] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1+1][y+2] = ".";
                        battleField1[x1+1][y+1] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y-1] = ".";
                    }
                    else if (x1 > 0 && x1 < 9 && y == 8)
                    {
                        battleField1[x1][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y+1] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y+1] = ".";
                    }

                    else if (x1 == 0 && y == 8)
                    {
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y+1] = ".";
                        battleField1[x1][y-2] = ".";

                    }
                    else if (x1 == 9 && y == 8)
                    {
                        battleField1[x1][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y+1] = ".";
                    }


                    else if (x1 == 0 && y > 1 && y < 8)
                    {
                        battleField1[x1][y+2] = ".";
                        battleField1[x1+1][y+2] = ".";
                        battleField1[x1+1][y+1] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";
                    }

                    else if (x1 == 9 && y > 1 && y < 9)
                    {
                        battleField1[x1][y+2] = ".";
                        battleField1[x1-1][y+2] = ".";
                        battleField1[x1-1][y+1] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                    }

                    else
                    {
                        battleField1[x1][y+2] = ".";

                        battleField1[x1-1][y+2] = ".";
                        battleField1[x1-1][y+1] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";

                        battleField1[x1+1][y+2] = ".";
                        battleField1[x1+1][y+1] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y-1] = ".";

                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";

                    }




                    submarine--;
                    break;

                case 2:
                    if (y < 3)
                    {

                        battleField1[x1][y-1] = "◇";
                        break;
                    }

                    if ((battleField1[x1][y-2] != "▥" && battleField1[x1][y-3] != "▥") && (battleField1[x1][y-2] != "." && battleField1[x1][y-3] != "."))
                    {
                        battleField1[x1][y-2] = "▥";
                        battleField1[x1][y-3] = "▥";
                    }
                    else
                    {
                        battleField1[x1][y-1] = "◇";
                        break;
                    }


                    if (y == 10 && x1 > 0 && x1 < 9)
                    {
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+1][y-3] = ".";
                        battleField1[x1+1][y-4] = ".";
                        battleField1[x1][y-4] = ".";

                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-1][y-3] = ".";
                        battleField1[x1-1][y-4] = ".";


                    }
                    else if (y == 10 && x1 == 0)
                    {
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+1][y-3] = ".";
                        battleField1[x1+1][y-4] = ".";
                        battleField1[x1][y-4] = ".";
                    }

                    else if (y == 10 && x1 == 9)
                    {
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-1][y-3] = ".";
                        battleField1[x1-1][y-4] = ".";
                        battleField1[x1][y-4] = ".";
                    }

                    else if (y > 3 && y < 10 && x1 == 9)
                    {
                        battleField1[x1][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-1][y-3] = ".";
                        battleField1[x1-1][y-4] = ".";
                        battleField1[x1][y-4] = ".";

                    }
                    else if (y == 3 && x1 == 9)
                    {
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-1][y-3] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1][y] = ".";

                    }
                    else if (y == 3 && x1 > 0 && x1 < 9)
                    {
                        battleField1[x1][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-1][y-3] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+1][y-3] = ".";
                    }
                    else if (y == 3 && x1 == 0)
                    {
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+1][y-3] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1][y] = ".";
                    }
                    else if (x1 == 0 && y > 3 && y < 10)
                    {
                        battleField1[x1][y] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+1][y-3] = ".";
                        battleField1[x1+1][y-4] = ".";
                        battleField1[x1][y-4] = ".";

                    }
                    else
                    {
                        battleField1[x1][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-1][y-3] = ".";
                        battleField1[x1-1][y-4] = ".";
                        battleField1[x1][y-4] = ".";
                        battleField1[x1+1][y-4] = ".";
                        battleField1[x1+1][y-3] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y] = ".";
                    }


                    submarine--;
                    break;

                case 3:
                    if (x1 < 2)
                    {

                        battleField1[x1][y-1] = "◇";
                        break;
                    }

                    if ((battleField1[x1-1][y-1] != "▥" && battleField1[x1-2][y-1] != "▥") && (battleField1[x1-1][y-1] != "." && battleField1[x1-2][y-1] != "."))
                    {
                        battleField1[x1-1][y-1] = "▥";
                        battleField1[x1-2][y-1] = "▥";

                    }
                    else
                    {
                        battleField1[x1][y-1] = "◇";
                        break;
                    }

                    if (x1 == 2 && y == 1)
                    {
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1-2][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1][y] = ".";

                    }
                    else if (x1 == 9 && y == 1)
                    {
                        battleField1[x1-3][y-1] = ".";
                        battleField1[x1-3][y] = ".";
                        battleField1[x1-2][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1][y] = ".";
                    }
                    else if (x1 > 2 && x1 < 9 && y == 1)
                    {

                        battleField1[x1-3][y-1] = ".";
                        battleField1[x1-3][y] = ".";
                        battleField1[x1-2][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1][y] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y] = ".";

                    }

                    else if (x1 == 2 && y == 10)
                    {
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1-2][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1][y-2] = ".";

                    }
                    else if (x1 == 9 && y == 10)
                    {
                        battleField1[x1-3][y-1] = ".";
                        battleField1[x1-3][y-2] = ".";
                        battleField1[x1-2][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1][y-2] = ".";
                    }
                    else if (x1 > 2 && x1 < 9 && y == 10)
                    {

                        battleField1[x1-3][y-1] = ".";
                        battleField1[x1-3][y-2] = ".";
                        battleField1[x1-2][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y-2] = ".";
                    }

                    else if (y > 1 && y < 10 && x1 == 9)
                    {
                        battleField1[x1-3][y-1] = ".";
                        battleField1[x1-3][y] = ".";
                        battleField1[x1-2][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1][y] = ".";
                        battleField1[x1-3][y-2] = ".";
                        battleField1[x1-2][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1][y-2] = ".";



                    }
                    else if (y > 1 && y < 10 && x1 == 2)
                    {
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y-2] = ".";

                        battleField1[x1][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-2][y] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-2][y-2] = ".";
                    }

                    else
                    {
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y-2] = ".";

                        battleField1[x1][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-2][y] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-2][y-2] = ".";

                        battleField1[x1-3][y] = ".";
                        battleField1[x1-3][y-1] = ".";
                        battleField1[x1-3][y-2] = ".";
                    }


                    submarine--;
                    break;

                case 4:
                    if (x1 > 7)
                    {

                        battleField1[x1][y-1] = "◇";
                        break;
                    }

                    if ((battleField1[x1+1][y-1] != "▥" && battleField1[x1+2][y-1] != "▥") && (battleField1[x1+1][y-1] != "." && battleField1[x1+2][y-1] != "."))
                    {
                        battleField1[x1+1][y-1] = "▥";
                        battleField1[x1+2][y-1] = "▥";
                    }
                    else
                    {

                        battleField1[x1][y-1] = "◇";
                        break;
                    }



                    if (y == 10 && x1 > 0 && x1 < 7)
                    {

                        battleField1[x1+3][y-1] = ".";
                        battleField1[x1+3][y-2] = ".";
                        battleField1[x1+2][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";

                    }
                    else if (y == 10 && x1 == 0)
                    {
                        battleField1[x1+3][y-1] = ".";
                        battleField1[x1+3][y-2] = ".";
                        battleField1[x1+2][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1][y-2] = ".";
                    }

                    else  if (y == 10 && x1 == 7)
                    {
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+2][y-2] = ".";
                    }



                    else if (y > 1 && y < 10 && x1 == 7)
                    {
                        battleField1[x1][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+2][y] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+2][y-2] = ".";
                    }



                    else  if (y == 1 && x1 == 7)
                    {
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1][y] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+2][y] = ".";
                    }


                    else if (y == 1 && x1 > 0 && x1 < 7)
                    {


                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1][y] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+2][y] = ".";
                        battleField1[x1+3][y] = ".";
                        battleField1[x1+3][y-1] = ".";
                    }
                    else if (y == 1 && x1 == 0)
                    {
                        battleField1[x1+3][y-1] = ".";
                        battleField1[x1+3][y] = ".";
                        battleField1[x1+2][y] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1][y] = ".";
                    }



                    else  if (x1 == 0 && y > 1 && y < 10)
                    {
                        battleField1[x1][y] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+2][y] = ".";
                        battleField1[x1+3][y] = ".";
                        battleField1[x1+3][y-1] = ".";
                        battleField1[x1+3][y-2] = ".";
                        battleField1[x1+2][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1][y-2] = ".";

                    }

                    else
                    {
                        battleField1[x1][y] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+2][y] = ".";
                        battleField1[x1+3][y] = ".";
                        battleField1[x1+3][y-1] = ".";
                        battleField1[x1+3][y-2] = ".";
                        battleField1[x1+2][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                    }

                    submarine--;
                    break;

            }


        } while(submarine != 0);

        do {

            x1 = rand() % 9;
            y = rand() % 10 + 1;


            while (battleField1[x1][y-1] == "▥" || battleField1[x1][y-1] == ".")
            {

                inputValidation1(x1, y);
            }

            battleField1[x1][y-1] = "▥";


            choice = rand() % 4 + 1;



            switch (choice)
            {
                case 1:

                    if (y > 7)
                    {
                        battleField1[x1][y-1] = "◇";
                        break;
                    }


                    if ((battleField1[x1][y] != "▥" && battleField1[x1][y+1] != "▥" && battleField1[x1][y+2] != "▥") && (battleField1[x1][y] != "." && battleField1[x1][y+1] != "." && battleField1[x1][y+2] != "."))
                    {
                        battleField1[x1][y] = "▥";
                        battleField1[x1][y+1] = "▥";
                        battleField1[x1][y+2] = "▥";
                    }
                    else
                    {
                        battleField1[x1][y-1] = "◇";
                        break;
                    }

                    if (x1 == 0 && y == 1)
                    {
                        battleField1[x1][y+3] = ".";
                        battleField1[x1+1][y+3] = ".";
                        battleField1[x1+1][y+2] = ".";
                        battleField1[x1+1][y+1] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y-1] = ".";
                    }
                    else if (x1 == 9 && y == 1)
                    {
                        battleField1[x1][y+3] = ".";
                        battleField1[x1-1][y+3] = ".";
                        battleField1[x1-1][y+2] = ".";
                        battleField1[x1-1][y+1] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";

                    }

                    else if (x1 > 0 && x1 < 8 && y == 1)
                    {
                        battleField1[x1][y+3] = ".";
                        battleField1[x1-1][y+3] = ".";
                        battleField1[x1-1][y+2] = ".";
                        battleField1[x1-1][y+1] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1+1][y+3] = ".";
                        battleField1[x1+1][y+2] = ".";
                        battleField1[x1+1][y+1] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y-1] = ".";
                    }
                    else if (x1 > 0 && x1 < 9 && y == 7)
                    {
                        battleField1[x1][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y+1] = ".";
                        battleField1[x1-1][y+2] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y+1] = ".";
                        battleField1[x1+1][y+2] = ".";
                    }

                    else if (x1 == 0 && y == 7)
                    {
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y+1] = ".";
                        battleField1[x1+1][y+2] = ".";
                        battleField1[x1][y-2] = ".";

                    }
                    else if (x1 == 9 && y == 7)
                    {
                        battleField1[x1][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y+1] = ".";
                        battleField1[x1-1][y+2] = ".";
                    }


                    else if (x1 == 0 && y > 1 && y < 7)
                    {
                        battleField1[x1][y+3] = ".";
                        battleField1[x1+1][y+3] = ".";
                        battleField1[x1+1][y+2] = ".";
                        battleField1[x1+1][y+1] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";
                    }

                    else if (x1 == 9 && y > 1 && y < 7)
                    {
                        battleField1[x1][y+3] = ".";
                        battleField1[x1-1][y+3] = ".";
                        battleField1[x1-1][y+2] = ".";
                        battleField1[x1-1][y+1] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                    }

                    else
                    {
                        battleField1[x1][y+3] = ".";
                        battleField1[x1-1][y+3] = ".";
                        battleField1[x1-1][y+2] = ".";
                        battleField1[x1-1][y+1] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";

                        battleField1[x1+1][y+3] = ".";
                        battleField1[x1+1][y+2] = ".";
                        battleField1[x1+1][y+1] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y-1] = ".";

                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";

                    }

                    carrier--;
                    break;

                case 2:
                    if (y < 4)
                    {

                        battleField1[x1][y-1] = "◇";
                        break;
                    }

                    if ((battleField1[x1][y-2] != "▥" && battleField1[x1][y-3] != "▥" && battleField1[x1][y-4] != "▥") && (battleField1[x1][y-2] != "." && battleField1[x1][y-3] != "." && battleField1[x1][y-4] != "."))
                    {
                        battleField1[x1][y-2] = "▥";
                        battleField1[x1][y-3] = "▥";
                        battleField1[x1][y-4] = "▥";
                    }
                    else
                    {
                        battleField1[x1][y-1] = "◇";
                        break;
                    }

                    if (y == 10 && x1 > 0 && x1 < 9)
                    {
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+1][y-3] = ".";
                        battleField1[x1+1][y-4] = ".";
                        battleField1[x1+1][y-5] = ".";
                        battleField1[x1][y-5] = ".";

                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-1][y-3] = ".";
                        battleField1[x1-1][y-4] = ".";
                        battleField1[x1-1][y-5] = ".";


                    }
                    else if (y == 10 && x1 == 0)
                    {
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+1][y-3] = ".";
                        battleField1[x1+1][y-4] = ".";
                        battleField1[x1+1][y-5] = ".";
                        battleField1[x1][y-5] = ".";
                    }

                    else if (y == 10 && x1 == 9)
                    {
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-1][y-3] = ".";
                        battleField1[x1-1][y-4] = ".";
                        battleField1[x1-1][y-5] = ".";
                        battleField1[x1][y-5] = ".";
                    }

                    else if (y > 4 && y < 10 && x1 == 9)
                    {
                        battleField1[x1][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-1][y-3] = ".";
                        battleField1[x1-1][y-4] = ".";
                        battleField1[x1-1][y-5] = ".";
                        battleField1[x1][y-5] = ".";

                    }
                    else if (y == 4 && x1 == 9)
                    {
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-1][y-3] = ".";
                        battleField1[x1-1][y-4] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1][y] = ".";

                    }
                    else if (y == 4 && x1 > 0 && x1 < 9)
                    {
                        battleField1[x1][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-1][y-3] = ".";
                        battleField1[x1-1][y-4] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+1][y-3] = ".";
                        battleField1[x1+1][y-4] = ".";
                    }
                    else if (y == 4 && x1 == 0)
                    {
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+1][y-3] = ".";
                        battleField1[x1+1][y-4] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1][y] = ".";
                    }
                    else if (x1 == 0 && y > 4 && y < 10)
                    {
                        battleField1[x1][y] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+1][y-3] = ".";
                        battleField1[x1+1][y-4] = ".";
                        battleField1[x1+1][y-5] = ".";
                        battleField1[x1][y-5] = ".";

                    }
                    else
                    {
                        battleField1[x1][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-1][y-3] = ".";
                        battleField1[x1-1][y-4] = ".";
                        battleField1[x1-1][y-5] = ".";
                        battleField1[x1][y-5] = ".";
                        battleField1[x1+1][y-5] = ".";
                        battleField1[x1+1][y-4] = ".";
                        battleField1[x1+1][y-3] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y] = ".";
                    }


                    carrier--;
                    break;

                case 3:
                    if (x1 < 3)
                    {

                        battleField1[x1][y-1] = "◇";
                        break;
                    }

                    if ((battleField1[x1-1][y-1] != "▥" && battleField1[x1-2][y-1] != "▥" && battleField1[x1-3][y-1] != "▥") && (battleField1[x1-1][y-1] != "." && battleField1[x1-2][y-1] != "." && battleField1[x1-3][y-1] != "."))
                    {
                        battleField1[x1-1][y-1] = "▥";
                        battleField1[x1-2][y-1] = "▥";
                        battleField1[x1-3][y-1] = "▥";
                    }
                    else
                    {

                        battleField1[x1][y-1] = "◇";
                        break;
                    }

                    if (x1 == 3 && y == 1)
                    {
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1-3][y] = ".";
                        battleField1[x1-2][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1][y] = ".";

                    }
                    else if (x1 == 9 && y == 1)
                    {
                        battleField1[x1-4][y-1] = ".";
                        battleField1[x1-4][y] = ".";
                        battleField1[x1-3][y] = ".";
                        battleField1[x1-2][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1][y] = ".";
                    }


                    else if (x1 > 3 && x1 < 9 && y == 1)
                    {

                        battleField1[x1-4][y-1] = ".";
                        battleField1[x1-4][y] = ".";
                        battleField1[x1-3][y] = ".";
                        battleField1[x1-2][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1][y] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y] = ".";

                    }

                    else if (x1 == 3 && y == 10)
                    {
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1-3][y-2] = ".";
                        battleField1[x1-2][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1][y-2] = ".";

                    }
                    else if (x1 == 9 && y == 10)
                    {
                        battleField1[x1-4][y-1] = ".";
                        battleField1[x1-4][y-2] = ".";
                        battleField1[x1-3][y-2] = ".";
                        battleField1[x1-2][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1][y-2] = ".";
                    }
                    else if (x1 > 3 && x1 < 9 && y == 10)
                    {

                        battleField1[x1-4][y-1] = ".";
                        battleField1[x1-4][y-2] = ".";
                        battleField1[x1-3][y-2] = ".";
                        battleField1[x1-2][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y-2] = ".";
                    }

                    else if (y > 1 && y < 10 && x1 == 9)
                    {
                        battleField1[x1-4][y-1] = ".";
                        battleField1[x1-4][y] = ".";
                        battleField1[x1-3][y] = ".";
                        battleField1[x1-2][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1][y] = ".";
                        battleField1[x1-4][y-2] = ".";
                        battleField1[x1-3][y-2] = ".";
                        battleField1[x1-2][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1][y-2] = ".";

                    }
                    else if (y > 1 && y < 10 && x1 == 3)
                    {
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y-2] = ".";

                        battleField1[x1][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-2][y] = ".";
                        battleField1[x1-3][y] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-2][y-2] = ".";
                        battleField1[x1-3][y-2] = ".";
                    }

                    else
                    {
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+1][y-1] = ".";
                        battleField1[x1+1][y-2] = ".";

                        battleField1[x1][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-2][y] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1-2][y-2] = ".";
                        battleField1[x1-3][y-2] = ".";
                        battleField1[x1-4][y-2] = ".";
                        battleField1[x1-4][y] = ".";
                        battleField1[x1-4][y-1] = ".";

                    }


                    carrier--;
                    break;

                case 4:
                    if (x1 > 6)
                    {

                        battleField1[x1][y-1] = "◇";
                        break;
                    }


                    if ((battleField1[x1+1][y-1] != "▥" && battleField1[x1+2][y-1] != "▥" && battleField1[x1+3][y-1] != "▥") && (battleField1[x1+1][y-1] != "." && battleField1[x1+2][y-1] != "." && battleField1[x1+3][y-1] != "."))
                    {
                        battleField1[x1+1][y-1] = "▥";
                        battleField1[x1+2][y-1] = "▥";
                        battleField1[x1+3][y-1] = "▥";
                    }
                    else
                    {

                        battleField1[x1][y-1] = "◇";
                        break;
                    }



                    if (y == 10 && x1 > 0 && x1 < 6)
                    {
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+2][y-2] = ".";
                        battleField1[x1+3][y-2] = ".";
                        battleField1[x1+4][y-2] = ".";
                        battleField1[x1+4][y-1] = ".";


                    }
                    else if (y == 10 && x1 == 0)
                    {
                        battleField1[x1+4][y-1] = ".";
                        battleField1[x1+4][y-2] = ".";
                        battleField1[x1+3][y-2] = ".";
                        battleField1[x1+2][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1][y-2] = ".";
                    }

                    else  if (y == 10 && x1 == 6)
                    {
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+2][y-2] = ".";
                        battleField1[x1+3][y-2] = ".";
                        battleField1[x1+4][y-2] = ".";
                    }



                    else if (y > 1 && y < 10 && x1 == 6)
                    {
                        battleField1[x1][y] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+2][y] = ".";
                        battleField1[x1+3][y] = ".";
                        battleField1[x1+4][y] = ".";

                        battleField1[x1][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1+2][y-2] = ".";
                        battleField1[x1+3][y-2] = ".";
                        battleField1[x1+4][y-2] = ".";
                    }

                    else  if (y == 1 && x1 == 6)
                    {
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1][y] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+2][y] = ".";
                        battleField1[x1+3][y] = ".";
                        battleField1[x1+4][y] = ".";

                    }

                    else if (y == 1 && x1 > 0 && x1 < 6)
                    {

                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1][y] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+2][y] = ".";
                        battleField1[x1+3][y] = ".";
                        battleField1[x1+4][y] = ".";
                        battleField1[x1+4][y-1] = ".";
                    }
                    else if (y == 1 && x1 == 0)
                    {
                        battleField1[x1+4][y-1] = ".";
                        battleField1[x1+4][y] = ".";
                        battleField1[x1+3][y] = ".";
                        battleField1[x1+2][y] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1][y] = ".";
                    }

                    else  if (x1 == 0 && y > 1 && y < 10)
                    {
                        battleField1[x1][y] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+2][y] = ".";
                        battleField1[x1+3][y] = ".";
                        battleField1[x1+4][y] = ".";
                        battleField1[x1+4][y-1] = ".";
                        battleField1[x1+4][y-2] = ".";
                        battleField1[x1+3][y-2] = ".";
                        battleField1[x1+2][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1][y-2] = ".";

                    }

                    else
                    {
                        battleField1[x1][y] = ".";
                        battleField1[x1+1][y] = ".";
                        battleField1[x1+2][y] = ".";
                        battleField1[x1+3][y] = ".";
                        battleField1[x1+4][y] = ".";
                        battleField1[x1+4][y-1] = ".";
                        battleField1[x1+4][y-2] = ".";
                        battleField1[x1+3][y-2] = ".";
                        battleField1[x1+2][y-2] = ".";
                        battleField1[x1+1][y-2] = ".";
                        battleField1[x1][y-2] = ".";
                        battleField1[x1-1][y] = ".";
                        battleField1[x1-1][y-1] = ".";
                        battleField1[x1-1][y-2] = ".";
                    }

                    carrier--;
                    break;

            }

        } while(carrier != 0);


    }while (patrol != 0 && cruiser != 0 && carrier != 0 && submarine != 0);
}

void inputValidation(char &x, int &y)
{
    cout << "\nБуква: ";
    cin >> x;
    while (toupper(x) != 'A' && toupper(x) != 'B' && toupper(x) != 'C' && toupper(x) != 'D'
           && toupper(x) != 'E' && toupper(x) != 'F' && toupper(x) != 'G' && toupper(x) != 'H'
           && toupper(x) != 'I' && toupper(x) != 'J')
    {
        cout << "Ошибка ввода! Попробуйте ещё раз!" << endl;
        cin >> x;
    }
    cout << "Цифра: ";
    cin >> y;
    while (y <= 0 || y > 10)
    {
        cout << "Ошибка ввода! Попробуйте ещё раз!" << endl;
        cin >> y;
    }
}

void inputValidation1(int &x, int &y)
{
    x = rand() % 9;
    y = rand() % 10 + 1;

}





