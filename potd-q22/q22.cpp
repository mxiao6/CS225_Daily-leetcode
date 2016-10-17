#include <iostream>
#include <map>
#include <string> // std::string
#include <locale> // std::locale, std::tolower

using namespace std;

int main() {
	cout << "Please enter a string only containing upper and lowercase letters and spaces:" << endl;

	string str = "";
	getline(cin, str);

	locale loc;

	map<char, int> characters;

	for (string::size_type i=0; i<str.length(); i++) {
    	characters[tolower(str[i],loc)] += 1;
	}

	int tempNumber = 0;
	char tempChar;

	for (map<char,int>::iterator it=characters.begin(); it!=characters.end(); it++) {
		if (it->second > tempNumber) {
			tempChar = it->first;
			tempNumber = it->second;
		}
	}

	cout << "The most frequent character is " << tempChar << endl;
}