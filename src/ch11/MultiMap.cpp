#include <iostream>
#include <map> 

template <typename K, typename V>
void print_multimap(std::multimap<K, V>& maps) {
    for (const std::pair<K, V>& map: maps) {
        std::cout << "key: " << map.first << ", val: " << map.second << std::endl;
    }
}

int main() {
    std::multimap<std::string, int> map;

    map.insert(std::pair<std::string, int>("test1", 1));
    map.insert(std::make_pair("test1", 2));
    map.insert(std::make_pair("test1", 3));
    map.insert(std::make_pair("test2", 2));
    map.insert(std::make_pair("test3", 3));

    print_multimap(map);

    std::cout << "test1 value is " << map.find("test1")->second << std::endl;

    std::cout << "print all elem which have key test1" << std::endl;

    auto range = map.equal_range("test1");
    for (auto itr = range.first; itr != range.second; itr++) {
        std::cout << itr->first << ": " << itr->second << std::endl;
    }

    return 0;
}
