#include <algorithm>
#include <fstream>
#include <iostream>
#include <cctype>
#include <string>
#include <tuple>
#include <vector>

using std::cout, std::string, std::get;

std::vector<std::tuple<int, int>> adjacent(int x, int y, int max_x, int max_y) {
    std::vector<std::tuple<int, int>> result;
    if (x > 0 && y > 0) {
        for (int i = x - 1; i < std::min(max_x, x + 2); i++) {
            for (int j = y - 1; j < std::min(max_y, y + 2); j++) {
                if (i == x && j == y) {
                    continue;
                } 
                result.push_back(std::make_tuple(i, j));
            }   
        }
    } else if (x == 0 && y > 0) {
        for (int i = 0; i < std::min(max_x, x + 2); i++) {
            for (int j = y - 1; j < std::min(max_y, y + 2); j++) {
                if (i == x && j == y) {
                    continue;
                } 
                result.push_back(std::make_tuple(i, j));
            }   
        }
    } else if (x > 0 && y == 0) {
        for (int i = x - 1; i < std::min(max_x, x + 2); i++) {
            for (int j = 0; j < std::min(max_y, y + 2); j++) {
                if (i == x && j == y) {
                    continue;
                } 
                result.push_back(std::make_tuple(i, j));
            }   
        }
    } else {
        for (int i = 0; i < std::min(max_x, x + 2); i++) {
            for (int j = 0; j < std::min(max_y, y + 2); j++) {
                if (i == x && j == y) {
                    continue;
                } 
                result.push_back(std::make_tuple(i, j));
            }   
        }
    }
    
    return result;
}

std::tuple<int, int> whole_number(std::vector<string> lines, int x, int y) {
    std::tuple<int, int> result;
    int j = y + 1;

    while (j < lines[x].length() && isdigit(lines[x][j])) {
        j++;
    }
    string num = "";
    for (int i = y; i < j; i++) {
        num += lines[x][i];
    }

    result = std::make_tuple((j - y), std::stoi(num));

    return result;
}

int adjacent_to_symbol(std::vector<string> lines, int x, int y) {
    std::vector<std::tuple<int,int>> point = adjacent(x, y, lines.size(), lines[0].length());
    for (int i = 0; i < point.size(); i++) {
        if (!isdigit(lines[get<0>(point[i])][get<1>(point[i])]) && lines[get<0>(point[i])][get<1>(point[i])] != '.') {
            return 1;
        }
        if (y + 1 == get<1>(point[i]) && x == get<0>(point[i]) && isdigit(lines[get<0>(point[i])][get<1>(point[i])]) && adjacent_to_symbol(lines, get<0>(point[i]), get<1>(point[i]))) {
            return 1;
        }
    }
    return 0;
} 

int part1() {
    string text;
    std::ifstream data("text.txt");
    std::vector<string> textLines;
    int result = 0; 
    
    while (getline(data, text)) {
        textLines.push_back(text);
    }

    for (int i = 0; i < textLines.size(); i++) {
        int j = 0;
        while (j < textLines[i].length()) {
            if (isdigit(textLines[i][j]) && adjacent_to_symbol(textLines, i, j)) {
                std::tuple<int, int> n = whole_number(textLines, i, j);
                cout << get<1>(n) << "\n";
                j += get<0>(n);
                result += get<1>(n);
            } else {
                j++;
            }
        }
    }

    return result;
}

int main() {
    cout << part1() << "\n";

    return 0;  
}
