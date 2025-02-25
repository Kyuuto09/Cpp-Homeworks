#include <iostream>
#include <Windows.h>
#include <conio.h>
#include "Console.h"
#include <chrono>
using namespace std;

static HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

enum Direction { UP, DOWN, LEFT, RIGHT };

void gotoxy(int x, int y)
{
    COORD pos = { x, y };
    HANDLE houtput = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(houtput, pos);
}

void hideCursor(bool showFlag) {
    HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = showFlag;
    SetConsoleCursorInfo(out, &cursorInfo);
}

class Hero
{
    int hp;
    int h, w;
    int points;
    COORD position;
    char symbol;
    string name;
    Direction dir;

    void Print(char filler)
    {
        for (int y = 0; y < h; y++)
        {
            gotoxy(position.X, position.Y + y);
            for (int x = 0; x < w; x++)
            {
                cout << filler;
            }
            cout << endl;
        }
    }

public:
    Hero() : hp(100), h(1), w(1), position({ 0,0 }), symbol('#'), name("No name"), dir(RIGHT), points(0) {}
    Hero(string name, int h, int w, char s) : hp(100), h(h), w(w), position({ 0,0 }), symbol(s), name(name), dir(RIGHT), points(0)
    {
        h > 1 ? this->h = h : this->h = 1;
        this->w = w > 0 ? w : 1;
    }

    void ShowInfo() const
    {
        gotoxy(0, 0);
        cout << "========= Player [ " << name << " ] == HP: [ " << hp << " ] == Points: [ " << points << " ] =========" << endl;
    }

    void SetPosition(int x, int y)
    {
        position.X = x >= 0 ? x : 0;
        position.Y = y >= 0 ? y : 0;
    }

    void Move()
    {
        bool isMoved = false;
        switch (dir)
        {
        case UP: isMoved = MoveUp(); break;
        case DOWN: isMoved = MoveDown(); break;
        case LEFT: isMoved = MoveLeft(); break;
        case RIGHT: isMoved = MoveRight(); break;
        }
        if (isMoved) CheckCollectible();
    }

    void MarkHero()
    {
        SetConsoleTextAttribute(hConsole, ConsoleColors::RED);
        Print(symbol);
    }

    void ChangeDirection(Direction dir)
    {
        this->dir = dir;
    }

    bool MoveRight()
    {
        if (IsValidPosition(position.X + 1, position.Y))
        {
            ClearHero();
            position.X++;
            PrintHero();
            return true;
        }
        return false;
    }

    bool MoveLeft()
    {
        if (IsValidPosition(position.X - 1, position.Y))
        {
            ClearHero();
            position.X--;
            PrintHero();
            return true;
        }
        return false;
    }

    bool MoveUp()
    {
        if (IsValidPosition(position.X, position.Y - 1))
        {
            ClearHero();
            position.Y--;
            PrintHero();
            return true;
        }
        return false;
    }

    bool MoveDown()
    {
        if (IsValidPosition(position.X, position.Y + 1))
        {
            ClearHero();
            position.Y++;
            PrintHero();
            return true;
        }
        return false;
    }

    void PrintHero()
    {
        SetConsoleTextAttribute(hConsole, ConsoleColors::GREEN);
        Print(symbol);
    }

    void ClearHero()
    {
        SetConsoleTextAttribute(hConsole, ConsoleColors::BLACK);
        Print(' ');
    }

    bool IsValidPosition(int x, int y)
    {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        GetConsoleScreenBufferInfo(hConsole, &csbi);
        int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

        return x >= 0 && x + w <= consoleWidth && y >= 0 && y + h <= consoleHeight;
    }

	// Collectibles
    void CheckCollectible()
    {
        HANDLE hInput = GetStdHandle(STD_INPUT_HANDLE);
        INPUT_RECORD ir;
        DWORD events;
        PeekConsoleInput(hInput, &ir, 1, &events);

        if ((position.X == 15 && position.Y == 15) ||
            (position.X == 20 && position.Y == 10) ||
            (position.X == 25 && position.Y == 12))
        {
            points += 10;
            ShowInfo();  
        }
    }
};

int main()
{
    hideCursor(false);
    Hero hero("King", 1, 1, char(219));
    hero.ShowInfo();

	// Collectibles
    SetConsoleTextAttribute(hConsole, ConsoleColors::YELLOW);
    gotoxy(15, 15); cout << "$";
    gotoxy(20, 10); cout << "$";
    gotoxy(25, 12); cout << "$";

    hero.SetPosition(10, 10);
    hero.PrintHero();

    time_t interval = 500;
    time_t start = clock();

    while (true)
    {
        if (clock() >= start + interval)
        {
            hero.Move(); 
            start = clock();
        }

        if (_kbhit())
        {
            int key = _getch();
            if (key == 224)
            {
                key = _getch();
                switch (key)
                {
                case 77: hero.ChangeDirection(RIGHT); break;
                case 75: hero.ChangeDirection(LEFT); break;
                case 72: hero.ChangeDirection(UP); break;
                case 80: hero.ChangeDirection(DOWN); break;
                }
            }
        }
    }
}