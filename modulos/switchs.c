#include "switchs.h"
#include "celular.h"
#include "clientes.h"
#include "atendimentos.h"
#include "relatorios.h"
#include <stdio.h>
#include <stdlib.h>

// Esse módulo está todas as chamadas de funções para que o menu principal dê certo
char sw_cell()
{
  char op;

  while (op != '0')
  {
    op = cad_cell();
    switch (op)
    {
    case '1':
      novo_cell();
      break;
    case '2':
      busca_cell();
      break;

    case '3':
      atual_cell();
      break;

    case '4':
      excl_cell();
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

char sw_clien()
{
  char op;
  while (op != '0')
  {
    op = cad_clien();
    switch (op)
    {
    case '1':
      novo_clien();
      break;
    case '2':
      busca_clien();
      break;

    case '3':
      atual_clien();
      break;

    case '4':
      excl_clien();
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

char sw_atendimentos()
{
  char op;
  while (op != '0')
  {

    op = area_atendimento();
    switch (op)
    {
    case '1':
      novo_atendimento();
      break;

    case '2':
      busca_atendimento();
      break;

    case '3':
      atual_atendimento();
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

char sw_relatorios()
{
  char op;
  while (op != '0')
  {

    op = relatorios();
    switch (op)
    {
    case '1':
      rel_cell();
      break;

    case '2':
      rel_clien();
      break;

    case '3':
      rel_atend();
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

char sw_sobre()
{
  char op;
  while (op != '0')
  {
    op = tela_sobre();
    switch (op)
    {
    case '1':
      sobre();
      break;

    case '2':
      equipe();
      break;

    default:
      if (op = '0')
      {
        printf("Voltando...\n");
      }
      else
      {
        printf("Opção inválida\n");
      }
      break;
    }
  }
  return op;
}

void sobre()
{
  system("clear || cls");
  printf("            Universidade Federal do Rio Grande do Norte\n          ");
  printf("                Centro de Ensino Superior do Seridó\n  ");
  printf("                Disciplina DCT1106 -- Programação\n");
  printf("                      Projeto Cell Service\n  ");
  printf("           Esse projeto está sendo desenvolvido para simular \n ");
  printf("                uma loja para conserto de celular.\n");
  printf("                 Desenvolvido por: Cecília Morais\n");
  printf("                      GitHub: @cecília-morais         \n");
  printf("                      Colaborador: Matheus Diniz\n");
  printf("                      GitHub: @matheusdiniz01         \n");
  printf("                      Colaborador: Maxsuel Gadelha\n");
  printf("                      GitHub: @maxuelgadelha         \n\n");
  printf("Tecla ENTER para continuar \n");
  getchar();
}

void equipe()
{
  system("clear || cls");
  printf("            Universidade Federal do Rio Grande do Norte\n          ");
  printf("                Centro de Ensino Superior do Seridó\n  ");
  printf("                Disciplina DCT1106 -- Programação\n");
  printf("                      Projeto Cell Service\n  ");
  printf("                 Desenvolvido por: Cecilia Morais\n");
  printf("                      GitHub: @cecília-morais         \n");
  printf("                      Colaborador: Matheus Diniz\n");
  printf("                      GitHub: @matheusdiniz01         \n");
  printf("                      Colaborador: Maxsuel Gadelha\n");
  printf("                      GitHub: @maxuelgadelha         \n\n");
  printf("Tecla ENTER para continuar \n");
  getchar();
}

char tela_sobre()
{
  system("clear || cls");
  char op;
  printf("*********************************************************************"
         "\n");
  printf("                             SOBRE                                     \n");
  printf("***********************************************************************\n");
  printf("1 - Tela sobre o projeto\n");
  printf("2 - Tela sobre a equipe\n");
  printf("Tecle ENTER para continuar \n");
  scanf("%c", &op);
  getchar();

  return op;
}
