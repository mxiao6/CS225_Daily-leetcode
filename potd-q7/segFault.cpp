#include <iostream>
using namespace std;

int main() {
    int* p;
    cout << *p <<endl;
    //dereferencing uninitialized pointer causes segFault
}