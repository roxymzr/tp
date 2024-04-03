//6.2

/*
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

float *allocVec(int n, ...) 
{
    float *vec = (float *)malloc(n * sizeof(float));
    if (vec == NULL) 
    {
        printf("Eroare la alocarea vectorului.\n");
        exit(1);
    }
    va_list args;
    va_start(args, n);
    for (int i = 0; i < n; i++) 
    {
        vec[i] = va_arg(args, double);
    }
    va_end(args);

    return vec;
}

int main() 
{
    int n = 3;
    float *result = allocVec(n, 7.2, -1, 0);
    printf("{");
    for (int i = 0; i < n; i++) 
    {
        printf("%.1f", result[i]);
        if (i < n - 1) 
        {
            printf(", ");
        }
    }
    printf("}\n");
    free(result);
    return 0;
}
*/

//6.4

/*
#include <stdio.h>
#include <stdarg.h>

int crescator(int n, char tip, ...)
 {
    va_list args;
    va_start(args, tip);
    double prev_val = 0.0;
    if (tip != 'd' && tip != 'f') 
    {
        printf("Tip invalid. Utilizați 'd' pentru int sau 'f' pentru double.\n");
        return 0;
    }
    if (n <= 0) 
    {
        printf("Număr invalid de argumente.\n");
        return 0;
    }
    for (int i = 0; i < n; i++) 
    {
        double val = (tip == 'd') ? va_arg(args, int) : va_arg(args, double);
        if (val <= prev_val) 
        {
            va_end(args);
            return 0;
        }
        prev_val = val;
    }
    va_end(args);
    return 1;
}

int main() 
{
    printf("%d\n", crescator(3, 'd', -1, 7, 9)); 

    return 0;
}
*/



//6.6

/*
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

{
    va_list args;
    va_start(args, n);
    int total_length = 0;
    for (int i = 0; i < n; i++) 
    {
        char *str = va_arg(args, char *);
        total_length += strlen(str) + 1; 
    }
    char *result = (char *)malloc(total_length);
    if (result == NULL) 
    {
        printf("Eroare la alocarea șirului.\n");
        exit(1);
    }
    va_end(args);
    va_start(args, n);
    strcpy(result, va_arg(args, char *));
    for (int i = 1; i < n; i++) 
    {
        strcat(result, " "); 
        strcat(result, va_arg(args, char *));
    }
    va_end(args);
    return result;
}

int main() 
{
    char *result = concat(3, "Ion", "si", "Ana");
    printf("%s\n", result);  
    free(result);
    return 0;
}

*/

//6.9

/*
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    double sum = 0.0;
    for (int i = 1; i < argc; i++) 
    {
        sum += atof(argv[i]);
    }
    printf("%.3f\n", sum);
    return 0;
}
*/

//6.11

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double calculate_expression(int argc, char *argv[]) 
{
    double result = atof(argv[1]);
    for (int i = 2; i < argc; i += 2) 
    {
        char *operator = argv[i];
        double number = atof(argv[i + 1]);
        if (strcmp(operator, "add") == 0) 
        {
            result += number;
        } 
        else if (strcmp(operator, "sub") == 0) 
        {
            result -= number;
        } 
        else if (strcmp(operator, "mul") == 0) 
        {
            result *= number;
        } 
        else if (strcmp(operator, "div") == 0) 
        {
            if (number != 0) 
            {
                result /= number;
            } 
            else 
            {
                printf("Eroare: împărțire la zero.\n");
                exit(1);
            }
        }
        else 
        {
            printf("Operator invalid: %s\n", operator);
            exit(1);
        }
    }
    return result;
}

int main(int argc, char *argv[]) 
{
    if (argc < 4 || (argc - 2) % 2 != 0) 
    {
        printf("Utilizare: %s numar1 operatie numar2 [operatie numar3 ...]\n", argv[0]);
        return 1;
    }
    double result = calculate_expression(argc, argv);
    printf("Rezultat: %.2f\n", result);
    return 0;
}
*/


//6.13

/*
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    int i, j;
    int count[26] = {0};
    int total = 0;
    if (argc < 3) 
    {
        printf("Usage: %s <0|1> <words>\n", argv[0]);
        return 1;
    }
    for (i = 2; i < argc; i++) 
    {
        for (j = 0; j < strlen(argv[i]); j++)
        {
            if (argv[i][j] >= 'a' && argv[i][j] <= 'z') {

                total++;
                if (argv[1][0] == '1') 
                {
                    count[argv[i][j] - 'a']++;
                }
            }
        }
    }
    if (argv[1][0] == '0') 
    {
        printf("%d\n", total);
    } else if (argv[1][0] == '1') 
    {
        for (i = 0; i < 26; i++) 
        {
            if (count[i] > 0) 
            {
                printf("%c: %d\n", i + 'a', count[i]);
            }
        }
    }
    return 0;
}
*/


