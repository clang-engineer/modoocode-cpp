#include <iostream>

class Parent {
    public:
        Parent() {
            std::cout << "Parent Constuctor" << std::endl;
        }
        ~Parent() {
            std::cout << "Parent Denstuctor" << std::endl;
        }
};

class Child : public Parent {
    public: 
        Child() : Parent() {
            std::cout << "Childs Constuctor" << std::endl;
        }
        ~Child() {
            std::cout << "Child Denstuctor" << std::endl;
        }
};

int main() {
    std::cout << " == Child Object ==" << std::endl;
    {Child c;}

    std::cout << " == Child Object with Parnet Pointer ==" << std::endl;
    {
        Parent* p = new Child();
        delete p;
    }
    return 0;
}
