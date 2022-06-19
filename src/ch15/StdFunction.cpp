#include <iostream>
#include <string>
#include <functional>

int sum_func1(const std::string& a) {
    std::cout << "Func1 call! " << a << std::endl;
    return 0;
}

struct S {
    void operator() (char c) {
        std::cout << "Func2 call! " << c << std::endl;
    }
};

int main() {
    std::function<int(const std::string&)> f1 = sum_func1;
    std::function<void(char)> f2 = S();
    std::function<void()> f3 = []() {
        std::cout << "Func3 call!" << std::endl;
    };

    f1("hello");
    f2('c');
    f3();
}
