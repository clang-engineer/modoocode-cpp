#include <iostream>
#include <memory>

class Foo {
    private:
        int a, b;

    public:
        Foo(int a, int b): a(a), b(b) {
            std::cout << "Constructor Foo(int a, int b) called" << std::endl;
        }

        void print() {
            std::cout << "a: " << a << ", " << "b: " << b << std::endl;
        }

        ~Foo() {
            std::cout << "Detructor Foo(int a, int b) called" << std::endl;
        }
};

int  main() {
    auto ptr = std::make_unique<Foo>(3, 2);
    ptr->print();
}
