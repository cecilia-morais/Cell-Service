#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void menu_principal(void);
void sobre(void);
void equipe(void);
void cad_cell(void);


int main(void)
{
    setlocale (LC_ALL , "Portuguese");
    menu_principal();
    cad_cell();
	sobre();
    equipe();

	   return 0;
}

void sobre(){
    system("clear || cls");
    printf("            Universidade Federal do Rio Grande do Norte\n          ");
    printf("                Centro de Ensino Superior do Serid�\n  "            );
    printf("                Disciplina DCT1106 -- Programa��o\n"                );
    printf("                      Projeto Cell Service\n  "                     );
    printf("           Esse projeto est� sendo desenvolvido para simular \n "   );
    printf("                uma loja para conserto de celular.\n"               );
    printf("                 Desenvolvido por: Cecilia Morais\n"                );
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

void menu_principal(){
    system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                           MENU PRINCIPAL                            \n");
    printf("*********************************************************************\n");
    printf("1 - Cadastro de celular \n");
    printf("2 - Clientes \n");
    printf("3 - Estoques de pe�as\n");
    printf("4 - Relat�rios\n");
    printf("5 - Sobre o programa\n");
    printf("6 - Sobre a equipe\n");
    printf("7 - Encerrar o programa\n");
    printf("*********************************************************************\n");
    printf("\n");
    printf("Digite o n�mero desejado: ");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar ");
    getchar();
}

void cad_cell(){
    system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                          CADASTRO DE CELULAR                        \n");
    printf("*********************************************************************\n");
    printf("1 - Cadastrar um novo celular\n");
    printf("2 - Buscar um celular \n");
    printf("3 - Atualizar um celular\n");
    printf("4 - Deletar um celular\n");
    printf("5 - Sair \n");
    printf("*********************************************************************\n");
    printf("\n");
    printf("Digite o n�mero desejado: ");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar ");
    getchar();


}