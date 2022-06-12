#include <iostream>

template <typename T>
class Vector {
    private:
        T* data_;
        size_t size_;
    public:
        Vector(size_t size): size_(size) {
            data_ = new T[size_];
            for (int i = 0; i < size_; i++) {
                data_[i] = 3;
            }
        }
        const T& at(size_t index) const {
            if (index >= size_) {
                throw std::out_of_range("Out of range exception");
            }
            return data_[index];
        }
        ~Vector() {
            delete[] data_;
        }
};

int main() {
    Vector<int> vec(3);

    int index, data = 0;
    std::cin >> index;

    try {
        data = vec.at(index);
    } catch (std::out_of_range& ex) {
        std::cout << ex.what() << std::endl;
    }

    std::cout << "data: " << data << std::endl;
}
