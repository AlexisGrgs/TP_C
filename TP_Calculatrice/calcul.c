#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define TRUE 1
#define FALSE 0




const char * OPER_NAMES[] = { "x", "sin(x)", "cos(x)", "log(x)", "exp(x)", NULL };

typedef enum ope {
  ID , SIN, COS, LOG, EXP, NONE
} OP;

OP identification(char* chaine);
double evaln(double nb, OP oper);
void calcul(double a, double b, double delta, OP oper);

int main()
{

	double born_inf;
	double born_sup;
	double delta;
	char str[10];
	printf("Entrez la fonction : \n");
	scanf("%s", str);
	printf("Entrez la borne inferieure : \n");
	scanf("%lf", &born_inf);
	printf("Entrez la borne superieure : \n");
	scanf("%lf", &born_sup);
	printf("Entrez le delta : \n");
	scanf("%lf", &delta);
	calcul(born_inf, born_sup, delta, identification(str));
	return 0;
}

OP identification(char* chaine)
{
	int i = 0;
	int found = FALSE;
	OP oper = ID;
	
	while(oper != NONE && !found)
	{
		if(strcmp(OPER_NAMES[i],chaine)==0)
		{
			found = TRUE;
		}
		i++;
		oper++;
	}
	
	return --oper;
}

double evaln(double nb, OP oper)
{
	double retour;
	switch(oper)
	{
		case ID:
			retour = nb;
			break;
		case SIN:
			retour = sin(nb);
			break;
		case COS:
			retour = cos(nb);
			break;
		case LOG:
			retour = log(nb);
			break;
		case EXP:
			retour = exp(nb);
			break;
		default:
			printf("Cette opération n'existe pas !!\n FATAL ERROR :\n");
			printf(" Extinction de la calculatrice\n");
			exit(0);
			break;
	}
}

void calcul(double a, double b, double delta, OP oper)
{
	for (a; a<=b; a+=delta)
	{
		printf("f(%f) = %f\n",a,evaln(a,oper));
	}

}
