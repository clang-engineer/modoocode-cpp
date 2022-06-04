#include <iostream>
#include <list>

template <typename T>
void print(std::list<T>& list) {
    for (std::list<int>::iterator itr = list.begin(); itr != list.end(); itr++) {
        std::cout << *itr << std::endl;
    }
}
int main() {
    std::list<int> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_back(40);
    list.push_back(50);

    std::cout << "intial list" << std::endl;
    print(list);

    std::cout << "insert elem to list" << std::endl;
    for (std::list<int>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        if (*itr == 20) {
            list.insert(itr, 21);
        }
    }
    print(list);

    std::cout << "erase elem to list" << std::endl;
    for (std::list<int>::iterator itr = list.begin(); itr != list.end(); ++itr) {
        if (*itr == 20) {
            list.erase(itr);
            break;
        }
    }
    print(list);

    return 0;
}
