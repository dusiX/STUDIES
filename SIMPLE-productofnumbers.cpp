//Programme draws two numbers and counts their product

#include <iostream>
#include <cmath>
using namespace std;

long rndi(int a, int b) {
	return rand() % (b - a) + a;
}

int liczba(int a) {
	a = rndi(0, (int)pow(10, 100));
}

int main() {
	long int a = 0;
	srand(time(nullptr));
	a = liczba(a);

	long int b = 0;
	b = liczba(b);

	cout << "The product of the numbers " << a << " and " << b << " is " << a * b << endl;

	return 0;
}
