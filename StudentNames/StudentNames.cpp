#include <algorithm> // std::sort
#include <cstddef> // std::size_t
#include <iostream>
#include <string>
#include <vector>

struct Student
{
	std::string Name;
	int Grade;
};

int GetNumber() // get number of students
{
	int NumStudents;
	do
	{
		std::cout << "How many students do you wish to enter? ";
		std::cin >> NumStudents;
	} while (NumStudents <= 0);
	return NumStudents;
}


std::vector<Student> GetList() // use number of students to make a vector and initialize each student using a for-each loop
{
	using Student_Vector = std::vector<Student>;
	int TotalStudents(GetNumber());

	Student_Vector StudentList(static_cast<Student_Vector::size_type>(TotalStudents)); // must static cast the int to a size_type the vector can recognize
	int StudentNumber{ 1 }; // to keep track of students number
	for (auto& Student : StudentList) /// auto& student acts as a reference of the current vector studentlist element
	{
		std::cout << "Enter student #" << StudentNumber << "'s name: ";
		std::cin >> Student.Name;
		std::cout << "Enter student #" << StudentNumber << "'s Grade: ";
		std::cin >> Student.Grade;
		++StudentNumber;
	}
	return StudentList;
}

bool SortStudents(const Student& a, const Student& b)
{
	return (a.Grade > b.Grade);
}

int main()
{
	auto StudentList{GetList()};
	std::sort(StudentList.begin(), StudentList.end(), SortStudents);

	for (auto& Student : StudentList)
	{
		std::cout << Student.Name << " got a grade of " << Student.Grade << '\n';
	}
	return 0;
}
