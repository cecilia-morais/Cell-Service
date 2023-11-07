#include "validacoes.h"
#ifndef CLIENTES_H
#define CLIENTES_H
typedef struct clientes
{
    char cpf[12];
    char nome[70];
    char email[100];
    char telefone[15];
}Clientes;

#endif
char cad_clien(void);
void novo_clien(void);
void busca_clien(void);
char atual_clien(void);
// char excl_clien(void);


