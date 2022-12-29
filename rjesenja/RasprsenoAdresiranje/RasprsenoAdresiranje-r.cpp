#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

//Parametri
#define MAXZAPIS 100
#define BLOK 512
#define C (int)(BLOK/sizeof(zapis))
#define M (int) ((MAXZAPIS/C) * 1.3)

//Struktura
typedef struct {
	int sifra;
	char naziv[50 + 1];
	float cijena;
}zapis;

int adresa(int sifra) {
	return sifra % M;
}

int upis(FILE* f, int adr, zapis pom)
{
	zapis pretinac[C];

	int poc = adr;
	int i;
	i = poc;

	do {
		fseek(f, i * BLOK, SEEK_SET);
		fread(pretinac, sizeof(pretinac), 1, f);
		for (int j = 0; j < C; j++) {
			if (pretinac[j].sifra == pom.sifra) {
				return 0;
			}if (pretinac[j].sifra == 0) {
				pretinac[j] = pom;
				fseek(f, i * BLOK, SEEK_SET);
				fwrite(pretinac, sizeof(pretinac), 1, f);
				return 1;
			}
		}
		i = (i + 1) % M;
	} while (i != poc);
	return 0;
}

int prepisi(char* izlaz, char* ulaz)
{
	FILE* fizlaz, * fulaz;
	if ((fizlaz = fopen(izlaz, "wb+")) == NULL)
		return -1;
	if ((fulaz = fopen(ulaz, "r")) == NULL)
		return -1;

	//Format
	zapis pret[C];
	fseek(fizlaz, 0, SEEK_SET);
	for (int i = 0; i < C; i++)
		pret[i].sifra = 0;

	for (int i = 0; i < M; i++) {
		fseek(fizlaz, i * BLOK, SEEK_SET);
		fwrite(pret, sizeof(pret), 1, fizlaz);
	}

	zapis pom;
	int adr;
	while (fscanf(fulaz, "%d,%[^,],%f", &pom.sifra, &pom.naziv, &pom.cijena) != EOF)
	{
		adr = adresa(pom.sifra);
		printf("\n%d %d %s %.2f", adr, pom.sifra, pom.naziv, pom.cijena);
		upis(fizlaz, adr, pom);
	}

	fclose(fizlaz);
	fclose(fulaz);
	return 1;
}


void parametri() {
	printf("\n\nParametri");
	printf("\nM = %d", M);
	printf("\nC = %d", C);
	printf("\nzapis = %d", sizeof(zapis));
}

void ispisiDatoteku(FILE* f)
{
	zapis pretinac[C];
	int br = 0;
	printf("\n\nDatoteka\n");
	for (int i = 0; i < M; i++)
	{
		fseek(f, i * BLOK, SEEK_SET);
		fread(pretinac, sizeof(pretinac), 1, f);
		for (int j = 0; j < C; j++)
		{
			printf("%03d ", pretinac[j].sifra);
		}
		printf("\n");
	}
}


// Zadatak 1
int brojZapisa(FILE* f)
{
	zapis pretinac[C];
	int br = 0;
	for (int i = 0; i < M; i++)
	{
		fseek(f, i * BLOK, SEEK_SET);
		fread(pretinac, sizeof(pretinac), 1, f);
		for (int j = 0; j < C; j++)
		{
			if (pretinac[j].sifra != 0)
				br++;
		}
	}
	return br;
}

// Zadatak 2
int pronadji(FILE* f, int sifra) {
	int i = adresa(sifra);
	int poc = i;

	zapis pom[C];
	do {
		fread(pom, sizeof(pom), 1, f);
		for (int j = 0; j < C; j++)
		{
			if (pom[j].sifra == sifra)
				return 1;
		}
		poc = (poc + 1) % M;
	} while (poc != i);
	return 0;
}

// Zadatak 3
float gustoca(const char* ime_datoteke)
{
	return 0.0;
}

// Zadatak 4
void format(FILE* f)
{
	zapis pom[C];

	for (int j = 0; j < C; j++)
		pom[j].sifra = 0;

	for (int i = 0; i < M; i++)
	{
		fseek(f, i * BLOK, SEEK_SET);
		fwrite(pom, sizeof(pom), 1, f);
	}
}

int main()
{
	char fin[] = "artikli.txt";
	char fout[] = "artikli.dat";

	prepisi(fout, fin);

	FILE* f = fopen(fout, "rb+");
	if (f == NULL)
		return -1;

	parametri();
	ispisiDatoteku(f);

	return 1;
}