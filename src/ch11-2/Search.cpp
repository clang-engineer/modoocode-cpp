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

int main() {
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(3);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    vec.push_back(4);

    std::cout << "initial vec" << std::endl;
    print(vec.begin(), vec.end());

    std::cout << "find one" << std::endl;
    std::vector<int>::iterator result = std::find(vec.begin(), vec.end(), 1);
    std::cout << "vec 1 is on " << std::distance(vec.begin(), result) << " position" << std::endl;

    std::cout << "find all" << std::endl;
    std::vector<int>::iterator current = vec.begin();
    while (true) {
        current = std::find(current, vec.end(), 3);

        if (current == vec.end()) break;

        std::cout << "3 is " << std::distance(vec.begin(), current) + 1 << "th elem" << std::endl;
        current++;
    }

    std::cout << "find one by functor" << std::endl;
    current = vec.begin();
    while(true) {
        current = std::find_if(current, vec.end(), 
                [](int i) -> bool {
                return i % 3 == 2;
                });

        if (current == vec.end()) break;

        std::cout << *current << std::endl;
        current++;
    }
}
