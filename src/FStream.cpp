#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream in("test.txt");

    if(!in.is_open()) {
        std::cout << "can not find file" << std::endl;
    }

    std::string s;
    while (in) {
        getline(in, s);
        std::cout << s << std::endl;
    }
    return 0;
}
