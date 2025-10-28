#include "app.h"
#include <iostream>

using namespace vsite::oop::v3;

// read number of results
// read all student data
// read grade and output grade statistics
// read letter and output letter statistics
int main()
{

	std::cout << "Enter number of students: ";
	unsigned n;
	std::cin >> n;
	results r(n);

	std::string name;
	int grade;

	for (unsigned i = 0; i < n; i++)
	{
		std::cout << "Enter " << i + 1 << ". student's name : ";
		std::cin >> name;
		std::cout << "Enter student grade: ";
		std::cin >> grade;
		r.add({ name, grade });
	}

	std::cout << "Enter grade to check: ";
	std::cin >> grade;
	std::cout << "Number of students with grade " << grade << ": " << r.has_grade(grade) << std::endl;
	char letter;
	std::cout << "Enter starting letter to check: ";
	std::cin >> letter;
	std::cout << "Number of students starting with letter " << letter << ": " << r.starts_with_letter(letter) << std::endl;
}
