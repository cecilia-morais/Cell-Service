#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include "validacoes.h"
#include "celular.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////
//AS VAVALIDAÇÕES A SEGUIR FORAM FEITAS COM AJUDA DO CHATGPT                                       //
/////////////////////////////////////////////////////////////////////////////////////////////////////

struct Data {
    int dia;
    int mes;
    int ano;
};

// Função para validar uma data
int validarData(int dia, int mes, int ano) {
    // Verifica o ano bissexto
    int bissexto = (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0));
    
    // Verifica se o mês está dentro do intervalo válido (1 a 12)
    if (mes < 1 || mes > 12) {
        return 0; // Mês inválido
    }
    
    // Verifica se o dia está dentro do intervalo válido
    int dias_mes[] = {0, 31, 28 + bissexto, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (dia < 1 || dia > dias_mes[mes]) {
        return 0; // Dia inválido
    }
    
    return 1; // Data válida
}

// Função para verificar se a data de saída não é anterior à data de entrada
int dataSaidaValida(int dia_entrada, int mes_entrada, int ano_entrada, int dia_saida, int mes_saida, int ano_saida) {
    if (ano_saida < ano_entrada) {
        return 0; // Ano de saída é anterior ao ano de entrada
    }
    if (ano_saida == ano_entrada && mes_saida < mes_entrada) {
        return 0; // Mês de saída é anterior ao mês de entrada no mesmo ano
    }
    if (ano_saida == ano_entrada && mes_saida == mes_entrada && dia_saida < dia_entrada) {
        return 0; // Dia de saída é anterior ao dia de entrada na mesma data
    }
    return 1; // Data de saída é válida
}


bool ler_data_saida(int dia_entrada, int mes_entrada, int ano_entrada, int *dia_saida, int *mes_saida, int *ano_saida) {
    do {
        printf("Informe a data de saída (dd/mm/aaaa): ");
        scanf("%d/%d/%d", dia_saida, mes_saida, ano_saida);

        if (!validarData(*dia_saida, *mes_saida, *ano_saida)) {
            printf("Data de saída inválida.\n");
        } else if (!dataSaidaValida(dia_entrada, mes_entrada, ano_entrada, *dia_saida, *mes_saida, *ano_saida)) {
            printf("Data de saída anterior à data de entrada.\n");
        }
    } while (!validarData(*dia_saida, *mes_saida, *ano_saida) || !dataSaidaValida(dia_entrada, mes_entrada, ano_entrada, *dia_saida, *mes_saida, *ano_saida));
    return true;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//AS VAVALIDAÇÕES A SEGUIR FORAM FEITAS OU RETIRADAS DO PROJETO DE MATHEUS DINIZ FERNANDES. GITHUB: @matheusdnf           //
//Disponível em <https://github.com/Matheusdnf/projeto_horarios_de_aula.git> acesso em 11/10/2023                         //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



void ler_telefone(char *telefone) {
    //função reutilizável para realizar a leitura do telefone
    int t;
    bool v=true,f=false;
    while (v) {
        printf("Digite o telefone do cliente com DDD (apenas números):"); //LINHA DE VALIDAÇÃO ALTERADA POR cecilia-morais PARA ENCAIXAR NO PROGRAMA
        fgets(telefone, 15, stdin);
        t = valida_telefone(telefone);
        if (t == 1) {
            printf("Telefone válido\n");
            v = f;  // Saia do loop quando o telefone for válido
        } else if (t == 0) {
            printf("Telefone inválido\n");
        }
    }
}

int valida_telefone(char *telefone) {
    //uma lista com os ddds existentes no brasil
    char *ddd[] = {
        "11", "12", "13", "14", "15", "16", "17", "18", "19",
        "21", "22", "24", "27", "28", "31", "32", "33", "34",
        "35", "37", "38", "41", "42", "43", "44", "45", "46",
        "47", "48", "49", "51", "53", "54", "55", "61", "62",
        "63", "64", "65", "66", "67", "68", "69", "71", "73",
        "74", "75", "77", "79", "81", "82", "83", "84", "85",
        "86", "87", "88", "89", "91", "92", "93", "94", "95",
        "96", "97", "98", "99"
    };
    int tam = strlen(telefone);
    // Deve ter no mínimo 12 caracteres (incluindo '\n') e o ddd
    if (tam != 12) {
        return 0;
    }

    // Verificar se os primeiros 2 caracteres são um DDD válido
    // rodou 81 vezes por causa da quantidade de ddd
    for (int i = 0; i < 81; i++) {  
        //o strncmp compara os dois primeiros caracter de ambos
        if (strncmp(telefone, ddd[i], 2) == 0) {
            // Encontrou um DDD válido, agora verifique se os outros caracteres são dígitos
            for (int j = 2; j < 11; j++) {
                if (!isdigit(telefone[j])) {
                    return 0; // Contém caracteres não numéricos
                }
            }
            return 1; // Telefone válido
        }
    }
    return 0; // DDD inválido
}

// Função personalizada para verificar se um caractere é uma letra (incluindo acentos)
// Desenvolvida com akuda do chat gpt
bool eh_letra_acentuada(char c) {   //recebe uma letra por vez
    //um char com as palavras que possam vir a ser acentuadas
    char letras_acentuadas[] = "ÁÀÂÃÉÈÊÍÌÎÓÒÔÕÚÙÛÇáàâãéèêíìîóòôõúùûç"; 
    //ela roda um loop que termina até o caracter nulo do fgets
    for (int i = 0; letras_acentuadas[i] != '\0'; i++) {  
        // aí se a letra em questão for igual ao char letras_acentuadas retornará vdd
        //esse loop e esse if verificiarão toda as letras
        if (c == letras_acentuadas[i]) {
            return true;
        }
    }
    //verifica se a letra c é uma letra ou um espaço em branco 
    return isalpha(c) || c == ' ';
}


void ler_nome(char *nome) {
    //função reutilizável para realizar a leitura do nome
    int n;
    bool v=true,f=false;
    while (v) {
        printf("Digite o nome do cliente:"); //LINHA DE VALIDAÇÃO ALTERADA POR cecilia-morais PARA ENCAIXAR NO PROGRAMA
        fgets(nome, 100, stdin);
        n = valida_nome(nome);
        if (n == 1) {
            printf("válido\n");
            v=f;
        } else if (n == 0) {
            printf("inválido\n");
        }
    }
}

int valida_nome(char *nome) {
    // Pega o tamanho da variável nome
    int tam = strlen(nome);
    //só permite nome maiores que 2 letras 
    // é utilizado 3 para contar com o \n do teclado
    if (tam<3){
        return 0;
    }
    // Verificar se o usuário não digitou um espaço em branco,tanto no ínicio como no final
    if ((isspace(nome[0])) || (isspace(nome[tam - 2]))) {
        return 0;
    }
    //esse loop serve para procurar a questão de números
    for (int j = 0; j < tam - 1; j++) {
        if (!eh_letra_acentuada(nome[j])) {
            return 0;
        }
    }
    // Verifica se dois espaços em branco consecutivos
    for (int i = 0; i < tam - 2; i++) {
        if ((isspace(nome[i])) && (isspace(nome[i + 1]))) {
            return 0;
        }
    }
    return 1;
}


void removerCaracteresNaoNumericos(char cpf[]) {
    //feita pelo chat gpt
    int len = strlen(cpf);
    int k = 0;
    for (int i = 0; i < len; i++) {
        if (cpf[i] >= '0' && cpf[i] <= '9') {
            cpf[k] = cpf[i];
            k++;
        }
    }
    cpf[k] = '\0'; // Adicione o terminador nulo ao final
}

int validarCPF(char cpf[]) {
    //validação de cpf retirado do site http://wurthmann.blogspot.com/ e sofreu algumas adpatações por Matheus Diniz
    // Remova os caracteres de pontuação (.) e hífen (-) do CPF
    removerCaracteresNaoNumericos(cpf);

    int i, j, digito1 = 0, digito2 = 0;

    if (strlen(cpf) != 11)
        return 0;
    else if ((strcmp(cpf, "00000000000") == 0) || (strcmp(cpf, "11111111111") == 0) ||
             (strcmp(cpf, "22222222222") == 0) || (strcmp(cpf, "33333333333") == 0) ||
             (strcmp(cpf, "44444444444") == 0) || (strcmp(cpf, "55555555555") == 0) ||
             (strcmp(cpf, "66666666666") == 0) || (strcmp(cpf, "77777777777") == 0) ||
             (strcmp(cpf, "88888888888") == 0) || (strcmp(cpf, "99999999999") == 0))
        return 0;
    else {
        // Digito 1
        for (i = 0, j = 10; i < 9; i++, j--) {
            digito1 += (cpf[i] - '0') * j;
        }
        digito1 %= 11;
        if (digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if ((cpf[9] - '0') != digito1)
            return 0;

        // Digito 2
        for (i = 0, j = 11; i < 10; i++, j--) {
            digito2 += (cpf[i] - '0') * j;
        }
        digito2 %= 11;
        if (digito2 < 2)
            digito2 = 0;
        else
            digito2 = 11 - digito2;
        if ((cpf[10] - '0') != digito2)
            return 0;
    }

    return 1;
}

void ler_cpf(char cpf[]) {
    //função reutilizável para realizar a leitura do cpf
    int c;
    bool v=true,f=false;
    while (v) {
        printf("Digite o CPF do cliente: "); //LINHA DE VALIDAÇÃO ALTERADA POR cecilia-morais PARA ENCAIXAR NO PROGRAMA
        scanf("%s", cpf);
        limpar_buffer();
        c = validarCPF(cpf);
        if (c == 1) {
            printf("válido\n");
            v=f;
        } else if (c == 0) {
            printf("inválido\n");
        }
    }
}

//feito com a ajuda do chat gpt
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {
        // Lê e descarta cada caractere até encontrar uma nova linha ('\n') ou o fim do arquivo (EOF)
    }
}


void ler_email(char email[]) {
    //função reutilizável para realizar a leitura do email
    int e;
    bool v=true,f=false;
    while (v) {
        printf("Digite o Email do cliente:"); //LINHA DE VALIDAÇÃO ALTERADA POR cecilia-morais PARA ENCAIXAR NO PROGRAMA
        scanf("%[-._@A-Za-z0-9]", email);
        limpar_buffer();
        e = validate_email(email);
        if (e == 1) {
            printf("Email válido!\n");
           v=f;
        } else if (e == 0) {
            printf("Email inválido!\n");
        }
    }
}

int validate_email(char email[]) {
    //função pega de marlison silva @MarlisonSilva
    //modifiquei o retorno
    email = str_to_lower(email);
    char aux [255];
    if (strlen(email) >= 7 && !has_space(email)) {
        aux[0] = '\0';
        // prefixo
        int pos = 0;
        do {
            aux[pos] = email[pos];
            pos++;
        } while ((email[pos] != '\0') && (email[pos] != '@'));
        aux[pos] = '\0';

        if (strlen(aux) >= 1 && strlen(aux) <= 64){
            // primeira letra não é alfa-numérica e a última é um ponto
            if(!isalnum(aux[0]) || aux[strlen(aux) - 1] == '.') {
                return 0;
            }
        } else {
            return 0;
        }
        
        // caso não haja mais 2 caracteres após o @
        if (strlen(email) < (pos + 2)) {
            return 0;
        }

        // domínio
        pos = pos + 1;
        int i = 0;
        aux[0] = '\0';

        do {
            aux[i] = email[pos];
            pos++;
            i++;
        } while ((email[pos] != '\0') && (email[pos] != '.'));
        aux[i] = '\0';

        // domínio de tamanho incorreto
        if (strlen(aux) >= 2 && strlen(aux) <= 253){
            // primeira e última letra não é alfa-numérica
            if(!isalnum(aux[0]) || !isalnum(aux[strlen(aux) - 1])) {
                return 0;
            }
        } else {
            return 0;
        }

        // caso não haja mais 2 caracteres após o .
        if (strlen(email) < (pos + 2)) {
            return 0;
        }
        pos = pos + 1;
        i = 0;
        aux[0] = '\0';
        do {
            aux[i] = email[pos];
            pos++;
            i++;
        } while (email[pos] != '\0');
        aux[i] = '\0';
        
        // tamanho do top level domain incorreto
        if (strlen(aux) >= 2 && strlen(aux) <= 253){
            // primeira e última letra não é alfa-numérica
            if(!isalnum(aux[0]) || !isalnum(aux[strlen(aux) - 1])) {
                return 0;
            }
            
        } else {
            return 0;
        }
        
        return 1;

    }
    return 0;
}
//auxiliares
int has_space(char* str) {
    //função pega de marlison silva @MarlisonSilva
    int i = 0;
    do
    {
        if (isspace(str[i]))
        {
            return true;
        }
        i++;
    } while (str[i] != '\0');
    
   return false;
}
//auxiliares
char* str_to_lower(char* str){
    //função pega de marlison silva @MarlisonSilva
    char *aux = str;
    int i = 0;
    do
    {
        aux[i] = tolower(str[i]);
        i++;
    } while (aux[i] != '\0');
    return aux;
}