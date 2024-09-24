#include <stdio.h>
#include <stdlib.h>
#include "bfs.h"

int bfs(Grafo* grafo, int inicio, int alvo) {
    int visitado[MAX_VERTICES] = {0};
    int pai[MAX_VERTICES];
    int fila[MAX_VERTICES];
    int inicioFila = 0, fimFila = 0;

    for (int i = 0; i < grafo->numVertices; i++) {
        pai[i] = -1;
    }

    visitado[inicio] = 1;
    fila[fimFila++] = inicio;

    while (inicioFila < fimFila) {
        int atual = fila[inicioFila++];

        if (atual == alvo) {
            imprimirCaminho(pai, inicio, alvo);
            return 1;
        }

        for (int i = 0; i < grafo->tamanhosListaAdj[atual]; i++) {
            int vizinho = grafo->listaAdj[atual][i];
            if (!visitado[vizinho]) {
                visitado[vizinho] = 1;
                pai[vizinho] = atual;
                fila[fimFila++] = vizinho;
            }
        }
    }

    printf("Não há caminho entre os vértices.\n");
    return 0;
}

void imprimirCaminho(int* pai, int inicio, int alvo) {
    if (alvo == -1) {
        printf("Caminho não encontrado.\n");
        return;
    }

    if (inicio == alvo) {
        printf("%d ", inicio + 1);
    } else {
        imprimirCaminho(pai, inicio, pai[alvo]);
        printf("%d ", alvo + 1);
    }
}
