#include <iostream>
#include <string>

class Person {
public:
	Person() {}

	Person(
		const std::string &first_name,
		const std::string &middle_name,
		const std::string &last_name) : m_first_name{first_name},
										m_middle_name{middle_name},
										m_last_name{last_name} {
	}

	std::string get_first_name() const { return m_first_name; }
	std::string get_middle_name() const { return m_middle_name; }
	std::string get_last_name() const { return m_last_name; }

private:
	std::string m_first_name;
	std::string m_middle_name;
	std::string m_last_name;
};

std::ostream &operator<<(std::ostream &os, const Person &person) {
	os << person.get_first_name() << ' '
	   << person.get_middle_name() << ' '
	   << person.get_last_name();
	return os;
}


void reception(const Person& p) {
	std::cout << "Hello, " << p.get_first_name() << std::endl;
}



class Student : public Person {
public:
	Student(
		const std::string &first_name,
		const std::string &second_name,
		const std::string &third_name,
		const std::string &group)
			: Person{first_name, second_name, third_name},
		  m_group{group} {}

	std::string group() const { return m_group; }

private:
	std::string m_group;
};

std::ostream &operator<<(std::ostream &os, const Student &student) {
	// Call the operactor<< for the base part of the Student object (Person)
	os << static_cast<const Person &>(student);
	// And then print the rest part - group field
	os << " Group: " << student.group();
	return os;
}



int main() {

	Person person{
		"Ivan",
		"Ivanovich",
		"Ivanov"};

	std::cout << person << std::endl;

	reception(person);

	Student student{
		"Ivan", "Ivanovich", "Ivanov", // Person part
		"C++ basics"					// Student part
	};

	std::cout << student << std::endl;

	reception(student); // !!! This is the key idea!

	std::cout << "Let's see sizes:" << std::endl;
	std::cout << "\tsizeof(std::string) = " << sizeof(std::string) << std::endl;
	std::cout << "\tsizeof(Person) = " << sizeof(Person) << std::endl;
	std::cout << "\tsizeof(Student) = " << sizeof(Student) << std::endl;

	return 0;
}