#include "Teacher.h"
#include <fstream>
#include <iostream>
using namespace std;

Teacher::Teacher() {
	name = "None";
}

Teacher::Teacher(string name) {
	this->name = name;
}

const string& Teacher::GetName() {
	return name;
}

Record* Teacher::operator[](string group) {
	map<string, Record>::iterator iter = data.find(group);
	if (iter == data.end()) return NULL;
	return &iter->second;
}

void Teacher::AddRecord(string group, Record rec) {
	data[group] = rec;
}

map<string, Record>::iterator Teacher::GetIter() {
	return data.begin();
}

map<string, Record>::iterator Teacher::GetEnd() {
	return data.end();
}

Record GetRecord(char* text, char* subject) {
	char* list[5];
	int index = 0;
	char* token = strtok(text, " ");
	list[index] = token;
	index++;
	while (true) {
		token = strtok(NULL, " ");
		if (token == NULL) break;
		list[index] = token;
		index++;
	}
	if (!strcmp(list[1], "зачет")) return { atoi(list[0]), -1, subject };
	else return { atoi(list[0]), atoi(list[3]) };
}

vector<Teacher> ParseTeachers(string path) {
	ifstream file(path);
	vector<Teacher> t_vect;
	char line[140];
	char* list[4];
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
		string name = list[0];
		bool exists = false;
		for (int i = 0; i < t_vect.size(); i++) {
			if (t_vect[i].GetName() == name) {
				exists = true;
				t_vect[i].AddRecord(list[2], GetRecord(list[3], list[2]));
			}
		}
		if (!exists) {
			Teacher teacher(list[0]);
			teacher.AddRecord(list[2], GetRecord(list[3], list[2]));
			t_vect.push_back(teacher);
		}
	}
	t_vect.shrink_to_fit();
	return t_vect;
}