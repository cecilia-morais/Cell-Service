#include <stdio.h>
#include <stdlib.h>


// Assinaturas de fun��es:

void menu_principal(void);
void sobre(void);
void equipe(void);
void cad_cell(void);
void novo_cell(void);
void busca_cell(void);
void atual_cell(void);
void excl_cell(void);
void cad_clien(void);
void novo_clien(void);
void busca_clien(void);
void atual_clien(void);
void excl_clien(void);

int main(void){
    menu_principal();
    cad_cell();
    novo_cell();
    busca_cell();
    atual_cell();
    excl_cell();
    cad_clien();
    novo_clien();
    busca_clien();
    atual_clien();
    excl_clien();
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
    printf("                 Desenvolvido por: Cecília Morais\n"                );
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

// Fun��es do m�dulo 1:

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

void atual_cell(){
    system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                         ATUALIZAR UM CELULAR                        \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    scanf("%c", &op);
    getchar();
    printf("Digite o modelo do aparelho: \n");
    scanf("%c", &op);
    getchar();
    printf("Digite a marca do aparelho:\n ");
    scanf("%c", &op);
    printf("Tecle ENTER para continuar \n");
    getchar();
}

void excl_cell(){
    system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                         DELETAR UM CELULAR                          \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}

// Fun��es do m�dulo 2:
void cad_clien(){
    system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                          ÁREA DE CLIENTES                           \n");
    printf("*********************************************************************\n");
    printf("1 - Cadastrar um novo cliente\n");
    printf("2 - Buscar um cliente \n");
    printf("3 - Atualizar um cliente\n");
    printf("4 - Deletar um cliente\n");
    printf("5 - Sair \n");
    printf("*********************************************************************\n");
    printf("\n");
    printf("Digite o número desejado: \n");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}

void novo_clien(){
system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                       CADASTRAR UM NOVO CLIENTE                     \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    scanf("%c", &op);
    getchar();
    printf("Digite o nome completo do cliente: \n");
    scanf("%c", &op);
    getchar();
    printf("Digite a data de nascimento do cliente:\n ");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}

void busca_clien(){
    system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                           BUSCAR POR CLIENTE                        \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}

void atual_clien(){
    system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                         ATUALIZAR UM CLIENTE                        \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    scanf("%c", &op);
    getchar();
    printf("Digite '1' se deseja alterar o nome do cliente ou '2' se deseja alterar a data de nascimento do cliente: \n");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}

void excl_clien(){
    system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                         DELETAR UM CLIENTE                          \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    scanf("%c", &op);
    getchar();
    printf("Tem certeza que quer continuar a operação? ");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}