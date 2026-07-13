#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <string>

template<typename Container>
void print_container(const Container& container) {

    auto it = container.begin();

    if (it != container.end()) {
        std::cout << *it;
        ++it;
    }

    while (it != container.end()) {
        std::cout << ", " << *it;
        ++it;
    }

    std::cout << std::endl;
}

int main() {
    std::set<std::string> test_set = { "one", "two", "three", "four" };
    std::cout << "set: ";
    print_container(test_set); 

    std::list<std::string> test_list = { "one", "two", "three", "four" };
    std::cout << "list: ";
    print_container(test_list); 

    std::vector<std::string> test_vector = { "one", "two", "three", "four" };
    std::cout << "vector: ";
    print_container(test_vector); 

    return 0;
}