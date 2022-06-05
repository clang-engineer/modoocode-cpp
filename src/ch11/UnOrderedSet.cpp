#include <iostream>
#include <unordered_set>

template <typename K>
void print_unordered_set(const std::unordered_set<K>& m) {
    for (const auto& elem: m) {
        std::cout << elem << std::endl;
    }
}

template <typename K>
void is_exist(const std::unordered_set<K>& m, std::string key) {

    if (m.find(key) != m.end()) {
        std::cout << "is present key: " << key << std::endl;
    } else {
        std::cout << "is not present key: " << key << std::endl;
    }
}

int main() {
    std::unordered_set<std::string> s;

    s.insert("hi");
    s.insert("my");
    s.insert("name");
    s.insert("is");
    s.insert("psi");
    s.insert("welcome");
    s.insert("to");
    s.insert("c++");

    print_unordered_set(s);

    is_exist(s, "c++");
    is_exist(s, "c");

    s.erase(s.find("hi"));
    is_exist(s, "hi");

    return 0;
}
