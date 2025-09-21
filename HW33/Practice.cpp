#include <array>
#include <algorithm>
#include <functional>
#include <iostream>
#include <string_view>
#include <numeric>
#include <random>
using namespace std;

// Task 1
void task1() {
    using namespace std;
    array<int, 10> numbers = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    bool all_even = all_of(numbers.begin(), numbers.end(), [](int n) { return n % 2 == 0; });
    bool any_multiple_of_5 = any_of(numbers.begin(), numbers.end(), [](int n) { return n % 5 == 0; });
    bool none_negative = none_of(numbers.begin(), numbers.end(), [](int n) { return n < 0; });

    cout << "All even: " << all_even << endl;
    cout << "Any multiple of 5: " << any_multiple_of_5 << endl;
    cout << "None negative: " << none_negative << endl;
}

// Task 2
void executeAction(int times, const std::function<void(int)>& action) {
    for (int i = 0; i < times; ++i) {
        action(i);
    }
}

void task2() {
    executeAction(10, [](int i) { cout << i * i << endl; });
}

// Task 3
void task3() {
    array<string_view, 5> words = { "apple", "banana", "cherry", "date", "elderberry" };

    auto it = find_if(words.begin(), words.end(), [](string_view word) { return word.find('a') != string_view::npos; });

    if (it != words.end()) {
        cout << "First word with 'a': " << *it << endl;
    }
    else {
        cout << "No word contains 'a'" << endl;
    }
}

// Task 4
void task4() {
    array<string_view, 5> words = { "apple", "apricot", "banana", "cherry", "date" };

    auto it = adjacent_find(words.begin(), words.end(), [](string_view a, string_view b) { return a[0] == b[0]; });

    if (it != words.end() && (it + 1) != words.end()) {
        cout << "Adjacent words with the same first letter: " << *it << " and " << *(it + 1) << endl;
    }
    else {
        cout << "No adjacent words with the same first letter" << endl;
    }
}

// Task 5
void task5() {
    array<string_view, 10> words = { "apple", "banana", "cherry", "date", "ee", "fig", "grape", "honeydew", "kiwi", "lemon" };

    int count = count_if(words.begin(), words.end(), [](string_view word) { return word.find('e') != string_view::npos; });

    cout << "Number of words containing 'e': " << count << endl;
}

// Task 6
void task6() {
    array<int, 10> numbers = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };

    sort(numbers.begin(), numbers.end());

    for_each(numbers.begin(), numbers.end(), [](int n) { cout << n << " "; });
    cout << endl;
}

// Task 7
void task7() {
    array<int, 7> numbers = { 3, 1, 4, 1, 5, 9, 2 };

    auto [min_it, max_it] = minmax_element(numbers.begin(), numbers.end());

    cout << "Min element: " << *min_it << endl;
    cout << "Max element: " << *max_it << endl;
}

// Task 8
void task8() {
    array<int, 8> numbers = { -1, 2, -3, 4, -5, 6, -7, 8 };

    transform(numbers.begin(), numbers.end(), numbers.begin(), [](int n) { return n < 0 ? -n : n; });

    for_each(numbers.begin(), numbers.end(), [](int n) { cout << n << " "; });
    cout << endl;
}

// Task 9
void task9() {
    auto lambda = [](int x, int y) { return x * x + y * y; };

    cout << "lambda(3, 4): " << lambda(3, 4) << endl;
    cout << "lambda(5, 12): " << lambda(5, 12) << endl;
}

// Task 10
void task10() {
    array<int, 10> numbers;
    iota(numbers.begin(), numbers.end(), 1);

    random_device rd;
    mt19937 g(rd());
    shuffle(numbers.begin(), numbers.end(), g);

    for_each(numbers.begin(), numbers.end(), [](int n) { cout << n << " "; });
    cout << endl;
}

int main() {
    task1();
    cout << "----------------" << endl;
    task2();
    cout << "----------------" << endl;
    task3();
    cout << "----------------" << endl;
    task4();
    cout << "----------------" << endl;
    task5();
    cout << "----------------" << endl;
    task6();
    cout << "----------------" << endl;
    task7();
    cout << "----------------" << endl;
    task8();
    cout << "----------------" << endl;
    task9();
    cout << "----------------" << endl;
    task10();
}
