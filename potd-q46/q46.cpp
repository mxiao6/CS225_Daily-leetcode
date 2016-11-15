#include <iostream>
#include <string>
using namespace std;

class Food{
    protected:
        string name;
    public:
        Food(){name = "Food";}
        void virtual printColor(){cout << "Foods come in a variety of colors." << endl;}
};

class Fruit : public Food{
    public:
        Fruit(){name = "Fruit";}
        void virtual printColor(){cout << "Fruits come in a variety of colors." << endl;}
};

class SpecificFruit : public Fruit{
    private:
        string color;
    public:
        SpecificFruit(string newName, string newColor){
            name = newName;
            color = newColor;
        }
        void printColor(){cout << "A " << name << " is " << color << "." << endl;}
};

void printColors(Food * arr[], int size){
    for(int i = 0; i < size; i++){
        arr[i]->printColor();
    }
}

int main() {
	Food* p[4];
	//Fruits come in a variety of colors.
	p[0] = new Food();

	//Foods come in a variety of colors.
	p[1] = new Fruit();

	//A banana is yellow.
	p[2] = new SpecificFruit("banana", "yellow");

	//A strawberry is red.
	p[3] = new SpecificFruit("strawberry", "red");

	printColors(p, 4);

}
