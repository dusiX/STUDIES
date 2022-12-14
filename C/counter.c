// Programme which counts digits, words, bytes and lines in a file.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

	FILE* fp = NULL;

	if (argc < 2) {
		printf("Not enough arguments\n");
		return 1;
	}

	char* sciezka = argv[1];

	if ((fp = fopen(sciezka, "r")) == NULL) {
		printf("You cannot do this!");
		return 1;
		}

	int bajty = 0;
	int slowa = 1;
	int linijki = 0;
	int znaki = 1;
	char ch, c;

	printf("Wait...\n\n");

	ch = fgetc(fp);

	while (ch != EOF) {

		if (ch == '\n') {

			linijki = linijki + 1;
			slowa++;

		} else if (ch == ' ') {
			slowa++;
		}
		else {
			znaki++;
		}

		ch = fgetc(fp);
	
	}

	linijki = linijki + 1;

	fseek(fp, 0L, SEEK_END);
	bajty = ftell(fp);
	
	printf("Number of bytes in the file: %d\n", bajty);

	printf("Number of lines in the file: %d\n", linijki);

	printf("Number of words in the file: %d\n", slowa);

	printf("Number of digits in the file: %d\n", znaki);

	if (fp == NULL) {
		return 1;
	}
	else(fclose(fp));

	return 0;

}
