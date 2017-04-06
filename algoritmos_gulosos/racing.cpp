// UVA 1234 - https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=3675

#include <cstdlib>
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <functional>
#include <math.h>

#define MAX 100000
#define P pair<int, double>
#define INF 1000000000

#define FOR(i, N) for( int i = 0 ; i < N ; i++ )

using namespace std;

typedef struct Ruas {
    int a, b, custo; // arestas e custo

    /**
    * Auxilia a tratar os operadores "<" e ">" e começar a selecionar as aretas da maior para a menor
    */
    bool operator < (const Ruas &e) const {
        return custo > e.custo;
    }
}E;

class UnionFind {

public: int tamanho, Pai[MAX];

public:

    /**
    * Inicializa o grafo
    */
    void Inicializar(int N) {

        for(int i = 0; i < N; i++)
            Pai[i] = i;
            tamanho = N;
    }

    /**
    * Função recursiva que busca o subconjunto de um determnado elemento "v" do grafo
    * Enquanto houver vertices, percorre uma aresta ligada a um novo vertice
    * O(n)
    */
    int busca(int Index) {
        return Pai[Index] == Index ? Index : (Pai[Index] = busca(Pai[Index]));
    }

    /**
    * Função que verifica se a chamada de busca pega o mesmo valor e forma ciiclo
    * O(log n)
    */
    bool identificaCiclo(int X, int Y) {
        return busca(X) == busca(Y);
        return false;
    }

    /**
    * Função para unir dois subconjuntos em um único conjunto
    * Usa a função busca para identificar os subconjuntos de cada vertice e em seguida os une
    * O(log n)
    */
    void une(int X, int Y) {
        if(!identificaCiclo(X, Y))
            Pai[busca(X)] = busca(Y), tamanho--;
    }

    /**
    * Função para unir dois subconjuntos em um único conjunto
    * Usa a função busca para identificar os subconjuntos de cada vertice e em seguida os une
    * O(1)
    */
    int GetTamanho() {
        return tamanho;
    }
};

int c; // casos de teste
int n; // numero de junções
int m; // numero de estradas
int a, b, custo; // arestas e custo

E Edges[MAX];
int Index;

int main(int argc, char** argv) {

    scanf("%d", &c);

    /**
    * Recebe as entredas dos casos de teste
    */
    while(c--) {
        UnionFind X;
        Index = 0;
        scanf("%d %d", &n, &m);

        /**
        * O(n)
        */
        FOR(i, m) {
            scanf("%d %d %d", &a, &b, &custo);
            Edges[Index].a = a - 1;
            Edges[Index].b = b - 1;
            Edges[Index].custo = custo;
            Index++;
        }

        /**
        * O(n)
        */
        X.Inicializar(n);
        sort(Edges, Edges + Index);
        int CustoMinimo = 0;
        FOR(i, m)   CustoMinimo += Edges[i].custo;

        /**
        * O(n^2 + log n + 1)
        */
        for(int i = 0; i < Index && X.GetTamanho() > 0; i++) {
            if(!X.identificaCiclo(Edges[i].a, Edges[i].b)) {
                X.une(Edges[i].a, Edges[i].b);
                CustoMinimo -= Edges[i].custo;
            }
        }

        printf("%d\n", CustoMinimo);
    }

    return 0;
}
