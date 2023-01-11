#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct c {
	int broj;
	struct c *sljed;
}cvor;

typedef struct {
	cvor *vrh;
}Stog;

cvor *novicvor(int broj) {
	cvor *pom = (cvor *)malloc(sizeof(cvor));
	if (pom == NULL)
		return NULL;
	pom->broj = broj;
	pom->sljed = 0;
	return pom;
}

int init(Stog *stog) {
	stog->vrh = NULL;
	return 1;
}

int dodaj(Stog *stog, int element) {
	cvor *pom = novicvor(element);
	if (pom == NULL)
		return 0;
	pom->sljed = stog->vrh;
	stog->vrh = pom;
	return 1;
}

int skini(Stog *stog, int *element) {
	if (stog->vrh == NULL)
		return 0;
	cvor *pom = stog->vrh;
	stog->vrh = pom->sljed;
	*element = pom->broj;
	free(pom);
	return 1;
}

void ispis(Stog* stog) {
	int element = NULL;
	Stog pom;
	init(&pom);
	if (skini(stog, &element)) {
		printf("\n\nvrh ->%3d", element);
		dodaj(&pom, element);
	}
	else
		printf("\n\nvrh -> NULL");
	while (skini(stog, &element)) {
		printf("\n%9d", element);
		dodaj(&pom, element);
	}
	while (skini(&pom, &element))
		dodaj(stog, element);
}


// Zadatak 1. Napisati funkciju koja vraća broj elemenata u stogu?
int brojElemenata(Stog* stog) {
	int br = 0;
	int elem;
	Stog pom;
	init(&pom);
	
	// Ovdje pisati kod

	return br;
}


// Zadatak 2. Napisati funkciju koja vraća ukupan zbroj svih elemenata na stogu?
int zbrojElemenata(Stog* stog) {
	int zbroj = 0;
	int elem;
	Stog pom;
	init(&pom);

	// Ovdje pisati kod

	return zbroj;
}

// Zadatak 3. Napisati funkciju koja izbacuje najveći element sa stoga?
void izbaciMax(Stog* stog) {
	Stog pom;
	init(&pom);
	int element;
	int max;

	// Ovdje pisati kod
}

// Zadatak 4. Napisati funkciju koja briše stog?
void prazni(Stog* stog) {
	int element;

	// Ovdje pisati kod
}

void main() {
	Stog stog;
	init(&stog);
	dodaj(&stog, 5);
	dodaj(&stog, 10);
	dodaj(&stog, 15);
	dodaj(&stog, 3);

	// Ispis
	ispis(&stog);

	// Zadatak 1
	printf("\n\nBroj elemenata: %d", brojElemenata(&stog));

	// Zadatak 2
	printf("\nSuma: %d", zbrojElemenata(&stog));

	// Zadatak 3
	izbaciMax(&stog);
	ispis(&stog);

	// Zadatak 4
	prazni(&stog);
	ispis(&stog);

	getchar();
}