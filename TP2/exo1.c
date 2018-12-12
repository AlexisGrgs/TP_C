#include <stdio.h>
#include <stdlib.h>

void echangeParValeur( int a, int b);
void echangeParAdresse( int* a, int* b);

int main()
{
	int i = 5;
	int j = 7;
	echangeParValeur(i,j);
	printf("Echange par valeur : \n");
	printf("a : %d / b : %d \n", i, j);
	echangeParAdresse(&i,&j);
	printf("Echange par adresse : \n");
	printf("a : %d / b : %d \n", i, j);
	return 0;
}

void echangeParValeur( int a, int b)
{
	int k = a;
	a = b;
	b = k;
}

void echangeParAdresse( int* a, int* b)
{
	int k = *a;
	*a = *b;
	*b = k;
}
