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

void grava_celulares(Celulares *celular){
    FILE *fc = fopen("./Celulares.dat", "ab");
    fwrite(celular , sizeof(Celulares), 1, fc);
    fclose(fc);
}


void novo_cell(void){
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                       CADASTRAR UM NOVO CELULAR                     \n");
    printf("*********************************************************************\n");
    printf("\n");
    char cpf_cliente[12];
    int id_celular;
    char modelo[20];
    char marca[15];
    char problema[100];
    char data_cadastro[11];
    int status;

    time_t rawtime;
    struct tm *info;
    time(&rawtime);
    info = localtime(&rawtime);
    Celulares novo_celular;

    FILE* fc = fopen("./Clientes.dat", "rb");
    if (fc == NULL) {
        printf("Nenhum cliente cadastrado.\n");
        printf("Pressione ENTER para continuar...");
        getchar();
        return;
    }

    ler_cpf(cpf_cliente);

    bool cpf_encontrado = false;
    Clientes cliente;

    while (fread(&cliente, sizeof(Clientes), 1, fc)) {
        if (strcmp(cliente.cpf, cpf_cliente) == 0) {
            cpf_encontrado = true;
            break;
        }
    }

    fclose(fc);

    if (!cpf_encontrado) {
        printf("Cliente com CPF %s não encontrado.\n", cpf_cliente);
        printf("Pressione ENTER para continuar...");
        getchar();
        return;
    }

    printf("Digite a marca do aparelho: ");
    ler_nome(marca);

    printf("Digite o modelo do aparelho: ");
    fgets(modelo, sizeof(modelo), stdin);
    modelo[strlen(modelo) - 1] = 0;

    printf("Digite o problema do aparelho: ");
    ler_nome(problema);

    snprintf(data_cadastro, sizeof(novo_celular.data_cadastro), "%02d/%02d/%04d", info->tm_mday, info->tm_mon + 1, info->tm_year + 1900);

    status = 1;

    id_celular = criar_id_d();
    novo_celular.id_celular = id_celular;
    strncpy(novo_celular.cpf_cliente, cpf_cliente, sizeof(novo_celular.cpf_cliente));
    strncpy(novo_celular.modelo, modelo, sizeof(novo_celular.modelo));
    strncpy(novo_celular.marca, marca, sizeof(novo_celular.marca));
    strncpy(novo_celular.problema, problema, sizeof(novo_celular.problema));
    strncpy(novo_celular.data_cadastro, data_cadastro, sizeof(novo_celular.data_cadastro));
    novo_celular.status = status;
    
    grava_celulares(&novo_celular);

    printf("Celular cadastrado com sucesso.\n");
    getchar();
}

void busca_cell(){
    char cpf_cliente[12];
    int celular_encontrado = 0;
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                 BUSCAR CELULARES CADASTRADOS POR CLIENTE               \n");
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
    Clientes cliente;

    while (fread(&cel, sizeof(Celulares), 1, fc)) {
        if (strcmp(cel.cpf_cliente, cpf_cliente) == 0 && cel.status != 0) {
            FILE* fc = fopen("./Clientes.dat", "rb");
            if (fc == NULL) {
                printf("Arquivo de clientes não encontrado.\n");
                printf("Pressione ENTER para continuar...");
                getchar();
                return;
            }
            while (fread(&cliente, sizeof(Clientes), 1, fc)) {
                if (strcmp(cliente.cpf, cpf_cliente) == 0) {
                    system("clear || cls");
                    printf("Cliente: %s\n", cliente.nome);
                    break;
                }
            }
            fclose(fc);

            printf("Celulares cadastrados para o CPF %s:\n", cpf_cliente);
            printf("ID do aparelho: %d\n", cel.id_celular);
            printf("modelo: %s\n", cel.modelo);
            printf("marca: %s\n", cel.marca);
            printf("problema: %s\n", cel.problema);
            printf("Data de entrada: %s\n", cel.data_cadastro);
            //quando fizer a verificação de que o celular ja foi atendido, aparecera a data de saída
            printf("Status: %d\n", cel.status);
            celular_encontrado = 1;
            getchar();
            break; 

        }
    }

    fclose(fc);

    if (!celular_encontrado) {
        printf("Cliente com CPF %s não encontrado ou não possui celulares cadastrados.\n", cpf_cliente);
    }

    printf("Pressione ENTER para continuar...");
    getchar();
}
    

void atual_cell() {
    int id_celular;
    char cpf_cliente[12];
    int celular_encontrado = 0;

    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                       ATUALIZAR UM CELULAR                          \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    fgets(cpf_cliente, sizeof(cpf_cliente), stdin);
    limpar_buffer();

    printf("Digite o ID do celular a ser atualizado:\n ");
    scanf("%d", &id_celular);
    limpar_buffer();

    FILE* fc = fopen("./Celulares.dat", "r+b");

    if (fc == NULL) {
        printf("Arquivo de celulares não encontrado.\n");
        printf("Tecle ENTER para continuar\n");
        getchar();
        return;
    }

    Celulares cel;

    while (fread(&cel, sizeof(Celulares), 1, fc)) {
        if (strcmp(cel.cpf_cliente, cpf_cliente) == 0 && cel.id_celular == id_celular) {
            printf("Celular encontrado:\n");
            printf("ID do aparelho: %d\n", cel.id_celular);
            printf("modelo: %s\n", cel.modelo);
            printf("marca: %s\n", cel.marca);
            printf("problema: %s\n", cel.problema);
            printf("Data de entrada: %s\n", cel.data_cadastro);
            printf("Status: %d\n", cel.status);
            celular_encontrado = 1;
            break;
        }
    }

    if (!celular_encontrado) {
        printf("Celular não encontrado.\n");
        printf("Tecle ENTER para continuar\n");
        getchar();
        fclose(fc);
        return;
    }

    int opcao;
    printf("Escolha o campo que deseja atualizar:\n");
    printf("1. Modelo\n");
    printf("2. Marca\n");
    printf("3. Problema\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);
    limpar_buffer();

    switch (opcao) {
        case 1:
            printf("Digite o novo modelo: ");
            fgets(cel.modelo, sizeof(cel.modelo), stdin);
            cel.modelo[strlen(cel.modelo) - 1] = '\0';
            break;
        case 2:
            printf("Digite a nova marca: ");
            fgets(cel.marca, sizeof(cel.marca), stdin);
            cel.marca[strlen(cel.marca) - 1] = '\0';
            break;
        case 3:
            printf("Digite o novo problema: ");
            ler_nome(cel.problema);
            break;

        default:
            printf("Opção inválida.\n");
            printf("Tecle ENTER para continuar\n");
            getchar();
            fclose(fc);
            return;
    }

    fseek(fc, -(long long int)sizeof(Celulares), SEEK_CUR);
    fwrite(&cel, sizeof(Celulares), 1, fc);
    fclose(fc);

    printf("Celular atualizado com sucesso.\n");
    printf("Tecle ENTER para continuar\n");
    getchar();
}




void excl_cell() {
    int id_celular;
    char cpf_cliente[12];
    int celular_encontrado = 0;

    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                         DELETAR UM CELULAR                          \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    fgets(cpf_cliente, sizeof(cpf_cliente), stdin);
    limpar_buffer();

    printf("Digite o ID do celular a ser excluído:\n ");
    scanf("%d", &id_celular);
    limpar_buffer();

    FILE* fc = fopen("./Celulares.dat", "r+b");

    if (fc == NULL) {
        printf("Arquivo de celulares não encontrado.\n");
        printf("Tecle ENTER para continuar\n");
        getchar();
        return;
    }

    Celulares cel;

    while (fread(&cel, sizeof(Celulares), 1, fc)) {
        if (strcmp(cel.cpf_cliente, cpf_cliente) == 0 && cel.id_celular == id_celular) {
            celular_encontrado = 1;

            cel.status = 0;

            fseek(fc, - (long int)sizeof(Celulares), SEEK_CUR); 
            fwrite(&cel, sizeof(Celulares), 1, fc);   

            printf("Celular com ID %d desativado com sucesso.\n", id_celular);
            break;
        }
    }

    fclose(fc);

    if (!celular_encontrado) {
        printf("Celular com ID %d para o CPF %s não encontrado.\n", id_celular, cpf_cliente);
    }

    printf("Tecle ENTER para continuar\n");
    getchar();
}

void todos_celulares(void){
    printf("Celulares");
    listar_celulares();
    getchar();
    getchar();
}


void exibindo_celulares(Celulares* celular) {
    FILE* fc = fopen("./Celulares.dat", "rb");
    if (fc == NULL) {
        printf("Arquivo Celulares.dat não encontrado.\n");
        return;
    }

    Celulares cel;
    while (fread(&cel, sizeof(Celulares), 1, fc)) {
        if (cel.status != 0) {
            printf("\nCelular cadastrado por clientes\n");
            printf("ID do aparelho: %d\n", cel.id_celular);
            printf("CPF: %s\n", cel.cpf_cliente);
            printf("Modelo: %s\n", cel.modelo);
            printf("Marca: %s\n", cel.marca);
            printf("Problema: %s\n", cel.problema);
            printf("Data de entrada: %s\n", cel.data_cadastro);
            getchar();
        }
    }

    fclose(fc);
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
//Adaptado por cecilia morais para ser usado no projeto
int criar_id_d(void){
    // Abrir o arquivo
    FILE *fc = fopen("./Celulares.dat", "rb");
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



