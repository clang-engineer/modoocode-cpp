#include <iostream>
#include <unordered_set>

template <typename K>
void print_unordered_set(const std::unordered_set<K>& m) {
    for (const auto& elem : m) {
        std::cout << elem << std::endl;
    }
}

class Todo {
    private:
        int priority;
        std::string job_desc;
    public:
        Todo(int priority, std::string job_desc): priority(priority), job_desc(job_desc) {}

        bool operator==(const Todo& t) const {
            if (priority == t.priority && job_desc == t.job_desc) {
                return true;
            } else {
                return false;
            }
        }

        friend std::ostream& operator<<(std::ostream& o, const Todo& todo);
        friend struct std::hash<Todo>;
};

namespace std {
    template<>
        struct hash<Todo> {
            size_t operator()(const Todo& todo) const {
                hash<string> hash_func;
                return todo.priority ^ (hash_func(todo.job_desc));
            }
        };
}

std::ostream& operator<<(std::ostream& os, const Todo& todo) {
    os << "priority: " << todo.priority << " -> " << todo.job_desc;
    return os;
}

int main() {
    std::unordered_set<Todo> todos;

    todos.insert(Todo(1, "test a"));
    todos.insert(Todo(2, "test b"));
    todos.insert(Todo(1, "test c"));
    todos.insert(Todo(2, "test d"));
    todos.insert(Todo(3, "test e"));
    print_unordered_set(todos);

}
