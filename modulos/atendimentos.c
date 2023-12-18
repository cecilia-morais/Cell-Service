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

void novo_atendimento()
{
    
    time_t rawtime;
    struct tm *info;
    time(&rawtime);
    info = localtime(&rawtime);
    char cpf[12];
    int id_em_cell;
    char descricao[100];
    char data_saida[11];
    int status;
    int id_atd;
    int celular_encontrado = 0;
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                           NOVO ATENDIMENTO                          \n");
    printf("*********************************************************************\n");

     FILE *fc = fopen("./Celulares.dat", "rb");
    if (fc == NULL)
    {
        printf("Nenhum celular cadastrado.\n");
        printf("Tecle ENTER para continuar \n");
        getchar();
        return;
    }

    Atendimentos novo_atendimento;
    Celulares celular;

    printf("Digite o CPF do cliente ou '0' para sair: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0'; // Remove a quebra de linha do final do CPF
    
    if (strcmp(cpf, "0") == 0)
    {
        return;
    }

    while (fread(&celular, sizeof(Celulares), 1, fc) == 1)
    {
        if (strcmp(celular.cpf_cliente, cpf) == 0 && celular.status == 1)
        {
            celular_encontrado = 1;
            printf("ID do Celular: %d\n", celular.id_celular);
            printf("Marca: %s\n", celular.marca);
            printf("Modelo: %s\n", celular.modelo);
            printf("Problema: %s\n", celular.problema);
            printf("Data de entrada: %s\n", celular.data_cadastro);
            printf("__________________________________________________\n");
        }
    }

    if(!celular_encontrado)
    {
        printf("Não foi encontrado um celular cadastrado para o CPF informado.\n");
        printf("Tecle ENTER para continuar \n");
        getchar();
        getchar();
        fclose(fc);
        return;
    }

    fseek(fc, 0, SEEK_SET);
    getchar();


    printf("Digite o ID do celular para atendimento:\n");
    scanf("%d", &id_em_cell);
    getchar();


    while (fread(&celular, sizeof(Celulares), 1, fc) == 1)
    {
        if (celular.id_celular == id_em_cell && celular.status == 1)
        {
            celular_encontrado = 1;
            celular.status = 3;                                  // Marca o celular como atendido
            fseek(fc, -((long int)sizeof(Celulares)), SEEK_CUR); // Volta para a posição correta no arquivo
            fwrite(&celular, sizeof(Celulares), 1, fc);          // Atualiza as informações do celular no arquivo
            break;
        }
    }

    fclose(fc);

    if (!celular_encontrado)
    {
        printf("O ID do celular informado não existe ou não está disponível para atendimento.\n");
        printf("Tecle ENTER para continuar \n");
        getchar();
        return;
    }

    snprintf(data_saida, sizeof(novo_atendimento.data_saida), "%02d/%02d/%04d", info->tm_mday, info->tm_mon + 1, info->tm_year + 1900);
    id_atd = criar_id_a();
    printf("Digite a descrição do atendimento:\n");
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

    novo_atendimento.id_atendimento = id_atd;
    strncpy(novo_atendimento.cpf, cpf, sizeof(novo_atendimento.cpf));
    strncpy(novo_atendimento.descricao, descricao, sizeof(novo_atendimento.descricao));
    strncpy(novo_atendimento.data_saida, data_saida, sizeof(novo_atendimento.data_saida));
    grava_atendimentos(&novo_atendimento);
    printf("Atendimento cadastrado com sucesso.\n");
    printf("ID do Atendimento: %d\n", novo_atendimento.id_atendimento);
    printf("Tecle ENTER para continuar \n");
    getchar();
}

void busca_atendimento()
{
    char cpf[12];
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                         BUSCAR UM ATENDIMENTO                        \n");
    printf("*********************************************************************\n");
    FILE *fa = fopen("./Atendimentos.dat", "rb");
    if (fa == NULL)
    {
        printf("Nenhum atendimento cadastrado até o momento.\n");
        printf("Tecle ENTER para continuar \n");
        getchar();
        return;
    }

    printf("Digite o CPF do cliente: ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0'; // Remove a quebra de linha do final do CPF

    FILE *fc = fopen("./Celulares.dat", "rb");
    if (fc == NULL)
    {
        printf("Erro ao abrir o arquivo de celulares.\n");
        printf("Tecle ENTER para continuar \n");
        getchar();
        fclose(fa);
        return;
    }

    FILE *fcli = fopen("./Clientes.dat", "rb");
    if (fcli == NULL)
    {
        printf("Erro ao abrir o arquivo de clientes.\n");
        printf("Tecle ENTER para continuar \n");
        getchar();
        fclose(fa);
        fclose(fc);
        return;
    }

    Atendimentos atendimento;
    Celulares celular;
    Clientes cliente;

    int atendimento_encontrado = 0;
    while (fread(&atendimento, sizeof(Atendimentos), 1, fa) == 1)
    {
        if (strcmp(atendimento.cpf, cpf) == 0)
        {
            atendimento_encontrado = 1;
            break;
        }
    }

    if (!atendimento_encontrado)
    {
        printf("Não foram encontrados atendimentos para o CPF informado.\n");
        printf("Tecle ENTER para continuar \n");
        getchar();
        fclose(fa);
        fclose(fc);
        fclose(fcli);
        return;
    }

    int celular_encontrado = 0;
    while (fread(&celular, sizeof(Celulares), 1, fc) == 1)
    {
        if (strcmp(celular.cpf_cliente, cpf) == 0 && celular.status != 0)
        {
            celular_encontrado = 1;
            printf("ID do Celular: %d\n", celular.id_celular);
            printf("Marca: %s\n", celular.marca);
            printf("Modelo: %s\n", celular.modelo);
            printf("__________________________________________________\n");
        }
    }

    if (!celular_encontrado)
    {
        printf("Não foi encontrado um celular cadastrado para o CPF informado no atendimento.\n");
        printf("Tecle ENTER para continuar \n");
        getchar();
        fclose(fa);
        fclose(fc);
        fclose(fcli);
        return;
    }

    int cliente_encontrado = 0;
    while (fread(&cliente, sizeof(Clientes), 1, fcli) == 1)
    {
        if (strcmp(cliente.cpf, cpf) == 0)
        {
            cliente_encontrado = 1;
            break;
        }
    }

    if (!cliente_encontrado)
    {
        printf("Não foi encontrado um cliente cadastrado para o CPF informado no atendimento.\n");
        printf("Tecle ENTER para continuar \n");
        getchar();
        fclose(fa);
        fclose(fc);
        fclose(fcli);
        return;
    }
    int id;
    printf("Digite o ID do atendimento ou '0' para voltar: ");
    scanf("%d", &id);
    getchar();

    if (id == 0)
    {
        return;
    }

    fseek(fa, 0, SEEK_SET);
    int atendimento_por_id = 0;
    while(fread(&atendimento, sizeof(Atendimentos), 1, fa) == 1)
    {
        if(atendimento.id_atendimento == id)
        {
            if(strcmp(atendimento.cpf, cpf) == 0)
            {
                atendimento_por_id = 1;
                break;
            }
        }
    }

    if(!atendimento_por_id)
    {
        printf("O ID do atendimento informado não corresponde ao CPF informado.\n");
        printf("Tecle ENTER para continuar \n");
        getchar();
        fclose(fa);
        fclose(fc);
        fclose(fcli);
        return;
    }

    system("clear || cls");
    printf("ID do Atendimento: %d\n", atendimento.id_atendimento);
    printf("ID do Celular: %d\n", celular.id_celular);
    printf("Cliente: %s\n", cliente.nome);
    printf("CPF do Cliente: %s\n", atendimento.cpf);
    printf("Descrição do atendimento: %s\n", atendimento.descricao);
    printf("Marca: %s\n", celular.marca);
    printf("Modelo: %s\n", celular.modelo);
    printf("Problema: %s\n", celular.problema);
    printf("Data de entrada: %s\n", celular.data_cadastro);
    printf("Data de Saída: %s\n", atendimento.data_saida);
    if (atendimento.status == 1)
    {
        printf("O aparelho foi consertado.\n");
    }
    else if (atendimento.status == 2)
    {
        printf("O aparelho não foi consertado.\n");
    }

    fclose(fa);
    fclose(fc);
    fclose(fcli);
    printf("\n");
    printf("Tecle ENTER para continuar \n");
    getchar();
    return;
}

void atual_atendimento()
{
    char cpf[12];
    system("clear || cls");
    int op;
    int id_atendimento;
    printf("*********************************************************************\n");
    printf("                         ATUALIZAR UM ATENDIMENTO                    \n");
    printf("*********************************************************************\n");
    FILE *fa = fopen("./Atendimentos.dat", "rb+");
    if (fa == NULL)
    {
        printf("Erro ao abrir o arquivo de atendimentos.\n");
        printf("Tecle ENTER para continuar \n");
        getchar();
        return;
    }

    FILE *fc = fopen("./Celulares.dat", "rb+");
    if (fc == NULL)
    {
        printf("Erro ao abrir o arquivo de celulares.\n");
        printf("Tecle ENTER para continuar \n");
        getchar();
        fclose(fa);
        return;
    }

    FILE *fcli = fopen("./Clientes.dat", "rb+");
    if (fcli == NULL)
    {
        printf("Erro ao abrir o arquivo de clientes.\n");
        printf("Tecle ENTER para continuar \n");
        getchar();
        fclose(fa);
        fclose(fc);
        return;
    }

    Atendimentos atendimento;
    Celulares celular;
    Clientes cliente;

    printf("Digite o CPF do cliente ou '0' para voltar:\n ");
    fgets(cpf, sizeof(cpf), stdin);
    cpf[strcspn(cpf, "\n")] = '\0'; // Remove a quebra de linha do final do CPF

    if (strcmp(cpf, "0") == 0)
    {
        return;
    }

    printf("Digite o ID do atendimento que deseja atualizar ou '0' para voltar: \n");
    scanf("%d", &id_atendimento);
    getchar();

    if (id_atendimento == 0)
    {
        limpar_buffer();
        return;
    }
    int atendimento_encontrado = 0;
    int atendimento_por_id = 0;
    while(fread(&atendimento, sizeof(Atendimentos), 1, fa) == 1)
    {
        if(atendimento.id_atendimento == id_atendimento)
        {
            atendimento_encontrado = 1; 
            if(strcmp(atendimento.cpf, cpf) == 0)
            {
                atendimento_por_id = 1;
                break;
            }
        }
    }

    if (!atendimento_encontrado)
    {
        printf("O ID do atendimento informado não existe.\n");
        printf("Tecle ENTER para continuar \n");
        getchar();
        fclose(fa);
        fclose(fc);
        fclose(fcli);
        return;
    }

    if (!atendimento_por_id)
    {
        printf("O ID do atendimento informado não corresponde ao CPF informado.\n");
        printf("Tecle ENTER para continuar \n");
        getchar();
        fclose(fa);
        fclose(fc);
        fclose(fcli);
        return;
    }

    printf(" O que deseja atualizar?\n1- Descrição\n2- O aparelho teve o probelma resolvido\n 3- Aparelho atendido é errado\n 0- Voltar\n");
    scanf("%d", &op);
    printf("Tecle ENTER para continuar \n");
    getchar();
    if (op == 0)
    {
        limpar_buffer();
        return;
    }

    if (op != 1 && op != 2 && op != 3)
    {
        printf("Opção inválida.\n");
        printf("Tecle ENTER para continuar \n");
        getchar();
        return;
}


    int celular_encontrado = 0;
    while (fread(&celular, sizeof(Celulares), 1, fc) == 1)
    {
        if (strcmp(celular.cpf_cliente, atendimento.cpf) == 0 && celular.status != 0)
        {
            celular_encontrado = 1;
            break;
        }
    }
    

    if (!celular_encontrado)
    {
        printf("Não foi encontrado um celular cadastrado para o CPF informado no atendimento.\n");
        printf("Tecle ENTER para continuar \n");
        getchar();
        fclose(fa);
        fclose(fc);
        fclose(fcli);
        return;
    }

    int cliente_encontrado = 0;
    while (fread(&cliente, sizeof(Clientes), 1, fcli) == 1)
    {
        if (strcmp(cliente.cpf, atendimento.cpf) == 0 && cliente.status != 0)
        {
            cliente_encontrado = 1;
            break;
        }
    }

    if (!cliente_encontrado)
    {
        printf("Não foi encontrado um cliente cadastrado para o CPF informado no atendimento.\n");
        printf("Tecle ENTER para continuar \n");
        getchar();
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
    printf("ID do Celular: %d\n", celular.id_celular);

    // Verificar a opção escolhida pelo usuário
    switch (op)
    {
    case 1:
        // Atualizar a descrição do problema
        printf("Digite a nova descrição do problema: ");
        fgets(atendimento.descricao, sizeof(atendimento.descricao), stdin);
        break;
    case 2:
        // Marcar o problema como resolvido
        atendimento.status = 2;
        break;
    case 3:
        // Marcar o aparelho atendido como errado
        celular.status = 1;
        break;
    default:
        printf("Opção inválida.\n");
        break;
    }

    fclose(fcli);
    // Atualizar o registro do atendimento no arquivo
    fseek(fa, (long int)-sizeof(Atendimentos), SEEK_CUR);
    fwrite(&atendimento, sizeof(Atendimentos), 1, fa);
    fclose(fa);

    // Atualizar o registro do celular no arquivo
    fseek(fc, (long int)-sizeof(Celulares), SEEK_CUR);
    fwrite(&celular, sizeof(Celulares), 1, fc);
    fclose(fc);


    printf("Tecle ENTER para continuar \n");
    getchar();
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