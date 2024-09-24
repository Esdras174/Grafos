#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

Grafo* criarGrafo(int vertices) {
    Grafo* grafo = (Grafo*)malloc(sizeof(Grafo));
    grafo->numVertices = vertices;

    
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            grafo->matrizAdj[i][j] = 0;
        }
    }

    
    for (int i = 0; i < vertices; i++) {
        grafo->tamanhosListaAdj[i] = 0;
    }

    return grafo;
}

void adicionarAresta(Grafo* grafo, int origem, int destino) {
    
    grafo->matrizAdj[origem][destino] = 1;
    grafo->matrizAdj[destino][origem] = 1; // Grafo não direcionado

    
    grafo->listaAdj[origem][grafo->tamanhosListaAdj[origem]++] = destino;
    grafo->listaAdj[destino][grafo->tamanhosListaAdj[destino]++] = origem;
}

void carregarDoArquivo(Grafo* grafo, const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "r");
    if (!arquivo) {
        printf("Erro ao abrir arquivo.\n");
        return;
    }

    int numArestas, origem, destino;
    fscanf(arquivo, "%d %d", &grafo->numVertices, &numArestas);

    for (int i = 0; i < numArestas; i++) {
        fscanf(arquivo, "%d %d", &origem, &destino);
        adicionarAresta(grafo, origem - 1, destino - 1);
    }

    fclose(arquivo);
}

void imprimirGrafo(Grafo* grafo) {
    printf("Matriz de Adjacência:\n");
    for (int i = 0; i < grafo->numVertices; i++) {
        for (int j = 0; j < grafo->numVertices; j++) {
            printf("%d ", grafo->matrizAdj[i][j]);
        }
        printf("\n");
    }

    printf("\nLista de Adjacência:\n");
    for (int i = 0; i < grafo->numVertices; i++) {
        printf("%d: ", i + 1);
        for (int j = 0; j < grafo->tamanhosListaAdj[i]; j++) {
            printf("%d ", grafo->listaAdj[i][j] + 1);
        }
        printf("\n");
    }
}
