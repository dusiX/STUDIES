// Programme loads size of an array filled with random numbers in range [0, 1] and sums up adjacent numbers

#include <iostream>
#include <random>
#include <time.h>
#include <ctime>

using namespace std;

long rndi(int a, int b) {
	return rand() % (b - a) + a;
}

int ran()
{
	int randNum = rand() % 2; 

	return randNum;
}

int main() {
	int n = 100, r = 0, x = 0, k, l;

	srand(time(NULL));

	cout << "Provide size of an array:" << endl;
	cin >> n;
	cout << endl;
	cout << "Provide the distance over which the sum is to be measured:" << endl;
	cin >> r;
	cout << endl;
	cout << endl;

	double** F = new double* [n];

	for (int i = 0; i < n; i++) {
		F[i] = new double[n];
	}

	double** W = new double* [n];

	for (int i = 0; i < n; i++) {
		W[i] = new double[n];
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			F[i][j] = ran();
		}
	}

	cout << "Size of the array is " << n << "x" << n << " and a maximum distance is " << r << endl;
	cout << endl;
	cout << "Original array looks like this:" << endl;
	cout << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << F[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			W[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = i - r; k <= i + r; k++) {
				if (k < 0) {
					continue;
				}
				else if (k < n) {
					for (int l = j - r; l <= j + r; l++) {
						if (l < 0) {
							continue;
						}
						else if (l < n) {
							if (F[k][l] > 0) {
								W[i][j]++;
							}
						}
					}
				}
			}
		}
	}

	cout << "Generated and summed array looks like this:" << endl;
	cout << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << W[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < n; i++) {
		delete [] F[i];
	}

	for (int i = 0; i < n; i++) {
		delete[] W[i];
	}

	delete[] F;
	delete[] W;
	return 0;
}
