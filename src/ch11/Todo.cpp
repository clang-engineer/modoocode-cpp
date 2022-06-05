#include <iostream>
#include <set>

template <typename T>
void print_set(std::set<T>& todos) {
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
        bool operator<(const Todo todo) const {
            if (priority == todo.priority) {
                return job_desc < todo.job_desc;
            }
            return priority > todo.priority;
        }

        friend std::ostream& operator<<(std::ostream& os, const Todo& todo);
};

std::ostream& operator<<(std::ostream& os, const Todo& todo) {
    std::cout << "[priority: " << todo.priority << "]: " << todo.job_desc; 
    return os;
}

int main() {
    std::set<Todo> todos;

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
