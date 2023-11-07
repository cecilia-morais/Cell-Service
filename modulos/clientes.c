#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "validacoes.h"


Clientes* clien;

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

 void novo_clien(){
    system("clear || cls");
    clien = (Clientes*)malloc(sizeof(Clientes));
    printf("*********************************************************************\n");
    printf("                       CADASTRAR UM NOVO CLIENTE                     \n");
    printf("*********************************************************************\n");
    ler_cpf(clien->cpf);
    ler_nome(clien->nome);
    ler_email(clien->email);
    ler_telefone(clien->telefone);
    printf("Tecle ENTER para continuar \n");
    getchar();
    return;
}

void busca_clien(){
    char cpf[12];
    int numClientes = 0;
    int clienteEncontrado = 0;
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                           BUSCAR POR CLIENTE                        \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    scanf("%s", cpf);

    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clien[i].cpf, cpf) == 0) {
            printf("Cliente encontrado:\n");
            printf("Nome: %s\n", clien[i].nome);
            printf("CPF: %s\n", clien[i].cpf);
            printf("Email: %s\n", clien[i].email);
            printf("Telefone: %s\n", clien[i].telefone);
            clienteEncontrado = 1; 
            break;
        }
    }

    if (!clienteEncontrado) {
        printf("Cliente não encontrado.\n");
    }
    printf("Tecle ENTER para continuar \n");
    getchar();
}

void atual_clien(){
    char cpf[12];
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                         ATUALIZAR UM CLIENTE                        \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    scanf("%c", cpf);
    printf("Digite:\n '1' se deseja alterar o nome do cliente\n '2' se deseja alterar a data de nascimento do cliente\n '3' se deseja alterar o telefone: \n");
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}

// char excl_clien(){
//     char cpf[12];
//     system("clear || cls");
//     printf("*********************************************************************\n");
//     printf("                         DELETAR UM CLIENTE                          \n");
//     printf("*********************************************************************\n");
//     printf("Digite o CPF do cliente:\n ");
//     scanf("%c", cpf);
//     printf("Tem certeza que quer continuar a operação? ");
//     getchar();
//     printf("Tecle ENTER para continuar \n");
//     getchar();

// }