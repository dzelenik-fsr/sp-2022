#include <stdio.h>
#include <stdlib.h>

typedef struct c {
	int broj;
	struct c* sljed;
}cvor;


cvor* novicvor(int broj) {
	cvor* pom = (cvor*)malloc(sizeof(cvor));
	pom->broj = broj;
	pom->sljed = 0;
	return pom;
}

// Zadatak 1
int dodaj(cvor* glava, int broj) {
	// Ovdje pisati kod
	return 1;
}

// Zadatak 2
int brojElemenata(cvor* glava) {
	int br = 0;
	// Ovdje pisati kod
	return br;
}

// Zadatak 3
int izbrisiPrvi(cvor** glava) {
	// Ovdje pisati kod
	return 1;
}

// Zadatak 4
void uvecaj(cvor* glava, int p) {
	// Ovdje pisati kod
}

// Zadatak 5 - Napisati funkciju koja spaja dvije liste M i L.
// Rezultate je lista M' koja sadrži sve čvorove liste M, iza kojih slijede čvorovi liste L
void spoji(cvor* glavaM, cvor* glavaL) {
	// Ovdje pisati kod
}

// Zadatak 6
// Napisati rekurzivnu funkciju koja računa elemenata u listi
void brojCvorovaR(cvor* glava) {
	// Ovdje pisati kod
}

// Zadatak 7
// Napisati program koji mijenja dva čvora u listi (ne samo vrijednost)
void zamjena(cvor* glava, int a, int b) {
	// Ovdje pisati kod
}

void ispis(cvor* glava) {
	cvor* pom = glava;
	printf("\n*glava\n%#4c\n  ", 25);
	while (pom != NULL) {
		printf("%#2d %c ", pom->broj, 26);
		pom = pom->sljed;
	}
	printf("NULL");
	printf("\nBroj elemenata: %d\n", brojElemenata(glava));
}

void main() {
	int br;
	cvor* glava = 0;
	glava = novicvor(2);
	dodaj(glava, 3);
	dodaj(glava, 15);

	printf("# Lista");
	ispis(glava);

	br = 10;
	printf("\n# Dodaj %d", br);
	dodaj(glava, br);
	ispis(glava);

	printf("\n# Izbrisi prvi");
	izbrisiPrvi(&glava);
	ispis(glava);

	br = 3;
	printf("\n# Uvecaj sve za %d", br);
	uvecaj(glava, br);
	ispis(glava);
}