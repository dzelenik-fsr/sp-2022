#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

/*****************************************************************
	Funkcija koja ispisuje brojeve od 1 do 100
*****************************************************************/
void funkcija1(int n) {
	if (n <= 5) {
		funkcija1(n + 1);
		printf("\n%d", n);
	}
}

/*****************************************************************
	Funkcija koja ispisuje brojeve od 100 do 1
*****************************************************************/
void funkcija2(int n) {
	if (n <= 5) {
		printf("\n%d", n);
		funkcija2(n + 1);
	}
}

/*****************************************************************
	Funkcija koja ispisuje brojeve od 1 do 100 i 100 do 1 
*****************************************************************/
void funkcija3(int n) {
	if (n <= 5) {
		printf("\n%d", n);
		funkcija3(n + 1);
		printf("\n%d", n);
	}
}

/*****************************************************************
	Funkcija koja ispisuje brojeve od [a] do [b]
*****************************************************************/
void funkcija4(int a, int b) {
	// Ovdje napisati kod
	if (a <= b) {
		printf("%d", a);
		funkcija4(a + 1, b);
	}
}

/*****************************************************************
	Funkcija koja vraća sumu brojeva od od [a] do [b]
*****************************************************************/
int suma(int a, int b) {
	// Ovdje napisati kod
	if (a <= b) {
		printf("%d", a);
		return a + suma(a + 1, b);
	}
	return 0;
}


/*****************************************************************
	Funkcija koja znamenke broja u obrnutom redoslijedu
*****************************************************************/
void funkcija5(int n) {
	// Ovdje napisati kod
	if (n > 0) {
		printf("%d", n % 10);
		funkcija5(n / 10);
	}
}

/*****************************************************************
	Funkcija niz znakova obrnutim redolijedom
*****************************************************************/
void obrnuto(char* niz, int d) {
	// Ovdje napisati kod
	if (d > 0) {
		printf("%c", niz[d-1]);
		obrnuto(niz, d - 1);
	}
}

/*****************************************************************
	Funkcija niz znakova obrnutim redolijedom
*****************************************************************/
void obrnuto2(char* niz){
	// Ovdje napisati kod
	if (*niz != '\0') {
		printf(niz++);
		printf("%c", *niz);
	}
}

int main() {
	char niz[] = "Strukture";
	//int rez = suma(2, 5);
	//printf("Suma je %d", rez);

	funkcija5(345);

	int d = strlen(niz);
	obrnuto(niz, d);
	obrnuto2(niz);
}