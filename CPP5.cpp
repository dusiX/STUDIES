#include<iostream>
#include<string>

using namespace std;

inline int sprawdz(char znak)
{
	//jesli jest mala litera
	if (znak >= 'a' && znak <= 'z') return 0;
	//jesli jest duza litera
	if (znak >= 'A' && znak <= 'Z') return 1;
	//inna ni¿ litera
	return 2;
}

void szyfruj(int klucz, string& tab)
{
	//sprawdzenie, czy klucz miesci sie w zakresie
	if (!(klucz >= -26 && klucz <= 26)) return;

	int pom;
	char a, z;

	for (int i = 0; i < tab.size(); i++)
	{
		pom = sprawdz(tab[i]);
		//ustalienie wielkosci litery
		if (pom < 2)
		{
			if (pom == 0)
				a = 'a', z = 'z';
			else
				a = 'A', z = 'Z';

			if (klucz >= 0)

				if (tab[i] + klucz <= z)
					tab[i] += klucz;
				else
					tab[i] = tab[i] + klucz - 26;
			else
				if (tab[i] + klucz >= a)
					tab[i] += klucz;
				else
					tab[i] = tab[i] + klucz + 26;
		}
	}
}

int main()
{
	string tab;

	int klucz;

	cout << "Podaj zdanie do zaszyfrowania: ";
	getline(cin, tab);

	cout << "Podaj klucz z przedzia³u [-26..26]: ";
	cin >> klucz;

	szyfruj(klucz, tab); //szyfrowanie

	cout << "Po zaszyfrowaniu: " << tab << endl;

	return 0;
}