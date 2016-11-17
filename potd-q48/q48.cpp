#include <iostream>
using namespace std;

class Circle {
  private:
  	double radius;

  public:
  	double getRadius() const ;
  	void setRadius(double newR);
  	Circle();
  	Circle(double newR);
};

Circle::Circle() {
	radius = 0;
}

Circle::Circle(double newR) {
	radius = newR;
}

double Circle::getRadius() const {
	return radius;
}

void Circle::setRadius(double newR) {
	radius = newR;
}

void print(Circle const & c) {
	cout << "I am a circle. My radius is " << c.getRadius() << endl;

	// c.setRadius(3);
}

int main() {
	Circle c(2);

	// cannot change the Circle object the pointer points to
	const Circle * p1 = &c; 
	print(*p1);

	/* 
	  cannot change what the pointer points to
	  (i.e., you cannot do the following: 
	  int * x = p; x = q; where p and q are integers)
	*/
	Circle * const p2 = &c; 
	p2 -> setRadius(3);
	print(*p2);
}