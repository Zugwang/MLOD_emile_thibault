#include <stdlib.h>
#include <stdio.h>


enum Mois 
{
	Janvier, Fevrier, Mars, Avril, Mai ,Juin, Juillet, Aout, Septembre, Octobre, Novembre, Decembre
};

typedef enum Mois Mois;

struct Date
{
	unsigned int Jour;
	unsigned int Mois;
	unsigned int Annee;
};

typedef struct Date Date;


void initialiseDate(Date* date) {

    printf("Jour: ");
    scanf("%d", &date->Jour);
    

    printf("Mois: ");
    scanf("%d", &date->Mois);
    
    printf("Annee: ");
    scanf("%d", &date->Annee);
}


void afficheDate(Date *d){

    printf("%d / %d / %d \n", d->Annee, d->Mois, d->Jour);
}

Date creerDateParCopie(){
    Date d;

    printf("Jour: ");
    scanf("%d", &d.Jour);
    

    printf("Mois: ");
    scanf("%d", &d.Mois);
    
    printf("Annee: ");
    scanf("%d", &d.Annee);

    return d;
}

Date *newDate(void){

    Date *d = malloc(sizeof(Date));

    printf("Jour: ");
    scanf("%d", &d->Jour);
    

    printf("Mois: ");
    scanf("%d", &d->Mois);
    
    printf("Annee: ");
    scanf("%d", &d->Annee);

    return d;
}

// (e) 


int main(void){

    Date d;
    initialiseDate(&d);
    afficheDate(&d);
    printf("test\n");

    Date d2;
    d2 = creerDateParCopie();
    afficheDate(&d2);
    printf("test\n");

    Date *d3;
    d3 = newDate();
    afficheDate(d3);

    printf("test\n");

    return 0;
}

