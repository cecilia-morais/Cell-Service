#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "clientes.h"
#include "validacoes.h"


///////////////////////////////////////////////////////////////////////////////////////
// OS CODIGOS DESSE MÓDULO FOI FEITO COM AJUDA DE MAXSUEL GADELHA- GitHub: @Lleusxam //
///////////////////////////////////////////////////////////////////////////////////////


Clientes clientes[1000];
int quantidade_clientes = 0;

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
    char cpf[12];
    char nome[70];
    char email[100];
    char telefone[15];
    int status;
    Clientes novo_cliente;
    printf("*********************************************************************\n");
    printf("                       CADASTRAR UM NOVO CLIENTE                     \n");
    printf("*********************************************************************\n");
    ler_cpf(cpf);
    ler_nome(nome);
    ler_email(email);
    ler_telefone(telefone);
    printf("Tecle ENTER para continuar \n");

    strncpy(novo_cliente.cpf, cpf, sizeof(novo_cliente.cpf));
    strncpy(novo_cliente.nome, nome, sizeof(novo_cliente.nome));
    strncpy(novo_cliente.email, email, sizeof(novo_cliente.email));
    strncpy(novo_cliente.telefone, telefone, sizeof(novo_cliente.telefone));
    novo_cliente.status = 1;

    clientes[quantidade_clientes] = novo_cliente;

    quantidade_clientes++;

    printf("Cliente cadastrado com sucesso!\n");

    getchar();
    return;
}

void busca_clien() {
    char cpf[12];
    int numClientes = 0;
    int clienteEncontrado = 0;

    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                           BUSCAR POR CLIENTE                        \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    scanf("%s", cpf);
    getchar();

    for (int i = 0; i < quantidade_clientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            printf("Cliente encontrado!\n");
            printf("Nome: %s\n", clientes[i].nome);
            printf("Email: %s\n", clientes[i].email);
            printf("Telefone: %s\n", clientes[i].telefone);
            printf("Status: %d\n", clientes[i].status);
            clienteEncontrado = 1;
        }
    }

    if (!clienteEncontrado) {
        printf("Cliente com CPF %s não encontrado.\n", cpf);
    }

    printf("Pressione ENTER para continuar...");
    getchar();
}


void atual_clien() {
    char cpf[12];
    int encontrado = 0;

    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                         ATUALIZAR UM CLIENTE                        \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente que deseja atualizar: ");
    scanf("%s", cpf);
    getchar();

    for (int i = 0; i < quantidade_clientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            encontrado = 1;

            printf("Atualizando as informações do cliente:\n");
            ler_nome(clientes[i].nome);
            ler_email(clientes[i].email);
            ler_telefone(clientes[i].telefone);
            clientes[i].status = 1;

            printf("Cliente atualizado com sucesso.\n");
            break;
        }
    }

    if (!encontrado) {
        printf("Cliente com CPF %s não encontrado.\n", cpf);
    }

    printf("Tecle ENTER para continuar\n");
    getchar();
}

void excl_clien(){
    char cpf[12];
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                         DELETAR UM CLIENTE                          \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente que deseja excluir:\n ");
    scanf("%s", cpf);
    getchar();

    for (int i = 0; i < quantidade_clientes; i++){
        if (strcmp(clientes[i].cpf, cpf) == 0){
            clientes[i].status = 0;
            printf("Cliente excluído com sucesso!\n");
            break;
        }
    }
}