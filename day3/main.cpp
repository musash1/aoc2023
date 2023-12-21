#include <fstream>
#include <iostream>

using std::cout, std::string;

int part1() {
    string text;
    std::ifstream data("test.txt");

    while (getline(data, text)) {
        cout << text << '\n';
    }

    return 0;
}

int main() {
    int part1Result = part1();  
    return 0;  
}
