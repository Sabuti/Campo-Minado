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
    /*
    int num_bombas_escolha = 0;
    for(int i = valor_x-1; i <= valor_x+1; i++){
        for(int j = valor_y-1; j <= valor_y+1; j++){
            if(matriz_bombas[i][j] == 15){
                num_bombas_escolha += 1;                     // calcula quant de bombas em volta
                if (i == valor_x && j == valor_y){
                    num_bombas_escolha -= 1;                 // ignora se posi = bomba (mudar para game over)
                }
            }
        }
    } */
    return 0;
} 

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
    printf("Numero de bombas restantes: %i \n", num_bombas);
    printf("Numero de espacos livres restantes: %i \n\n", espaco_sem_bombas);
    }

    while(num_bombas > 0){
        printf("Qual valor de [x] vc quer? ");
        scanf("%i", &valor_x);
        printf("Qual valor de [y] vc quer? ");
        scanf("%i", &valor_y);
        if(matriz_bombas[valor_x][valor_y] == 1){
            printf("Bomba achada! \n Game Over");
            return 0;
        } else if(calcu_espaco_sem_bomba() == 2) { // = 2 só pra dar errado por enquanto
            return 0;
        } else{     
            printf("\nEspaco vazio! \n\n");
            int num_bombas_escolha = 0;
            for(int i = valor_x-1; i <= valor_x+1; i++){
                for(int j = valor_y-1; j <= valor_y+1; j++){
                    if(matriz_bombas[i][j] == 1){
                        num_bombas_escolha += 1;                     // calcula quant de bombas em volta
                        if (i == valor_x && j == valor_y){
                            num_bombas_escolha -= 1;                 // ignora se posi = bomba (mudar para game over)
                        }
                    }
                }
            } 
            espaco_sem_bombas -= 1;
            matriz_jogador[valor_x][valor_y] = num_bombas_escolha;
        }
        // mostra_matriz(*matriz_jogador);
        for (int i = 0; i < 5; i++){
            for (int j = 0; j < 5; j++){
                printf("%i - ",matriz_jogador[i][j]);
                if (j==4){
                    printf("\n"); }
            }
        }
        printf("\nNum de espacos vazios = %i \n", espaco_sem_bombas);
    }
    return 0;
}