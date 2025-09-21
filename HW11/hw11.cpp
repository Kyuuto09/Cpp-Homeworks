#include <iostream>
#include <cstring>
using namespace std;

// Task 1:
void removeCharAtPosition(char* str, int pos) {
    int len = strlen(str);
    if (pos < 0 || pos >= len) return;
    for (int i = pos; i < len; i++) str[i] = str[i + 1];
}

// Task 2:
void removeAllOccurrences(char* str, char ch) {
    int len = strlen(str);
    int j = 0;
    for (int i = 0; i < len; i++) {
        if (str[i] != ch) str[j++] = str[i];
    }
    str[j] = '\0';
}

// Task 3:
void insertCharAtPosition(char* str, int pos, char ch) {
    int len = strlen(str);
    if (pos < 0 || pos > len) return;
    for (int i = len; i >= pos; i--) str[i + 1] = str[i];
    str[pos] = ch;
}

// Task 4:
void replaceDotsWithExclamation(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == '.') str[i] = '!';
    }
}

// Task 5:
int countOccurrences(char* str, char ch) {
    int count = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (str[i] == ch) count++;
    }
    return count;
}

// Task 6:
void countCharacters(char* str, int& letters, int& digits, int& others) {
    letters = digits = others = 0;
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (isalpha(str[i])) letters++;
        else if (isdigit(str[i])) digits++;
        else others++;
    }
}

int main() {
    char str[100];
    cout << "Enter a string: ";
    cin.getline(str, 100);

    // Task 1
    int pos;
    cout << "Enter position to remove: ";
    cin >> pos;
    removeCharAtPosition(str, pos);
    cout << "After removing character at position " << pos << ": " << str << endl;

    // Task 2
    char ch;
    cout << "Enter character to remove: ";
    cin >> ch;
    removeAllOccurrences(str, ch);
    cout << "After removing all occurrences of '" << ch << "': " << str << endl;

    // Task 3
    cout << "Enter position to insert and character to insert: ";
    cin >> pos >> ch;
    insertCharAtPosition(str, pos, ch);
    cout << "After inserting '" << ch << "' at position " << pos << ": " << str << endl;

    // Task 4
    replaceDotsWithExclamation(str);
    cout << "After replacing dots with exclamation marks: " << str << endl;

    // Task 5
    cout << "Enter character to count: ";
    cin >> ch;
    int count = countOccurrences(str, ch);
    cout << "The character '" << ch << "' appears " << count << " times in the string." << endl;

    // Task 6
    int letters, digits, others;
    countCharacters(str, letters, digits, others);
    cout << "Letters: " << letters << ", Digits: " << digits << ", Others: " << others << endl;

}
