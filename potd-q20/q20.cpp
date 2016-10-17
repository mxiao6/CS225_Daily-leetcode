/* Author: Mingze Xiao
 * Data: 28 Sep 2016
 */

#include <iostream>
#include <string>
using namespace std;

//helper function to determain whether the first is vowel
bool isVowel(const string p_word) {
	char front = p_word.front();
	if (front == 'a' || front == 'e' || front == 'i' || 
		front == 'o' || front == 'u' || front == 'y') 
		return true;
	return false;
}

//helper function to determain whether voewl exists
bool noVowel(const string p_word) {
	if (p_word.find('a') == -1 && p_word.find('e') == -1 && p_word.find('i') == -1 && 
		p_word.find('o') == -1 && p_word.find('u') == -1 && p_word.find('y') == -1)
		return true;
	return false;
}

int main() {
	while (true) {
		cout << "Please enter a lower case English word. (Enter q to quit)" << endl;

		string word;

		cin >> word;

		// if q, quit
		if (word == "q") 
			return 0;

		// first case is vowel or no vewel, directly append and continue
		if (isVowel(word) || noVowel(word)) {
			word += "ay";
			cout << word << endl;
			continue;
		}

		// if first case is not vowel, replace the first to the end 
		// untill the first is vowel
		while (!isVowel(word)) {
			char temp = word.front();
			word.erase(0, 1);
			word += temp;
		}
		word += "ay";
		cout << word << endl;
	}
}
