#include "Output.h"
#include "Sorting.h"
#include <fstream>
using namespace std;

void PrintByTeachers(vector<FRecord>& list, string path) {
	SortByTeachers(list);
	ofstream file(path);
	file << "Преподаватель,Предмет,Группа,ФИО Студента,баллы\n";
	for (int i = 0; i < list.size(); i++) {
		file << list[i].teacher << "," << list[i].subject << "," << list[i].group << "," << list[i].student;
		if (list[i].points == -1) file << ",зачет\n";
		else file << "," << list[i].points << '\n';
	}
	file.close();
}

void PrintByGroups(vector<FRecord>& list, string path) {
	SortByGroups(list);
	ofstream file(path);
	file << "Преподаватель,Предмет,Группа,ФИО Студента,баллы\n";
	for (int i = 0; i < list.size(); i++) {
		file << list[i].teacher << "," << list[i].subject << "," << list[i].group << "," << list[i].student;
		if (list[i].points == -1) file << ",зачет\n";
		else file << "," << list[i].points << '\n';
	}
	file.close();
}