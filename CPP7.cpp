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

	cout << "Podaj poczatek przedzialu:" << endl;
	cin >> a;
	cout << "Podaj koniec przedzialu:" << endl;
	cin >> b;
	cout << "Podaj przyrost:" << endl;
	cin >> p;

	cout << "Tabela od lewej bedzie podawac: " << endl;
	cout << "- wartosc argumentu x" << endl;
	cout << "- wartosc cos(x) z funkcji bibliotecznej" << endl;
	cout << "- wartosc cos(x) z rozwiniêcia w szereg Taylora" << endl;

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
