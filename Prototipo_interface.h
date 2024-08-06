// Realiza a leitura do sistema operacional do compilador
// Entrada: ponteiro sobre inicialização do programa
// Retorno: nenhum
// Pré-condição: nenhuma
// Pós-condição: sistema operacional salvo
void inicializa_Programa(char* ArquivoBinario);

// Configura a inicialização do arquivo binário
// Entrada: resposta da inicilização e ponteiro do arquivo aberto
// Retorno: nenhum
// Pré-condição: Repostar o questionário do inicializa programa
// Pós-condição: nenhuma
void inicializa_ArquivoBinario(char ArquivoBinario, FILE** ArvoreProdutos);

// Realiza a quebra de pagina dependendo do sistema operacional do compilador
// Entrada: nenhum
// Retorno: quebra de página
// Pré-condição: nenhuma
// Pós-condição: nenhuma
void quebra_Pagina();

// Apresenta na tela as opções principais do menu do programa
// Entrada: nenhum
// Retorno: nenhum
// Pré-condição: nenhuma
// Pós-condição: nenhuma
void apreseta_Menu();

// Apresenta as opções de manter produtos
// Entrada: nenhum
// Retorno: nenhum
// Pré-condição: nenhuma
// Pós-condição: nenhuma
void apreseta_Manter();

// Apresenta as opções de imprimir do programa
// Entrada: nenhum
// Retorno: nenhum
// Pré-condição: nenhuma
// Pós-condição: nenhuma
void apresenta_Imprimir();