#include <iostream>
#include <string>

class Base {
    public:
        std::string s;

        Base(): s("Base"){
            std::cout << "Base Class Constructor" << std::endl;
        }

        virtual void what() {
            std::cout << s << std::endl;
        }
};

class Drived: public Base {
    private:
        std::string s;
    public:
        Drived(): Base(), s("drived") {
            std::cout << "Drived Class Constructor" << std::endl;
        }

        void what() override {
            std::cout << s << std::endl;
        }
};

int main() {
    Base p;
    Drived c;

    std::cout << "== pointer viersion ==" << std::endl;
    std::cout << "Base class init" << std::endl;
    Base* p_p = &p;
    Base* p_c = &c;

    std::cout << "== no casting ==" << std::endl;
    p_p->what();

    std::cout << "== up casting ==" << std::endl;
    p_c->what();

    return 0;
}
