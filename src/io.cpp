#include <iostream>

int main(){
    int lucky_number=3;
    std::cout<< "input value test " <<std::endl;

    int user_input;

    while(1) {
        std::cout << "input: ";
        std::cin >> user_input;
        if (lucky_number == user_input) {
            std::cout << "correct" << std::endl;
            break;
        }
    }
}
