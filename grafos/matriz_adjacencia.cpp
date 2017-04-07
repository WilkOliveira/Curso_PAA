#include <iostream>

using namespace std;

/**
* matriz de adjacencia para representar o grafo (5 v�rtices, n�o dirigido e sem pesos)
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
* Fun��o recursiva para verificar se existe existe liga��o entre algum dos vertices do grafo
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
	cout << tem_ligacao(0, 2) << endl; // verifica se tem liga��o entre os v�rtices de posi��o 0 2 (que podem A e C por exemplo)
	return 0;
}
