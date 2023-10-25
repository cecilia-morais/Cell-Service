#include <stdio.h>
#include <stdlib.h>
#include "pecas.h"

char estoque(){
    system("clear || cls");
    char opest;
    printf("*********************************************************************\n");
    printf("                          ESTOQUE DE PEÇAS                           \n");
    printf("*********************************************************************\n");
    printf("1 - Cadastrar uma nova peça\n");
    printf("2 - Buscar uma peça \n");
    printf("3 - Atualizar uma peça \n");
    printf("4 - Deletar uma peça \n");
    printf("0 - Sair \n");
    printf("*********************************************************************\n");
    printf("\n");
    printf("Digite o número desejado: \n");
    scanf("%c", &opest);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();

    return opest;
}

char nova_peca(){
    char peca[30];
    char marca[20];
    int estoque[5];
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                        CADASTRAR UMA NOVA PEÇA                      \n");
    printf("*********************************************************************\n");
    printf("Digite o nome da peça a ser cadastrada:\n ");
    fgets(peca, sizeof(peca), stdin);
    printf("Digite a marca do aparelho que recebe a peça(EM CASO DE PEÇA UNIVERSAL, COLOCAR 'TODAS'): \n");
    fgets(marca, sizeof(marca), stdin);
    printf("Digite o estoque de peças:\n ");
    fgets(estoque, sizeof(estoque), stdin);
    printf("Tecle ENTER para continuar \n");
    getchar();
}

char buscar_peca(){
    char peca[30];
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                           BUSCAR POR PEÇA                           \n");
    printf("*********************************************************************\n");
    printf("Digite o nome da peça: \n ");
    fgets(peca, sizeof(peca), stdin);
    printf("Tecle ENTER para continuar \n");
    getchar();

}
char atual_peca(){
    char peca[30];
    int estoque[5];
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                         ATUALIZAR UMA PEÇA                          \n");
    printf("*********************************************************************\n");
    printf("Digite o nome da peça:\n ");
    fgets(peca, sizeof(peca), stdin);
    printf("Digite a quantidade de peças a serem adicionadas ao estoque: \n");
    fgets(estoque, sizeof(estoque), stdin);
    printf("Tecle ENTER para continuar \n");
    getchar();
}

char excl_peca(){
    char peca[30];
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                         DELETAR UMA PEÇA                            \n");
    printf("*********************************************************************\n");
    printf("Digite o nome da peça:\n ");
    fgets(peca, sizeof(peca), stdin);
    printf("Tem certeza que quer continuar a operação? ");
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}