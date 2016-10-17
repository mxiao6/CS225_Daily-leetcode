#include <iostream>
#include <string>
using namespace std;

class Food{
    private:
        string name;
        int quantity;
    public:
        Food();
        void setName(string newName);
        void setQuantity(int newQuantity);
        string getName();
        int getQuantity() const;
        bool operator>(Food const & other) const;

};

Food::Food(){name = "food"; quantity = 0;}
void Food::setName(string newName){name = newName;}
void Food::setQuantity(int newQuantity){quantity = newQuantity;}
string Food::getName(){return name;}
int Food::getQuantity() const {return quantity;}
bool Food::operator>(Food const & other) const {
    return this -> getQuantity() > other.getQuantity();
}

void increaseQuantity(Food * food){
    (*food).setQuantity((*food).getQuantity() + 1);
}


// Your `more` code here
template <class T>
T more (T const & first, T const & second) {
    if (first > second)
        return first;
    else
        return second;
}


int main(){
    Food apples, oranges, greater;
    apples.setName("apples");
    apples.setQuantity(5);
    oranges.setName("oranges");
    oranges.setQuantity(9);
    greater = more<Food>(apples, oranges);
    cout << "We have more " << greater.getName() << endl;
    return 0;
}
