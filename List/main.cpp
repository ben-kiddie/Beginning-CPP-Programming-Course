#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
#include <string>

class Person {
	friend std::ostream& operator<<(std::ostream& os, const Person& p);
	std::string name;
	int age;
public:
	Person() : name("Unknown"), age(0) {}	// Modified the default constructor. Usually you can say 'Person() = default;' and let the compiler initialise.
	Person(std::string name, int age)
		: name(name), age(age) {}
	bool operator<(const Person& rhs) const {
		return(this->age < rhs.age);
	}
	bool operator==(const Person& rhs) const {
		return(this->name == rhs.name && this->age == rhs.age);
	}
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
	os << p.name << " : " << p.age;
	return os;
}

template<typename T>
void Display(const std::list<T>& d) {
	std::cout << "[ ";
	for (const auto& elem : d) {
		std::cout << elem << " ";
	}
	std::cout << "]" << std::endl;
}

void Test1() {
	std::list<int> l1{ 1,2,3,4,5 };
	Display(l1);

	std::list<std::string> l2;
	l2.push_back("Back");
	l2.push_back("Front");
	Display(l2);

	std::list<int> l3;
	l3 = { 1,2,3,4,5,6,7,8,9,10 };
	Display(l3);

	std::list<int> l4(10, 100);
	Display(l4);
}

void Test2() {
	std::list<int> l{ 1,2,3,4,5,6,7,8,9,10 };
	Display(l);
	std::cout << "Size: " << l.size() << std::endl;
	std::cout << "Front: " << l.front() << std::endl;
	std::cout << "Back: " << l.back() << std::endl;

	l.clear();
	Display(l);
	std::cout << "Size: " << l.size() << std::endl;
}

void Test3() {
	std::list<int> l{ 1,2,3,4,5,6,7,8,9,10 };
	Display(l);

	l.resize(5);
	Display(l);

	l.resize(10);
	Display(l);

	std::list<Person> p;
	p.resize(5);
	Display(p);
}

void Test4() {
	std::list<int> l{ 1,2,3,4,5,6,7,8,9,10 };
	Display(l);

	auto it = std::find(l.begin(), l.end(), 5);
	if (it != l.end()) {
		l.insert(it, 100);
	}
	Display(l);

	std::list<int> l2{ 1000,2000,3000 };
	l.insert(it, l2.begin(), l2.end());
	Display(l);

	std::advance(it, -4);
	std::cout << "Deleting: " << *it << std::endl;
	l.erase(it);
	Display(l);
}

void Test5() {
	std::list<Person> stooges{
		{"Larry", 18},
		{"Moe", 25},
		{"Curly", 17}
	};

	Display(stooges);

	std::string name;
	int age{};
	std::cout << "Enter the name of the next stooge: ";
	//getline(std::cin, name);
	std::cin >> name;
	std::cout << "Enter their age: ";
	std::cin >> age;

	stooges.emplace_back(name, age);
	Display(stooges);

	auto it = std::find(stooges.begin(), stooges.end(), Person("Moe", 25));
	if (it != stooges.end()) {
		stooges.emplace(it, "Frank", 18);
	}
	Display(stooges);
}

void Test6() {
	std::list<Person> stooges{
	{"Larry", 18},
	{"Moe", 25},
	{"Curly", 17}
	};

	Display(stooges);
	stooges.sort();
	Display(stooges);
}

int main() {
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	//Test6();

	return 0;
}