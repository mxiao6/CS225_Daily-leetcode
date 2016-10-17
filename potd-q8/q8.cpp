#include <iostream>
using namespace std;

int main() {
    char* x = new char[5];
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        x[i] = char('a' + i);
        sum += int(x[i]);
    }
    char** y = &x;
    
    cout << "The value of y is " << y << "." << endl;
    cout << "The sum of the characters is " << sum << "." << endl;
    
    delete[] x;
}