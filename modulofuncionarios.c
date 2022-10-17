#include <stdio.h>
#include <stdlib.h>
#include "modulofuncionarios.h"

void menu_nav_funcionarios(void){
    char esc = ' ';
    do {
        esc = tela_funcionarios();
        switch (esc){
        case '1':
            tela_cadastrar_f();
            break;
        case '2':
            tela_pesquisar_f();
            break;
        case '3':
            tela_editar_f();
            break;
        case '4':
            tela_excluir_f();
        default:
            printf("Opcao Invalida \n");
            break;
    }

    } while (esc != '0');
}

char tela_funcionarios(void){
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
    printf("///            = = = = = = = = =  Menu Funcionarios= = = = = = = = =        ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar um funcionario                                  ///\n");
    printf("///            2. Pesquisar os dados de um funcionario                      ///\n");
    printf("///            3. Atualizar o cadastro de um funcionario                    ///\n");
    printf("///            4. Excluir funcionario                                       ///\n");
    printf("///            0. Voltar ao menu principal                                  ///\n");
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

char tela_cadastrar_f(void){
    char esc;
    char nome[51];
    char cpf[12];
    char telefone[12];
    char email[51];
    
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
    printf("///            = = = = = = = = Cadastro de Funcionario = = = = = = = =      ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe seu nome:                                            ///\n");
    scanf("%[A-ZÁÉÍÓÚÂÊÔÇÀÃÕ a-záéíóúâêôçàãõ]", nome);
    getchar();
    printf("///            Informe seu CPF:                                             ///\n");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///            Informe seu telefone:                                        ///\n"); 
    scanf("%[0-9]", telefone);
    getchar();
    printf("///            Informe seu Email:                                           ///\n");
    scanf("%[A-Za-z0-9@._]", email);
    getchar();
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    scanf("%c", &esc);
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return esc;
}

char tela_pesquisar_f(void){
    char esc;
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
    printf("///            = = = = = = = = Pesquisar Funcionario = = = = = = = =        ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o ID de funcionario:                                 ///\n");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    scanf("%c", &esc);
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return esc;
}

char tela_editar_f(void){
    char esc;
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
    printf("///            = = = = = = = = Editar Funcionario = = = = = = = =           ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o ID de Funcionario:                                 ///\n");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    scanf("%c", &esc);
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return esc;
}

char tela_excluir_f(void){
    char esc;
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
    printf("///            = = = = = = = = excluir Funcionario = = = = = = = =          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o ID de funcionario:                                 ///\n");
    scanf("%[0-9]", cpf);
    getchar();
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    scanf("%c", &esc);
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return esc;
}
