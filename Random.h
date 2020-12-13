#pragma once
#include "Teacher.h"
#include "Student.h"

struct FRecord {
	std::string teacher;
	std::string subject;
	std::string group;
	std::string student;
	int points;
};

std::vector<FRecord> GenerateList(std::vector<Teacher> teachers, std::map<std::string, std::vector<Student>> students);