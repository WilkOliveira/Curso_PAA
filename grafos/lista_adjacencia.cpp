#include <iostream>
#include <list>
#include <algorithm> // importa a fun��o "find"

using namespace std;

/**
* Classe para representar o grafo
*/
class Grafo
{
	int V; // n�mero de v�rtices
	list<int> *adjacente; // ponteiro para um array contendo as listas de adjac�ncias

public:
	Grafo(int V); // construtor

	/**
	* Fun��o para adicionar as arestas ao grafo
	*/
	void adicionaAresta(int v1, int v2); // aresta saindo do v�rtice v1 e indo at� o v�rtice v2

	/**
	* Fun��o para obter o grau de sa�da de um dado v�rtice
	*/
	int obtemGrauDeSaida(int v);

    /**
	* Fun��o para verificar se tem visinho (v1 � visinho de v2?)
	*/
	bool existeVizinho(int v1, int v2);
};

Grafo::Grafo(int V)
{
	this->V = V; // atribui o n�mero de v�rtices
	adjacente = new list<int>[V]; // cria as listas
}

/**
* Implmenta a fun��o adicionaAresta
*/
void Grafo::adicionaAresta(int v1, int v2){

	adjacente[v1].push_back(v2); // adiciona v�rtice v2 � lista de v�rtices adjacentes de v1

}

/**
* Implmenta a fun��o obtemGrauDeSaida
*/
int Grafo::obtemGrauDeSaida(int v){

		return adjacente[v].size(); // basta retornar o tamanho da lista que � a quantidade de vizinhos

}

/**
* Implmenta a fun��o existeVizinho
*/
bool Grafo::existeVizinho(int v1, int v2){

	if(find(adjacente[v1].begin(), adjacente[v1].end(), v2) != adjacente[v1].end())
		return true;
	return false;

}

int main()
{

	Grafo grafo(4); // criando um grafo de 4 v�rtices

	/**
	* Adiciona as arestas por meio da fun��o adicionaAresta
	*/
	grafo.adicionaAresta(0, 1);
	grafo.adicionaAresta(0, 3);
	grafo.adicionaAresta(1, 2);
	grafo.adicionaAresta(3, 1);
	grafo.adicionaAresta(3, 2);

	/**
	* Imprime os graus de sa�da por meio da fun��o obtemGrauDeSaida
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
