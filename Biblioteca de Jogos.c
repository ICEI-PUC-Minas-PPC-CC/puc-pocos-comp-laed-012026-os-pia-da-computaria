#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

struct jogos{

    float tamanho;
    char nome[50] ;
    char genero[50];
    int ativo;

};
 void listar(struct jogos lista_jogos [10], int total_jogos){

 int i;

        printf("\n\nListar os jogos\n\n\n");
        if (total_jogos == 0)
        {
        printf ("Nenhum jogo cadastrado.");
        }
        else { for (i = 0; i < total_jogos; i++)
        {
        if (lista_jogos[i].ativo == 1) {
        printf("\nJogo: %d\n \nNome: %s\n \nGênero: %s\n", i+1, lista_jogos[i].nome, lista_jogos[i].genero);
        }
        }
        }
 }

 void cadastrar(struct jogos lista_jogos [10], int total_jogos){

         printf("\n\nInserir jogo\n\n\n");

         printf("Nome do Jogo:  ");
         scanf("%s", lista_jogos[total_jogos].nome);

         printf("Gênero do Jogo:  ");
         scanf("%s", lista_jogos[total_jogos].genero);
         lista_jogos[total_jogos].ativo = 1;


 }
int main(){

  setlocale(LC_ALL, "Portuguese");


struct jogos lista_jogos [10];
int total_jogos = 0;
int i;

for(i=0; i<10; i++){
    lista_jogos[i].ativo = 0;
    if (i==9)
    {
        printf("Vetor percorrido com sucesso\n\n\n");
    }
}

int opcao;

do{

printf("\n\n============= MENU =============\n\n");
printf("Aperte 1 para inserir o jogo\n");
printf("================================\n");
printf("Aperte 2 para excluir o jogo\n");
printf("================================\n");
printf("Aperte 3 para favoritar o jogo\n");
printf("================================\n");
printf("Aperte 4 para listar os jogos\n");
printf("================================\n");
printf("Aperte 5 para pesquisar o jogo\n\n");
printf("--------------------------------\n");
printf("Aperte 0 para sair\n");

scanf("%d", &opcao);


switch(opcao){
    case 1:
        if (total_jogos < 10)
         {

         cadastrar(lista_jogos, total_jogos);

         total_jogos++;

         printf("\n\nJogo cadastrado!\n\n");

         }
         else { printf("\nNão há mais espaços para adicionar jogos!\n");
         }

         break;
    case 2:
        printf("\n\nExcluir o jogo\n\n\n");
        break;
    case 3:
        printf("\n\nFavoritar o jogo\n\n\n");
        break;
    case 4:
        listar(lista_jogos, total_jogos);
        break;
    case 5:
        printf("\n\nDigite o nome do jogo\n\n\n");
        break;
    case 0:
        printf("\n\nEncerrando...\n\n\n");
        break;
    default:
        printf("\n\nTecla inválida\n\n\n");
}
 }while (opcao!=0);

}
