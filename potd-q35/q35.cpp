#include <iostream>
#include <fstream>
using namespace std;

int main () {
	ofstream myfile ("test.txt");
    if (myfile.is_open()) {
  	    myfile << "This is a line.\n";
        myfile << "This is another line.\n";
        myfile.close();
    }
    else cout << "Unable to open file";

    ifstream myfileR ("test.txt");
    string line;
    if (myfileR.is_open()) {
        while (getline(myfileR, line)) {
            cout << line << '\n';
        }
        myfileR.close();
    } else cout << "Unable to open file";

    return 0;
}