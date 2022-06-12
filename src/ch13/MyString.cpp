#include <iostream>
#include <cstring>
#include <vector>

class MyString {
    private:
        char* string_content;
        int string_length;

        int memory_capacity;
    public:
        MyString();

        MyString(const char* str);

        MyString(const MyString& str);

        MyString(MyString&& str) noexcept;

        void reserve(int size);

        MyString operator+(const MyString& str);

        ~MyString();

        int length() const;

        void print();

        void println();
};

MyString::MyString() {
    std::cout << "Constructor MyString() is called" << std::endl;
    string_length = 0;
    memory_capacity = 0;
    string_content = nullptr;
}

MyString::MyString(const char*  str) {
    std::cout << "Constructor MyString(const char* str) is called" << std::endl;
    string_length = strlen(str);
    memory_capacity = string_length;

    string_content = new char[string_length];

    for (int i = 0; i < string_length; i++) {
        string_content[i] = str[i];
    }
}

MyString::MyString(const MyString&  str) {
    std::cout << "Constructor MyString(const MyString& str) is called" << std::endl;
    string_length = str.string_length;
    memory_capacity = str.string_length;

    string_content = new char[string_length];

    for (int i = 0; i < string_length; i++) {
        string_content[i] = str.string_content[i];
    }
}

MyString::MyString(MyString&& str) noexcept {
    std::cout << "Constructor MyString(const MyString&& str) is called" << std::endl;
    string_length = str.string_length;
    string_content =  str.string_content;
    memory_capacity = str.memory_capacity;

    str.string_content = nullptr;
}

MyString::~MyString() {
    if (string_content) {
        delete[] string_content;
    }
}

void MyString::reserve(int size) {
    if (size > memory_capacity) {
        char* prev_string_content = string_content;

        string_content = new char[size];
        memory_capacity = size;

        for (int i = 0; i < string_length; i++) {
            string_content[i] = prev_string_content[i];
        }

        if (prev_string_content != nullptr) {
            delete[] prev_string_content;
        }
    }
}

MyString MyString::operator+(const MyString& str) {
    MyString result;
    result.reserve(string_length + str.string_length);

    for (int i = 0; i < string_length; i++) {
        result.string_content[i] = string_content[i];
    }
    
    for (int i = 0; i < str.string_length; i++) {
        result.string_content[string_length + i] = str.string_content[i];
    }

    result.string_length = string_length + str.string_length;

    return result;
}

void MyString::println() {
    for (int i = 0; i < string_length; i++) {
        std::cout << string_content[i];
    }

    std::cout << std::endl;
}

int main() {
    MyString s("abc");
    std::vector<MyString> vec;
    vec.resize(0);

    std::cout << "first elem" << std::endl;
    vec.push_back(s);

    std::cout << "second elem" << std::endl;
    vec.push_back(s);

    std::cout << "third elem" << std::endl;
    vec.push_back(s);
}
