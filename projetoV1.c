#include <stdio.h>
#include <stdlib.h>
#include "modulousuario.h"
#include "moduloemprestimos.h"
#include "modulodevolucoes.h"
#include "modulofuncionarios.h"
#include "modulolivros.h"
#include "modulosobre.h"


// Controle de telas 

char tela_inicial(void);
void tela_sobre(void);
void tela_equipe(void);

// Programa 

int main(void)
{
    char esc;
    do {
        esc = tela_inicial();
        switch(esc){
        case '1':
            menu_nav_usuario();
            break;
        case '2':
            menu_nav_livros();
            break;
        case '3':
            menu_nav_emprestimos();
            break;
        case '4':
            menu_nav_devolucoes();
            break;
        case '5':
            menu_nav_funcionarios();
            break;
        case '6':
            tela_sobre();
            tela_equipe();
            break;
        default:
            printf("Programa finalizado com Sucesso!\n");
            break;
        
        }   
        } while(esc != '0');

    return 0; 
}
   
// Funções 
char tela_inicial(void){
    char op;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///             Universidade Federal do Rio Grande do Norte                 ///\n");
    printf("///                 Centro de Ensino Superior do Seridó                     ///\n");
    printf("///                 Bacharelado Sistemas de Informação                      ///\n");
    printf("///                  Disciplina DCT1106 -- Programação                      ///\n");
    printf("///               Projeto Sistema de Controle de Biblioteca                 ///\n");
    printf("///           Developed by @Pedro-E-Rodrigues and @ArturCandeia -- 2022     ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            > > > >  Sistema de Controle de Biblioteca < < < <           ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Menu Usuários                                             ///\n");
    printf("///            2. Menu Livros                                               ///\n");
    printf("///            3. Menu Empréstimos                                          ///\n");
    printf("///            4. Menu Devoluções                                           ///\n");
    printf("///            5. Menu Funcionários                                         ///\n");
    printf("///            6. Menu Sobre                                                ///\n");
    printf("///            0. Sair                                                      ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha o menu desejado:                                     ///\n");              
    scanf("%c", &op);
    getchar();             
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return op;
}