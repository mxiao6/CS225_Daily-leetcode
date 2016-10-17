#include <math.h>
//pow (base, power)
#include <iostream>
using namespace std;

int* raise (int ori[], int power) {
	int number = 0;
	for (int i = 0; ; i++) {
		number++;
		if (ori[i] < 0)
			break;
	}
	//cout << number << endl;
	int* result = new int[number];
	for (int i = 0; i < number - 1; i++) {
		result[i] = pow(ori[i], power);
		cout << result[i] << endl;
	}

	return &result[0];
}

int main() {
	int input[] = {2, 4, -1};

	int* address = raise(input, 2);
	cout << address << endl;
	cout << address[0] << endl;
	cout << address[1] << endl;
}
