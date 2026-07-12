#include <vector>
#include <utility>

template<typename T>
class Table {
private:
    size_t rows_;
    size_t cols_;
    std::vector<T> data_;

public:
    Table(size_t rows, size_t cols)
        : rows_(rows), cols_(cols), data_(rows* cols) {
    }
    class Row {
    private:
        T* data_;
        size_t cols_;

    public:
        Row(T* data, size_t cols) : data_(data), cols_(cols) {}

        T& operator[](size_t col) {
            return data_[col];
        }

        const T& operator[](size_t col) const {
            return data_[col];
        }
    };

    // Оператор [] для неконстантных объектов
    Row operator[](size_t row) {
        return Row(data_.data() + row * cols_, cols_);
    }

    // Оператор [] для константных объектов
    const Row operator[](size_t row) const {
        return Row(const_cast<T*>(data_.data() + row * cols_), cols_);
    }

    std::pair<size_t, size_t> Size() const {
        return { rows_, cols_ };
    }
};