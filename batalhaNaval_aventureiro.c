#include <stdio.h>

#define TAM 10  //Tamanho do tabuleiro 10x10
#define NAVIO 3 //Tamanho fixo dos navios (3 posições)
#define MAR 0   //Representação da água
#define NAV 3   //Representação do navio

    int main() {
        int tabuleiro[TAM][TAM];

        //Iniciando o tabuleiro com água
        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                tabuleiro[i][j] = MAR;
            }
        }

        //Coordenadas fixas dos navios
        //Navio horizontal, vertical e diagonal.
        int linhaX = 2, colunaX = 4;
        int linhaY = 5, colunaY = 7;
        int linhaD1 = 3, colunaD1 = 3;
        int linhaD2 = 0, colunaD2 = TAM - 1;

        //Posicionamento navio horizontal
        if (linhaX + NAVIO <= TAM) {
            for (int j = 0; j < NAVIO; j++) {
                if (tabuleiro[linhaX][colunaX + j] ==MAR) {
                    tabuleiro[linhaX][colunaX + j] = NAV;
                }
            }
        } else {
            printf("Erro: navio horizontal fora dos limites!\n");
        }

        //Posicionando navio vertical
        if (linhaY + NAVIO <= TAM) {
            for (int i = 0; i < NAVIO; i++) {
                if (tabuleiro[linhaY + i][colunaY] == MAR) {
                    tabuleiro[linhaY + i][colunaY] = NAV;
                }
            }
        } else { 
            printf("Erro: navio diagonal principal fora dos limites!\n");
        }

        //Posicionando navio diagonal principal
        if (linhaD1 + NAVIO <= TAM && colunaD1 + NAVIO <= TAM) {
            for (int i = 0; i < NAVIO; i++){
                if(tabuleiro[linhaD1 + i][colunaD1 + i] == MAR) {
                    tabuleiro[linhaD1 + i][colunaD1 + i] = NAV;
                    }
                }
        } else { 
            printf("Erro: navio diagonal principal fora dos limites!\n");
        }

        //Posicionando navio diagonal secundário
        if (linhaD2 + NAVIO <= TAM && colunaD2 - (NAVIO -1) >= 0) {
            for (int i = 0; i < NAVIO; i++) {
                if (tabuleiro[linhaD2 + i][colunaD2 - i] == MAR) {
                    tabuleiro[linhaD2 + i][colunaD2 - i] = NAV;
                }
            }
        } else {
            printf("Erro: navio diagonal secundário fora dos limites!\n");
        }

        //Exibição do tabuleiro
        printf("\n **** TABULEIRO BATALHA NAVAL **** \n");
        for (int i = 0; i < TAM; i++) {
            for (int j = 0; j < TAM; j++) {
                    printf("%d ", tabuleiro[i][j]);
            }
            printf("\n");

        }

    return 0;
}