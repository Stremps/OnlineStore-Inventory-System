typedef struct cabecalho{
    int cabeca; // Posição do nó pai
    int topo; // Quantidade de elementos na árvore
    int livre; // Cabeça da lista de elementos removidos
} Cabecalho;

typedef struct produtos{
    int codigo;
    char nome[50];
    char marca[30];
    char categoria[50];
    int estoque;
    double valor;
} Produtos; //Struct que guarda as informações do produto

typedef struct no{
    int codigo; //Chave que facilita a inserção
    Produtos produto; //Informações do produto
    int noEsquerdo; //No que guarda elementos com o código menor
    int noDireito; //No que guarda elemtnos com o código maior
} No_Arvore;

typedef struct arvorebin{ //Struct auxiliar para imprimir níveis
    int codigo; //Chave de busca
    int nivel; //Nível auxiliar
    struct arvorebin* prox; //Ponteiro para próximo elemento
} Arvore_Bin; //Lista encadeada que vai conter todos os elementos da arvore binária


// Realiza a modificação do cabecalho
// Entrada: Arquivo binário e cabeçalho auxiliar
// Retorno: nenhum
// Pré-condição: nenhuma
// Pós-condição: arquivo binário modificado
void escreve_cabecalho(FILE* arq, Cabecalho* Cab);

// Realiza a incialização do cabeçalho do arquivo
// Entrada: Arquivo binário
// Retorno: nenhum
// Pré-condição: nenhuma
// Pós-condição: arquivo binário incializado
void cria_lista_vazia(FILE* arq);

// Realiza uma cópia das informações que estão no cabeçalho
// Entrada: Arquivo binário
// Retorno: Cabeçalho cópia alocado
// Pré-condição: arquivo binário tem que estar incializado
// Pós-condição: arquivo binário incializado
Cabecalho* le_cabecalho(FILE * arq);

// Realiza a leitura do arquivo binário para copiar um nó da árvore
// Entrada: Arquivo binário e posição do elemento
// Retorno: Nó alocado da árvore
// Pré-condição: nenhuma
// Pós-condição: nenhuma
No_Arvore* le_Arvore(FILE* arquivo, int posi);

// Realiza a inserção e modificação do arquivo binário
// Entrada: arquivo binário, nó que será inserido e indice do arquivo que ocorrerá a inserção
// Retorno: nenhum
// Pré-condição: Arquivo binário tem que estar inicializado
// Pós-condição: Arquivo binário modificado
void escreve_Arvore(FILE* arq, No_Arvore* aux, int posi);

// Configura e inicializa um nó para inserir na árvore
// Entrada: struct do produto preenchida
// Retorno: Nó alocado da árvore
// Pré-condição: struct do produto tem que apresentar o código
// Pós-condição: nenhuma
No_Arvore* inicializa_No_arvore(Produtos* produto);

// Realiza uma busca de uma posição livre da árvore, ou não, e retorna o nó pai deste
// Entrada: arquivo binário e chave de busca
// Retorno: Nó alocado da árvore
// Pré-condição: nenhuma
// Pós-condição: nenhuma
int procura_Posi_Anterior(FILE* arquivo, int key);

// Encadeia com o nó pai o novo nó inserido
// Entrada: arquivo binário, chave do código e posição do arquivo
// Retorno: nenhum
// Pré-condição: Arquivo binário tem que estar inicializado
// Pós-condição: Arquivo binário modificado
void encadeia_No(FILE* arquivo, int codigo, int posi);

// Encadeia com o nó pai o novo nó inserido
// Entrada: arquivo binário, chave do código e posição do arquivo
// Retorno: nenhum
// Pré-condição: Arquivo binário tem que estar inicializado
// Pós-condição: Arquivo binário modificado
void inserir_Produto_Arquivo(Produtos* produto, FILE* arquivo);

// Procura a posição ocupada pelo elemento com a chave desejada
// Entrada: arquivo binário e chave do código
// Retorno: posição se encontrado e -1 se não estiver na lista
// Pré-condição: Arquivo binário tem que estar inicializado
// Pós-condição: nenhuma
int procura_codigo(FILE* arquivo, int key);

// Realiza leitura das informações do produto e insere ele na árvore
// Entrada: arquivo binário e inputs do teclado
// Retorno: nenhum
// Pré-condição: Arquivo binário tem que estar inicializado
// Pós-condição: Arquivo binário modificado
void cadastra_Produto_Individual(FILE* ArvoreBinaria);

// Realiza leitura de um arquivo que contem as informações do produtos e insere ele na árvore
// Entrada: arquivo binário e arquivo de texto
// Retorno: nenhum
// Pré-condição: Arquivo binário tem que estar inicializado e arquivo de texto no formato adequado
// Pós-condição: Arquivo binário modificado
void cadastra_Produto_Lote(FILE* ArvoreBinaria);

// Realiza a leitura de um arquivo e insere em uma struct
// Entrada: arquivo binário e inputs do teclado
// Retorno: se leitura for um sucesso 1, se não tiver leitura 0
// Pré-condição: Arquivo binário tem que estar inicializado
// Pós-condição: Arquivo binário modificado
int Le_Produto_Arquivo(FILE* ArvoreBinaria, FILE* finput);

// Realiza a impressão dos códigos em ordem crescente de forma recursiva
// Entrada: arquivo binário e posição que sera imprimida
// Retorno: nenhum
// Pré-condição: Arquivo binário tem que estar inicializado
// Pós-condição: nenhuma
void Imprimir_In_Ordem(FILE* ArvoreBinaria, int pose);

// Opção selecionado do menu que verifica a arvore está inicializada, se estiver imprime
// Entrada: arquivo binário
// Retorno: nenhum
// Pré-condição: Arquivo binário tem que estar inicializado
// Pós-condição: nenhuma
void imprimir_Lista_Produtos(FILE* ArvoreBinaria);

// Opção slecianada do menu que verifica a lista de nós livres contém algo, se estiver imprime
// Entrada: arquivo binário
// Retorno: nenhum
// Pré-condição: Arquivo binário tem que estar inicializado
// Pós-condição: nenhuma
void imprimir_Lista_Livre(FILE* ArvoreBinaria);

// Opção slecianada do menu que verifica a lista de nós livres contém algo, se estiver imprime
// Entrada: arquivo binário
// Retorno: nenhum
// Pré-condição: Arquivo binário tem que estar inicializado
// Pós-condição: nenhuma
void imprimir_No_Livre(FILE* ArvoreBinaria, int posi);

// Procura o elemnto com mair codigo na árvore, ou sub-árvore
// Entrada: arquivo binário e posição inicial da árvore
// Retorno: posição do maior elemento, ou -1 se não for nada
// Pré-condição: Arquivo binário tem que estar inicializado
// Pós-condição: nenhuma
int posi_codigo_Maximo(FILE* ArvoreBinaria, int posi);

// Procura o elemnto com menor codigo na árvore, ou sub-árvore
// Entrada: arquivo binário e posição inicial da árvore
// Retorno: posição do menor elemento, ou -1 se não for nada
// Pré-condição: Arquivo binário tem que estar inicializado
// Pós-condição: nenhuma
int posi_codigo_Minimo(FILE* ArvoreBinaria, int posi);

// Função recursiva de remoção do produto
// Entrada: arquivo binário, chave de procura e posição inicial da árvore/sub-árvore
// Retorno: retorna a posição do nó removido ou subsequente
// Pré-condição: Arquivo binário tem que estar inicializado
// Pós-condição: Arquivo binário modificado
int remove_Produto(FILE* ArvoreBinaria, int key, int posi);

// Função que realiza a leitura do arquivo e inicializa a remoção de determinado produto se presente no arquivo
// Entrada: arquivo binário
// Retorno: nenhum
// Pré-condição: Arquivo binário tem que estar inicializado
// Pós-condição: Arquivo binário modificado
void remove_Produto_Lote(FILE* ArquivoBinario);

// Função que realiza a leitura do teclado e inicializa a remoção de determinado produto, se presente no arquivo
// Entrada: arquivo binário
// Retorno: nenhum
// Pré-condição: Arquivo binário tem que estar inicializado
// Pós-condição: Arquivo binário modificado
void remove_Produto_Individual(FILE* ArquivoBinario);

// Função que troca informações de nós, mantendo o código do segundo
// Entrada: arquivo binário, posição do nó 1 e 2
// Retorno: nenhum
// Pré-condição: Arquivo binário tem que estar inicializado e posição existentes
// Pós-condição: Arquivo binário modificado
void troca_No(FILE* ArvoreBinaria, int posi1, int posi2);

// Função que apresenta as opções e tipos de atualizações de valores
// Entrada: arquivo binário com a árvore
// Retorno: nenhum
// Pré-condição: nenhuma
// Pós-condição: nenhuma
void atualiza_Produto(FILE* ArvoreBinaria);

// Atualiza individualmente o valor do produto desejado a partir de seu código
// Entrada: arquivo binário com a árvore e input do teclado
// Retorno: nenhum
// Pré-condição: Arquivo binário tem que estar inicializado e posição existentes
// Pós-condição: Arquivo binário modificado
void atualiza_Produto_valor(FILE* ArvoreBinaria);

// Atualiza individualmente o estoque do produto desejado a partir de seu código
// Entrada: arquivo binário com a árvore e input do teclado
// Retorno: nenhum
// Pré-condição: Arquivo binário tem que estar inicializado e posição existentes
// Pós-condição: Arquivo binário modificado
void atualiza_Produto_estoque(FILE* ArvoreBinaria);

// Atualiza individualmente o estoque do produto desejado a partir de seu código lido do arquivo
// Entrada: arquivo binário com a árvore, codigo e estoque
// Retorno: nenhum
// Pré-condição: Arquivo binário tem que estar inicializado e posição existentes
// Pós-condição: Arquivo binário modificado
void atualiza_Produto_estoque_LOTE(FILE* ArvoreBinaria, int codigo, int estoque);

// Atualiza individualmente o valor do produto desejado a partir de seu código lido do arquivo
// Entrada: arquivo binário com a árvore, codigo e valor
// Retorno: nenhum
// Pré-condição: Arquivo binário tem que estar inicializado e posição existentes
// Pós-condição: Arquivo binário modificado
void atualiza_Produto_valor_LOTE(FILE* ArvoreBinaria, int codigo, double valor);

// Realiza a leitura do nome do arquivo e altera as informações desejadas
// Entrada: arquivo binário com a árvore e nome do arquivo que será lido
// Retorno: nenhum
// Pré-condição: Arquivo binário tem que estar inicializado e posição existentes
// Pós-condição: Arquivo binário modificado
void atualiza_Produto_Lote(FILE* ArvoreBinaria);

// Realiza a leitura do arquivo e altera as informações desejadas
// Entrada: arquivo binário com a árvore e arquivo de leitura
// Retorno: 1 para dizer que não acabou o 0 para End Of File
// Pré-condição: Arquivo binário tem que estar inicializado e posição existentes
// Pós-condição: Arquivo binário modificado
int Atualiza_Produto_Arquivo(FILE* ArvoreBinaria, FILE* finput);

// Realiza a impressão das informações do produto a partir do código
// Entrada: arquivo binário com a árvore e o código do produto
// Retorno: nenhum
// Pré-condição: Arquivo binário tem que estar inicializado e posição existentes
// Pós-condição: Arquivo binário modificado
void imprimir_produto_unico(FILE* arquivo);

// Verifica se a árvore é vazia
// Entrada: Lista que da Arvore_Binaria auxíliar
// Retorno: 1 para vazio, ou 0 para com conteúdo
// Pré-condição: nenhuma
// Pós-condição: nenhuma
int vazia_arvorebin(Arvore_Bin* arvore);

// Encadeia na lista auxílizar de maneira ordenada por nível
// Entrada: Lista que da Arvore_Binaria auxíliar
// Retorno: Cabeça da lista alterada
// Pré-condição: nenhuma
// Pós-condição: Lista modificada
Arvore_Bin* inserir_arvore_ordenada(Arvore_Bin* arvore, int codigo, int nivel);

// Imprime a árvore em níveis
// Entrada: Lista que da Arvore_Binaria auxíliar e nível
// Retorno: nenhum
// Pré-condição: nenhuma
// Pós-condição: nenhuma
void imprimir_arvorebin(Arvore_Bin* arvore, int nivel);

// Função que cria a árvore
// Entrada: Arquivo binário, posição, arvore binária auxíliar e nível
// Retorno: Arvore auxíliar modificada
// Pré-condição: nenhuma
// Pós-condição: Lista modificada
Arvore_Bin* criar_lista_niveis_arvore(FILE* ArvoreBinaria, int pose, Arvore_Bin* arvore, int nivel);

// Libera todos os elementos criados temporariamente para impressão de produtos
// Entrada: Lista que da Arvore_Binaria auxíliar
// Retorno: Cabeça da lista alterada
// Pré-condição: nenhuma
// Pós-condição: Lista modificada
Arvore_Bin* remover_arvorebin(Arvore_Bin* arvore);