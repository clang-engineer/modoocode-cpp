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

        MyString &operator=(const MyString& s);

        ~MyString();

        int length() const;

        void println();
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
    str.string_length = 0;
    str.memory_capacity = 0;
}


MyString &MyString::operator=(const MyString& s) {
    std::cout << "Call operator=" << std::endl;
    if (s.string_length > memory_capacity) {
        delete[] string_content;
        string_content = new char[s.string_length];
        memory_capacity = s.string_length;
    }

    string_length = s.string_length;
    for (int i = 0; i != string_length; i++) {
        string_content[i] = s.string_content[i];
    }

    return *this;
};

MyString::~MyString() {
    if (string_content) {
        delete[] string_content;
    }
}

int MyString::length() const {
    return string_length;
}

void MyString::println() {
    for (int i = 0; i < string_length; i++) {
        std::cout << string_content[i];
    }

    std::cout << std::endl;
}

template <typename T>
void my_swap(T &a, T &b) {
    T tmp(std::move(a));
    a = std::move(b);
    b = std::move(tmp);
}

int main() {
    MyString str1("abc");
    MyString str2("def");

    std::cout << "Before Swap ========" << std::endl;
    str1.println();
    str2.println();

    std::cout << "After Swap ========" << std::endl;
    my_swap(str1, str2);
    str1.println();
    str2.println();
}
