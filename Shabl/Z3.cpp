#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

class DivisibleByThreeCounter {
private:
    int sum_;
    int count_;

public:

    DivisibleByThreeCounter() : sum_(0), count_(0) {}

    void operator()(int num) {
        if (num % 3 == 0) {
            sum_ += num;
            count_++;
        }
    }

    // Возвращает сумму чисел, делящихся на 3
    int get_sum() const {
        return sum_;
    }

    // Возвращает количество чисел, делящихся на 3
    int get_count() const {
        return count_;
    }
};

std::vector<int> parseInput(const std::string& input) {
    std::vector<int> result;
    std::stringstream ss(input);
    int num;
    while (ss >> num) {
        result.push_back(num);
    }
    return result;
}

int main() {
    std::string input = "4 1 3 6 25 54";
    std::cout << "[IN]: " << input << std::endl;

    std::vector<int> numbers = parseInput(input);

    DivisibleByThreeCounter counter;

    std::for_each(numbers.begin(), numbers.end(), std::ref(counter));

    std::cout << "[OUT]: get_sum() = " << counter.get_sum() << std::endl;
    std::cout << "[OUT]: get_count() = " << counter.get_count() << std::endl;

    return 0;
}