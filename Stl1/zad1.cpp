#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

int main() {
    std::string input = "Hello world!!";

    std::cout << "[IN]: " << input << std::endl;
    std::cout << "[OUT]: " << std::endl;
    std::map<char, int> charCount;

    for (char c : input) {
        charCount[c]++;  
    }

    std::vector<std::pair<char, int>> sorted(charCount.begin(), charCount.end());

    std::sort(sorted.begin(), sorted.end(),
        [](const std::pair<char, int>& a, const std::pair<char, int>& b) {
            return a.second > b.second;  
        });

    for (const auto& pair : sorted) {
        if (pair.first == ' ') {
            std::cout << "  : " << pair.second << std::endl; 
        }
        else {
            std::cout << pair.first << ": " << pair.second << std::endl;
        }
    }

    return 0;
}