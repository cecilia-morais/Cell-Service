#include <stdio.h>
#include <stdlib.h>
#include "relatorios.h"

void relatorios(){
    system("clear || cls");
    int oprel;
    printf("*********************************************************************\n");
    printf("                            RELATÓRIOS                               \n");
    printf("*********************************************************************\n");
    printf("Pressione o número desejado para imprimir o relátorio de: \n ");
    printf("1 - Celular\n ");
    printf("2 - Cliente\n");
    printf("3 - Estoque de peças\n ");
    scanf("%d", &oprel);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}