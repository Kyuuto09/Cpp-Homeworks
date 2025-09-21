#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <functional>
#include <map>
#include <memory>
#include <chrono>

using namespace std;

int main() {
    // Task 1
    int x = 10;
    auto printX = [=]() { cout << "x = " << x << endl; };
    printX();
    x = 20;
    printX();

    // Task 2
    x = 10;
    auto incrementX = [&]() { x++; };
    incrementX();
    cout << "x after increment: " << x << endl;

    // Task 3
    int a = 5, b = 7;
    auto sumAB = [a, b]() { return a + b; };
    cout << "Sum of a and b: " << sumAB() << endl;

    // Task 4
    a = 3; b = 4; x = 10;
    auto lambda1 = [=]() { cout << "a = " << a << ", b = " << b << ", x = " << x << endl; };
    auto lambda2 = [&, x]() { cout << "a = " << a << ", b = " << b << ", x = " << x << endl; };
    lambda1();
    lambda2();

    // Task 5
    int count = 0;
    auto incrementCount = [count]() mutable { count++; cout << "count inside lambda: " << count << endl; };
    incrementCount();
    cout << "count after lambda: " << count << endl;

    // Task 6
    vector<int> numbers = { 1, 2, 3, 4, 5 };
    for_each(numbers.begin(), numbers.end(), [&](int& n) { n *= 2; });
    for (int n : numbers) cout << n << " ";
    cout << endl;

    // Task 7
    vector<int> values = { 3, 1, 4, 1, 5, 9, 2 };
    sort(values.begin(), values.end(), [=](int a, int b) { return a > b; });
    for (int v : values) cout << v << " ";
    cout << endl;

    // Task 8
    numbers = { 10, 20, 30, 40, 50, 60 };
    int threshold;
    cout << "Enter threshold: ";
    cin >> threshold;
    numbers.erase(remove_if(numbers.begin(), numbers.end(), [=](int n) { return n < threshold; }), numbers.end());
    for (int n : numbers) cout << n << " ";
    cout << endl;

    // Task 9
    values = { 1, 2, 3, 4, 5 };
    int multiplier;
    cout << "Enter multiplier: ";
    cin >> multiplier;
    transform(values.begin(), values.end(), values.begin(), [=](int n) { return n * multiplier; });
    for (int v : values) cout << v << " ";
    cout << endl;

    // Task 10
    string message = "Thread running";
    thread t([=]() {
        for (int i = 1; i <= 5; ++i) {
            cout << message << ": " << i << endl;
            this_thread::sleep_for(chrono::milliseconds(100));
        }
        });
    t.join();

    // Task 11
    class MathOperations {
    public:
        function<int(int, int)> add = [](int a, int b) { return a + b; };
        function<int(int, int)> multiply = [](int a, int b) { return a * b; };
    };

    MathOperations mathOps;
    cout << "Add: " << mathOps.add(3, 4) << endl;
    cout << "Multiply: " << mathOps.multiply(3, 4) << endl;

    // Task 12
    class Counter {
    public:
        int count = 0;
        function<int()> getIncrementer() {
            return [this]() { return ++count; };
        }
    };

    Counter counter;
    auto incrementer = counter.getIncrementer();
    cout << "Counter: " << incrementer() << endl;
    cout << "Counter: " << incrementer() << endl;

    // Task 13
    class Greeter {
    public:
        string name;
        function<void()> greet;
        Greeter(string n) : name(n), greet([=]() { cout << "Hello, " << name << "!" << endl; }) {}
    };

    Greeter greeter("World");
    greeter.greet();

    // Task 14
    class Executor {
    public:
        void executeTask(function<void()> task) {
            task();
        }
    };

    Executor executor;
    executor.executeTask([]() { cout << "Task executed!" << endl; });

    // Task 15
    class Numbers {
    public:
        vector<int> nums;
        Numbers(vector<int> n) : nums(n) {}
        void printFiltered(function<bool(int)> filter) {
            for (int n : nums) {
                if (filter(n)) {
                    cout << n << " ";
                }
            }
            cout << endl;
        }
    };

    Numbers numObj({ 1, 2, 3, 4, 5, 6 });
    numObj.printFiltered([](int n) { return n % 2 == 0; });

    // Task 16
    class People {
    public:
        vector<string> names;
        People(vector<string> n) : names(n) {}
        void sortNames() {
            sort(names.begin(), names.end(), [](string a, string b) { return a.length() < b.length(); });
        }
    };

    People people({ "Alice", "Bob", "Charlie", "Dave" });
    people.sortNames();
    for (string name : people.names) cout << name << " ";
    cout << endl;

    // Task 17
    class Grades {
    public:
        vector<int> grades;
        Grades(vector<int> g) : grades(g) {}
        void removeLowGrades(int threshold) {
            grades.erase(remove_if(grades.begin(), grades.end(), [=](int grade) { return grade < threshold; }), grades.end());
        }
    };

    Grades grades({ 50, 60, 70, 80, 90 });
    grades.removeLowGrades(70);
    for (int grade : grades.grades) cout << grade << " ";
    cout << endl;

    // Task 18
    class AgeFilter {
    public:
        map<string, int> ages;
        AgeFilter(map<string, int> a) : ages(a) {}
        void filterAdults() {
            vector<string> adults;
            for (const auto& p : ages) {
                if (p.second > 18) {
                    adults.push_back(p.first);
                }
            }
            for (const string& name : adults) {
                cout << name << " ";
            }
            cout << endl;
        }
    };

    AgeFilter ageFilter({ {"Alice", 20}, {"Bob", 17}, {"Charlie", 19} });
    ageFilter.filterAdults();
    

    // Task 19
    class Scaler {
    public:
        vector<int> numbers;
        Scaler(vector<int> n) : numbers(n) {}
        void scaleNumbers(int factor) {
            transform(numbers.begin(), numbers.end(), numbers.begin(), [=](int n) { return n * factor; });
        }
    };

    Scaler scaler({ 1, 2, 3, 4, 5 });
    scaler.scaleNumbers(3);
    for (int n : scaler.numbers) cout << n << " ";
    cout << endl;

    // Task 20
    class ResourceManager {
    public:
        unique_ptr<int> resource;
        ResourceManager(int r) : resource(make_unique<int>(r)) {}
        void useResource() {
            auto lambda = [res = move(resource)]() { cout << "Resource value: " << *res << endl; };
            lambda();
        }
    };

    ResourceManager resourceManager(42);
    resourceManager.useResource();
}