#include <iostream>

class Parent: public std::exception {
    public:
        virtual const char* what() const noexcept override {
            return "Parent!\n";
        }
};

class Child: public Parent {
    public:
        const char* what() const noexcept override {
            return "Child!\n";
        }
};

int func(int c) {
    if (c == 1) {
        throw Parent();
    } else {
        throw Child();
    }

    return 0;
}

int main() {
    int c;
    std::cin >> c;

    try {
     func(c);
    } catch (Child& child) {
        std::cout << "Child catch" << std::endl;
        std::cout << child.what();
    } catch (Parent& parent) {
        std::cout << "Parent catch" << std::endl;
        std::cout << parent.what();
    }
}
