#pragma once
#include <string>

namespace vsite::oop::v3 
{
	struct student
	{
		std::string name;
		int grade;
	};

	class results
	{
		student* students;
		unsigned capacity;
		unsigned count;

	public:
		results(unsigned capacity);
		~results();

		void add(const student& s);

		unsigned has_grade(int grade) const;

		unsigned starts_with_letter(char letter) const;
	};

	// class array
	class array {

		uint32_t size_;
		double* data;

	public:
		array();
		array(uint32_t size, double value);
		array(const array& other);
		array(array&& other) noexcept;
		~array();

		uint32_t size() const;
		double at(int32_t index) const;
		void push_back(double value);
	};
}