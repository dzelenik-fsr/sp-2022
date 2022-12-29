#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct c {
	int broj;
	struct c* sljed;
}cvor;

cvor* novicvor(int broj) {
	cvor* pom;
	pom = (cvor*)malloc(sizeof(cvor));
	if (pom == NULL)
		return NULL;
	pom->broj = broj;
	pom->sljed = NULL;
	return pom;
}

int randomGen(int minValue = 0, int maxValue = 10)
{
	int random = rand() % ((maxValue + minValue) + minValue);
	return random;
}

cvor* kreirajListu(int brojElemenata, int minValue = 0, int maxValue = 10) {
	cvor* glava, * pom, * novi;
	glava = pom = novicvor(randomGen(minValue, maxValue));
	if (glava == NULL)
		return NULL;
	for (int i = 1; i < brojElemenata; i++) {
		novi = novicvor(randomGen(minValue, maxValue));
		if (novi == NULL)
			break;
		pom->sljed = novi;
		pom = novi;
	}
	return glava;
}

// Zadatak 1
int dodaj(cvor* glava, int broj) {
	while (glava->sljed != 0)
		glava = glava->sljed;
	glava->sljed = novicvor(broj);
	return 1;
}

// Zadatak 2
int brojElemenata(cvor* glava) {
	int br = 0;
	while (glava != NULL)
	{
		br++;
		glava = glava->sljed;
	}
	return br;
}

// Zadatak 3
int izbrisiPrvi(cvor** glava) {
	cvor* pom = *glava;
	*glava = pom->sljed;
	free(pom);
	return 1;
}

// Zadatak 4
void uvecaj(cvor* glava, int p) {
	while (glava != NULL) {
		glava->broj = glava->broj + p;
		glava = glava->sljed;
	}
}

// Zadatak 5 - Napisati funkciju koja spaja dvije liste M i L.
// Rezultate je lista M' koja sadrži sve čvorove liste M, iza kojih slijede čvorovi liste L
cvor *spoji(cvor* glavaM, cvor* glavaL) {
	// Ovdje pisati kod
	cvor* pom = glavaM;
	if (pom == NULL)
		return glavaL;
	while (pom->sljed)
		pom = pom->sljed;
	pom->sljed = glavaL;
	return  glavaM;
}

// Zadatak 6
// Napisati rekurzivnu funkciju koja računa elemenata u listi
int brojElemenataR(cvor* glava) {
	// Ovdje pisati kod
	if (glava)
		return 1 + brojElemenataR(glava->sljed);
	return 0;
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
	printf("\nUkupno: %d\n", brojElemenata(glava));
}

int main() {
	int br;
	cvor* glava = kreirajListu(5);
	printf("# Lista");
	ispis(glava);

	br = 10;
	printf("\n# z1. Dodaj %d na kraj", br);
	dodaj(glava, br);
	ispis(glava);

	printf("\n# z3. Izbrisi prvi");
	izbrisiPrvi(&glava);
	ispis(glava);

	br = 3;
	printf("\n# z4. Uvecaj sve za %d", br);
	uvecaj(glava, br);
	ispis(glava);

	printf("\n# z5. Spoji");
	cvor* nova = kreirajListu(3);
	printf("\n# Nova lista");
	ispis(nova);
	printf("\n# Stara lista");
	ispis(glava);
	printf("\n# Nova lista + Stara lista");
	cvor *tmp = spoji(nova, glava);
	ispis(tmp);

	printf("\n# z6. Broj elemenata rekurzivno");
	printf("\nBroj elemenata: %d\n", brojElemenataR(glava));

	return 1;
}