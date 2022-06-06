#include <iostream>
#include <vector>
#include <algorithm>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << "[" << *begin << "]";
        begin++;
    }
    std::cout << std::endl;
}

struct is_odd {
    bool operator() (const int& i) {
        return i % 2 == 0;
    }
};

int main() {
    std::vector<int> vec;

    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::cout << "before remove" << std::endl;
    print(vec.begin(), vec.end());

    std::cout << "after remove" << std::endl;
    vec.erase(std::remove_if(vec.begin(), vec.end(), is_odd()), vec.end());
    print(vec.begin(), vec.end());
}
