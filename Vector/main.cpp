#include <iostream>
#include <vector>
#include <algorithm>

class Person {
	friend std::ostream& operator<<(std::ostream& os, const Person& p);
	std::string name;
	int age;
public:
	Person() = default;
	Person(std::string name, int age)
		: name(name), age(age) {}
	bool operator<(const Person& rhs) const {
		return(this->age < rhs.age);
	}
	bool operator==(const Person &rhs) const {
		return(this->name == rhs.name && this->age == rhs.age);
	}
};

std::ostream& operator<<(std::ostream& os, const Person& p) {
	os << p.name << " : " << p.age;
	return os;
}

void Display2(const std::vector<int>& vec) {
	std::cout << "[ ";
	std::for_each(vec.begin(), vec.end(), [](int x) {std::cout << x << " "; });
	std::cout << "]" << std::endl;
}

template <typename T>
void Display(const std::vector<T>& vec) {
	std::cout << "[ ";
	for (const auto& elem : vec)
		std::cout << elem << " ";
	std::cout << "]" << std::endl;
}

 void Test1(){
	 std::vector<int> vec {1, 2, 3, 4, 5};
	 
	 Display(vec);

	 vec = { 2,4,5,6 };

	 Display2(vec);

	 std::vector<int> vec1(10, 100);
	 Display(vec1);
 }

 void Test2(){
	 std::vector<int> vec{ 1,2,3,4,5 };
	 Display(vec);

	 std::cout << "\nvec size: " << vec.size() << std::endl;
	 std::cout << "vec max size: " << vec.max_size() << std::endl;
	 std::cout << "vec capacity: " << vec.capacity() << std::endl;

	 vec.push_back(6);
	 Display(vec);
	 std::cout << "\nvec size: " << vec.size() << std::endl;
	 std::cout << "vec max size: " << vec.max_size() << std::endl;
	 std::cout << "vec capacity: " << vec.capacity() << std::endl;

	 vec.shrink_to_fit();
	 Display(vec);
	 std::cout << "\nvec size: " << vec.size() << std::endl;
	 std::cout << "vec max size: " << vec.max_size() << std::endl;
	 std::cout << "vec capacity: " << vec.capacity() << std::endl;

	 vec.reserve(100);
	 Display(vec);
	 std::cout << "\nvec size: " << vec.size() << std::endl;
	 std::cout << "vec max size: " << vec.max_size() << std::endl;
	 std::cout << "vec capacity: " << vec.capacity() << std::endl;
 }

 void Test3(){
	 std::vector<int> vec{ 1,2,3,4,5 };
	 Display(vec);

	 vec[0] = 100;
	 vec.at(1) = 200;

	 Display(vec);
 }

 void Test4(){
	 std::vector<Person> stooges;
	 Display(stooges);

	 Person p1{ "Larry", 18 };
	 stooges.push_back(p1);
	 Display(stooges);

	 stooges.push_back(Person("Moe", 25));
	 Display(stooges);

	 stooges.emplace_back("Curly", 30);
	 Display(stooges);
 }

 void Test5(){
	 std::vector<Person> stooges{
		 {"Larry", 18},
		 {"Moe", 25},
		 {"Curly", 30}
	 };

	 Display(stooges);
	 std::cout << "\nFront: " << stooges.front() << std::endl;
	 std::cout << "Back: " << stooges.back() << std::endl;

	 stooges.pop_back();
	 Display(stooges);
	 std::cout << "Back: " << stooges.back() << std::endl;
 }

 void Test6(){
	 std::vector<int> vec{ 1,2,3,4,5 };
	 Display(vec);

	 vec.clear();
	 Display(vec);

	 vec = { 1,2,3,4,5,6,7,8,9,10 };
	 Display(vec);

	 vec.erase(vec.begin(), vec.begin() + 2);
	 Display(vec);

	 vec = { 1,2,3,4,5,6,7,8,9,10 };
	 auto it = vec.begin();
	 while (it != vec.end()) {
		 if (*it % 2 == 0)
			 //vec.erase(it);	// This does not work, at least in VS2019. The iterator becomes invalid once the element it points to is erased.
			 it = vec.erase(it);	// However, this does work. This is because the .erase() method returns a new, valid iterator.
		 else
			 it++;
	 }
	 Display(vec);
 }

 void Test7(){
	 std::vector<int> vec1{ 1,2,3,4,5 };
	 std::vector<int> vec2{ 10,20,30,40,50 };

	 Display(vec1);
	 Display(vec2);
	 vec1.swap(vec2);
	 Display(vec1);
	 Display(vec2);
 }

 void Test8(){
	 std::vector<int> vec{ 1,21,3,40,12 };
	 Display(vec);

	 std::sort(vec.begin(), vec.end());
	 Display(vec);
 }

 void Test9(){
	 std::vector<int> vec1{ 1,2,3,4,5 };
	 std::vector<int> vec2{ 10,20 };

	 Display(vec1);
	 Display(vec2);

	 std::copy(vec1.begin(), vec1.end(), std::back_inserter(vec2));
	 Display(vec1);
	 Display(vec2);

	 vec1 = { 1,2,3,4,5,6,7,8,9,10 };
	 vec2 = { 10,20 };

	 Display(vec1);
	 Display(vec2);
	 std::copy_if(vec1.begin(), vec1.end(), std::back_inserter(vec2), [](int x) {return x % 2 == 0; });

	 Display(vec1);
	 Display(vec2);
 }

 void Test10(){
	 std::vector<int> vec1{ 1,2,3,4,5 };
	 std::vector<int> vec2{ 10,20,30,40,50 };
	 std::vector<int> vec3;

	 // 1*10, 2*20, 3*30, 4*40, 5*50, store result in vec3
	 std::transform(vec1.begin(), vec1.end(), vec2.begin(), std::back_inserter(vec3), [](int x, int y) {return x * y; });
	 Display(vec3);
 }

 void Test11(){
	 std::vector<int> vec1{ 1,2,3,4,5,6,7,8,9,10 };
	 std::vector<int> vec2{ 100,200,300,400,500 };

	 Display(vec1);
	 Display(vec2);

	 auto it = std::find(vec1.begin(), vec1.end(), 5);
	 if (it != vec1.end()) {
		 std::cout << "Inserting..." << std::endl;
		 vec1.insert(it, vec2.begin(), vec2.end());
	 }
	 else {
		 std::cout << "Sorry, 5 could not be found" << std::endl;
	 }

	 Display(vec1);
 }

int main() {
	//Test1();
	Test2();
	//Test3();
	//Test4();
	//Test5();
	//Test6();
	//Test7();
	//Test8();
	//Test9();
	//Test10();
	//Test11();

	return 0;
}