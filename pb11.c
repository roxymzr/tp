//11.1

/*
#include <stdio.h>
#include <float.h>
#include <math.h>

#define MAX_POINTS 100

typedef struct {
    double x, y;
} Point;

double dist(Point a, Point b) 
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main() 
{
    int n, i, j, min_index;
    double min_dist;
    Point points[MAX_POINTS], current_point = {0, 0};
    int visited[MAX_POINTS] = {0};

    printf("Introduceti numarul de puncte: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) 
    {
        printf("Introduceti coordonatele punctului %d: ", i + 1);
        scanf("%lf %lf", &points[i].x, &points[i].y);
    }

    for(i = 0; i < n; i++) 
    {
        min_dist = DBL_MAX;
        for(j = 0; j < n; j++) 
        {
            if(!visited[j] && dist(current_point, points[j]) < min_dist) 
            {
                min_dist = dist(current_point, points[j]);
                min_index = j;
            }
        }
        visited[min_index] = 1;
        current_point = points[min_index];
        printf("Gaura %d: (%.2lf, %.2lf)\n", i + 1, current_point.x, current_point.y);
    }
    return 0;
}
*/



//11.2

/*
#include <stdio.h>
#include <math.h>

#define G 6.674e-11

double calc_force(double m1, double m2, double d) 
{
    return G * m1 * m2 / (d * d);
}

int main() 
{
    int n, i;
    double ma, mb, m, d, pas,forta, da, db;

    printf("Introduceti numarul de pasi: ");
    scanf("%d", &n);

    printf("Introduceti masele ma, mb si m: ");
    scanf("%lf %lf %lf", &ma, &mb, &m);

    printf("Introduceti distanta d: ");
    scanf("%lf", &d);

    pas=d/n;
    for(i = 0; i <= n; i++) 
    {
        da = i * pas;
        db = d - da;
        forta = calc_force(m, mb, db) - calc_force(m, ma, da);
        printf("Pasul %d: F = %.2e N\n", i, forta);
    }

    return 0;
}
*/



//11.3


/*#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int reduce(int** matrice, int x, int y, int m, int n) 
{
    if(m == 0 || n == 0) 
    {
        return 0;
    } 
    else if(m == 1 && n == 1) 
    {
        return matrice[x][y];
    } 
    else 
    {
        int mijloc_m = m / 2;
        int mijloc_n = n / 2;
        int sus_stg = reduce(matrice, x, y, mijloc_m, mijloc_n);
        int sus_dr = reduce(matrice, x, y + mijloc_n, mijloc_m, n-mijloc_n);
        int jos_stg = reduce(matrice, x + mijloc_m, y, m - mijloc_m, mijloc_n);
        int jos_dr = reduce(matrice, x + mijloc_m, y + mijloc_n, m - mijloc_m, n - mijloc_n);
        int max_sus = sus_stg > sus_dr ? sus_stg : sus_dr;
        int min_jos = jos_stg < jos_dr ? jos_stg : jos_dr;
        return max_sus-min_jos;
    }
}

int main() 
{
    int m, n, i, j;
    printf("Introduceti dimensiunile matricei (m, n): ");
    scanf("%d %d", &m, &n);
    int**matrice=(int**)malloc(m * sizeof(int*));
    for(i = 0; i < m; i++) 
    {
        matrice[i]=(int*)malloc(n * sizeof(int));
        for(j = 0; j < n; j++) 
        {
            printf("Introduceti elementul matricei[%d][%d]: ", i, j);
            scanf("%d", &matrice[i][j]);
        }
    }
    int result = reduce(matrice,0,0,m,n);
    printf("Reducerea matricei este: %d\n", result);
    for(i = 0; i < m; i++) 
    {
        free(matrice[i]);
    }
    free(matrice);
    return 0;
}
*/



//11.4


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[16];
    int value;
}Player;

int comparare(const void* a, const void* b) 
{
    return ((Player*)b)->value-((Player*)a)->value;
}

int main() 
{
    FILE* file = fopen("players.txt", "r");
    if(file == NULL) 
    {
        printf("Nu s-a putut deschide fisierul.\n");
        return 1;
    }
    int n, m, i, j;
    fscanf(file, "%d %d", &n, &m);
    Player* players = (Player*)malloc(n*sizeof(Player));
    for(i = 0;i < n;i++) 
    {
        fscanf(file, "%s %d", players[i].name, &players[i].value);
    }
    fclose(file);
    qsort(players,n,sizeof(Player),comparare);
    for(i = 0;i < m;i++) 
    {
        printf("Grupa %d:\n",i + 1);
        for(j = i; j < n; j += m) 
        {
            printf("%s %d\n", players[j].name, players[j].value);
        }
        printf("\n");
    }
    free(players);
    return 0;
}
*/



//11.5



/*
#include <stdio.h>

char *unitati[] = {"", "unu", "doi", "trei", "patru", "cinci", "sase", "sapte", "opt", "noua"};
char *zeci[] = {"", "zece", "douazeci", "treizeci", "patruzeci", "cincizeci", "saizeci", "saptezeci", "optzeci", "nouazeci"};
char *special[] = {"zece", "unsprezece", "doisprezece", "treisprezece", "paisprezece", "cincisprezece", "saisprezece", "saptesprezece", "optsprezece", "nouasprezece"};

void afisare(int n) 
{
    if(n == 1000) 
    {
        printf("o mie\n");
        return;
    }
    if(n >= 100) 
    {
        printf("%s sute ", unitati[n / 100]);
        n %= 100;
    }
    if(n >= 20) 
    {
        printf("%s ", zeci[n / 10]);
        n %= 10;
    }
    if(n >= 10) 
    {
        printf("%s ", special[n % 10]);
        n = 0;
    }
    printf("%s\n", unitati[n]);
}

int main() 
{
    int n;
    do 
    {
        printf("Introduceti un numar: ");
        scanf("%d", &n);
        afisare(n);
    } while(n != 1000);
    return 0;
}*/



