#include <stdio.h>
#include "dfs.h"

void dfs(Grafo* grafo, int inicio) {
    int visitado[MAX_VERTICES] = {0};
    int pilha[MAX_VERTICES];
    int topo = -1;

    pilha[++topo] = inicio;

    while (topo >= 0) {
        int atual = pilha[topo--];

        if (!visitado[atual]) {
            printf("Visitando vértice %d\n", atual + 1);
            visitado[atual] = 1;

            for (int i = 0; i < grafo->tamanhosListaAdj[atual]; i++) {
                int vizinho = grafo->listaAdj[atual][i];
                if (!visitado[vizinho]) {
                    pilha[++topo] = vizinho;
                }
            }
        }
    }
}
