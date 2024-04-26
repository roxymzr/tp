//9.1
/*
typedef struct Nod {
    int val;
    struct Nod* urm;
} Nod;

void adaugaSfarsit(Nod** cap, int val) 
{
    Nod* nou = (Nod*)malloc(sizeof(Nod));
    nou->val = val;
    nou->urm = NULL;

    if (*cap == NULL) 
    {
        *cap = nou;
        return;
    }

    Nod* temp = *cap;
    while (temp->urm != NULL) 
    {
        temp = temp->urm;
    }

    temp->urm = nou;
}

void stergePrimul(Nod** cap) 
{
    if (*cap == NULL) 
    {
        return;
    }

    Nod* temp = *cap;
    *cap = (*cap)->urm;
    free(temp);
}

void permuta(Nod** cap, int q) 
{
    if (*cap == NULL)
    {
        return;
    }

    while (q > 0) 
    {
        adaugaSfarsit(cap, (*cap)->val);
        stergePrimul(cap);
        q--;
    }
}


void afiseazaLista(Nod* cap) 
{
    while (cap != NULL) 
    {
        printf("%d ", cap->val);
        cap = cap->urm;
    }
    printf("\n");
}

int main() 
{
    FILE* f = fopen("date.in", "r");
    if (f == NULL) 
    {
        perror("Eroare");
        return 1;
    }

    int q;
    fscanf(f, "%d", &q);

    Nod* cap = NULL;
    int val;
    while (fscanf(f, "%d", &val) == 1) 
    {
        adaugaSfarsit(&cap, val);
    }

    fclose(f);

    permuta(&cap, q);
    afiseazaLista(cap);

    while (cap != NULL) 
    {
        stergePrimul(&cap);
    }

    return 0;
}
*/

//9.2

/*
typedef struct Nod {
    int val;
    struct Nod* urm;
} Nod;

void adaugaSfarsit(Nod** cap, int val) 
{
    Nod* nou = (Nod*)malloc(sizeof(Nod));
    nou->val = val;
    nou->urm = NULL;

    if (*cap == NULL) 
    {
        *cap = nou;
        return;
    }

    Nod* temp = *cap;
    while (temp->urm != NULL) 
    {
        temp = temp->urm;
    }

    temp->urm = nou;
}

void afiseazaLista(Nod* cap) 
{
    while (cap != NULL) {
        printf("%d ", cap->val);
        cap = cap->urm;
    }
    printf("\n");
}

int main() 
{
    FILE* f = fopen("numere.txt", "r");
    if (f == NULL) 
    {
        perror("Eroare");
        return 1;
    }

    Nod* listaPare = NULL;
    Nod* listaImpare = NULL;
    int val;

    while (fscanf(f, "%d", &val) == 1) 
    {
        if (val % 2 == 0) 
        {
            adaugaSfarsit(&listaPare, val);
        } 
        else
        {
            adaugaSfarsit(&listaImpare, val);
        }
    }

    fclose(f);

    if (listaPare == NULL) 
    {
        listaPare = listaImpare;
    } 
    else 
    {
        Nod* temp = listaPare;
        while (temp->urm != NULL) 
        {
            temp = temp->urm;
        }
        temp->urm = listaImpare;
    }

    printf("Lista cu numere pare: ");
    afiseazaLista(listaPare);

    while (listaPare != NULL) 
    {
        Nod* temp = listaPare;
        listaPare = listaPare->urm;
        free(temp);
    }

    return 0;
}
*/


//9.3

/*
typedef struct Nod {
    int val;
    struct Nod* urm;
} Nod;

void adaugaDupaPar(Nod* nod) 
{
    if (nod == NULL) {

        return;
    }

    if (nod->val % 2 == 0) 
    {
        Nod* nou = (Nod*)malloc(sizeof(Nod));
        if (nou == NULL) 
        {
            perror("Eroare");
            exit(EXIT_FAILURE);
        }
        nou->val = nod->val / 2;
        nou->urm = nod->urm;
        nod->urm = nou;
        adaugaDupaPar(nod->urm);
    } 
    else 
    {
        adaugaDupaPar(nod->urm);
    }
}

void afiseazaLista(Nod* cap) 
{
    while (cap != NULL) 
    {
        printf("%d ", cap->val);
        cap = cap->urm;
    }
    printf("\n");
}

void elibereazaLista(Nod* cap) 
{
    while (cap != NULL) 
    {
        Nod* temp = cap;
        cap = cap->urm;
        free(temp);
    }
}

int main() 
{
    Nod* cap = NULL;
    for (int i = 10; i >= 1; i--) 
    {
        Nod* nou = (Nod*)malloc(sizeof(Nod));
        if (nou == NULL) 
        {
            perror("Eroare la alocare memorie");
            exit(EXIT_FAILURE);
        }
        nou->val = i;
        nou->urm = cap;
        cap = nou;
    }

    printf("Lista initiala: ");
    afiseazaLista(cap);
    adaugaDupaPar(cap);
    printf("Lista modificata: ");
    afiseazaLista(cap);
    elibereazaLista(cap);
    return 0;
}
*/

//9.4

/*
typedef struct Nod {
    int val;
    struct Nod* urm;
    struct Nod* pred;
} Nod;

void interschimbaPerechi(Nod* cap) 
{
    if (cap == NULL || cap->urm == NULL) 
    {
        return; 
    }
    Nod* prim = cap;
    Nod* alDoilea = prim->urm;
    while (prim && alDoilea) 
    {
        int temp = prim->val;
        prim->val = alDoilea->val;
        alDoilea->val = temp;
        if (alDoilea->urm && alDoilea->urm->urm) 
        {
            prim = alDoilea->urm;
            alDoilea = prim->urm;
        } 
        else 
        {
            break; 
        }
    }
}

void afiseazaLista(Nod* cap) 
{
    while (cap != NULL) 
    {
        printf("%d ", cap->val);
        cap = cap->urm;
    }
    printf("\n");
}

void elibereazaLista(Nod* cap) 
{
    while (cap != NULL) 
    {
        Nod* temp = cap;
        cap = cap->urm;
        free(temp);
    }
}

int main() 
{
    Nod* cap = NULL;
    Nod* ultim = NULL;
    for (int i = 1; i <= 10; i++) 
    {
        Nod* nou = (Nod*)malloc(sizeof(Nod));
        if (nou == NULL) 
        {
            perror("Eroare la alocare memorie");
            exit(EXIT_FAILURE);
        }
        nou->val = i;
        nou->urm = NULL;
        nou->pred = ultim;
        if (ultim == NULL) 
        {
            cap = nou;
        } 
        else 
        {
            ultim->urm = nou;
        }
        ultim = nou;
    }
    printf("Lista initiala: ");
    afiseazaLista(cap);
    interschimbaPerechi(cap);
    printf("Lista modificata: ");
    afiseazaLista(cap);
    elibereazaLista(cap);
    return 0;
}
*/

//9.5

/*
typedef struct Nod {
    int val;
    struct Nod* urm;
    struct Nod* pred;
} Nod;

void stergePrimUltim(Nod** cap) 
{
    if (*cap == NULL || (*cap)->urm == NULL) 
    {
        return;
    }

    Nod* prim = *cap;
    Nod* ultim = prim;

    while (ultim->urm != NULL) 
    {
        ultim = ultim->urm;
    }

    *cap = prim->urm;

  
    if (prim->urm) 
    {
        prim->urm->pred = NULL;
    }
    free(prim);

    if (ultim->pred) 
    {
        ultim->pred->urm = NULL;
    }
    free(ultim);
}


void afiseazaLista(Nod* cap) 
{
    while (cap != NULL) 
    {
        printf("%d ", cap->val);
        cap = cap->urm;
    }
    printf("\n");
}

void elibereazaLista(Nod* cap) 
{
    while (cap != NULL) 
    {
        Nod* temp = cap;
        cap = cap->urm;
        free(temp);
    }
}

int main() 
{
    Nod* cap = NULL;
    Nod* ultim = NULL;

    for (int i = 1; i <= 5; i++) 
    {
        Nod* nou = (Nod*)malloc(sizeof(Nod));
        if (nou == NULL) 
        {
            perror("Eroare");
            exit(EXIT_FAILURE);
        }
        nou->val = i;
        nou->urm = NULL;
        nou->pred = ultim;

        if (ultim == NULL) 
        {
            cap = nou;
        } 
        else 
        {
            ultim->urm = nou;
        }
        ultim = nou;
    }

    printf("Lista initiala: ");
    afiseazaLista(cap);

    stergePrimUltim(&cap);

    printf("Lista modificata: ");
    afiseazaLista(cap);

    elibereazaLista(cap);

    return 0;
}*/

//9.6
/*
typedef struct Nod {
    int val;
    struct Nod* urm;
    struct Nod* pred;
} Nod;

void mutaUltimInFata(Nod** cap) 
{
    if (*cap == NULL || (*cap)->urm == NULL) 
    {
        return;
    }

    Nod* ultim = *cap;
    while (ultim->urm != NULL) 
    {
        ultim = ultim->urm;
    }

    ultim->urm = *cap;
    (*cap)->pred = ultim;
  
    *cap = ultim->urm;
    (*cap)->pred = NULL;

    ultim->urm = NULL;
}


void afiseazaLista(Nod* cap) 
{
    while (cap != NULL) 
    {
        printf("%d ", cap->val);
        cap = cap->urm;
    }
    printf("\n");
}


void elibereazaLista(Nod* cap) 
{
    while (cap != NULL) 
    {
        Nod* temp = cap;
        cap = cap->urm;
        free(temp);
    }
}

int main() 
{
    Nod* cap = NULL;
    Nod* ultim = NULL;

    for (int i = 1; i <= 5; i++) 
    {
        Nod* nou = (Nod*)malloc(sizeof(Nod));
        if (nou == NULL) 
        {
            perror("Eroare ");
            exit(EXIT_FAILURE);
        }
        nou->val = i;
        nou->urm = NULL;
        nou->pred = ultim;

        if (ultim == NULL) 
        {
            cap = nou;
        } 
        else 
        {
            ultim->urm = nou;
        }
        ultim = nou;
    }

    printf("Lista initiala: ");
    afiseazaLista(cap);

    mutaUltimInFata(&cap);

    printf("Lista modificata: ");
    afiseazaLista(cap);
    elibereazaLista(cap);

    return 0;
}
*/

//9.7

/*
typedef struct Nod {
    int cifra;
    struct Nod* urm;
    struct Nod* pred;
} Nod;


void adaugaNodSfarsit(Nod** cap, int cifra) 
{
    Nod* nou = (Nod*)malloc(sizeof(Nod));
    if (nou == NULL) 
    {
        perror("Eroare la alocare memorie");
        exit(EXIT_FAILURE);
    }
    nou->cifra = cifra;
    nou->urm = NULL;
    nou->pred = NULL;

    if (*cap == NULL) 
    {
        *cap = nou;
    } 
    else 
    {
        Nod* temp = *cap;
        while (temp->urm != NULL) 
        {
            temp = temp->urm;
        }
        temp->urm = nou;
        nou->pred = temp;
    }
}


int estePalindrom(Nod* cap) 
{
    Nod* stanga = cap;
    Nod* dreapta = cap;
    while (dreapta->urm != NULL) 
    {
        dreapta = dreapta->urm;
    }

    while (stanga != dreapta && dreapta->urm != stanga) 
    {
        if (stanga->cifra != dreapta->cifra) 
        {
            return 0; 
        }
        stanga = stanga->urm;
        dreapta = dreapta->pred;
    }

    return 1; 
}


void afiseazaLista(Nod* cap) 
{
    while (cap != NULL) 
    {
        printf("%d ", cap->cifra);
        cap = cap->urm;
    }
    printf("\n");
}

void elibereazaLista(Nod* cap) 
{
    while (cap != NULL) 
    {
        Nod* temp = cap;
        cap = cap->urm;
        free(temp);
    }
}

int main() 
{
    Nod* cap = NULL;
    int cifra;
    printf("Introduceti cifrele pentru lista (0 pentru a opri): ");
    while (1) 
    {
        scanf("%d", &cifra);
        if (cifra == 0) 
        {
            break;
        }
        adaugaNodSfarsit(&cap, cifra);
    }

    printf("Lista introdusa: ");
    afiseazaLista(cap);

    if (estePalindrom(cap)) 
    {
        printf("Numarul format din cifrele listei este palindrom.\n");
    } 
    else 
    {
        printf("Numarul format din cifrele listei nu este palindrom.\n");
    }

    elibereazaLista(cap);

    return 0;
}
*/

//9.8

/*
typedef struct Nod {
    int valoare;
    struct Nod* urm;
} Nod;


void adaugaNodSfarsit(Nod** cap, int valoare) 
{
    Nod* nou = (Nod*)malloc(sizeof(Nod));
    if (nou == NULL) 
    {
        perror("Eroare la alocare memorie");
        exit(EXIT_FAILURE);
    }
    nou->valoare = valoare;
    nou->urm = NULL;

    if (*cap == NULL) 
    {
        *cap = nou;
    } 
    else 
    {
        Nod* temp = *cap;
        while (temp->urm != NULL) 
        {
            temp = temp->urm;
        }
        temp->urm = nou;
    }
}

void mutaPrimulDupaUltimul(Nod** cap) 
{
    if (*cap == NULL || (*cap)->urm == NULL || (*cap)->urm->urm == NULL) {
        printf("Lista nu are suficiente noduri pentru a efectua mutarea.\n");
        return;
    }

    Nod* temp = *cap;
    *cap = (*cap)->urm;

    Nod* ultim = *cap;
    while (ultim->urm != NULL) 
    {
        ultim = ultim->urm;
    }

    ultim->urm = temp;
    temp->urm = NULL;
}

void afiseazaLista(Nod* cap) {

    while (cap != NULL) 
    {
        printf("%d ", cap->valoare);
        cap = cap->urm;
    }
    printf("\n");
}

void elibereazaLista(Nod* cap) 
{
    while (cap != NULL) 
    {
        Nod* temp = cap;
        cap = cap->urm;
        free(temp);
    }
}

int main() 
{
    Nod* cap = NULL;

    adaugaNodSfarsit(&cap, 1);
    adaugaNodSfarsit(&cap, 2);
    adaugaNodSfarsit(&cap, 3);
    adaugaNodSfarsit(&cap, 4);

    printf("Lista initiala: ");
    afiseazaLista(cap);

    mutaPrimulDupaUltimul(&cap);

    printf("Lista dupa mutare: ");
    afiseazaLista(cap);

    elibereazaLista(cap);

    return 0;
}*/

//9.9

/*
typedef struct Nod {
    int valoare;
    struct Nod* urm;
} Nod;

void adaugaNodSfarsit(Nod** cap, int valoare) 
{
    Nod* nou = (Nod*)malloc(sizeof(Nod));
    if (nou == NULL) 
    {
        perror("Eroare la alocare memorie");
        exit(EXIT_FAILURE);
    }
    nou->valoare = valoare;
    nou->urm = NULL;

    if (*cap == NULL) 
    {
        *cap = nou;
    } 
    else 
    {
        Nod* temp = *cap;
        while (temp->urm != NULL) 
        {
            temp = temp->urm;
        }
        temp->urm = nou;
    }
}

void stergePare(Nod** cap) 
{
    while (*cap != NULL && (*cap)->valoare % 2 == 0) 
    {
        Nod* temp = *cap;
        *cap = (*cap)->urm;
        free(temp);
    }

    Nod* current = *cap;
    while (current != NULL && current->urm != NULL) 
    {
        if (current->urm->valoare % 2 == 0) 
        {
            Nod* temp = current->urm;
            current->urm = temp->urm;
            free(temp);
        } 
        else 
        {
            current = current->urm;
        }
    }
}

void afiseazaLista(Nod* cap) 
{
    while (cap != NULL) 
    {
        printf("%d ", cap->valoare);
        cap = cap->urm;
    }
    printf("\n");
}

void elibereazaLista(Nod* cap) 
{
    while (cap != NULL) 
    {
        Nod* temp = cap;
        cap = cap->urm;
        free(temp);
    }
}

int main() 
{
    Nod* cap = NULL;

    adaugaNodSfarsit(&cap, 1);
    adaugaNodSfarsit(&cap, 2);
    adaugaNodSfarsit(&cap, 3);
    adaugaNodSfarsit(&cap, 4);
    adaugaNodSfarsit(&cap, 5);

    printf("Lista initiala: ");
    afiseazaLista(cap);

    stergePare(&cap);

    printf("Lista dupa stergere elemente pare: ");
    afiseazaLista(cap);

    elibereazaLista(cap);

    return 0;
}*/

//9.10

/*
typedef struct Nod {
    int valoare;
    struct Nod* urm;
} Nod;

void adaugaNodSfarsit(Nod** cap, int valoare) 
{
    Nod* nou = (Nod*)malloc(sizeof(Nod));
    if (nou == NULL) 
    {
        perror("Eroare la alocare memorie");
        exit(EXIT_FAILURE);
    }
    nou->valoare = valoare;
    nou->urm = NULL;

    if (*cap == NULL) 
    {
        *cap = nou;
    } 
    else 
    {
        Nod* temp = *cap;
        while (temp->urm != NULL) 
        {
            temp = temp->urm;
        }
        temp->urm = nou;
    }
}

void separaPareImpare(Nod* cap, Nod** capPare, Nod** capImpare) 
{
    while (cap != NULL) 
    {
        if (cap->valoare % 2 == 0) 
        {
            adaugaNodSfarsit(capPare, cap->valoare);
        } 
        else 
        {
            adaugaNodSfarsit(capImpare, cap->valoare);
        }
        cap = cap->urm;
    }
}

void afiseazaLista(Nod* cap) 
{
    while (cap != NULL) 
    { 
        printf("%d ", cap->valoare);
        cap = cap->urm;
    }
    printf("\n");
}


void elibereazaLista(Nod* cap) 
{
    while (cap != NULL) 
    {
        Nod* temp = cap;
        cap = cap->urm;
        free(temp);
    }
}

int main() 
{
    Nod* cap = NULL;
    Nod* capPare = NULL;
    Nod* capImpare = NULL;
    adaugaNodSfarsit(&cap, 1);
    adaugaNodSfarsit(&cap, 2);
    adaugaNodSfarsit(&cap, 3);
    adaugaNodSfarsit(&cap, 4);
    adaugaNodSfarsit(&cap, 5);

    printf("Lista initiala: ");
    afiseazaLista(cap);

    separaPareImpare(cap, &capPare, &capImpare);

    printf("Lista cu elemente pare: ");
    afiseazaLista(capPare);

    printf("Lista cu elemente impare: ");
    afiseazaLista(capImpare);

    elibereazaLista(capPare);
    elibereazaLista(capImpare);

    return 0;
}
*/