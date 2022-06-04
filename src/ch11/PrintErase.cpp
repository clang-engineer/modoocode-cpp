#include <iostream>
#include <vector>

template <typename T>
void print_vec(std::vector<T>& vec) {
    for (typename std::vector<T>::iterator itr = vec.begin(); itr != vec.end(); itr++) {
        std::cout << "vec: " << *itr << std::endl;
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
    print_vec(vec);

    std::vector<int>::iterator itr = vec.begin() + 2;
    *itr = 500;
    print_vec(vec);


    std::vector<int>::const_iterator citr = vec.begin() + 2;
    *citr = 300;
    print_vec(vec);
}
