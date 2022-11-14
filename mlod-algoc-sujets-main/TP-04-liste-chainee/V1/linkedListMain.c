#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void  afficheElement(Element e){
    printf("%s", (char *)e);
    printf("\n");
}

void detruireElement(Element e){ }

bool equalsElement(Element e1, Element e2){
    if(strcmp(e1,e2)==0){
        return true;
    }else{
        return false;
    }
}

int main(void){
    Liste l;

    l = NULL;
    printf("Vide ? : %s\n",estVide(l)?"OUI":"NON");

    l = ajoutTete("You",l);
    l = ajoutTete("is",l);
    l = ajoutTete("Baba",l);

    afficheListe_i(l);

    printf("hello");

    return EXIT_SUCCESS;
}