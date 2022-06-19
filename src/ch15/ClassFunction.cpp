#include <iostream>
#include <functional>
#include <string>

class A {
    private:
        int c;
    public:
        A(int c): c(c) {}
        int some_func() {
            std::cout << "some_func call " << ++c << std::endl;
            return c;
        }

        int some_const_func() const {
            std::cout << "some_const_func call" << c << std::endl;
            return c;
        }
};

int main() {
    A a(5);
    std::function<int(A&)> f1 = &A::some_func;
    std::function<int(const A&)> f2 = &A::some_const_func;

    f1(a);
    f2(a);
}
