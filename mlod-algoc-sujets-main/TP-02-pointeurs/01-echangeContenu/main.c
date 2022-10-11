#include <stdio.h>
//#include "echangeContenu.h"

void echangeContenu(int *x , int *y){
    int z = *x;
    *x = *y;
    *y = z;
}

#define SIZE 5

void matrix_mult()


int main(void)
{
	int a=4,b=14;

	printf ("a = %d\tb = %d\n", a, b);

	echangeContenu(&a,&b);


	printf ("a et b echanges \n");
	printf ("a = %d\tb = %d\n", a, b);

	return 0;
}

