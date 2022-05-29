#include <iostream>
#include <string>

class Base {
    protected:
        std::string parent_string;
    public:
        Base(): parent_string("Base"){
            std::cout << "Base Class init" << std::endl;
        }

        void what() {
            std::cout << parent_string <<std::endl;
        }
};

class Drived: public Base {
    private:
        std::string child_string;
    public:
        Drived(): Base(), child_string("drived") {
            std::cout << "Drived Class init" << std::endl;
            parent_string = "change by child";
        }

        void what() {
            std::cout << child_string << std::endl;
            std::cout << parent_string << std::endl;
        }
};

int main() {
    std::cout << "== Init Base Class==" << std::endl;
    Base p1;

    std::cout << "== Init Drived Class==" << std::endl;
    Drived p2;

    p2.what();

    return 0;
}
