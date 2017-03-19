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
	* Adiciona as arestas
	*/
	Aresta(int v1, int v2, int peso)
	{
		vertice1 = v1;
		vertice2 = v2;
		this->peso = peso;
	}

	/**
	* Obtem o primeiro vertice (é apagado cada nova iteração)
	*/
	int obtemVertice1()
	{
		return vertice1;
	}

	/**
	* Obtem o segundo vertice (é apagado cada nova iteração)
	*/
	int obtemVertice2()
	{
		return vertice2;
	}

	/**
	* Obtem o peso da aresta que liga um vertice a outro
	*/
	int obterPeso()
	{
		return peso;
	}

	/**
	* Operação para sobrescrita do operador "<", que será sada para ordenar as arestas em ordem cescente
	*/
	bool operator < (const Aresta& aresta2) const
	{
		return (peso < aresta2.peso);
	}
};

class Grafo
{
	int V; // número de vértices
	vector<Aresta> arestas; // vetor de arestas

public:

	Grafo(int V)
	{
		this->V = V;
	}

	/**
	* Função para adicionar arestas
	*/
	void adicionaAresta(int v1, int v2, int peso)
	{
		Aresta aresta(v1, v2, peso);
		arestas.push_back(aresta);
	}

    // inicio da plimentação do union-find

	/**
	* Função recursiva que busca o subconjunto de um determnado elemento "i" do grafo
    * Enquanto houver vertices, percorre uma aresta ligada a um novo vertice
	*/
	int busca(int subset[], int i)
	{
		if(subset[i] == -1)
			return i;
		return busca(subset, subset[i]);
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
	* Implementação do algoritmo de Kruskal de acordo com os slides
	*/
	void kruskal()
	{
		vector<Aresta> arvore;
		int size_arestas = arestas.size();

		sort(arestas.begin(), arestas.end()); // ordena as arestas pelo menor peso

		int * subset = new int[V]; // aloca memória para criar "V" subconjuntos (subconjunto de vertices)

		memset(subset, -1, sizeof(int) * V); // inicializa todos os subconjuntos como conjuntos de um único elemento

		for(int i = 0; i < size_arestas; i++)
		{
			int v1 = busca(subset, arestas[i].obtemVertice1());
			int v2 = busca(subset, arestas[i].obtemVertice2());

			if(v1 != v2)
			{
				// se forem diferentes é porque NÃO forma ciclo, insere no vetor
				arvore.push_back(arestas[i]);
				unir(subset, v1, v2); // faz a união
			}
		}

		int size_arvore = arvore.size();

		// mostra as arestas selecionadas com seus respectivos pesos
		for(int i = 0; i < size_arvore; i++)
		{
			char v1 = 'A' + arvore[i].obtemVertice1();
			char v2 = 'A' + arvore[i].obtemVertice2();
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
