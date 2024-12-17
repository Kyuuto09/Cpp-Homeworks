#include <iostream>
#include <stack> 
#include <string>

using namespace std;

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
        (open == '{' && close == '}') ||
        (open == '[' && close == ']');
}

bool checkBrackets(const string& str) {
    stack<char> s;
    for (char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty() || !isMatchingPair(s.top(), ch)) {
                return false;
            }
            s.pop();
        }
        else if (ch == ';') {
            break;
        }
    }
	return s.empty(); // if stack is empt then all brackets are matched
}

int main() {
    string input;
    getline(cin, input);
    if (checkBrackets(input)) {
        cout << "The string is correct." << endl;
    }
    else {
        cout << "The string is incorrect." << endl;
    }
}
