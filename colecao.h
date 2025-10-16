#ifndef COLECAO_H
#define COLECAO_H

#define MAX_DESC 1000

struct Item{
    int id, quantidade, ano;
    char titulo[MAX_DESC], descricao[MAX_DESC], genero[MAX_DESC], elenco[MAX_DESC];
};
typedef struct Item Item;

void carregarAcervo();
void salvarAcervo();
void cadastrarItem();
void consultarItem();
void removerItem();
void alterarItem();
void listarAcervo();

#endif
