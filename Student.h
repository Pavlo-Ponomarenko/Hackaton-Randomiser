#pragma once
#include <string>
#include <vector>

class Student
{
	std::string name;
	std::string group;
	int index;
public:
	Student();
	Student(std::string name, std::string group, int index);
	std::string GetName();
	std::string GetGroup();
	int GetIndex();
};

std::vector<Student> ParseStudents(std::string path);