// Count net value, VAT value and gross value of purchased product

#include <iostream>
using namespace std;

int main() {
	int a, x, p;
	cout << endl;
	cout << "Provide net price: \n";
	cin >> a;
	cout << "Provide a number of pieces purchased: \n";
	cin >> x;
	cout << "Provide VAT value in %: \n";
	cin >> p;

	int NETTO = a * x;
	cout << "Net value:" << NETTO << "\n";
	int BRUTTO = NETTO * (100 + p) / 100;
	cout << "Gross value:" << BRUTTO << "\n";
	int VAT = BRUTTO - NETTO;
	cout << "VAT value:" << VAT << "\n";

	cout << endl;
	return 0;
}
