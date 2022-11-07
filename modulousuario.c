#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "modulousuario.h"

typedef struct usuario Usuario;

void menu_nav_usuario(void)
{
    char esc = ' ';
    do {
        esc = tela_usuarios();
        switch (esc){
        case '1':
            tela_cadastrar_u();
            break;
        case '2':
            tela_pesquisar_u();
            break;
        case '3':
            tela_editar_u();
            break;
        case '4':
            tela_excluir_u();
        default:
            printf("Opcao Invalida \n");
            break;
    }

    } while (esc != '0');
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

void salArq_Usuario(Usuario* usu){
    FILE *fp;
fp = fopen("arqUsuario.dat","ab");

if (fp == NULL){

      fp = fopen("arqUsuario.dat","wb");
      printf("Arquivo inexistente!\n");
      printf("Criando novo arquivo!");

      if (fp == NULL) {
        printf("Erro com arquivo!");

      }

      else {
        fwrite(usu, sizeof(Usuario), 1, fp);

      }

    }

    else {
        fwrite(usu, sizeof(Usuario), 1, fp);

    }

    fclose(fp);

}

 void lerArq_Usuario(void) {
    FILE *fp;
    Usuario *usu;
    usu = (Usuario*) malloc(sizeof(Usuario));

    fp = fopen("arqUsuario.dat","rb");

    if (fp == NULL) {

        fp = fopen("arqUsuario.dat","wb");
        printf("Arquivo inexistente!\n");
        printf("Criando novo arquivo!");

        if (fp == NULL) {
            printf("Erro com arquivo!");

        }

    }

    else {

        while (fread(usu, sizeof(Usuario), 1, fp)) {

            if (usu->status != 0) {

                fread(usu, sizeof(Usuario), 1, fp);
                
                exibeUsuario(usu);


            }
        }
    }

    free(usu);
    fclose(fp);

}

Usuario* achar_Usuario(char *cpf) {
    FILE* fp;
    Usuario* usu;

    usu = (Usuario*) malloc(sizeof(Usuario));
    fp = fopen("arqUsuario.dat", "rb");

    if (fp == NULL) {
        printf("Ocorreu um erro na abertura do arquivo!\n");

    }


    else {

        while(!feof(fp)) {
            fread(usu, sizeof(Usuario), 1, fp);

            if (strcmp(usu->cpf, cpf) == 0) {

                if (usu->status != 0) {
                    fclose(fp);
                    return usu;
                }

                else {
                    fclose(fp);
                    return NULL;
                }

            } 

        }

    }

    fclose(fp);
    return NULL;
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

void tela_pesquisar_u(void){
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


void tela_excluir_u(Usuario* usuLido) {
    FILE* fp;
    Usuario* usu;
    char cpf[12];
    int achou = 0;
    if (usuLido == NULL) {
    printf(" O Usuário informado não existe!\n");
    }
    else {
    usu = (Usuario*) malloc(sizeof(Usuario));
    fp = fopen("arqUsuario.dat", "r+b");
    if (fp == NULL) {
      printf("Ops! Ocorreu um erro na abertura do arquivo!\n");
      printf("Não é possível continuar este programa...\n");
      exit(1);
    }
    while(!feof(fp)) {
      fread(usu, sizeof(Usuario), 1, fp);
      if ((usu->cpf == usuLido->cpf) && (usu->status != 'x')) {
        achou = 1;
        usu->status = 'x';
        fseek(fp, -1*sizeof(Usuario), SEEK_CUR);
        fwrite(usu, sizeof(Usuario), 1, fp);
        printf("\nUsuário excluído com sucesso!!!\n");
      }
    }
    if (!achou) {
      printf("\nUsuário não encontrado!\n");
    }
    fclose(fp);
    free(usu);
  }
}