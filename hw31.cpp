#include <iostream>
#include <map>
#include <windows.h>
#include <list>
#include <string>
using namespace std;

struct Student
{
    string id;
    string name;
};

map<string, Student> students;
multimap<string, int> grades;

void AddStudent()
{
    string id, name;
    cout << "Enter id : ";
    getline(cin, id);
    cout << "Enter name : ";
    getline(cin, name);
    students[id] = { id, name };
    cout << "Student was added" << endl;
}

void AddMark()
{
    string id;
    int mark;
    cout << "Enter id of student : ";
    getline(cin, id);
    if (students.find(id) == students.end())
    {
        cout << "Student not found" << endl;
        return;
    }
    cout << "Enter mark : ";
    cin >> mark;
    cin.ignore();
    grades.insert(make_pair(id, mark));
    cout << "Mark was added" << endl;
}

void ShowMarks()
{
    string id;
    cout << "Enter id of student : ";
    getline(cin, id);
    if (students.find(id) == students.end())
    {
        cout << "Student not found" << endl;
        return;
    }
    cout << "Student : " << students[id].name << " : ";
    auto range = grades.equal_range(id);
    for (auto it = range.first; it != range.second; ++it)
    {
        cout << it->second << " ";
    }
    cout << endl;
}

void ShowStudents()
{
    for (auto st : students)
    {
        cout << "ID : " << st.second.id << " Name : " << st.second.name << endl;
    }
}

// AVG Grade
float CalculateAverageGrade(string id)
{
    if (students.find(id) == students.end())
    {
        cout << "Student not found" << endl;
        return 0.0f;
    }

    auto range = grades.equal_range(id);
    float sum = 0;
    int count = 0;

    for (auto it = range.first; it != range.second; ++it)
    {
        sum += it->second;
        count++;
    }

    return count > 0 ? sum / count : 0.0f;
}

// MENU
void ShowMenu()
{
    cout << "\nStudent Grade Management System\n";
    cout << "1. Add new student\n";
    cout << "2. Add grade for student\n";
    cout << "3. Show student's grades\n";
    cout << "4. Show all students\n";
    cout << "5. Calculate average grade\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);  
    SetConsoleCP(CP_UTF8);       

    int choice;
    do {
        ShowMenu();
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            AddStudent();
            break;
        case 2:
            AddMark();
            break;
        case 3:
            ShowMarks();
            break;
        case 4:
            ShowStudents();
            break;
        case 5:
        {
            string id;
            cout << "Enter id of student : ";
            getline(cin, id);
            float avg = CalculateAverageGrade(id);
            if (avg > 0)
                cout << "Average grade for " << students[id].name << " is: " << avg << endl;
            break;
        }
        case 0:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 0);

}