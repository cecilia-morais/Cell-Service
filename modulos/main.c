#include <stdio.h>
#include <stdlib.h>
#include "modulos/clientes.h"
#include "modulos/celular.h"
#include "modulos/pecas.h"
#include "modulos/relatorios.h"
#include "modulos/switchs.h"

// Assinaturas de fun??es:

char menu_principal(void);
void sobre(void);
void equipe(void);

int main(void){
char op;

        do{
            op = menu_principal(); 

            switch (op){
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

                default: 
                    printf("Op��o inv�lida");
                    break; 

            }

        } while (op != '0'); 
        printf("FIM DO PROGRAMA!");
	   return 0;
}

char menu_principal(){
    system("clear || cls");
    char menu;
    printf("*********************************************************************\n");
    printf("                           MENU PRINCIPAL                            \n");
    printf("*********************************************************************\n");
    printf("1 - Cadastro de celular \n");
    printf("2 - Clientes \n");
    printf("3 - Estoques de pe�as\n");
    printf("4 - Relat�rios\n");
    printf("5 - Sobre\n");
    printf("0 - Encerrar o programa\n");
    printf("*********************************************************************\n");
    printf("\n");
    printf("Digite o n�mero desejado:\n ");
    scanf("%c", &menu);
    getchar();
    printf("Tecle ENTER para continuar\n ");
    getchar();

    return menu;
}

void sobre(){
    system("clear || cls");
    printf("            Universidade Federal do Rio Grande do Norte\n          ");
    printf("                Centro de Ensino Superior do Serid�\n  "            );
    printf("                Disciplina DCT1106 -- Programa��o\n"                );
    printf("                      Projeto Cell Service\n  "                     );
    printf("           Esse projeto est� sendo desenvolvido para simular \n "   );
    printf("                uma loja para conserto de celular.\n"               );
    printf("                 Desenvolvido por: Cec�lia Morais\n"                );
    getchar();
}

void equipe(){
    system("clear || cls");
    printf("            Universidade Federal do Rio Grande do Norte\n          ");
    printf("                Centro de Ensino Superior do Serid�\n  "            );
    printf("                Disciplina DCT1106 -- Programa��o\n"                );
    printf("                      Projeto Cell Service\n  "                     );
    printf("                 Desenvolvido por: Cecilia Morais\n"                );   
    printf("                      GitHub: @cec�lia-morais         \n"           );  
    getchar();
}