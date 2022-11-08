#include "echangeContenu.h"

void echangeContenu(int *x , int *y){
    int z = *x;
    *x = *y;
    *y = z;
}