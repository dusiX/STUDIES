// Array of 15 random alphabetical digits

#include <iostream>
using namespace std;

long rndi(int a, int b) {
	return rand() % (b - a) + a;
}

int main() {
	srand(time(nullptr));
	char chars[15];
	for (int i = 0; i < 15; i++) {
		chars[i] = rndi(97, 123);
		cout << chars[i] << " ";
	}

	cout << endl;

	for (int i = 14; i >= 0; i--) {
		chars[i] = chars[i] - 32;
		cout << chars[i] << " ";
	}

	return 0;
}
