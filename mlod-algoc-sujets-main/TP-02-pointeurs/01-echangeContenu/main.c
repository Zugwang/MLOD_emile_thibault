#include <stdio.h>
//#include "echangeContenu.h"

void echangeContenu(int *x , int *y){
    int z = *x;
    *x = *y;
    *y = z;
}

#define SIZE 5

void matrix_print(int64_t mat[SIZE][SIZE]){
	for (int i = 0 ; i < SIZE ; i++){
		printf("\n");
		for (int j = 0 ; j < SIZE ; j++){
			printf("%d", mat[i][j]);
			printf("  ");
		}
	}	
	printf("\n");

}


void matrix_mult(int64_t matRes[SIZE][SIZE] , int64_t mat1[SIZE][SIZE], int64_t mat2[SIZE][SIZE]){

	for (int i = 0 ; i < SIZE ; i++){
		for (int j = 0 ; j < SIZE ; j++){
			matRes[i][j] = 0;
			for (int h = 0 ; h < SIZE ; h++){
				matRes[i][j] += mat1[i][h]*mat2[h][j];
			}
		}
	}
}


int main(void)
{
	int a=4,b=14;

	printf ("a = %d\tb = %d\n", a, b);

	echangeContenu(&a,&b);

	printf ("a et b echanges \n");
	printf ("a = %d\tb = %d\n", a, b);

	int64_t matrice1[][SIZE]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
	int64_t matrice2[][SIZE]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};

	int64_t matriceResultat[SIZE][SIZE];

	matrix_mult(matriceResultat, matrice1,matrice2);
	matrix_print(matrice1);

	matrix_print(matriceResultat);


	return 0;
}

