#include <iostream>
using namespace std;

int sumakwadratow(int n) {
	long int kwadraty = 0;
	int reszta = 1;
	int i = 1;
	for (i = 1; reszta != 0; i++) {
		reszta = n % 10;
		if (reszta != 0)
			kwadraty = kwadraty + (reszta * reszta);
		n = n - reszta;
		n = n / 10;
	}

	return kwadraty;
}

int liczbapodzielnikow(int n) {
	int i = 0, j = 1;
	for (j = 1; j <= n; j++) {
		if (n % j == 0)
			i++;
	}
	return i;
}

int sumapodzielnikow(int n) {
	int suma = 0, j = 1;
	for (j = 1; j <= n; j++) {
		if (n % j == 0)
			suma += j;
	}
	return suma;
}

int liczba(int n, int reszta, int a, int k) {
	while (reszta != 0) {
		reszta = n % 10;
		if (reszta == a)
			k++;
		if (k > 1) {
			return 1;
		}
		n = n / 10;
	}
	return 0;
}

int liczbyunikalne(int n) {
	int i = 1, reszta = 1, k = 0, a = 0;
	for (a = 0; a < 10; k = 0) {
		if (liczba(n, reszta, a, k) == 1) {
			return 1;
		}
		else {
			reszta = 1;
			a++;
		}
	}
	return 0;
}

int NWD(int n, int m) {
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

int NWW(int n, int m) {
	if (m != n) {
		if (n > m) {
			if (n % m == 0) {
				return n;
			}
			else {
				int x;
				x = m * n;
				if (NWD(n, m) != 1) {
					x /= NWD(n, m);
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
				if (NWD(n, m) != 1) {
					x /= NWD(n, m);
				}
				return x;
			}
		}
	} else
		return m;
}

int ciag(int n) {
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
	if (ciag(n) == 0) {
		cout << "Liczba nalezy do ciagu Fibonacciego" << endl;
	}
	else
		cout << "Liczba nie nalezy do ciagu Fibonacciego" << endl;
}

int wielokrotnosc(int n) {
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
	cout << "Podaj pierwsza liczbe: " << endl;
	cin >> n;
	cout << "Podaj druga liczbe: " << endl;
	cin >> m;
	cout << endl;

	cout << "Dla liczby " << n << endl;
	cout << endl;
	cout << "Suma kwadratow tej liczby to: " << sumakwadratow(n) << endl;
	cout << "Ilosc podzielnikow tej liczby to: " << liczbapodzielnikow(n) << endl;
	cout << "Suma podzielnikow tej liczby to: " << sumapodzielnikow(n) << endl;
	if (liczbyunikalne(n) == 0)
		cout << "Cyfry w tej liczbie wystepuja mniej niz raz, czyli sa unikalne" << endl;
	else cout << "Cyfry w tej liczbie wystepuja wiecej niz raz, czyli nie sa unikalne" << endl;
	Fibonacci(n);
	if (wielokrotnosc(n) == 0)
		cout << "Ta liczba jest wielokrotnoscia kwadratu liczby calkowitej wiekszej od 2" << endl;
	else
		cout << "Ta liczba nie jest wielokrotnoscia kwadratu liczby calkowitej wiekszej od 2" << endl;
	cout << endl;
	cout << endl;

	cout << "Dla liczby " << m << endl;
	cout << endl;
	cout << "Suma kwadratow tej liczby to: " << sumakwadratow(m) << endl;
	cout << "Ilosc podzielnikow tej liczby to: " << liczbapodzielnikow(m) << endl;
	cout << "Suma podzielnikow tej liczby to: " << sumapodzielnikow(m) << endl;
	if (liczbyunikalne(m) == 0)
		cout << "Cyfry w tej liczbie wystepuja mniej niz raz, czyli sa unikalne" << endl;
	else cout << "Cyfry w tej liczbie wystepuja wiecej niz raz, czyli nie sa unikalne" << endl;
	Fibonacci(m);
	if (wielokrotnosc(m) == 0)
		cout << "Ta liczba jest wielokrotnoscia kwadratu liczby calkowitej wiekszej od 2" << endl;
	else
		cout << "Ta liczba nie jest wielokrotnoscia kwadratu liczby calkowitej wiekszej od 2" << endl;
	cout << endl;
	cout << endl;

	cout << "Najwiekszy wspolny dzielnik tych liczb to: " << NWD(n, m) << endl;
	cout << "Najmniejsza wspolna wielokrotnosc tych liczb to: " << NWW(n, m) << endl;

	return 0;
}