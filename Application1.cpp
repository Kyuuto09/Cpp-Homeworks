#include <iostream>
#include <cctype>
using namespace std; 

int main()
{	
	//1 
	/* 
	char symbol;
	cout << "Enter a character: ";
	cin >> symbol;

	if (isalpha(symbol))
	{
		cout << "It's a letter." << endl;
	}
	else if (isdigit(symbol))
	{
		cout << "It's a digit." << endl;
	}
	else if (ispunct(symbol))
	{
		cout << "It's a punctuation." << endl;
	}
	else
	{
		cout << "It's a special character." << endl;
	}
	*/


	//2
	/*
    const float kyivstar = 3.5;
    const float vodafone = 4.5;
    const float lifecell = 2.5;
    int minutes;
    int operatorFrom, operatorTo;
    float costPerMinute;

    cout << "How long is your call going to take (minutes): ";
    cin >> minutes;

    cout << "Select your operator (1 - Kyivstar, 2 - Vodafone, 3 - Lifecell): ";
    cin >> operatorFrom;

    cout << "Select the operator you're calling to (1 - Kyivstar, 2 - Vodafone, 3 - Lifecell): ";
    cin >> operatorTo;

    if (operatorFrom == 1 && operatorTo == 1) {
        costPerMinute = kyivstar;
    }
    else if (operatorFrom == 1 && operatorTo == 2) {
        costPerMinute = kyivstar + vodafone;
    }
    else if (operatorFrom == 1 && operatorTo == 3) {
        costPerMinute = kyivstar + lifecell;
    }
    else if (operatorFrom == 2 && operatorTo == 1) {
        costPerMinute = vodafone + kyivstar;
    }
    else if (operatorFrom == 2 && operatorTo == 2) {
        costPerMinute = vodafone;
    }
    else if (operatorFrom == 2 && operatorTo == 3) {
        costPerMinute = vodafone + lifecell;
    }
    else if (operatorFrom == 3 && operatorTo == 1) {
        costPerMinute = lifecell + kyivstar;
    }
    else if (operatorFrom == 3 && operatorTo == 2) {
        costPerMinute = lifecell + vodafone;
    }
    else if (operatorFrom == 3 && operatorTo == 3) {
        costPerMinute = lifecell;
    }
    else {
        cout << "Invalid operator selection!" << endl;
        return 1;
    }

    float totalCost = minutes * costPerMinute;

    cout << "The cost of your call is: " << totalCost << " UAH" << endl; 
	*/

	//3
    int choice;
    const int salary_per_100_lines = 50;
    const int penalty_per_3_delays = 20;

    do {
        cout << "\nMenu:\n";
        cout << "1. Enter desired income and number of delays. Calculate how many lines of code to write.\n";
        cout << "2. Enter lines of code and desired income. Calculate how many times you can be late.\n";
        cout << "3. Enter lines of code and number of delays. Calculate how much money will be paid.\n";
        cout << "4. Exit the program.\n";
        cout << "Choose an action: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            int desired_income, delays;
            cout << "Enter desired income: ";
            cin >> desired_income;
            cout << "Enter number of delays: ";
            cin >> delays;

            int penalty = (delays / 3) * penalty_per_3_delays;
            int effective_income = desired_income + penalty;
            int lines_needed = (effective_income * 100) / salary_per_100_lines;

            cout << "You need to write " << lines_needed << " lines of code.\n";
            break;
        }

        case 2: {
            int lines_written, desired_income;
            cout << "Enter lines of code written: ";
            cin >> lines_written;
            cout << "Enter desired income: ";
            cin >> desired_income;

            int total_income = (lines_written / 100) * salary_per_100_lines;
            int max_penalties = total_income - desired_income;

            if (max_penalties < 0) {
                cout << "Desired income exceeds potential earnings.\n";
            }
            else {
                int max_delays = (max_penalties / penalty_per_3_delays) * 3;
                cout << "You can be late up to " << max_delays << " times.\n";
            }
            break;
        }

        case 3: {
            int lines_written, delays;
            cout << "Enter lines of code written: ";
            cin >> lines_written;
            cout << "Enter number of delays: ";
            cin >> delays;

            int total_income = (lines_written / 100) * salary_per_100_lines;
            int penalty = (delays / 3) * penalty_per_3_delays;
            int final_income = total_income - penalty;

            if (final_income > 0) {
                cout << "Vasya will be paid " << final_income << "$.\n";
            }
            else {
                cout << "Vasya will not be paid.\n";
            }
            break;
        }

        case 4:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice, please try again.\n";
            break;
        }
    } while (choice != 4);
}