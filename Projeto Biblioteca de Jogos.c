#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct jogos{

    float tamanho;
    char nome[30] ;
    char genero[30];

};
int main(){

  setlocale(LC_ALL, "Portuguese");


int jogos_n[10];
int i;

for(i=0; i<10; i++){
    if (i==9)
    {
        printf("Vetor percorrido com sucesso\n\n\n");
    }
}

int opcao;

do{

printf("================================\n");
printf("Aperte 1 para adicionar o jogo\n");
printf("================================\n");
printf("Aperte 2 para excluir o jogo\n");
printf("================================\n");
printf("Aperte 3 para favoritar o jogo\n");
printf("================================\n");
printf("Aperte 4 para listar os jogos\n");
printf("================================\n");
printf("Aperte 5 para pesquisar o jogo\n");
printf("================================\n");
printf("================================\n");
printf("Aperte 0 para sair\n");

scanf("%d", &opcao);


switch(opcao){
    case 1:
         printf("\n\nInserir jogo\n\n\n");
         break;
    case 2:
        printf("\n\nExcluir o jogo\n\n\n");
        break;
    case 3:
        printf("\n\nFavoritar o jogo\n\n\n");
        break;
    case 4:
        printf("\n\nListar os jogos\n\n\n");
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



