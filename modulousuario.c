#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "modulousuario.h"

typedef struct usuario Usuario;

int menu_nav_usuario(void)
{
    Usuario* alefe;
  int opcao;
  printf("Modulo Usuário\n\n");
  opcao = tela_usuarios();
  while (opcao != 0) {
    switch (opcao) {
      case 1 :  alefe = tela_cadastrar_u();
                salvaUsuario(alefe);
                free(alefe);
                break;
      case 2 :  alefe = tela_exibir_u();
                exibe_Usuario(alefe);
                free(alefe);
                break;
/*      case 3 :  // Tente implementar esta função ;)
                //;
                break;
      case 4 :  alefe = buscaAluno();
                excluiAluno(alefe);
                free(alefe);
                break;*/
    }
    opcao = tela_usuarios();
  }
  return 0;
}

char tela_usuarios(void){
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
    printf("///            = = = = = = = = =  Menu Usuário = = = = = = = = =            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            1. Cadastrar um usuário                                      ///\n");
    printf("///            2. Pesquisar os dados de um usuário                          ///\n");
    printf("///            3. Atualizar o cadastro de um usuário                        ///\n");
    printf("///            4. Excluir usuário                                           ///\n");
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
void salvaUsuario(Usuario* usu) {
  FILE* fp;
  fp = fopen("usuario.dat", "ab");
  if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }
  fwrite(usu, sizeof(Usuario), 1, fp);
  fclose(fp);

}

 
void exibe_Usuario(Usuario *usu) {

    printf("\n");
    printf("Nome do Usuário: ");
    printf("%s" ,usu->nome);
    printf("\n");
    printf("CPF do Usuário: ");
    printf("%s" ,usu->cpf);
    printf("\n");
    printf("Email do Usuário: ");
    printf("%s" ,usu->email);
    printf("\n");
    printf("Número do Usuário: ");
    printf("%s" ,usu->celular);
    printf("\n");
    printf("Data de nascimento do Usuário");
    printf("%s" ,usu->nasc);
    printf("\n");
}




    Usuario* tela_cadastrar_u(void){
    Usuario* usu;
    usu = (Usuario*) malloc(sizeof(Usuario));
    system("clear||cls");
    printf("\n");                                                                       
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Cadastro de úsuario = = = = = = = =          ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///           CPF (apenas números): ");
    scanf(" %11[^\n]", usu->cpf);
    printf("///           Nome completo: ");
    scanf(" %50[^\n]", usu->nome);
    printf("///           E-mail: ");
    scanf(" %50[^\n]", usu->email);
    printf("///           Data de Nascimento (dd/mm/aaaa):  ");
    scanf(" %10[^\n]", usu->nasc);
    printf("///           Celular  (apenas números): ");
    scanf(" %11[^\n]", usu->celular);
    usu->status = 'm';
    return usu;
}

Usuario* tela_exibir_u(void){
    FILE* fp;
    Usuario* usu;
    char cpf[12];
    system("clear||cls");
    printf("\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Pesquisar Usuário = = = = = = = =            ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///           Informe o CPF (apenas números): ");
    scanf("%d", &cpf);
    usu = (Usuario*) malloc(sizeof(Usuario));
    fp = fopen("arqUsuario.dat", "rb");
    if (fp == NULL) {
    printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
    printf("Não é possível continuar este programa...\n");
    exit(1);
  }
  while(!feof(fp)) {
    fread(usu, sizeof(Usuario), 1, fp);
    if ((usu->cpf == cpf) && (usu->status != 'x')) {
      fclose(fp);
      return usu;
    }
  }
  fclose(fp);
  return NULL;
}

char tela_editar_u(void){
    char esc;
    char cpf[12];

    system("clear||cls");
    printf("\n");
    printf("///                                                                         ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///            = = = = = = = = Editar Usuário = = = = = = = =               ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///           Informe o CPF (apenas números): ");
    scanf("%[0-9]", cpf);
    getchar();
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


char tela_excluir_u(void){
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
    printf("///            = = = = = = = = excluir Usuário = = = = = = = =              ///\n");
    printf("///            = = = = = = = = = = = = = = = = = = = = = = = =              ///\n");
    printf("///                                                                         ///\n");
    printf("///            Informe o ID de usuário:                                     ///\n");
    printf("///                                                                         ///\n");
    printf("///                                                                         ///\n");
    printf("///////////////////////////////////////////////////////////////////////////////\n");
    scanf("%c", &esc);
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
    return esc;
}