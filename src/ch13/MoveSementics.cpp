#include <iostream>
#include <utility>

class A {
    public:
        A() {
            std::cout << "Call Constructor A()" << std::endl;
        }

        A(const A& a) {
            std::cout << "Call Constructor A(const A& a)" << std::endl;
        }

        A(A&& a) {
            std::cout << "Call Constructor A(A&& a)" << std::endl;
        }
};

int main() {
    A a;

    std::cout << "===================" << std::endl;
    A b(a);

    std::cout << "===================" << std::endl;
    A c(std::move(a));
    return 0;
} 
