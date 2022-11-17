#include <stdio.h>

int trazi(int trazeni)
{
    FILE* f = fopen("brojevi.dat", "r");

    bool pronadjen = false;
    int br;
    int sredina;
    int poc = 0;

    fseek(f, 0, SEEK_END);
    int kraj = ftell(f) / sizeof(int);

    do {
        // Ovdje pisati kod
        printf("\nTrazim u a[%2d:%2d], a[%2d]=%2d", poc, kraj, sredina, br);

    } while (poc <= kraj);

    return pronadjen ? 1 : 0;
}

int main() {

    FILE* f, * fb;
    int br;
    f = fopen("brojevi.txt", "r");
    fb = fopen("brojevi.dat", "w+");

    // Ovdje napisati kod

    fclose(f);
    fclose(fb);

    printf("\nPronadjen = %d", trazi(5));
}