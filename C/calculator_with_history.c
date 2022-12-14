// Programme is a calculator which saves its history in the file.

#include <stdio.h>

void wypisz_menu_glowne()
{
    printf("Main menu:\n");
    printf("1) Add\n2) Subtract\n");
    printf("5) History\n");
    printf("9) Leave");  
}

void wypisz_menu_historii()
{
    printf("History menu:\n");
    printf("1) Show\n");
    printf("2) Save\n");
    printf("3) Read\n");
    printf("4) Clear\n");
    printf("9) Leave");  
}

void historia()
{
    int opcja;  
      
    for (;;)
    {
      wypisz_menu_historii();
      printf("\nProvide an option:");
      scanf("%d", &opcja);

      if (opcja == 9)
        return;
    }
}

int main()  
{  
    int opcja, a, b, wynik;  
      
    for (;;)
    {
      wypisz_menu_glowne();
      printf("\nProvide an option:");
      scanf("%d", &opcja);
      switch (opcja)
      {
        case 1:
            printf("Provide first number: ");
            scanf("%d", &a);
            printf("Provide second number: ");
            scanf("%d", &b);
            wynik = a + b;
            printf("Result: %d\n", wynik);
            break;
        
        case 2:
            printf("Provide first number: ");
            scanf("%d", &a);
            printf("Provide second number: ");
            scanf("%d", &b);
            wynik = a - b;
            printf("Result: %d\n", wynik);
            break;

        case 5:
            historia();
            break;

        case 9:
            return 0;
      }
    }    
    return 0;  
}  
