#include "modulos/switchs.h"
#include "modulos/celular.h"
#include "modulos/clientes.h"
#include "modulos/relatorios.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Assinaturas de fun��es:
char menu_principal(void);
void tela_inicial(void);
void tela_carregamento(void);

int main(void)
{
  tela_carregamento();

  char op;
  do
  {
    tela_inicial();
    system("clear || cls");
    op = menu_principal();

    switch (op)
    {
    case '1':
      sw_cell();
      break;

    case '2':
      sw_clien();
      break;

    case '3':
      sw_atendimentos();
      break;

    case '4':
      relatorios();
      break;

    case '5':
      sw_sobre();
      break;

    default:
      if (op = '0')
      {
        printf("Encerrando...\n");
      }
      else
      {
        printf("Opção inválida\n");
      }
      break;
    }

  } while (op != '0');
  printf("FIM DO PROGRAMA!");
  return 0;
}

char menu_principal()
{
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
  printf("3 - Atendimentos\n");
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

void tela_inicial()
{ // Função feita com ajuda do ChatGPT e aprimorada por Cecilia Morais
  system("clear || cls");
  char *cores[] = {"\033[0;31m", "\033[0;32m", "\033[0;34m", "\033[0;35m", "\033[0;36m"};
  int num_cores = sizeof(cores) / sizeof(cores[0]);

  int i, j;
  for (j = 0; j < 3; j++)
  { // Altere o número de iterações conforme necessário

    for (i = 0; i < num_cores; i++)
    {
      printf("%s", cores[i]);
      printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n"
        "        ______________                                                           \n"
        "       |     ====     |                                                          \n"
        "       | ____________ |          ,,---.     ,---.                 o              \n"
        "       ||            ||         ||          `---.,---.,--. .    ,.,---.,---.     \n"
        "       ||            ||         ||              ||---'|     \\ / ||    |---'     \n"
        "       ||            ||          ``---' o   `---'`---'`      V   ``---'`---'     \n"
        "       ||            ||               __________________________________________ \n"
        "       ||            ||                    A sua loja de conserto de celulares!! \n"
        "       ||            ||                                                          \n"
        "       ||____________||                                                          \n"
        "       |       o      |                                                          \n"
        "       |______________|                                                          \n"
        "                                                                                 \n"
        "     >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
      printf("\033[0m"); // Código de escape para restaurar a cor padrão
      // Aguarde um curto período para criar o efeito de piscar
      usleep(500000);
      system("clear || cls"); // Limpar a tela
    }
  }
}



void tela_carregamento()
{
  system("clear || cls");
  printf("                           INICIANDO..");

  int i;
  for (i = 0; i < 3; i++)
  {
    printf(".");
    fflush(stdout);  // Limpar o buffer de saída para garantir que os pontos apareçam imediatamente
    usleep(500000);  // Aguardar 500ms entre cada ponto
    printf("\b \b"); // Apagar o ponto anterior usando caracteres de retorno (\b) e espaço em branco
    fflush(stdout);  // Limpar novamente o buffer de saída
    usleep(500000);  // Aguardar mais 500ms antes do próximo ponto
  }
  printf("\n");
}
