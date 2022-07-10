//Programme returns value of the element of n degree of the number A

#include <iostream>

using namespace std;

double pierwiastek(double a, int n) {
	double sp, p = a, xk = 1;
	do {
		sp = p;
		xk = 1;
		for (int i = 1; i < n; i++) {
			xk *= p;
		}

		p = (1.0 / n) * ((n - 1) * p + a / xk);
	} while ((sp - p) * (sp - p) > 0.00000000001);

	return p;
}

int main() {
	double a;
	int n;

	cout << "Provide a number:" << endl;
	cin >> a;
	cout << "Provide the degree of the element" << endl;
	cin >> n;
	cout << "The element of " << n << " degree of the number " << a << " is " << pierwiastek(a, n) << endl;


	return 0;
}
