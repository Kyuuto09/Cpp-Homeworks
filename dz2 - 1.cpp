#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

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
    srand(static_cast<unsigned int>(time(0))); //random number

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
