#include <functional>
#include <iostream>
#include <string>

class A {
    private:
        int c;
    public:
        A(int c) : c(c) {}

        int some_func() {
            std::cout << "normal func: " << ++c << std::endl;
        }

        int some_const_func() const {
            std::cout << "const func: " << c << std::endl;
        }

        static void sc() {}
};

int main() {
    A a(5);

    std::function<int(A&)> f1 = &A::some_func;
    std::function<int(const A&)> f2 = &A::some_const_func;

    f1(a);
    f2(a);
}
