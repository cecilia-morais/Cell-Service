#include "relatorios.h"
#include "validacoes.h"
#include "clientes.h"
#include "atendimentos.h"
#include "celular.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void listar_celulares(void); // Forward declaration

char relatorios()
{
       char opr;
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
       printf(" 3- Atendimentos\n");
       printf(" 0 - Sair\n");
       printf("Digite a opção desejada: ");
       scanf("%c", &opr);
       getchar();
       printf("Tecle ENTER para continuar \n");
       getchar();
       return opr;
}

char relatorios_clientes()
{
       char opr;
       system("clear || cls");
       printf("*********************************************************************"
              "\n");
       printf("                       RELATÓRIOS CLIENTES                             "
              "\n");
       printf("*********************************************************************"
              "\n");
       printf("Pressione o número desejado para imprimir o relátorio de: \n ");
       printf("1 - Clientes por ordem alfabética\n ");
       printf("2 - Todos os clientes\n");
       printf(" 0 - Sair\n");
       printf("Digite a opção desejada: ");
       scanf("%c", &opr);
       getchar();
       printf("Tecle ENTER para continuar \n");
       getchar();
       return opr;
}

char rel_clien()
{
       char op;
       while (op != '0')
       {
              op = relatorios_clientes();
              switch (op)
              {
              case '1':
                     clientes_por_ordem_alfabetica();
                     break;
              case '2':
                     todos_clientes();
                     break;
              default:
                     if (op = '0')
                     {
                            printf("Voltando...\n");
                            getchar();
                     }
                     else
                     {
                            printf("Opção inválida\n");
                            getchar();
                     }
                     break;
              }
       }
       return op;
}

char relatorios_celulares()
{
       char opr;
       system("clear || cls");
       printf("*********************************************************************"
              "\n");
       printf("                       RELATÓRIOS CELULARES                             "
              "\n");
       printf("*********************************************************************"
              "\n");
       printf("Pressione o número desejado para imprimir o relátorio de: \n ");
       printf("1 - Celulares por data de cadastro \n ");
       printf("2 - Todos os celulares\n");
       printf(" 0 - Sair\n");
       printf("Digite a opção desejada: ");
       scanf("%c", &opr);
       getchar();
       printf("Tecle ENTER para continuar \n");
       getchar();
       return opr;
}

void celulares_atendidos()
{
}

char rel_cell()
{
       char op;
       while (op != '0')
       {
              op = relatorios_celulares();
              switch (op)
              {
              case '1':
                     celulares_por_data_de_entrada();
                     break;
              case '2':
                     todos_celulares();
                     break;
              default:
                     if (op = '0')
                     {
                            printf("Voltando...\n");
                            getchar();
                     }
                     else
                     {
                            printf("Opção inválida\n");
                            getchar();
                     }
                     break;
              }
       }
       return op;
}

char relatorios_atendimentos()
{
       char opr;
       system("clear || cls");
       printf("*********************************************************************"
              "\n");
       printf("                       RELATÓRIOS ATENDIMENTOS                             "
              "\n");
       printf("*********************************************************************"
              "\n");
       printf("Pressione o número desejado para imprimir o relátorio de: \n ");
       printf("1 - Atendimentos por data\n ");
       printf("2 - Todos os atendimentos\n");
       printf(" 0 - Sair\n");
       printf("Digite a opção desejada: ");
       scanf("%c", &opr);
       getchar();
       printf("Tecle ENTER para continuar \n");
       getchar();
       return opr;
}

char rel_atend()
{
       char op;
       while (op != '0')
       {
              op = relatorios_atendimentos();
              switch (op)
              {
              case '1':
                     atendimentos_por_data_de_saida();
                     break;
              case '2':
                     todos_atendimentos();
                     break;
              default:
                     if (op = '0')
                     {
                            printf("Voltando...\n");
                            getchar();
                     }
                     else
                     {
                            printf("Opção inválida\n");
                            getchar();
                     }
                     break;
              }
       }
       return op;
}

void atendimentos_por_data_de_saida()
{
       char data[11];
       system("clear || cls");
       printf("*********************************************************************\n");
       printf("                       ATENDIMENTOS POR DATA                             \n");
       printf("*********************************************************************\n");
       printf("Digite a data desejada em que o aparelho : ");
       scanf("%s", data);
       getchar();
       printf("Tecle ENTER para continuar \n");
       getchar();

       FILE *fa = fopen("./Atendimentos.dat", "rb");
       if (fa == NULL)
       {
              printf("Arquivo Atendimentos.dat não encontrado.\n");
              printf("Tecle ENTER para continuar \n");
              getchar();
              return;
       }
       FILE *fc = fopen("./Clientes.dat", "rb");
       if (fc == NULL)
       {
              printf("Arquivo Atendimentos.dat não encontrado.\n");
              printf("Tecle ENTER para continuar \n");
              getchar();
              return;
       }
       FILE *fc_celulares = fopen("./Celulares.dat", "rb");
       if (fc_celulares == NULL)
       {
              printf("Arquivo Celulares.dat não encontrado.\n");
              printf("Tecle ENTER para continuar \n");
              getchar();
              return;
       }

       Celulares celular;
       Clientes cliente;
       Atendimentos atendimento;
       int found = 0;

       while (fread(&atendimento, sizeof(Atendimentos), 1, fa) == 1)
       {
              if (strcmp(atendimento.data_saida, data) == 0 && atendimento.status != 0)
              {
                     printf("ID atendimento: %d\n", atendimento.id_atendimento);
                     printf("Data: %s\n", atendimento.data_saida);
                     printf("Descrição do atendimento: %s\n", atendimento.descricao);
                     

                     while (fread(&celular, sizeof(Celulares), 1, fc_celulares) == 1)
                     {
                            if (strcmp(celular.cpf_cliente, atendimento.cpf) == 0)
                            {
                                   printf("ID celular: %d\n", celular.id_celular);
                                   printf("Modelo: %s\n", celular.modelo);
                                   printf("Marca: %s\n", celular.marca);
                                   printf("Problema: %s\n", celular.problema);
                                   printf("Data de entrada: %s\n", celular.data_cadastro);
                                   break;
                            }
                     fseek(fc_celulares, 0, SEEK_SET);
                     }

                     while (fread(&cliente, sizeof(Clientes), 1, fc) == 1)
                     {
                            if (strcmp(cliente.cpf, atendimento.cpf) == 0)
                            {
                                   printf("CLIENTE:\n");
                                   printf("Nome: %s\n", cliente.nome);
                                   printf("CPF: %s\n", cliente.cpf);
                                   printf("Email: %s\n", cliente.email);
                                   printf("Telefone: %s\n", cliente.telefone);
                                   break;
                            }
                     }
                     fseek(fc, 0, SEEK_SET);
                     if (atendimento.status == 1)
                     {
                            printf("O aparelho foi consertado.\n");
                            printf("Tecle ENTER para continuar \n");
                            getchar();
                     }
                     else if (atendimento.status == 2)
                     {
                            printf("O aparelho não foi consertado.\n");
                            printf("Tecle ENTER para continuar \n");
                            getchar();
                     }

                     printf("***************************************\n");
                     found = 1;
              }
       }

       // Close the file
       fclose(fa);
       fclose(fc);
       fclose(fc_celulares);

       if (!found)
       {
              printf("Nenhum atendimento encontrado para a data especificada.\n");
       }

       printf("Tecle ENTER para continuar \n");
       getchar();
}

void celulares_por_data_de_entrada()
{
       // FUNÇÃO FEITA COM AJUDA DO CHATGPT
       system("clear || cls");
       printf("*********************************************************************"
              "\n");
       printf("                      CELULARES POR DATA DE ENTRADA                   "
              "\n");
       printf("*********************************************************************"
              "\n");
       printf("Digite a data de entrada desejada (formato: dd/mm/aaaa): ");
       char data[11];
       fgets(data, sizeof(data), stdin);
       data[strcspn(data, "\n")] = '\0'; // Remove o caractere de nova linha

       FILE *fc_celulares = fopen("./Celulares.dat", "rb");
       if (fc_celulares == NULL)
       {
              printf("Arquivo Celulares.dat não encontrado.\n");
              printf("Tecle ENTER para continuar \n");
              getchar();
              return;
       }

       // Obter o número total de registros no arquivo
       fseek(fc_celulares, 0, SEEK_END);
       long int num_registros = ftell(fc_celulares) / sizeof(Celulares);
       rewind(fc_celulares);

       // Ler todos os registros de celulares para um array
       Celulares *celulares = (Celulares *)malloc(num_registros * sizeof(Celulares));
       fread(celulares, sizeof(Celulares), num_registros, fc_celulares);

       // Filtrar os registros pela data de entrada desejada
       int found = 0;
       for (int i = 0; i < num_registros; i++)
       {
              if (strcmp(celulares[i].data_cadastro, data) == 0)
              {
                     printf("ID: %d\n", celulares[i].id_celular);
                     printf("CPF: %s\n", celulares[i].cpf_cliente);
                     printf("Marca: %s\n", celulares[i].marca);
                     printf("Modelo: %s\n", celulares[i].modelo);
                     printf("Problema: %s\n", celulares[i].problema);
                     printf("Data de Entrada: %s\n", celulares[i].data_cadastro);
                     printf("******************************\n");
                     getchar();
                     found = 1;
              }
       }

       if (!found)
       {
              printf("Nenhum celular encontrado com a data de entrada especificada.\n");
              getchar();
              return;
       }

       printf("Tecle ENTER para continuar \n");
       getchar();

       free(celulares);
       fclose(fc_celulares);
}

// void celulares_atendidos_e_nao_atendidos()
// {
//        // FUNÇÃO FEITA COM AJUDA DO CHATGPT
//        system("clear || cls");
//        printf("*********************************************************************"
//                  "\n");
//        printf("              CELULARES ATENDIDOS E NÃO ATENDIDOS                   "
//                  "\n");
//        printf("*********************************************************************"
//                  "\n");

//        FILE *fc_celulares = fopen("./Celulares.dat", "rb");
//        if (fc_celulares == NULL)
//        {
//               printf("Arquivo Celulares.dat não encontrado.\n");
//               printf("Tecle ENTER para continuar \n");
//               getchar();
//               return;
//        }

//        // Obter o número total de registros no arquivo
//        fseek(fc_celulares, 0, SEEK_END);
//        long int num_registros = ftell(fc_celulares) / sizeof(Celulares);
//        rewind(fc_celulares);

//        // Contadores para celulares atendidos e não atendidos
//        int atendidos = 0;
//        int nao_atendidos = 0;

//        // Ler todos os registros de celulares para um array
//        Celulares *celulares = (Celulares *)malloc(num_registros * sizeof(Celulares));
//        fread(celulares, sizeof(Celulares), num_registros, fc_celulares);

//        // Verificar se cada celular foi atendido ou não
//        for (int i = 0; i < num_registros; i++)
//        {
//               if (celulares[i].atendido)
//               {
//                      atendidos++;
//               }
//               else
//               {
//                      nao_atendidos++;
//               }
//        }

//        printf("Número de celulares atendidos: %d\n", atendidos);
//        printf("Número de celulares não atendidos: %d\n", nao_atendidos);

//        printf("Tecle ENTER para continuar \n");
//        getchar();

//        free(celulares);
//        fclose(fc_celulares);
// }

void clientes_por_ordem_alfabetica()
{
       // FUNÇÃO FEITA COM AJUDA DO CHATGPT
       system("clear || cls");
       printf("*********************************************************************"
              "\n");
       printf("                    CLIENTES POR ORDEM ALFABÉTICA                              "
              "\n");
       printf("*********************************************************************"
              "\n");

       FILE *fc_clientes = fopen("./Clientes.dat", "rb");
       if (fc_clientes == NULL)
       {
              printf("Arquivo Clientes.dat não encontrado.\n");
              printf("Tecle ENTER para continuar \n");
              getchar();
              return;
       }

       // Obter o número total de registros no arquivo
       fseek(fc_clientes, 0, SEEK_END);
       long int num_registros = ftell(fc_clientes) / sizeof(Clientes);
       rewind(fc_clientes);

       // Ler todos os registros de clientes para um array
       Clientes *clientes = (Clientes *)malloc(num_registros * sizeof(Clientes));
       fread(clientes, sizeof(Clientes), num_registros, fc_clientes);

       // Ordenar os registros em ordem alfabética pelo nome do cliente
       for (int i = 0; i < num_registros - 1; i++)
       {
              for (int j = i + 1; j < num_registros; j++)
              {
                     if (strcmp(clientes[i].nome, clientes[j].nome) > 0)
                     {
                            Clientes temp = clientes[i];
                            clientes[i] = clientes[j];
                            clientes[j] = temp;
                     }
              }
       }

       // Exibir os clientes em ordem alfabética
       for (int i = 0; i < num_registros; i++)
       {
              printf("Nome: %s\n", clientes[i].nome);
              printf("CPF: %s\n", clientes[i].cpf);
              printf("Email: %s\n", clientes[i].email);
              printf("Telefone: %s\n", clientes[i].telefone);
              printf("******************************\n");
       }

       free(clientes);
       fclose(fc_clientes);

       printf("Tecle ENTER para continuar \n");
       getchar();
}

void todos_celulares(void)
{
       system("clear || cls");
       listar_celulares();
       getchar();
       getchar();
}

void exibindo_celulares(Celulares *celular)
{
       FILE *fc = fopen("./Celulares.dat", "rb");
       if (fc == NULL)
       {
              printf("Arquivo Celulares.dat não encontrado.\n");
              printf("Tecle ENTER para continuar \n");
              getchar();
              fclose(fc);
              return;
       }

       FILE *fc_clientes = fopen("./Clientes.dat", "rb");
       if (fc_clientes == NULL)
       {
              printf("Arquivo Clientes.dat não encontrado.\n");
              printf("Tecle ENTER para continuar \n");
              getchar();
              fclose(fc);
              return;
       }

       FILE *fa = fopen("./Atendimentos.dat", "rb");
       if (fa == NULL)
       {
              printf("Arquivo de atendimentos não encontrado.\n");
              printf("Tecle ENTER para continuar \n");
              getchar();
              fclose(fc);
              return;
       }

       Celulares cel;
       while (fread(&cel, sizeof(Celulares), 1, fc))
       {
              if (cel.status != 0)
              {
                     printf("CELULAR ENCONTRADO:\n\n");
                     printf("ID DO APARELHO: %d\n", cel.id_celular);
                     printf("MODELO: %s\n", cel.modelo);
                     printf("MARCA: %s\n", cel.marca);
                     printf("PROBLEMA: %s\n", cel.problema);
                     printf("DATA DE ENTRADA: %s\n", cel.data_cadastro);

                     Atendimentos atendimento;
                     if (fread(&atendimento, sizeof(Atendimentos), 1, fa))
                     {
                            if (cel.status == 3)
                            {
                                   printf("Data de saída: %s\n", atendimento.data_saida);
                                   printf("ID do Atendimento: %d\n", atendimento.id_atendimento);
                                   printf("Descrição do Problema: %s\n", atendimento.descricao);
                                   printf("Celular foi atendido!\n");
                                   if (atendimento.status == 1)
                                   {
                                          printf("O aparelho foi consertado.\n");
                                          printf("Tecle ENTER para continuar \n");
                                          getchar();
                                   }
                                   else if (atendimento.status == 2)
                                   {
                                          printf("O aparelho não foi consertado.\n");
                                          printf("Tecle ENTER para continuar \n");
                                          getchar();
                                   }
                            }
                     }

                     // Buscar o nome do cliente no arquivo Clientes.dat
                     Clientes clientes;
                     if (fread(&clientes, sizeof(Clientes), 1, fc_clientes))
                     {
                            if (strcmp(clientes.cpf, cel.cpf_cliente) == 0)
                            {
                                   printf("Nome do cliente: %s\n", clientes.nome);
                                   printf("CPF do cliente: %s\n", clientes.cpf);
                                   printf("Email do cliente: %s\n", clientes.email);
                                   printf("Telefone do cliente: %s\n", clientes.telefone);
                                   printf("Tecle ENTER para continuar \n");
                                   getchar();
                                   return;
                            }
                     }
              }
       }
       getchar();

       fclose(fc);
       fclose(fc_clientes);
       fclose(fa);
}

void listar_celulares(void)
{
       FILE *fc;
       Celulares *cel;
       cel = (Celulares *)malloc(sizeof(Celulares));
       fc = fopen("./Celulares.dat", "rb");
       if (fc == NULL)
       {
              printf("Arquivo não existente");
              printf("Tecle ENTER para continuar \n");
              getchar();
              return;
       }
       while (fread(cel, sizeof(Celulares), 1, fc))
       {
              if (cel->status != 0)
              {
                     exibindo_celulares(cel);
                     getchar();
              }
       }
       fclose(fc);
       free(cel);
}

void todos_clientes(void)
{
       system("clear || cls");
       listar_cliente();
       getchar();
}

void exibindo_clientes(Clientes *clientes)
{
       char situ[17];
       if ((clientes == NULL) || (clientes->status == 0))
       {
              printf("\nEsse cliente não existe no sistema\n");
       }
       else
       {
              printf("************************");
              printf("\nDADOS DOS CLIENTES\n");
              printf("\n");
              printf("Nome: %s", clientes->nome);
              printf("CPF: %s\n", clientes->cpf);
              printf("Email: %s\n", clientes->email);
              printf("Telefone: %s\n", clientes->telefone);
              if (clientes->status == '1')
              {
                     strcpy(situ, "cadastrados");
                     getchar();
              }
              else if (clientes->status == '0')
              {
                     strcpy(situ, "Fechado");
                     getchar();
              }
       }
}

void listar_cliente(void)
{
       FILE *fc;
       Clientes *cli;
       cli = (Clientes *)malloc(sizeof(Clientes));
       fc = fopen("./Clientes.dat", "rb");
       if (fc == NULL)
       {
              printf("Arquivo não existente\n");
              printf("Tecle ENTER para continuar \n");
              getchar();
              return;
       }
       while (fread(cli, sizeof(Clientes), 1, fc))
       {
              if (cli->status != 0)
              {
                     exibindo_clientes(cli);
                     getchar();
              }
       }
       fclose(fc);
       free(cli);
}

void todos_atendimentos(void)
{
       listar_atendimentos();
       getchar();
       getchar();
}

void exibindo_atendimentos(Atendimentos *atendimento)
{
       FILE *fa = fopen("./Atendimentos.dat", "rb");
       if (fa == NULL)
       {
              printf("Arquivo de atendimentos não encontrado.\n");
              printf("Tecle ENTER para continuar \n");
              getchar();
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
              printf("Tecle ENTER para continuar \n");
              getchar();
              return;
       }
       while (fread(ate, sizeof(Atendimentos), 1, fa))
       {
              exibindo_atendimentos(ate);
              getchar();
       }
       fclose(fa);
       free(ate);
}

bool verificar_cpf_existente(const char *cpf)
{
       FILE *fc = fopen("./Clientes.dat", "rb");
       if (fc == NULL)
       {
              printf("Arquivo de clientes não encontrado.\n");
              printf("Tecle ENTER para continuar \n");
              getchar();
              return false;
       }

       Clientes cliente;
       while (fread(&cliente, sizeof(Clientes), 1, fc))
       {
              if (strcmp(cliente.cpf, cpf) == 0)
              {
                     fclose(fc);
                     return true;
              }
       }

       fclose(fc);
       return false;
}
