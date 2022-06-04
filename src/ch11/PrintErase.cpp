#include <iostream>
#include <vector>

template <typename T>
void print_vec(std::vector<T>& vec) {
    for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); itr++) {
        std::cout << "vec: " << *itr << std::endl;
    }
}

template <typename T>
void print_vector_range_based(std::vector<T>* vec) {
    for (const auto& elem : *vec) {
        std::cout << elem << std::endl;
     }
    
}

int main() {
    std::vector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    std::cout << "initial vector is" << std::endl;
    print_vector_range_based(&vec);

    std::vector<int>::reverse_iterator r_iter = vec.rbegin();
    for (; r_iter != vec.rend(); r_iter++) {
        std::cout << *r_iter << std::endl;
    }
}
