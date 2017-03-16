#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

/**
* Função recursiva que busca o subconjunto de um determnado elemento "v" do grafo
* Enquanto houver vertices, percorre uma aresta ligada a um novo vertice
*/
int busca(int subset[], int v)
{
	if(subset[v] == -1)
		return v;
	return busca(subset, subset[v]);
}

/**
* Função para unir dois subconjuntos em um único conjunto
* Usa a função busca para identificar os subconjuntos de cada vertice e em seguida os une
*/
void unir(int subset[], int v1, int v2)
{
	int v1_set = busca(subset, v1);
	int v2_set = busca(subset, v2);

	subset[v1_set] = v2_set;
}

/**
* Função que identifica a formações de ciclos no grafo (para encontrar a arvore geradora minima)
*/
int identificaCiclo(int grafo[3][3])
{
	int * subset = (int*)malloc(3 * sizeof(int)); // malloc do c

	memset(subset, -1, sizeof(int) * 3); // inicializa todos os subconjuntos como conjuntos de um único elemento

	for(int i = 0; i < 3; i++)
	{
		for(int j = i; j < 3; j++)
		{
			if(grafo[i][j] == 1)
			{
				int v1 = busca(subset, i);
				int v2 = busca(subset, j);

				if(v1 == v2)
					return 1;
				else
					unir(subset, v1, v2);
			}
		}
	}

	return 0;
}

int main(int argc, char *argv[])
{
	/**
	* Grafo representado como uma matriz de adjacencias
	* Grafo sem pesos
	*/
	int grafo[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};

	grafo[0][1] = 1; // vertice 1 esta ligada a vertice 2
	grafo[1][0] = 1; // vertice 2 esta ligada a vertice 1
	grafo[1][2] = 1;
	grafo[2][1] = 1;
	grafo[0][2] = 1;
	grafo[2][0] = 1;

	if(identificaCiclo(grafo))
		cout << "O grafo tem ciclo!\n";
	else
		cout << "O grafo NAO tem ciclo!\n";
	return 0;
}
