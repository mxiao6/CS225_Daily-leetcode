#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int myhash(string str){     // many different hash fucntions acceptable, this is just an example
    int sum = 0;
    int length = str.length();

    for (int i = 0; i < length; i++) {
        sum += str[i] * length;
    }

    return sum % 5;
}

int main(){
    cout << "State your question: ";
    string in;
    getline(cin, in);
    // put error checking code here...
    int length = in.length();

    if (in[length-1] != '?') {
        cout << "The string does not end in a \'?\'" << endl;
        return 1;
    }

    if (length > 100 || length <= 1) {
        cout << "The string should be be less than or equal to 100 characters but greater than 1." << endl;
        return 1;
    }

    int val = myhash(in);

    cout << in << " hashed to value " << val << endl;
    if(val == 0)
        cout << "The outlook is bleak." << endl;
    else if(val == 1)
        cout << "The answer is most likely yes." << endl;
    else if(val == 2)
        cout << "Is today Tuesday? If yes, then yes! Otherwise, probably not." << endl;
    else if(val == 3)
        cout << "Most definitely!" << endl;
    else
        cout << "The future in unclear at the moment. Try again later." << endl;
    return 0;
}
