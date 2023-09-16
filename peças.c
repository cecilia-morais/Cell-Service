void estoque(){
    system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                          ESTOQUE DE PEÇAS                           \n");
    printf("*********************************************************************\n");
    printf("1 - Cadastrar uma nova peça\n");
    printf("2 - Buscar uma peça \n");
    printf("3 - Atualizar uma peça \n");
    printf("4 - Deletar uma peça \n");
    printf("5 - Sair \n");
    printf("*********************************************************************\n");
    printf("\n");
    printf("Digite o número desejado: \n");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}

void nova_peca(){
system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                        CADASTRAR UMA NOVA PEÇA                      \n");
    printf("*********************************************************************\n");
    printf("Digite o nome da peça a ser cadastrada:\n ");
    scanf("%c", &op);
    getchar();
    printf("Digite a marca do aparelho que recebe a peça(EM CASO DE PEÇA UNIVERSAL, COLOCAR 'TODAS'): \n");
    scanf("%c", &op);
    getchar();
    printf("Digite o número de série da peça:\n ");
    scanf("%c", &op);
    getchar();
    printf("Digite o estoque de peças:\n ");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}

void buscar_peca(){
    system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                           BUSCAR POR PEÇA                           \n");
    printf("*********************************************************************\n");
    printf("Digite o nome da peça: \n ");
    scanf("%s", &op);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();

}
void atual_peca(){
 system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                         ATUALIZAR UMA PEÇA                          \n");
    printf("*********************************************************************\n");
    printf("Digite o nome da peça:\n ");
    scanf("%s", &op);
    getchar();
    printf("Digite a quantidade de peças a serem adicionadas ao estoque: \n");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}

void excl_peca(){
    system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                         DELETAR UMA PEÇA                            \n");
    printf("*********************************************************************\n");
    printf("Digite o nome da peça:\n ");
    scanf("%c", &op);
    getchar();
    printf("Tem certeza que quer continuar a operação? ");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}