#include <stdio.h>
#include <stdlib.h>
#include "celular.h"
#include "validacoes.h"

Celulares celulares[2000];
int qnt_celulares = 0;

char cad_cell(){
    system("clear || cls");
    char opcel;
    printf("*********************************************************************\n");
    printf("                          ÁREA DE CELULAR                             \n");
    printf("*********************************************************************\n");
    printf("1 - Cadastrar um novo celular\n");
    printf("2 - Buscar um celular \n");
    printf("3 - Atualizar um celular\n");
    printf("4 - Deletar um celular\n");
    printf("0 - Sair \n");
    printf("*********************************************************************\n");
    printf("\n");
    printf("Digite o número desejado: \n");
    scanf("%c", &opcel);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();

    return opcel;

}

void  novo_cell(){
    system("clear || cls");
    char cpf[12];
    char modelo[20];
    char marca[15];
    char problema[100];
    char datas_entradas[9];
    char datas_saidas[9];
    int status;
    Celulares novo_celular;
    printf("*********************************************************************\n");
    printf("                       CADASTRAR UM NOVO CELULAR                     \n");
    printf("*********************************************************************\n");
    ler_cpf(cpf);
    printf("Digite o modelo do aparelho: \n");
    fgets(modelo, sizeof(modelo), stdin);
    printf("Digite a marca do aparelho:\n ");
    fgets(marca, sizeof(marca), stdin);
    printf("Digite o problema do aparelho: \n");
    ler_data_saida(datas_entradas, datas_saidas);
    fgets(problema, sizeof(problema), stdin);
    
    printf("Tecle ENTER para continuar \n");
    strncpy(novo_celular.cpf, cpf, sizeof(novo_celular.cpf));
    strncpy(novo_celular.modelo, modelo, sizeof(novo_celular.modelo));
    strncpy(novo_celular.marca, marca, sizeof(novo_celular.marca));
    strncpy(novo_celular.problema, problema, sizeof(novo_celular.problema));
    strncpy(novo_celular.datas_entradas, datas_entradas, sizeof(novo_celular.datas_entradas));
    strncpy(novo_celular.datas_saidas, datas_saidas, sizeof(novo_celular.datas_saidas));
    novo_celular.status = 1;

    celulares[qnt_celulares] = novo_celular;

    qnt_celulares++;

    printf("Celular cadastrado com sucesso!\n");
    getchar();


}


void busca_cell(){
    char cpf[12];
    char modelo[20];
    char marca[15];
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                 BUSCAR CELULAR CADASTRADO POR CLIENTE               \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    fgets(cpf, sizeof(cpf), stdin);
    printf("Digite o modelo do aparelho: \n");
    fgets(modelo, sizeof(modelo), stdin);
    printf("Digite a marca do aparelho:\n ");
    fgets(marca, sizeof(marca), stdin);
    printf("Tecle ENTER para continuar \n");
    getchar();
}


void atual_cell(){
    char cpf[12];
    char modelo[20];
    char marca[15];
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                         ATUALIZAR UM CELULAR                        \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    fgets(cpf, sizeof(cpf), stdin);
    printf("Digite o modelo do aparelho: \n");
    fgets(modelo, sizeof(modelo), stdin);
    printf("Digite a marca do aparelho:\n ");
    fgets(marca, sizeof(marca), stdin);
    printf("Tecle ENTER para continuar \n");
    getchar();
}

 void excl_cell(){
    char cpf[12];
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                         DELETAR UM CELULAR                          \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    fgets(cpf, sizeof(cpf), stdin);
    printf("Tecle ENTER para continuar \n");
    getchar();
}