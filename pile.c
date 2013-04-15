#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ElementPrimitives.h" /**** attention � mettre les include � jour dans votre projet */
#include "pile.h" 	/**** attention � mettre les include � jour dans votre projet */

/* cr�e une file : renvoie juste un pointeur NULL */
PILE PileCreer(){
	return (PILE_VIDE);
}

/* indique si la file est vide c'est � dire si le pointeur est NULL */
int PileVide (PILE p){
	return (p == PILE_VIDE);
}

/* ajoute une element au sommet de la pile */
void PileEmpiler (PILE *p, ELEMENT element) {
	PILE p_sommet = PileCreer();
	PileSommet(p); // se positionne au sommet de la pile
	p_sommet = (PILE)malloc(sizeof(PILE));
	if (!PileVide(p_sommet)) {
		p_sommet->element = element;
		p_sommet->precedent = NULL; // pas d'�l�ment pr�c�dent, car c'est le sommet
		p_sommet-> suivant = *p;
		if (!PileVide(*p)) { // on raccroche l'ancienne pile
			(*p)-> precedent = p_sommet;
		} 
		*p = p_sommet;
	} else {
		printf("memoire insuffisante \n");
	}
}

/* renvoie la element de l'�l�ment au somet de la pile, mais ne modifie pas la pile */
ELEMENT PileValeurSommet (PILE *p) {
	if (!PileVide(*p)) {
		ELEMENT i;
		PileSommet(p);
		i = (*p)->element;
		return i;
	} else {
		return ELEMENT_VIDE;
	}
}

/* supprime l'�l�ment au sommet de la pile */
void PileDepiler(PILE *p) {
	
	PILE p_temp;
	PileSommet(p); // se place au sommet de la pile
	if (!PileVide(*p)) {
		p_temp = (*p)->suivant;
		if (!PileVide(p_temp)) {
			p_temp->precedent = NULL; 
			*p = PILE_VIDE ;// compilateur 
			free(*p); 
			*p = p_temp; // devient le sommet
		}
		else {
			// la pile ne contenait qu'un �lement
			*p = PILE_VIDE;// compilateur 
			free(*p); 
			*p = PILE_VIDE ;// r�initialise
		}
	}
}

/* renvoie la element de l'�l�ment au somet de la pile, etmodifie pas la pile */
ELEMENT PilePop (PILE *p) {
	ELEMENT e = PileValeurSommet(p);
	PileDepiler(p);
	return e;
}

/* positionne le pointeur au sommet de la pile */
void PileSommet (PILE *p){
	if (! PileVide(*p)){
		while (PilePrecedent(p)) // se d�place successivement sur chaque �l�ment "pr�cedent"
		{}
	}
}

/* si c'est possible, d�place le pointeur sur le "pr�c�dent" de l'�l�ment point� et renvoie 1
 sinon, renvoie 0.
 */
int PilePrecedent (PILE *p){
	if (!PileVide(*p) && !PileVide((*p)->precedent)) {
		*p = (*p)->precedent;
		return(1);
	} else {
		return(0);
	}
}

/* d�truit tous les �l�ments de la file */
void PileDetruire (PILE *p){
	while (! PileVide(*p)) {
		PileDepiler(p);
	}
}

/*
 * Affiche la pile
 */
void PileAfficher (PILE *p) {
    
    PILE pile = *p;
    
    PileSommet(&pile);
    
    printf("|   | \n");
    
    while (pile != NULL)
    {
        printf("|");
        ElementAfficher(pile->element);
        printf("| \n");
        pile = pile->suivant;
    }
    printf("|___| \n");
}