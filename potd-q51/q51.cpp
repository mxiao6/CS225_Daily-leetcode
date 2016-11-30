#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <vector>

using namespace std;

class Patient
{
public:
	Patient();
	Patient(int r, int t);
	Patient(int r);

	int getId();
	int getRank();
	void setRank(int r);
	int getTime();
	void setTime(int t);
	
private:
	int id;
	int rank;
	int timeIn;
	int uniqueGenerator(int a, int b);
};


Patient::Patient() {
	id = uniqueGenerator(1, 1);
}

Patient::Patient(int r, int t) {
	id = uniqueGenerator(r, t);
	rank = r;
	timeIn = t;
}

Patient::Patient(int r) {
	id = uniqueGenerator(r, 1);
	rank = r;
}

int Patient::getId() {
	return id;
}

int Patient::getRank() {
	return rank;
}

void Patient::setRank(int r) {
	rank = r;
}

int Patient::getTime() {
	return timeIn;
}

void Patient::setTime(int t) {
	timeIn = t;
}

int Patient::uniqueGenerator(int a, int b) {
	/* initialize random seed: */
	// srand (time(NULL));

	/* generate unique id between 1 and 1000: */
	return abs((rand() * a * b)) % 1000 + 1;
}


class Hospital
{
public:
	Hospital();

	void add_patients(vector<Patient> new_patients);

	/*
		Rank 1: 123(9) 456(10) 789(11)
		Rank 2: No patients
		Rank 3: 234(8) 583(12) 222(13)
		Rank 4: 111(26)
	*/
	void print_patients();

private:
	int hour;
	vector<Patient> patients;
	void elapse_hour();

};

Hospital::Hospital() {
	hour = 7;
}

void Hospital::elapse_hour() {
	hour++;
	for (auto i = patients.begin(); i != patients.end(); i++) {
		int curRank = i -> getRank();

		if (--curRank == 0) {
			cout << "Patient " << i -> getId() << " was relesed" << endl;
			patients.erase(i); // i no longer exits
			i = patients.begin();
			// cout << "erase successfull" << endl;
			continue;
		}
		
		i -> setRank(curRank);
	}
}

void Hospital::add_patients(vector<Patient> new_patients) {	
	cout << endl;
	cout << "One hour later ... ... " << endl;
	cout << endl;

	elapse_hour();

	for (auto i = new_patients.begin(); i != new_patients.end(); i++) {
		i -> setTime(hour);
		patients.push_back(*i);
	}
}

/*
	Rank 1: 123(9) 456(10) 789(11)
	Rank 2: No patients
	Rank 3: 234(8) 583(12) 222(13)
	Rank 4: 111(26)
*/
void Hospital::print_patients() {
	for (int i = 1; i <= 4; i++) {
		cout << "Rank " << i << ": ";
		bool noPatients = true;
		for (auto j = patients.begin(); j != patients.end(); j++) {
			if (j -> getRank() == i) {
				cout << j -> getId() << "(" << j -> getTime() << ") ";
				noPatients = false;
			}
		}
		if (noPatients) cout << "No patients";
		cout << endl;
	}
}

int main() {
	Hospital h;

	Patient p1(4);
	Patient p2(1);

	Patient p3(3);
	Patient p4(4);

	vector<Patient> patients;
	vector<Patient> patients2;

	patients.push_back(p1);
	patients.push_back(p2);
	patients2.push_back(p3);
	patients2.push_back(p4);

	h.add_patients(patients);
	h.print_patients();

	h.add_patients(patients2);
	h.print_patients();

	return 0;
}