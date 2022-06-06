#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void print_vec(std::vector<T>& vec) {
    for (const auto& elem : vec) {
        std::cout << elem << std::endl;
    }

}

template <typename T>
struct greater_comp {
    bool operator() (const T& a, const T& b) const {
        return a > b;
    }
};

int main() {
    std::vector<int> vec;

    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(6);
    vec.push_back(4);
    vec.push_back(7);
    vec.push_back(2);

    std::cout << "before sort" << std::endl;
    print_vec(vec);

    std::cout << "after sort" << std::endl;
    std::sort(vec.begin(), vec.end(), greater_comp<int>());
    print_vec(vec);
}
