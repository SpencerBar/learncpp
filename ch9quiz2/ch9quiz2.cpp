#include <algorithm> // std::sort
#include <cstddef> // std::size_t
#include <iostream>
#include <string>
#include <vector>


struct Students
{
	std::string Name{};
	int Grade{};
};

int getNumStudents()
{
	int tempnum{};
	do {
		std::cout << "How many names would you like to enter? ";
		std::cin >> tempnum;
	} while (tempnum <= 0);
	return tempnum;
}

std::vector<Students> getStudents()
{
	using student_Vector = std::vector<Students>;
	int numStudents{ getNumStudents() };

	student_Vector student_List(static_cast<student_Vector::size_type>(numStudents));

	int studentNumber{ 1 };
	for (auto& Student : student_List)
	{
		std::cout << "Enter student #" << studentNumber << "'s name: ";
		std::cin >> Student.Name;
		std::cout << "Enter student #" << studentNumber << "'s grade: ";
		std::cin >> Student.Grade;

		++studentNumber;
	}
	return student_List;
}

bool compareStudents(const Students& a, const Students& b)
{
	return (a.Grade > b.Grade);
}

int main()
{
	auto student_list{ getStudents() };
	std::sort( student_list.begin(), student_list.end(), compareStudents );

	for (const auto& student: student_list)
	{
		std::cout << student.Name << " got a score of " << student.Grade << '\n';
	}

	return 0;
}