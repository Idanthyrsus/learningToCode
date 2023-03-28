////
////  copy.cpp
////  ShipBattle
////
////  Created by Alexander Korchak on 19.04.2022.
////
//
////#include "copy.hpp"
////
////cout << "Расположите корабли:" << endl;
////cout << "Патрульный катер (1 палуба, 4 единицы)." << endl;
////    do {
////    cout << "Назовите координаты: " << endl;
////
////    cout << "\nБуква: ";
////    cin >> x;
////    while (toupper(x) != 'A' && toupper(x) != 'B' && toupper(x) != 'C' && toupper(x) != 'D'
////        && toupper(x) != 'E' && toupper(x) != 'F' && toupper(x) != 'G' && toupper(x) != 'H'
////        && toupper(x) != 'I' && toupper(x) != 'J')
////    {
////        cout << "Ошибка ввода! Попробуйте ещё раз!" << endl;
////        cin >> x;
////    }
////    switch (x)
////    {
////        case 'A':
////        case 'a':
////            cout << "Цифра: ";
////            cin >> y;
////            while (y <= 0 || y > 10)
////            {
////                cout << "Ошибка ввода! Попробуйте ещё раз!" << endl;
////                cin >> y;
////            }
////            if (battleField[0][y-1] == "▥")
////            {
////                cout << "Эта клетка уже занята! Попробуйте ещё раз: ";
////                inputValidation(x, y);
////            }
////            else if (battleField[0][y-1] == ".")
////            {
////                cout << "Командование доложило, что располагать корабли так близко угрожает их безопасности. Попробуйте ещё раз: ";
////                inputValidation(x, y);
////            }
////
////                battleField[0][y-1] = "▥";
////
////            if (y == 1)
////            {
////                battleField[0][y] = ".";
////                battleField[1][y-1] = ".";
////                battleField[1][y] = ".";
////            }
////            else if (y == 10)
////            {
////                battleField[0][y-2] = ".";
////                battleField[1][y-1] = ".";
////                battleField[1][y-2] = ".";
////            }
////            else
////            {
////                battleField[0][y] = ".";
////                battleField[0][y-2] = ".";
////                battleField[1][y] = ".";
////                battleField[1][y-1] = ".";
////                battleField[1][y-2] = ".";
////            }
////
////                displayBattlefield();
////        patrol--;
////            break;
////        case 'B':
////        case 'b':
////            cout << "Цифра: ";
////            cin >> y;
////            while (y <= 0 || y > 10)
////            {
////                cout << "Ошибка ввода! Попробуйте ещё раз!" << endl;
////                cin >> y;
////            }
////            if (battleField[1][y-1] == "▥")
////            {
////                cout << "Эта клетка уже занята! Попробуйте ещё раз: ";
////                inputValidation(x, y);
////            }
////            else if (battleField[1][y-1] == ".")
////            {
////                cout << "Командование доложило, что располагать корабли так близко угрожает их безопасности. Попробуйте ещё раз: ";
////                inputValidation(x, y);
////            }
////
////            battleField[1][y-1] = "▥";
////
////            if (y == 1)
////            {
////                battleField[0][y-1] = ".";
////                battleField[0][y] = ".";
////                battleField[1][y] = ".";
////                battleField[2][y] = ".";
////                battleField[2][y-1] = ".";
////            }
////            else if (y == 10)
////            {
////                battleField[0][y-1] = ".";
////                battleField[0][y-2] = ".";
////                battleField[1][y-2] = ".";
////                battleField[2][y-1] = ".";
////                battleField[2][y-2] = ".";
////            }
////            else
////            {
////            battleField[0][y-1] = ".";
////            battleField[0][y-2] = ".";
////            battleField[0][y] = ".";
////            battleField[1][y] = ".";
////            battleField[1][y-2] = ".";
////            battleField[2][y] = ".";
////            battleField[2][y-1] = ".";
////            battleField[2][y-2] = ".";
////            }
////
////            displayBattlefield();
////        patrol--;
////            break;
////        case 'C':
////        case 'c':
////            cout << "Цифра: ";
////            cin >> y;
////            while (y <= 0 || y > 10)
////            {
////                cout << "Ошибка ввода! Попробуйте ещё раз!" << endl;
////                cin >> y;
////            }
////            if (battleField[2][y-1] == "▥")
////            {
////                cout << "Эта клетка уже занята! Попробуйте ещё раз: ";
////                inputValidation(x, y);
////            }
////            else if (battleField[2][y-1] == ".")
////            {
////                cout << "Командование доложило, что располагать корабли так близко угрожает их безопасности. Попробуйте ещё раз: ";
////                inputValidation(x, y);
////            }
////
////            battleField[2][y-1] = "▥";
////
////            if (y == 1)
////            {
////                battleField[1][y-1] = ".";
////                battleField[1][y] = ".";
////                battleField[2][y] = ".";
////                battleField[3][y] = ".";
////                battleField[3][y-1] = ".";
////            }
////            else if (y == 10)
////            {
////                battleField[1][y-1] = ".";
////                battleField[1][y-2] = ".";
////                battleField[2][y-2] = ".";
////                battleField[3][y-1] = ".";
////                battleField[3][y-2] = ".";
////            }
////            else
////            {
////            battleField[1][y-1] = ".";
////            battleField[1][y-2] = ".";
////            battleField[1][y] = ".";
////            battleField[2][y] = ".";
////            battleField[2][y-2] = ".";
////            battleField[3][y] = ".";
////            battleField[3][y-1] = ".";
////            battleField[3][y-2] = ".";
////            }
////
////            displayBattlefield();
////        patrol--;
////            break;
////        case 'D':
////        case 'd':
////            cout << "Цифра: ";
////            cin >> y;
////            while (y <= 0 || y > 10)
////            {
////                cout << "Ошибка ввода! Попробуйте ещё раз!" << endl;
////                cin >> y;
////            }
////            while (battleField[3][y-1] == "▥")
////            {
////                cout << "Эта клетка уже занята! Попробуйте ещё раз: ";
////                inputValidation(x, y);
////            }
////            while (battleField[3][y-1] == ".")
////            {
////                cout << "Командование доложило, что располагать корабли так близко угрожает их безопасности. Попробуйте ещё раз: ";
////                inputValidation(x, y);
////            }
////
////            battleField[3][y-1] = "▥";
////
////            if (y == 1)
////            {
////                battleField[2][y-1] = ".";
////                battleField[2][y] = ".";
////                battleField[3][y] = ".";
////                battleField[4][y] = ".";
////                battleField[4][y-1] = ".";
////            }
////            else if (y == 10)
////            {
////                battleField[2][y-1] = ".";
////                battleField[2][y-2] = ".";
////                battleField[3][y-2] = ".";
////                battleField[4][y-1] = ".";
////                battleField[4][y-2] = ".";
////            }
////            else
////            {
////            battleField[2][y-1] = ".";
////            battleField[2][y-2] = ".";
////            battleField[2][y] = ".";
////            battleField[3][y] = ".";
////            battleField[3][y-2] = ".";
////            battleField[4][y] = ".";
////            battleField[4][y-1] = ".";
////            battleField[4][y-2] = ".";
////            }
////
////            displayBattlefield();
////        patrol--;
////            break;
////        case 'E':
////        case 'e':
////            cout << "Цифра: ";
////            cin >> y;
////            while (y <= 0 || y > 10)
////            {
////                cout << "Ошибка ввода! Попробуйте ещё раз!" << endl;
////                cin >> y;
////            }
////            while (battleField[4][y-1] == "▥")
////            {
////                cout << "Эта клетка уже занята! Попробуйте ещё раз: ";
////                inputValidation(x, y);
////            }
////            while (battleField[4][y-1] == ".")
////            {
////                cout << "Командование доложило, что располагать корабли так близко угрожает их безопасности. Попробуйте ещё раз: ";
////                inputValidation(x, y);
////            }
////            battleField[4][y-1] = "▥";
////
////            if (y == 1)
////            {
////                battleField[3][y-1] = ".";
////                battleField[3][y] = ".";
////                battleField[4][y] = ".";
////                battleField[5][y] = ".";
////                battleField[5][y-1] = ".";
////            }
////            else if (y == 10)
////            {
////                battleField[3][y-1] = ".";
////                battleField[3][y-2] = ".";
////                battleField[4][y-2] = ".";
////                battleField[5][y-1] = ".";
////                battleField[5][y-2] = ".";
////            }
////            else
////            {
////            battleField[3][y-1] = ".";
////            battleField[3][y-2] = ".";
////            battleField[3][y] = ".";
////            battleField[4][y] = ".";
////            battleField[4][y-2] = ".";
////            battleField[5][y] = ".";
////            battleField[5][y-1] = ".";
////            battleField[5][y-2] = ".";
////            }
////
////            displayBattlefield();
////        patrol--;
////            break;
////        case 'F':
////        case 'f':
////            cout << "Цифра: ";
////            cin >> y;
////            while (y <= 0 || y > 10)
////            {
////                cout << "Ошибка ввода! Попробуйте ещё раз!" << endl;
////                cin >> y;
////            }
////            while (battleField[5][y-1] == "▥")
////            {
////                cout << "Эта клетка уже занята! Попробуйте ещё раз: ";
////                inputValidation(x, y);
////            }
////            while (battleField[5][y-1] == ".")
////            {
////                cout << "Командование доложило, что располагать корабли так близко угрожает их безопасности. Попробуйте ещё раз: ";
////                inputValidation(x, y);
////            }
////
////            battleField[5][y-1] = "▥";
////
////            if (y == 1)
////            {
////                battleField[4][y-1] = ".";
////                battleField[4][y] = ".";
////                battleField[5][y] = ".";
////                battleField[6][y] = ".";
////                battleField[6][y-1] = ".";
////            }
////            else if (y == 10)
////            {
////                battleField[4][y-1] = ".";
////                battleField[4][y-2] = ".";
////                battleField[5][y-2] = ".";
////                battleField[6][y-1] = ".";
////                battleField[6][y-2] = ".";
////            }
////            else
////            {
////            battleField[4][y-1] = ".";
////            battleField[4][y-2] = ".";
////            battleField[4][y] = ".";
////            battleField[5][y] = ".";
////            battleField[5][y-2] = ".";
////            battleField[6][y] = ".";
////            battleField[6][y-1] = ".";
////            battleField[6][y-2] = ".";
////            }
////
////            displayBattlefield();
////        patrol--;
////            break;
////        case 'G':
////        case 'g':
////            cout << "Цифра: ";
////            cin >> y;
////            while (y <= 0 || y > 10)
////            {
////                cout << "Ошибка ввода! Попробуйте ещё раз!" << endl;
////                cin >> y;
////            }
////            while (battleField[6][y-1] == "▥")
////            {
////                cout << "Эта клетка уже занята! Попробуйте ещё раз: ";
////                inputValidation(x, y);
////            }
////            while (battleField[6][y-1] == ".")
////            {
////                cout << "Командование доложило, что располагать корабли так близко угрожает их безопасности. Попробуйте ещё раз: ";
////                inputValidation(x, y);
////            }
////
////            battleField[6][y-1] = "▥";
////
////            if (y == 1)
////            {
////                battleField[5][y-1] = ".";
////                battleField[5][y] = ".";
////                battleField[6][y] = ".";
////                battleField[7][y] = ".";
////                battleField[7][y-1] = ".";
////            }
////            else if (y == 10)
////            {
////                battleField[5][y-1] = ".";
////                battleField[5][y-2] = ".";
////                battleField[6][y-2] = ".";
////                battleField[7][y-1] = ".";
////                battleField[7][y-2] = ".";
////            }
////            else
////            {
////            battleField[5][y-1] = ".";
////            battleField[5][y-2] = ".";
////            battleField[5][y] = ".";
////            battleField[6][y] = ".";
////            battleField[6][y-2] = ".";
////            battleField[7][y] = ".";
////            battleField[7][y-1] = ".";
////            battleField[7][y-2] = ".";
////            }
////
////
////            displayBattlefield();
////        patrol--;
////            break;
////        case 'H':
////        case 'h':
////            cout << "Цифра: ";
////            cin >> y;
////            while (y <= 0 || y > 10)
////            {
////                cout << "Ошибка ввода! Попробуйте ещё раз!" << endl;
////                cin >> y;
////            }
////            while (battleField[7][y-1] == "▥")
////            {
////                cout << "Эта клетка уже занята! Попробуйте ещё раз: ";
////                inputValidation(x, y);
////            }
////            while (battleField[7][y-1] == ".")
////            {
////                cout << "Командование доложило, что располагать корабли так близко угрожает их безопасности. Попробуйте ещё раз: ";
////                inputValidation(x, y);
////            }
////
////            battleField[7][y-1] = "▥";
////
////            if (y == 1)
////            {
////                battleField[6][y-1] = ".";
////                battleField[6][y] = ".";
////                battleField[7][y] = ".";
////                battleField[8][y] = ".";
////                battleField[8][y-1] = ".";
////            }
////            else if (y == 10)
////            {
////                battleField[6][y-1] = ".";
////                battleField[6][y-2] = ".";
////                battleField[7][y-2] = ".";
////                battleField[8][y-1] = ".";
////                battleField[8][y-2] = ".";
////            }
////            else
////            {
////            battleField[6][y-1] = ".";
////            battleField[6][y-2] = ".";
////            battleField[6][y] = ".";
////            battleField[7][y] = ".";
////            battleField[7][y-2] = ".";
////            battleField[8][y] = ".";
////            battleField[8][y-1] = ".";
////            battleField[8][y-2] = ".";
////            }
////
////            displayBattlefield();
////        patrol--;
////            break;
////        case 'I':
////        case 'i':
////            cout << "Цифра: ";
////            cin >> y;
////            while (y <= 0 || y > 10)
////            {
////                cout << "Ошибка ввода! Попробуйте ещё раз!" << endl;
////                cin >> y;
////            }
////            while (battleField[8][y-1] == "▥")
////            {
////                cout << "Эта клетка уже занята! Попробуйте ещё раз: ";
////                inputValidation(x, y);
////            }
////            while (battleField[8][y-1] == ".")
////            {
////                cout << "Командование доложило, что располагать корабли так близко угрожает их безопасности. Попробуйте ещё раз: ";
////                inputValidation(x, y);
////            }
////
////            battleField[8][y-1] = "▥";
////
////            if (y == 1)
////            {
////                battleField[7][y-1] = ".";
////                battleField[7][y] = ".";
////                battleField[8][y] = ".";
////                battleField[9][y] = ".";
////                battleField[9][y-1] = ".";
////            }
////            else if (y == 10)
////            {
////                battleField[7][y-1] = ".";
////                battleField[7][y-2] = ".";
////                battleField[8][y-2] = ".";
////                battleField[9][y-1] = ".";
////                battleField[9][y-2] = ".";
////            }
////            else
////            {
////            battleField[7][y-1] = ".";
////            battleField[7][y-2] = ".";
////            battleField[7][y] = ".";
////            battleField[8][y] = ".";
////            battleField[8][y-2] = ".";
////            battleField[9][y] = ".";
////            battleField[9][y-1] = ".";
////            battleField[9][y-2] = ".";
////            }
////
////            displayBattlefield();
////        patrol--;
////            break;
////        case 'J':
////        case 'j':
////            cout << "Цифра: ";
////            cin >> y;
////            while (y <= 0 || y > 10)
////            {
////                cout << "Ошибка ввода! Попробуйте ещё раз!" << endl;
////                cin >> y;
////            }
////            while (battleField[9][y-1] == "▥")
////            {
////                cout << "Эта клетка уже занята! Попробуйте ещё раз: ";
////                inputValidation(x, y);
////            }
////            while (battleField[9][y-1] == ".")
////            {
////                cout << "Командование доложило, что располагать корабли так близко угрожает их безопасности. Попробуйте ещё раз: ";
////                inputValidation(x, y);
////            }
////
////            battleField[9][y-1] = "▥";
////
////            if (y == 1)
////            {
////                battleField[9][y] = ".";
////                battleField[8][y-1] = ".";
////                battleField[8][y] = ".";
////            }
////            else if (y == 10)
////            {
////                battleField[9][y-2] = ".";
////                battleField[8][y-1] = ".";
////                battleField[8][y-2] = ".";
////            }
////            else
////            {
////                battleField[9][y] = ".";
////                battleField[9][y-2] = ".";
////                battleField[8][y] = ".";
////                battleField[8][y-1] = ".";
////                battleField[8][y-2] = ".";
////            }
////
////            displayBattlefield();
////        patrol--;
////            break;
////    }
////    } while (patrol != 0);
//
//
//if (y < 4)
//  {
//
//     battleField1[x1][y-1] = "◇";
//    break;
//   }
//
//if ((battleField1[x1][y-2] != "▥" && battleField1[x1][y-3] != "▥" && battleField1[x1][y-4] != "▥") && (battleField1[x1][y-2] != "." && battleField1[x1][y-3] != "." && battleField1[x1][y-4] != "."))
// {
//        battleField1[x1][y-2] = "▥";
//        battleField1[x1][y-3] = "▥";
//        battleField1[x1][y-4] = "▥";
//}
//   else
//    {
//      battleField1[x1][y-1] = "◇";
//        break;
//    }
//
//          if (y == 10 && x1 > 0 && x1 < 9)
//          {
//              battleField1[x1+1][y-1] = ".";
//              battleField1[x1+1][y-2] = ".";
//              battleField1[x1+1][y-3] = ".";
//              battleField1[x1+1][y-4] = ".";
//              battleField1[x1+1][y-5] = ".";
//              battleField1[x1][y-5] = ".";
//
//              battleField1[x1-1][y-1] = ".";
//              battleField1[x1-1][y-2] = ".";
//              battleField1[x1-1][y-3] = ".";
//              battleField1[x1-1][y-4] = ".";
//              battleField1[x1-1][y-5] = ".";
//
//
//          }
//          else if (y == 10 && x1 == 0)
//          {
//          battleField1[x1+1][y-1] = ".";
//          battleField1[x1+1][y-2] = ".";
//          battleField1[x1+1][y-3] = ".";
//          battleField1[x1+1][y-4] = ".";
//          battleField1[x1+1][y-5] = ".";
//          battleField1[x1][y-5] = ".";
//          }
//
//          else if (y == 10 && x1 == 9)
//          {
//          battleField1[x1-1][y-1] = ".";
//          battleField1[x1-1][y-2] = ".";
//          battleField1[x1-1][y-3] = ".";
//          battleField1[x1-1][y-4] = ".";
//          battleField1[x1-1][y-5] = ".";
//          battleField1[x1][y-5] = ".";
//          }
//
//          else if (y > 4 && y < 10 && x1 == 9)
//          {
//              battleField1[x1][y] = ".";
//              battleField1[x1-1][y] = ".";
//              battleField1[x1-1][y-1] = ".";
//              battleField1[x1-1][y-2] = ".";
//              battleField1[x1-1][y-3] = ".";
//              battleField1[x1-1][y-4] = ".";
//              battleField1[x1-1][y-5] = ".";
//              battleField1[x1][y-5] = ".";
//
//          }
//              else if (y == 4 && x1 == 9)
//              {
//                  battleField1[x1-1][y-1] = ".";
//                  battleField1[x1-1][y-2] = ".";
//                  battleField1[x1-1][y-3] = ".";
//                  battleField1[x1-1][y-4] = ".";
//                  battleField1[x1-1][y] = ".";
//                  battleField1[x1][y] = ".";
//
//              }
//              else if (y == 4 && x1 > 0 && x1 < 9)
//              {
//                  battleField1[x1][y] = ".";
//                  battleField1[x1-1][y] = ".";
//                  battleField1[x1-1][y-1] = ".";
//                  battleField1[x1-1][y-2] = ".";
//                  battleField1[x1-1][y-3] = ".";
//                  battleField1[x1-1][y-4] = ".";
//                  battleField1[x1+1][y] = ".";
//                  battleField1[x1+1][y-1] = ".";
//                  battleField1[x1+1][y-2] = ".";
//                  battleField1[x1+1][y-3] = ".";
//                  battleField1[x1+1][y-4] = ".";
//              }
//              else if (y == 4 && x1 == 0)
//              {
//                  battleField1[x1+1][y-1] = ".";
//                  battleField1[x1+1][y-2] = ".";
//                  battleField1[x1+1][y-3] = ".";
//                  battleField1[x1+1][y-4] = ".";
//                  battleField1[x1+1][y] = ".";
//                  battleField1[x1][y] = ".";
//              }
//              else if (x1 == 0 && y > 4 && y < 10)
//              {
//                  battleField1[x1][y] = ".";
//                  battleField1[x1+1][y] = ".";
//                  battleField1[x1+1][y-1] = ".";
//                  battleField1[x1+1][y-2] = ".";
//                  battleField1[x1+1][y-3] = ".";
//                  battleField1[x1+1][y-4] = ".";
//                  battleField1[x1+1][y-5] = ".";
//                  battleField1[x1][y-5] = ".";
//
//              }
//              else
//              {
//                  battleField1[x1][y] = ".";
//                  battleField1[x1-1][y] = ".";
//                  battleField1[x1-1][y-1] = ".";
//                  battleField1[x1-1][y-2] = ".";
//                  battleField1[x1-1][y-3] = ".";
//                  battleField1[x1-1][y-4] = ".";
//                  battleField1[x1-1][y-5] = ".";
//                  battleField1[x1][y-5] = ".";
//                  battleField1[x1+1][y-5] = ".";
//                  battleField1[x1+1][y-4] = ".";
//                  battleField1[x1+1][y-3] = ".";
//                  battleField1[x1+1][y-2] = ".";
//                  battleField1[x1+1][y-1] = ".";
//                  battleField1[x1+1][y] = ".";
//              }
//
//
//carrier--;
//break;


//cout << R"(
//Выберите вариант расположения корабля:
//1. -> ▥ ▥ ▥  Горизонтально вправо
//
//2. ▥ ▥ ▥ <-  Горизонтально влево
//
//3. ^  ▥      Вертикально вверх
//|  ▥
//▥
//
//4. |  ▥    Вертикально вниз
//V  ▥
//▥
//)";
//cin >> choice;
