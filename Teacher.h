#pragma once
#include <string>
#include <map>
#include <vector>

struct Record {
	int sets;
	int points;
	std::string subject;
};

class Teacher
{
	std::string name;
	std::map<std::string, Record> data;
public:
	Teacher();
	Teacher(std::string name);
	const std::string& GetName();
	Record* operator[](std::string group);
	std::map<std::string, Record>::iterator GetIter();
	std::map<std::string, Record>::iterator GetEnd();
	void AddRecord(std::string group, Record rec);
};

std::vector<Teacher> ParseTeachers(std::string path);