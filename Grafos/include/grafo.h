#ifndef GRAFO_H
#define GRAFO_H

#define MAX_VERTICES 100

typedef struct {
    int numVertices;
    int matrizAdj[MAX_VERTICES][MAX_VERTICES];
    int listaAdj[MAX_VERTICES][MAX_VERTICES];
    int tamanhosListaAdj[MAX_VERTICES];
} Grafo;

Grafo* criarGrafo(int vertices);
void adicionarAresta(Grafo* grafo, int origem, int destino);
void carregarDoArquivo(Grafo* grafo, const char* nomeArquivo);
void imprimirGrafo(Grafo* grafo);

#endif
