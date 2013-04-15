
/* d�finition des primitives du type concret ELEMENT caract�re */

#include <stdio.h>
#include "ElementPrimitives.h"

/* Lit un �l�ment */
void ElementLire(ELEMENT * elt)	{
	char c;
	scanf("%c",&c);
	fflush(stdin);
	*elt = c;
}

/* affiche un �l�ment */
void ElementAfficher(ELEMENT elt)	{
	printf(" %c ",elt);
}

/* affecte le deuxieme argument dans le premier
qui est donc modifi� et pass� par adresse */
ELEMENT ElementAffecter(ELEMENT * e1, ELEMENT e2)   {
	return  *e1 = e2  ;
}

/* retourne 1 si les deux arguments sont identiques */
int ElementIdentique(ELEMENT e1, ELEMENT e2)  {
	return 	e1 == e2 ;
}

/* 	compare 2 entiers e1 et e2 pass�s en param�tres
	retourne un entier > 0  si e1 > e2 
	retourne 0 si e1 = e2
	retourne un entier < 0 si e1 < e2 */
int ElementComparer(ELEMENT e1, ELEMENT e2)  {
  return(e1 - e2) ;
}

/* cr�e un �l�ment vide   */
ELEMENT ElementCreer () {
	return ELEMENT_VIDE ;
}

/* d�truit un �l�ment */
void ElementDetruire (ELEMENT e) {
}
