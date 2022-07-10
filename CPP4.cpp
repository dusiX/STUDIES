#include <iostream>

using namespace std;
int i = 0, j = 0, x;

bool is_prime(int n) {
	if (n < 2)
		return 1;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return 1;
	return 0;
}

void print_primes(int m, int n){
	cout << "Wszystkie liczby z przedzialu od " << m << " do " << n << " to: " << endl;
	while (j <= n) {
		if (j >= m) {
			if (is_prime(j) == 0) {
				cout << j << endl;
			}
		}
		j++;
	}
}

int num_primes(int m, int n) {
	j = 0;
	while (j <= n) {
		if (j >= m) {
			if (is_prime(j) == 0) {
				i++;
			}
		}
		j++;
	}
	return i;
}

int glowny(int m, int n) {
	print_primes(m, n);
	cout << "Ilosc liczb pierwszych w danym przedziale: " << num_primes(m, n) << endl;
	return 0;
}

int main(int m, int n) {
	glowny(50, 150);

	for (x = 0; x <= 10; x++) {
		glowny((x * 100) + 1, (x + 1) * 100);
	}

	return 0;
}