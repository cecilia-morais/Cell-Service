#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <time.h>
#include "celular.h"
#include "clientes.h"
#include "atendimentos.h"
#include "validacoes.h"

char cad_cell()
{
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

void grava_celulares(Celulares *celular)
{
    FILE *fc = fopen("./Celulares.dat", "ab");
    fwrite(celular, sizeof(Celulares), 1, fc);
    fclose(fc);
}

void novo_cell(void)
{
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
    int id_cell;
    time_t rawtime;
    struct tm *info;
    time(&rawtime);
    info = localtime(&rawtime);
    Celulares novo_celular;

    FILE *fc = fopen("./Clientes.dat", "rb");
    if (fc == NULL)
    {
        printf("Nenhum cliente cadastrado.\n");
        printf("Pressione ENTER para continuar...");
        getchar();
        return;
    }

    printf("Digite o CPF do cliente (ou 0 para sair): \n");
    fgets(cpf_cliente, sizeof(cpf_cliente), stdin);
    if (strcmp(cpf_cliente, "0\n") == 0)
    {
        return;
    }

    bool cpf_encontrado = false;
    Clientes cliente;

    while (fread(&cliente, sizeof(Clientes), 1, fc))
    {
        if (strcmp(cliente.cpf, cpf_cliente) == 0)
        {
            cpf_encontrado = true;
            break;
        }
    }

    fclose(fc);

    if (!cpf_encontrado)
    {
        printf("Cliente com CPF %s não encontrado.\n", cpf_cliente);
        printf("Pressione ENTER para continuar...");
        getchar();
        return;
    }

    limpar_buffer();
    printf("Digite a marca do aparelho: \n ");
    fgets(marca, sizeof(marca), stdin);
    marca[strlen(marca) - 1] = 0;
    getchar();

    limpar_buffer();
    printf("Digite o modelo do aparelho: \n");
    fgets(modelo, sizeof(modelo), stdin);
    modelo[strlen(modelo) - 1] = 0;
    getchar();

    limpar_buffer();
    printf("Digite o problema do aparelho: ");
    fgets(problema, sizeof(problema), stdin);
    problema[strlen(problema) - 1] = 0;
    getchar();

    snprintf(data_cadastro, sizeof(novo_celular.data_cadastro), "%02d/%02d/%04d", info->tm_mday, info->tm_mon + 1, info->tm_year + 1900);

    status = 1;

    id_cell = criar_id_d();
    novo_celular.id_celular = id_cell;
    strncpy(novo_celular.cpf_cliente, cpf_cliente, sizeof(novo_celular.cpf_cliente));
    strncpy(novo_celular.modelo, modelo, sizeof(novo_celular.modelo));
    strncpy(novo_celular.marca, marca, sizeof(novo_celular.marca));
    strncpy(novo_celular.problema, problema, sizeof(novo_celular.problema));
    strncpy(novo_celular.data_cadastro, data_cadastro, sizeof(novo_celular.data_cadastro));
    novo_celular.status = status;

    grava_celulares(&novo_celular);

    printf("Celular cadastrado com sucesso.\n");
    getchar();

    return;
}

void busca_cell()
{
    int id_celular;
    char cpf_cliente[12];
    int celular_encontrado = 0;
    int cliente_encontrado = 0;
    char nome[70];

    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                          BUSCAR UM CELULAR                          \n");
    printf("*********************************************************************\n");
    FILE *fc = fopen("./Celulares.dat", "rb");
    if (fc == NULL)
    {
        printf("Nenhum celular cadastrado até o momento.\n");
        printf("Tecle ENTER para continuar \n");
        getchar();
        return;
    }

    FILE *fcli = fopen("./Clientes.dat", "rb");
    if (fcli == NULL)
    {
        printf("Erro ao abrir o arquivo de clientes.\n");
        printf("Tecle ENTER para continuar \n");
        getchar();
        fclose(fc);
        fclose(fcli);
        return;
    }
    Celulares celular;
    Clientes cliente;

    printf("Digite o CPF do cliente ou '0' para sair: ");
    fgets(cpf_cliente, sizeof(cpf_cliente), stdin);
    cpf_cliente[strcspn(cpf_cliente, "\n")] = '\0'; // Remove a quebra de linha do final do CPF
    
    if (strcmp(cpf_cliente, "0") == 0)
    {
        return;
    }

    while (fread(&celular, sizeof(Celulares), 1, fc) == 1)
    {
        if (strcmp(celular.cpf_cliente, cpf_cliente) == 0)
        {
            celular_encontrado = 1;
            printf("Celular encontrado:\n\n");
            printf("ID do Celular: %d\n", celular.id_celular);
            printf("Marca: %s\n", celular.marca);
            printf("Modelo: %s\n", celular.modelo);
            printf("__________________________________________________\n");
        }
        else
        {
            printf("Não foi encontrado um celular cadastrado para o CPF informado.\n");
            printf("Tecle ENTER para continuar \n");
            getchar();
            fclose(fc);
            fclose(fcli);
            return;
        }
    }

    fseek(fc, 0, SEEK_SET);
    fseek(fcli, 0, SEEK_SET);
    getchar();

    int id;
    printf("\nDigite o ID do celular ou '0' para voltar: ");
    scanf("%d", &id);
    getchar();
    if (id == 0)
    {
        return;
    }
    FILE *fa = fopen("./Atendimentos.dat", "rb");
    Atendimentos atendimentos;
    
    while (fread(&celular, sizeof(Celulares), 1, fc) == 1)
    {
        if (celular.id_celular == id)
        {
            printf("ID do celular: %d\n", celular.id_celular);
            printf("Modelo: %s\n", celular.modelo);
            printf("Marca: %s\n", celular.marca);
            printf("Problema: %s\n", celular.problema);
            printf("Data de entrada: %s\n", celular.data_cadastro);
            if (celular.status == 3 && fread (&atendimentos, sizeof(Atendimentos), 1, fa) == 1){
            
                printf("Data de saída: %s\n", atendimentos.data_saida);
                printf("O Aparelho foi atendido.\n");
            }

            celular_encontrado = 1;
            break;
            
        }
    }

    if (celular.id_celular != id)
    {
        printf("O ID do celular informado não está disponível.\n");
        printf("Tecle ENTER para continuar \n");
        getchar();
        fclose(fc);
        fclose(fcli);
        return;
    }

    fclose(fc);
    fclose(fcli);
    fclose(fa);
    printf("\n");
    getchar();
    return;
}

void atual_cell()
{
    int id_celular;
    char cpf_cliente[12];
    int celular_encontrado = 0;

    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                       ATUALIZAR UM CELULAR                          \n");
    printf("*********************************************************************\n");
    FILE *fc = fopen("./Celulares.dat", "r+b");

    if (fc == NULL)
    {
        printf("Nenhum celular cadastrado até o momento.\n");
        printf("Tecle ENTER para continuar\n");
        getchar();
        return;
    }
    printf("Digite o CPF do cliente:\n ");
    fgets(cpf_cliente, sizeof(cpf_cliente), stdin);
    limpar_buffer();

    printf("Digite o ID do celular a ser atualizado:\n ");
    scanf("%d", &id_celular);
    limpar_buffer();

    Celulares cel;

    while (fread(&cel, sizeof(Celulares), 1, fc))
    {
        if (strcmp(cel.cpf_cliente, cpf_cliente) == 0 && cel.id_celular == id_celular)
        {
            system("clear || cls");
            printf("Celular encontrado:\n");
            printf("ID do aparelho: %d\n", cel.id_celular);
            printf("modelo: %s\n", cel.modelo);
            printf("marca: %s\n", cel.marca);
            printf("problema: %s\n", cel.problema);
            printf("Data de entrada: %s\n", cel.data_cadastro);
            celular_encontrado = 1;
            break;
        }
    }

    if (!celular_encontrado)
    {
        printf("Celular não encontrado.\n");
        printf("Tecle ENTER para continuar\n");
        getchar();
        fclose(fc);
        return;
    }

    int opcao;
    printf("\n");
    printf("_____________________________________________________________________\n");
    printf("Escolha o campo que deseja atualizar:\n");
    printf("1. Modelo\n");
    printf("2. Marca\n");
    printf("3. Problema\n");
    printf("Digite a opção desejada: ");
    scanf("%d", &opcao);
    limpar_buffer();

    switch (opcao)
    {
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

void excl_cell()
{
    int id_celular;
    char cpf_cliente[12];
    int celular_encontrado = 0;

    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                         DELETAR UM CELULAR                          \n");
    printf("*********************************************************************\n");
    FILE *fc = fopen("./Celulares.dat", "r+b");

    if (fc == NULL)
    {
        printf("Nenhum celular cadastrado até o momento.\n");
        printf("Tecle ENTER para continuar\n");
        getchar();
        return;
    }

    printf("Digite o CPF do cliente:\n ");
    fgets(cpf_cliente, sizeof(cpf_cliente), stdin);
    limpar_buffer();

    printf("Digite o ID do celular a ser excluído:\n ");
    scanf("%d", &id_celular);
    limpar_buffer();

    Celulares cel;

    while (fread(&cel, sizeof(Celulares), 1, fc))
    {
        if (strcmp(cel.cpf_cliente, cpf_cliente) == 0 && cel.id_celular == id_celular)
        {
            celular_encontrado = 1;

            cel.status = 0;

            fseek(fc, -(long int)sizeof(Celulares), SEEK_CUR);
            fwrite(&cel, sizeof(Celulares), 1, fc);

            printf("Celular com ID %d desativado com sucesso.\n", id_celular);
            break;
        }
    }

    fclose(fc);

    if (!celular_encontrado)
    {
        printf("Celular com ID %d para o CPF %s não encontrado.\n", id_celular, cpf_cliente);
    }

    printf("Tecle ENTER para continuar\n");
    getchar();
}

// Criar Id de forma nativa
// Feito com a ajuda do Chat Gpt e com Consultas no site StackOverflow
// Adapatado por Maria Eloisa e Matheus Diniz
// Adaptado por cecilia morais para ser usado no projeto
int criar_id_d(void)
{
    // Abrir o arquivo
    FILE *fc = fopen("./Celulares.dat", "rb");
    if (fc == NULL)
    {
        // caso o arquivo não exista começe com 1
        return 1;
        // Percorre o arquivo inteiro
        fseek(fc, 0, SEEK_END);
        // Para verificiar o tamanho do arquivo
        if ((long)ftell(fc) == 0)
        {
            // caso o arquivo esteja vázio
            fclose(fc);
            return 1;
        }
    }
    else
    {
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
