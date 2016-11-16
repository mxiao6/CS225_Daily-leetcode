#include <iostream>
using namespace std;

#define COLOR "Blue"
#define IAMDEFINED

int main() {
#ifdef IAMDEFINED	//or #if defined IAMDEFINED
	cout << COLOR << " is a great color" << endl;
#endif
	return 0;
}