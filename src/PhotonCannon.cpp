#include <iostream>
#include <string.h>


class PhotonCanon {
    private:
        int hp, shield;
        int coord_x, coord_y;
        int damage;
        char* name;

    public:
        PhotonCanon(int x, int y);
        PhotonCanon(int x, int y,const char* name);
        PhotonCanon(const PhotonCanon &pc);
        ~PhotonCanon();

        void showStatus();
};

PhotonCanon::PhotonCanon(int x, int y){
    hp=shield =100;
    coord_x = x;
    coord_y = y;

    damage=20;

    name= NULL;
};


PhotonCanon::PhotonCanon(int x, int y,const char *cannon_name){
    hp=shield =100;
    coord_x = x;
    coord_y = y;

    damage=20;

    name = new char[strlen(cannon_name) + 1];

    strcpy(name,cannon_name);

};

PhotonCanon::PhotonCanon(const PhotonCanon& pc){
    hp=pc.hp;
    shield = pc.shield;
    coord_x = pc.coord_x;
    coord_y = pc.coord_y;
    damage = pc.damage;


    name = new char[strlen(pc.name) + 1];
    strcpy(name, pc.name);
};

void PhotonCanon::showStatus() {
    std::cout << "PhotonCanon :: " << name << std::endl;
    std::cout << "Location :: (" << coord_x << "," << coord_y << ")" << std::endl;
    std::cout << "HP :: " << hp << std::endl;
};

PhotonCanon::~PhotonCanon(){
    if(name){
        delete[] name;
    };
};


int main(){
    PhotonCanon pc1(3,3, "cannon");
    PhotonCanon pc2 = pc1;

    pc1.showStatus();
    pc2.showStatus();
};
