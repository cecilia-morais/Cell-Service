#include "validacoes.h"
#include <stdbool.h>

typedef struct celular
{
    int cpf[12];
    char modelo[20];
    char marca[15];
    char problema[100];
    char datas_entradas[9];
    char datas_saidas[9];
}Celulares;

char cad_cell(void);
Celulares* novo_cell(void);
char busca_cell(void);
char atual_cell(void);
char excl_cell(void);