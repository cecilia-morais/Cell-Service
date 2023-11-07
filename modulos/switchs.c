#include "switchs.h"
#include "celular.h"
#include "clientes.h"
#include "pecas.h"
#include "relatorios.h"
#include <stdio.h>
#include <stdlib.h>

char sw_cell() {
  char op;
  while (op != '0') {

    op = cad_cell();

    switch (op) {
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
      if (op = '0'){
        printf("Voltando...\n");
      }else{
        printf("Opção inválida\n");
      }
      break;
    }
  }
  return op;
}

char sw_clien() {
  char op;
  while (op != '0') {

    op = cad_clien();
    switch (op) {
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
    if (op = '0'){
        printf("Voltando...\n");
      }else{
        printf("Opção inválida\n");
      }
      break;
    }
  }
  return op;
}

char sw_estoque() {
  char op;
  while (op != '0') {
    op = pecas_estoque();
    switch (op) {
    case '1':
      nova_peca();
      break;

    case '2':
      buscar_peca();
      break;

    case '3':
      atual_peca();
      break;

    case '4':
      excl_peca();
      break;

default:
    if (op = '0'){
        printf("Voltando...\n");
      }else{
        printf("Opção inválida\n");
      }
      break;
    }
  }
  return op;
}


char sw_sobre() {
  char op;
  while (op != '0') {
    op = tela_sobre();
    switch (op) {
    case '1':
      sobre();
      break;

    case '2':
      equipe();
      break;

    default:
    if (op = '0'){
        printf("Voltando...\n");
      }else{
        printf("Opção inválida\n");
      }
      break;
    }
  }
  return op;
}

void sobre() {
  system("clear || cls");
  printf("            Universidade Federal do Rio Grande do Norte\n          ");
  printf("                Centro de Ensino Superior do Seridó\n  ");
  printf("                Disciplina DCT1106 -- Programação\n");
  printf("                      Projeto Cell Service\n  ");
  printf("           Esse projeto está sendo desenvolvido para simular \n ");
  printf("                uma loja para conserto de celular.\n");
  printf("                 Desenvolvido por: Cecília Morais\n");
}

void equipe() {
  system("clear || cls");
  printf("            Universidade Federal do Rio Grande do Norte\n          ");
  printf("                Centro de Ensino Superior do Seridó\n  ");
  printf("                Disciplina DCT1106 -- Programação\n");
  printf("                      Projeto Cell Service\n  ");
  printf("                 Desenvolvido por: Cecilia Morais\n");
  printf("                      GitHub: @cecília-morais         \n");
}

char tela_sobre() {
  system("clear || cls");
  char optela;
  printf("*********************************************************************"
         "\n");
  printf("                             SOBRE                                   "
         "\n");
  printf("*********************************************************************"
         "\n");
  printf("1 - Tela sobre o projeto\n");
  printf("2 - Tela sobre a equipe\n");
  printf("Tecle ENTER para continuar \n");
  scanf("%c", &optela);
  getchar();

  return optela;
}
