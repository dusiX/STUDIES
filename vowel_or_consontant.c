// Check if provided letter is a vowel or a consontant.

#include <stdio.h>
#include <locale.h>



int main()
{
    setlocale(LC_CTYPE, "Polish");
    char litera;

    printf("Provide a letter: \n");
    scanf_s(" %c", &litera);

    if (litera == '1' || litera == '2' || litera == '3' || litera == '4' || litera == '5' || litera == '6' || litera == '7' || litera == '8' || litera == '9' || litera == '0') {
        printf("This is not a letter");
        return 0;
    }

    if (litera == 'a' || litera == 'e' || litera == 'i' || litera == 'o' || litera == 'u' || litera == 'y' || litera == '¹' || litera == 'A' || litera == 'E' || litera == 'I' || litera == 'O' || litera == 'U' || litera == 'Y' || litera == '¥'){

        printf("%c is a vowel", litera);

    }
    
    else{
        
        printf("\nYour number is a consontant");
    
    }

    return 0;

}
