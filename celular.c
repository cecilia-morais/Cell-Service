void cad_cell(){
    system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                          CADASTRO DE CELULAR                        \n");
    printf("*********************************************************************\n");
    printf("1 - Cadastrar um novo celular\n");
    printf("2 - Buscar um celular \n");
    printf("3 - Atualizar um celular\n");
    printf("4 - Deletar um celular\n");
    printf("5 - Sair \n");
    printf("*********************************************************************\n");
    printf("\n");
    printf("Digite o número desejado: \n");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();


}

void novo_cell(){
system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                       CADASTRAR UM NOVO CELULAR                     \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    scanf("%c", &op);
    getchar();
    printf("Digite o modelo do aparelho: \n");
    scanf("%c", &op);
    getchar();
    printf("Digite a marca do aparelho:\n ");
    scanf("%c", &op);
    getchar();
    printf("Digite o problema do aparelho: \n");
    scanf("%c", &op);
    getchar();
    printf("Digite a data de entrada do aparelho:\n ");
    scanf("%c", &op);
    getchar();
    printf("Digite a previsão de entrega do aparelho\n");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}

void busca_cell(){
    system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                 BUSCAR CELULAR CADASTRADO POR CLIENTE               \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    scanf("%c", &op);
    getchar();
    printf("Digite o modelo do aparelho: \n");
    scanf("%c", &op);
    getchar();
    printf("Digite a marca do aparelho:\n ");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();


}

void atual_cell(){
    system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                         ATUALIZAR UM CELULAR                        \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    scanf("%c", &op);
    getchar();
    printf("Digite o modelo do aparelho: \n");
    scanf("%c", &op);
    getchar();
    printf("Digite a marca do aparelho:\n ");
    scanf("%c", &op);
    printf("Tecle ENTER para continuar \n");
    getchar();
}

void excl_cell(){
    system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                         DELETAR UM CELULAR                          \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}