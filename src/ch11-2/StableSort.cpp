#include <iostream>
#include <vector>
#include <algorithm>

template <typename Iter>
void print(Iter begin, Iter end) {
    while (begin != end) {
        std::cout << "[" << *begin << "] ";
        begin++;
    }
    std::cout << std::endl;
}

struct User {
    std::string name;
    int age;

    User(std::string name, int age): name(name), age(age) {}

    bool operator<(const User& u) const {
        return age < u.age;
    }
};

std::ostream& operator<<(std::ostream& os, const User& user) {
    os << user.name << ", " << user.age;
    return os;
};

int main() {
    std::vector<User> vec;
    for (int i=0; i < 100; i++) {
        std::string name = "";
        name.push_back('a' + i / 26);
        name.push_back('a' + i / 26);
        vec.push_back(User(name, static_cast<int>(rand() % 10)));
    }

    std::vector<User> vec2 = vec;

    std::cout << "before sort" << std::endl;
    print(vec.begin(), vec.end());

    std::cout << "after sort" << std::endl;
    std::sort(vec.begin(), vec.end());
    print(vec.begin(), vec.end());

    std::cout << "after stable sort" << std::endl;
    std::stable_sort(vec2.begin(), vec2.end());
    print(vec2.begin(), vec2.end());
}
