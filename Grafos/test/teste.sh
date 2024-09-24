#!/bin/bash

# Executa o programa
./grafo > saida.txt

# Verifica a saída
if grep -q "Caminho entre 1 e 5" saida.txt; then
    echo "Teste BFS passou"
else
    echo "Teste BFS falhou"
fi
