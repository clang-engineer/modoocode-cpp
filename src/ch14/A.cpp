#include <iostream> 
#include <memory>

class A {
    private: 
        int *data;

    public:
        A() {
            std::cout << "call Constructor A()" << std::endl;
            data = new int[100];
        }

        void some() {
            std::cout << "can use same as normal pointer" << std::endl;
        }

        ~A() { 
            std::cout << "call Destoryer A()" << std::endl;
            delete[] data;
        }
};


void do_something() {
    std::unique_ptr<A> pa(new A());

    std::unique_ptr<A> pb = std::move(pa);
    pa->some();
}


int main() {
    do_something();
}
