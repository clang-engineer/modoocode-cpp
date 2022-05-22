#include <iostream>

class Animal {
    private:
        int food;
        int weight;

    public:
        void set_animal(int _food, int _weight) {
            food = _food;
            weight = _weight;
        }

        void increase_food(int inc){
            food +=inc;
            weight +=(inc/3);
        }

        void view_stat() {
            std::cout << "food is : " << food <<std::endl;
            std::cout << "weight is : " << weight <<std::endl;
        }
};

int main(){
    Animal animal;
    animal.set_animal(10,10);

    animal.view_stat();
}
