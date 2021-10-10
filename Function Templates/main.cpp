#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

void Display(const std::vector<int>& vec) {
	std::cout << "[";
	for (auto const& i : vec) {
		std::cout << i;
	}
	std::cout << "]";
}

void Test1() {
	std::vector<int> nums1{ 1,2,3,4,5 };
	auto it = nums1.begin();
	std::cout << *it << std::endl;	// Point to 1

	it++;
	std::cout << *it << std::endl;	// Point to 2

	it += 2;
	std::cout << *it << std::endl;	// Point to 4

	it -= 2;
	std::cout << *it << std::endl;	// Point to 2

	it = nums1.end() - 1;
	std::cout << *it << std::endl;	// Point to 5
}

void Test2() {
	std::vector<int> nums1{ 1,2,3,4,5 };
	std::vector<int>::iterator it = nums1.begin();
	
	while (it != nums1.end()) {
		std::cout << *it << std::endl;
		it++;
	}

	it = nums1.begin();
	while (it != nums1.end()) {
		*it = 0;
		it++;
	}

	Display(nums1);
}

void Test3() {
	std::vector<int> nums1{ 1,2,3,4,5 };
	std::vector<int>::const_iterator it1 = nums1.begin();
	//auto it1 = nums1.cbegin();	// This is the same as the line above

	while (it1 != nums1.end()) {
		std::cout << *it1 << std::endl;
		it1++;
	}

	it1 = nums1.begin();
	while (it1 != nums1.end()) {
		//*it1 = 0;	// Error - read only
		std::cout << *it1 << std::endl;
		it1++;
	}
}

void Test4() {
	std::vector<int> vec{ 1,2,3,4 };
	auto it1 = vec.rbegin();
	while (it1 != vec.rend()) {
		std::cout << *it1 << std::endl;
		it1++;
	}

	std::list<std::string> name{ "Larry", "Moe", "Curly" };
	auto it2 = name.crbegin();
	std::cout << *it2 << std::endl;
	it2++;
	std::cout << *it2 << std::endl;

	std::map<std::string, std::string> favourites{
		{"Frank", "C++"},
		{"Bill", "Java"},
		{"James", "Haskell"}
	};
	auto it3 = favourites.begin();
	while (it3 != favourites.end()) {
		std::cout << it3->first << " : " << it3->second << std::endl;
		it3++;
	}
}

void Test5() {
	std::vector<int> vec{ 1,2,3,4,5,6,7,8,9,10 };
	auto start = vec.begin() + 2;
	auto finish = vec.end() - 3;

	while (start != finish) {
		std::cout << *start << std::endl;
		start++;
	}
}

int main() {
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();

	return 0;
}