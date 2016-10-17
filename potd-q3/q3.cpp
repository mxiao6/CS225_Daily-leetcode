#include <string>
#include <iostream>
using namespace std;

class Pet{
public:
    Pet();
    Pet(string n, string b, string t, string o) {
        name = n;
        birth_year = b;
        type = t;
        owner_name = o;
    }
    
    //clients can modify or access information using setter or getter
    void set_name(string n) { name = n;}
    void set_birth_year(string b) { birth_year = b;}
    void set_type(string t) { type = t;}
    void set_owner_name(string o) {owner_name = o;}
    
    string get_name() { return name;}
    string get_birth_year() {return birth_year;}
    string get_type() { return type;}
    string get_owner_name() { return owner_name;}
    
private:
    //clients cannot modify the information directly
    string name;
    string birth_year;
    string type;
    string owner_name;
};

int main() {
    //Test
    Pet p = Pet("Parrot", "2006", "dog", "Mingze");
    p.set_name("Ocean");
    cout << p.get_name() <<endl;
}