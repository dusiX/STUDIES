// Dynamic array allocation (width provided as a programme argument) filled with randomly generated numbers.
// There is a function, which counts product of odd natural numbers from generated array.
// The generated array and the result of the funtion is printed to the standard output and to the file (path to the file is provided as a second argument).


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#pragma warning(disable : 4996)

int main(int argc, char* argv[]) {

	FILE* fp=NULL;

	if (argc < 3) {
		printf("Not enough arguments\n");
		return 0;
	}

	int a = atoi(argv[1]), i;
	char* sciezka = argv[2];
	int c = 1;

	int *tab = NULL;
	tab = (int*)malloc(sizeof(int) *a);


	srand((unsigned int) time(NULL));

	for (i = 0; i < a; ++i) {

		tab[i] = rand() % 10;

	}

	printf("Array arguments:\n");

	for (i = 0; i < a; i++) {
		printf("%i", tab[i]);
		printf("\n");
	}
	
	for (i = 0; i < a; i++) {

		if (tab[i] % 2 == 1) {
			c = c * tab[i];
		}

	}

	printf("Product of odd natural numbers from array is: %i\n", c);

	if ((fp = fopen(sciezka, "w")) == NULL) {
			printf("You cannot do this!\n");
			return(1);
	}

	fprintf(fp, "Array arguments:\n");

	for (i = 0; i < a; i++) {
		fprintf(fp, "%i", tab[i]);
		fprintf(fp, "\n");
	}

	fprintf(fp, "Product of odd natural numbers from array is %d \n", c);
	fclose(fp);

	free(tab);
	tab = NULL;

	return 0;

}
