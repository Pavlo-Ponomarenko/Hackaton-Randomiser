#include "Random.h"
#include <random>
#include <iostream>
using namespace std;

bool Contains(vector<int> vect, int num) {
	for (int i = 0; i < vect.size(); i++) {
		if (num == vect[i]) return true;
	}
	return false;
}

void Randomize(vector<FRecord>& result, string teacher, vector<Student>& st_vect, Record record) {
	vector<int> list;
	std::random_device rd; // obtain a random number from hardware
	std::mt19937 gen(rd()); // seed the generator
	std::uniform_int_distribution<> distr(0, st_vect.size() - 1); // define the range
	for (int i = 0; i < record.sets; i++) {
		int index = -1;
		while (true) {
			index = distr(gen);
			if (!Contains(list, index)) {
				list.push_back(index);
				break;
			}
		}
		result.push_back({ teacher, record.subject, st_vect[index].GetGroup(), st_vect[index].GetName(), record.points });
	}
	result.shrink_to_fit();
}

vector<FRecord> GenerateList(vector<Teacher> teachers, map<string, vector<Student>> students) {
	vector<FRecord> result;
	for (int i = 0; i < teachers.size(); i++) {
		map<string, Record>::iterator iter = teachers[i].GetIter();
		Record record;
		while (iter != teachers[i].GetEnd()) {
			string group = (*iter).first;
			record = (*iter).second;
			vector<Student> st_vect = students[group];
			if (st_vect.size()) {
				Randomize(result, teachers[i].GetName(), st_vect, record);
			}
			iter++;
		}
	}
	return result;
}