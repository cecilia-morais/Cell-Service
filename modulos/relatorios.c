#include "relatorios.h"
#include "validacoes.h"
#include "clientes.h"
#include "atendimentos.h"
#include "celular.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char relatorios()
{
       char op;
       system("clear || cls");
       printf("*********************************************************************"
              "\n");
       printf("                            RELATÓRIOS                               "
              "\n");
       printf("*********************************************************************"
              "\n");
       printf("Pressione o número desejado para imprimir o relátorio de: \n ");
       printf("1 - Celular\n ");
       printf("2 - Cliente\n");
       printf(" 3- Atendimentos por dia\n");
       printf(" 0 - Sair\n");
       getchar();
       printf("Tecle ENTER para continuar \n");
       getchar();
       return op;
}

char relatorios_celulares()
{
       char op;
       system("clear || cls");
       printf("*********************************************************************"
              "\n");
       printf("                            RELATÓRIOS                               "
              "\n");
       printf("*********************************************************************"
              "\n");
       printf("Pressione o número desejado para imprimir o relátorio de: \n ");
       printf("1 - Celulares atendidos\n ");
       printf("2 - Celulares não atendidos\n");
       printf("3 - Celulares por cliente\n");
       printf("4 - Celulares por data de entrada\n");
       printf("5 - Celulares por data de saída\n");
       printf("6 - Celulares com problema resolvido\n");
       printf("7 - Celulares com problema não resolvido\n");
       printf("8 - Todos os celulares\n");
       printf("0 - Sair\n");
       printf("\n");
       printf("Digite o número desejado: \n");
       scanf("%c", &op);
       getchar();
       return op;
}

void relatorio_celulares_atendidos()
{
       system("clear || cls");
       printf("*********************************************************************\n");
       printf("                            Celulares Atendidos                      \n");
       printf("\n");
       FILE *fc = fopen("./Celulares.dat", "rb");
       if (fc == NULL)
       {
              printf("Arquivo Celulares.dat não encontrado.\n");
              return;
       }

       FILE *fc_clientes = fopen("./Clientes.dat", "rb");
       if (fc_clientes == NULL)
       {
              printf("Arquivo Clientes.dat não encontrado.\n");
              fclose(fc);
              return;
       }

       FILE *fa = fopen("./Atendimentos.dat", "rb");
       if (fa == NULL)
       {
              printf("Arquivo Atendimentos.dat não encontrado.\n");
              fclose(fc);
              fclose(fc_clientes);
              return;
       }

       Celulares cel;
       Atendimentos atd;
       Clientes cli;

       while (fread(&atd, sizeof(Atendimentos), 1, fa) == 1)
       {
              if (atd.status == 3)
              {
                     // Mostrar informações do aparelho
                     fseek(fc, (atd.id_celular - 1) * sizeof(Celulares), SEEK_SET);
                     fread(&cel, sizeof(Celulares), 1, fc);
                     printf("Informações do Aparelho:\n\n");
                     printf("ID: %d\n", cel.id_celular);
                     printf("Nome do Cliente: %s\n", cli.nome);
                     printf("CPF: %s\n", cel.cpf_cliente);
                     printf("Problema: %s\n", cel.problema);
                     printf("Marca: %s\n", cel.marca);
                     printf("Modelo: %s\n", cel.modelo);
                     printf("\n");

                     // Mostrar informações do atendimento
                     printf("Informações do Atendimento:\n\n");
                     printf("ID do atendimento: %d\n", atd.id_atendimento);
                     printf("Descrição do atendimento: %s\n", atd.descricao);
                     printf("Data de Entrada: %s\n", cel.data_cadastro);
                     printf("Data de Saída: %s\n", atd.data_saida);
                     if (atd.status == 1)
                     {
                            printf("Status: Consertado\n");
                     }
                     else if (atd.status == 2)
                     {
                            printf("Status: Não Consertado\n");
                     }
                     printf("*********************************************************************\n");
                     printf("\n");
                     getchar();
              }
       }

       fclose(fc);
       fclose(fc_clientes);
       fclose(fa);
}







