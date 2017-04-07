#include <iostream>
#include <list>
#include <algorithm> // importa a função "find"

using namespace std;

/**
* Classe para representar o grafo
*/
class Grafo
{
	int V; // número de vértices
	list<int> *adjacente; // ponteiro para um array contendo as listas de adjacências

public:
	Grafo(int V); // construtor

	/**
	* Função para adicionar as arestas ao grafo
	*/
	void adicionaAresta(int v1, int v2); // aresta saindo do vértice v1 e indo até o vértice v2

	/**
	* Função para obter o grau de saída de um dado vértice
	*/
	int obtemGrauDeSaida(int v);

    /**
	* Função para verificar se tem visinho (v1 é visinho de v2?)
	*/
	bool existeVizinho(int v1, int v2);
};

Grafo::Grafo(int V)
{
	this->V = V; // atribui o número de vértices
	adjacente = new list<int>[V]; // cria as listas
}

/**
* Implmenta a função adicionaAresta
*/
void Grafo::adicionaAresta(int v1, int v2){

	adjacente[v1].push_back(v2); // adiciona vértice v2 à lista de vértices adjacentes de v1

}

/**
* Implmenta a função obtemGrauDeSaida
*/
int Grafo::obtemGrauDeSaida(int v){

		return adjacente[v].size(); // basta retornar o tamanho da lista que é a quantidade de vizinhos

}

/**
* Implmenta a função existeVizinho
*/
bool Grafo::existeVizinho(int v1, int v2){

	if(find(adjacente[v1].begin(), adjacente[v1].end(), v2) != adjacente[v1].end())
		return true;
	return false;

}

int main()
{

	Grafo grafo(4); // criando um grafo de 4 vértices

	/**
	* Adiciona as arestas por meio da função adicionaAresta
	*/
	grafo.adicionaAresta(0, 1);
	grafo.adicionaAresta(0, 3);
	grafo.adicionaAresta(1, 2);
	grafo.adicionaAresta(3, 1);
	grafo.adicionaAresta(3, 2);

	/**
	* Imprime os graus de saída por meio da função obtemGrauDeSaida
	*/
	cout << "Grau de saida do vertice 1: " << grafo.obtemGrauDeSaida(1);
	cout << "\nGrau de saida do vertice 3: " << grafo.obtemGrauDeSaida(3);

	/**
	* Verifica se existe vizinhos
	*/
	if(grafo.existeVizinho(0, 1))
		cout << "\n\n1 eh vizinho de 0\n";
	else
		cout << "\n\n1 NAO eh vizinho de 0\n";

	if(grafo.existeVizinho(0, 2))
		cout << "2 eh vizinho de 0\n";
	else
		cout << "2 NAO eh vizinho de 0\n";

	return 0;
}
