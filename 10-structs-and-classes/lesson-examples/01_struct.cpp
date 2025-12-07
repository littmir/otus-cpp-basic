#include <iostream>
#include <string>

namespace motivation {
    // Say: mutable ref
    void get_user_info(std::string& name, std::string& surname, int& age) {
        std::cout << "Hello!" << std::endl;

        std::cout << "Enter your name:" << std::endl;
        std::cin >> name;

        std::cout << "Enter your surname:" << std::endl;
        std::cin >> surname;

        std::cout << "Enter your age:" << std::endl;
        std::cin >> age;
    }

    void example() {
        std::string name;
        std::string surname;
        int age{};

        get_user_info(name, surname, age);

        if (age < 16) {
            std::cout << "Access denied!" << std::endl;
        } else if (age < 30) {
            std::cout << "Hello, " << name << std::endl;
        } else {
            std::cout << "Hello, " << name << " " << surname << std::endl;
        }
    }

} // namespace motivation

namespace structures {

    // Объединяет данные, относящиеся к одной сущности, реализуя принцип абстракции
    // Пользовательский тип
    // Say: syntax
    struct Person {
        std::string name;
        std::string surname = "Ivanov";
        int age;
    };

    Person get_user_info() {
        // объект типа Person
        Person person;

        std::cout << "Hello!" << std::endl;

        std::cout << "Enter your name:" << std::endl;
        std::cin >> person.name;

        std::cout << "Enter your surname:" << std::endl;
        std::cin >> person.surname;

        std::cout << "Enter your age:" << std::endl;
        std::cin >> person.age;

        return person;
    }

    void example() {
        const Person person = get_user_info();
        // Say: Person.age, Person::age - err

        if (person.age < 16) {
            std::cout << "Access denied!" << std::endl;
        } else if (person.age < 30) {
            std::cout << "Hello, " << person.name << std::endl;
        } else {
            std::cout << "Hello, " << person.name << " " << person.surname << std::endl;
        }
        // Say: const Person
    }
} // namespace structures

namespace object_as_field {
    struct Biometrics {
        int one;
        int another;
        //...
    };

    struct Person {
        std::string name;
        std::string surname = "Ivanov";
        int age;
        Biometrics biometrics;
    };

    void example() { Person p; }
} // namespace object_as_field

int main() {
    motivation::example();
    structures::example();
    object_as_field::example();
}
