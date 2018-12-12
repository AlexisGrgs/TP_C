#include <stdio.h>
#include <stdlib.h>
#define SIZE 800

int main()
{
	double * tab;
	int i;
	tab = (double*) malloc(sizeof(double)*SIZE);
	for(i=0; i<SIZE; i++)
	{
		tab[i] = i*i;
		printf("%f\n",tab[i]);
	}
	
	free(tab);
	
	return 0;
}
