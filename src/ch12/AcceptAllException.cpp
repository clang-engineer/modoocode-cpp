#include <iostream>

int func(int c) {
    if (c == 1) {
        throw 1;
    } else if (c == 2) {
        throw "hi";
    } else if (c == 3) {
        throw std::runtime_error("error");
    }

    return 0;
}

int main() {
    int c;

    std::cin >> c;

    try {
        func(c);
    } catch (int a) {
        std::cout << "Catch int: " << a << std::endl;
    } catch (...) {
        std::cout << "Default catch!" << std::endl;
    }
}
