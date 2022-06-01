#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream in("test.txt");
    std::string s;

    if (in.is_open()) {
        in >> s;
        std::cout << "input string is: " << s << std::endl;
    } else {
        std::cout << "can not find file" << s << std::endl;
    }

    in.close();
    in.open("other.txt");
    
    if (in.is_open()) {
        in >> s;
        std::cout << "input string is: " << s << std::endl;
    } else {
        std::cout << "can not find file" << s << std::endl;
    }
    return 0;
}
