#include <iostream>
using namespace std;

//write a class food that has two private member variables: name and quantity
//write the functions to access those private member variables
//write the default constructor
//write the function "increaseQuantity" that is not part of the class which increases the quantity of a food by one
//
//this function should be called by passing a food object BY POINTER
//write a main method that
//
//creates an instance of the food class
//prints out its quantity
//calls increaseQuantity on it
//prints out the new quantity

//You have 5 apples.
//You have 6 apples.

class Food {
private:
    string name;
    int quantity;
    
public:
    Food() {
        name = "";
        quantity = 0;
    };
    
    string getName() {
        return name;
    }
    
    void setName(string newName) {
        name = newName;
    }
    
    int getQuantity() {
        return quantity;
    }
    
    void setQuantity(int newQuantity) {
        quantity = newQuantity;
    }
};

void increaseQuantity(Food * someFood) {
    someFood -> setQuantity(someFood -> getQuantity() + 1);
}

int main() {
    Food food;
    
    food.setQuantity(5);
    food.setName("apple");
    
    cout << "You have " << food.getQuantity() << " " << food.getName() << (food.getQuantity() > 1 ? "s." : ".") << endl;
    
    increaseQuantity(&food);
    
    cout << "You have " << food.getQuantity() << " " << food.getName() << (food.getQuantity() > 1 ? "s." : ".") << endl;
}