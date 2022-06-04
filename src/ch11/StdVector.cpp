#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);

    for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); ++itr) {
        std::cout << "vec is " << *itr << std::endl;
    }

    std::vector<int>::iterator itr = vec.begin() + 2;

    std::cout << "3 of vector is " << *itr << std::endl;
}
