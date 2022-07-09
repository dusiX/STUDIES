// Count polynomial value using Horner's diagram

#include <iostream>
using namespace std;

double calculateHorner(double a, double b, double c, double d, double x) {
	return ((a * x + b) * x + c) * x + d;
}

double calculate(double a, double b, double c, double d, double x) {
	return a * x * x * x + b * x * x + c * x + d;
}

int main() {
	double a, b, c, d, x;
	cin >> a >> b >> c >> d >> x;
	cout << calculateHorner(a, b, c, d, x) << endl << calculate(a, b, c, d, x);

	return 0;
}
