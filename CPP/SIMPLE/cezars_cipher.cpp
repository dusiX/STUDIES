// String encryption programme (like Cezar's cipher)

#include<iostream>
#include<string>

using namespace std;

inline int check(char c)
{
	if (c >= 'a' && c <= 'z') return 0;
	if (c >= 'A' && c <= 'Z') return 1;
	return 2;
}

void encrypt(int key, string& tab)
{
	if (!(key >= -26 && key <= 26)) return;

	int pom;
	char a, z;

	for (int i = 0; i < tab.size(); i++)
	{
		pom = check(tab[i]);
		if (pom < 2)
		{
			if (pom == 0)
				a = 'a', z = 'z';
			else
				a = 'A', z = 'Z';

			if (key >= 0)

				if (tab[i] + key <= z)
					tab[i] += key;
				else
					tab[i] = tab[i] + key - 26;
			else
				if (tab[i] + key >= a)
					tab[i] += key;
				else
					tab[i] = tab[i] + key + 26;
		}
	}
}

int main()
{
	string tab;

	int key;

	cout << "Provide string to encrypt: ";
	getline(cin, tab);

	cout << "Provide a key in range [-26..26]: ";
	cin >> key;

	encrypt(key, tab);

	cout << "After encrypting: " << tab << endl;

	return 0;
}
