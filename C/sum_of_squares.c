/* Sum of squared numbers from 1 to n. */

#include <stdio.h>
#include <stdlib.h>

int suma_kwadratow_do(int);
int main(void) {

	int i, a[100];
	int a_suma_wprost = 0, a_suma_formula = 0;
	for (i = 1; i <= 100; i++) {
		a[i - 1] = i * i;
	}

	for (i = 1; i <= 100; i++) {
		a_suma_wprost = a_suma_wprost + a[i - 1];
	}

	a_suma_formula = suma_kwadratow_do(100);
	printf("suma wprost: %d = suma z formuly: %d\n",
		a_suma_wprost, a_suma_formula);
	return 0;
}
int suma_kwadratow_do(int n) {
	n = n* (n + 1)* (2 * n + 1) / 6;
}
