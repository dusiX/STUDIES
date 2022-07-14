#include <iostream>

using namespace std;

struct Point {

	double x, y;

	Point(double X, double Y) {
		x = X;
		y = Y;
	}

	Point() {
		x = 0;
		y = 0;
	}

	void show() {
		cout << "[" << x << ", " << y << "]" << endl;
	}

};

int main() {
	Point p(4.8, 1.1);
	//p.x = 1.9;
	//p.y = 3.5;
	p.show();

	Point* p1 = new Point(4.2, 8.1);
	p1->show();

	show(p);

	return 0;
}