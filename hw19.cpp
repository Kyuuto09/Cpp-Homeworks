#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
    char* _chars;
    size_t _length;
    static int _objectCount;

public:
    String() : String(80) {}

    String(size_t size) {
        _length = size;
        _chars = new char[_length + 1];
        memset(_chars, 0, _length + 1);
        _objectCount++;
    }

    String(const char* initialString) {
        _length = strlen(initialString);
        _chars = new char[_length + 1];
        strcpy_s(_chars, _length + 1, initialString);
        _objectCount++;
    }

    ~String() {
        delete[] _chars;
        _objectCount--;
    }

    void Input() {
        cout << "Enter a string: ";
        char buffer[1000];
        cin.getline(buffer, 1000);
        _length = strlen(buffer);
        delete[] _chars;
        _chars = new char[_length + 1];
        strcpy_s(_chars, _length + 1, buffer);
    }

    void Output() const {
        cout << _chars << endl;
    }

    static int GetObjectCount() {
        return _objectCount;
    }
};

int String::_objectCount = 0;

int main() {
    String str1;
    str1.Output();

    String str2(10);
    str2.Output();

    String str3("hello, world!");
    str3.Output();

    str1.Input();
    str1.Output();

    cout << "number of string objects: " << String::GetObjectCount() << endl;
}