#include <iostream>

template <typename... Ints>
int sum_all(Ints... nums) {
    return (... + nums);

}

int main() {
    std::cout << sum_all(1,2,3,4,5) << std::endl;

    return 0;
}
