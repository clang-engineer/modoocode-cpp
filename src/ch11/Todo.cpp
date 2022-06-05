#include <iostream>
#include <set>

template <typename T, typename C>
void print_set(std::set<T, C>& todos) {
    for (const auto& elem : todos) {
        std::cout << elem << std::endl;
    }
}

class Todo {
    private:
        int priority;
        std::string job_desc;
    public:
        Todo(int priority, std::string job_desc): priority(priority), job_desc(job_desc) {}

        friend struct TodoComp;

        friend std::ostream& operator<<(std::ostream& os, const Todo& todo);
};

struct TodoComp {
    bool operator()(const Todo& t1, const Todo& t2) const {
        if (t1.priority == t2.priority) {
            return t1.job_desc < t2.job_desc;
        }

        return t1.priority > t2.priority;
    }
};

std::ostream& operator<<(std::ostream& os, const Todo& todo) {
    std::cout << "[priority: " << todo.priority << "]: " << todo.job_desc; 
    return os;
}

int main() {
    std::set<Todo, TodoComp> todos;

    std::cout << "=== init todos ===" << std::endl;
    todos.insert(Todo(1, "todo 1"));
    todos.insert(Todo(1, "todo 3"));
    todos.insert(Todo(1, "todo 2"));
    todos.insert(Todo(2, "todo 2"));
    todos.insert(Todo(3, "todo 3"));
    todos.insert(Todo(4, "todo 4"));
    todos.insert(Todo(5, "todo 5"));

    print_set(todos);

    std::cout << "=== after remove ===" << std::endl;
    todos.erase(todos.find(Todo(2, "todo 2")));
    print_set(todos);
}
