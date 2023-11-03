typedef struct clientes
{
    int cpf[12];
    char nome[70];
    char email[100];
    int telefone[15];
}Clientes;


char cad_clien(void);
Clientes* novo_clien(void);
int busca_clien(void);
char atual_clien(void);
char excl_clien(void);


