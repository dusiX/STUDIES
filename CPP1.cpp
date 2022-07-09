#include <iostream>
using namespace std;

int main() {
	int a, x, p;
	cout << endl;
	cout << "Wprowadz cenê netto: \n";
	cin >> a;
	cout << "Wprowadz liczbe zakupionych sztuk towaru: \n";
	cin >> x;
	cout << "Wprowadz wysokosc VAT w procentach: \n";
	cin >> p;

	int NETTO = a * x;
	cout << "Wartosc netto:" << NETTO << "\n";
	int BRUTTO = NETTO * (100 + p) / 100;
	cout << "Wartosc brutto:" << BRUTTO << "\n";
	int VAT = BRUTTO - NETTO;
	cout << "Wartosc VAT:" << VAT << "\n";

	cout << endl;
	return 0;
}