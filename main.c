#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void menu_principal(void);
void sobre(void);
void equipe(void);
void cad_cell(void);
void novo_cell(void);
void busca_cell(void);

int main(void)
{
    setlocale (LC_ALL , "Portuguese");
    menu_principal();
    cad_cell();
    novo_cell();
    busca_cell();
	sobre();
    equipe();

	   return 0;
}

void sobre(){
    system("clear || cls");
    printf("            Universidade Federal do Rio Grande do Norte\n          ");
    printf("                Centro de Ensino Superior do Seridó\n  "            );
    printf("                Disciplina DCT1106 -- Programação\n"                );
    printf("                      Projeto Cell Service\n  "                     );
    printf("           Esse projeto está sendo desenvolvido para simular \n "   );
    printf("                uma loja para conserto de celular.\n"               );
    printf("                 Desenvolvido por: Cecilia Morais\n"                );
    getchar();
}

void equipe(){
    system("clear || cls");
    printf("            Universidade Federal do Rio Grande do Norte\n          ");
    printf("                Centro de Ensino Superior do Seridó\n  "            );
    printf("                Disciplina DCT1106 -- Programação\n"                );
    printf("                      Projeto Cell Service\n  "                     );
    printf("                 Desenvolvido por: Cecilia Morais\n"                );   
    printf("                      GitHub: @cecília-morais         \n"           );  
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
    printf("3 - Controle de aparelhos: \n");
    printf("4 - Estoques de peças\n");
    printf("5 - Relatórios\n");
    printf("6 - Sobre o programa\n");
    printf("7 - Sobre a equipe\n");
    printf("0 - Encerrar o programa\n");
    printf("*********************************************************************\n");
    printf("\n");
    printf("Digite o número desejado:\n ");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar\n ");
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
    printf("Digite o número desejado: \n");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();


}

void novo_cell(){
system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                       CADASTRAR UM NOVO CELULAR                     \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    scanf("%c", &op);
    getchar();
    printf("Digite o modelo do aparelho: \n");
    scanf("%c", &op);
    getchar();
    printf("Digite a marca do aparelho:\n ");
    scanf("%c", &op);
    getchar();
    printf("Digite o problema do aparelho: \n");
    scanf("%c", &op);
    getchar();
    printf("Digite a data de entrada do aparelho:\n ");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}

void busca_cell(){
    system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                 BUSCAR CELULAR CADASTRADO POR CLIENTE               \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    scanf("%c", &op);
    getchar();
    printf("Digite o modelo do aparelho: \n");
    scanf("%c", &op);
    getchar();
    printf("Digite a marca do aparelho:\n ");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();


}

