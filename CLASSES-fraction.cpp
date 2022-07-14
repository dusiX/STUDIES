// Programme including class which adds, multiplies, reduces and returns fraction

#include <iostream>

using namespace std;

class Fraction {
private:

	float dod, mno, r, x, y;
	int i;

public:

	Fraction() {
		x = 0;
		y = 0;
	}

	bool zero() {
		if (y == 0) {
			cout << "ERROR" << endl;
		}
		return false;
	}

	Fraction(int a, int b) {
		this->x = a;
		this->y = b;
		zero();
		reduce();
	}

	float add() {
		zero();
		reduce();
		dod = (x + x) / y;
		return dod;
	}

	float mult() {
		zero();
		reduce();
		mno = (x * x) / (y * y);
		return mno;
	}

	void reduce() {
		zero();
		int a, b, c;
		if (y < x) { a = x; b = y; }
		else { a = y; b = x; }
		do { c = a % b; a = b; b = c; } while (c != 0);

		x = x / a;
		y = y / a;

	}

	void print() {
		reduce();
		zero();
		cout << "The fraction is: " << x << "/" << y << endl;
		cout << "The fraction in the form of a real number: " << evaluate() << endl;
		cout << "A sum of the fractions: " << add() << endl;
		cout << "A product of the fractions: " << mult() << endl;
	}

	float evaluate() {
		zero();
		reduce();
		r = x / y;

		return r;
	}
	
};

int main() {
	int x, y;

	cout << "Provide meter: " << endl;
	cin >> x;
	cout << "Provide denominator: " << endl;
	cin >> y;

	Fraction f(x, y);
	f.print();

	return 0;
}
