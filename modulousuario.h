typedef struct usuario Usuario;

struct usuario {
  char esc;
  char cpf[12]; 
  char nome[51];
  char email[51];
  char nasc[11];
  char celular[12];
  char status;
};


char tela_usuarios(void);

Usuario* tela_cadastrar_u(void);

void tela_pesquisar_u(void);

char tela_editar_u(void);

char tela_excluir_u(void);

void menu_nav_usuario(void);