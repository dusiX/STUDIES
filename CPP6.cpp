#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>
using namespace std;

double rndd(double M, double N)
{
	return M + (rand() / (RAND_MAX / (N - M)));
}

int main() {
	float y, x, a, b, pole, N, n = 1;

	cout << "Podaj poczatek przedzialu:" << endl;
	cin >> a;
	cout << "Podaj koniec przedzialu:" << endl;
	cin >> b;
	cout << "Podaj liczbe losowanych punktow:" << endl;
	cin >> N;

	srand(static_cast <unsigned> (time(0)));

	for (int i{ 0 }; i < N; ++i)
	{

		x = rndd(a, b);
		y = rndd(-1, 1);

		if (y <= sin(x)*sin(x))
		{
			++n;
		}
	}

	pole = n / N;

	cout << "Pole wynosi: " << pole << endl;

	return 0;
}

