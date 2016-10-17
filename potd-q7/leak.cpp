#include <iostream>
using namespace std;

int main() {
    int* p = new int();
    *p = 10;
    int x = *p;
    cout << x << endl;
    p = NULL;
    //memory leak because we did not delete p
}