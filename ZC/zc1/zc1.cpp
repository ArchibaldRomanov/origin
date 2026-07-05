#include <iostream>
#include <stdexcept>  

class smart_array {
private:
    int* data;        
    size_t size;      
    size_t capacity;  

public:
    // Конструктор 
    explicit smart_array(size_t initial_capacity)
        : data(nullptr), size(0), capacity(initial_capacity)
    {
        if (capacity == 0) {
            throw std::runtime_error("Initial capacity must be > 0");
        }
        data = new int[capacity];
    }

    // Деструктор
    ~smart_array() {
        delete[] data;
    }

    
    smart_array(const smart_array&) = delete;
    smart_array& operator=(const smart_array&) = delete;


    void add_element(int value) {
        if (size == capacity) {
            
            size_t new_capacity = capacity * 2;
            int* new_data = new int[new_capacity];
            
            for (size_t i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            // Освобождаем старый буфер
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
        data[size++] = value;
    }

   
    int get_element(size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    size_t get_size() const { return size; }
    size_t get_capacity() const { return capacity; }
};


int main() {
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
       
        arr.add_element(100);  

        std::cout << arr.get_element(1) << std::endl;  // выведет 4
        std::cout << "Size: " << arr.get_size() << ", Capacity: " << arr.get_capacity() << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}