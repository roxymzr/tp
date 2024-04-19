#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//8.1

/*
typedef struct Cuvant {
    char text[16]; 
    int contor;
    struct Cuvant* pred; 
    struct Cuvant* urm; 
} Cuvant;

Cuvant* Cuvant_nou(const char* text) {
    Cuvant* c = (Cuvant*)malloc(sizeof(Cuvant));
    if (!c) {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    strcpy(c->text, text);
    c->contor = 1; 
    return c;
}

typedef struct {
    Cuvant* prim; 
    Cuvant* ultim; 
} Propozitie;

void Propozitie_init(Propozitie* p) 
{
    p->prim = p->ultim = NULL;
}

void Propozitie_adauga(Propozitie* p, const char* text) 
{
    Cuvant* c = p->prim;
    while (c)
    {
        if (strcmp(c->text, text) == 0) 
        { 
            c->contor++;
            return;
        }
        c = c->urm;
    }
 
    c = Cuvant_nou(text);
    c->pred = p->ultim;
    if (p->ultim) 
    {
        p->ultim->urm = c;
    } else 
    {
        p->prim = c;
    }
    p->ultim = c;
}

void Propozitie_afisare(Propozitie* p) 
{
    Cuvant* c = p->prim;
    while (c) 
    {
        printf("%s (%d) ", c->text, c->contor);
        c = c->urm;
    }
    printf(".\n");
}

int main() 
{
    Propozitie p;
    int op; 
    char text[16];
    Propozitie_init(&p); 
    do {
        printf("1 - propozitie noua\n");
        printf("2 - afisare\n");
        printf("3 - iesire\n");
        printf("optiune: "); scanf("%d", &op);
        switch (op) 
        {
            case 1:
                Propozitie_init(&p); 
                for (;;) 
                {
                    scanf("%s", text);
                    if (!strcmp(text, ".")) break; 
                    for (int i = 0; text[i]; i++) 
                    {
                        text[i] = tolower(text[i]);
                    }
                    Propozitie_adauga(&p, text);
                }
                break;
            case 2:
                Propozitie_afisare(&p);
                break;
            case 3:
                break;
            default:
                printf("optiune invalida\n");
        }
    } while (op != 3);
    
    return 0;
}*/


//8.2

/*
typedef struct Cuvant {
    char text[16]; 
    int contor; 
    struct Cuvant* pred; 
    struct Cuvant* urm; 
} Cuvant;

Cuvant* Cuvant_nou(const char* text) {
    Cuvant* c = (Cuvant*)malloc(sizeof(Cuvant));
    if (!c) {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    strcpy(c->text, text);
    c->contor = 1;
    return c;
}

typedef struct {
    Cuvant* prim;
    Cuvant* ultim;
} Propozitie;

void Propozitie_init(Propozitie* p) 
{
    p->prim = p->ultim = NULL;
}

void Propozitie_adauga(Propozitie* p, const char* text) 
{
    Cuvant* c = p->prim;
    while (c) 
    {
        if (strcmp(c->text, text) == 0) 
        {
            c->contor++;
            return;
        }
        c = c->urm;
    }
    c = Cuvant_nou(text);
    c->pred = p->ultim;
    if (p->ultim) 
    {
        p->ultim->urm = c;
    } else 
    {
        p->prim = c;
    }
    p->ultim = c;
}

void Propozitie_sterge(Propozitie* p, Cuvant* c) 
{
    if (c == NULL) 
    {
        printf("cuvantul nu se gaseste in propozitie\n");
        return;
    }
    if (c->pred) 
    {
        c->pred->urm = c->urm;
    } else 
    {
        p->prim = c->urm;
    }
    if (c->urm) 
    {
        c->urm->pred = c->pred;
    } else 
    {
        p->ultim = c->pred;
    }
    free(c);
}

Cuvant* Propozitie_cauta(Propozitie* p, const char* text) 
{
    Cuvant* c;
    for (c = p->prim; c != NULL; c = c->urm) 
    {
        if (strcmp(c->text, text) == 0) 
        {
            return c;
        }
    }
    return NULL;
}


void Propozitie_insereaza(Propozitie* p, const char* cuvant, const char* succesor) 
{
    Cuvant* c = p->prim;
    while (c) {
        if (strcmp(c->text, succesor) == 0) 
        {
            Cuvant* nou = Cuvant_nou(cuvant);
            nou->pred = c->pred;
            nou->urm = c;
            if (c->pred) 
            {
                c->pred->urm = nou;
            } else 
            {
                p->prim = nou;
            }
            c->pred = nou;
            return;
        }
        c = c->urm;
    }
    Propozitie_adauga(p, cuvant);
}

void Propozitie_afisare(Propozitie* p) 
{
    Cuvant* c = p->prim;
    while (c) 
    {
        printf("%s (%d) ", c->text, c->contor);
        c = c->urm;
    }
    printf(".\n");
}

int main() 
{
    Propozitie p;
    int op;
    char text[16], succesor[16];
    Propozitie_init(&p);
    do {
        printf("1 - propozitie noua\n");
        printf("2 - afisare\n");
        printf("3 - stergere cuvant\n");
        printf("4 - inserare cuvant\n");
        printf("5 - iesire\n");
        printf("optiune: "); scanf("%d", &op);
        switch (op) 
        {
            case 1:
                Propozitie_init(&p);
                for (;;) 
                {
                    scanf("%s", text);
                    if (!strcmp(text, ".")) break;
                    for (int i = 0; text[i]; i++) 
                    {
                        text[i] = tolower(text[i]);
                    }
                    Propozitie_adauga(&p, text);
                }
                break;
            case 2:
                Propozitie_afisare(&p);
                break;
            case 3:
                printf("cuvant de sters: "); scanf("%s", text);
                Propozitie_sterge(&p, Propozitie_cauta(&p, text));
                break;
            case 4:
                printf("cuvant de inserat: "); scanf("%s", text);
                printf("succesor: "); scanf("%s", succesor);
                for (int i = 0; text[i]; i++) 
                {
                    text[i] = tolower(text[i]);
                }
                for (int i = 0; succesor[i]; i++) 
                {
                    succesor[i] = tolower(succesor[i]);
                }
                Propozitie_insereaza(&p, text, succesor);
                break;
            case 5:
                break;
            default:
                printf("optiune invalida\n");
        }
    } while (op != 5);
    
    return 0;
}*/


//8.3

/*
typedef struct Linie {
    char text[1001]; 
    struct Linie* urm;
    struct Linie* pred;
} Linie;

typedef struct {
    Linie* prim;
    Linie* ultim;
} Lista;

void Lista_init(Lista* l) 
{
    l->prim = l->ultim = NULL;
}

void Lista_insereaza(Lista* l, const char* text) 
{
    Linie* noua = (Linie*)malloc(sizeof(Linie));
    if (!noua) 
    {
        printf("Eroare de alocare a memoriei\n");
        exit(EXIT_FAILURE);
    }
    strcpy(noua->text, text);
    
    Linie** p = &l->prim;
    while (*p && strcmp((*p)->text, text) < 0) 
    {
        p = &(*p)->urm;
    }
    
    noua->urm = *p;
    noua->pred = (*p) ? (*p)->pred : l->ultim;
    
    if (*p) 
    {
        (*p)->pred = noua;
    } else 
    {
        l->ultim = noua;
    }
    
    *p = noua;
}

void Lista_afisare(Lista* l)
{
    Linie* p = l->prim;
    while (p)
     {
        printf("%s\n", p->text);
        p = p->urm;
    }
}

void Lista_elibereaza(Lista* l) 
{
    Linie* p = l->prim;
    while (p) 
    {
        Linie* temp = p;
        p = p->urm;
        free(temp);
    }
    Lista_init(l);
}

int main(int argc, char* argv[]) 
{
    if (argc != 2) 
    {
        printf("Nu sunt destule argumente!");
        return 1;
    }

    Lista l;
    Lista_init(&l);
    
    FILE* f = fopen(argv[1], "r");
    if (!f) 
    {
        printf("Eroare la deschiderea fisierului\n");
        return 1;
    }

    char linie[1001];
    while (fgets(linie, sizeof(linie), f))
    {
        linie[strcspn(linie, "\n")] = '\0'; 
        Lista_insereaza(&l, linie);
    }

    fclose(f);
    
    Lista_afisare(&l);
    Lista_elibereaza(&l);

    return 0;
}*/


//8.4

/*
typedef struct Produs {
    char nume[50];
    float pret;
    struct Produs* urm;
    struct Produs* pred;
} Produs;

typedef struct {
    char nume[50];
    Produs* prim;
    Produs* ultim;
    struct Categorie* urm;
    struct Categorie* pred;
} Categorie;

typedef struct {
    Categorie* prim;
    Categorie* ultim;
} ListaCategorii;

void Produs_init(Produs* p, const char* nume, float pret)
{
    strcpy(p->nume, nume);
    p->pret = pret;
    p->urm = NULL;
    p->pred = NULL;
}

void Produs_adauga(Produs** prim, Produs** ultim, const char* nume, float pret) 
{
    Produs* nou = (Produs*)malloc(sizeof(Produs));
    if (!nou) 
    {
        printf("Eroare de alocare a memoriei\n");
        exit(EXIT_FAILURE);
    }
    Produs_init(nou, nume, pret);
    
    if (*ultim) 
    {
        nou->pred = *ultim;
        (*ultim)->urm = nou;
    } else 
    {
        *prim = nou;
    }
    *ultim = nou;
}

void Produs_afisare(Produs* prim) 
{
    while (prim) 
    {
        printf("%s - %.2f\n", prim->nume, prim->pret);
        prim = prim->urm;
    }
}

void Categorie_init(Categorie* c, const char* nume) 
{
    strcpy(c->nume, nume);
    c->prim = NULL;
    c->ultim = NULL;
    c->urm = NULL;
    c->pred = NULL;
}

void Categorie_adaugaProdus(Categorie* c, const char* nume, float pret) 
{
    Produs_adauga(&c->prim, &c->ultim, nume, pret);
}

void Categorie_afisareNume(Categorie* c) 
{
    printf("%s\n", c->nume);
}

void Categorie_afisareProduse(Categorie* c) 
{
    printf("Produse pentru categoria %s:\n", c->nume);
    Produs_afisare(c->prim);
}

void ListaCategorii_init(ListaCategorii* lc) 
{
    lc->prim = NULL;
    lc->ultim = NULL;
}

void ListaCategorii_adauga(ListaCategorii* lc, const char* nume) 
{
    Categorie* nou = (Categorie*)malloc(sizeof(Categorie));
    if (!nou) 
    {
        printf("Eroare de alocare a memoriei\n");
        exit(EXIT_FAILURE);
    }
    Categorie_init(nou, nume);
    
    if (lc->ultim) 
    {
        nou->pred = lc->ultim;
        lc->ultim->urm = nou;
    } else 
    {
        lc->prim = nou;
    }
    lc->ultim = nou;
}

Categorie* ListaCategorii_cauta(ListaCategorii* lc, const char* nume)
 {
    Categorie* c = lc->prim;
    while (c)
     {
        if (strcmp(c->nume, nume) == 0) 
        {
            return c;
        }
        c = c->urm;
    }
    return NULL;
}

int main() 
{
    ListaCategorii lc;
    ListaCategorii_init(&lc);
    
    int optiune;
    char nume[50];
    char numeProdus[50];
    float pret;
    
    do {
        printf("\nMeniu:\n");
        printf("1 - Adaugă categorie\n");
        printf("2 - Adaugă produs\n");
        printf("3 - Afișare categorii\n");
        printf("4 - Afișare produse\n");
        printf("5 - Ieșire\n");
        printf("Alegeți o opțiune: ");
        scanf("%d", &optiune);
        
        switch (optiune) 
        {
            case 1:
                printf("Introduceți numele categoriei: ");
                scanf("%s", nume);
                ListaCategorii_adauga(&lc, nume);
                break;
            case 2:
                printf("Introduceți numele categoriei: ");
                scanf("%s", nume);
                Categorie* c = ListaCategorii_cauta(&lc, nume);
                if (c) 
                {
                    printf("Introduceți numele produsului și prețul: ");
                    scanf("%s %f", numeProdus, &pret);
                    Categorie_adaugaProdus(c, numeProdus, pret);
                } else 
                {
                    printf("Categoria nu există.\n");
                }
                break;
            case 3:
                printf("Categoriile disponibile sunt:\n");
                Categorie* cat = lc.prim;
                while (cat) 
                {
                    Categorie_afisareNume(cat);
                    cat = cat->urm;
                }
                break;
            case 4:
                printf("Introduceți numele categoriei pentru care doriți afișarea produselor: ");
                scanf("%s", nume);
                Categorie* catProd = ListaCategorii_cauta(&lc, nume);
                if (catProd) 
                {
                    Categorie_afisareProduse(catProd);
                } else 
                {
                    printf("Categoria nu există.\n");
                }
                break;
            case 5:
                printf("Ieșire.\n");
                break;
            default:
                printf("Opțiune invalidă.\n");
        }
    } while (optiune != 5);
    
    Categorie* c = lc.prim;
    while (c) 
    {
        Produs* p = c->prim;
        while (p) 
        {
            Produs* temp = p;
            p = p->urm;
            free(temp);
        }
        Categorie* tempC = c;
        c = c->urm;
        free(tempC);
    }

    return 0;
}*/



//8.5

typedef struct Automobil {
    unsigned int cod : 13;        
    unsigned int locuri : 4;      
    unsigned int putere : 9;      
    unsigned int an : 8;          
    char marca[20];
    char culoare[20];
    struct Automobil* urm;
    struct Automobil* pred;
} Automobil;

typedef struct {
    Automobil* prim;
    Automobil* ultim;
} ParcAuto;


void Automobil_init(Automobil* a, int cod, int locuri, int putere, int an, const char* marca, const char* culoare) 
{
    a->cod = cod;
    a->locuri = locuri;
    a->putere = putere;
    a->an = an;
    strcpy(a->marca, marca);
    strcpy(a->culoare, culoare);
    a->urm = NULL;
    a->pred = NULL;
}

void ParcAuto_init(ParcAuto* pa) 
{
    pa->prim = NULL;
    pa->ultim = NULL;
}

void ParcAuto_adauga(Automobil** prim, Automobil** ultim, Automobil* nou) 
{
    if (*ultim) 
    {
        nou->pred = *ultim;
        (*ultim)->urm = nou;
    } else 
    {
        *prim = nou;
    }
    *ultim = nou;
}

void ParcAuto_introducere(ParcAuto* pa) 
{
    int cod, locuri, putere, an;
    char marca[20], culoare[20];

    printf("Introduceți codul, numărul de locuri, puterea, anul, marca și culoarea mașinii: ");
    scanf("%d %d %d %d %s %s", &cod, &locuri, &putere, &an, marca, culoare);

    Automobil* nou = (Automobil*)malloc(sizeof(Automobil));
    Automobil_init(nou, cod, locuri, putere, an, marca, culoare);

    ParcAuto_adauga(&pa->prim, &pa->ultim, nou);
}

void ParcAuto_stergere(ParcAuto* pa, int cod) 
{
    Automobil* current = pa->prim;

    while (current) 
    {
        if (current->cod == cod) 
        {
            if (current->pred) 
            {
                current->pred->urm = current->urm;
            } else 
            {
                pa->prim = current->urm;
            }

            if (current->urm) 
            {
                current->urm->pred = current->pred;
            } else 
            {
                pa->ultim = current->pred;
            }

            free(current);
            return;
        }
        current = current->urm;
    }

    printf("Automobilul cu codul %d nu a fost găsit.\n", cod);
}

void ParcAuto_afisare(ParcAuto* pa) 
{
    Automobil* current = pa->prim;

    while (current) 
    {
        printf("Cod: %d, Locuri: %d, Putere: %d CP, An: %d, Marca: %s, Culoare: %s\n",
               current->cod, current->locuri, current->putere, current->an, current->marca, current->culoare);
        current = current->urm;
    }
}

void ParcAuto_afisareLocuri(ParcAuto* pa, int locuri) 
{
    Automobil* current = pa->prim;

    while (current) 
    {
        if (current->locuri == locuri) 
        {
            printf("Cod: %d, Locuri: %d, Putere: %d CP, An: %d, Marca: %s, Culoare: %s\n",
                   current->cod, current->locuri, current->putere, current->an, current->marca, current->culoare);
        }
        current = current->urm;
    }
}

void ParcAuto_ordonareAn(ParcAuto* pa) 
{
    Automobil* i, * j;
    for (i = pa->prim; i != NULL; i = i->urm) 
    {
        for (j = i->urm; j != NULL; j = j->urm) 
        {
            if (i->an > j->an) 
            {
                int temp_cod = i->cod;
                int temp_locuri = i->locuri;
                int temp_putere = i->putere;
                int temp_an = i->an;
                char temp_marca[20], temp_culoare[20];
                strcpy(temp_marca, i->marca);
                strcpy(temp_culoare, i->culoare);
                i->cod = j->cod;
                i->locuri = j->locuri;
                i->putere = j->putere;
                i->an = j->an;
                strcpy(i->marca, j->marca);
                strcpy(i->culoare, j->culoare);
                j->cod = temp_cod;
                j->locuri = temp_locuri;
                j->putere = temp_putere;
                j->an = temp_an;
                strcpy(j->marca, temp_marca);
                strcpy(j->culoare, temp_culoare);
            }
        }
    }
}

int main() 
{
    ParcAuto pa;
    ParcAuto_init(&pa);

    int optiune;
    int cod;
    int locuri;

    do {
        printf("\nMeniu:\n");
        printf("1. Adăugă automobil\n");
        printf("2. Șterge automobil\n");
        printf("3. Afișează toate automobilele\n");
        printf("4. Afișează automobilele cu un anumit număr de locuri\n");
        printf("5. Ordonează automobilele după anul fabricației\n");
        printf("6. Ieșire\n");
        printf("Alegeți o opțiune: ");
        scanf("%d", &optiune);

        switch (optiune) 
        {
            case 1:
                ParcAuto_introducere(&pa);
                break;
            case 2:
                printf("Introduceți codul automobilului pe care doriți să îl ștergeți: ");
                scanf("%d", &cod);
                ParcAuto_stergere(&pa, cod);
                break;
            case 3:
                ParcAuto_afisare(&pa);
                break;
            case 4:
                printf("Introduceți numărul de locuri: ");
                scanf("%d", &locuri);
                ParcAuto_afisareLocuri(&pa, locuri);
                break;
            case 5:
                ParcAuto_ordonareAn(&pa);
                printf("Automobilele au fost ordonate după anul fabricației.\n");
                break;
            case 6:
                printf("Programul se încheie.\n");
                break;
            default:
                printf("Opțiune invalidă.\n");
        }
    } while (optiune != 6);

    Automobil* current = pa.prim;
    while (current) 
    {
        Automobil* temp = current;
        current = current->urm;
        free(temp);
    }

    return 0;
}









