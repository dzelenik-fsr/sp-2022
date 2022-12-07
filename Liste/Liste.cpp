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

void ispis(cvor* glava) {
	while (glava != NULL) {
		printf("\n%d", glava->broj);
		glava = glava->sljed;
	}
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


void main() {
	cvor* glava = NULL;
	glava = novicvor(2);
}