#include <stdio.h>
#include <stdlib.h>

void swap(char* p1, char*p2);

int main()
{
   int i  , *ptri  = &i;
   char c1 = '1', *ptrc1 = &c1;
   char c2 = '2', *ptrc2 = &c2;
   double d2, *ptrdb = &d2;

   
   printf("INT : \n Valeur pointée : %d\n Adresse contenue dans le pointeur : %p\n Adresse du pointeur : %p\n", i, ptri, &ptri);
   printf("CHAR : \n Valeur pointée : %c\n Adresse contenue dans le pointeur : %p\n Adresse du pointeur : %p\n", c1, ptrc1, &ptrc1);
   printf("DOUBLE : \n Valeur pointée : %f\n Adresse contenue dans le pointeur : %p\n Adresse du pointeur : %p\n", d2, ptrdb, &ptrdb);

   /*ptrdb+=2;
   printf("DOUBLE : \n Valeur pointée : %f\n Adresse contenue dans le pointeur : %p\n Adresse du pointeur : %p\n", d2, ptrdb, &ptrdb);*/
   
   printf("CHAR1 : \n Valeur pointée : %c\n Adresse contenue dans le pointeur : %p\n Adresse du pointeur : %p\n", c1, ptrc1, &ptrc1);
   printf("CHAR2 : \n Valeur pointée : %c\n Adresse contenue dans le pointeur : %p\n Adresse du pointeur : %p\n", c2, ptrc2, &ptrc2);
   swap(ptrc1,ptrc2);
   printf("CHAR1 : \n Valeur pointée : %c\n Adresse contenue dans le pointeur : %p\n Adresse du pointeur : %p\n", c1, ptrc1, &ptrc1);
   printf("CHAR2 : \n Valeur pointée : %c\n Adresse contenue dans le pointeur : %p\n Adresse du pointeur : %p\n", c2, ptrc2, &ptrc2);
   return 0 ;
}

void swap(char* p1, char* p2)
{
	char k = *p1;
	*p1 = *p2;
	*p2 = k;
}
