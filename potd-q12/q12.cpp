#include <iostream>
#include <math.h>
using namespace std;

int main() {
	string choise;
	do {
		cout << "Enter \"s\" to calculate sin, \"c\" to calculate cos, and \"q\" to quit:" << endl;
		cin >> choise;
	} while (!(choise == "s" || choise == "c" || choise == "q"));

	if (choise == "q") {
		return 0;
	}

	cout << "Enter the number:" << endl;
	int number;
	cin >> number;

	if (choise == "s") {
		cout << sin(number) << endl;
		return 0;
	} else if (choise == "c") {
		cout << cos(number) << endl;
		return 0;
	}
}