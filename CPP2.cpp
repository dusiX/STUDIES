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

	cout << "Podaj liczbe" << endl;
	cin >> a;
	cout << "Podaj stopien pierwiastka" << endl;
	cin >> n;
	cout << "Pierwiastkiem " << n << "-tego stopnia z liczby " << a << " wynosi " << pierwiastek(a, n) << endl;


	return 0;
}