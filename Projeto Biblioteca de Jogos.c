//Alunos: Wellington Henrique de Melo Dainesi, Guilherme Bruno Franco Fernandes, Mizael Olivan Gualberto Ribeiro, Allan Giacon Vilella.




#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct jogos{

    char nome[100] ;
    char genero[100];
    int ativo;

};

 // Estatísticas: Mostra todos os jogos ativos, inativos e cadastrados.

void estatisticas (struct jogos lista_jogos [10], int total_jogos){

    int ativos = 0;
    int inativos = 0;
    int j;

    if (total_jogos == 0) {
    printf("\nNão existem jogos cadastrados, ativos ou inativos!");
      return;

    }

    for (j = 0; j < total_jogos; j++){

       if (lista_jogos[j].ativo == 1){
            ativos++;
       } else if (lista_jogos[j].ativo == 0) {
            inativos++;
    }

}

    printf("Total de jogos cadastrados: %d\n", total_jogos);
    printf("Total de jogos ativos: %d\n", ativos);
    printf("Total de jogos inativos: %d\n", inativos);

}

 //Excluir: "Excluir" um jogo específico. Ele é desativado no programa.

void excluir (struct jogos lista_jogos [10], int total_jogos){

int i;

    printf("\nSelecione o código do jogo que deseja excluir: \n");
    scanf ("%d", &i);
    getchar();

if (i >= 1 && i <= total_jogos){

    lista_jogos[i - 1].ativo = 0;
    printf("Jogo excluido!\n");
    } else {

    printf("Jogo não encontrado!\n");

    }
}

 //Listar: Lista todos os jogos cadastrados. Se houverem jogos cadastrados, ele exibe o nome, gênero e o Jogo (Que seria o índice dele no vetor).

 void listar(struct jogos lista_jogos [10], int total_jogos){

 int b;

        printf("\n\nListar os jogos\n\n\n");
        if (total_jogos == 0)

        {
        printf ("Nenhum jogo cadastrado.");
        }

        else {
        for (b = 0; b < total_jogos; b++)
        {

        if (lista_jogos[b].ativo == 1) {
        printf("\nJogo: %d\n \nNome: %s\n \nGênero: %s\n", b+1, lista_jogos[b].nome, lista_jogos[b].genero);

                 }
             }
        }
 }

  //Cadastrar: Cadastra o jogo desejado. Ele pede duas informações, nome e gênero.
 void cadastrar(struct jogos lista_jogos [10], int total_jogos){

     int valido = 0;

     do {

         valido = 1;

         printf("\n\nInserir jogo\n\n\n");
         printf("Nome do Jogo:  ");
         fgets(lista_jogos[total_jogos].nome, 100, stdin);
         lista_jogos[total_jogos].nome[strcspn(lista_jogos[total_jogos].nome, "\n")] = '\0';

         if (strlen(lista_jogos[total_jogos].nome) < 2){
         printf("\n\nO nome não pode ter menos que 2 caracteres.\n\n");
         valido = 0;

         } }while (valido == 0);

         do {

         valido = 1;

         printf("Gênero do Jogo:  ");
         fgets(lista_jogos[total_jogos].genero, 100, stdin);
         lista_jogos[total_jogos].genero[strcspn(lista_jogos[total_jogos].genero,"\n")] = '\0';

         if (strlen(lista_jogos[total_jogos].genero) < 2){
         printf("\\nnO gênero não pode ter menos que 2 caracteres.\n\n");

         valido = 0;
         }

         }  while (valido == 0);


         lista_jogos[total_jogos].ativo = 1;

 }
  // Editar: Edita o jogo que já está cadastrado.

 void editar(struct jogos lista_jogos[10], int total_jogos){

     int codigo;

        printf("\n\n======= EDITAR JOGO =======\n\n");
        if (total_jogos == 0){
        printf("Nenhum jogo foi cadastrado.\n");
        return;
     }
        printf("Digite o código do jogo que deseja editar: ");
        scanf("%d", &codigo);

        codigo = codigo - 1;
        if (codigo < 0 || codigo >= total_jogos){
        printf("\nCódigo inválido.\n");
        return;
}

   if (lista_jogos[codigo].ativo == 0){
        printf("\nEsse jogo foi excluido e nao pode ser editado.\n");
        return;
    }

    getchar();
    printf("\nEditando o jogo: %s\n", lista_jogos[codigo].nome);

    printf("Novo nome: ");
    fgets(lista_jogos[codigo].nome,100,stdin);
    lista_jogos[codigo].nome[strcspn(lista_jogos[codigo].nome,"\n")] = '\0';

    printf("Novo genero: ");
    fgets(lista_jogos[codigo].genero,100,stdin);
    lista_jogos[codigo].genero[strcspn(lista_jogos[codigo].genero,"\n")] = '\0';

    printf("\nJogo foi editado com sucesso.\n");
}

 //Pesquisar: Pesquisa o nome do jogo. Seja por, nome, gênero ou código.
 void pesquisar(struct jogos lista_jogos [10], int total_jogos){

     char texto_pesquisa[100];
     int  cadastrados = 0;
     int a;
     int opcao_pesquisa;
     int codigo_pesquisa;

     printf("\n\n=======PESQUISAR JOGO=======\n\n");
     if (total_jogos == 0){
     printf("Nenhum jogo encontrado.");
     return;
     }

     printf("Escolha o tipo de pesquisa:\n");
     printf("1 - Nome\n");
     printf("2 - Código\n");
     printf("3 - Gênero\n");
     printf("Opção: ");
     scanf("%d", &opcao_pesquisa);

     switch (opcao_pesquisa){

 case 1:

     printf("Digite o nome do jogo corretamente: ");
     getchar();
     fgets(texto_pesquisa,100,stdin);
     texto_pesquisa[strcspn(texto_pesquisa,"\n")] = '\0';

  for (a = 0; a < total_jogos; a++)

  if (lista_jogos[a].ativo == 1 && strcmp(lista_jogos[a].nome, texto_pesquisa) == 0){

     printf("\n\nJogo Encontrado!\n\n");
     printf("Código do Jogo: %d\nNome: %s\nGênero: %s\n", a + 1, lista_jogos[a].nome, lista_jogos[a].genero);

     }

     if (cadastrados == 0)
        printf("\nJogo não encontrado!");

  break;

 case 2:

    printf("Digite o código do jogo: ");
    scanf (" %d", &codigo_pesquisa);

  int codigo = codigo_pesquisa - 1;

  if (codigo >= 0 && codigo < total_jogos && lista_jogos[codigo].ativo == 1) {
                printf("\n\nJogo Encontrado:\n\n");
                printf("Código: %d\nNome: %s\nGênero: %s\n", codigo_pesquisa, lista_jogos[codigo].nome, lista_jogos[codigo].genero);
  } else {
                printf("\nCódigo inválido.\n");
            }
  break;

 case 3:

    printf("Digite o gênero do jogo corretamente: ");
    getchar();
    fgets(texto_pesquisa,100,stdin);
    texto_pesquisa[strcspn(texto_pesquisa,"\n")] = '\0';

    printf("\nJogos do gênero '%s':\n\n", texto_pesquisa);

  for (a = 0; a < total_jogos; a++) {

  if (lista_jogos[a].ativo == 1 && strcmp(lista_jogos[a].genero, texto_pesquisa) == 0) {

    printf("Código: %d \nNome: %s\n", a + 1, lista_jogos[a].nome);
    cadastrados = 1;

    }
    }

  if (cadastrados == 0) {
                printf("\nNenhum jogo encontrado com esse gênero.\n");
    }
  break;

  default:
            printf("\nOpção de pesquisa inválida!\n");
            break;
 }
 }
  int main(){

  setlocale(LC_ALL, "Portuguese");


  struct jogos lista_jogos [10];
  int total_jogos = 0;
  int d;

  for(d=0; d<10; d++){
    lista_jogos[d].ativo = 0;
    if (d==9)
    {
        printf("Vetor percorrido com sucesso\n\n\n");
    }
}

  char opcao;

  do{

printf("\n\n============= MENU =============\n\n");
printf("Aperte 1 para inserir o jogo\n");
printf("================================\n");
printf("Aperte 2 para excluir o jogo\n");
printf("================================\n");
printf("Aperte 3 para listar os jogos\n");
printf("================================\n");
printf("Aperte 4 para pesquisar o jogo\n");
printf("================================\n");
printf("Aperte 5 para editar o jogo\n");
printf("================================\n");
printf ("Aperte 6 para estatísticas\n");
printf("================================\n");
printf("\nAperte 0 para sair\n");

scanf(" %c", &opcao);
getchar();

// Switch opcção: Menu de decisão do usuário. Aqui ele escolhe a opção que ele quer.
switch(opcao){
    case '1':
         if (total_jogos < 10)
         {

         cadastrar(lista_jogos, total_jogos);

         total_jogos++;

         printf("\n\nJogo cadastrado!\n\n");

         }
         else { printf("\nNão há mais espaços para adicionar jogos!\n");
         }

         break;
    case '2':
        excluir (lista_jogos, total_jogos);
         break;
    case '3':
        listar(lista_jogos, total_jogos);
         break;
    case '4':
        pesquisar(lista_jogos, total_jogos);
         break;
    case '5':
        editar(lista_jogos, total_jogos);
         break;
    case '6':
        estatisticas(lista_jogos, total_jogos);
         break;
    case '0':
        printf("\n\nEncerrando...\n\n\n");
         break;
    default:
        printf("\n\nTecla inválida\n\n\n");
         break;
}
 }while (opcao!='0');
}
