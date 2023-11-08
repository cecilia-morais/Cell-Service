#include "validacoes.h"
#include <stdbool.h>

typedef struct celular
{
    char cpf[12];
    char modelo[20];
    char marca[15];
    char problema[100];
    char datas_entradas[9];
    char datas_saidas[9];
    int status;
}Celulares;

char cad_cell(void);
void novo_cell(void);
void busca_cell(void);
void atual_cell(void);
void excl_cell(void);