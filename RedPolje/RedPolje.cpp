/* RedPoljem.c */
#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>

/***** IMPLEMENTACIJA REDA POLJEM **************/

#define MAXRED 5

typedef struct {
	int polje[MAXRED];
	int ulaz;
	int izlaz;
} Red;

void init(Red *red) {
	red->ulaz = 0;
	red->izlaz = 0;
}

int dodaj(Red* red, int element) {
	if ((red->ulaz +1)%MAXRED == red->izlaz)
		return 0;
	red->ulaz = (red->ulaz + 1) % MAXRED;
	red->polje[red->ulaz] = element;
	return 1;
}
int skini(Red* red, int *element) {
	if (red->izlaz == red->ulaz)
		return 0;
	red->izlaz = (red->izlaz + 1) % MAXRED;
	*element = red->polje[red->izlaz];
	return 1;
}

void ispis(Red* red) {
	int element = NULL;
	Red pom;
	init(&pom);

	printf("\nRed: izlaz ->");
	while (skini(red, &element)) {
		printf("%3d", element);
		dodaj(&pom, element);
	}
	printf(" <- ulaz");
	while (skini(&pom, &element))
		dodaj(red, element);
}

// Zadatak 1. Napisati funkcija koja vraća element s početka reda
int zaviri(Red* red, int *element) {
	int p;
	Red pom; init(&pom);

	// Ovdje pisati kod

	return 1;
}

// Zadatak 2. Veličina reda
int velicina(Red* red)
{
	int br = 0;
	int elem;
	Red pom;
	init(&pom);

	// Ovdje pisati kod

	return br;
}

// Zadatak 3. Napisati funkciju koja briše red?
void prazni(Red* red) {
	int element;

	// Ovdje pisati kod
}

void main() {
	int element;
	Red red;
	init(&red);
	dodaj(&red, 5);
	dodaj(&red, 11);
	dodaj(&red, 15);
	dodaj(&red, 3);

	// Ispis
	ispis(&red);

	//Izbaci jedan element iz reda
	skini(&red, &element);
	printf("\n\nIzbacujem %d", element);
	ispis(&red);

	//Dodaj novi elemnet
	printf("\n\nDodaj 14");
	dodaj(&red, 14);
	ispis(&red);

	//Zadatak 1.
	if(zaviri(&red, &element))
		printf("\n\nNa pocetku reda je element %d", element);
	else
		printf("\n\nRed je prazan");

	// Zadatak 2
	printf("\n\nBroj elemenata: %d", velicina(&red));
	ispis(&red);

	// Zadatak 3
	prazni(&red);
	printf("\n\nRed je prazan");
	ispis(&red);

	getchar();
}