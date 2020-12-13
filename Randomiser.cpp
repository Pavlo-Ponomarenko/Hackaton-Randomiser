#include <iostream>
#include <map>
#include <vector>
#include "Student.h"
#include "Output.h"
#include "Teacher.h"
#include "Random.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "");
	int num;
	cout << "Количество исходников - ";
	cin >> num;
	vector<Student> st = ParseStudents("Students.csv");
	vector<Teacher> tch = ParseTeachers("Teachers.csv");
	map<string, vector<Student>> m;
	m[st[0].GetGroup()] = st;
	vector<FRecord> list = GenerateList(tch, m);
	PrintByTeachers(list, "Result1.csv");
	PrintByGroups(list, "Result1.csv");
}