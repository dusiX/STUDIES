#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

	int a;

	srand(time(NULL));
	int x = (rand() % 100);

	cout << "Uwazam, ze X ma wartosc: \n";
	cin >> a;

	if (a == x)
		cout << "Brawo! Trafiles!";
	else
		cout << "Nie tym razem :( \n Sprobuj jeszcze raz!";

	cout << "Wylosowane X ma wartosc:" << x;

	return 0;
}