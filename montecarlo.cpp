// Find surface area bounded by the axis OX and graph of the function sin(x) in range [a, b] by Monte Carlo method. 

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

	cout << "Provide beggining of the interval:" << endl;
	cin >> a;
	cout << "Provide ending of the interval:" << endl;
	cin >> b;
	cout << "Provide a number of randomised points:" << endl;
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

	cout << "The surface area is: " << pole << endl;

	return 0;
}

