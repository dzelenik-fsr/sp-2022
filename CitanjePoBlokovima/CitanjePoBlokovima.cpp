#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define BLOK 60

typedef struct {
    int pbr;
    char mjesto[50 + 1];
    char opcina[50 + 1];
}zapis;


void brojzapisa_velicina_brojanjem() {
    printf("\nBroj zapisa i velicina datoteke 'mjesta.txt' brojanjem");

    FILE* f = fopen("mjesta.txt", "r");
    int br = 0;
    int velicina = 0;
    char c;

    // Ovdje pisati kod
   
    printf("\nBroj zapisa: %d", br + 1);
    printf("\nVelicina datoteke: %d", velicina);
    fclose(f);
}

void brojzapisa_velicina_jednomnaredbom() {
    printf("\nBroj zapisa i velicina datoteke 'mjesta.txt' jednom naredbom.");

    FILE* f = fopen("mjesta.txt", "r");
    int velicina = 0;

    // Ovdje psiati kod

    printf("\nVelicina datoteke %d", velicina);
    fclose(f);
}

void brojzapisa_velicina_brojanjem2() {
    printf("\nBroj zapisa i velicina datoteke 'mjesta.dat' brojanjem");

    FILE* f = fopen("mjesta.dat", "rb");
    zapis tmp;
    int br = 0;
    int velicina = 0;
    
    // Ovdje pisati kod

    printf("\nBroj zapisa %d", br);
    printf("\nVelicina datoteke %d", velicina);
    fclose(f);
}

void brojzapisa_velicina_jednomnaredbom2() {
    printf("\nBroj zapisa i velicina datoteke 'mjesta.dat' jednom naredbom.");

    FILE* f = fopen("mjesta.dat", "rb");
    int velicina = 0;
    int br = 0;

    // Ovdje pisati kod

    printf("\nBroj zapisa %d", br);
    printf("\nVelicina datoteke %d", velicina);
    fclose(f);
}

void tablica_vodecih_zapisa_u_memoriji() {

    FILE* f = fopen("mjesta.dat", "rb");            // Otvori datoteku

    fseek(f, 0, SEEK_END);                          // Idi na kraj
    int broj_zapisa = (ftell(f) / sizeof(zapis));
    int broj_blokova = ceil((float)broj_zapisa / BLOK);

    printf("\nBroj zapisa %d", broj_zapisa);
    printf("\nBroj blokova %d", broj_blokova);

    zapis pom;
    long* index = NULL;

    // Ovdje pisati kod

}

void main() {
    FILE* f, * fb;
    zapis pom;
    int br;
    f = fopen("mjesta.txt", "r");
    fb = fopen("mjesta.dat", "wb+");
    // Početak datoteke
    fseek(f, 0, SEEK_SET);
    fseek(fb, 0, SEEK_SET);
    // Prebaci podatke
    br = 0;
    while (fscanf(f, "%[^,],%d,%[^\n] ", pom.mjesto, &pom.pbr, pom.opcina) != EOF) {
        fwrite(&pom, sizeof(zapis), 1, fb);
        br++;
    }
    fclose(f);
    fclose(fb);
    printf("Ukupno: %d zapisa", br);

    brojzapisa_velicina_brojanjem();
}