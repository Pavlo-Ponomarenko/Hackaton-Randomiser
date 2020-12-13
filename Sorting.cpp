#include "Sorting.h"
using namespace std;

void SortByTeachers(vector<FRecord>& vect) {
	string teacher;
	for (int i = 0; i < vect.size(); i++) {
		teacher = vect[i].teacher;
		int border = i;
		for (int m = i; m < vect.size(); m++) {
			if (vect[m].teacher != teacher) break;
			else border++;
		}
		i = border - 1;
		for (int k = i + 1; k < vect.size(); k++) {
			if (vect[k].teacher == teacher) {
				FRecord rec = vect[border];
				vect[border] = vect[i];
				vect[k] = rec;
				border++;
			}
		}
		i = border - 1;
	}
}

void SortByGroups(vector<FRecord>& vect) {
	string group;
	for (int i = 0; i < vect.size(); i++) {
		group = vect[i].group;
		int border = i;
		for (int m = i; m < vect.size(); m++) {
			if (vect[m].group != group) break;
			else border++;
		}
		i = border - 1;
		for (int k = i + 1; k < vect.size(); k++) {
			if (vect[k].group == group) {
				FRecord rec = vect[border];
				vect[border] = vect[i];
				vect[k] = rec;
				border++;
			}
		}
		i = border - 1;
	}
}