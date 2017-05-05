#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <queue>
#include <list>

#define MAX 100100
#define INFINITO 999999999

using namespace std;

int locais_cidade;
int cidades;
int linhas;
int estradas;
int origem, destino, distancia;
int capacidade;

/**
* Implementa��o do algoritmos de Dijkstra
*/
int dijkstra(int origem, int destino)
{
		int distancia[origem][destino]; // vetor de dist�ncias

		/**
        * Vetor de visitados, impede que um vertice visitado seja visitado novamente (guloso)
        */
        int visitados[origem][destino];

        /**
        * Define a fila de prioridades (distancia, v�rtice)
        */
        priority_queue < pair<int, int>,
		vector<pair<int, int> >, greater<pair<int, int> > > pq;

        /**
        * Inicia o vetor de dist�ncias e vertices visitadas
        */
        for(int i = 0; i < visitados; i++)
        {
		distancia[i] = INFINITO;
		visitados[i] = false;
        }

        distancia[origem] = 0; // a dist�ncia de origem para origem � 0

        pq.push(make_pair(distancia[origem], origem)); // insere na fila
		while(!pq.empty())
		{
			pair<int, int> p = pq.top(); // extrai o pair do topo
			int u = p.second; // obt�m o v�rtice do pair
			pq.pop(); // remove da fila

			/**
			* Verifica se o v�rtice n�o foi expandido
			*/
			if(visitados[origem] == false)
			{
				visitados[origem] = true; // marca como visitado

				list<pair<int, int> >::iterator it;

				/**
				* Percorre os v�rtices "v" capacidades de "u"
				*/
				for(int it = capacidade[origem].begin(); it != capacidade[origem].end(); it++)
				{
					// obt�m o v�rtice capacidade e o custo da aresta
					int dest = it->first;
					int custo_aresta = it->second;

					// relaxamento (origem, destino)
					if(distancia[destino] > (distancia[origem] + custo_aresta))
					{
						// atualiza a dist�ncia de "v" e insere na fila
						distancia[v] = distancia[u] + custo_aresta;
						pq.push(make_pair(distancia[destino], destino));
					}
				}
			}
	}

return distancia[destino];
}

int main(){
    int testes = 0; // casos de teste

    while (!cin.eof()){
        cin >> n; // n�mero total de locais dentro de tod
        if (cin.eof()) break;
        testes++;
        int k, m, n, u, v, c, d;

        for (int j=1; j<=n; j++){
            cin >> n;

        dijkstra(u, v);
        }

    }
return 0;
}
