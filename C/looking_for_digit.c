// Find and print first and last digit in the number(int).

#include <stdio.h>

int main() {

	int liczba, pierwsza, ostatnia;
	int n;

	printf("Provide a random number:\n");
	scanf_s("%d", &liczba);

	ostatnia = liczba % 10;

	while (liczba >= 10){
		liczba = liczba / 10;
	}

	pierwsza = liczba;

	printf("The first digit in your number is: %d\n", pierwsza);
	printf("The last digit in your number is: %d\n", ostatnia);

	return 0;
}
