#include <stdio.h>
#include <stdlib.h>
#include "celular.h"

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

char novo_cell(){
    int nCPF[12];
    char modelo[20];
    char marca[15];
    char problema[100];
    char dataent[9];
    char previsao[9];
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                       CADASTRAR UM NOVO CELULAR                     \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    fgets(nCPF, sizeof(nCPF), stdin);
    printf("Digite o modelo do aparelho: \n");
    fgets(modelo, sizeof(modelo), stdin);
    printf("Digite a marca do aparelho:\n ");
    fgets(marca, sizeof(marca), stdin);
    printf("Digite o problema do aparelho: \n");
    fgets(problema, sizeof(problema), stdin);
    printf("Digite a data de entrada do aparelho:\n ");
    fgets(dataent, sizeof(dataent), stdin);
    printf("Digite a previsão de entrega do aparelho\n");
    fgets(previsao, sizeof(previsao), stdin);
    printf("Tecle ENTER para continuar \n");
    getchar();
}

char busca_cell(){
    int nCPF[12];
    char modelo[20];
    char marca[15];
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                 BUSCAR CELULAR CADASTRADO POR CLIENTE               \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    fgets(nCPF, sizeof(nCPF), stdin);
    printf("Digite o modelo do aparelho: \n");
    fgets(modelo, sizeof(modelo), stdin);
    printf("Digite a marca do aparelho:\n ");
    fgets(marca, sizeof(marca), stdin);
    printf("Tecle ENTER para continuar \n");
    getchar();


}

char atual_cell(){
    int nCPF[12];
    char modelo[20];
    char marca[15];
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                         ATUALIZAR UM CELULAR                        \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    fgets(nCPF, sizeof(nCPF), stdin);
    printf("Digite o modelo do aparelho: \n");
    fgets(modelo, sizeof(modelo), stdin);
    printf("Digite a marca do aparelho:\n ");
    fgets(marca, sizeof(marca), stdin);
    printf("Tecle ENTER para continuar \n");
    getchar();
}

char excl_cell(){
    int nCPF[12];
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                         DELETAR UM CELULAR                          \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    fgets(nCPF, sizeof(nCPF), stdin);
    printf("Tecle ENTER para continuar \n");
    getchar();
}