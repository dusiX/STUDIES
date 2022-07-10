#include <iostream>
using namespace std;

long rndi(int a, int b) {
	return rand() % (b - a) + a;
}

int main() {
	srand(time(nullptr));
	char znaki[15];
	for (int i = 0; i < 15; i++) {
		znaki[i] = rndi(97, 123);
		cout << znaki[i] << " ";
	}

	cout << endl;

	for (int i = 14; i >= 0; i--) {
		znaki[i] = znaki[i] - 32;
		cout << znaki[i] << " ";
	}

	return 0;
}