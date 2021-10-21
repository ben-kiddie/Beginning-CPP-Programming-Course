#include <iostream>
#include <array>
#include <algorithm>
#include <numeric>

template<int x>
void Display(const std::array<int, x>& arr) {
	std::cout << "[";
	for (const auto& i : arr) {
		std::cout << " " << i;
	}
	std::cout << " ]" << std::endl;
}

void Test1() {
	std::array<int, 5> arr1{ 1,2,3,4,5 };
	std::array<int, 5> arr2;

	Display<5>(arr1);
	Display<5>(arr2);

	arr2 = { 10,20,30,40,50 };

	Display<5>(arr1);
	Display<5>(arr2);

	std::cout << "The size of arr1 is " << arr1.size() << std::endl;
	std::cout << "The size of arr2 is " << arr2.size() << std::endl;

	arr1[0] = 1000;
	arr1.at(1) = 2000;
	Display<5>(arr1);

	std::cout << "Front of arr2: " << arr2.front() << std::endl;
	std::cout << "Back of arr2: " << arr2.back() << std::endl;
}

void Test2(){
	std::array<int, 5> arr1{ 1,2,3,4,5 };
	std::array<int, 5> arr2{ 10,20,30,40,50 };

	Display<5>(arr1);
	Display<5>(arr2);

	arr1.fill(0);

	Display<5>(arr1);
	Display<5>(arr2);

	arr1.swap(arr2);

	Display<5>(arr1);
	Display<5>(arr2);
}

void Test3(){
	std::array<int, 5> arr1{ 1,2,3,4,5 };

	int* ptr = arr1.data();
	std::cout << ptr << std::endl;

	*ptr = 10000;
	Display<5>(arr1);
}

void Test4(){
	std::array<int, 5> arr1{ 2,1,4,5,3 };
	Display<5>(arr1);

	std::sort(arr1.begin(), arr1.end());
	Display<5>(arr1);
}

void Test5(){
	std::array<int, 5> arr1{ 2,1,4,5,3 };

	std::array<int, 5>::iterator minNum = std::min_element(arr1.begin(), arr1.end());

	auto maxNum = std::max_element(arr1.begin(), arr1.end());

	Display<5>(arr1);
	std::cout << "Min: " << *minNum << ", Max: " << *maxNum << std::endl;
}

void Test6(){
	std::array<int, 5> arr1{ 2,1,3,3,5 };

	auto adjacent = std::adjacent_find(arr1.begin(), arr1.end());
	Display<5>(arr1);
	if (adjacent != arr1.end())
		std::cout << "Adjacent element found with value: " << *adjacent << std::endl;
	else
		std::cout << "No adjacent elements" << std::endl;
}

void Test7(){
	std::array<int, 5> arr1{ 1,2,3,4,5 };

	int sum = std::accumulate(arr1.begin(), arr1.end(), 0);
	Display<5>(arr1);
	std::cout << "Sum total: " << sum << std::endl;
}

void Test8(){
	std::array<int, 10> arr1{ 1,2,3,1,2,3,3,3,3,3 };

	int count = std::count(arr1.begin(), arr1.end(), 3);
	Display<10>(arr1);
	std::cout << "Instances of 3: " << count << std::endl;
}

void Test9() {
	std::array<int, 10> arr1{ 1,2,3,50,60,70,80,200,300,400 };

	int count = std::count_if(arr1.begin(), arr1.end(), [](int x) {return x >= 10 && x <= 200; });
	Display<10>(arr1);
	std::cout << "Found " << count << " matches of values between 10 and 200" << std::endl;
}

int main() {
	//Test1();
	//Test2();
	//Test3();
	//Test4();
	//Test5();
	//Test6();
	//Test7();
	//Test8();
	//Test9();

	return 0;
}