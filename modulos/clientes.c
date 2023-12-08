#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "clientes.h"
#include "validacoes.h"


///////////////////////////////////////////////////////////////////////////////////////
// OS CODIGOS DESSE MÓDULO FOI FEITO COM AJUDA DE MAXSUEL GADELHA- GitHub: @Lleusxam //
// E MATHEUS DINIZ - GitHub: @matheusdnf                                             //
///////////////////////////////////////////////////////////////////////////////////////

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
    printf("5 - Listar clientes\n");
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

void grava_cliente(Clientes* clientes){
    FILE* fc;
    fc=fopen("./Clientes.dat","ab");
    fwrite(clientes,sizeof(Clientes),1,fc);
    fclose(fc);
}

 void novo_clien(void){
    system("clear || cls");
    Clientes novo_cliente;   
    
    printf("*********************************************************************\n");
    printf("                       CADASTRAR UM NOVO CLIENTE                     \n");
    printf("*********************************************************************\n");
    
    char cpf[12];
    char nome[70];
    char email[100];
    char telefone[15];
    int status;

    printf("Digite o nome do cliente ");
    ler_nome(nome);
    ler_cpf(cpf);
    ler_email(email);
    ler_telefone(telefone);
    status = 1;
 
    strncpy(novo_cliente.cpf, cpf, sizeof(novo_cliente.cpf));
    strncpy(novo_cliente.nome, nome, sizeof(novo_cliente.nome));
    strncpy(novo_cliente.email, email, sizeof(novo_cliente.email));
    strncpy(novo_cliente.telefone, telefone, sizeof(novo_cliente.telefone));
    novo_cliente.status = status;


    grava_cliente(&novo_cliente);

    printf("Cadastro realizado com sucesso!\n");
    getchar();
    
}


void busca_clien(void) {
    char cpf[12];
    int clienteEncontrado = 0;
    
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                           BUSCAR POR CLIENTE                        \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n");
    scanf("%s", cpf);
    getchar();

    FILE* fc = fopen("./Clientes.dat", "rb");
    if (fc == NULL) {
        printf("Arquivo de clientes não encontrado.\n");
        printf("Pressione ENTER para continuar...");
        getchar();
        return;
    }

    Clientes cli;

    while (fread(&cli, sizeof(Clientes), 1, fc)) {
        if (strcmp(cli.cpf, cpf) == 0) {
            system("clear || cls");
            printf("Cliente encontrado!\n");
            printf("***********************************\n");
            printf("\nNome: %s", cli.nome);
            printf("Email: %s\n", cli.email);
            printf("Telefone: %s\n", cli.telefone);
            printf("***********************************\n");
            clienteEncontrado = 1;
            break; 
        }
    }

    fclose(fc);

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

    FILE* fc = fopen("./Clientes.dat", "r+b");  
    if (fc == NULL) {
        printf("Arquivo de clientes não encontrado.\n");
        printf("Tecle ENTER para continuar\n");
        getchar();
        return;
    }

    Clientes cli;

    while (fread(&cli, sizeof(Clientes), 1, fc)) {
        if (strcmp(cli.cpf, cpf) == 0) {
            encontrado = 1;

            printf("Atualizando as informações do cliente:\n");
            printf("1. Nome\n");
            printf("2. Email\n");
            printf("3. Telefone\n");
            printf("Escolha o número correspondente ao campo que deseja atualizar: ");
            int opcao;
            scanf("%d", &opcao);
            getchar();

            switch (opcao) {
                case 1:
                    printf("Digite o novo nome do cliente: ");
                    ler_nome(cli.nome);
                    break;
                case 2:
                    ler_email(cli.email);
                    break;
                case 3:
                    ler_telefone(cli.telefone);
                    break;
                default:
                    printf("Opção inválida.\n");
                    break;
            }

            cli.status = 1;

            fseek(fc, - (long int)sizeof(Clientes), SEEK_CUR);
            fwrite(&cli, sizeof(Clientes), 1, fc);   

            printf("Cliente atualizado com sucesso.\n");
            break;
        }
    }

    fclose(fc);

    if (!encontrado) {
        printf("Cliente com CPF %s não encontrado.\n", cpf);
    }

    printf("Tecle ENTER para continuar\n");
    getchar();
}


void excl_clien() {
    char cpf[12];
    int encontrado = 0;
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                        DESATIVAR UM CLIENTE                        \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente que deseja desativar: ");
    scanf("%s", cpf);
    getchar();

    FILE* fc = fopen("./Clientes.dat", "r+b");  
    if (fc == NULL) {
        printf("Arquivo de clientes não encontrado.\n");
        printf("Tecle ENTER para continuar\n");
        getchar();
        return;
    }

    Clientes cli;

    while (fread(&cli, sizeof(Clientes), 1, fc)) {
        if (strcmp(cli.cpf, cpf) == 0) {
            encontrado = 1;

            printf("Deseja realmente desativar %s? \n 1- Sim \n 2-Não \n ", cli.nome);
            char resposta;
            scanf(" %c", &resposta);
            getchar();

            if (resposta == 'S' || resposta == 's') {
                cli.status = 0;
                fseek(fc, - (long int)sizeof(Clientes), SEEK_CUR); 
                fwrite(&cli, sizeof(Clientes), 1, fc);   
                printf("Cliente desativado com sucesso.\n");
            } else {
                break;
            }
        }
    }

    fclose(fc);

    if (!encontrado) {
        printf("Cliente com CPF %s não encontrado.\n", cpf);
    }

    printf("Tecle ENTER para continuar\n");
    getchar();
}


void todos_clientes(void){
    system("clear || cls");
    printf("\nCLientes\n");
    listar_cliente();
    getchar();
}

void exibindo_clientes(Clientes* clientes){
    char situ[17];
    if((clientes==NULL) || (clientes->status==0)){
        printf("\nEsse cliente não existe no sistema\n");
    }
    else{
        printf("************************");
        printf("\nDADOS DOS CLIENTES\n");
        printf("\n");
        printf("Nome: %s",clientes->nome);
        printf("CPF: %s\n",clientes->cpf);
        printf("Email: %s\n",clientes->email);
        printf("Telefone: %s\n",clientes->telefone);
            if (clientes->status == '1'){
                strcpy(situ, "cadastrados");
            }
            else if (clientes->status == '0'){
                strcpy(situ, "Fechado");
        }
    }
}

void listar_cliente(void){
    FILE* fc;
    Clientes* cli;
    cli=(Clientes*)malloc(sizeof(Clientes));
    fc=fopen("./Clientes.dat","rb");
    if (fc==NULL){
        printf("Arquivo não existente\n");
        return;
    }
    while(fread(cli,sizeof(Clientes),1,fc)){
        if(cli->status!=0){
            exibindo_clientes(cli);
        }
    }
    fclose(fc);
    free(cli);
}