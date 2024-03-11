#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

//2.1

/*
void tabelare(double (*f)(double), double A, double B, double P) 
{
    double x;
    for (x = A; x <= B; x += P) 
    {
        double r = f(x);
        printf("f(%.2f) = %.2f\n", x, r);
    }
}


double functie1(double x) 
{
    return (x * x * x + 4) / (x * x + 5);
}

double functie2(double x) 
{
    return x + 10;
}

double functie3(double x) 
{
    return 2 * x * x - 1;
}

int main() 
{
    double A, B, P;
    printf(" A B P: ");
    scanf("%lf %lf %lf", &A, &B, &P);

    printf("functie1:\n");
    tabelare(functie1, A, B, P);

    printf("functie2:\n");
    tabelare(functie2, A, B, P);

    printf("functie3:\n");
    tabelare(functie3, A, B, P);

    return 0;
}
*/

//2.2

/*
int lungime(const char* s) 
{
    return strlen(s);
}

int vocale(const char* s) 
{
    int numar = 0;
    for (int i = 0; s[i] != '\0'; i++) 
    {
        char c = tolower(s[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') 
        {
            numar++;
        }
    }
    return numar;
}

int numarliteremari(const char* s) 
{
    int numar = 0;
    for (int i = 0; s[i] != '\0'; i++) 
    {
        if (isupper(s[i])) 
        {
            numar++;
        }
    }
    return numar;
}

int diferentaASCII(const char* s) 
{
    return s[strlen(s) - 1] - s[0];
}

int main(int argc, char* argv[]) 
{
    if (argc < 2) 
    {
        printf("introduceți cuvant.\n");
        return 1;
    }

    FILE* file = fopen("CUVINTE.TXT", "w");
    if (file == NULL) 
    {
        printf("eroare\n");
        return 1;
    }

    for (int i = 1; i < argc; i++)
    {
        printf("cuvânt: %s\n", argv[i]);
        fprintf(file, "cuvânt: %s\n", argv[i]);

        printf("lungime: %d\n", lungime(argv[i]));
        fprintf(file, "lungime: %d\n", lungime(argv[i]));

        printf("vocale: %d\n", vocale(argv[i]));
        fprintf(file, "vocale: %d\n", vocale(argv[i]));

        printf("litere mari: %d\n", numarliteremari(argv[i]));
        fprintf(file, "litere mari: %d\n", numarliteremari(argv[i]));

        printf("diferența ASCII: %d\n", diferentaASCII(argv[i]));
        fprintf(file, "diferența ASCII: %d\n", diferentaASCII(argv[i]));

        printf("\n");
        fprintf(file, "\n");
    }

    fclose(file);
    return 0;
}
*/