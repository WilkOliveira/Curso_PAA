// UVA 11733 - https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=2833

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

#define TESTES 1000000000

using namespace std;

class Cidades
{
	int cidade1, cidade2, custo;

public:

	Cidades(int c1, int c2, int custo)
	{
		cidade1 = c1;
		cidade2 = c2;
		this->custo = custo;
	}

	int obtemCidade1()
	{
		return cidade1;
	}

	int obtemCidade2()
	{
		return cidade2;
	}

	int obtercusto()
	{
		return custo;
	}

	bool operator < (const Cidades& Cidades2) const
	{
		return (custo < Cidades2.custo);
	}
};

class Grafo
{
	int V; // número de vértices
	vector<Cidades> Cidadess; // vetor de cidades

public:

	 Grafo(int V)
	{
		this->V = V;
	}

	void adicionaCidades(int c1, int c2, int custo)
	{
		Cidades Cidades(c1, c2, custo);
		Cidadess.push_back(Cidades);
	}

    // Union-find

	int busca(int subset[], int i)
	{
		if(subset[i] == -1)
			return i;
		return busca(subset, subset[i]);
	}

	void unir(int subset[], int c1, int c2)
	{
		int c1_set = busca(subset, c1);
		int c2_set = busca(subset, c2);
		subset[c1_set] = c2_set;
	}


	// Kruskal
	void kruskal()
	{
		vector<Cidades> arvore;
		int size_Cidadess = Cidadess.size();

		sort(Cidadess.begin(), Cidadess.end());

		int * subset = new int[V];

		memset(subset, -1, sizeof(int) * V);

		/**
		* Loop para obter os vertices e os custos entre eles
		*/
		for(int i = 0; i < size_Cidadess; i++)
		{
			int c1 = busca(subset, Cidadess[i].obtemCidade1());
			int c2 = busca(subset, Cidadess[i].obtemCidade2());

			if(c1 != c2)
			{
				arvore.push_back(Cidadess[i]);
				unir(subset, c1, c2);
			}
		}

		int size_arvore = arvore.size();

		/**
		* Loop para mostrar as cidades selecionadas com seus respectivos custos
		*/
		for(int i = 0; i < size_arvore; i++)
		{
			char c1 = 'A' + arvore[i].obtemCidade1();
			char c2 = 'A' + arvore[i].obtemCidade2();
			cout << "(" << c1 << ", " << c2 << ") = " << arvore[i].obtercusto() << endl;
		}
	}
};

int main(int argc, char *argv[])
{

	int t, n, m, a;

	scanf("%d", &t);

	Grafo g(t);

	for(int i=0; i <= t; i++){
		scanf("%d %d %d", &n, &m, &a);

		g.adicionaCidades(n, m, a);

		cout << "Case #" << i << ":" << endl;
		g.kruskal();

	}

	return 0;
}
