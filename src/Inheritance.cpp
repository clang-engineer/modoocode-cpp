#include <iostream>
#include <string>

class Base {
    public:
        std::string parent_string;

        Base(): parent_string("Base"){
            std::cout << "Base Class init" << std::endl;
        }

        void what() {
            std::cout << parent_string <<std::endl;
        }
};

class Drived: private Base {
    private:
        std::string child_string;
    public:
        Drived(): Base(), child_string("drived") {
            std::cout << "Drived Class init" << std::endl;
        }

        void what() {
            std::cout << child_string << std::endl;
        }
};

int main() {
    Base p;

    std::cout << p.parent_string << std::endl;

    Drived c;
    return 0;
}
