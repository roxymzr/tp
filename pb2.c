#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

//2.1

/*
typedef struct 
{
    char name[50];
    int grade;
}StudentResult ;

int comp(const void* a, const void* b) {
    const StudentResult* resultA = (const StudentResult*)a;
    const StudentResult* resultB = (const StudentResult*)b;

    if (resultA->grade != resultB->grade) 
    {
        return resultB->grade - resultA->grade;
    }

    else 
    {
        return strcmp(resultA->name, resultB->name);
    }
}

int main() 
{
    int n;
    printf("n:");
    scanf("%d", &n);

    StudentResult results[n];
    for (int i = 0; i < n; i++) 
    {
        scanf("%s %d", results[i].name, &results[i].grade);
    }

    qsort(results, n, sizeof(StudentResult), comp);

    for (int i = 0; i < n; i++) 
    {
        printf("%s: %d\n", results[i].name, results[i].grade);
    }

    return 0;
}
*/

//2.2

/*
void sterge(int vector[], int* numarElemente, int (*cond)(int)) 
{
    int i, j;
    for (i = 0, j = 0; i < *numarElemente; i++) 
    {
        if (cond(vector[i])) 
        {
            vector[j++] = vector[i];
        }
    }
    *numarElemente = j;
}

int neg(int numar) 
{
    return numar < 0;
}

int main() {
    int vector[] = {10, -5, 7, -3, 0, -8, 15};
    int numarElemente = sizeof(vector) / sizeof(vector[0]);
    sterge(vector, &numarElemente, neg);
    for (int i = 0; i < numarElemente; i++) 
    {
        printf("%d ", vector[i]);
    }
    printf("\n");

    return 0;
}
*/

//2.3

/*
int comp(const void* a, const void* b) 
{
    float A = *((float*)a);
    float B = *((float*)b);

    if (A < B) return -1;
    if (A > B) return 1;
    return 0;
}

int main() 
{
    int n;
    printf("n:");
    scanf("%d", &n);

    if (n >= 10) 
    {
        printf("ieșire\n");
        return 1;
    }

    float numere[n];
    for (int i = 0; i < n; i++) 
    {
        scanf("%f", &numere[i]);
    }

    qsort(numere, n, sizeof(float), comp);

    for (int i = 0; i < n; i++) 
    {
        printf("%.2f ", numere[i]);
    }
    printf("\n");

    float x;
    printf("x:");
    scanf("%f", &x);

    float* rezultat = (float*)bsearch(&x, numere, n, sizeof(float), comp);
    if (rezultat != NULL) 
    {
        printf("%.2f exista\n", x);
    } 
    else 
    {
        printf("%.2f nu exista\n", x);
    }

    return 0;
}
*/

//2.4

/*
double tabelare(double (*f)(double), double a, double b, int n) 
{
    double step = (b - a) / n;
    double x, r;

    for (int i = 0; i <n; i++) 
    {
        x = a + i * step;
        r = f(x);
        printf("f(%.2f) = %.2f\n", x, r);
    }
}

int main() 
{
    double a, b;
    int n;

    printf("[a, b]:");
    scanf("%lf %lf", &a, &b);

    printf("n:");
    scanf("%d", &n);

    printf("cos:\n");
    tabelare(cos, a, b, n);

    printf("sqrt:\n");
    tabelare(sqrt, a, b, n);

    printf("fabs:\n");
    tabelare(fabs, a, b, n);

    return 0;
}
*/

