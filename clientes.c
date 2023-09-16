void cad_clien(){
    system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                          ÁREA DE CLIENTES                           \n");
    printf("*********************************************************************\n");
    printf("1 - Cadastrar um novo cliente\n");
    printf("2 - Buscar um cliente \n");
    printf("3 - Atualizar um cliente\n");
    printf("4 - Deletar um cliente\n");
    printf("5 - Sair \n");
    printf("*********************************************************************\n");
    printf("\n");
    printf("Digite o número desejado: \n");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}

void novo_clien(){
system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                       CADASTRAR UM NOVO CLIENTE                     \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    scanf("%c", &op);
    getchar();
    printf("Digite o nome completo do cliente: \n");
    scanf("%c", &op);
    getchar();
    printf("Digite a data de nascimento do cliente:\n ");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}

void busca_clien(){
    system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                           BUSCAR POR CLIENTE                        \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}

void atual_clien(){
    system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                         ATUALIZAR UM CLIENTE                        \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    scanf("%c", &op);
    getchar();
    printf("Digite '1' se deseja alterar o nome do cliente ou '2' se deseja alterar a data de nascimento do cliente: \n");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}

void excl_clien(){
    system("clear || cls");
    char op;
    printf("*********************************************************************\n");
    printf("                         DELETAR UM CLIENTE                          \n");
    printf("*********************************************************************\n");
    printf("Digite o CPF do cliente:\n ");
    scanf("%c", &op);
    getchar();
    printf("Tem certeza que quer continuar a operação? ");
    scanf("%c", &op);
    getchar();
    printf("Tecle ENTER para continuar \n");
    getchar();
}