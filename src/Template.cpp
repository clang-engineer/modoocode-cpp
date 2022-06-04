#include <iostream>

template <typename String>
std::string StrCat(const String& s) {
    return std::string(s);
}

template <typename String, typename...Strings>
std::string StrCat(const String& s, Strings... strs) {
    return std::string(s) + StrCat(strs...);
}

int main() {
    std::cout << StrCat(std::string("this"), " ", "is", " ", 
            "a", " ", "sentence") << std::endl;
    return 0;
}
