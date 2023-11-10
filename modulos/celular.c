#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "celular.h"
#include "clientes.h"
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

void grava_celulares(Celulares* celular){
    FILE* fc;
    fc=fopen("Celulares.dat","ab");
    if (fc==NULL){
        printf("Arquivo não existe!");
        return;
    }
    fwrite(celular,sizeof(Celulares),1,fc);
    fclose(fc);
    free(celular);
}

Celulares*  novo_cell(void){
    system("clear || cls");
    Celulares* cel;
    cel=(Celulares*)malloc(sizeof(Celulares));
    char cpf_cliente;
    Celulares novo_celular;
    printf("*********************************************************************\n");
    printf("                       CADASTRAR UM NOVO CELULAR                     \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente: \n");
    scanf("%c", cpf_cliente);  
    printf("Digite a marca do aparelho:\n ");
    fgets(cel->marca, sizeof(cel->marca), stdin);
    printf("Digite o problema do aparelho: \n");
    ler_data_saida(cel->datas_entradas, cel->datas_saidas);
    fgets(cel->problema, sizeof(cel->problema), stdin);
    getchar();
    printf("Cadastro realizado com sucesso!\n");
    getchar();
    return cel;
    free(cel);


}


void busca_cell(){
    char cpf_cliente[12];
    
    system("clear || cls");
    printf("*********************************************************************\n");
    printf("                 BUSCAR CELULAR CADASTRADO POR CLIENTE               \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    fgets(cpf_cliente, sizeof(cpf_cliente), stdin);
    printf("Celulares cadastrados para o CPF %s:\n", cpf_cliente);
    
    for (int i = 0; i < qnt_celulares; i++) {
        if (strcmp(celulares[i].cpf_cliente, cpf_cliente) == 0) {
            printf("Nome do cliente: %s");
            printf("Modelo: %s", celulares[i].modelo);
            printf("Marca: %s", celulares[i].marca);
            printf("Problema do aparelho: %s", celulares[i].problema);
            printf("Data de entrada: %s", celulares [i].datas_entradas);


        }

    }
    
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