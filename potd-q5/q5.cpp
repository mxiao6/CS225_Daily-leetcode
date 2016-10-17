#include <string>
#include <iostream>

using namespace std;

int main() {
    int x = 2016;
    cout << "x is stored at address " << &x << " and has value " << x << endl;
    
    int* p = &x;
    *p = 2017;
    cout << "x is stored at address " << p << " and has value " << *p << endl;
}
