// Programme including struct which checks if triangle is equilateral, isosceles or rectangular, prints coordinates of the points of the triangle,
// returns area and perimeter of a triangle

#include <iostream>
#include <cmath>

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

struct Triangle {

	Point a, b, c;
	double ab, ac, bc, obw, pol;

	void setSides() {
		ab = sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
		ac = sqrt((c.x - a.x) * (c.x - a.x) + (c.y - a.y) * (c.y - a.y));
		bc = sqrt((c.x - b.x) * (c.x - b.x) + (c.y - b.y) * (c.y - b.y));
	}

	bool isTriangle() {
		if ((ab + ac > bc) && (ac + bc > ab) && (bc + ab > ac)) {
			cout << "Triangle is ok :)" << endl;
			return true;
		}
		else {
			cout << "Triangle is not ok :(" << endl;
			return false;
		}
	}

	Triangle(Point A, Point B, Point C) {
		a = A;
		b = B;
		c = C;
		setSides();
		isTriangle();
	}

	Triangle(double ax, double ay, double bx, double by, double cx, double cy) {
		a.x = ax;
		a.y = ay;
		b.x = bx;
		b.y = by;
		c.x = cx;
		c.y = cy;
		setSides();
		isTriangle();
	}

	void setA(double x, double y) {
		a.x = x;
		a.y = y;
		setSides();
		isTriangle();
	}

	void setA(Point p) {
		a = p;
		setSides();
		isTriangle();
	}

	void setB(double x, double y) {
		b.x = x;
		b.y = y;
		setSides();
		isTriangle();
	}

	void setB(Point p) {
		b = p;
		setSides();
		isTriangle();
	}

	void setC(double x, double y) {
		c.x = x;
		c.y = y;
		setSides();
		isTriangle();
	}

	void setC(Point p) {
		c = p;
		setSides();
		isTriangle();
	}

	Point getA() {
		return a;
	}

	Point getB() {
		return b;
	}

	Point getC() {
		return c;
	}

	bool isEquilateral() {
		if ((ab == ac) && (ac == bc)) {
			cout << "Triangle is equilateral" << endl;
			return true;
		}
		else {
			cout << "Triangle is not equilateral" << endl;
		}
		return false;
	}

	bool isIsosceles() {
		if (ab == ac || ac == bc || bc == ab) {
			cout << "Triangle is isosceles" << endl;
			return true;
		}
		else {
			cout << "Triangle is not isosceles" << endl;
		}
		return false;
	}

	bool isRectangular() {
		if (abs(ab * ab + bc * bc - ac * ac) < 0.00001 || abs(bc * bc + ac * ac - ab * ab) < 0.00001 || abs(ac * ac + ab * ab - bc * bc) < 0.00001) {
			cout << "Triangle is rectangular" << endl;
			return true;
		}
		else {
			cout << "Triangle is not rectangular" << endl;
		}
		return false;
	}

	void print() {
		cout << "Coordinates of the triangle are: " << endl;
		cout << "(" << "[" << a.x << ", " << a.y << "]" << ", " << "[" << b.x << ", " << b.y << "]" << ", " << "[" << c.x << ", " << c.y << "]" << ")" << endl;
	}

	double area() {
		obw = ab + ac + bc;

		pol = sqrt((obw / 2) * ((obw / 2) - ab) * ((obw / 2) - ac) * ((obw / 2) - bc));
		cout << "Area of the triangle is: " << pol << endl;
		return 0;
	}

	double perimeter() {
		obw = ab + ac + bc;
		cout << "Perimeter of the triangle is: " << obw << endl;
		return 0;
	}

};

int main() {
	double a, b, c, d, e, f, g, h;
	Point p(4.8, 1.1);

	Point* p1 = new Point(4.2, 8.1);

	cout << "Provide coordinates of the first point: " << endl << "x: ";
	cin >> a;
	cout << "y: ";
	cin >> b;
	cout << endl;

	cout << "Provide coordinates of the second point: " << endl << "x: ";
	cin >> c;
	cout << "y: ";
	cin >> d;
	cout << endl;

	cout << "Provide coordinates of the third point: " << endl << "x: ";
	cin >> e;
	cout << "y: ";
	cin >> f;
	cout << endl;

	Triangle t{ a, b, c, d, e, f };
	cout << endl;
	t.print();
	cout << endl;
	t.isEquilateral();
	cout << endl;
	t.isIsosceles();
	cout << endl;
	t.isRectangular();
	cout << endl;
	t.area();
	cout << endl;
	t.perimeter();



	return 0;
}
