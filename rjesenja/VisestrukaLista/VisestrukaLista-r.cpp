#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

typedef struct c {
	int mbr;
	char prezime[14 + 1];
	struct c* smbr;
	struct c* sprez;
} cvor;

cvor* novicvor(int mbr, const char *prezime) {
	cvor* pom = (cvor*)malloc(sizeof(cvor));
	if (pom == NULL)
		return NULL;
	pom->mbr = mbr;
	strcpy(pom->prezime, prezime);
	pom->smbr = NULL;
	pom->sprez = NULL;
	return pom;
}

// Ispis liste
void ispis(cvor* glava, const char red = 'm') {
	cvor* pom = glava;
	printf("\n*glava\n%#4c\n  ", 25);
	while (pom != NULL) {
		if (red == 'm') {
			printf("%#2d %c ", pom->mbr, 26);
			pom = pom->smbr;
		}
		else {
			printf("%s %c ", pom->prezime, 26);
			pom = pom->sprez;
		}
	}
	printf("null\n");
}

// Dodavanje u listu
// sortiranu po rastucoj vrijednosti maticnog broja
void dodajMbr(cvor** glava, cvor* novi) {
	// ******************************************************** //
	// Traži mjesto za umetanje
	// 
	//    *glava	   pp   pom	    
	//	   ↓           ↓     ↓
	//	  [1] → [2] → [3] → [6] → [7] → NULL
	// 
	//            novi → [5]
	//
	// Izmjena pokazivača
	// 
	//  *glava	      pp  pom	    
	//	   ↓           ↓   ↓
	//	  [1] → [2] → [3] [6] → [7] → NULL
	//	            (2)↓   ↑(1)
	//           novi → [5]
	// ********************************************************* //

	cvor *pom = *glava;			// pom sadrzi adresu pokazivaca cvora
	cvor *pp = pom;

	// Novi ne postoji
	if (novi == NULL)
		return;

	while(pom) {
		if (novi->mbr > pom->mbr) {
			pp = pom;
			pom = pom->smbr;
		}
		else
			// Našao sam poziciju
			break;
	}
	novi->smbr = pom;		//  1. Korak
	if (*glava == pom)
		*glava = novi;		// Dodaj na početak
	else
		pp->smbr = novi;	//  2. Korak
}

// Dodavanje u listu
// sortiranu po rastucoj vrijednosti maticnog broja
void dodajPrezime(cvor** glava, cvor* novi) {

	cvor* pom = *glava;					// pom sadrzi adresu pokazivaca cvora
	cvor* pp = pom;

	// Novi ne postoji
	if (novi == NULL)
		return;

	// Traži poziciju
	while (pom) {
		if (strcmp(novi->prezime, pom->prezime) > 0) {
			pp = pom;
			pom = pom->sprez;
		}
		else
			// Našao sam poziciju
			break;
	}
	novi->sprez = pom;				//  1. Korak
	if (*glava == pom)				// Dodaj na početak
		*glava = novi;
	else
		pp->sprez = novi;			//  2. Korak
}

void main() {
	
	//132 PETROVIC
	//111 ZANIC
	//981 HORVAT
	//114 MARKOVIC

	cvor* glavaM = NULL;
	cvor* glavaP = NULL;

	cvor *p1 = novicvor(132, "PETROVIC");
	cvor *p2 = novicvor(111, "ZANIC");
	cvor *p3 = novicvor(981, "HORVAT");
	cvor *p4 = novicvor(301, "MARKOVIC");
	cvor* p5 = novicvor(432, "ANIC");

	// Dodaj po matičnom broju
	dodajMbr(&glavaM, p1);
	dodajMbr(&glavaM, p2);
	dodajMbr(&glavaM, p3);
	dodajMbr(&glavaM, p4);
	dodajMbr(&glavaM, p5);
	ispis(glavaM);

	// Dodaj po prezimenu
	dodajPrezime(&glavaP, p1);
	dodajPrezime(&glavaP, p2);
	dodajPrezime(&glavaP, p3);
	dodajPrezime(&glavaP, p4);
	dodajPrezime(&glavaP, p5);
	ispis(glavaP, 'p');
}