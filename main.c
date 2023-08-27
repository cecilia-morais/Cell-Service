#include <stdio.h>
#include <stdlib.h>

void menu_principal(void);
void sobre(void);

int main(void)
{
    menu_principal();

	sobre();	
	   return 0;
}

void sobre(){
    printf("            Universidade Federal do Rio Grande do Norte\n          ");
    printf("                Centro de Ensino Superior do Seridó\n  "            );
    printf("                Disciplina DCT1106 -- Programação\n"                );
    printf("                      Projeto Cell Service\n  "                     );
    printf("           Esse projeto está sendo desenvolvido para simular \n "   );
    printf("                uma loja para conserto de celular.\n"               );
    printf("                 Desenvolvido por: Cecilia Morais\n"                );
}

void menu_principal(){
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                           MENU PRINCIPAL                            \n");
    printf("*********************************************************************\n");
    printf("1 - Cadastro de celular \n");
    printf("2 - Clientes \n");
    printf("3 - Estoques de peças\n");
    printf("4 - Relatórios\n");
    printf("5 - Sobre o programa\n");
    printf("6 - Encerrar o programa\n");
    
}