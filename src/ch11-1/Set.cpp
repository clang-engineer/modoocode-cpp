#include <iostream>
#include <set>

void print_set(std::set<int>* s) {
    for (std::set<int>::iterator itr = s->begin(); itr != s->end(); itr++) {
        std::cout << *itr << std::endl;
    }
}

int main() {
    std::set<int> s;

    s.insert(10);
    s.insert(40);
    s.insert(50);
    s.insert(20);
    s.insert(30);
    
    std::cout << "inital set print_set" << std::endl;
    print_set(&s);

    std::cout << "check if 20 in set" << std::endl;
    std::set<int>::iterator itr = s.find(20);
    if (itr != s.end()) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
    
    std::cout << "check if 25 in set" << std::endl;
    itr = s.find(25);
    if (itr != s.end()) {
        std::cout << "Yes" << std::endl;
    } else {
        std::cout << "No" << std::endl;
    }
}
