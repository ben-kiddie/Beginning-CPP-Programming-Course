#include <iostream>

int main()
{
	int favouriteNumber = 0;

	std::cout << "Section 4 Challenge" << std::endl;
	std::cout << "What is your favourite number between 1 and 100? ";
	std::cin >> favouriteNumber;

	while (favouriteNumber < 1 || favouriteNumber > 100)
	{
		std::cout << "That's not a number between 1 and 100!" << std::endl;
		std::cin >> favouriteNumber;
	}

	std::cout << "Amazing! " << favouriteNumber << " is my favourite number too!" << std::endl;

	return 0;
}