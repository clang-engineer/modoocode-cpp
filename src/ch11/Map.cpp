#include <iostream>
#include <map>

template <typename K, typename V>
void print_map(std::map<K, V>* map) {
    for (typename std::map<K, V>::iterator itr = map->begin(); itr != map->end(); itr++) {
        std::cout << itr->first << ", " << itr->second << std::endl;
    }

    for (const std::pair<K, V> elem : *map) {
        std::cout << elem.first << ", " << elem.second << std::endl;
    }

}

template <typename K, typename V>
void search_and_print(std::map<K, V>* map, K key) {
    typename std::map<K, V>::iterator itr = map->find(key);

    if (itr != map->end()) {
        std::cout << key << "--->" << itr->second << std::endl;
    } else {
        std::cout << key << " is not in map" << std::endl;
    }
}

int main() {
    std::map<std::string, double> pitcher_list;

    pitcher_list.insert(std::pair<std::string, double>("kim1", 1.5));
    pitcher_list.insert(std::pair<std::string, double>("lee1", 2.1));
    pitcher_list.insert(std::pair<std::string, double>("park1", 3.3));

    pitcher_list.insert(std::make_pair("kim2", 1.5));
    pitcher_list.insert(std::make_pair("lee2", 2.1));
    pitcher_list.insert(std::make_pair("park2", 3.3));

    pitcher_list["kim3"] = 3.9;
    pitcher_list["lee3"] = 4.2;
    pitcher_list["park3"] = 1.6;

    print_map(&pitcher_list);

    search_and_print(&pitcher_list, std::string("kim3"));
    search_and_print(&pitcher_list, std::string("kim5"));
}
