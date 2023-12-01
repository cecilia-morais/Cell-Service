#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <string.h>
#include "atendimentos.h"
#include "clientes.h"
#include "celular.h"

void grava_atendimentos(Atendimentos *atendimentos)
{
    FILE *fc = fopen("./Atendimentos.dat", "ab");
    fwrite(atendimentos, sizeof(Atendimentos), 1, fc);
    fclose(fc);
}

char area_atendimento()
{
    system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                            ATENDIMENTOS                             \n");
    printf("*********************************************************************\n");
    printf("1 - Cadastrar um novo atendimento\n");
    printf("2 - Buscar um atendimento \n");
    printf("3 - Atualizar um atendimento\n");
    printf("4- Listar todos os atendimentos\n");
    printf("0 - Sair \n");
    printf("*********************************************************************\n");
    printf("\n");
    printf("Digite o número desejado: \n");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();

    return op;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "atendimentos.h"
#include "celular.h"

void novo_atendimento()
{
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                           NOVO ATENDIMENTO                          \n");
    printf("*********************************************************************\n");
    Atendimentos novo_atendimento;
    Celulares celular;
    time_t rawtime;
    struct tm *info;
    time(&rawtime);
    info = localtime(&rawtime);
    int id_atendimento;
    char cpf[12];
    int id_em_cell;
    char descricao[100];
    char data_saida[11];
    int status;

    int celular_encontrado = 0;
    while (!celular_encontrado)
    {
        printf("Digite o CPF do cliente:\n");
        fgets(cpf, sizeof(cpf), stdin);
        novo_atendimento.id_atendimento = id_atendimento;
        system("clear || cls");

        FILE *fc = fopen("./Celulares.dat", "rb");
        if (fc == NULL)
        {
            printf("Erro ao abrir o arquivo de celulares.\n");
            return;
        }

        while (fread(&celular, sizeof(Celulares), 1, fc) == 1)
        {
            while (strcmp(celular.cpf_cliente, cpf) == 0 && celular.status == 1)
            {
                printf("ID do celular disponível para atendimento: %d\n", celular.id_celular);
                printf("Modelo: %s\n", celular.modelo);
                printf("Marca: %s\n", celular.marca);
                printf("Problema: %s\n", celular.problema);
                printf("Data de entrada: %s\n", celular.data_cadastro);
                printf("_____________________________________________________________________\n");
                celular_encontrado = 1;
                break;
            }
        }

        if (celular_encontrado == 0)
        {
            printf("Não há celulares disponíveis para atendimento com o CPF informado.\n");
            printf("Digite um CPF válido.\n");
        }

        fclose(fc);
    }

    printf("Digite o ID do celular para atendimento:\n");
    scanf("%d", &id_em_cell);
    getchar();

    FILE *fc = fopen("./Celulares.dat", "rb");
    if (fc == NULL)
    {
        printf("Erro ao abrir o arquivo de celulares.\n");
        return;
    }

    celular_encontrado = 0;
    while (fread(&celular, sizeof(Celulares), 1, fc) == 1)
    {
        if (celular.id_celular == id_em_cell && celular.status == 1)
        {
            celular_encontrado = 1;
            break;
        }
    }

    fclose(fc);

    if (!celular_encontrado)
    {
        printf("O ID do celular informado não existe ou não está disponível para atendimento.\n");
        return;
    }

    snprintf(data_saida, sizeof(novo_atendimento.data_saida), "%02d/%02d/%04d", info->tm_mday, info->tm_mon + 1, info->tm_year + 1900);
    id_atendimento = criar_id_a();
    printf("Digite a descrição do problema:\n");
    fgets(descricao, sizeof(descricao), stdin);
    printf("O problema foi resolvido?\n");
    printf("1 - Sim\n");
    printf("2 - Não\n");
    scanf("%d", &status);
    getchar();

    if (status == 1)
    {
        novo_atendimento.status = 1;
    }
    else if (status == 2)
    {
        novo_atendimento.status = 2;
    }
    else
    {
        printf("Opção inválida!\n");
        getchar();
        return;
    }

    novo_atendimento.id_atendimento = id_atendimento;
    strncpy(novo_atendimento.cpf, cpf, sizeof(novo_atendimento.cpf));
    strncpy(novo_atendimento.descricao, descricao, sizeof(novo_atendimento.descricao));
    strncpy(novo_atendimento.data_saida, data_saida, sizeof(novo_atendimento.data_saida));
    grava_atendimentos(&novo_atendimento);
    printf("Atendimento cadastrado com sucesso.\n");
    getchar();
}


void busca_atendimento() {
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                 BUSCAR ATENDIMENTOS CADASTRADOS                      \n");
    printf("*********************************************************************\n");

    FILE *fa = fopen("./Atendimentos.dat", "rb");
    if (fa == NULL) {
        printf("Erro ao abrir o arquivo de atendimentos.\n");
        return;
    }

    FILE *fc = fopen("./Celulares.dat", "rb");
    if (fc == NULL) {
        printf("Erro ao abrir o arquivo de celulares.\n");
        fclose(fa);
        return;
    }

    FILE *fcli = fopen("./Clientes.dat", "rb");
    if (fcli == NULL) {
        printf("Erro ao abrir o arquivo de clientes.\n");
        fclose(fa);
        fclose(fc);
        return;
    }

    Atendimentos atendimento;
    Celulares celular;
    Clientes cliente;

    int id_atendimento;
    printf("Digite o ID do atendimento: ");
    scanf("%d", &id_atendimento);
    getchar();

    int atendimento_encontrado = 0;
    while (fread(&atendimento, sizeof(Atendimentos), 1, fa) == 1) {
        if (atendimento.id_atendimento == id_atendimento) {
            atendimento_encontrado = 1;
            break;
        }
    }

    if (!atendimento_encontrado) {
        printf("O ID do atendimento informado não existe.\n");
        fclose(fa);
        fclose(fc);
        fclose(fcli);
        return;
    }

    int celular_encontrado = 0;
    while (fread(&celular, sizeof(Celulares), 1, fc) == 1) {
        if (strcmp(celular.cpf_cliente, atendimento.cpf) == 0) {
            celular_encontrado = 1;
            break;
        }
    }

    if (!celular_encontrado) {
        printf("Não foi encontrado um celular cadastrado para o CPF informado no atendimento.\n");
        fclose(fa);
        fclose(fc);
        fclose(fcli);
        return;
    }

    int cliente_encontrado = 0;
    while (fread(&cliente, sizeof(Clientes), 1, fcli) == 1) {
        if (strcmp(cliente.cpf, atendimento.cpf) == 0) {
            cliente_encontrado = 1;
            break;
        }
    }

    if (!cliente_encontrado) {
        printf("Não foi encontrado um cliente cadastrado para o CPF informado no atendimento.\n");
        fclose(fa);
        fclose(fc);
        fclose(fcli);
        return;
    }

    printf("ID do Atendimento: %d\n", atendimento.id_atendimento);
    printf("CPF do Cliente: %s\n", atendimento.cpf);
    printf("Nome do Cliente: %s\n", cliente.nome);
    printf("Descrição do Problema: %s\n", atendimento.descricao);
    printf("Data de entrada: %s\n", celular.data_cadastro);
    printf("Data de Saída: %s\n", atendimento.data_saida);
    printf("Status: %d\n", atendimento.status);
    printf("ID do Celular: %d\n", celular.id_celular);
    printf("Status do Celular: %d\n", celular.status);

    fclose(fa);
    fclose(fc);
    fclose(fcli);

    printf("Tecle ENTER para continuar \n");
    getchar();
}


char atual_atendimento()
{
    char cpf[12];
    system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                         ATUALIZAR UM ATENDIMENTO                    \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    fgets(cpf, sizeof(cpf), stdin);
    printf("Digite o ID do aparelho que deseja atualizar: \n");
    getchar();
    printf(" 1- Deseja finalizar o atendimento ou 2 -alterar alguma informação no atendimento?\n ");
    // if (op == 1){

    // }else if{

    // }
    printf("Tecle ENTER para continuar \n");
    getchar();

    return op;
}
// NAO EXISTIRÁ O DELETE UM ATENDIMENTO PARA QUE TODOS OS ATENDIMENTOS, INCLUINDO OS CANCELADOS, FIQUEM REGISTRADOS!!

// Criar Id de forma nativa
// Feito com a ajuda do Chat Gpt e com Consultas no site StackOverflow
// Adapatado por Maria Eloisa e Matheus Diniz
// Adaptado por cecilia morais para ser usado no projeto
int criar_id_a(void)
{
    // Abrir o arquivo
    FILE *fc = fopen("./Atendimentos.dat", "rb");
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
        fseek(fc, -((long)sizeof(Atendimentos)), SEEK_END);
        // Agora você pode ler o último registro usando fread

        Atendimentos ultstruct;
        fread(&ultstruct, sizeof(Atendimentos), 1, fc);

        // Obtenha o ID do último registro e incremente
        int id = ultstruct.id_atendimento + 1;

        fclose(fc); // Feche o arquivo aqui
        return id;
    }
}

void todos_atendimentos(void)
{
    printf("Atendimentos:\n");
    listar_atendimentos();
    getchar();
    getchar();
}

void exibindo_atendimentos(Atendimentos *atendimento)
{
    FILE *fa = fopen("./Atendimentos.dat", "rb");
    if (fa == NULL)
    {
        printf("Arquivo Atendimentos.dat não encontrado.\n");
        return;
    }

    Atendimentos ate;
    while (fread(&ate, sizeof(Atendimentos), 1, fa))
    {
        if (ate.status == 1)
        {
            printf("\nAtendimento:\n");
            printf("ID do atendimento: %d\n", ate.id_atendimento);
            printf("CPF: %s\n", ate.cpf);
            printf("Descrição: %s\n", ate.descricao);
            printf("Data de saída: %s\n", ate.data_saida);
            getchar();
        }
        else if (ate.status == 2)
        {
            printf("\nAtendimento:\n");
            printf("ID do atendimento: %d\n", ate.id_atendimento);
            printf("CPF: %s\n", ate.cpf);
            printf("Descrição: %s\n", ate.descricao);
            printf("Data de saída: %s\n", ate.data_saida);
            printf("O aparelho não foi consertado.\n");
            getchar();
        }
    }
    fclose(fa);
}

void listar_atendimentos(void)
{
    FILE *fa;
    Atendimentos *ate;
    ate = (Atendimentos *)malloc(sizeof(Atendimentos));
    fa = fopen("./Atendimentos.dat", "rb");
    if (fa == NULL)
    {
        printf("Arquivo não existente");
        return;
    }
    while (fread(ate, sizeof(Atendimentos), 1, fa))
    {
        exibindo_atendimentos(ate);
    }
    fclose(fa);
    free(ate);
}
