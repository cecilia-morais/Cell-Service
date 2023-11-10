#include "validacoes.h"
#ifndef CLIENTES_H
#define CLIENTES_H
typedef struct clientes
{
    char cpf[12];
    char nome[70];
    char email[100];
    char telefone[15];
    int status;
}Clientes;

#endif
char cad_clien(void);
Clientes* novo_clien(void);
void busca_clien(void);
void atual_clien(void);
void excl_clien(void);
void grava_cliente(Clientes* clientes);
void todos_clientes(void);
void exibindo_clientes(Clientes* clientes);
void listar_cliente(void);

