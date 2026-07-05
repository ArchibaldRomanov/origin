#include <iostream>
#include <stdexcept>

class smart_array {
private:
    int* data;
    size_t size;      // выделенный размер
    size_t count;     // текущее количество элементов

    void resize() {
        size_t new_size = (size == 0) ? 1 : size * 2;
        int* new_data = new int[new_size];
        for (size_t i = 0; i < count; ++i) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        size = new_size;
    }

public:
    // Конструктор с указанием начального размера
    explicit smart_array(size_t initial_size = 0)
        : data(nullptr), size(initial_size), count(0) {
        if (size > 0) {
            data = new int[size];
        }
    }

    // Конструктор копирования (глубокое копирование)
    smart_array(const smart_array& other)
        : data(nullptr), size(other.size), count(other.count) {
        if (size > 0) {
            data = new int[size];
            for (size_t i = 0; i < count; ++i) {
                data[i] = other.data[i];
            }
        }
    }

    // Оператор присваивания (глубокое копирование)
    smart_array& operator=(const smart_array& other) {
        if (this == &other) {
            return *this; // защита от самоприсваивания
        }

        // Освобождаем старую память
        delete[] data;
        data = nullptr;

        // Копируем размеры
        size = other.size;
        count = other.count;

        // Выделяем новую память и копируем элементы
        if (size > 0) {
            data = new int[size];
            for (size_t i = 0; i < count; ++i) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Деструктор
    ~smart_array() {
        delete[] data;
    }

    // Добавление элемента (с автоматическим расширением)
    void add_element(int value) {
        if (count == size) {
            resize();
        }
        data[count++] = value;
    }

    // Получение элемента по индексу (с проверкой)
    int get_element(size_t index) const {
        if (index >= count) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    // Получение текущего количества элементов
    size_t get_count() const {
        return count;
    }
};

// Пример использования (как в задаче)
int main() {
    smart_array arr(5);
    arr.add_element(1);
    arr.add_element(4);
    arr.add_element(155);

    smart_array new_array(2);
    new_array.add_element(44);
    new_array.add_element(34);

    arr = new_array; // теперь arr содержит копию данных new_array

    // Проверим
    for (size_t i = 0; i < arr.get_count(); ++i) {
        std::cout << arr.get_element(i) << " "; // 44 34
    }

    return 0;
}