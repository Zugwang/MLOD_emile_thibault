/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring < turingWinners.txt > out.txt

 Tests
 diff out.txt turingWinners.txt

 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* This function scans a line of text (until \n) and returns a char* that contains all characters on the line (up to 255) excluding \n.
It also ensures the \0 termination.
**WARNING**: The result of this function has been allocated (calloc) by the function */
char* scanLine()
{
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize+1,sizeof(char));

	scanf("%250[^\n]", line);

	if ( (c = getchar()) != '\n') {
		/* we did not get all the line */
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		// line[255] = '\0'; // useless because already initialized by calloc

		// let's skip all chars untli the end of line
		while (( (c = getchar()) != '\n') && c != EOF) ;
	}

	return line;
}

/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt() {
	int buf;
	scanf("%i\n",&buf);
	return buf;
}

typedef struct {
	int annee;
	char *gagnant;
	char *sujet;

} GagnantTuring;

void sortTuringWinnerByYear(GagnantTuring *tab_appelle, int nbGagnants){

	GagnantTuring intermediaire;
	for (int i=0 ; i<nbGagnants ; i++){
    	for(int j=i+1 ; j <= nbGagnants;j++){
			if(tab_appelle[i].annee > tab_appelle[j].annee){
				intermediaire = tab_appelle[i];
				tab_appelle[i] = tab_appelle[j];
				tab_appelle[j] = intermediaire;

			}
		}
	}
}

GagnantTuring *readWinners(int nbGagnants ){

	GagnantTuring *tab;
	tab = malloc(nbGagnants * sizeof(GagnantTuring));
	

	for (int i = 0 ; i < nbGagnants ; i++){

		tab[i].annee = scanLineAsInt();
		tab[i].gagnant = scanLine();
		tab[i].sujet = scanLine();
	}

	printf("A lu\n");
	return tab;
}

void printWinners(GagnantTuring *tab_appelle, int taille){

	printf("Taille =%d", taille);

	for (int i = 0 ; i < taille ; i ++){
		printf("L'année : %d \n",tab_appelle[i].annee);
		printf("Le gagnant était ");
		printf("%s",tab_appelle[i].gagnant);
		printf("\n");
		printf("%s",tab_appelle[i].sujet);
		printf("\n");

	}
}

void infosAnnee(GagnantTuring *tab_appelle, int annee, int nbGagnants){
	int a = 1;
	for(int i = 0 ; i < nbGagnants ; i++){
		if (tab_appelle[i].annee == annee){
			printf("L'annee %d le gagnant a été %s \n", annee, tab_appelle[i].gagnant);
			printf("Nature du prix : %s", tab_appelle[i].sujet);
			a = 0;
		}
	}

	if (a){
		printf("Année non correcte");
	}
}

void LET_BE_FREEEEEEEEEE(GagnantTuring *tab_appelle, int nbGagnants){
	for(int i = 0 ; i < nbGagnants ; i++){

		free(tab_appelle[i].gagnant);
		free(tab_appelle[i].sujet);
	}

	free(tab_appelle);
}


int main(int argc, char *argv[]	)
{
	
	int nbGagnants = scanLineAsInt();
	printf("nbGagnants = %i\n",nbGagnants);

	GagnantTuring *test = readWinners(nbGagnants);
	//printWinners(test,nbGagnants);

	if ( (argc > 0) && (argv[1] = "infosAnnee") ){
		int annee_r = atoi(argv[2]);
		infosAnnee(test, annee_r, nbGagnants);
	}

	if (argc > 2){
		//sortTuringWinnerByYear(&test, nbGagnants);
	}

	sortTuringWinnerByYear(test,nbGagnants);

	printWinners(test, nbGagnants);

	LET_BE_FREEEEEEEEEE(test, nbGagnants);

	return EXIT_SUCCESS;
}
