#include "../BasicHeader.hpp"

void border (void);
void snakeMovement (void);
char detectArrowKey (void);
void generateFood (void);

const char snakebody = char(219);       //char(254);
const char emptySpace = ' ';

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


void snakeMovement()
{
    int x = 10, y = 10;
    char direction = 'r';
    vector<pair<int, int>> snake;
    size_t maxLength = 10; 
    generateFood();

    while (true)
    {
        char newDirection = detectArrowKey();
        if (newDirection != '0' && (
            (newDirection == 'u' && direction != 'd') ||
            (newDirection == 'd' && direction != 'u') ||
            (newDirection == 'l' && direction != 'r') ||
            (newDirection == 'r' && direction != 'l')))
        {
            direction = newDirection;
        }

        switch (direction) {
            case 'u': y--; break;
            case 'd': y++; break;
            case 'l': x--; break;
            case 'r': x++; break;
        }

        snake.push_back({x, y});
        gotoxy(x, y); cout << snakebody;

        if (snake.size() > maxLength) {
            auto tail = snake.front();
            gotoxy(tail.first, tail.second); cout << emptySpace;
            snake.erase(snake.begin()); 
        }

        Sleep(100);
    }
}
void generateFood()
{
    int foodX = rand() % 98 + 2; 
    int foodY = rand() % 26 + 1; 
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED | FOREGROUND_INTENSITY);
    gotoxy(foodX, foodY); cout << char(254);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN | FOREGROUND_INTENSITY);
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