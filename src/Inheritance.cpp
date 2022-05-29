#include <iostream>
#include <string>

class Base {
    private:
        std::string s;
    public:
        Base(): s("Base"){
            std::cout << "Base Class init" << std::endl;
        }

        void what() {
            std::cout << s <<std::endl;
        }
};

class Drived: public Base {
    private:
        std::string s;
    public:
        Drived(): Base(), s("drived") {
            std::cout << "Drived Class init" << std::endl;
            what();
        }

        void what() {
            std::cout << s << std::endl;
        }
};

int main() {
    std::cout << "== Init Base Class==" << std::endl;
    Base p1;

    std::cout << "== Init Drived Class==" << std::endl;
    Drived p2;

    return 0;
}
