#include "validacoes.h"
#include <time.h>
#include <stdbool.h>
#ifndef CELULAR_H
#define CELULAR_H
typedef struct celular
{
    char cpf_cliente[12];
    char modelo[20];
    char marca[15];
    char problema[100];
    char data_cadastro[11];
    int status;
    
}Celulares;

#endif

char cad_cell(void);
void novo_cell(void);
void busca_cell(void);
void atual_cell(void);
void excl_cell(void);
void grava_celulares(Celulares* celular);
void todos_celulares(void);
void exibindo_celulares(Celulares* celular);
void listar_celulares(void);


 



    