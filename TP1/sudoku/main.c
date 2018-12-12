#include <stdio.h>
#define N 9
#define HORIZ 0
#define VERT 1

int initialiser(int grille[N][N]);
int afficher(int grille[N][N]);
void generer(int grille[N][N], int* remplissage);
void saisir(int grille[N][N], int* remplissage);

int main ()
{
	int grille[N][N];
	int remplissage = 0 ;
	initialiser(grille);
	generer(grille, &remplissage);
	printf("SUDOKU\n");
	afficher(grille);
	
	return 0;
}

int initialiser(int grille[N][N])
{
	int i, j;
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			grille[i][j] = 0;
		}
	}
	
	return 0;
}

int afficher(int grille[N][N])
{
	int i, j;
	printf("-------------------------------\n");
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			if(j%3==0)
			{
				printf("| %d ", grille[i][j]);
			}
			else
			{
				printf(" %d ", grille[i][j]);
			}
			if(j==N-1)
				printf("|");
		}
		if((i+1)%3==0)
			{
				printf("\n-------------------------------\n");
			}
		else
		{
			printf("\n");
		}
		
			
	}

	return 0;
}

void generer(int grille[N][N], int* remplissage)
{
	int res = 0;
	int i, j;


		for(i=0;i<9; ++i)
		{
			for(j=0; j<9; ++j)
			{	
			 	grille[j][i] = (i + j*3 +j /3) %9 +1 ;
			}
		}

		
	
	for(i=0; i<N; i++)
	{
		for(j=0; j<N; j++)
		{
			if(!grille[i][j]) res++;
		}
	}
	
	*remplissage = res;
	
}

void saisir(int grille[N][N], int* remplissage)
{
	int i , j, valeur;
	printf("Saisir la ligne :\n");
	scanf("%d", &i);
	printf("Saisir la colonne :\n");
	scanf("%d", &j);
	printf("Saisir la valeur :\n");
	scanf("%d", &valeur);
	
	if ( i < 9 && i > -1 && j < 9 && j>-1 && !grille[i][j]) 
	{
		grille[i][j] = valeur;
		(*remplissage)++;
	}
}


