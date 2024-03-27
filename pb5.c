//5.2

/*
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 4096

int main(int argc, char *argv[]) 
{
    FILE *src, *dst;
    char buffer[BLOCK_SIZE];
    size_t bytes;

    if(argc != 3) 
    {
        printf("Utilizare: %s <fișier_sursă> <fișier_destinație>\n", argv[0]);
        return 1;
    }

    src = fopen(argv[1], "rb");
    if(src == NULL)
    {
        perror("Eroare la deschiderea fișierului sursă");
        return 1;
    }

    dst = fopen(argv[2], "wb");
    if(dst == NULL) 
    {
        perror("Eroare la deschiderea fișierului destinație");
        fclose(src);
        return 1;
    }

    while((bytes = fread(buffer, 1, BLOCK_SIZE, src)) > 0) {
        fwrite(buffer, 1, bytes, dst);
    }

    fclose(src);
    fclose(dst);

    return 0;
}
*/

//5.3

/*
#include <stdio.h>
#include <stdlib.h>

void scrie_matrice(int m, int n, int a[m][n]) 
{
    FILE *f = fopen("matrice.bin", "wb");
    if(f == NULL) 
    {
        printf("Eroare la deschiderea fișierului\n");
        exit(1);
    }

    fwrite(&m, sizeof(int), 1, f);
    fwrite(&n, sizeof(int), 1, f);
    fwrite(a, sizeof(int), m*n, f);

    fclose(f);
}

void citeste_matrice() 
{
    FILE *f = fopen("matrice.bin", "rb");
    if(f == NULL) 
    {
        printf("Eroare la deschiderea fișierului\n");
        exit(1);
    }

    int m, n;
    fread(&m, sizeof(int), 1, f);
    fread(&n, sizeof(int), 1, f);

    int b[m][n];
    fread(b, sizeof(int), m*n, f);

    for(int i = 0; i < m; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    fclose(f);
}

int main() 
{
    int m, n;
    printf("Introduceți m și n: ");
    scanf("%d%d", &m, &n);

    int a[m][n];
    printf("Introduceți elementele matricei:\n");
    for(int i = 0; i < m; i++) 
    {
        for(int j = 0; j < n; j++) 
        {
            scanf("%d", &a[i][j]);
        }
    }

    scrie_matrice(m, n, a);
    citeste_matrice();

    return 0;
}
*/


//5.5

/*
#include <stdio.h>
#include <stdlib.h>

void hexdump(const char *filename) 
{
    FILE *file = fopen(filename, "rb");
    if(file == NULL) 
    {
        printf("Eroare la deschiderea fișierului\n");
        exit(1);
    }

    unsigned char buffer[16];
    size_t bytes;
    unsigned long offset = 0;

    while((bytes = fread(buffer, 1, sizeof(buffer), file)) > 0) 
    {
        printf("%08lx  ", offset);

        for(size_t i = 0; i < 16; i++) 
        {
            if(i < bytes) {
                printf("%02x ", buffer[i]);
            } else {
                printf("   ");
            }
        }

        printf(" ");

        for(size_t i = 0; i < bytes; i++) 
        {
            unsigned char c = buffer[i];
            printf("%c", (c >= 32 && c <= 255) ? c : '.');
        }

        printf("\n");
        offset += 16;
    }

    fclose(file);
}

int main(int argc, char *argv[]) 
{
    if(argc != 2) 
    {
        printf("Utilizare: %s <fișier>\n", argv[0]);
        return 1;
    }

    hexdump(argv[1]);

    return 0;
}
*/

//5.6

/*
#include <stdio.h>
#include <stdlib.h>

void compara_fisiere(const char *fisier1, const char *fisier2) 
{
    FILE *f1 = fopen(fisier1, "rb");
    FILE *f2 = fopen(fisier2, "rb");

    if(f1 == NULL || f2 == NULL) 
    {
        printf("Eroare la deschiderea fișierelor\n");
        exit(1);
    }

    int c1, c2;
    unsigned long offset = 0;

    while((c1 = fgetc(f1)) != EOF && (c2 = fgetc(f2)) != EOF) 
    {
        if(c1 != c2) 
        {
            printf("%08lx %02x %02x\n", offset, c1, c2);
        }
        offset++;
    }

    while((c1 = fgetc(f1)) != EOF) 
    {
        printf("%08lx %02x --\n", offset, c1);
        offset++;
    }

    while((c2 = fgetc(f2)) != EOF) 
    {
        printf("%08lx -- %02x\n", offset, c2);
        offset++;
    }

    fclose(f1);
    fclose(f2);
}

int main(int argc, char *argv[]) 
{
    if(argc != 3) 
    {
        printf("Utilizare: %s <fișier1> <fișier2>\n", argv[0]);
        return 1;
    }

    compara_fisiere(argv[1], argv[2]);

    return 0;
}
*/

//5.7


/*
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    if(argc < 4) 
    {
        printf("Utilizare: %s <fișier> <offset> <octeți>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    unsigned long offset = strtoul(argv[2], NULL, 16);

    FILE *file = fopen(filename, "r+b");
    if(file == NULL) 
    {
        printf("Eroare la deschiderea fișierului\n");
        exit(1);
    }

    fseek(file, offset, SEEK_SET);

    for(int i = 3; i < argc; i++) 
    {
        unsigned char octet = strtoul(argv[i], NULL, 16);
        fwrite(&octet, 1, 1, file);
    }

    fclose(file);

    return 0;
}
*/


//5.8

/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) 
{
    if(argc < 3) 
    {
        printf("Utilizare: %s <fișier> <octeți>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    int seq_len = argc - 2;
    unsigned char *seq = malloc(seq_len);

    for(int i = 0; i < seq_len; i++) 
    {
        seq[i] = strtoul(argv[i+2], NULL, 16);
    }

    FILE *file = fopen(filename, "rb");
    if(file == NULL) 
    {
        printf("Eroare la deschiderea fișierului\n");
        free(seq);
        exit(1);
    }

    unsigned long offset = 0;
    unsigned char *buffer = malloc(seq_len);
    size_t bytes;

    while((bytes = fread(buffer, 1, seq_len, file)) == seq_len) 
    {
        if(memcmp(buffer, seq, seq_len) == 0) 
        {
            printf("%08lx\n", offset);
        }
        fseek(file, 1 - seq_len, SEEK_CUR);
        offset++;
    }

    free(buffer);
    free(seq);
    fclose(file);

    return 0;
}
*/

//5.9

/*
#include <stdio.h>
#include <stdlib.h>

#define BLOCK_SIZE 4096

void concateneaza_fisiere(int numar_fisiere, char *fisiere[], const char *fisier_destinatie) 
{
    FILE *destinatie = fopen(fisier_destinatie, "wb");
    if(destinatie == NULL) 
    {
        printf("Eroare la deschiderea fișierului destinatie\n");
        exit(1);
    }

    char buffer[BLOCK_SIZE];
    size_t bytes;

    for(int i = 0; i < numar_fisiere; i++) 
    {
        FILE *sursa = fopen(fisiere[i], "rb");
        if(sursa == NULL) 
        {
            printf("Eroare la deschiderea fișierului sursă %s\n", fisiere[i]);
            continue;
        }

        while((bytes = fread(buffer, 1, BLOCK_SIZE, sursa)) > 0) 
        {
            fwrite(buffer, 1, bytes, destinatie);
        }

        fclose(sursa);
    }

    fclose(destinatie);
}

int main(int argc, char *argv[]) 
{
    if(argc < 3) 
    {
        printf("Utilizare: %s <fișiere_sursă> <fișier_destinație>\n", argv[0]);
        return 1;
    }

    concateneaza_fisiere(argc - 2, argv + 1, argv[argc - 1]);

    return 0;
}
*/
