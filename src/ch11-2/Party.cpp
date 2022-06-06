#include <iostream>
#include <vector>
#include <algorithm>

struct User {
    std::string name;
    int level;

    User(std::string name, int level): name(name), level(level) {}
    bool operator==(const User& user) const {
        if (level == user.level && name == user.name) {
            return true;
        } 
        return false;
    }
};

class Party {
    private:
        std::vector<User> users;
    public:
        bool add_user(const User& user) {
            User new_user(user.name, user.level);
            std::vector<User>::iterator result = std::find(users.begin(), users.end(), new_user);

            if (result != users.end()) {
                return false;
            }

            users.push_back(User(user.name, user.level));
            return true;
        }

        bool can_join_dungeon() {
            return std::all_of(users.begin(), users.end(), 
                    [] (User& user) -> bool {
                    return user.level >= 15;
                    });
        }

        bool can_use_special_item() {
            return std::any_of(users.begin(), users.end(), 
                    [] (User& user) -> bool {
                        return user.level >= 19;
                    });
        }
};

int main() {
    Party party;

    party.add_user(User("user a", 15));
    party.add_user(User("user b", 16));
    party.add_user(User("user c", 17));
    party.add_user(User("user d", 18));
    party.add_user(User("user e", 18));

    std::cout << std::boolalpha;
    std::cout << "can join dungeon ? " << party.can_join_dungeon() << std::endl;
    std::cout << "can use special item ? " << party.can_use_special_item() << std::endl;
}
