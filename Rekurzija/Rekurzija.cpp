#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

/*****************************************************************
	Funkcija koja ispisuje brojeve od 1 do 100
*****************************************************************/
void funkcija1(int n) {
	if (n <= 100) {
		funkcija1(n + 1);
		printf("\n%d", n);
	}
}

/*****************************************************************
	Funkcija koja ispisuje brojeve od 100 do 1
*****************************************************************/
void funkcija2(int n) {
	if (n <= 100) {
		printf("\n%d", n);
		funkcija2(n + 1);
	}
}

/*****************************************************************
	Funkcija koja ispisuje brojeve od 1 do 100 i 100 do 1 
*****************************************************************/
void funkcija3(int n) {
	// Ovdje napisati kod
}

/*****************************************************************
	Funkcija koja ispisuje brojeve od [a] do [b]
*****************************************************************/
void funkcija4(int a, int b) {
	// Ovdje napisati kod
}

/*****************************************************************
	Funkcija koja vraća sumu brojeva od od [a] do [b]
*****************************************************************/
int suma(int a, int b) {
	// Ovdje napisati kod
	return 1;
}


/*****************************************************************
	Funkcija koja znamenke broja u obrnutom redoslijedu
*****************************************************************/
void funkcija5(int n) {
	// Ovdje napisati kod
}

/*****************************************************************
	Funkcija niz znakova obrnutim redolijedom
*****************************************************************/
void obrnuto(char* niz, int d) {
	// Ovdje napisati kod
}

/*****************************************************************
	Funkcija niz znakova obrnutim redolijedom
*****************************************************************/
void obrnuto2(char* niz){
	// Ovdje napisati kod
}

int main() {
	char niz[] = "Strukture";
	funkcija1(1);
}