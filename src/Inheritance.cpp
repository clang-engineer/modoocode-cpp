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

class Drived: public Base {
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
    Base p;
    Drived c;

    std::cout << "== pointer viersion ==" << std::endl;
    Drived* p_p  = &p;
    p_p->what();

    return 0;
}
