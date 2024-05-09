//10.1


/*
#include <stdio.h>

int cmmdc(int a, int b) 
{
    if (b == 0)
        return a;
    return cmmdc(b, a % b);
}

int main() 
{
    int n1,n2;
    printf("n1 , n2:");
    scanf("%d %d", &n1, &n2);

    printf("cmmdc: %d \n", cmmdc(n1,n2));

    return 0;
}
*/


//10.2


/*
#include<stdio.h>

int suma_cifre(int n)
{
    if(n==0)
        return 0;
    return suma_cifre(n%10+suma_cifre(n/10));
}

int main()
{
    int n;
    printf("n:");
    scanf("%d",&n);
    printf("suma cifrelor este: %d \n",suma_cifre(n));
    return 0;
}
*/


//10.3

/*
#include <stdio.h>

int cifra_max(int n) 
{
    if (n < 10)
        return n;
    else {
        int cifra = n % 10;
        int max = cifra_max(n / 10);
        if (cifra > max)
            return cifra;
        else
            return max;
    }
}

int main() 
{
    int n;
    printf("n: ");
    scanf("%d", &n);

    printf("Cifra maxima este: %d\n", cifra_max(n));

    return 0;
}
*/



//10.4

/*
#include <stdio.h>

int fibonacci(int n) 
{
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() 
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    printf("Al %d-lea termen Fibonacci este %d.\n", n, fibonacci(n));
    return 0;
}
*/


//10.5

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* fibonacci(int n, char* s1, char* s2) 
{
    if (n == 0)
        return s1;
    else if (n == 1)
        return s2;
    else 
    {
        char* prev1 = fibonacci(n - 1, s1, s2);
        char* prev2 = fibonacci(n - 2, s1, s2);
        char* result = malloc(strlen(prev1) + strlen(prev2) + 1);
        strcpy(result, prev2);
        strcat(result, prev1);
        return result;
    }
}

int main() 
{
    int n;
    char s1[100], s2[100];
    printf("s1: \n");
    scanf("%s", s1);
    printf("s2: \n");
    scanf("%s", s2);
    printf("n: \n");
    scanf("%d", &n);

    char* result = fibonacci(n, s1, s2);
    printf("%s\n", result);
    free(result);
    return 0;
}
*/


//10.6



//10.7



//10.8


#include <stdio.h>

int bsearch(int v[],int s,int right,int x) 
{
    if(right>=s) 
    {
        int mij=s+(right-s)/2;
        if(v[mij]==x)
        {
            return 1;
        }
        if (v[mij]<x)
        {
            return bsearch(v,mij+1,right, x);
        }
        return bsearch(v,s, mij-1,x);
    }
    return 0;
}

int main(void) 
{
    int v[] = {1, 5, 8, 12, 17, 20, 33, 40};
    int n = sizeof(v) / sizeof(v[0]);
    int x = 33;
    int a= bsearch(v, 0, n - 1, x);
    if(a!= 0) 
    {
        printf("Numarul este prezent in vector\n");
    }
    else
    {
        printf("Numarul nu este prezent in vector\n");
    }
    return 0;
}