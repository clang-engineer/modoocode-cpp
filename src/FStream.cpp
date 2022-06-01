#include <fstream>
#include <iostream>
#include <string>

class Human {
    private: 
        std::string name;
        int age;

    public:
        Human(const std::string& name, int age): name(name), age(age) {}
        std::string get_info() {
            return "Name: " + name + "/ Age: " + std::to_string(age);
        }

        friend std::ofstream& operator<<(std::ofstream& o, Human& h);
};

std::ofstream& operator<<(std::ofstream& os, Human& h) {
    os << h.get_info();
    return os;
};

int main() { 

    std::ofstream out("test.txt");

    Human h("lee", 60);
    out << h << std::endl;

    return 0;
}
