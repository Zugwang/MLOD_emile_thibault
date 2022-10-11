#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>


int est_parfait(int N){

    int sum = 0;

    for (int i = 1 ; i < N ; i++){
        if ( (N % i) == 0){
            //printf("%d \n",i);
            sum += i;
            
        }
    }

    if (sum == N){
        //printf("Est parfait \n");
        return 1;
    }else{
        //printf("Est pas parfait \n");

        return 0;
    }
}

void tous_les_parfaits(int N){
    for (int i = 0 ; i <= N ; i++) {
        if ( est_parfait(i) ) {
            printf("%d \n",i);
        }
    }
}

typedef short TypeEntier;

TypeEntier factorielle(TypeEntier nbre){
    int res = 1;
    for (int i = 1 ; i <= nbre ; i++){
        res *= i;
    }
    return res;
}

int main(void){

    printf("Q1 \n");

    tous_les_parfaits(1000);

    printf("Q2-factorielle \n");
    printf("%d \n" , factorielle(5)) ;

    return 0;

}