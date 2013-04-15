
/* inclusion de la d�claration du type concret ELEMENT */
#include "ElementStructureChoisie.h"


/* Lit un �l�ment */
void ElementLire(ELEMENT *);

/* affiche un �l�ment */
void ElementAfficher(ELEMENT);

/* affecte le deuxieme argument dans le premier
qui est donc modifi� et pass� par adresse */
ELEMENT ElementAffecter(ELEMENT*, ELEMENT);

/* retourne 1 si les deux arguments sont identiques */
int ElementIdentique(ELEMENT, ELEMENT);

/* 	compare 2 entiers e1 et e2 pass�s en param�tres
	retourne un entier > 0  si e1 > e2 
	retourne 0 si e1 = e2
	retourne un entier < 0 si e1 < e2 */
int ElementComparer(ELEMENT, ELEMENT);



/* Primitives inutiles pour le stockage direct, Mais obligatoire en
   stockage indirect */

/* cr�e un �l�ment vide   */
ELEMENT ElementCreer() ;

/* d�truit un �l�ment */
void ElementDetruire(ELEMENT) ;