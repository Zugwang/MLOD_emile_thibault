#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

#define TODO NULL;

// retourne vrai si l est vide et faux sinon
bool estVide(Liste l) {
	return (l == NULL);
}

// créer une liste d'un seul élément contenant la valeur v
Liste creer(Element v){
	Liste list = malloc(sizeof(Cellule));
	if( list != NULL){
		list->val = v;
		list->suiv = NULL;
	}
	
	return list;
}


// ajoute l'élément v en tete de la liste l
Liste ajoutTete(Element v, Liste l) {

	if (l == NULL){
		return creer(v);
	}

	Liste nvl_list = malloc(sizeof(Cellule));

	nvl_list->val = v;
	nvl_list->suiv = l;
	
	return nvl_list;
}


// affiche tous les éléments de la liste l
// Attention, cette fonction doit être indépendante du type des éléments de la liste
// utiliser une fonction annexe affiche_element
// Attention la liste peut être vide !
// version itérative
void afficheListe_i(Liste l) {
	if(estVide(l)){
		printf("none");
		return;
	}

	Liste l_parcours = l;

	while (l_parcours->suiv != NULL)
	{
		afficheElement(l_parcours->val);
		l_parcours = l_parcours->suiv;
	}
	afficheElement(l_parcours->val);
}

// version recursive
void afficheListe_r(Liste l) {
	TODO;
}

// Détruit tous les éléments de la liste l
// version itérative
void detruire_i(Liste l) {
	Liste suivant, actuel = l;

	while(!estVide(actuel)){
		suivant = actuel->suiv;
		detruireElement(actuel->val);
		free(actuel);
		actuel = suivant;
	}
}

// version récursive
void detruire_r(Liste l) {
	Liste suivant = l->suiv;
	detruireElement(l->val);
	free(l);
	if(!estVide(suivant)){
		detruire_r(suivant);
	}


}

// retourne la liste dans laquelle l'élément v a été ajouté en fin
// version itérative
Liste ajoutFin_i(Element v, Liste l) {
	Liste parcours = l;
	Liste new = creer(v);

	if(estVide(l)){
		return new;
	}

	while(parcours->suiv != NULL){
		parcours = parcours->suiv;
	}
	parcours->suiv=new;

	return l;

}

// version recursive
Liste ajoutFin_r(Element v, Liste l) {
	
	if(estVide(l)){
		return creer(v);
	}else{
		l->suiv = ajoutFin_r(v,l->suiv);
	}
	return l;
}


// Retourne un pointeur sur l'élément de la liste l contenant la valeur v ou NULL
// version itérative
Liste cherche_i(Element v,Liste l) {
	
	while(l->val != v){
		if(l->suiv == NULL){
			return NULL;
		}
		l = l->suiv;
	}
	return l;
}

// version récursive
Liste cherche_r(Element v,Liste l) {
	if(l == NULL || equalsElement(v, l->val)){
		return l;
	}else{
		return cherche_r(v,l->suiv);
	}
}

// Retourne la liste modifiée dans la laquelle le premier élément ayant la valeur v a été supprimé
// ne fait rien si aucun élément possède cette valeur
// version itérative
Liste retirePremier_i(Element v, Liste l) {
	Liste preced, p;

	if(estVide(l))
		return l;
	
	if(equalsElement(l->val,v)){
		p = l->suiv;
		l->suiv = NULL;
		detruire_r(l);
		return p;
	}
	preced = l;
	p = l->suiv;
	

	while(l->val != v){
		if(l->suiv == NULL){
			return NULL;
		}
		preced = l;
		l = l->suiv;
	}

	preced->suiv = l->suiv;
	free(l);
	detruireElement(v);
	

	return l;

}


// version recursive
Liste retirePremier_r(Element v, Liste l) {
	if(estVide(l))
		return l;
	
	if(equalsElement(l->val,v)){
		Liste p = l->suiv;
		l->suiv = NULL;
		detruire_r(l);
		return p;
	}

	l->suiv = retirePremier_r(v,l->suiv);
	return l;
}


void afficheEnvers_r(Liste l) {
	if(!estVide(l)){ 
		if(!estVide(l->suiv)){
			afficheEnvers_r(l->suiv);
		}
		afficheElement(l->val);
		printf("	");
	}
	return;
}