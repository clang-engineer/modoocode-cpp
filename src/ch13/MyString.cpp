#include <iostream>
#include <cstring>
#include <vector>

class MyString {
    private:
        char *string_content;
        int string_length;

        int memory_capacity;
    public:
        MyString();

        MyString(const char *str);

        MyString(const MyString &str);

        MyString(MyString &&str) noexcept;

        ~MyString();

};

MyString::MyString() {
    std::cout << "Constructor - MyString()" << std::endl;
    string_content = nullptr;
    string_length = 0;
    memory_capacity = 0;
}

MyString::MyString(const char *str) {
    std::cout << "Constructor - MyString(const char *str)" << std::endl;
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];

    for (int i = 0; i < string_length; i++) {
        string_content[i] = str[i];
    }
}

MyString::MyString(const MyString &str) {
    std::cout << "Constructor - MyString(const MyString &str)" << std::endl;
    string_length = str.string_length;
    memory_capacity = str.memory_capacity;
    string_content = new char[string_length];

    for (int i = 0; i < string_length; i++) {
        string_content[i] = str.string_content[i];
    }
}

MyString::MyString(MyString &&str) noexcept {
    std::cout << "Constructor - MyString(MyString &&str)" << std::endl;
    string_length = str.string_length;
    memory_capacity = str.memory_capacity;
    string_content = str.string_content;

    str.string_content = nullptr;
}


MyString::~MyString() {
    if (string_content) {
        delete[] string_content;
    }
}

int main() {
    MyString s("abc");
    std::vector<MyString> vec;
    
    std::cout << "===========add first elem=========" << std::endl;
    vec.push_back(s);

    std::cout << "===========add second elem=========" << std::endl;

    vec.push_back(s);

    std::cout << "===========add third elem=========" << std::endl;
    vec.push_back(s);
}
