#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

class Aresta
{
	int vertice1, vertice2, peso;

public:

    /**
    * Monta a aresta com seus vertices e pesos de um determinado vertice a outro
    */
	Aresta(int v1, int v2, int peso)
	{
		vertice1 = v1; // pega "localmente"
		vertice2 = v2;
		this->peso = peso;
	}

	/**
	* Fun��o para retornar o vertice 1
	*/
	int obterVertice1()
	{
		return vertice1;
	}

    /**
	* Fun��o para retornar o vertice 2
	*/
	int obterVertice2()
	{
		return vertice2;
	}

    /**
	* Fun��o para retornar o peso de cada
	*/
	int obterPeso()
	{
		return peso;
	}

	/**
	* Sobrescrita do operador "<" para ordenar "futuramente" da menor para a maior aresta
	*/
	bool operator < (const Aresta& aresta2) const
	{
		return (peso < aresta2.peso);
	}
};

class Grafo
{
	int V; // n�mero de v�rtices
	vector<Aresta> arestas; // vetor de arestas

public:

	Grafo(int V)
	{
		this->V = V;
	}

	/**
	* Fun��o que adiciona uma aresta
	*/
	void adicionaAresta(int v1, int v2, int peso)
	{
		Aresta aresta(v1, v2, peso);
		arestas.push_back(aresta);
	}

	// fun��o que busca o subconjunto de um elemento "i"
	int buscar(int subset[], int i)
	{
		if(subset[i] == -1)
			return i;
		return buscar(subset, subset[i]);
	}

	// fun��o para unir dois subconjuntos em um �nico subconjunto
	void unir(int subset[], int v1, int v2)
	{
		int v1_set = buscar(subset, v1);
		int v2_set = buscar(subset, v2);
		subset[v1_set] = v2_set;
	}

	/// fun��o que roda o algoritmo de Kruskal
	void kruskal()
	{
		vector<Aresta> arvore;
		int size_arestas = arestas.size();

		// ordena as arestas pelo menor peso
		sort(arestas.begin(), arestas.end());

		// aloca mem�ria para criar "V" subconjuntos
		int * subset = new int[V];

		// inicializa todos os subconjuntos como conjuntos de um �nico elemento
		memset(subset, -1, sizeof(int) * V);

		for(int i = 0; i < size_arestas; i++)
		{
			int v1 = buscar(subset, arestas[i].obterVertice1());
			int v2 = buscar(subset, arestas[i].obterVertice2());

			if(v1 != v2)
			{
				// se forem diferentes � porque N�O forma ciclo, insere no vetor
				arvore.push_back(arestas[i]);
				unir(subset, v1, v2); // faz a uni�o
			}
		}

		int size_arvore = arvore.size();

		// mostra as arestas selecionadas com seus respectivos pesos
		for(int i = 0; i < size_arvore; i++)
		{
			char v1 = 'A' + arvore[i].obterVertice1();
			char v2 = 'A' + arvore[i].obterVertice2();
			cout << "(" << v1 << ", " << v2 << ") = " << arvore[i].obterPeso() << endl;
		}
	}
};

int main(int argc, char *argv[])
{
	Grafo g(7); // grafo

	// adiciona as arestas
	g.adicionaAresta(0, 1, 7);
	g.adicionaAresta(0, 3, 5);
	g.adicionaAresta(1, 2, 8);
	g.adicionaAresta(1, 3, 9);
	g.adicionaAresta(1, 4, 7);
	g.adicionaAresta(2, 4, 5);
	g.adicionaAresta(3, 4, 15);
	g.adicionaAresta(3, 5, 6);
	g.adicionaAresta(4, 5, 8);
	g.adicionaAresta(4, 6, 9);
	g.adicionaAresta(5, 6, 11);

	g.kruskal(); // roda o algoritmo de Kruskal

	return 0;
}
