#include <iostream>
#include <set>

template <typename T>
void print_multiset(const std::multiset<T>& s) {
    for (const auto& elem : s) {
        std::cout << elem << std::endl;
    }
};

int main() {
    std::multiset<std::string> s;

    s.insert("a");
    s.insert("a");
    s.insert("a");
    s.insert("a");
    s.insert("a");
    s.insert("a");
    s.insert("a");

    print_multiset(s);
}
