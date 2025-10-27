#include "app.h"
#include <algorithm>

namespace vsite::oop::v3
{
	// CLASS Results

	// constructor
	results::results(unsigned capacity) : capacity(capacity), count(0)
	{
		students = new student[capacity];
	}
	// destructor
	results::~results()
	{
		delete[] students;
	}

	
	// add function - adds a student to the results
	void results::add(const student& s)
	{
		if (count < capacity)
		{
			students[count] = s;
			++count;
		}
	}
	// has_grade function - counts how many students have the specified grade
	unsigned results::has_grade(int grade) const
	{
		unsigned grade_count = 0;
		for (unsigned i = 0; i < count; ++i)
		{
			if (students[i].grade == grade)
			{
				++grade_count;
			}
		}
		return grade_count;
	}
	// starts_with_letter function - counts how many students' names start with the specified letter
	unsigned results::starts_with_letter(char letter) const
	{
		unsigned letter_count = 0;
		for (unsigned i = 0; i < count; ++i)
		{
			if (std::tolower(students[i].name[0]) == std::tolower(letter))
			{
				++letter_count;
			}
		}
		return letter_count;
	}


	// CLASS Array

	// default constructor
	array::array() : size_(0), data(nullptr) {};

	// constructor with size and value
	array::array(uint32_t size, double value) : size_(size)
	{
		data = new double[size];
		for (uint32_t i = 0; i < size; ++i)
			data[i] = value;
	}

	// copy constructor
	array::array(const array& other) : size_(other.size_)
	{
		data = new double[size_];
		for (uint32_t i = 0; i < size_; ++i)
			data[i] = other.data[i];
	}
	// move constructor
	array::array(array&& other) noexcept : size_(other.size_), data(other.data) {
		other.size_ = 0;
		other.data = nullptr;
	}
	// destructor
	array::~array() {
		delete[] data;
	}

	// member functions:
	// size 
	uint32_t array::size() const  {
		return size_;
	}
	// at with bounds checking 
	double array::at(int32_t index) const {
		if (index < 0 || index >= size_)
			return 0.;
		return data[index];
	}
	// push_back - to add element at the end
	void array::push_back(double value) {
		double* new_data = new double[size_ + 1];
		for (uint32_t i = 0; i < size_; ++i)
			new_data[i] = data[i];
		new_data[size_] = value;
		delete[] data;
		data = new_data;
		++size_;
	}
}