#include <iostream>
using namespace std;

class Animal {
private:
	string animal_type;
protected:
	string food_type;
public:
	Animal() {
		animal_type = "cat";
		food_type = "fish";
	}

	Animal(string p_animal_type, string p_food_type) {
		animal_type = p_animal_type;
		food_type = p_food_type;
	}

	string getType() {
		return animal_type;
	}

	void setType(string newanimal_type) {
		animal_type = newanimal_type;
	}

	string getFood() {
		return food_type;
	}

	void setFood(string newfood_type) {
		food_type = newfood_type;
	}

	virtual void print() {
		cout << "I am a " << animal_type << "." << endl;
	}
};

// int main() {
// 	Animal cat;
// 	cat.print();

// 	Animal dog("dog", "meat");
// 	dog.print();
// }