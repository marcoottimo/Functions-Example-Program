//
// Created by marco on 02/02/2025.
//
#include <iostream>
#include <vector>

void print(const std::vector<int> &v);
void add(std::vector<int> &v, int n);
int average(const std::vector<int> &v);
int low(const std::vector<int> &v);
int high(const std::vector <int> &v);
void clear(std::vector<int> &v);
void find(const std::vector<int> &v, int n);
void quit();
void handler(char c, std::vector<int> &v);
void displayMenu();


void print(const std::vector<int> &v) {
    std::cout << "[";
    for (auto i: v) {
        if (i != v.at(v.size() - 1))
            std::cout << i << ", ";
        else
            std::cout << i;
    }
    std::cout << "]" << std::endl;
}

void add(std::vector<int> &v, int n) {
    v.push_back(n);
}

int average(const std::vector<int> &v) {
    static int avg {};
    for (auto i: v)
        avg += i;
    return avg /= static_cast<int>(v.size());
}
int low (const std::vector<int> &v) {
    if (v.empty()) return 0; // Or some other value to indicate the vector is empty

    int min = v.at(0); // Initialize max with the first element
    for (auto i: v) {
        if (i < min)
            min = i;
    }
    return min;
}
int high(const std::vector<int> &v) {
    if (v.empty()) return 0; // Or some other value to indicate the vector is empty

    int max = v.at(0); // Initialize max with the first element
    for (auto i: v) {
        if (i > max)
            max = i;
    }
    return max;
}
void clear(std::vector<int> &v) {
    v.clear();
    std::cout << "Vector cleared successfully." << std::endl;
}

void quit() {
    std::cout << "Quitting..." << std::endl;
    exit(0);
}

void find(const std::vector<int> &v, int n) {
    for (size_t i {}; i < v.size(); ++i) {
        if (v.at(i) == n) {
            std::cout << n << " found at position " << i << std::endl;
            return;
        }
    }
    std::cout << n << " not found." << std::endl;
}

void displayMenu() {
    std::vector<std::string> menu_options = {
        "P - Print numbers",
        "A - Add a number",
        "M - Display mean of the numbers",
        "S - Display the smallest number",
        "L - Display the largest number",
        "C - Clears the vector",
        "F - Find a number in vector",
        "Q - Quit"
    };

    for (auto i: menu_options) {
        std::cout << i << std::endl;
    }
    std::cout << std::endl;
}

void handler(char c, std::vector <int> &v) {
    c = std::tolower(c);

    int to_insert {};
    int to_find {};
    int avg {};
    int largest {};
    int lowest {};

    switch (c) {
        case 'p':
            print(v);
            break;
        case 'a':
            std::cin >> to_insert;
            add(v, to_insert);
            break;
        case 'f':
            std::cin >> to_find;
            find(v, to_find);
            break;
        case 'm':
            avg = average(v);
            std::cout << avg << std::endl;
            break;
        case 's':
            lowest = low(v);
            std::cout << lowest << std::endl;
            break;
        case 'l':
            largest = high(v);
            std::cout << largest << std::endl;
            break;
        case 'c':
            clear(v);
            break;
        case 'q':
            quit();
            break;
        default:
            std::cout << "Invalid choice." << std::endl;
    }
}

int main () {
    std::vector<int> v {1, 2, 3, 4, 5};
    char choice {};
    do {
        displayMenu();
        std::cin >> choice;
        handler(choice, v);
    } while (true);

    return 0;
}