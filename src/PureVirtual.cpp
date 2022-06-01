#include <iostream>

class Animal {
    public: 
        Animal() {}
        virtual ~Animal() {}
        virtual void speak() = 0;
};

class Dog : public Animal {
    public:
        Dog(): Animal() {}
        void speak() override {
            std::cout << "wal wal wall .. " << std::endl;
        }
};

class Cat: public Animal {
    public: 
        Cat(): Animal() {}
        void speak() override { 
            std::cout << "yaong yaong yaong .. " << std::endl;
        }

};

int main() {
    Animal* dog = new Dog();
    Animal* cat = new Cat();

    dog->speak();
    cat->speak();
};
