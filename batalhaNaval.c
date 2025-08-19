#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    int tabuleiro [10][10];
    int tamanhoNavio = 3;

    //Inicializando o tabuleiro com água (0).
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            tabuleiro[i][j] = 0;
        }
    }

    //Coordenadas fixas dos navios.
    //Navio horizontal começa na linha 4, coluna 2.
    //Navio vertical começa na linha 7, coluna 5.
    int navioLinhaX = 2, navioColunaX = 4;
    int navioLinhaY = 5, navioColunaY = 7;

    //Posicionando o navio horizontal.
    if (navioColunaX + tamanhoNavio <= 10) {
        for (int j = 0; j < tamanhoNavio; j++){
            tabuleiro[navioLinhaX][navioColunaX + j] = 3;
        }
    } else {
        printf("Erro! Navio horizontal não cabe no tabuleiro!\n");
    }
    
    //Posicionando o navio vertical.
    if (navioLinhaY + tamanhoNavio <= 10) {
        for (int i = 0; i < tamanhoNavio; i++) {
            //Validando se já existe navio naquela posição.
            if (tabuleiro[navioLinhaY + i][navioColunaY] == 0) {
                tabuleiro[navioLinhaY + i][navioColunaY] = 3;
            } else {
                printf("Erro: sobreposição de navios!\n");
                break;
            }
        }
    } else {
        printf("Erro: navio vertical não cabe no tabuleiro!\n");
    }

    //Exibindo o tabuleiro.
    printf("\n **** TABULEIRO BATALHA NAVAL **** \n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
