#include <fstream>
#include <iostream>
#include <cctype>
#include <string>
#include <vector>

using std::cout, std::string;

int part1() {
    string text;
    std::ifstream data("test.txt");
    std::vector<string> textLines;
    int x = 0;
    
    while (getline(data, text)) {
        textLines.push_back(text);
        x++;
    }
    for (int i = 0; i < x; i++) {
        char temp;
        for (int j = 0; j < textLines.size(); j++) {
            if (isdigit(textLines[i][j])) {
                cout << textLines[i][j]; 
            }
        }
    }

    return 0;
}

int main() {
    int part1Result = part1();  
    return 0;  
}
