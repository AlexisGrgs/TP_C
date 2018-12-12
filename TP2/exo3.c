#include <stdio.h>
#include <stdlib.h>

int compter1(char * chaine);
int compter2(char * chaine);
int compter3(char * chaine);

int main()
{
   //int tab[] = {0,1,2,3,4,5};
   char *chaine = (char*) malloc(50);
	/*int  * p1;
   char * p2;
   
   printf("%lu %lu %lu\n", sizeof(char), sizeof(int), sizeof(double));

   

   p1 = tab;
   ++p1;
   printf("%d ", *p1);

   p2 = (char *) p1;
   p2 += sizeof(int);

   printf("%d\n", *((int*)p2));
   printf("%d\n", *(p1+6));

   p1 = NULL;
   printf("%d\n", *p1);*/
   scanf("%s", chaine);
   printf("%s\n", chaine);
   printf("longueur : %d\n", compter3(chaine));
   return 0;
}

int compter1(char * chaine)
{
  int i = 0;

  while (*(chaine+i) != '\0')
     ++i;

  return i;
}

int compter2(char * chaine)
{
  char * s = chaine;

  while (*chaine != '\0')
     ++chaine;

  return chaine - s;
}

int compter3(char * chaine)
{
  char * s = chaine;

  while (*chaine++);

  return chaine - s -1;
}
