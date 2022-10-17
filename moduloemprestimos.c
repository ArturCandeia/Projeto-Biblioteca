#include <stdio.h>
#include <stdlib.h>
#include "moduloemprestimos.h"

void menu_nav_emprestimos(void){
    char esc = ' ';
    do {
        esc = tela_emprestimos();
        switch (esc){
        case '1':
            tela_emprestimos_u();
            break;
        case '2':
            tela_emprestimos_p();
            break;              
        default:
            printf("Opcao Invalida \n");
            break;
    }

    } while (esc != '0');
}

char tela_emprestimos(void){
    char esc;
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///             > > > > Sistema de Controle de Biblioteca < < < <           ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///           Developed by @pedro__emanuel__ and @ArturCandeia --2022       ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = =  Menu Emprestimos = = = = = = = = =        ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Emprestimos do úsuario                                    ///\n");
    printf("///            2. Prazos do úsuario                                         ///\n");
    printf("///            0. Voltar ao menu principal                                  ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///            Escolha a opção desejada:");
    scanf("%c", &esc);
    getchar();   
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return esc;
    
}

char tela_emprestimos_u(void){
    char esc;
    char nome[51];
    char cpf[12];
    
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            > > > > Sistema de Controle de Biblioteca < < < <            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///           Developed by @pedro__emanuel__ and @ArturCandeia --2022       ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Emprestimos do Úsuario = = = = = = = =       ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            Informe seu nome:                                            ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
    getchar();
    printf("///            Informe o seu CPF:                                           ///\n");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///                                                                         ///\n");
    scanf("%c", &esc);
    getchar();
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return esc;
}

char tela_emprestimos_p(void){
    char esc;
    char nome[51];
    char cpf[12];
    
    system("clear||cls");
    printf("\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            ===================================================          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            > > > > Sistema de Controle de Biblioteca < < < <            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = = = =          ///\n");
    printf("///            ===================================================          ///\n");
    printf("///           Developed by @pedro__emanuel__ and @ArturCandeia --2022       ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Prazo Emprestimos = = = = = = = =            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe seu nome:                                            ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
    getchar();
    printf("///            Informe seu CPF:                                             ///\n");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///                                                                         ///\n");
    scanf("%c", &esc);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return esc;
}
