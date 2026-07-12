#include <vector>
#include <iostream>

template<typename T>
T square(const T& x) {
    return x * x;
}

template<typename T>
std::vector<T> square(const std::vector<T>& v) {
    std::vector<T> result;
    result.reserve(v.size());
    for (const auto& x : v) {
        result.push_back(x * x);  
    }
    return result;
}

int main() {
    // Работа с числом
    std::cout << "[IN]: 4" << std::endl;
    std::cout << "[OUT]: " << square(4) << std::endl;

    // Работа с вектором
    std::vector<int> v = { -1, 4, 8 };
    std::cout << "[IN]: -1, 4, 8" << std::endl;

    auto result = square(v);
    std::cout << "[OUT]: ";
    for (size_t i = 0; i < result.size(); ++i) {
        if (i > 0) std::cout << ", ";
        std::cout << result[i];
    }
    std::cout << std::endl;

    return 0;
}