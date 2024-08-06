#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Prototipo_auxiliares.h"
#include "Prototipo_comandos.h"
#include "Prototipo_interface.h"
#include "Prototipo_produtos.h"

int main(){
    char AbrirArquivo;
    int escolha;
    FILE *ArvoreProdutos;

    inicializa_Programa(&AbrirArquivo);
    inicializa_ArquivoBinario(AbrirArquivo, &ArvoreProdutos);

    while(1){
        quebra_Pagina();
        apreseta_Menu();
        scanf("%d%*c", &escolha);

        if(escolha ==  1){ //Escolha que guia para o menu de manter produtos
            menu_produtos(ArvoreProdutos);
        }
        if(escolha == 2){ //Escolha que guia para o menu de imprimir produtos
            menu_Imprimir(ArvoreProdutos);
        }
        if(escolha == 3){ //Escolha que guia para a leitura em lote
            menu_Leitura_Lote(ArvoreProdutos);
        }
        if(escolha == 4) //Fecha programa
            break;
        if(escolha == 414){ //Comando para testes
            No_Arvore *aux = le_Arvore(ArvoreProdutos, 4);
            printf("Esquerda = %d\nDireita = %d", aux->noEsquerdo, aux->noDireito);
            free(aux);
            scanf("%*c");
        }
    }

    fclose(ArvoreProdutos);
    return 0;
}