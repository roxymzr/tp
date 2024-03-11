#include<stdio.h>
#include<stdlib.h>

//8.3
/*
int main()
{
    int m,n,i,j;
    int a[20][20];
    printf("m:");
    scanf("%d",&m);
    printf("n:");
    scanf("%d",&n);
    int c=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=c;
            c++;
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
*/

//8.4

/*
int main()
{
    int n,i,j;
    int a[50][50];
    int b[50][50];
    printf("n:");
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    { 
        for (j = 0; j < n; j++)
        { 
            printf("a[%d][%d]=", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            b[i][j]=a[j][i];
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
    return 0;
}
*/

//8.5

/*
int main() 
{
    int n,i,j;
    printf("n:");
    scanf("%d",&n);

    int **a=NULL;
    a=malloc(n * sizeof(int*));
    if(a==NULL)
    {
        printf("eroare\n");
        perror(NULL);
        exit(-1);
    }

    for (i = 0; i < n; i++) 
    {
        a[i] = malloc(n * sizeof(int));
        if(a[i]==NULL)
        {
            printf("eroare\n");
            perror(NULL);
            exit(-1);
        }
        for (j = 0; j < n; j++) 
        {
            scanf("%d", &a[i][j]);
        }
    }

    int *sum_linii=NULL, *sum_coloane=NULL;
    sum_linii=malloc(n * sizeof(int));
    sum_coloane=malloc(n * sizeof(int));

    if(sum_linii==NULL)
    {
        printf("eroare\n");
        perror(NULL);
        exit(-1);
    }

    if(sum_coloane==NULL)
    {
        printf("eroare\n");
        perror(NULL);
        exit(-1);
    }

    for (i = 0; i < n; i++) 
    {
        sum_linii[i] = 0;
        sum_coloane[i] = 0;
    }

    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < n; j++) 
        {
            sum_linii[i] += a[i][j];
            sum_coloane[j] += a[i][j];
        }
    }

    for (i = 0; i < n; i++) 
    {
        printf("%d ", sum_linii[i]);
    }
    printf("\n");

    for (j = 0; j < n; j++) 
    {
        printf("%d ", sum_coloane[j]);
    }
    printf("\n");

    for (i = 0; i < n;i++) 
    {
        free(a[i]);
    }
    free(a);
    free(sum_linii);
    free(sum_coloane);

    return 0;
}
*/

//8.6

/*
int main() 
{
    int n,i,j;
    printf("n: ");
    scanf("%d", &n);
    int **prieteni=NULL; 
    prieteni=malloc(n * sizeof(int*));
    if(prieteni==NULL)
    {
        printf("eroare\n");
        perror(NULL);
        exit(-1);
    }

    for (i = 0; i < n; i++) 
    {
        prieteni[i] = malloc(n * sizeof(int));
        if(prieteni[i]==NULL)
        {
            printf("eroare\n");
            perror(NULL);
            exit(-1);
        }
        for (j = 0; j < n; j++) 
        {
            scanf("%d", &prieteni[i][j]);
        }
    }

    for (i = 0; i < n; i++) 
    {
        printf("%d", i);
        int prieten;
        int num_prieteni = 0;
        while (1) 
        {
            scanf("%d", &prieten);
            if (prieten == -1) 
            {
                break;
            }
            prieteni[i][num_prieteni++] = prieten;
        }
    }

    for (i = 0; i < n; i++) 
    {
        int num_prieteni = 0;
        for (j = 0; j < n; j++) 
        {
            if (prieteni[i][j] != -1) 
            {
                num_prieteni++;
            }
        }
        printf("%d are %d prieteni.\n", i, num_prieteni);
    }

    for (i = 0; i < n; i++) 
    {
        free(prieteni[i]);
    }
    free(prieteni);

    return 0;
}
*/

//8.7

/*
int main() 
{
    int n,i,j;
    printf("n: ");
    scanf("%d", &n);
    int **distante=NULL; 
    distante=malloc(n * sizeof(int*));
    if(distante==NULL)
    {
        printf("eroare\n");
        perror(NULL);
        exit(-1);
    }

    for (i = 0; i < n; i++) 
    {
        distante[i]=malloc(n * sizeof(int));
        if(distante[i]==NULL)
        {
            printf("eroare\n");
            perror(NULL);
            exit(-1);
        }
        for (j = 0; j < n; j++) 
        {
            scanf("%d", &distante[i][j]);
        }
    }

    int distanta_minima = 100; 
    int oras1, oras2;

    for (i = 0; i < n; i++) 
    {
        for (j = i + 1; j < n; j++) 
        {
            if (distante[i][j] > 0 && distante[i][j] < distanta_minima) 
            {
                distanta_minima = distante[i][j];
                oras1 = i;
                oras2 = j;
            }
        }
    }

    printf("%d %d : %d\n", oras1, oras2, distanta_minima);

    for (i = 0; i < n; i++) 
    {
        free(distante[i]);
    }
    free(distante);

    return 0;
}
*/

//8.8

/*
int main()
{
    int m,n,p,i,j;
    int a[10][10],b[10][10],c[10][10];
    printf("m:");
    scanf("%d",&m);
    printf("n:");
    scanf("%d",&n);
    printf("p:");
    scanf("%d",&p);
    
    for (i = 0; i < m; i++)
    { 
        for (j = 0; j < n; j++)
        { 
            printf("a[%d][%d]=", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    { 
        for (j = 0; j < p; j++)
        { 
            printf("b[%d][%d]=", i, j);
            scanf("%d", &b[i][j]);
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<p;j++)
        {
            c[i][j]=0;
            for(int k=0;k<n;k++)
            {
                c[i][j]=c[i][j]+a[i][k]*b[k][j];
            }
        }
    }
    for(i=0;i<m;i++)
    {
        for(j=0;j<p;j++)
        {
            printf("%d ",c[i][j]);
        }
        printf("\n");
    }
    return 0;
}
*/

//8.9

/*
int main()
{
    int n,i,j;
    int a[10][10];
    printf("n:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i==j || j==(n-i-1))
            {
                a[i][j]=1;
            }
            else a[i][j]=0;
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
*/

//8.10

/*
int main() 
{
    int n,i,j;
    printf("n: ");
    scanf("%d", &n);

    int vanzari[10][4];

    for (i = 0; i < n; i++) 
    {
        for (j = 0; j < 4; j++) 
        {
            scanf("%d", &vanzari[i][j]);
        }
    }

    for (i = 0; i < n; i++) 
    {
        int crescator = 1;
        for (j = 1; j < 4; j++) 
        {
            if (vanzari[i][j] <= vanzari[i][j - 1]) 
            {
                crescator = 0;
                break;
            }
        }
        if (crescator) 
        {
            printf("%d \n", i + 1);
        }
    }

    return 0;
}
*/

