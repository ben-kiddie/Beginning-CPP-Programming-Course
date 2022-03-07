#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
	int score{ 100 };
	int* score_ptr{ &score };

	cout << "score is: " << score << endl;
	cout << "score_ptr is: " << *score_ptr << endl;
	*score_ptr = 200;
	cout << "score is: " << score << endl;
	cout << "score_ptr is: " << *score_ptr << endl;

	double high_temp{ 100.7 };
	double low_temp{ 37.4 };
	double* temp_ptr{ &high_temp };

	cout << "\nhigh_temp address is " << &high_temp << endl;
	cout << "low_temp address is " << &low_temp << endl;
	cout << "temp_ptr value is " << temp_ptr << endl;
	cout << "temp_ptr dereferenced value: " << *temp_ptr << endl;
	temp_ptr = &low_temp;
	cout << "temp_ptr value is " << temp_ptr << endl;
	cout << "temp_ptr dereferenced value: " << *temp_ptr << endl;

	string name{ "Frank" };
	string* string_ptr{ &name };

	cout << "\nname value is " << name << endl;
	cout << "name address is " << &name << endl;
	cout << "string_ptr value is " << string_ptr << endl;
	cout << "string_ptr dereferenced value is " << *string_ptr << endl;
	name = "James";
	cout << "name value is " << name << endl;
	cout << "name address is " << &name << endl;
	cout << "string_ptr value is " << string_ptr << endl;
	cout << "string_ptr dereferenced value is " << *string_ptr << endl;

	vector<string> stooges{ "Larry", "Moe", "Curly" };
	vector<string>* vector_ptr{ nullptr };

	vector_ptr = &stooges;
	cout << "\nFirst stooge: " <<  (*vector_ptr).at(0) << endl;
	cout << "Stooges: ";
	for (auto stooge : *vector_ptr)
	{
		cout << stooge << " ";
	}
	cout << endl;

	return 0;
}