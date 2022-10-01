#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int mostra_matriz(int *algo){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            printf("%i - ",*algo);
            if (j==4){
                printf("\n"); }
            algo++; 
        }
    }
}

int calcu_espaco_sem_bomba(){ // fazer a funcao certinha
    return 1; } 

int func_atualiza_matriz_jogo(){ // fazer a funcao certinha
    return 0;
}

int main(){
    int matriz_bombas[5][5];
    int matriz_jogador[5][5] = {0}; //pra começar tudo zerado
    int num_bombas = 0;
    int espaco_sem_bombas = 0;
    int valor_x, valor_y;
    srand(time(NULL));
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            matriz_bombas[i][j] = rand()%101; // pra criar numeros de 0 a 99
            if (matriz_bombas[i][j] > 20){
                matriz_bombas[i][j] = 2;
                espaco_sem_bombas += 1;
            } else {
                matriz_bombas[i][j] = 1;
                num_bombas += 1;
            }
        }
    }
    { // mostrar as matrizes
    printf("Matriz Bombas: \n");
    mostra_matriz(*matriz_bombas);
    printf("Matriz Jogo: \n");
    mostra_matriz(*matriz_jogador);
    printf("Numero de bombas restantes: %i \n\n", num_bombas);
    }

    while(num_bombas > 0){
        printf("Qual valor de [x] vc quer? ");
        scanf("%i", &valor_x);
        printf("Qual valor de [y] vc quer? ");
        scanf("%i", &valor_y);
        if(matriz_bombas[valor_y-1][valor_x-1] == 1){
            printf("Bomba achada! \n Game Over");
            return 0;
        } else if(calcu_espaco_sem_bomba() == 2) { // = 2 só pra dar errado por enquanto
            return 0;
        } else{     
            printf("Espaco vazio! \n");
            // func_atualiza_matriz_jogo
            espaco_sem_bombas -= 1;
        }
    }
    return 0;
}