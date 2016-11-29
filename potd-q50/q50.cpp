#include <iostream>
#include <string>
#include <sstream>
#include <utility>
#include <map>
#include <vector>
using namespace std;

map<int, vector<pair<int, string> > > records;

class printTime {
public:
    /*
        123456789
        1- 60 minutes: office hours
        2- 30 minutes: graded exam 1
    */
    void operator() (int uin) {
        auto current = records[uin];
        auto it = current.begin();
        // for (auto it = current.begin(); it != current.end(); it++) {
        for (size_t i = 1; i <= current.size(); i++) {
            cout << i << "- " << it -> first << " minutes: " << it -> second << endl;
            it++;
        }
    }
};

void addTime(int uin, int time, string task){
    map<int, vector<pair<int, string> > >::iterator it;
    it = records.find(uin);
    if(it == records.end()){            // see if uin is in map already
        vector<pair<int, string> > vec;
        pair<int, string> entry (time, task);
        vec.push_back(entry);
        records.insert(pair<int, vector<pair<int, string> > > (uin, vec));
    } else {
        pair<int, string> entry (time, task);
        records[uin].push_back(entry);
    }
}

void printRecord(int uin) {
    cout << uin << endl;
    printTime p;
    p(uin);
}

void printAll() {
    int uin = -1;
    printTime p;
    for (auto it = records.begin(); it != records.end(); it++) {
        uin = it -> first;
        cout << uin << endl;
        p(uin);
    }
}

int main(){
    char input;
    do{
        char choise;
        cout << "Add time (a) or lookup entry (l): ";
        cin >> choise;
        if (choise == 'a') {
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
        } else if (choise == 'l') {
            int uin;
            cout << "Enter a UIN or enter 0 to print all of the time records: ";
            cin >> uin;
            cin.ignore();
            uin != 0 ? printRecord(uin) : printAll();
        }
        cout << "Would you like to perform another operation (y/n): ";
        cin >> input;
    } while(input == 'y');
    return 0;
}
