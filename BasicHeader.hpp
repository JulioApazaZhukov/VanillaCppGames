#include <windows.h>
#include <iostream>
#include <chrono>
#include <conio.h>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::pair;

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