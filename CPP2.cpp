#include <iostream>
using namespace std;

long rndi(int a, int b) {
	return rand() % (b - a) + a;
}

int main() {
	float A[20], B[30], suma = 0, sumasrednich = 0;
	int j;
	float srednia, sredsrednich, min, max;
	srand(time(nullptr));
	min = 100;
	max = 0;

	for (j = 0; j < 30; j++) {
		for (int i = 0; i < 20; i++) {
			A[i] = rndi(0, 100);
			cout << A[i] << " ";
			suma += A[i];
		}
		cout << endl;
		cout <<"Suma liczb wynosi " << suma << endl;

		srednia = suma / 20;
		cout << "Srednia wynosi " << srednia << endl;
		suma = 0;
		B[j] = srednia;
		sumasrednich += B[j];
		if (B[j] < min) min = B[j];
		if (B[j] > max) max = B[j];
		cout << endl;
		srednia = 0;
	}
	cout << endl;
	sredsrednich = sumasrednich / 30;
	cout << "Srednia srednich to " << sredsrednich << endl;
	cout << "Minimalna srednia to " << min << endl;
	cout << "Maksymalna srednia to " << max << endl;

	return 0;
}