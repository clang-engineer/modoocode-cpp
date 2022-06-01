#include <iostream>

int main() {
    std::string s;
    std::cin >> s;

    char peek = std::cin.rdbuf() -> snextc();
    if (std::cin.fail()) std::cout << "failed" << std::endl;

    std::cout << "first of next word: " << peek << std::endl;
    std::cin >> s;
    std::cout << "read re: " << s << std::endl;
    
    return 0;
}
