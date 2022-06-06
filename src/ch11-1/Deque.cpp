#include <iostream>
#include <deque>

template <typename T>
void print_deque(std::deque<T>* deq) {
    for (typename std::deque<T>::iterator itr = deq->begin(); itr != deq->end(); itr++) {
        std::cout << *itr << std::endl;
    }
}

int main() {
    std::deque<int> deq;

    deq.push_front(10);
    deq.push_back(20);
    deq.push_front(30);
    deq.push_back(40);
    deq.push_front(50);

    std::cout << "int deque" << std::endl;
    print_deque(&deq);

    
    std::cout << "remove first elem" << std::endl;
    deq.pop_front();
    print_deque(&deq);

    return 0;
}
