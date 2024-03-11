#include<stdio.h>
#include<string.h>

//8.1

/*

#define size 30

void citire(int c[size][size], int nr)
{
    for(int i=0;i<nr;i++)
    {
        for(int j=0;j<nr;j++)
        {
            printf("c[%d][%d]:",i,j);
            scanf("%d",&c[i][j]);
        }
    }
}


int main()
{
    int a[size][size], b[size][size];
    int n,m,i,j;
    printf("n:");
    scanf("%d",&n);
    printf("m:");
    scanf("%d",&m);
    citire(a,n);
    citire(b,m);

    int apare=0;
    for(i=0;i<n-m+1;i++) 
    {
        for(j=0;j<n-m+1;j++) 
        {
            int egal=1;
            for(int x=0;x<m;x++) 
            {
                for(int y=0;y<m;y++) 
                {
                    if(a[i+x][j+y]!=b[x][y]) 
                    {
                        egal=0;
                        break;
                    }
                }
                if(!egal) 
                {
                    break;
                }
            }
            if(egal) 
            {
                printf("(%d,%d) ",i,j);
                apare=1;
            }
        }
    }

    printf("\n");

    if(!apare) 
    {
        printf("nu apare\n");
    }


    return 0;
}

*/

//8.2

/*

#define MAX 100

void citire(char c[MAX][MAX], int n) 
{
    for (int i = 0; i < n; i++) 
    {
        scanf("%s", c[i]);
    }
}

void verif(char c[MAX][MAX], int n, char cuv[MAX]) 
{
    int len=strlen(cuv);
    for(int i=0;i<n;i++) 
    {
        for(int j=0;j<=(n-len);j++) 
        {
            int k;
            for(k=0;k<len;k++) 
            {
                if(c[i][j+k]!=cuv[k]) 
                {
                    break;
                }
            }
            if(k==len) 
            {
                printf("(%d,%d) dreapta\n",i,j);
            }
        }
    }

    for(int i=0;i<n;i++) 
    {
        for(int j=(len-1);j<n;j++) 
        {
            int k;
            for(k=0;k<len;k++) 
            {
                if(c[i][j-k]!=cuv[k]) 
                {
                    break;
                }
            }
            if(k==len) 
            {
                printf("(%d,%d) stanga\n",i,j);
            }
        }
    }

    for(int i=(len-1);i<n;i++) 
    {
        for(int j=0;j<n;j++) 
        {
            int k;
            for(k=0;k<len;k++) 
            {
                if(c[i-k][j]!=cuv[k]) 
                {
                    break;
                }
            }
            if(k==len) 
            {
                printf("(%d,%d) sus\n",i,j);
            }
        }
    }

    for(int i=0;i<=(n-len);i++) 
    {
        for(int j=0;j<n;j++) 
        {
            int k;
            for(k=0;k<len;k++) 
            {
                if(c[i+k][j]!=cuv[k]) 
                {
                    break;
                }
            }
            if(k==len) 
            {
                printf("(%d,%d) jos\n",i,j);
            }
        }
    }
}

int main() 
{
    int n;
    char a[MAX][MAX];
    char cuvant[MAX];
    scanf("%d",&n);
    citire(a,n);
    scanf("%s",cuvant);
    verif(a,n,cuvant);
    return 0;
}

*/