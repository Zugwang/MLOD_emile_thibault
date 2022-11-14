#include <stdio.h>
#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <string.h>

void afficheElement(Element e){
    Musique *musique = (Musique *)e;
    printf("%s,", musique->name);
    printf("%s,", musique->artist);
    printf("%s,", musique->album);
    printf("%s,", musique->genre);
    printf("%s,", musique->discNumber);
    printf("%s,", musique->trackNumber);
    printf("%s", musique->year);
    printf("\n");
}

void detruireElement(Element e){
    Musique *music = (Musique *)e;

    free(music->name);
    free(music->genre);
    free(music->album);
    free(music->artist);
    free(music->discNumber);
    free(music->trackNumber);
    free(music->year);
    free(music);

    e = NULL;

    return;
}

// test d'egalité
bool equalsElement(Element e1, Element e2){
    Musique *music1 = (Musique *)e1;
    Musique *music2 = (Musique *)e2;

    if (strcmp(music1->name, music2->name) != 0){
        return false;
    }

    if (strcmp(music1->genre, music2->genre) != 0){
        return false;
    }

    if (strcmp(music1->album, music2->album) != 0){
        return false;
    }

    if (strcmp(music1->artist, music2->artist) != 0){
        return false;
    }

    if (strcmp(music1->discNumber, music2->discNumber) != 0){
        return false;
    }

    if (strcmp(music1->trackNumber, music2->trackNumber) != 0){
        return false;
    }

    if (strcmp(music1->year, music2->year) != 0){
        return false;
    }

    return true;
}

// lire le csv donnée en parametre
Liste readCSV(FILE *csv){
    Liste l;
    int tailleLigne = 256;
    l = NULL;
    Musique *musicTemp;
    char *line, *copy, *value, *tracer;
    line = calloc(tailleLigne, sizeof(char));

    while (fgets(line, tailleLigne, csv) != NULL){
        musicTemp = (Musique *)malloc(sizeof(Musique));
        copy = strdup(line);
        tracer = copy;

        value = strsep(&copy, ",\n");
        musicTemp->name = calloc(strlen(value) + 1, sizeof(char));
        strcpy(musicTemp->name, value);

        value = strsep(&copy, ",\n");
        musicTemp->artist = calloc(strlen(value) + 1, sizeof(char));
        strcpy(musicTemp->artist, value);

        value = strsep(&copy, ",\n");
        musicTemp->album = calloc(strlen(value) + 1, sizeof(char));
        strcpy(musicTemp->album, value);

        value = strsep(&copy, ",\n");
        musicTemp->genre = calloc(strlen(value) + 1, sizeof(char));
        strcpy(musicTemp->genre, value);

        value = strsep(&copy, ",\n");
        musicTemp->discNumber = calloc(strlen(value) + 1, sizeof(char));
        strcpy(musicTemp->discNumber, value);

        value = strsep(&copy, ",\n");
        musicTemp->trackNumber = calloc(strlen(value) + 1, sizeof(char));
        strcpy(musicTemp->trackNumber, value);

        value = strsep(&copy, ",\n");
        musicTemp->year = calloc(strlen(value) + 1, sizeof(char));
        strcpy(musicTemp->year, value);

        l = ajoutFin_i(musicTemp, l);
        free(tracer);
    }
    free(line);
    return l;
}

Liste triParAnnee(Liste l){
    if(estVide(l) || estVide(l->suiv)){
		return l;
	}

    Cellule *actu, *precedent, *ancien, *precedentAncien; 
    Musique *musiqueActu = actu->val; 
    Musique *musiqueprecedent = precedent->val; 
    Musique *musiqueAncien = ancien->val; 
    Musique *musiqueprecedentAncien = precedentAncien->val;

	actu = precedent = ancien = precedentAncien = l;

	while(!estVide(actu)){
		if(strcmp(musiqueActu->year, musiqueAncien->year) <= 0){
			precedentAncien = precedent;
			ancien = actu;
		}
		precedent = actu;
		actu = actu->suiv;
	}

	Liste temp;
	if(ancien != l){
		precedentAncien->suiv = l;
		temp = l->suiv;
		l->suiv = ancien->suiv;
		ancien->suiv = temp;
	}
	ancien->suiv = trierParAnnee(ancien->suiv);

	return ancien;
}
/// ///////////////////////////////////////////////////////
int main(void)
{
    FILE *fichierCsv;
    fichierCsv = fopen("music.csv", "r");
    Liste bibliotheque;

    bibliotheque = readCSV(fichierCsv);
    
    afficheListe_i(bibliotheque);

    detruire_i(bibliotheque);

    fclose(fichierCsv);

    return 0;
}