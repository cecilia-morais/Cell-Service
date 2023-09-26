#include <stdio.h>
#include <stdlib.h>
#include "atendimentos.h"

char area_atendimento(){
    system("clear || cls");
    char opcel;
    printf("*********************************************************************\n");
    printf("                            ATENDIMENTOS                             \n");
    printf("*********************************************************************\n");
    printf("1 - Cadastrar um novo atendimento\n");
    printf("2 - Buscar um atendimento \n");
    printf("3 - Atualizar um atendimento\n");
    printf("4 - Deletar um atendimento\n");
    printf("0 - Sair \n");
    printf("*********************************************************************\n");
    printf("\n");
    printf("Digite o número desejado: \n");
    scanf("%c", &opcel);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();

    return opcel;

}