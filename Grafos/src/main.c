#include <stdio.h>
#include "grafo.h"
#include "bfs.h"
#include "dfs.h"

int main() {
    Grafo* grafo = criarGrafo(MAX_VERTICES);
    carregarDoArquivo(grafo, "entrada.txt");
    imprimirGrafo(grafo);

    int inicio = 0, alvo = 4;  // Exemplo: de 1 para 5
    printf("Busca em Largura (BFS):\n");
    bfs(grafo, inicio, alvo);

    printf("\nBusca em Profundidade (DFS):\n");
    dfs(grafo, inicio);

    free(grafo);
    return 0;
}
