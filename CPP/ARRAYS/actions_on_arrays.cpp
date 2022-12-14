// Programme with array of 20 random integers in range [0, 100) which prints a sum and an arithmetic average of all numbers written in the array.
// Calculations are repeated 30 times and provided to a new array which average, minimum and maximum value is printed

#include <iostream>
using namespace std;

long rndi(int a, int b) {
	return rand() % (b - a) + a;
}

int main() {
	float A[20], B[30], sum = 0, sumofaverages = 0;
	int j;
	float average, averageofaverages, min, max;
	srand(time(nullptr));
	min = 100;
	max = 0;

	for (j = 0; j < 30; j++) {
		for (int i = 0; i < 20; i++) {
			A[i] = rndi(0, 100);
			cout << A[i] << " ";
			sum += A[i];
		}
		cout << endl;
		cout <<"The sum of the numbers is " << sum << endl;

		average = sum / 20;
		cout << "The arithmetic average is " << average << endl;
		sum = 0;
		B[j] = average;
		averageofaverages += B[j];
		if (B[j] < min) min = B[j];
		if (B[j] > max) max = B[j];
		cout << endl;
		average = 0;
	}
	cout << endl;
	averageofaverages = sumofaverages / 30;
	cout << "Tha sum of the averages is " << averageofaverages << endl;
	cout << "Minimum value within averages is " << min << endl;
	cout << "Maximum value within averages is " << max << endl;

	return 0;
}
