#include <iostream>

using namespace std;

long rndi(int a, int b) {
	return rand() % (b - a) + a;
}

int main() {
	srand(time(nullptr));
	int N = 10, i, j = 0, M = 10;

	cout << "Podaj wielkosc pierwszej tablicy " << endl;
	cin >> N;

	double* t1 = new double[N];
	double* t2 = new double [M];

	if (N % 2 == 0) {
		M = N / 2;
	}
	else {
		M = (N + 1) / 2;
	}

	for (int i = 0; i < N; ++i)
		t1[i] = rndi(0, 100);


	cout << endl;
	cout << "Twoja tablica o wymiarach " << N << ":" << endl;


	for (i = 0; i < N; i++) {
		cout << t1[i] << " ";
	}
	cout << endl;

	cout << endl;
	cout << "Tablica srednich arytmetycznych o wymiarze " << M << ":" << endl;

	for (i = 0; i < M; i++) {
		if (j + 1 < N) {
			t2[i] = (t1[j] + t1[j + 1]) / 2;
			cout << t2[i] << " ";
		}
		else {
			t2[i] = t1[j];
			cout << t2[i] << " ";
		}
		j++;
		j++;
	}

	delete[] t2;
	return 0;
}