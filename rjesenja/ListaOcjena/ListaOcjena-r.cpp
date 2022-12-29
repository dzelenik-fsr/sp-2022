#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct c {
	int mbr;
	char ime_prezime[14 + 1];
	int ocjena;
	struct c* sljed;
} cvor;

cvor* novicvor(int mbr, const char* ime_prezime, int ocjena) {
	cvor* pom = (cvor*)malloc(sizeof(cvor));
	if (pom == NULL)
		return NULL;
	pom->mbr = mbr;
	strcpy(pom->ime_prezime, ime_prezime);
	pom->ocjena = ocjena;
	pom->sljed = NULL;
	return pom;
}

int dodaj(cvor** glava, cvor *novi) {
	cvor* pom = *glava;
	if (novi == NULL)
		return -1;

	if (*glava == NULL) {
		*glava = novi;
		return 1;
	}

	// Trazi kraj
	while (pom->sljed != 0)
		pom = pom->sljed;

	// Dodaj na kraj
	pom->sljed = novi;
	return 1;
}

void ispis(cvor* glava, const char red = 'm') {
	cvor* pom = glava;
	printf("\n*glava\n%#4c\n", 25);
	while (pom != NULL) {
		if (red == 'm') {
			printf("|%.3s:%1d| %c ", pom->ime_prezime, pom->ocjena, 26);
			pom = pom->sljed;
		}
		else {
			printf("%s %c ", pom->ime_prezime, 26);
			pom = pom->sljed;
		}
	}
	printf("null\n");
}

// Napisati funkciju koja briše sve jedinice
void brisi(cvor** glava) {
	cvor* pom = *glava;
	cvor* pp = pom;
	cvor* tmp;
	while (pom)
	{
		// Brišem čvor
		if (pom->ocjena == 1) {
			// Brišem prvi u listi
			if (pom == *glava)
				*glava = pom->sljed;
			else
				pp->sljed = pom->sljed;
			tmp = pom;
			pom = pom->sljed;
			free(tmp);
		}
		else {
			pp = pom;
			pom = pom->sljed;
		}
	}
}


void main() {

	//132 PETROVIC
	//111 ZANIC
	//981 HORVAT
	//114 MARKOVIC

	cvor* glava = NULL;

	cvor* p1 = novicvor(132, "PETROVIC", 1);
	cvor* p2 = novicvor(111, "ZANIC", 2);
	cvor* p3 = novicvor(981, "HORVAT", 3);
	cvor* p4 = novicvor(301, "MARKOVIC", 1);
	cvor* p5 = novicvor(432, "ANIC", 5);

	// Dodaj po matičnom broju
	dodaj(&glava, p1);
	dodaj(&glava, p2);
	dodaj(&glava, p3);
	dodaj(&glava, p4);
	dodaj(&glava, p5);

	printf("\nLista");
	ispis(glava);

	// Brišem jedinice
	printf("\nBrisem jedinice");
	brisi(&glava);
	ispis(glava);
}