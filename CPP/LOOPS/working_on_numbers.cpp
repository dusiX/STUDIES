// Programme returns a sum of the numbers squares, returns a quantity of divisors of the number, returns a sum of divisors of the numbers,
// checks if all digits in the number are unique, returns the greatest common divisor of the numbers, returns the least common multiple of the numbers,
// checks if the number is an element of the Fibonacci sequence and checks if the number is a multiple of squared natural number greater than 2

#include <iostream>
using namespace std;

int sumofsquares(int n) {
	long int squares = 0;
	int rest = 1;
	int i = 1;
	for (i = 1; rest != 0; i++) {
		rest = n % 10;
		if (rest != 0)
			squares = squares + (rest * rest);
		n = n - rest;
		n = n / 10;
	}

	return squares;
}

int numberofdivisors(int n) {
	int i = 0, j = 1;
	for (j = 1; j <= n; j++) {
		if (n % j == 0)
			i++;
	}
	return i;
}

int sumofdivisors(int n) {
	int sum = 0, j = 1;
	for (j = 1; j <= n; j++) {
		if (n % j == 0)
			sum += j;
	}
	return sum;
}

int number(int n, int rest, int a, int k) {
	while (rest != 0) {
		rest = n % 10;
		if (rest == a)
			k++;
		if (k > 1) {
			return 1;
		}
		n = n / 10;
	}
	return 0;
}

int uniquenumbers(int n) {
	int i = 1, rest = 1, k = 0, a = 0;
	for (a = 0; a < 10; k = 0) {
		if (number(n, rest, a, k) == 1) {
			return 1;
		}
		else {
			rest = 1;
			a++;
		}
	}
	return 0;
}

int greatestcommondivisor(int n, int m) {
	while (n != m) {
		if (m > n) {
			m -= n;
		}
		else if (m < n) {
			n -= m;
		}
	}
	if (m == n) {
		return m;
	}
	else {
		return 1;
	}
}

int leastcommonmultiple(int n, int m) {
	if (m != n) {
		if (n > m) {
			if (n % m == 0) {
				return n;
			}
			else {
				int x;
				x = m * n;
				if (greatestcommondivisor(n, m) != 1) {
					x /= greatestcommondivisor(n, m);
				}
				return x;
			}
		}
		else if (m > n) {
			if (m % n == 0) {
				return m;
			}
			else {
				int x;
				x = m * n;
				if (greatestcommondivisor(n, m) != 1) {
					x /= greatestcommondivisor(n, m);
				}
				return x;
			}
		}
	} else
		return m;
}

int sequence(int n) {
	int a = 0, b = 1, c;
	c = a + b;
	while (c <= n) {
		if (a == n)
			return 0;
		else if (b == n)
			return 0;
		else if (c == n)
			return 0;
		else {
			a = b;
			b = c;
			c = a + b;
		}
	}
	return 1;
}

void Fibonacci(int n) {
	if (sequence(n) == 0) {
		cout << "The number belongs to Fibonacci sequence" << endl;
	}
	else
		cout << "The number doesn't belong to Fibonacci sequence" << endl;
}

int multiple(int n) {
	int k, i, x;
	for (i = 3; i < n; i++) {
		k = i * i;
		x = k;
		if (k <= n) {
			while (k <= n) {
				if (k == n) {
					return 0;
				}
				else
					k += x;
			}
		}
		else
			return 1;
	}
	return 1;
}

int main() {
	int n, m;
	cout << "Provide first number: " << endl;
	cin >> n;
	cout << "Provide second number: " << endl;
	cin >> m;
	cout << endl;

	cout << "For the number " << n << endl;
	cout << endl;
	cout << "The sum of the squares of this number is: " << sumofsquares(n) << endl;
	cout << "The quantity of divisors of this number is: " << numberofdivisors(n) << endl;
	cout << "The sum of the divisors of this number is: " << sumofdivisors(n) << endl;
	if (uniquenumbers(n) == 0)
		cout << "The digits in this number appear less than once, which means they are unique" << endl;
	else cout << "The digits in this number appear more than once, which means they aren't unique" << endl;
	Fibonacci(n);
	if (multiple(n) == 0)
		cout << "This number is a multiple of the square of an integer greater than 2" << endl;
	else
		cout << "This number isn't a multiple of the square of an integer greater than 2" << endl;
	cout << endl;
	cout << endl;

	cout << "For the number " << m << endl;
	cout << endl;
	cout << "The sum of the squares of this number is: " << sumofsquares(m) << endl;
	cout << "The quantity of divisors of this number is: " << numberofdivisors(m) << endl;
	cout << "The sum of the divisors of this number is: " << sumofdivisors(m) << endl;
	if (uniquenumbers(m) == 0)
		cout << "The digits in this number appear less than once, which means they are unique" << endl;
	else cout << "The digits in this number appear more than once, which means they aren't unique" << endl;
	Fibonacci(m);
	if (multiple(m) == 0)
		cout << "This number is a multiple of the square of an integer greater than 2" << endl;
	else
		cout << "This number isn't a multiple of the square of an integer greater than 2" << endl;
	cout << endl;
	cout << endl;

	cout << "The greatest common divisor of these numbers is: " << greatestcommondivisor(n, m) << endl;
	cout << "The least common multiple of these numbers is: " << leastcommonmultiple(n, m) << endl;

	return 0;
}
