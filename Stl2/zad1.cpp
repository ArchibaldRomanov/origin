#include <iostream>
#include <vector>
#include <algorithm>

template<typename T>
void make_unique(std::vector<T>& vec) {
    std::sort(vec.begin(), vec.end());

    auto last = std::unique(vec.begin(), vec.end());

    vec.erase(last, vec.end());
}

int main() {
    std::vector<int> v = { 1, 1, 2, 5, 6, 1, 2, 4 };

    std::cout << "[IN]: ";
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    make_unique(v);

    std::cout << "[OUT]: ";
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}