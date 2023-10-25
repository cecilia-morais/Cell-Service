#include <stdio.h>
#include <stdlib.h>
#include "clientes.h"

char cad_clien(){
    system("clear || cls");
    char opcli;
    printf("*********************************************************************\n");
    printf("                          ÁREA DE CLIENTES                           \n");
    printf("*********************************************************************\n");
    printf("1 - Cadastrar um novo cliente\n");
    printf("2 - Buscar um cliente \n");
    printf("3 - Atualizar um cliente\n");
    printf("4 - Deletar um cliente\n");
    printf("0 - Sair \n");
    printf("*********************************************************************\n");
    printf("\n");
    printf("Digite o número desejado: \n");
    scanf("%c", &opcli);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();

    return opcli;
}

char novo_clien(){
    int nCPF[12];
    char nNome[70];
    int datanasc[9];
    int telefone[15];
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                       CADASTRAR UM NOVO CLIENTE                     \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    fgets(nCPF, sizeof(nCPF), stdin);
    printf("Digite o nome completo do cliente: \n");
    fgets(nNome, sizeof(nNome), stdin);
    printf("Digite a data de nascimento do cliente:\n ");
    fgets(datanasc, sizeof(datanasc), stdin);
    printf("Digite um telefone para contato:\n ");
    fgets(telefone, sizeof(telefone), stdin);
    printf("Tecle ENTER para continuar \n");
    getchar();
}e

char busca_clien(){
    int nCPF[12];
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                           BUSCAR POR CLIENTE                        \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    fgets(nCPF, sizeof(nCPF), stdin);
    printf("Tecle ENTER para continuar \n");
    getchar();
}

char atual_clien(){
    int nCPF[12];
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                         ATUALIZAR UM CLIENTE                        \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    fgets(nCPF, sizeof(nCPF), stdin);
    printf("Digite '1' se deseja alterar o nome do cliente ou '2' se deseja alterar a data de nascimento do cliente: \n");
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}

char excl_clien(){
    int nCPF[12];
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                         DELETAR UM CLIENTE                          \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    fgets(nCPF, sizeof(nCPF), stdin);
    printf("Tem certeza que quer continuar a operação? ");
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}