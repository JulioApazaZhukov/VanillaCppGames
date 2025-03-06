#include "../BasicHeader.hpp"

void border (void);
void snakeMovement (void);

const char snakebody = char(254);

void border ()
{
    for(int i = 1; i < 27; i++){
        gotoxy(1,i); cout << char(186);
        gotoxy(99,i); cout << char(186);
    }
    for(int i = 2; i < 99; i++){
        gotoxy(i,0); cout << char(205);
        gotoxy(i,27); cout << char(205);
    }
    gotoxy(1,0);    cout << char(201);
    gotoxy(1,27);   cout << char(200);
    gotoxy(99,0);   cout << char(187);
    gotoxy(99,27);  cout << char(188);
}

void snakeMovement ()
{
    for (int i = 5; i < 85; i++){
        Sleep(10);
        gotoxy(i,15); cout << snakebody;
    }
}

int main ()
{
    consoleStyle();
    border();

    snakeMovement();

    return 0;
}