#include <stdio.h>
#include "colecao.h"

int main() {
    int opcao;
    carregarAcervo();

    do {
        printf("\n--- MENU COLEÇÃO DE FILMES---\n");
        printf("1. Cadastrar item\n");
        printf("2. Consultar item\n");
        printf("3. Remover item\n");
        printf("4. Alterar item\n");
        printf("5. Listar acervo\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1: cadastrarItem(); break;
            case 2: consultarItem(); break;
            case 3: removerItem(); break;
            case 4: alterarItem(); break;
            case 5: listarAcervo(); break;
            case 0: salvarAcervo(); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    printf("Programa encerrado.\n");

    return 0;
}
