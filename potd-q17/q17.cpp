#include "q16.cpp"

class Pet : public Animal {
private:
	string owner_name;
public:
	Pet() : Animal() {
		owner_name = "Cinda";
	}

	Pet(string type, string food, string name) : Animal(type, food) {
		owner_name = name;
	}

	string getOwner() {
		return owner_name;
	}

	void setOwner(string newOwner) {
		owner_name = newOwner;
	}

	void print() {
		cout << "My name is " << owner_name << "." << endl;
	}
};

int main() {
	Pet cat;
	cat.print();

	Pet dog("dog", "mud", "mingze");
	dog.print();
}