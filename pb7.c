//7.1

/*
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct elem
{
    int n; 
    struct elem *urm; 
} elem;

elem *nou(int n, elem *urm) 
{
    elem *e = (elem*)malloc(sizeof(elem));
    if(!e) 
    {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    e->n = n;
    e->urm = urm;
    return e;
}

bool suntIdentice(elem *lista1, elem *lista2) 
{
    while (lista1 != NULL && lista2 != NULL) 
    {
        if (lista1->n != lista2->n)
            return false;
        lista1 = lista1->urm;
        lista2 = lista2->urm;
    }
    return (lista1 == NULL && lista2 == NULL);
}

int main() 
{
    elem *lista1 = nou(1, nou(2, nou(3, NULL)));
    elem *lista2 = nou(1, nou(2, nou(3, NULL)));
    if(suntIdentice(lista1, lista2))
        printf("Listele sunt identice\n");
    else
        printf("Listele nu sunt identice\n");
    return 0;
}
*/


//7.2

/*
#include <stdlib.h>
#include <stdio.h>

typedef struct elem
{
    int n; 
    struct elem *urm; 
} elem;

elem *nou(int n, elem *urm) 
{
    elem *e = (elem*)malloc(sizeof(elem));
    if(!e) 
    {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    e->n = n;
    e->urm = urm;
    return e;
}

void inverseaza(elem **head) 
{
    elem *prev = NULL;
    elem *current = *head;
    elem *next = NULL;
    while (current != NULL) 
    {
        next = current->urm;
        current->urm = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    afisare(&head);
}

void afisare(elem *head)  
{
    elem *temp = head;
    while (temp != NULL)  
    {
        printf("%d ", temp->n);
        temp = temp->urm;
    }
    printf("\n");
}

int main() 
{
    elem *head = nou(1, nou(2, nou(3, NULL)));
    inverseaza(&head);
    return 0;
}
*/

//7.3

/*
#include <stdio.h>
#include <stdlib.h>


typedef struct elem{
    int n;
    struct elem *urm;
}elem;

elem *nou(int n,elem *urm)
{
    elem *e=(elem*)malloc(sizeof(elem));
    if(e==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    e->n=n;
    e->urm=urm;
    return e;
}


elem *adaugaSfarsit(elem *lista,int n)
{
    if (lista == NULL) 
    {
        return nou(n, NULL); 
    }
    elem *p;
    for(p=lista;p->urm!=NULL;p=p->urm)
    {}
    p->urm=nou(n,NULL);
    return lista;
}

void afisare(elem *lista)
{
    for(;lista;lista=lista->urm)
    {
        printf("%d ",lista->n);
    }printf("\n");
}

void eliberare(elem *lista)
{
    elem *p;
    while(lista)
    {
        p=lista->urm;
        free(lista);
        lista=p;
    }
}

elem *concat(elem *lista1,elem *lista2)
{
    elem *rez=NULL;
    
    for(elem *p=lista1;p!=NULL;p=p->urm)
    {
        if(rez==NULL)
        {
            rez=nou(p->n,NULL);
        }
        else
        {
            adaugaSfarsit(rez,p->n);
        }
        
    }

    for(elem *p=lista2;p!=NULL;p=p->urm)
    {
        uint flag=0;
        for(elem *p1=rez;p1!=NULL;p1=p1->urm)
        {
            if(p->n==p1->n)
            {
                flag++;
                break;
            }
        }
        if(!flag) adaugaSfarsit(rez,p->n);
        else continue;
    }
    return rez;
}

int main(void)
{
    elem *lista1=NULL;
    uint size1=0;
    printf("Cate elemente se citesc in prima lista:");
    scanf("%d",&size1);
    for(int i=0;i<size1;i++)
    {
        int n=0;
        scanf("%d",&n);
        lista1=adaugaSfarsit(lista1,n);
    }

    elem *lista2=NULL;
    uint size2=0;
    printf("Cate elemente se citesc in a doua lista:");
    scanf("%d",&size2);
    for(int i=0;i<size2;i++)
    {
        int n=0;
        scanf("%d",&n);
        lista2=adaugaSfarsit(lista2,n);
    }

    elem *rez=concat(lista1,lista2);
    afisare(rez);
    eliberare(rez);
    
    
    eliberare(lista1);
    eliberare(lista2);
}
*/



//7.6

/*
#include<stdio.h>
#include<stdlib.h>

typedef struct elem{
    int n;
    struct elem *urm;
}elem;

elem *nou(int n,elem *urm)
{
    elem *e=(elem*)malloc(sizeof(elem));
    if(e==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    e->n=n;
    e->urm=urm;
    return e;
}

elem *adaugaSfarsit(elem *lista,int n)
{
    if(lista==NULL) return nou(n,NULL);

    elem *p;
    for(p=lista;p->urm!=NULL;p=p->urm)
    {}
    p->urm=nou(n,NULL);
    return lista;
}


void afisare(elem *lista)
{
    for(;lista;lista=lista->urm)
    {
        printf("%d ",lista->n);
    }printf("\n");
}



elem *ordonare(elem *lista)
{
    if(lista==NULL || lista->urm==NULL)return lista;
    elem *p1=NULL,*p2=NULL;
    for(p1=lista;p1->urm!=NULL;p1=p1->urm)
    {
        int aux=0;
        elem *min=p1;
        for(p2=p1;p2!=NULL;p2=p2->urm)
        {
            if (p2->n < min->n) 
            {
                min = p2;
            }
        }
        aux=p1->n;
        p1->n=min->n;
        min->n=aux;

    }
    return lista;
}


void eliberare(elem *lista)
{
    elem *p;
    while(lista!=NULL)
    {
        p=lista->urm;
        free(lista);
        lista=p;
    }
}

int main(void)
{
    elem *lista1=NULL;
    uint size1=0;
    printf("Cate elemente se citesc in prima lista:");
    scanf("%d",&size1);
    for(int i=0;i<size1;i++)
    {
        int n=0;
        scanf("%d",&n);
        lista1=adaugaSfarsit(lista1,n);
    }
    afisare(lista1);
    lista1=ordonare(lista1);
    afisare(lista1);
    eliberare(lista1);
}
*/


//7.7

/*
#include<stdio.h>
#include<stdlib.h>

typedef struct elem{
    int n;
    struct elem *urm;
}elem;

elem *nou(int n,elem *urm)
{
    elem *e=(elem*)malloc(sizeof(elem));
    if(e==NULL)
    {
        printf("Eroare la alocare\n");
        perror(NULL);
        exit(-1);
    }
    e->n=n;
    e->urm=urm;
    return e;
}

elem *adaugaSfarsit(elem *lista,int n)
{
    if(lista==NULL) return nou(n,NULL);

    elem *p;
    for(p=lista;p->urm!=NULL;p=p->urm)
    {}
    p->urm=nou(n,NULL);
    return lista;
}


void afisare(elem *lista)
{
    for(;lista;lista=lista->urm)
    {
        printf("%d ",lista->n);
    }printf("\n");
}



elem *ordonare(elem *lista)
{
    if(lista==NULL || lista->urm==NULL)return lista;
    elem *p1=NULL,*p2=NULL;
    for(p1=lista;p1->urm!=NULL;p1=p1->urm)
    {
        elem *min=p1;
        for(p2=p1;p2!=NULL;p2=p2->urm)
        {
            if(min->n>p2->n)
            {
                min=p2;
            }
        }
        int aux=0;
        aux=p1->n;
        p1->n=min->n;
        min->n=aux;
    }
    return lista;
}


elem *concat(elem *lista1,elem *lista2)
{
    if(lista1==NULL)return lista2;
    else if(lista2==NULL)return lista1;

    elem *p1=NULL,*p2=NULL,*rez=NULL;

    for(p1=lista1;p1!=NULL;p1=p1->urm)
    {
        if(rez==NULL)
        {
            rez=nou(p1->n,NULL);
        }
        else
        {
            rez=adaugaSfarsit(rez,p1->n);
        }
    }

    for(p2=lista2;p2!=NULL;p2=p2->urm)
    {
        rez=adaugaSfarsit(rez,p2->n);
    }

    return rez;
}



void eliberare(elem *lista)
{
    elem *p;
    while(lista!=NULL)
    {
        p=lista->urm;
        free(lista);
        lista=p;
    }
}

int main(void)
{
    elem *lista1=NULL;
    uint size1=0;
    printf("Cate elemente se citesc in prima lista:");
    scanf("%d",&size1);
    for(int i=0;i<size1;i++)
    {
        int n=0;
        scanf("%d",&n);
        lista1=adaugaSfarsit(lista1,n);
    }
    lista1=ordonare(lista1);
    afisare(lista1);

    elem *lista2=NULL;
    uint size2=0;
    printf("Cate elemente se citesc in a doua lista:");
    scanf("%d",&size2);
    for(int i=0;i<size2;i++)
    {
        int n=0;
        scanf("%d",&n);
        lista2=adaugaSfarsit(lista2,n);
    }
    lista2=ordonare(lista2);
    afisare(lista2);
    elem *rez=NULL;
    rez=concat(lista1,lista2);
    afisare(rez);
    
    eliberare(lista1);
    eliberare(lista2);
    eliberare(rez);
}
*/