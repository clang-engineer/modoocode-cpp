#include <iostream>
#include <vector>

void print_vec(std::vector<int>& vec) {
    for (std::vector<int>::iterator itr = vec.begin(); itr != vec.end(); itr++) {
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

    std::vector<int>::iterator itr = vec.begin();

    for (; itr != vec.end(); ++itr) {
        if (*itr == 20) {
            vec.erase(itr);
        }
    }


    std::cout << "after erase element is" << std::endl;
    print_vec(vec);
}
