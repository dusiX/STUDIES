// Programme, which counts  multiplicity of individual printable digits from ASCII array, in the file provided as a programme argument.

#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){

    FILE* fp = NULL;

    if (argc < 2) {
        printf("Not enought arguments\n");
        return 1;
    }

    char* sciezka = argv[1];

    if ((fp = fopen(sciezka, "r")) == NULL) {
        printf("You cannot do this!");
        return 1;
    }

    char ch, c;
    int i, ile = 0;

    printf("Provide the digit you are looking for:\n");
    scanf_s("%c", &c);

    ch = fgetc(fp);

    while (ch != EOF) {

        if (ch == c)
        {
            ile++;
        }

        ch = fgetc(fp);

    }

    printf("The digit you are looking for appears %d times \n ", ile);

    fclose(fp);
    return 0;
}
