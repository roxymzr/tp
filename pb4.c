#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//4.0

/*
struct Student 
{
    char nume[21];
    int nota;
};

int main() 
{
    struct Student student;

    // Citirea datelor studentului
    printf("nume: ");
    fgets(student.nume, sizeof(student.nume), stdin);
    student.nume[strcspn(student.nume, "\n")] = 0; 

    printf("nota: ");
    scanf("%d", &student.nota);

    printf("Numele studentului este: %s\n", student.nume);
    printf("Nota studentului este: %d\n", student.nota);

    return 0;
}
*/

//4.1

/*
typedef struct 
{
    char nume[16];
    unsigned int dimensiune : 10; 
    unsigned int tip : 2; 
    unsigned int tipFisier : 1; 
}fisier;

int main() 
{
    unsigned int aux1=0 , aux2=0, aux3=0;
    fisier v;
    
    printf("nume: ");
    fgets(v.nume, sizeof(v.nume), stdin);
    v.nume[strcspn(v.nume, "\n")] = 0;  

    printf("dimensiune: ");
    scanf("%u",&aux1);
    v.dimensiune=aux1;

    printf("tip: ");
    scanf("%u",&aux2);
    v.tip=aux2;

    printf("tip fisier: ");
    scanf("%u",&aux3);
    v.tipFisier=aux3;

    printf("Numele fisierului este: %s\n", v.nume);
    printf("Dimensiunea fisierului este: %u octeți\n", v.dimensiune);
    printf("Tipul fisierului este: %u\n", v.tip);
    printf("Tipul fisierului este: %u\n", v.tipFisier);

    return 0;
}
*/

//4.2

/*
typedef struct
{
    char nume[16];
    unsigned int dimensiune : 10; 
    unsigned int tip : 2; 
    unsigned int tipFisier : 1; 
}fisier;

int main() 
{
    fisier v[10];
    unsigned int aux1=0, aux2=0, aux3=0; 
    int i, n;

    printf("numar fisiere: ");
    scanf("%d", &n);
    getchar(); 

    
    for(i = 0; i < n; i++)
    {
        printf("nume %d: ", i+1);
        fgets(v[i].nume, sizeof(v[i].nume), stdin);
        v[i].nume[strcspn(v[i].nume, "\n")] = 0;  

        printf("dimensiune %d: ", i+1);
        scanf("%u", &aux1);
        v[i].dimensiune=aux1;

        printf("tip %d: ", i+1);
        scanf("%u", &aux2);
        v[i].tip=aux2;

        printf("tip %d:", i+1);
        scanf("%u", &aux3);
        v[i].tipFisier=aux3;

        getchar();
    }

    FILE *f = fopen("memorie.txt", "w");
    if(f == NULL) 
    {
        printf("Eroare\n");
        exit(-1);
    }

    for(i = 0; i < n; i++) 
    {
        fprintf(f, "Numele fisierului %d este: %s\n", i+1, v[i].nume);
        fprintf(f, "Dimensiunea fisierului %d este: %u octeți\n", i+1, v[i].dimensiune);
        fprintf(f, "Tipul fisierului %d este: %u\n", i+1, v[i].tip);
        fprintf(f, "Tipul fisierului %d este: %u\n\n", i+1, v[i].tipFisier);
    }

    fclose(f);
    printf("Datele au fost salvate cu succes în fisierul memorie.txt.\n");

    return 0;
}
*/

//4.3

/*
typedef struct  
{
    char nume[16];
    unsigned int dimensiune : 10; 
    unsigned int tip : 2; 
    unsigned int tipFisier : 1; 
}fisier;

int main() 
{
    fisier *v;
    unsigned int aux1=0, aux2=0, aux3=0; 
    int i, n;

    printf("Introduceti numarul de fisiere: ");
    scanf("%d", &n);
    getchar();

    v = malloc(n * sizeof(fisier));
    if(v == NULL)
    {
        printf("Eroare la alocarea memoriei.\n");
        exit(-1);
    }

    for(i = 0; i < n; i++) 
    {
        printf("nume %d: ", i+1);
        fgets(v[i].nume, sizeof(v[i].nume), stdin);
        v[i].nume[strcspn(v[i].nume, "\n")] = 0;  

        printf("dimensiune %d: ", i+1);
        scanf("%u", &aux1);
        v[i].dimensiune=aux1;

        printf("tip %d: ", i+1);
        scanf("%u", &aux2);
        v[i].tip=aux2;

        printf("tip %d: ", i+1);
        scanf("%u", &aux3);
        v[i].tipFisier=aux3;

        getchar(); 
    }

    FILE *f = fopen("memorie.txt", "w");
    if(f == NULL) 
    {
        printf("Eroare");
        exit(-1);
    }

    for(i = 0; i < n; i++) 
    {
        fprintf(f, "Numele fisierului %d este: %s\n", i+1, v[i].nume);
        fprintf(f, "Dimensiunea fisierului %d este: %u octeți\n", i+1, v[i].dimensiune);
        fprintf(f, "Tipul fisierului %d este: %u\n", i+1, v[i].tip);
        fprintf(f, "Tipul fisierului %d este: %u\n\n", i+1, v[i].tipFisier);
    }

    fclose(f);
    printf("Datele au fost salvate cu succes în fisierul memorie.txt.\n");

    free(v);

    return 0;
}
*/

//4.4

/*
typedef struct  
{
    unsigned int numar_picioare : 10; 
    float greutate;
    unsigned int periculos : 1; 
    char abreviere[8];
    unsigned int varsta_maxima : 11; 
}animal;

int main() 
{
    animal x;
    unsigned int aux1=0, aux3=0, aux5=0; 
    float  aux2=0;

    printf("Introduceti numarul de picioare: ");
    scanf("%u", &aux1);
    x.numar_picioare=aux1;

    printf("Introduceti greutatea: ");
    scanf("%f", &aux2);
    x.greutate=aux2;

    printf("Este periculos pentru om (1=da, 0=nu): ");
    scanf("%u", &aux3);
    x.periculos=aux3;

    printf("Introduceti abrevierea stiintifica a speciei: ");
    scanf("%s", x.abreviere);

    printf("Introduceti varsta maxima: ");
    scanf("%u", &aux5);
    x.varsta_maxima=aux5;

    printf("\nInformatii despre animal:\n");
    printf("Numar de picioare: %u\n", x.numar_picioare);
    printf("Greutate: %.2f kg\n", x.greutate);
    printf("Periculos pentru om: %s\n", x.periculos ? "da" : "nu");
    printf("Abreviere stiintifica: %s\n", x.abreviere);
    printf("Varsta maxima: %u ani\n",x.varsta_maxima);

    printf("\nMarimea structurii 'Animal' este: %lu bytes\n", sizeof(animal));

    return 0;
}
*/ 


//4.5

/*
typedef struct 
{
    unsigned int periculozitate : 2; 
    unsigned int reteta : 1; 
    unsigned int varsta_minima : 5; 
} Medicament;

int main() 
{
    Medicament m;
    unsigned int aux1=0, aux2=0, aux3=0; 

    printf("Introduceti gradul de periculozitate (0=scăzută, 1=medie, 2=mare): ");
    scanf("%u", &aux1);
    m.periculozitate=aux1;

    printf("Se eliberează doar pe bază de rețetă? (0=nu, 1=da): ");
    scanf("%u", &aux2);
    m.reteta=aux2;

    printf("Introduceti vârsta minimă de administrare (1-18): ");
    scanf("%u", &aux3);
    m.varsta_minima=aux3;

    printf("\nInformatii despre medicament:\n");
    printf("Gradul de periculozitate: %s\n", m.periculozitate == 0 ? "scăzută" : m.periculozitate == 1 ? "medie" : "mare");
    printf("Se eliberează doar pe bază de rețetă: %s\n", m.reteta ? "da" : "nu");
    printf("Vârsta minimă de administrare: %u ani\n", m.varsta_minima);

    return 0;
}
*/



//4.6

/*
typedef struct 
{
    unsigned int valoare : 12; 
    unsigned int unitate : 2;  
    unsigned int multiplicator : 2; 
} Masuratoare;

int main() 
{
    Masuratoare m;
    unsigned int valoare;
    char unitate[10];

    printf("Introduceti valoarea: ");
    scanf("%u", &valoare);

    printf("Introduceti unitatea de masura (gram, metru, litru): ");
    scanf("%s", unitate);

    if (valoare > 4095) 
    {
        printf("Eroare: Valoarea nu incape in structura Masuratoare.\n");
        return 1;
    }

    m.valoare = valoare;

    if (strcmp(unitate, "gram") == 0) 
    {
        m.unitate = 0;
    } else if (strcmp(unitate, "metru") == 0) 
    {
        m.unitate = 1;
    } else if (strcmp(unitate, "litru") == 0) 
    {
        m.unitate = 2;
    } else 
    {
        printf("Eroare: Unitatea de masura necunoscuta.\n");
        return 1;
    }

    while (m.valoare >= 10 && m.multiplicator < 3) 
    {
        m.valoare /= 10;
        m.multiplicator++;
    }

    printf("\nInformatii despre masuratoare:\n");
    printf("Valoare: %u\n", m.valoare);
    printf("Unitate de masura: %s\n", m.unitate == 0 ? "gram" : m.unitate == 1 ? "metru" : "litru");
    printf("Multiplicator: %s\n", m.multiplicator == 0 ? "pico" : m.multiplicator == 1 ? "nano" : m.multiplicator == 2 ? "mili" : "centi");

    return 0;
}
*/



