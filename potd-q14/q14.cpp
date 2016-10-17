#include <iostream>
using namespace std;

class Square {
private:
	double * length;
	string name;
	void copy(const Square &source) {
		length = new double();
		*length = *(source.length);
		name = source.name;
	}

	void clear() {
		delete length;
	}

public:
	Square() {
		name = "mysquare";
		length = new double(2.0);
	}

	Square(const Square &source) {
		copy(source);
		cout << "I am copying!" << endl;
	}

	~Square() {
		clear();
	}

	const Square & operator=(const Square &source) {
		if (this != &source) {
			clear();
			copy(source);
		}
		cout << "=========" << endl;
		return *this;
	}

	double getLength() {
		return *length;
	}

	string getName() {
		return name;
	}

	void setLength(double newLength) {
		*length = newLength;
	}

	void setName(string newName) {
		name = newName;
	}

	Square bounce(Square & s);

	Square generate();
};

Square Square::bounce(Square & s) {
	Square t(s);

	return s;
}

Square generate() {
	Square a;
	a.setName("a");
	a.setLength(6.0);
	return a;
}

int main() {
	Square s1;
	// cout << s1.getName() << "\t" << s1.getLength() << endl;

	// s1.setName("s1");
	// s1.setLength(1.0);

	// cout << s1.getName() << "\t" << s1.getLength() << endl;

	// Square s2(s1);
	// cout << s2.getName() << "\t" << s2.getLength() << endl;

	// Square s3 = s1;
	// s3 = s1;
	// cout << s3.getName() << "\t" << s3.getLength() << endl;

	// Square s4;

	// s4.setName("s4");
	// s4.setLength(4.0);

	// cout << s4.getName() << "\t" << s4.getLength() << endl;

	// s1.bounce(s4);

	// cout << s5.getName() << "\t" << s5.getLength() << endl;

	Square s6 = generate();
	cout << s6.getName() << "\t" << s6.getLength() << endl;

}