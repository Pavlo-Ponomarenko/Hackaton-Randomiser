#include "Student.h"
#include <fstream>
#include <iostream>
using namespace std;

Student::Student() {
	name = "None";
}

Student::Student(string name, string group, int index) {
	this->name = name;
	this->index = index;
	this->group = group;
}

string Student::GetName() {
	return name;
}

string Student::GetGroup() {
	return group;
}

int Student::GetIndex() {
	return index;
}

std::vector<Student> ParseStudents(std::string path) {
	ifstream file(path);
	vector<Student> t_vect;
	char line[140];
	char* list[3];
	if (!file.eof()) file.getline(line, 140);
	while (!file.eof()) {
		file.getline(line, 140);
		if (line[0] == '\0') break;
		char identity = line[0];
		char* token = strtok(line, ",");
		int index = 0;
		list[index] = token;
		index++;
		while (true) {
			token = strtok(NULL, ",");
			if (token == NULL) break;
			list[index] = token;
			index++;
		}
		Student student(list[1], list[0], atoi(list[2]));
		t_vect.push_back(student);
	}
	t_vect.shrink_to_fit();
	return t_vect;
}