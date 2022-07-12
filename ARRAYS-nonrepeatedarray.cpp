// Programme sorts provided arrays and returns third array filled with non-repeated numbers from first and second array

#include <iostream>

using namespace std;

long rndi(int a, int b) {
	return rand() % (b - a) + a;
}

int merge(int t1[], int N1, int t2[], int N2) {
	int x, j = 0, M = 10;
	M = N1 + N2;
	int* t3 = new int[M];

	for (int i = 0; i < N1; i++) {
		t3[j] = t1[i];
		j++;
	}

	for (int i = 0; i < N2; i++) {
		t3[j] = t2[i];
		j++;
	}

	cout << endl;
	cout << endl;
	cout << "Trzecia tablica nieposortowana" << endl;

	for (int i = 0; i < M; i++) {
		cout << t3[i] << " ";
	}

	cout << endl;
	cout << endl;

	for (int i = 0; i < M; i++)
		for (j = 1; j < M - i; j++)
			if (t3[j - 1] > t3[j]) {
				swap(t3[j - 1], t3[j]);
			}

	x = M;

	for (int i = 0; i < M; i++) {
		for (int j = 1; j < x - i; j++) {
			if (t3[j - 1] != t3[j]) {
				continue;
			}
			else {
				for (int k = j; k < x; k++) {
					t3[k - 1] = t3[k];
				}
				x--;
			}
		}
	}


	M = x;

	cout << "Trzecia tablica posortowana" << endl;

	for (int i = 0; i < M; i++) {
		cout << t3[i] << " ";
	}
	
	delete[]t3;
	return M;
}

int main() {
	srand(time(nullptr));

	int N1, N2, M;

	cout << "Podaj wielkosc pierwszej tablicy" << endl;
	cin >> N1;
	cout << endl;
	cout << "Podaj wielkosc drugiej tablicy" << endl;
	cin >> N2;

	int* t1 = new int[N1];
	int* t2 = new int[N2];

	cout << endl;
	cout << "Pierwsza tablica nieposortowana" << endl;

	for (int i = 0; i < N1; i++) {
		t1[i] = rndi(0, 11);
		cout << t1[i] << " ";
	}

	cout << endl;
	cout << endl;
	cout << "Druga tablica nieposortowana" << endl;

	for (int i = 0; i < N2; i++) {
		t2[i] = rndi(0, 11);
		cout << t2[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < N1; i++)
		for (int j = 1; j < N1 - i; j++)
			if (t1[j - 1] > t1[j])
				swap(t1[j - 1], t1[j]);

	for (int i = 0; i < N2; i++)
		for (int j = 1; j < N2 - i; j++)
			if (t2[j - 1] > t2[j])
				swap(t2[j - 1], t2[j]);

	cout << endl;
	cout << "Pierwsza tablica posortowana" << endl;

	for (int i = 0; i < N1; i++) {
		cout << t1[i] << " ";
	}

	cout << endl;
	cout << endl;
	cout << "Druga tablica posortowana" << endl;

	for (int i = 0; i < N2; i++) {
		cout << t2[i] << " ";
	}

	M = N1 + N2;

	M = merge(t1, N1, t2, N2);

	cout << endl;
	cout << "Wielkosc wynikowej tablicy to " << M << endl;

	delete[]t1;
	delete[]t2;

	return 0;
}
