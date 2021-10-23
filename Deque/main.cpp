#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

template<typename T>
void Display(const std::deque<T>& d) {
	std::cout << "[ ";
	for (const auto& elem : d) {
		std::cout << elem << " ";
	}
	std::cout << "]" << std::endl;
}

template <typename T>
void Display2(const std::vector<T>& vec) {
	std::cout << "[ ";
	for (const auto& elem : vec)
		std::cout << elem << " ";
	std::cout << "]" << std::endl;
}

void Test1(){
	 std::deque<int> d{ 1,2,3,4,5 };
	 Display(d);

	 d = { 2,4,5,6 };
	 Display(d);

	 std::deque<int> d1(10, 100);
	 Display(d1);

	 d[0] = 100;
	 d.at(1) = 200;
	 Display(d);
 }

void Test2(){
	 std::deque<int> d{ 0,0,0 };
	 Display(d);

	 d.push_back(10);
	 d.push_back(20);
	 Display(d);

	 d.push_front(100);
	 d.push_front(200);
	 Display(d);

	 std::cout << "Front: " << d.front() << std::endl;
	 std::cout << "Back: " << d.back() << std::endl;
	 std::cout << "Size: " << d.size() << std::endl;

	 d.pop_back();
	 d.pop_front();
	 Display(d);
 }

void Test3(){
	 std::vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	 std::deque<int> d;

	 Display(d);
	 Display2(vec);

	 for (const auto& elem : vec) {
		 if (elem % 2 == 0)
			 d.push_back(elem);
		 else
			 d.push_front(elem);
	 }

	 Display(d);
 }

void Test4(){
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	std::deque<int> d;

	Display(d);
	Display2(vec);

	for (const auto& elem : vec) {
		d.push_front(elem);
	}

	Display(d);

	d.clear();

	for (const auto& elem : vec) {
		d.push_back(elem);
	}

	Display(d);
}

void Test5(){
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	std::deque<int> d;

	Display(d);
	Display2(vec);

	std::copy(vec.begin(), vec.end(), std::front_inserter(d));
	Display(d);

	d.clear();

	std::copy(vec.begin(), vec.end(), std::back_inserter(d));
	Display(d);
}

int main() {
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();

	return 0;
}