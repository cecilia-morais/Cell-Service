#include "switchs.h"
#include "celular.h"
#include "clientes.h"
#include "pecas.h"
#include "relatorios.h"
#include <stdio.h>
#include <stdlib.h>

// Assinaturas de fun��es:
char menu_principal(void);


int main(void) {
  char op;

  do {
    op = menu_principal();

    switch (op) {
    case '1':
      sw_cell();
      break;

    case '2':
      sw_clien();
      break;

    case '3':
      sw_estoque();
      break;

    case '4':
      relatorios();
      break;
    case '5':
      sw_sobre();
      break;

    default:
      printf("Opção inválida");
      break;
    }

  } while (op != '0');
  printf("FIM DO PROGRAMA!");
  return 0;
}

char menu_principal() {
  system("clear || cls");
  char menu;
  printf("*********************************************************************"
         "\n");
  printf("                           MENU PRINCIPAL                            "
         "\n");
  printf("*********************************************************************"
         "\n");
  printf("1 - Cadastro de celular \n");
  printf("2 - Clientes \n");
  printf("3 - Estoques de peças\n");
  printf("4 - Relatórios\n");
  printf("5 - Sobre\n");
  printf("0 - Encerrar o programa\n");
  printf("*********************************************************************"
         "\n");
  printf("\n");
  printf("Digite o número desejado:\n ");
  scanf("%c", &menu);
  getchar();
  printf("Tecle ENTER para continuar\n ");
  getchar();

  return menu;
}

