#include <iostream>

using namespace std;

/**
* matriz de adjacencia para representar o grafo (5 vértices, não dirigido e sem pesos)
*/
int grafo[5][5] =
{
	{0, 0, 1, 0, 0},
	{0, 0, 1, 0, 0},
	{1, 1, 0, 1, 1},
	{0, 0, 1, 0, 1},
	{0, 0, 1, 1, 0}
};

/**
* Função recursiva para verificar se existe existe ligação entre algum dos vertices do grafo
* O(n^2)
*/
bool tem_ligacao(int v1, int v2)
{
	if(grafo[v1][v2])
		return true;
	return false;
}

int main(int argc, char *argv[])
{
	cout << tem_ligacao(0, 2) << endl; // verifica se tem ligação entre os vértices de posição 0 2 (que podem A e C por exemplo)
	return 0;
}
