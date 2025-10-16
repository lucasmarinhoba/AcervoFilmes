#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colecao.h"

#define MAX_ITENS 1000

Item acervo[MAX_ITENS];
int totalItens = 0;

void carregarAcervo() {
    FILE *fp = fopen("acervo.txt", "r");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    while (fscanf(fp, "id: %d | Titulo: %[^|] | Sinopse: %[^|] | Quantidade: %d | Genero: %[^|] | Elenco: %[^|] | Ano: %d\n", 
                  &acervo[totalItens].id, 
                  acervo[totalItens].titulo,
                  acervo[totalItens].descricao, 
                  &acervo[totalItens].quantidade, 
                  acervo[totalItens].genero,
                  acervo[totalItens].elenco,
                  &acervo[totalItens].ano) == 7) {
        totalItens++;
    }

    fclose(fp);
}


void salvarAcervo() {
    FILE *fp = fopen("acervo.txt", "w");  
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;  
    }

    for (int i = 0; i < totalItens; i++) {
        fprintf(fp, "id: %d | Titulo: %s | Sinopse: %s | Quantidade: %d | Genero: %s | Elenco: %s | Ano: %d\n",
            acervo[i].id,
            acervo[i].titulo,
            acervo[i].descricao,
            acervo[i].quantidade,
            acervo[i].genero,
            acervo[i].elenco,
            acervo[i].ano);
    }

    fclose(fp);
    printf("Acervo salvo com sucesso!\n");
}



void cadastrarItem() {
    if (totalItens >= MAX_ITENS) {
        printf("Limite de itens atingido!\n");
        return;
    }

    acervo[totalItens].id = (totalItens == 0) ? 1 : acervo[totalItens - 1].id + 1;

    printf("Titulo: ");
    fgets(acervo[totalItens].titulo, MAX_DESC, stdin);
    acervo[totalItens].titulo[strcspn(acervo[totalItens].titulo, "\n")] = '\0';

    printf("Sinopse: ");
    fgets(acervo[totalItens].descricao, MAX_DESC, stdin);
    acervo[totalItens].descricao[strcspn(acervo[totalItens].descricao, "\n")] = '\0';

    printf("Elenco: ");
    fgets(acervo[totalItens].elenco, MAX_DESC, stdin);
    acervo[totalItens].elenco[strcspn(acervo[totalItens].elenco, "\n")] = '\0';

    printf("Genero: ");
    fgets(acervo[totalItens].genero, MAX_DESC, stdin);
    acervo[totalItens].genero[strcspn(acervo[totalItens].genero, "\n")] = '\0';

    printf("Ano: ");
    scanf("%d", &acervo[totalItens].ano);
    getchar();
    printf("Quantidade: ");
    scanf("%d", &acervo[totalItens].quantidade);
    getchar();
    totalItens++;
    salvarAcervo();
    printf("\nItem cadastrado com sucesso!\n");
}

void consultarItem() {
    int id;
    printf("ID do item: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < totalItens; i++) {
        if (acervo[i].id == id) {
            printf("id: %d | Titulo: %s | Sinopse: %s | Quantidade: %d | Genero: %s | Elenco: %s | Ano: %d\n",
                acervo[i].id,
                acervo[i].titulo,
                acervo[i].descricao,
                acervo[i].quantidade,
                acervo[i].genero,
                acervo[i].elenco,
                acervo[i].ano);
            return;
        }
    }
    printf("Item não encontrado!\n");
}

void removerItem() {

    int id;
    printf("ID do item a remover: ");
    scanf("%d", &id);
    getchar();
    for (int i = 0; i < totalItens; i++) {
        if (acervo[i].id == id) {
            for (int j = i; j < totalItens - 1; j++) {
                acervo[j] = acervo[j + 1];
            }
            totalItens--;
            salvarAcervo();
            printf("Item removido com sucesso!\n");
            return;
        }
    }

    printf("Item não encontrado!\n");
}

void alterarItem() {
    int id;
    printf("ID do item a alterar: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < totalItens; i++) {
        if (acervo[i].id == id) {
            printf("Novo título (enter para manter): ");
            char novoTitulo[MAX_DESC];
            fgets(novoTitulo, MAX_DESC, stdin);
            novoTitulo[strcspn(novoTitulo, "\n")] = '\0';
            if (strlen(novoTitulo) > 0){
                strcpy(acervo[i].titulo, novoTitulo);
            }
                
            printf("Nova sinopse (enter para manter): ");
            char novaDesc[MAX_DESC];
            fgets(novaDesc, MAX_DESC, stdin);
            novaDesc[strcspn(novaDesc, "\n")] = '\0';
            if (strlen(novaDesc) > 0) {
                strcpy(acervo[i].descricao, novaDesc);
            }

            printf("Novo gênero (enter para manter): ");
            char novoGenero[MAX_DESC];
            fgets(novoGenero, MAX_DESC, stdin);
            novoGenero[strcspn(novoGenero, "\n")] = '\0';
            if (strlen(novoGenero) > 0) {
                strcpy(acervo[i].genero, novoGenero);
            }

            printf("Novo elenco (enter para manter): ");
            char novoElenco[MAX_DESC];
            fgets(novoElenco, MAX_DESC, stdin);
            novoElenco[strcspn(novoElenco, "\n")] = '\0';
            if (strlen(novoElenco) > 0) {
                strcpy(acervo[i].elenco, novoElenco);
            }

            printf("Nova quantidade (atual: %d): ", acervo[i].quantidade);
            scanf("%d", &acervo[i].quantidade);
            getchar();
            printf("Novo ano (atual: %d): ", acervo[i].ano);
            scanf("%d", &acervo[i].ano);
            getchar();
            salvarAcervo();
            printf("\nItem alterado!\n");
            return;
        }
    }

    printf("Item não encontrado!\n");
}

void listarAcervo() {
        system("clear");
        int totalQuantidade = 0;
        for (int i = 0; i < totalItens; i++) {
            totalQuantidade += acervo[i].quantidade;
        }

        printf("\nTotal de IDs cadastrados: %d\n", totalItens);
        printf("Total de unidades no acervo: %d\n", totalQuantidade);
    

    for (int i = 0; i < totalItens; i++) {
        
    printf("id: %d | Titulo: %s | Sinopse: %s | Elenco: %s | Genero: %s | Quantidade: %d | Ano: %d\n",
            acervo[i].id,
            acervo[i].titulo,
            acervo[i].descricao,
            acervo[i].elenco,
            acervo[i].genero,
            acervo[i].quantidade,
            acervo[i].ano);
    }
}
