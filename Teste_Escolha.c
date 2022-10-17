#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int montrar_matrizes(int tamanho){
    int valor_x, valor_y;
    int num_bombas = 0;
    int espaco_sem_bombas = 0;
    int matriz_bombas[valor_x][valor_y];
    int matriz_jogador[valor_x][valor_y]; //pra começar tudo zerado
    if (tamanho == 1){
        printf("\nOpcao escolhida = Principiante \n");
        valor_x = 9;
        valor_y = 9;
    } else if (tamanho == 2){
        printf("\nOpcao escolhida = Intermedio \n");
        valor_x = 16;
        valor_y = 16;
    } else if (tamanho == 3){
        printf("\nOpcao escolhida = Especialista \n");
        valor_x = 16;
        valor_y = 30;
    } else {
        printf("\nOpcao escolhida = Personalizado \n");
        printf("Qual quantidade de linhas vc quer? ");
        scanf("%i",&valor_x);
        printf("Qual quantidade de colunas vc quer? ");
        scanf("%i",&valor_y);
    }
    srand(time(NULL));
    for (int i = 0; i < valor_x; i++){
        for (int j = 0; j < valor_y; j++){
            matriz_bombas[i][j] = rand()%180; // pra criar numeros de 0 a 180
            if (matriz_bombas[i][j] >= 20){
                matriz_bombas[i][j] = 2;
                printf("%i - ",matriz_bombas[valor_x][valor_y]);
                espaco_sem_bombas += 1;
            } else {
                matriz_bombas[i][j] = 1;
                printf("\n");
                num_bombas += 1;
            }
        }
    }
    for (int i = 0; i < valor_x; i++){
        for (int j = 0; j < valor_y; j++){
            //printf("%i - ",matriz_bombas[valor_x][valor_y]);
            if (j==valor_y-1){
                printf("\n"); }
        }
    }
}

int main(){
    int opcao, escolhido;
    printf("\t\tBem vindo ao Campo Minado!!\n\n");
    printf("Dificuldades do Campo possiveis:\n1 - Principiante (09x09) - 2 - Intermedio (16x16)\n");
    printf("3 - Especialista (16x30) - 4 - Personalizado \n");
    printf("E ai, qual vc quer? ");
    scanf("%i",&opcao);
    montrar_matrizes(opcao);
    printf("1 - Palpite\n2 - Marcar bomba\n3 - Sair\nQual opcao vc deseja? ");
    scanf("%i", &opcao);
    do {
        if (opcao == 1){
            printf("Bom palpite\n");
        } else if (opcao == 2){
            printf("Bomba marcada\n");
        } else {
            printf("Nada escolhido\n");
        }
        printf("1 - Palpite\n2 - Marcar bomba\n3 - Sair\nQual opcao vc deseja? ");
        scanf("%i", &opcao);
    } while (opcao != 3);
    return 0;
}