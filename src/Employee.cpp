#include <iostream>
#include <string>

class Employee {
    protected:
        std::string name;
        int age;

        std::string position;
        int rank;

    public:
        Employee(std::string name, int age, std::string position, int rank)
            : name(name), age(age), position(position), rank(rank){}

        Employee(const Employee& employee) {
            name = employee.name;
            age = employee.age;
            position = employee.position;
            rank = employee.rank;
        }

        Employee() {}

        void print_info() {
            std::cout << name << " (" << position << ", " << age << ") ==> " <<  calculate_pay() << std::endl;
        }

        int calculate_pay() {
            return 200 + rank * 50;
        }

};

class Manager: public Employee {
    private:
        int year_of_service;

    public:
        Manager(std::string name, int age, std::string position, int rank, int year_of_service)
            : year_of_service(year_of_service), Employee(name, age, position, rank) {}

        Manager(const Manager& manager)
            : Employee(manager.name, manager.age, manager.position, manager.rank) {
                year_of_service = manager.year_of_service;
            }

        Manager(): Employee() {}

        int calculate_pay() {
            return 200 + rank * 50 + 5 * year_of_service;
        }

        void print_info() {
            std::cout << name << " (" << position << ", " << age << "," << year_of_service << "year work) ==> " <<  calculate_pay() << std::endl;
        }

};


class EmployeeList {
    private: 
        int alloc_employee;
        int current_employee;
        Employee** employee_list;

    public:
        EmployeeList(int alloc_employee): alloc_employee(alloc_employee) {
            employee_list = new Employee*[alloc_employee];
            current_employee = 0;
        }

        void add_employee(Employee* employee) {
            employee_list[current_employee] = employee;
            current_employee++;
        }

        int current_employ_num() {
            return current_employee;
        }

        void print_employee_info() {
            int total_pay = 0;
            for (int i=0; i<current_employee; i++) {
                employee_list[i]->print_info();
                total_pay += employee_list[i]->calculate_pay();
            }
            std::cout << "total paymenu: " << total_pay << std::endl;
        }

        ~EmployeeList() {
            for (int i=0; i<current_employee; i++) {
                delete employee_list[i];
            }

            delete[] employee_list;
        }
};

int main() {
    EmployeeList emp_list(10);
    emp_list.add_employee(new Employee("NoHongCheol", 34, "tester1", 1));
    emp_list.add_employee(new Employee("HaHa", 34, "tester2", 2));

    emp_list.add_employee(new Manager("YooJaeSuk", 41, "manager1", 3, 3));
    emp_list.add_employee(new Manager("JeongJunHa", 43, "manager2", 4, 4));
    emp_list.add_employee(new Manager("BarkMyeongSu", 43, "manager3", 5, 5));
    emp_list.add_employee(new Employee("JeongHyeongDon", 36, "tester4", 6));
    emp_list.add_employee(new Employee("Gil", 36, "teste5", 7));

    emp_list.print_employee_info();
    return 0;
}
