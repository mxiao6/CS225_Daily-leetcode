#include <iostream>
using namespace std;

int main(){
    int x;
    cout << "Enter a positive integer: " << endl;
    cin >> x;

    while (x < 2) {
    	cout << "Please enter a number bigger or equal to 2." << endl;
    	cin >> x;
    }

    bool isPrime = true;
    
    // the factors must be equal to or smaller than half of the original number
    for (int i = 2; i <= x/2; i++) { 
    	if (x % i == 0) {
    		if (isPrime) {
    			isPrime = false;
    			cout << "1 " << i << " "; // we have to print 1 first
    			continue;
    		}
    		cout << i << " ";
    	}
    }

    if (isPrime) {
    	cout << x << " is prime" << endl;
    } else {
    	cout << "divide 6" << endl;
    }

    return 0;
}
