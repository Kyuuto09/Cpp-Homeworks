#include <iostream>
#include <cctype>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

// 1. 
int countLettersAndDigits(const string& str) {
    int count = 0;
    for (char c : str) {
        if (isalnum(c)) count++;
    }
    return count;
}

// 2.
bool isPalindrome(string str) {
    string filtered;
    for (char c : str) {
        if (isalnum(c)) filtered += tolower(c);
    }
    string reversed = filtered;
    reverse(reversed.begin(), reversed.end());
    return filtered == reversed;
}

// 3. 
int countWords(const string& str) {
    stringstream ss(str);
    string word;
    int count = 0;
    while (ss >> word) count++;
    return count;
}

// 4. 
string reverseString(const string& str) {
    string reversed;
    for (int i = str.length() - 1; i >= 0; i--) {
        reversed += str[i];
    }
    return reversed;
}

// 5. 
int countCharOccurrences(const string& str, char ch) {
    int count = 0;
    for (char c : str) {
        if (c == ch) count++;
    }
    return count;
}

// 6. 
string replaceSubstring(string str, const string& oldWord, const string& newWord) {
    size_t pos = 0;
    while ((pos = str.find(oldWord, pos)) != string::npos) {
        str.replace(pos, oldWord.length(), newWord);
        pos += newWord.length();
    }
    return str;
}

// 7. 
string extractDomain(const string& email) {
    size_t atPos = email.find('@');
    if (atPos == string::npos) return "Invalid email";
    return email.substr(atPos + 1);
}

// 8. 
string removeDuplicates(const string& str) {
    string result;
    for (char c : str) {
        if (result.find(c) == string::npos) result += c;
    }
    return result;
}

// 9. 
string convertDateFormat(const string& date) {
    if (date.length() != 10 || date[2] != '.' || date[5] != '.') return "Invalid date";
    return date.substr(6, 4) + "-" + date.substr(3, 2) + "-" + date.substr(0, 2);
}

// 10. 
bool areAnagrams(string str1, string str2) {
    str1.erase(remove_if(str1.begin(), str1.end(), ::isspace), str1.end());
    str2.erase(remove_if(str2.begin(), str2.end(), ::isspace), str2.end());

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    return str1 == str2;
}

int main() {
    cout << countLettersAndDigits("Hello, World! 123") << endl;
    cout << isPalindrome("A man, a plan, a canal, a man!") << endl;
    cout << countWords("  Hello   world !  ") << endl;
    cout << reverseString("Hello") << endl;
    cout << countCharOccurrences("banana", 'a') << endl;
    cout << replaceSubstring("I love cats", "cats", "dogs") << endl;
    cout << extractDomain("test@gmail.com") << endl;
    cout << removeDuplicates("banana") << endl;
    cout << convertDateFormat("12.12.2024") << endl;
    cout << areAnagrams("listen", "silent") << endl;
}
