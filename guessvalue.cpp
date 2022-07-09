// Guess random "X" value

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {

	int a;

	srand(time(NULL));
	int x = (rand() % 100);

	cout << "I think X's value is: \n";
	cin >> a;

	if (a == x)
		cout << "Great! You made it!";
	else
		cout << "Not this time \n Try once again!";

	cout << "Randomly generated X is:" << x;

	return 0;
}
