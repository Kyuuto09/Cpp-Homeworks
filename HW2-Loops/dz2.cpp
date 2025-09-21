#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

/* 
// 111111111111111111111111111111

void drawLine(char symbol, int length, bool vertical, int speed) {
    for (int i = 0; i < length; ++i) {
        if (vertical) {
            cout << symbol << endl;
        }
        else {
            cout << symbol;
        }
        if (speed == 1) {
            this_thread::sleep_for(chrono::milliseconds(100));
        }
        else if (speed == 2) {
            this_thread::sleep_for(chrono::milliseconds(500));
        }
        else if (speed == 3) {
            this_thread::sleep_for(chrono::milliseconds(1000));
        }
    }
    if (!vertical) {
        cout << endl;
    }
}

int main() {
    char symbol;
    int length, direction, speed;

    cout << "Enter the symbol for the line: ";
    cin >> symbol;

    cout << "Enter the length of the line: ";
    cin >> length;

    cout << "Choose the direction of the line:\n";
    cout << "1. Vertical\n";
    cout << "2. Horizontal\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> direction;

    cout << "Choose the output speed:\n";
    cout << "1. Fast\n";
    cout << "2. Normal\n";
    cout << "3. Slow\n";
    cout << "Enter your choice (1, 2, or 3): ";
    cin >> speed;

    bool vertical = (direction == 1);

    drawLine(symbol, length, vertical, speed);

    return 0;
}
*/ 


//22222222222222222222222222222222222
int rollDice() {
    return rand() % 6 + 1;
}

int playTurn() {
    int total = 0;
    cout << "Rolling dice..." << endl;
    for (int i = 0; i < 3; ++i) {
        int die1 = rollDice();
        int die2 = rollDice();
        int roundScore = die1 + die2;
        total += roundScore;
        cout << "Roll " << i + 1 << ": " << die1 << " + " << die2 << " = " << roundScore << endl;
    }
    cout << "Total score for this turn: " << total << endl;
    return total;
}

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    cout << "Welcome to the Dice Game!" << endl;
    cout << "You and the computer will each roll two dice three times." << endl;
    cout << "The player with the highest total score wins!" << endl;

    int userScore = playTurn();
    cout << "Your total score: " << userScore << endl << endl;

    int computerScore = playTurn();
    cout << "Computer's total score: " << computerScore << endl << endl;

    cout << "Final Scores:" << endl;
    cout << "You: " << userScore << endl;
    cout << "Computer: " << computerScore << endl;

    if (userScore > computerScore) {
        cout << "Congratulations! You win!" << endl;
    }
    else if (userScore < computerScore) {
        cout << "Computer wins! Better luck next time." << endl;
    }
    else {
        cout << "It's a tie!" << endl;
    }

    return 0;
}
