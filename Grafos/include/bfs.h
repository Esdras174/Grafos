#ifndef BFS_H
#define BFS_H

#include "grafo.h"

int bfs(Grafo* grafo, int inicio, int alvo);
void imprimirCaminho(int* pai, int inicio, int alvo);

#endif
