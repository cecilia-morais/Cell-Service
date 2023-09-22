#include <stdio.h>
#include <stdlib.h>
#include "celular.h"

char cad_cell(){
    system("clear || cls");
    char opcel;
    printf("*********************************************************************\n");
    printf("                          CADASTRO DE CELULAR                        \n");
    printf("*********************************************************************\n");
    printf("1 - Cadastrar um novo celular\n");
    printf("2 - Buscar um celular \n");
    printf("3 - Atualizar um celular\n");
    printf("4 - Deletar um celular\n");
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

char novo_cell(){
system("clear || cls");
    printf("*********************************************************************\n");
    printf("                       CADASTRAR UM NOVO CELULAR                     \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    getchar();
    printf("Digite o modelo do aparelho: \n");
    getchar();
    printf("Digite a marca do aparelho:\n ");
    getchar();
    printf("Digite o problema do aparelho: \n");
    getchar();
    printf("Digite a data de entrada do aparelho:\n ");
    getchar();
    printf("Digite a previsão de entrega do aparelho\n");
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}

char busca_cell(){
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                 BUSCAR CELULAR CADASTRADO POR CLIENTE               \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    getchar();
    printf("Digite o modelo do aparelho: \n");
    getchar();
    printf("Digite a marca do aparelho:\n ");
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();


}

char atual_cell(){
    system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                         ATUALIZAR UM CELULAR                        \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    getchar();
    printf("Digite o modelo do aparelho: \n");
    getchar();
    printf("Digite a marca do aparelho:\n ");
    printf("Tecle ENTER para continuar \n");
    getchar();
}

char excl_cell(){
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                         DELETAR UM CELULAR                          \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}