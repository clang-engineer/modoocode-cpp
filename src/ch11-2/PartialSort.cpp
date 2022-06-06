#include <iostream>
#include <vector>
#include <algorithm>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << *begin << " ";
        begin++;
    }
    std::cout << std::endl;
}

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
    print(vec.begin(), vec.end());

    std::cout << "after sort" << std::endl;
    std::partial_sort(vec.begin(), vec.begin() + 3, vec.end());
    print(vec.begin(), vec.end());
}
