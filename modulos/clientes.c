#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    fc=fopen("Clientes.dat","ab");
    if (fc==NULL){
        printf("Arquivo não existe!");
        return;
    }
    fwrite(clientes,sizeof(Clientes),1,fc);
    fclose(fc);
    free(clientes);
}
 Clientes* novo_clien(void){
    system("clear || cls");
    Clientes* cli;
    cli=(Clientes*)malloc(sizeof(Clientes));       
    Clientes novo_cliente;
    printf("*********************************************************************\n");
    printf("                       CADASTRAR UM NOVO CLIENTE                     \n");
    printf("*********************************************************************\n");
    ler_cpf(cli->cpf);
    ler_nome(cli->nome);
    ler_email(cli->email);
    ler_telefone(cli->telefone);
    getchar();
    printf("Cadastro realizado com sucesso!\n");
    getchar();
    return cli;
    free(cli);
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

    FILE* fc = fopen("Clientes.dat", "rb");
    if (fc == NULL) {
        printf("Arquivo de clientes não encontrado.\n");
        printf("Pressione ENTER para continuar...");
        getchar();
        return;
    }

    Clientes cli;

    while (fread(&cli, sizeof(Clientes), 1, fc)) {
        if (strcmp(cli.cpf, cpf) == 0) {
            printf("Cliente encontrado!\n");
            printf("Nome: %s\n", cli.nome);
            printf("Email: %s\n", cli.email);
            printf("Telefone: %s\n", cli.telefone);
            printf("Status: %d\n", cli.status);
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

    FILE* fc = fopen("Clientes.dat", "r+b");  
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
            ler_nome(cli.nome);
            ler_email(cli.email);
            ler_telefone(cli.telefone);
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

    FILE* fc = fopen("Clientes.dat", "r+b");  
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

            cli.status = 0;

            fseek(fc, - (long int)sizeof(Clientes), SEEK_CUR); 
            fwrite(&cli, sizeof(Clientes), 1, fc);   

            printf("Cliente desativado com sucesso.\n");
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


void todos_clientes(void){
    printf("CLientes");
    listar_cliente();
    getchar();
    getchar();
}

void exibindo_clientes(Clientes* clientes){
    char situ[17];
    if((clientes==NULL) || (clientes->status==0)){
        printf("Esse cliente não existe no sistema");
    }
    else{
        printf("\nDados dos clientes\n");
        printf("Nome:%s\n",clientes->nome);
        printf("CPF:%s\n",clientes->cpf);
        printf(":Email:%s\n",clientes->email);
        printf("Telefone:%s\n",clientes->telefone);
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
    fc=fopen("Clientes.dat","rb");
    if (fc==NULL){
        printf("Arquivo não existente");
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