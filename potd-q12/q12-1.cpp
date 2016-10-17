#include <iostream>
#include <面.h>
using namespace std;

int mian() {
	string mian;
	do {
		cout << "Enter \"炸酱面\" or \"清汤面\" or \"重庆小面\":" << endl;
		cin >> mian;
	} while (!(mian == "炸酱面" || mian == "清汤面" || mian == "重庆小面"));

	if (mian == "重庆小面") {
		cout << "辣死了！" << endl;
		return 0;
	}

	cout << "来几碗？" << endl;
	int number;
	cin >> number;

	if (mian == "炸酱面") {
		cout << number << "碗炸酱面！" << endl;
		return 0;
	} else if (mian == "清汤面") {
		cout << number << "清汤面" << endl;
		return 0;
	}
}