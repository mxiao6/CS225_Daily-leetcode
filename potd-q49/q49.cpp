/*
The Problem

The student employment office has asked you to write a bit of code to help them keep track of student time cards. You can (and should) utilize STL data structures in this problem.

TODO:
* Declare the data structure that will be used to hold the time card information as a global variable (in practice you would not store all of your data in a global variable, but for our purposes it makes life easier)
* The following is the required information and functionality of time cards:
    * The records should be able to be looked up by student UIN
    * For each student UIN there needs to be a list of time enteries that consist of the amount of time spent working in minutes and a description of what they did
* Your main method should continue to do the following until "n" is entered:
    * Prompt the user to enter a UIN
    * Prompt the user to enter an amount of time in minutes (assume the user rounds to the nearest minute)
    * Prompt the user to enter a description of the task they performed
    * Ask the user if they would like to enter another time entry (y/n)
    * You can assume the user will enter valid input
* Write a helper method called addTime(int uin, int time, string task) that adds this information to the data structure. 

Sample input:
123456789
60
Proctored exam 1
*/

#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <map>
#include <vector>
using namespace std;

map<int, vector<pair<int, string> > > records;

void addTime(int uin, int time, string task){
    auto it = records.find(uin);
    if(it == records.end()){            // see if uin is in map already
        vector<pair<int, string> > vec;
        pair<int, string> entry (time, task);
        vec.push_back(entry);
        records[uin] = vec;
    } else{
        pair<int, string> entry (time, task);
        records[uin].push_back(entry);
    }
}

int main(){
    char input;
    do{
        int uin, time;
        string task;
        cout << "Enter a UIN: ";
        cin >> uin;
        cin.ignore();       // cin leaves the /n character, remove it from the buffer
        cout << "Enter the amount of time worked (rounded to the nearest minute): ";
        cin >> time;
        cin.ignore();       // remove newline from buffer
        cout << "Enter a description of the task(s) performed: ";
        getline(cin, task);
        addTime(uin, time, task);
        cout << "Would you like to create another time entry (y/n): ";
        cin >> input;
    } while(input == 'y');
    return 0;
}
