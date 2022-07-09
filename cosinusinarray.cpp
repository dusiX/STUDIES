// Push cosinus function to the array in provided range.

#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

float Taylor(float x) {
	float o = 0, T = 1, y = 1;
	while (fabs(y) > 1e-20) {
		y = (-y * x * x) / ((o + 1) * (o + 2));
		T += y;
		o += 2;
	}
	return T;
}

int main() {
	float p, x, y = 1, a, b, n = 0;

	cout << "Beggining of the interval:" << endl;
	cin >> a;
	cout << "Ending of the interval:" << endl;
	cin >> b;
	cout << "Provide increase value:" << endl;
	cin >> p;

	cout << "Array would print (from the left side): " << endl;
	cout << "- value of x argument << endl;
	cout << "- value of cos(x) from library function" << endl;
	cout << "- value of cos(x) from Taylor's series" << endl;

	x = a;

	for (int i = 0; i <= n; i++) {
		if (x <= b) {
			++n;
		}
		cout << x << "        ";
		cout << cos(x) << "        ";
		cout << Taylor(x) << endl;
		x += p;
	}

	return 0;
}
