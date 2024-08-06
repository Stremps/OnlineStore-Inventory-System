#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Prototipo_auxiliares.h"
#include "Prototipo_comandos.h"
#include "Prototipo_interface.h"
#include "Prototipo_produtos.h"

// Realiza a leitura do sistema operacional do compilador
// Entrada: ponteiro sobre inicialização do programa
// Retorno: nenhum
// Pré-condição: nenhuma
// Pós-condição: sistema operacional salvo
void inicializa_Programa(char* ArquivoBinario){
    char confirma;

    while(1){ //Parte muito importante para o usuário não realizar algum erro inversível!
        quebra_Pagina();
        printf("Deseja carregar o arquivo binario? (S\\N):\n"); //Se não quiser carregar, cria novos arquivos
        scanf("%c%*c", ArquivoBinario);
        if(*ArquivoBinario == 'n' || *ArquivoBinario == 'N'){
            printf("Ira perder tudo se ja tem algo salvo. Tem certeza disso?(S\\N):\n");
            scanf("%c%*c", &confirma);
            if(confirma == 'S' || confirma == 's') break;
        }
        else break;
    }
}

// Realiza a quebra de pagina dependendo do sistema operacional do compilador
// Entrada: nenhum
// Retorno: quebra de página
// Pré-condição: nenhuma
// Pós-condição: nenhuma
void quebra_Pagina(){
    #ifdef __linux__ //Para caso seja em um compilador Linux
        system("clear");
    #elif _WIN32 //Para caso seja em um compilador windows 32 bits
        system("cls");
    #elif _WIN64 //Para caso seja em um compilador windows 64 bits
        system("cls");
    #else //Se não nada

    #endif
}

// Configura a inicialização do arquivo binário
// Entrada: resposta da inicilização e ponteiro do arquivo aberto
// Retorno: nenhum
// Pré-condição: Repostar o questionário do inicializa programa
// Pós-condição: nenhuma
void inicializa_ArquivoBinario(char ArquivoBinario, FILE** ArvoreProdutos){
    char operacao[5];

    if(ArquivoBinario == 'N' || ArquivoBinario == 'n') strcpy(operacao, "w+b"); //Se não deseja ler, ou deseja iniciar novo, arquivo binário
    else strcpy(operacao, "r+b"); //Se sim, utiliza a operação de ler


    *ArvoreProdutos = fopen("Produtos.bin", operacao); //Realiza a operação
    
    if(ArquivoBinario == 'N' || ArquivoBinario == 'n') //Caso novo, inicializa novo cabeçalho
        cria_lista_vazia(*ArvoreProdutos);
}

// Apresenta na tela as opções principais do menu do programa
// Entrada: nenhum
// Retorno: nenhum
// Pré-condição: nenhuma
// Pós-condição: nenhuma
void apreseta_Menu(){
    printf(" == MENU PRINCIPAL ==\n\n");
    printf("1 - Manter produtos\n");
    printf("2 - Imprimir informacoes\n");
    printf("3 - Ler em lote\n");
    printf("4 - Fechar programa\n");
    printf("\n\n\n\n>");
}

// Apresenta as opções de manter produtos
// Entrada: nenhum
// Retorno: nenhum
// Pré-condição: nenhuma
// Pós-condição: nenhuma
void apreseta_Manter(){
    printf(" == MENU PRODUTOS ==\n\n");
    printf("1 - Cadastrar produto(s)\n");
    printf("2 - Remover produto(s)\n");
    printf("3 - Atualizar produto(s)\n");
    printf("4 - Voltar para o menu\n");
    printf("\n\n\n\n>");
}

// Apresenta as opções de imprimir do programa
// Entrada: nenhum
// Retorno: nenhum
// Pré-condição: nenhuma
// Pós-condição: nenhuma
void apresenta_Imprimir(){
    printf(" == MENU IMPRIMIR ==\n\n");
    printf("1 - Imprimir informacoes de um produto\n");
    printf("2 - Imprimir lista de produtos (in-ordem)\n");
    printf("3 - Imprimir arvore binaria\n");
    printf("4 - Imprimir lista de nos livres\n");
    printf("5 - Voltar para o menu\n");
    printf("\n\n\n>");
}