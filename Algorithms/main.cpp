#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>

class Person {
	std::string name;
	int age;
public:
	Person() = default;
	Person(std::string name, int age) : name{ name }, age{ age } {}
	bool operator<(const Person &rhs) const {
		return this->age < rhs.age;
	}
	bool operator==(const Person& rhs) const {
		return (this->name == rhs.name && this->age == rhs.age);
	}
};

void FindTest() {
	std::vector<int> vec{ 1,2,3,4,5 };
	
	auto loc = std::find(std::begin(vec), std::end(vec), 1);
	
	if (loc != std::end(vec))
		std::cout << "Found the number " << *loc << std::endl;
	else
		std::cout << "Could not find number" << std::endl;

	std::list<Person> players{
		{"Larry", 18},
		{"Moe", 20},
		{"Curly", 21}
	};

	auto loc1 = std::find(std::begin(players), std::end(players), Person("Moe", 20));

	if (loc1 != std::end(players))
		std::cout << "Found player" << std::endl;
	else
		std::cout << "Could not find player" << std::endl;
}

void CountTest() {
	std::vector<int> vec{ 1,2,3,4,5,1,2,1 };
	int count = std::count(std::begin(vec), std::end(vec), 1);
	std::cout << count << " occurence(s) of number " << 1 << std::endl;
	count = std::count(std::begin(vec), std::end(vec), 6);
	std::cout << count << " occurence(s) of number " << 6 << std::endl;
}

void CountIfTest() {
	std::vector<int> vec{ 1,2,3,4,5,1,2,1,100 };
	int num = std::count_if(std::begin(vec), std::end(vec), [](int x) {return x % 2 == 0; });	// Only count a number if it is even and output to console the total even nums
	std::cout << num << " even numbers found" << std::endl;
	num = std::count_if(std::begin(vec), std::end(vec), [](int x) {return x % 2 != 0; });	// Count odd numbers, output to console
	std::cout << num << " odd numbers found" << std::endl;
	num = std::count_if(std::begin(vec), std::end(vec), [](int x) {return x >= 5; });
	std::cout << num << " numbers >= 5" << std::endl;
}

void ReplaceTest() {
	std::vector<int> vec{ 1,2,3,4,5,1,2,1 };
	for (auto i : vec) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	std::replace(vec.begin(), vec.end(), 1, 100);	// Replace instances of 1 with 100 and output to console
	for (auto i : vec) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
}

void AllOfTest() {
	std::vector<int> vec{ 1,3,5,7,9,1,3,13,19,5 };
	if (std::all_of(vec.begin(), vec.end(), [](int x) {return x > 10; }))
		std::cout << "All elements are > 10" << std::endl;
	else
		std::cout << "Not all elements are > 10" << std::endl;

	if (std::all_of(vec.begin(), vec.end(), [](int x) {return x < 20; }))
		std::cout << "All elements are < 20" << std::endl;
	else
		std::cout << "Not all elements are < 20" << std::endl;
}

void AnyOfTest() {
	std::vector<int> vec{ 1,3,5,7,9,1,3,13,19,5 };
	if (std::any_of(vec.begin(), vec.end(), [](int x) {return x == 1; }))
		std::cout << "At least one number == 1" << std::endl;
	else
		std::cout << "No occurences of number 1" << std::endl;
}

void StringTransformTest() {
	std::string str1{ "This is a test" };
	std::cout << "Before transform: " << str1 << std::endl;
	std::transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
	std::cout << "After transform: " << str1 << std::endl;
	std::transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
	std::cout << "After transform two: " << str1 << std::endl;
}

int main() {
	//FindTest();
	//CountTest();
	//CountIfTest();
	//ReplaceTest();
	//AllOfTest();
	//AnyOfTest();
	//StringTransformTest();
	return 0;
}