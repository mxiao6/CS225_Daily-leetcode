#include <ctime>
#include <iostream>
using namespace std;

int main() {
    time_t seconds = std::time(nullptr);
    cout << "Seconds: " << seconds << endl;
    cout << "Hours: " << seconds / 3600 << endl;
    cout << "Years: " << seconds / 3600 / 24 / 365 << endl;
}