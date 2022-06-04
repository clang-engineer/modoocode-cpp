#include <iostream>
#include <cstring>

size_t GetStringSize(const char* s) {
    return strlen(s);
}

size_t GetStringSize(const std::string& s) {
    return s.size();
}

template <typename String, typename... Strings>
size_t GetStringSize(const String& s, Strings... strs) {
    return GetStringSize(s) + GetStringSize(strs...);
}

void AppendToString(std::string* concat_string) {
    return; 
}

template <typename String, typename... Strings> 
void AppendToString(std::string* concat_string, String& s, Strings... strs) {
    concat_string->append(s);
    AppendToString(concat_string, strs...);
}

template <typename String, typename... Strings>
std::string StrCat(String s, Strings... strs) {
    size_t total_size = GetStringSize(s, strs...);

    std::string concat_string;
    concat_string.reserve(total_size);

    concat_string = s;
    AppendToString(&concat_string, strs...);

    return concat_string;
}

int main() {
    std::cout << StrCat(std::string("this"), " ", "is", " ",
            std::string("a"), " ", std::string("sentence")) << std::endl;
    return 0;
}
