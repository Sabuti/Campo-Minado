#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
int faz_matriz(int algo){
    /*
    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            printf("%i [%i][%i] - ",algo[i], i,j);
            if (j==5){
                printf("\n");
            }
        }
    }
}*/

int main(){
    int matriz[5][5];
    int valor;
    srand(time(NULL));
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            matriz[i][j] = rand()%101; // pra criar numeros de 0 a 99
        }
    }
    //faz_matriz(matriz);

    for (int i = 0; i < 6; i++){
        for (int j = 0; j < 6; j++){
            printf("%i [%i][%i] - ",matriz[i][j], i,j);
            if (j==5){
                printf("\n");
            }
        }
    }
    return 0;
}