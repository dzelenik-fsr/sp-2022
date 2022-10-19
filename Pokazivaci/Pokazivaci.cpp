#include <stdio.h>
#include <conio.h>

/*****************************************************************
	Uvećava vrijednost varijable na koju pokazuje pokazivač [*a]
	za iznos zadan u agrumentu [uvecanje]
*****************************************************************/
void uvecaj(int* a, int uvecanje)
{
	// Ovdje pisati kod
}

/*****************************************************************
	Preusmjerava pokazivač [**pa] na adresu koja je zadana u [*b]
*****************************************************************/
void preusmjeri(int** pa, int* b)
{
	// Ovdje pisati kod
}

int main()
{
	int a = 5;
	int b = 10;
	int* pa;

	// Ispis
	printf("\n&a=%p a=%d", &a, a);
	printf("\n&b=%p b=%d", &b, b);

	// Spremi adresu varijable [a] u pokazivač [*pa]
	pa = &a;

	// Ispis
	printf("\n&pa=%p  pa=%p  *pa=%d", &pa, pa, *pa);

	// Uvećaj [a]
	uvecaj(&a, 5);

	// Preusmjeri pokazivač [*pa] na varijablu [b]
	preusmjeri(&pa, &b);

	getch();

	return 1;
}