#include <iostream>
#include <memory>
#include <vector>

class A {
    private:
        int *data;

    public:
        A() {
            std::cout << "Constructor A()" << std::endl;
            data = new int[100];
        }
        ~A() {
            std::cout << "Destructor ~A()" << std::endl;
            delete[] data;
        }

};

int main() {
    std::vector<std::shared_ptr<A>> vec;

    vec.push_back(std::shared_ptr<A>(new A()));
    vec.push_back(std::shared_ptr<A>(vec[0]));
    vec.push_back(std::shared_ptr<A>(vec[1]));

    std::cout << "remove first" << std::endl;
    vec.erase(vec.begin());

    std::cout << "remove second" << std::endl;
    vec.erase(vec.begin());

    std::cout << "remove third" << std::endl;
    vec.erase(vec.begin());
}
