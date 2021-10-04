// #includes are pre-processor directives, they don't take semi-colons at the end
#include <iostream>	// The standard input output library, used for things like cin and cout

int main()	// Main entry point of a program
{
	// The '<<' is the insertion operator, which inserts into a stream.
	// '>>' is the extraction operator which grabs whatever the user types in and stores it.
	// Whatever is entered between the quote marks "" is a string literal.
	// "String literals. A string literal represents a sequence of characters that together form a null-terminated string. The characters must be enclosed between double quotation marks."
	// https://docs.microsoft.com/en-us/cpp/cpp/string-and-character-literals-cpp?view=msvc-160
	// All statements (i.e., a line of code) end in a semi-colon.
	// 'cout' writes to the console, 'cin' reads from the console

	int favourite_number;

	std::cout << "Enter your favourite number between 1 and 100:";

	std::cin >> favourite_number;

	std::cout << "Amazing! That's my favourite number too!" << std::endl;

	return 0;	// If the program runs all good, return a 0
}