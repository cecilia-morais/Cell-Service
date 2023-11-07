#include <stdio.h>
#include <stdlib.h>
#include "celular.h"
#include "validacoes.h"

Celulares* cell;

char cad_cell(){
    system("clear || cls");
    char opcel;
    printf("*********************************************************************\n");
    printf("                          ÁREA DE CELULAR                             \n");
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

Celulares* novo_cell(){
    system("clear || cls");
    cell = (Celulares*)malloc(sizeof(Celulares));
    printf("*********************************************************************\n");
    printf("                       CADASTRAR UM NOVO CELULAR                     \n");
    printf("*********************************************************************\n");
    ler_cpf(cell->cpf);
    printf("Digite o modelo do aparelho: \n");
    fgets(cell->modelo, sizeof(cell->modelo), stdin);
    printf("Digite a marca do aparelho:\n ");
    fgets(cell->marca, sizeof(cell->marca), stdin);
    printf("Digite o problema do aparelho: \n");
    fgets(cell->problema, sizeof(cell->problema), stdin);
    printf("Tecle ENTER para continuar \n");
    getchar();
}


void busca_cell(){
    char cpf[12];
    char modelo[20];
    char marca[15];
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                 BUSCAR CELULAR CADASTRADO POR CLIENTE               \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    fgets(cpf, sizeof(cpf), stdin);
    printf("Digite o modelo do aparelho: \n");
    fgets(modelo, sizeof(modelo), stdin);
    printf("Digite a marca do aparelho:\n ");
    fgets(marca, sizeof(marca), stdin);
    printf("Tecle ENTER para continuar \n");
    getchar();
}


void atual_cell(){
    char cpf[12];
    char modelo[20];
    char marca[15];
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                         ATUALIZAR UM CELULAR                        \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    fgets(cpf, sizeof(cpf), stdin);
    printf("Digite o modelo do aparelho: \n");
    fgets(modelo, sizeof(modelo), stdin);
    printf("Digite a marca do aparelho:\n ");
    fgets(marca, sizeof(marca), stdin);
    printf("Tecle ENTER para continuar \n");
    getchar();
}

 excl_cell(){
    char cpf[12];
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                         DELETAR UM CELULAR                          \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    fgets(cpf, sizeof(cpf), stdin);
    printf("Tecle ENTER para continuar \n");
    getchar();
}