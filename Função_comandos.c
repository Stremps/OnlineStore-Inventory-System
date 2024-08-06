#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Prototipo_auxiliares.h"
#include "Prototipo_comandos.h"
#include "Prototipo_interface.h"
#include "Prototipo_produtos.h"

// Realiza as opções selecionadas pelo úsuario do menu produtos
// Entrada: Uma das 5 opções apresentadas na tela
// Retorno: quebra de página
// Pré-condição: nenhuma
// Pós-condição: nenhuma
void menu_produtos(FILE* ArvoreBinaria){
    int escolha;

    while(1){
        quebra_Pagina();
        apreseta_Manter();
        scanf("%d%*c", &escolha);
        
        if(escolha == 1){ // Cadastrar produto
            quebra_Pagina();
            printf("1 - Individual\n");
            printf("2 - Em lote\n>");
            scanf("%d%*c", &escolha);

            switch (escolha){
                case 1 :
                    cadastra_Produto_Individual(ArvoreBinaria);
                    break;
                case 2 :
                    cadastra_Produto_Lote(ArvoreBinaria);
                    break;
                default :
                    printf("Comando invalido!\n");
                    break;
            }
            printf("Aperte ENTER para continuar...");
            scanf("%*c"); //Para que o úsuario possa ler a confirmação de cadastro ou mensagem de erro
        }
        else if(escolha == 2){ // Remover Produto
            quebra_Pagina();
            printf("1 - Individual\n");
            printf("2 - Em lote\n>");
            scanf("%d%*c", &escolha);

            switch (escolha){
                case 1 :
                    remove_Produto_Individual(ArvoreBinaria);
                    break;
                case 2 :
                    remove_Produto_Lote(ArvoreBinaria);
                    break;
                case 3 :
                    atualiza_Produto_Lote(ArvoreBinaria);
                    break;
                default:
                    printf("Comando invalido!\n");
                    break;
            }
            
            printf("Aperte ENTER para continuar...");
            scanf("%*c"); //Para que o úsuario possa ler a confirmação de cadastro ou mensagem de erro
        }
        else if(escolha == 3){ // Atualizar produtos
            atualiza_Produto(ArvoreBinaria);
            printf("Aperte ENTER para continuar...");
            scanf("%*c"); //Para que o úsuario possa ler a confirmação de cadastro ou mensagem de erro
        }
        else if(escolha == 4) //Voltar para o menu
            break;
    }
}

// Realiza as opções selecionadas pelo úsuario do menu de imprimir
// Entrada: Uma das 4 opções apresentadas na tela
// Retorno: quebra de página
// Pré-condição: nenhuma
// Pós-condição: nenhuma
void menu_Imprimir(FILE* ArvoreBinaria){
    int escolha;

    while(1){
        quebra_Pagina();
        apresenta_Imprimir();
        scanf("%d%*c", &escolha);

        if(escolha == 1){ //Imprimir informações de um produto
            imprimir_Lista_Produtos(ArvoreBinaria);
            imprimir_produto_unico(ArvoreBinaria);
            printf("Aperte ENTER para continuar.");
            scanf("%*c");
        }
        else if(escolha == 2){ //Imprimir lista de produtos (in-ordem);
            imprimir_Lista_Produtos(ArvoreBinaria);
            printf("Aperte ENTER para continuar.");
            scanf("%*c");
        }
	    else if(escolha == 3){ //Imprimir árvore binária
            Cabecalho* cab = le_cabecalho(ArvoreBinaria);

            if(cab->cabeca == -1) printf("Arvore vazia...\n");
            else{
                Arvore_Bin* niveis = NULL;
                niveis = criar_lista_niveis_arvore(ArvoreBinaria, 0, niveis, 0);
                printf ("\n");
                imprimir_arvorebin(niveis, cab->cabeca);
                niveis = remover_arvorebin(niveis);
            }
            printf("Aperte ENTER para continuar.");
            scanf("%*c");
        }
        else if(escolha == 4){ //Imprimir lista de nós livres
            imprimir_Lista_Livre(ArvoreBinaria);
            printf("Aperte ENTER para continuar.");
            scanf("%*c");
        }
        else if(escolha == 5) //Voltar para o menu
            break;
    }
}

// Realiza a operação de leitura em Lote, do arquivo desejado pelo usuário
// Entrada: Arquivo binário e nome do arquivo
// Retorno: nenhum
// Pré-condição: nenhuma
// Pós-condição: nenhuma
void menu_Leitura_Lote(FILE* ArvoreBinaria){
    quebra_Pagina();
    char nomeArq[50];
    FILE* finput;

    printf("Escreva o diretorio do arquivo:\n>");
    scanf("%[^\n]%*c", nomeArq);

    finput = fopen(nomeArq, "r");

    if(finput == NULL) printf("Diretorio de arquivo invalido!\n");
    else{
        char comando[5];
        while(fscanf(finput, "%[^;];", comando) != EOF){
            
            if(!strcmp(comando, "I")){ //Operação de inserção
                Le_Produto_Arquivo(ArvoreBinaria, finput);
            }
            else if(!strcmp(comando, "A")){ //Operação de atualização
                Atualiza_Produto_Arquivo(ArvoreBinaria, finput);
            }
            else if(!strcmp(comando, "R")){ //Operação de remoção
                int codigo;
                fscanf(finput, "%d\n", &codigo);
                if(procura_codigo(ArvoreBinaria, codigo) == -1) printf("Não é possível remover: codigo [%d] não exite.\n", codigo); //Se não há o codigo, não faz nada
                else{
                    printf("Removido o produto com codigo [%d].\n", codigo);
                    remove_Produto(ArvoreBinaria, codigo, 0); //Se há remove normalmente
                }
            }
    
            }
        printf("Leitura realizada com sucesso!\n");
    }
    printf("Aperte ENTER para continuar.");
    scanf("%*c");
}