#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include "celular.h"
#include "clientes.h"
#include "validacoes.h"



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

void grava_celulares(Celulares* celular){
    FILE* fc;
    fc=fopen("Celulares.dat","ab");
    if (fc==NULL){
        printf("Arquivo não existe!");
        return;
    }
    fwrite(celular,sizeof(Celulares),1,fc);
    fclose(fc);
    free(celular);
}

void novo_cell(void){
    system("clear || cls");
    Celulares* cel;
    time_t rawtime;
    struct tm *info;
    time(&rawtime);
    info = localtime(&rawtime);
    cel=(Celulares*)malloc(sizeof(Celulares));
    // Celulares novo_celular;

    printf("*********************************************************************\n");
    printf("                       CADASTRAR UM NOVO CELULAR                     \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente: \n");
    fgets(cel->cpf_cliente, sizeof(cel->cpf_cliente), stdin);
    limpar_buffer();

   cel->id_celular = criar_id_d();

    printf("Digite a marca do aparelho: \n");
    fgets(cel->marca, sizeof(cel->marca), stdin);
    limpar_buffer();

    printf("Digite o problema do aparelho: \n");
    fgets(cel->problema, sizeof(cel->problema), stdin);

    snprintf(cel->data_cadastro, sizeof(cel->data_cadastro), "%02d/%02d/%04d", info->tm_mday, info->tm_mon + 1, info->tm_year + 1900);
    limpar_buffer();
    
    cel->status = 1;

    grava_celulares(cel);

    printf("Cadastro realizado com sucesso!\n");
    getchar();
}


void busca_cell(){
    char cpf_cliente[12];
    int celular_encontrado = 0;
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                 BUSCAR CELULAR CADASTRADO POR CLIENTE               \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    fgets(cpf_cliente, sizeof(cpf_cliente), stdin);
    
    FILE* fc = fopen("./Celulares.dat", "rb");
    if (fc == NULL) {
        printf("Arquivo de celulares não encontrado.\n");
        printf("Pressione ENTER para continuar...");
        getchar();
        return;
    }

    Celulares cel;
    while (fread(&cel, sizeof(Celulares), 1, fc)) {
        if (strcmp(cel.cpf_cliente, cpf_cliente) == 0) {
            printf("Celulares cadastrados para o CPF %s:\n", cpf_cliente);
            printf("ID do aparelho: %s\n", cel.id_celular);
            printf("modelo: %s\n", cel.modelo);
            printf("marca: %s\n", cel.marca);
            printf("problema: %s\n", cel.problema);
            printf("Data de entrada: %s\n", cel.data_cadastro);
            // quando fizer a verificação de que o celular ja foi atendido, aparecera a data de saída
            printf("Status: %d\n", cel.status);
            celular_encontrado = 1;
            getchar();
            break; 
        }
    }

    fclose(fc);

    if (!celular_encontrado) {
        printf("Cliente com CPF %s não encontrado.\n", cpf_cliente);
    }

    printf("Pressione ENTER para continuar...");
    getchar();
}
    


void atual_cell(){
    char cpf_cliente[12];
    int celular_encontrado = 0;
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                         ATUALIZAR UM CELULAR                        \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    scanf("%s", cpf_cliente);
    getchar();

    FILE* fc = fopen("./Celulares.dat", "r+b");  
    if (fc == NULL) {
        printf("Arquivo de celulares não encontrado.\n");
        printf("Tecle ENTER para continuar\n");
        getchar();
        return;
    }

    Celulares cel;

    while (fread(&cel, sizeof(Celulares), 1, fc)) {
        if (strcmp(cel.cpf_cliente, cpf_cliente) == 0) {
            celular_encontrado  = 1;

            printf("Digite a marca do aparelho:\n ");
            fgets(cel.marca, sizeof(cel.marca), stdin);
            printf("Digite o problema do aparelho: \n");
            fgets(cel.problema, sizeof(cel.problema), stdin);

            printf("Atualizando as informações do aparelho:\n");
            
            cel.status = 1;

            fseek(fc, - (long int)sizeof(Celulares), SEEK_CUR);
            fwrite(&cel, sizeof(Celulares), 1, fc);   

            printf("celente atualizado com sucesso.\n");
            break;
        }
    }

    fclose(fc);

    if (!celular_encontrado) {
        printf("Celulares para o CPF %s não encontrado.\n", cpf_cliente);
    }

    printf("Tecle ENTER para continuar\n");
    getchar();
}

 void excl_cell(){
    char cpf_cliente[12];
    int celular_encontrado = 0;
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                         DELETAR UM CELULAR                          \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    fgets(cpf_cliente, sizeof(cpf_cliente), stdin);
    printf("Tecle ENTER para continuar \n");
    getchar();

    FILE* fc = fopen("./Clientes.dat", "r+b");  
    if (fc == NULL) {
        printf("Arquivo de clientes não encontrado.\n");
        printf("Tecle ENTER para continuar\n");
        getchar();
        return;
    }

    Clientes cel;

    // while (fread(&cel, sizeof(Clientes), 1, fc)) {
    //     if (strcmp(cel.cpf_cliente, cpf) == 0) {
    //         celular_encontrado = 1;

    //         cli.status = 0;

    //         fseek(fc, - (long int)sizeof(Clientes), SEEK_CUR); 
    //         fwrite(&cli, sizeof(Clientes), 1, fc);   

    //         printf("Cliente desativado com sucesso.\n");
    //         break;
    //     }
    // }

    fclose(fc);

    if (!celular_encontrado) {
        printf("Cliente com CPF %s não encontrado.\n", cpf_cliente);
    }

    printf("Tecle ENTER para continuar\n");
    getchar();
}

void todos_celulares(void){
    printf("Celulares");
    listar_cliente();
    getchar();
    getchar();
}

void exibindo_celulares(Celulares* celular){
    char situ[17];
    char cpf_cliente[12];
    if((celular==NULL) || (celular->status==0)){
        printf("Esse celular não existe no sistema");
    }
    else{
        FILE* fc;
        Clientes* cli;
        fc=fopen("./Clientes.dat","rb");
        printf("\nCelulares cadastrado por clientes\n");

        printf("Nome:%s\n",cli->nome);

        fclose(fc);
        free(cli);

        printf("CPF:%s\n",celular->cpf_cliente);
        printf("Modelo:%s\n",celular->modelo);
        printf("Marca:%s\n",celular->marca);
        printf("Problema:%s\n",celular->problema);
        printf("Data de entrada:%s\n",celular->data_cadastro);
        getchar();
        getchar();

            if (celular->status == '1'){
                strcpy(situ, "cadastrados");
            }
            else if (celular->status == '0'){
                strcpy(situ, "Fechado");
        }
    }
}

void listar_celulares(void){
    FILE* fc;
    Celulares* cel;
    cel=(Celulares*)malloc(sizeof(Celulares));
    fc=fopen("./Celulares.dat","rb");
    if (fc==NULL){
        printf("Arquivo não existente");
        return;
    }
    while(fread(cel,sizeof(Celulares),1,fc)){
        if(cel->status!=0){
            exibindo_celulares(cel);
        }
    }
    fclose(fc);
    free(cel);
}

// Criar Id de forma nativa
// Feito com a ajuda do Chat Gpt e com Consultas no site StackOverflow
// Adapatado por Maria Eloisa e Matheus Diniz
int criar_id_d(void){
    // Abrir o arquivo
    FILE *fc = fopen("Celulares.dat", "rb");
    if (fc == NULL){
        // caso o arquivo não exista começe com 1
        return 1;
        // Percorre o arquivo inteiro
        fseek(fc, 0, SEEK_END);
        // Para verificiar o tamanho do arquivo
        if ((long)ftell(fc) == 0){
            // caso o arquivo esteja vázio
            fclose(fc);
            return 1;
        }
    }
    else{
        // Posicione o ponteiro no início do último registro
        // Ver a última estrutura Adicionada

        // long adicionada para evitar problemas de conversão pelo sizeof, para um valor negativo, causando um estouro no fseek
        fseek(fc, -((long)sizeof(Celulares)), SEEK_END);
        // Agora você pode ler o último registro usando fread

        Celulares ultstruct;
        fread(&ultstruct, sizeof(Celulares), 1, fc);

        // Obtenha o ID do último registro e incremente
        int id = ultstruct.id_celular + 1;

        fclose(fc); // Feche o arquivo aqui
        return id;
    }
}



