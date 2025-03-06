#include <windows.h>
#include <iostream>
#include <chrono>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void consoleStyle (void)
{
    system("color 0A");
    system("mode con: cols=101 lines=31");
}

void gotoxy (int x, int y)
{
    COORD coordinate;
    coordinate.X = x;
    coordinate.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinate);
}