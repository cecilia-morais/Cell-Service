#include "clientes.h"
#include "celular.h"
#include "pecas.h"
#include "relatorios.h"
#include "switchs.h"
#include <stdio.h> 
#include <stdlib.h> 


char sw_cell(){
char op;
    while (op != '0'){

        op = cad_cell();

        switch (op){
            case '1':
                novo_cell();
                break;

            case '2':
                busca_cell();
                break;

            case '3':
                atual_cell();
                break;

            case '4':
                excl_cell();
                break;               

            default:
                printf("Opção inválida");
                break;

        }
    }
    return op;
}

char sw_clien(){
char op;
    while (op != '0'){
    
        op = cad_clien();
        switch (op){
            case '1':
                novo_clien();
                break;

            case '2':
                busca_clien();
                break;

            case '3':
                atual_clien();
                break;

            case '4':
                excl_clien();
                break;

            
            default:
                printf("Opção inválida");
                break;
        }
    }
    return op;
}

char sw_estoque(){
char op;
    while(op != '0'){
        op = estoque();
        switch (op){
            case '1':
                nova_peca();
                break;

            case '2':
                buscar_peca();
                break;

            case '3':
                atual_peca();
                break;

            case '4':
                excl_peca();
                break;

            
            default:
                printf("Opção inválida");
                break;
        }
    }
    return op;
}

        