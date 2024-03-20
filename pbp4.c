#include <stdio.h>
#include <stdlib.h>
#include<string.h>


//pb1

/*
typedef struct 
{
    unsigned int cod : 14;
    unsigned int locuri : 4;
    unsigned int putere : 9;
    char marca[50];
    char culoare[50];
    unsigned int an : 11;
} Masina;

Masina *parc;
int n = 0;

void introducere() 
{
    parc = realloc(parc, (n + 1) * sizeof(Masina));
    unsigned int aux1=0, aux2=0, aux3=0, aux4=0;
    printf("Introduceti codul masinii: ");
    scanf("%u", &aux1);
    parc[n].cod=aux1;
    printf("Introduceti numarul de locuri: ");
    scanf("%u", &aux2);
    parc[n].locuri=aux2;
    printf("Introduceti puterea: ");
    scanf("%u", &aux3);
    parc[n].putere=aux3;
    printf("Introduceti marca: ");
    scanf("%s", parc[n].marca);
    printf("Introduceti culoarea: ");
    scanf("%s", parc[n].culoare);
    printf("Introduceti anul fabricatiei: ");
    scanf("%u", &aux4);
    parc[n].an=aux4;
    n++;
}

void stergere(unsigned int cod) 
{
    for (int i = 0; i < n; i++) 
    {
        if (parc[i].cod == cod) {
            for (int j = i; j < n - 1; j++) 
            {
                parc[j] = parc[j + 1];
            }
            parc = realloc(parc, (--n) * sizeof(Masina));
            return;
        }
    }
    printf("Nu exista masina cu codul dat.\n");
}

void afisare() 
{
    for (int i = 0; i < n; i++) 
    {
        printf("Cod: %u, Locuri: %u, Putere: %u, Marca: %s, Culoare: %s, An: %u\n",parc[i].cod, parc[i].locuri, parc[i].putere, parc[i].marca, parc[i].culoare, parc[i].an);
    }
}

void afisare_locuri(unsigned int locuri) 
{
    for (int i = 0; i < n; i++) 
    {
        if (parc[i].locuri == locuri) 
        {
            printf("Cod: %u, Locuri: %u, Putere: %u, Marca: %s, Culoare: %s, An: %u\n",parc[i].cod, parc[i].locuri, parc[i].putere, parc[i].marca, parc[i].culoare, parc[i].an);
        }
    }
}

int compar(const void *a, const void *b) 
{
    Masina *masinaA = (Masina *)a;
    Masina *masinaB = (Masina *)b;
    return (masinaA->an - masinaB->an);
}

void ordonare() 
{
    qsort(parc, n, sizeof(Masina), compar);
}

int main()
{
    unsigned int cod, locuri;
    introducere();
    printf("Introduceti codul masinii pe care doriti sa o stergeti: ");
    scanf("%u", &cod);
    stergere(cod);
    afisare();
    printf("Introduceti numarul de locuri: ");
    scanf("%u", &locuri);
    afisare_locuri(locuri);
    ordonare();
    afisare();
    return 0;
}

*/

//pb2

typedef struct 
{
    unsigned int nrExemplare : 10;
    unsigned int pret : 9;
    unsigned int nrPagini : 10;
    unsigned int greutate : 13;
    unsigned int tip : 1;
    union 
    {
        char isbn[14];
        unsigned int anAparitie : 11;
    } info;
    char titlu[50];
    char autor[50];
} Publicatie;

Publicatie *biblioteca;
int n = 0;

void introducere() 
{
    unsigned int aux1=0, aux2=0, aux3=0, aux4=0, aux5=0, aux6=0;
    biblioteca = realloc(biblioteca, (n + 1) * sizeof(Publicatie));
    printf("Introduceti titlul: ");
    scanf("%s", biblioteca[n].titlu);
    printf("Introduceti autorul: ");
    scanf("%s", biblioteca[n].autor);
    printf("Introduceti numarul de exemplare: ");
    scanf("%u", &aux1);
    biblioteca[n].nrExemplare=aux1;
    printf("Introduceti pretul: ");
    scanf("%u", &aux2);
    biblioteca[n].pret=aux2;
    printf("Introduceti numarul de pagini: ");
    scanf("%u", &aux3);
    biblioteca[n].nrPagini=aux3;
    printf("Introduceti greutatea: ");
    scanf("%u", &aux4);
    biblioteca[n].greutate=aux4;
    printf("Este carte (1) sau revista (0)? ");
    scanf("%u", &aux5);
    biblioteca[n].tip=aux5;
    if (biblioteca[n].tip) 
    {
        printf("Introduceti ISBN: ");
        scanf("%s", biblioteca[n].info.isbn);
    } else 
    {
        printf("Introduceti anul aparitiei primului numar: ");
        scanf("%u", &aux6);
        biblioteca[n].info.anAparitie=aux6;
    }
    n++;
}

void afisare_carti_pret() 
{
    for (int i = 0; i < n; i++) 
    {
        if (biblioteca[i].tip && biblioteca[i].pret > 100) 
        {
            printf("Titlu: %s, Autor: %s, ISBN: %s\n",
                   biblioteca[i].titlu, biblioteca[i].autor, biblioteca[i].info.isbn);
        }
    }
}

void afisare() 
{
    for (int i = 0; i < n; i++) 
    {
        printf("Titlu: %s, Autor: %s, ", biblioteca[i].titlu, biblioteca[i].autor);
        if (biblioteca[i].tip) 
        {
            printf("ISBN: %s\n", biblioteca[i].info.isbn);
        } 
        else 
        {
            printf("An aparitie: %u\n", biblioteca[i].info.anAparitie);
        }
    }
}

void salvare() 
{
    FILE *f = fopen("inventar.bin", "wb");
    fwrite(biblioteca, sizeof(Publicatie), n, f);
    fclose(f);
}

int main() 
{
    int optiune;
    do 
    {
        printf("1. Introducere\n2. Afisare carti cu pret peste 100\n3. Afisare\n4. Salvare\n5. Iesire\n");
        scanf("%d", &optiune);
        switch (optiune) 
        {
            case 1:
                introducere();
                break;
            case 2:
                afisare_carti_pret();
                break;
            case 3:
                afisare();
                break;
            case 4:
                salvare();
                break;
        }
    } while (optiune != 5);
    
    free(biblioteca);
    
    return 0;
}