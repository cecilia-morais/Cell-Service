#ifndef ATENDIMENTOS_H
#define ATENDIMENTOS_H

typedef struct atendimentos{
    int id_atendimento;
    char cpf[12];
    char descricao[100];
    char data_saida[11];
    int status;
}Atendimentos;

#endif

char area_atendimento(void);
void novo_atendimento(void);
void busca_atendimento(void);
char atual_atendimento(void);
void grava_atendimentos(Atendimentos *atendimentos);
void listar_atendimentos(void);
void todos_atendimentos(void);
void exibindo_atendimentos(Atendimentos *atendimentos);
int criar_id_a(void);