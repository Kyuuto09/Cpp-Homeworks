#include <iostream>
#include <vector>
#include <string>
#include <chrono> // for animating exit
#include <thread> // for animating exit

using namespace std;

void addTask(vector<string>& tasks) {
    cout << "------------------" << endl;
    cout << "Enter a task: ";
    string task;
    getline(cin, task);
    tasks.push_back(task);
    cout << "------------------" << endl;
}

void viewTask(const vector<string>& tasks) {
    cout << "------------------" << endl;
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
    }
    else {
        for (size_t i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }
    cout << "------------------" << endl;
}

void deleteTask(vector<string>& tasks) {
    cout << "------------------" << endl;
    cout << "Enter the task number to delete: ";
    size_t taskNumber;
    cin >> taskNumber;
    cin.ignore();
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task deleted successfully." << endl;
    }
    else {
        cout << "Invalid task number." << endl;
    }
    cout << "------------------" << endl;
}

void markTaskDone(vector<string>& tasks) {
    cout << "------------------" << endl;
    cout << "Enter the task number to mark as done: ";
    size_t taskNumber;
    cin >> taskNumber;
    cin.ignore();
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1] += " [DONE]";
        cout << "Task marked as done." << endl;
    }
    else {
        cout << "Invalid task number." << endl;
    }
    cout << "------------------" << endl;
}

void animateExit() {
    cout << "Exiting";
    for (int i = 0; i < 3; ++i) {
        this_thread::sleep_for(chrono::milliseconds(500));
        cout << ".";
    }
    cout << endl;
}

int main() {
    vector<string> tasks;
    int choice;

    do {
        cout << "------------------" << endl;
        cout << "1. Add a task" << endl;
        cout << "2. View tasks" << endl;
        cout << "3. Delete a task" << endl;
        cout << "4. Mark a task as done" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        cout << "------------------" << endl;

        switch (choice) {
        case 1: addTask(tasks); break;
        case 2: viewTask(tasks); break;
        case 3: deleteTask(tasks); break;
        case 4: markTaskDone(tasks); break;
        case 5: animateExit(); break;
        default: cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    system("pause");
}
