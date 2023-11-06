#include <stdio.h>
#include <stdlib.h>
#include "atendimentos.h"

char area_atendimento(){
    system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                            ATENDIMENTOS                             \n");
    printf("*********************************************************************\n");
    printf("1 - Cadastrar um novo atendimento\n");
    printf("2 - Buscar um atendimento \n");
    printf("3 - Atualizar um atendimento\n");
    printf("4 - Deletar um atendimento\n");
    printf("0 - Sair \n");
    printf("*********************************************************************\n");
    printf("\n");
    printf("Digite o número desejado: \n");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();

    return op;

}

char novo_atendimento(){
    char nCPF[12];
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                           NOVO ATENDIMENTO                          \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");//aqui será mostrada uma lista de celulares disponiveis para aquele cpf
    fgets(nCPF, sizeof(nCPF), stdin);
    printf("Digite o ID do celular para atendimento\n");
    getchar();// quando fizer o if e elseif será feito o crud de atendimentos
    printf("Tecle ENTER para continuar \n");
    getchar();
}

char busca_atendimento(){
    system("clear || cls");
    int op;
    printf("*********************************************************************\n");
    printf("                           BUSCAR ATENDIMENTO                        \n");
    printf("*********************************************************************\n");
    printf("Tecle 1 para ver celulares em atendimentos e 2 para celulares finalizados");
    scanf("%d", op);
    getchar();
    // if (op == 1){

    // }else if{
        
    // }
    printf("Tecle ENTER para continuar \n");
    getchar();

    return op;
}

char atual_atendimento(){
    int nCPF[12];
    system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                         ATUALIZAR UM ATENDIMENTO                    \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    fgets(nCPF, sizeof(nCPF), stdin);
    printf("Digite o ID do aparelho que deseja atualizar: \n");
    getchar();
    printf(" 1- Deseja finalizar o atendimento ou 2 -alterar alguma informação no atendimento?\n ");
    // if (op == 1){

    // }else if{
        
    // }
    printf("Tecle ENTER para continuar \n");
    getchar();

    return op;
}
 // NAO EXISTIRÁ O DELETE UM ATENDIMENTO PARA QUE TODOS OS ATENDIMENTOS, INCLUINDO OS CANCELADOS, FIQUEM REGISTRADOS!!