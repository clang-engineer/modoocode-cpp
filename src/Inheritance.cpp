#include <iostream>
#include <string>

class Base {
    public:
        std::string s;

        Base(): s("Base"){
            std::cout << "Base Class Constructor" << std::endl;
        }

        void what() {
            std::cout << s <<std::endl;
        }
};

class Drived: private Base {
    private:
        std::string s;
    public:
        Drived(): Base(), s("drived") {
            std::cout << "Drived Class Constructor" << std::endl;
        }

        void what() {
            std::cout << s << std::endl;
        }
};

int main() {
    std::cout << "Base class init" << std::endl;
    Base p;

    p.what();

    std::cout << "Drived class init" << std::endl;
    Drived c;

    c.what();

    return 0;
}
