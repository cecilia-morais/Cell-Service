#include <stdio.h>
#include <stdlib.h>
#include "relatorios.h"

char relatorios(){
    system("clear || cls");
    char oprel;
    printf("*********************************************************************\n");
    printf("                            RELATÓRIOS                               \n");
    printf("*********************************************************************\n");
    printf("Pressione o número desejado para imprimir o relátorio de: \n ");
    printf("1 - Celular\n ");
    printf("2 - Cliente\n");
    printf("3 - Estoque de peças\n ");
    scanf("%c", &oprel);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}

