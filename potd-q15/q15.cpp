#include <iostream>
#include <string>
using namespace std;

class Square{
    private:
        string name;
        double * lengthptr;
    public:
        Square();
        Square(const Square & old);
        ~Square();
        void setName(string newName);
        void setLength(double newVal);
        string getName() const;
        double getLength() const;
        Square& operator=(Square const & other);
        Square operator+(Square const & other) const;
};

Square::Square(){
    name = "mysquare";
    lengthptr = new double;
    *lengthptr = 2.0;
}

Square::Square(const Square & other){
    cout << "I am copying!" << endl;
    name = other.getName();
    lengthptr = new double;
    *lengthptr = other.getLength();
}

Square::~Square(){
    delete lengthptr;
}

//Big three. We must implement them all.
Square& Square::operator=(Square const & other) {
    if (this != &other) {
        delete lengthptr;
        name = other.getName();
        lengthptr = new double;
        *lengthptr = other.getLength();
    }

    return *this;
}

//Both the current object and the parameter should not change
Square Square::operator+(Square const & other) const{
    Square copy;
    copy.setName(name + other.getName());
    copy.setLength(*lengthptr + other.getLength());

    return copy;
}

void Square::setName(string newName){name = newName;}
void Square::setLength(double newVal){*lengthptr = newVal;}
string Square::getName() const {return name;}
double Square::getLength() const {return *lengthptr;}


int main(){
    Square s1;
    cout << s1.getName() << "\t" << s1.getLength() << endl;

    Square s2 = s1;
    cout << s2.getName() << "\t" << s2.getLength() << endl;

    s2.setName("yourSquare");
    s2.setLength(4.0);

    cout << s2.getName() << "\t" << s2.getLength() << endl;

    Square s4 = s1 + s2;
    cout << s4.getName() << "\t" << s4.getLength() << endl;

    return 0;
}
