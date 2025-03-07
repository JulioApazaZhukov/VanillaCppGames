#include "../BasicHeader.hpp"

void border (void);
void snakeMovement (void);
char detectArrowKey (void);

const char snakebody = char(219);//char(254);

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

char detectArrowKey ()
{
    unsigned char ch1 = _getch();
    if (ch1 == 224) {
        unsigned char ch2 = _getch();
        switch (ch2) {
            case 72: return 'u'; break;
            case 80: return 'd'; break;
            case 75: return 'l'; break;
            case 77: return 'r'; break;
        }
    }
    return '0';
}

void snakeMovement ()
{
    int x = 10;
    int y = 10;
    gotoxy(x,y);
    char direction = '0';
    while (true)
    {
        if (_kbhit())
        {
            char newDirection = detectArrowKey();
            if (newDirection != '0')
            {
                direction = newDirection;
            }
        }
        switch (direction) {
            case 'u':
                gotoxy(x,y--); cout << snakebody; break;
            case 'd':
                gotoxy(x,y++); cout << snakebody; break;
            case 'l':
                gotoxy(x--,y); cout << snakebody; break;
            case 'r':
                gotoxy(x++,y); cout << snakebody; break;
            default:
                break;
        }
        Sleep(100);
    }
}

int main ()
{
    CONSOLE_CURSOR_INFO cci = { 100, FALSE };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
    
    consoleStyle();
    border();

    snakeMovement();

    return 0;
}