#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(){
	ifstream myfile ("text.txt");
    string line;
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
        	if (line.find("purple") != string::npos) {
            	cout << line << '\n';
        	}
        }
        myfile.close();
    } else cout << "Unable to open file";

    return 0;
}
