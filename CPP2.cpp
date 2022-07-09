#include <iostream>
using namespace std;

int main() {
	unsigned int N;
	unsigned int silnia = 1;
	cout << "WprowadŸ liczbê N: \n";
	cin >> N;

	for (int i = 1; i <= N; i++)
		silnia *= i;

	cout << silnia << endl;
	return 0;
}