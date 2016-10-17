#include <iostream>
using namespace std;

int main() {
	cout << "Please enter a non-negative integer: " << endl;

	int div;
	cin >> div;

	int** nxn = new int*[div];
	for (int i = 0; i < div; i++) {
		nxn[i] = new int[div];
		for (int j = 0; j < div; j++) {
			nxn[i][j] = i + j;
			if (j == div-1)
				cout << nxn[i][j] << endl;
			else
				cout << nxn[i][j] << " ";
		}
	}

	for (int i = 0; i < div; i++) {
		delete[] nxn[i];
	}
	delete[] nxn;
}