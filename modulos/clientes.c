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

char cad_clien()
{
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

void grava_cliente(Clientes *clientes)
{
    FILE *fc;
    fc = fopen("./Clientes.dat", "ab");
    fwrite(clientes, sizeof(Clientes), 1, fc);
    fclose(fc);
}

void novo_clien(void)
{
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
    if (cliente_existente_cpf(cpf) == 1)
    {
        printf("CPF já cadastrado\n");
        getchar();
        return;
    }

    ler_email(email);
    if (cliente_existente_email(email) == 1)
    {
        printf("Email já cadastrado\n");
        printf("Deseja cadastrar outro cliente com o mesmo email? \n");
        printf("1- Sim \n");
        printf("2- Não \n");
        char resposta;
        scanf(" %c", &resposta);
        getchar();
        if (resposta == '2')
        {
            return;
        }
    }

    ler_telefone(telefone);
    if (cliente_existente_telefone(telefone) == 1)
    {
        printf("Telefone já cadastrado\n");
        printf("Deseja cadastrar outro cliente com o mesmo telefone? \n");
        printf("1- Sim \n");
        printf("2- Não \n");
        char resposta;
        scanf(" %c", &resposta);
        getchar();
        if (resposta == '2')
        {
            return;
        }
    }

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

void busca_clien(void)
{
    char cpf[12];
    int clienteEncontrado = 0;

    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                           BUSCAR POR CLIENTE                        \n");
    printf("*********************************************************************\n");
    FILE *fc = fopen("./Clientes.dat", "rb");
    if (fc == NULL)
    {
        printf("Não há clientes cadastrados.\n");
        printf("Pressione ENTER para continuar...");
        getchar();
        return;
    }

    printf("Digite o CPF do cliente que deseja buscar: ");
    scanf("%s", cpf);
    getchar();

    Clientes cli;

    while (fread(&cli, sizeof(Clientes), 1, fc))
    {
        if (strcmp(cli.cpf, cpf) == 0)
        {
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

    if (!clienteEncontrado)
    {
        printf("Cliente com CPF %s não encontrado.\n", cpf);
    }

    printf("Pressione ENTER para continuar...");
    getchar();
}

void atual_clien()
{
    char cpf[12];
    int encontrado = 0;

    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                         ATUALIZAR UM CLIENTE                        \n");
    printf("*********************************************************************\n");
    FILE *fc = fopen("./Clientes.dat", "r+b");
    if (fc == NULL)
    {
        printf("Não há clientes cadastrados.\n");
        printf("Tecle ENTER para continuar\n");
        getchar();
        return;
    }

    printf("Digite o CPF do cliente que deseja atualizar: ");
    scanf("%s", cpf);
    getchar();
    Clientes cli;

    while (fread(&cli, sizeof(Clientes), 1, fc))
    {
        if (strcmp(cli.cpf, cpf) == 0)
        {
            encontrado = 1;

            printf("Atualizando as informações do cliente:\n");
            printf("1. Nome\n");
            printf("2. Email\n");
            printf("3. Telefone\n");
            printf("Escolha o número correspondente ao campo que deseja atualizar: ");
            int opcao;
            scanf("%d", &opcao);
            getchar();

            switch (opcao)
            {
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

            fseek(fc, -(long int)sizeof(Clientes), SEEK_CUR);
            fwrite(&cli, sizeof(Clientes), 1, fc);

            printf("Cliente atualizado com sucesso.\n");
            break;
        }
    }

    fclose(fc);

    if (!encontrado)
    {
        printf("Cliente com CPF %s não encontrado.\n", cpf);
    }

    printf("Tecle ENTER para continuar\n");
    getchar();
}

void excl_clien()
{
    char cpf[12];
    int encontrado = 0;
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                        DESATIVAR UM CLIENTE                        \n");
    printf("*********************************************************************\n");
    FILE *fc = fopen("./Clientes.dat", "r+b");
    if (fc == NULL)
    {
        printf("Não há clientes cadastrados\n");
        printf("Tecle ENTER para continuar\n");
        getchar();
        return;
    }

    printf("Digite o CPF do cliente que deseja desativar: ");
    scanf("%s", cpf);
    getchar();

    Clientes cli;

    while (fread(&cli, sizeof(Clientes), 1, fc))
    {
        if (strcmp(cli.cpf, cpf) == 0)
        {
            encontrado = 1;

            printf("Deseja realmente desativar %s? \n 1- Sim \n 2-Não \n ", cli.nome);
            char resposta;
            scanf(" %c", &resposta);
            getchar();

            if (resposta == 'S' || resposta == 's')
            {
                cli.status = 0;
                fseek(fc, -(long int)sizeof(Clientes), SEEK_CUR);
                fwrite(&cli, sizeof(Clientes), 1, fc);
                printf("Cliente desativado com sucesso.\n");
            }
            else
            {
                break;
            }
        }
    }

    fclose(fc);

    if (!encontrado)
    {
        printf("Cliente com CPF %s não encontrado.\n", cpf);
    }

    printf("Tecle ENTER para continuar\n");
    getchar();
}

// Função para verificar se um CPF já está cadastrado
int cliente_existente_cpf(const char *cpf)
{
    FILE *fc = fopen("./Clientes.dat", "rb");
    if (fc == NULL)
    {
        printf("Não há clientes cadastrados\n");
        return 0;
    }

    Clientes cli;
    while (fread(&cli, sizeof(Clientes), 1, fc))
    {
        if (strcmp(cli.cpf, cpf) == 0)
        {
            fclose(fc);
            return 1; // CPF encontrado
        }
    }

    fclose(fc);
    return 0; // CPF não encontrado
}

// Função para verificar se um e-mail já está cadastrado
int cliente_existente_email(const char *email)
{
    FILE *fc = fopen("./Clientes.dat", "rb");
    if (fc == NULL)
    {
        printf("Não há clientes cadastrados\n");
        return 0;
    }

    Clientes cli;
    while (fread(&cli, sizeof(Clientes), 1, fc))
    {
        if (strcmp(cli.email, email) == 0)
        {
            fclose(fc);
            return 1; // E-mail encontrado
        }
    }

    fclose(fc);
    return 0; // E-mail não encontrado
}

// Função para verificar se um telefone já está cadastrado
int cliente_existente_telefone(const char *telefone)
{
    FILE *fc = fopen("./Clientes.dat", "rb");
    if (fc == NULL)
    {
        printf("Não há clientes cadastrados\n");
        return 0;
    }

    Clientes cli;
    while (fread(&cli, sizeof(Clientes), 1, fc))
    {
        if (strcmp(cli.telefone, telefone) == 0)
        {
            fclose(fc);
            return 1; // Telefone encontrado
        }
    }

    fclose(fc);
    return 0; // Telefone não encontrado
}
